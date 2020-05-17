#include "uart1.h"
#include "stm8l15x.h"
#include "stm8l15x_usart.h"

_uart uart1;
void Uart1_Init(u32 boundrate)
{
  CLK_PeripheralClockConfig(CLK_Peripheral_USART1,ENABLE);
  
  SYSCFG_REMAPDeInit();
//#if module == smartbox
//  //SYSCFG_REMAPPinConfig(REMAP_Pin_USART1TxRxPortC,ENABLE);
//  GPIO_Init(GPIOC, GPIO_Pin_3, GPIO_Mode_Out_PP_High_Fast);//TXD
//  GPIO_Init(GPIOC, GPIO_Pin_2, GPIO_Mode_In_PU_No_IT);//RXD
//#else if module == sensor
  SYSCFG_REMAPPinConfig(REMAP_Pin_USART1TxRxPortA,ENABLE);
  GPIO_Init(GPIOA, GPIO_Pin_2, GPIO_Mode_Out_PP_High_Fast);//TXD
  GPIO_Init(GPIOA, GPIO_Pin_3, GPIO_Mode_In_FL_No_IT);//RXD
//#endif
  
  
  
  USART_DeInit(USART1);		//复位UART1 
  
  
  USART_Init(USART1,boundrate, USART_WordLength_8b, USART_StopBits_1, 
             USART_Parity_No, USART_Mode_Tx|USART_Mode_Rx);
  USART_ClearITPendingBit(USART1, USART_IT_RXNE);
  
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启接收中断
  USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);//开启接收中断
  //USART_ITConfig(USART1, USART_IT_TC, ENABLE);  //开启发送中断
  USART_ClearITPendingBit(USART1,  USART_IT_IDLE);
  USART_Cmd(USART1, ENABLE);	//使能UART2
}

/*******************************************************************************
* 名称: UART1_SendByte
* 功能: UART1发送一个字节
* 形参: data -> 要发送的字节
* 返回: 无
* 说明: 无 
******************************************************************************/
void UART1_SendByte(u8 data)
{
  USART_SendData8(USART1, data);
  /* 等待传输结束 */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

/*******************************************************************************
* 名称: UART1_SendStr
* 功能: UART1发送len个字符
* 形参: data -> 指向要发送的字符串
*       len -> 要发送的字节数
* 返回: 无
* 说明: 无 
******************************************************************************/
void UART1_SendStr(u8 *str)
{
  unsigned char len;
  len = strlen((const char*)str);
	
  while(len>0)
  {
    UART1_SendByte(*str);
   // while(!USART_GetFlagStatus (USART1, USART_FLAG_TXE));
    str++;
    len--;
  }
}


/*******************************************************************************
* 名称: UART2_ReceiveByte
* 功能: UART2接收一个字符
* 形参: 无
* 返回: 接收到的字符
* 说明: 无 
******************************************************************************/
u8 UART1_ReceiveByte(void)
{
  u8 UART1_RX_BUF; 
  
  /* 等待接收完成 */
  while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
  
  UART1_RX_BUF = USART_ReceiveData8(USART1);
  
  return  UART1_RX_BUF;
}

/*******************************************************************************
* 名称: fputc
* 功能: 重定向c库函数printf到UART1
* 形参: 无
* 返回: 要打印的字符
* 说明: 由printf调用 
******************************************************************************/
#ifdef _IAR_
int fputc(int ch, FILE *f)
{  
  /* 将Printf内容发往串口 */
  UART1_SendByte(ch);
  
  return (ch);
}
#else
PUTCHAR_PROTOTYPE
{
  /* Write a character to the UART1 */
  UART1_SendByte(c);
  return (c);
}
#endif

GETCHAR_PROTOTYPE
{
#ifdef _COSMIC_
  char c = 0;
#else
  int c = 0;
#endif
  /* Loop until the Read data register flag is SET */
  while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);
  c = USART_ReceiveData8(USART1);
  return (c);
}

void uart1_interrupt_handler()
{
  unsigned char t;
  uart1.isGetData =1;
  //uart_str.receive_flag ++;
  t = USART1->SR;
  t = USART1->DR;//IDLE清零需要依次读SR 和DR 寄存器
  USART_ClearITPendingBit(USART1,  USART_IT_IDLE);
  uart1.isLen =  DMA_GetCurrDataCounter(DMA1_Channel2);
  uart1.index = uart1.index + uart1.isLen;
  if(uart1.index >= BUFFERSIZE)
    uart1.index = uart1.index - BUFFERSIZE;
  DMA_START_RX();//重新开启串口DMA接收模式
}
void USART1_CLR_Buf(void)                           // 串口缓存清理
{
  memset(uart1.Uart_Buffer , 0, BUFFERSIZE);      //清空                  
}