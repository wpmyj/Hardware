#define GLOBALS
#include "global.h"
#include "adc.h"
#include "other.h"
#include "CC1110.h"
#include "spi.h"
#include "flash.h"
#include "infrared.h"
/***************************预编译注意*****************************
在编译选择传感器类型时，在编译器Options For Target里的宏定义里修改
***************************传感器编译相关**************************/
#ifdef  Liceng
uint8_t Senor_Type=0xE1;
#elif   Maogan
uint8_t Senor_Type=0xE2;
#elif   Maosuo
uint8_t Senor_Type=0xE3;
#elif   Weiyan
uint8_t Senor_Type=0xE4;
#elif   Yali
uint8_t Senor_Type=0xE5;
#endif
/***************************传感器变量相关****************************/
uint32_t CV_Value[4]= {0,0,0,0};
/**********************传感器数据存取相关**************************/
uint32_t Flash_Read_Buff[4],Flash_Write_Buff[4];
/**************************定时计数相关****************************/
extern uint8_t Timer;
/**************************红外相关*************************/
uint8_t  SET_START,curse_ok;
uint8_t curse=0x28,curse_base=0x04,curse_tmp=0x00;
uint32_t k_code=0x00000000;
uint8_t Senor_IDNUM_Temp=0;
typedef void MENU_CALLBK(SENOR *pObj);
void Infrared_Fun(SENOR *pObj,MENU_CALLBK *_cbm,MENU_CALLBK *_cbo);
extern unsigned char Infrared_Status;
/**************************功能函数*************************/
extern WPStatus CC1100_WAKEUP_Flag;
extern int xinxi;
extern WPStatus PD_WAKEUP_Flag;
void SendMsg_Int(CC1110Tx_Msg *pMsg,SENOR *pObj);
void AD_Smapling_Function(SENOR *pObj);
void PD_WAKEUP_Int(void);
void Sendd_Int(void);
void AD_Display_Function(SENOR *pObj);
SENOR SenMsg;
extern uint32_t VValue[8]={0xAA,0x00,0x00,0x00,0x00,0x00,0xCA,0x55};
/**************************************************************
函数：int main(void)
功能：程序入口
**************************************************************/
int main(void)
{
    /************************光敏唤醒、无线唤醒初始化****************************/
    CC1110Tx_Msg TxMessage;
	  PWR_FastWakeUpCmd(ENABLE);//唤醒片内正常工作电源
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);//片内电源管理的时钟---使能 
    PWR_UltraLowPowerCmd(ENABLE);//配置低电源使能
    CC1100_WAKEUP_Flag=Low;
    PD_WAKEUP_Flag=Low;
    NVIC_Config();
    SenMsg.Senor_ID=1;
    SenMsg.Senor_Num=2;
	
    while(1)
    {
        EnterLowPower();
			//Wake_Config();	
        Bsp_Config();
        /******************初始读取flash 传感器ID和探头数量*********************/
        FLASH_Read(((uint32_t)0x08080000),((uint32_t)0x08080010),Flash_Read_Buff);
			    
        if(*Flash_Read_Buff==0x000000AA&&*(Flash_Read_Buff+3)==0x00000055)
        {
            SenMsg.Senor_ID=*(Flash_Read_Buff+1);
            SenMsg.Senor_Num=*(Flash_Read_Buff+2);
        }
        /*********如果是无光则发送 发送后无线模块进入待机，主板开始采集存储后待机*******/
        if((PD_WAKEUP_Flag<<1|CC1100_WAKEUP_Flag)==1)
        { 
				  PD_WAKEUP_Int();	
          CC1110_Config((uint32_t)9600);	
					SendMsg_Int(&TxMessage,&SenMsg);
          CC1110_Send_Flag=1;				 
          if(CC1110_Send_Flag!=Low)
          {
					   if(xinxi==1)
							{ 
								//CC1110_Sendd();
								xinxi=0;
							}
						 CC1110_Send_Flag=Low;
          }
            while(CC1110_TX_Status()!=Low)//等待模块进入休眠
            {
            }
            AD_Smapling_Function(&SenMsg);
            CC1100_WAKEUP_Flag=Low;
            PD_WAKEUP_Flag=Low;
						ControlGPIO_Init();
        }
        else if((PD_WAKEUP_Flag<<1|CC1100_WAKEUP_Flag)==2)
        {
            PD_WAKEUP_Int();
            Timer=0;
            do {
                Led_Display_XX(SenMsg.Senor_ID);
            } while(Timer<2);//光照启动先显示本机ID持续1秒
	
            AD_Display_Function(&SenMsg);
            PD_WAKEUP_Flag=Low;
            CC1100_WAKEUP_Flag=Low;
        }
    }
}
/**************************************************************
函数：void SendMsg_Int(CC1110Tx_Msg *pMsg,SENOR *pObj)
功能：无线发送初始信息
**************************************************************/
void SendMsg_Int(CC1110Tx_Msg *pMsg,SENOR *pObj)
{
    int j;
    memset(pMsg->Invalid,0xFE,5);
    pMsg->Start_Flag=0xAA;
    pMsg->ID=pObj->Senor_ID;
    pMsg->Type=Senor_Type;
    pMsg->Channel=pObj->Senor_Num;
    pMsg->Battery_Power =Battery_Monitor();
    pMsg->End_Flag=0x55;
    FLASH_Read(((uint32_t)0x08080020),((uint32_t)0x08080030),CV_Value);
    for(j=0; j<4; j++)
    {
    //    pMsg->T_Data_H[j]=(uint8_t)CV_Value[j]>>8;
    //    pMsg->T_Data_L[j]=(uint8_t)CV_Value[j]&0x00000ff;
			pMsg->T_Data_H[j]=0x00;//55
			pMsg->T_Data_L[j]=0x04;//99
    }
}
//extern int VValue[8]= {0xAA,0x00,0x00,0x00,0x00,0x00,0xCA,0x55};
void Sendd_Int(void)
{
    //int j;
    //memset(pMsg->Invalid,0xFE,5);
    //pMsg->Start_Flag=0xAA;
    //pMsg->ID=pObj->Senor_ID;
    //pMsg->Type=Senor_Type;
    //pMsg->Channel=pObj->Senor_Num;
    //pMsg->Battery_Power =Battery_Monitor();
    //pMsg->End_Flag=0x55;
	  VValue[0]=0xAA;
	  VValue[1]=SenMsg.Senor_ID;
    FLASH_Read(((uint32_t)0x08080020),((uint32_t)0x08080030),CV_Value);
    VValue[2]=(uint8_t)CV_Value[0]>>8;
    VValue[3]=(uint8_t)CV_Value[0]&0x00000ff;
    VValue[4]=(uint8_t)CV_Value[1]>>8;
    VValue[5]=(uint8_t)CV_Value[1]&0x00000ff;
	  VValue[6]=Battery_Monitor();
	  VValue[7]=0x55;
    //for(j=0; j<4; j++)
    //{
    //    pMsg->T_Data_H[j]=(uint8_t)CV_Value[j]>>8;
    //    pMsg->T_Data_L[j]=(uint8_t)CV_Value[j]&0x00000ff;
		//	pMsg->T_Data_H[j]=0x00;//55
		//	pMsg->T_Data_L[j]=0x04;//99
    //}
}
/**************************************************************
函数：void AD_Smapling_Function(CV_VALUE(*fun)(uint16_t, uint8_t),SENSOR *pObj)
功能：当无线唤醒时AD处理程序
**************************************************************/
void AD_Smapling_Function(SENOR *pObj)
{
    uint8_t i;
    Power_Control(Power_ON);   //启动传感器供电电源
    for(i=0; i<pObj->Senor_Num; i++)
    {
        delay_us(400);
        Get_ADC(i);
    }
    Power_Control(Power_OFF);  //关闭传感器电源
    FLASH_Write(((uint32_t)0x08080020),((uint32_t)0x08080030),CV_Value);
}
/**************************************************************
函数：void PD_WAKEUP_Int(void)
功能：当光照唤醒时需要的硬件
**************************************************************/
void PD_WAKEUP_Int(void)
{
    Timer_Config(1599);          //定时1秒
    Led_Control_GPIO();
    LED_Control(Power_ON);       //数码管供电
    SPI_Configuration();         //SPI开启
    Power_Control(Power_ON);     //探头电源开启
    Infrared_Config(2000,1599);  //红外开启
    NVIC_Config();
}
/**************************************************************
函数：static void _cboption(SENOR *pObj)
功能：红外功能
**************************************************************/
static void _cbmenu(SENOR *pObj)
{
    switch(k_code)
    {
    case IR_Up:
    case IR_Down:
        curse_tmp=curse;
        curse=curse_base;
        curse_base=curse_tmp;
        k_code=0;
        break;
    case IR_OK:
        curse_ok=0xff;
        k_code=0;
        break;
    case IR_Cancel:
        curse_ok=0;
        SET_START=0;
        k_code=0;
    default:
        break;
    }
    if(curse==0x28)
    {
        Led_Display_Set(0,pObj->Senor_ID);
        Senor_IDNUM_Temp=pObj->Senor_ID;          //初始信息
    }
    else if(curse==0x04)
    {
        Led_Display_Set(1,pObj->Senor_Num);
        Senor_IDNUM_Temp=pObj->Senor_Num;
    }
}
/**************************************************************
函数：static void _cboption(SENOR *pObj)
功能：红外功能
**************************************************************/
static void _cboption(SENOR *pObj)
{
    switch(k_code)
    {
    case IR_Up:
        if(Senor_IDNUM_Temp<1)Senor_IDNUM_Temp=curse;
        Senor_IDNUM_Temp--;
        k_code=0;
        break;
    case IR_Down:
        Senor_IDNUM_Temp++;
        if(Senor_IDNUM_Temp>curse)Senor_IDNUM_Temp=1;
        k_code=0;
        break;
    case IR_OK:
        if(curse==0x28)pObj->Senor_ID=Senor_IDNUM_Temp;
        else if(curse==0x04)pObj->Senor_Num=Senor_IDNUM_Temp;
        Flash_Write_Buff[0]=0x000000AA;
        Flash_Write_Buff[1]=pObj->Senor_ID;
        Flash_Write_Buff[2]=pObj->Senor_Num;
        Flash_Write_Buff[3]=0x00000055;
        FLASH_Write(((uint32_t)0x08080000),((uint32_t)0x08080010),Flash_Write_Buff);
        curse_ok=0x00;
        k_code=0;
        break;
    case IR_Cancel:
        curse_ok=0x00;
        k_code=0;
    default:
        break;
    }
    Led_Display_Set(2,Senor_IDNUM_Temp);
}
/**************************************************************
函数：void Infrared_Fun(SENOR *pObj)
功能：红外功能
**************************************************************/
void Infrared_Fun(SENOR *pObj,MENU_CALLBK *_cbm,MENU_CALLBK *_cbo)
{
    SET_START=1,curse_ok=0;
    while(SET_START==1)
    {
        k_code=IR_KEY_Scan();
        if(curse_ok==0x00)
        {
            _cbm(pObj);
        }
        else if(curse_ok==0xff)
        {
            _cbo(pObj);
        }
    }
}
/**************************************************************
函数：void AD_Display_Function(CV_VALUE(*fun)(uint16_t, uint8_t),SENOR *pObj)
功能：当光照唤醒时AD处理程序
**************************************************************/
void AD_Display_Function(SENOR *pObj)
{
    uint32_t KEY_CODE=0;
    Timer=0;
    do {
        if(Timer>=(pObj->Senor_Num))Timer=0;
        Led_Display_Data(Timer,CV_Value[Timer]);  //显示数据
        KEY_CODE=IR_KEY_Scan();
        if(KEY_CODE==IR_Fun2)        //如果有红外信号
        {
            KEY_CODE=0;
            Infrared_Fun(pObj,&_cbmenu,&_cboption);
        }
    } while(PD_WAKEUP_status()==Low); //等待光照结束
    TIM2->DIER &= (uint16_t)~TIM_IT_Update;
    TIM4->DIER &= (uint16_t)~TIM_IT_CC1|TIM_IT_Update;
    Power_Control(Power_OFF);        //关闭传感器电源
    LED_Display_Clear();             //清屏
    LED_Control(Power_OFF);          //关闭数码管电源
}





#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
    while (1)
    {
    }
}
#endif
extern uint32_t CV_Value[4];
int jj=0;
int k=0x01;
int Value[14]= {0xAA,0x08,0xE1,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCA,0x55};
void CC1110_Sendd(void)
{
    int i,h,m,p,q;
	  k++;
	  //int Value[14]= {0xAA,0x02,0xE1,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCA,0x55};
    //USART3->SR &= (uint16_t)~0x0040;
    for(i=2; i<3; i++)
    {         
		  ControlGPIO_Initt();
			GPIO_ResetBits(GPIOB,GPIO_Pin_8);//拉低 

			CV_Value[3]=SenMsg.Senor_ID;
			q = CV_Value[3];
			USART3->DR = (q & (uint16_t)0x01FF);
			while((USART3->SR & 0x0040) == RESET); //发送完成标志
			
			h = CV_Value[0]>>8;
			USART3->DR = (h & (uint16_t)0x01FF);
			//USART3->DR = (k& (uint16_t)0x01FF);
			while((USART3->SR & 0x0040) == RESET); //发送完成标志
			
			USART3->DR = (CV_Value[0] & (uint16_t)0x01FF);
			//USART3->DR = (k& (uint16_t)0x01FF);
			while((USART3->SR & 0x0040) == RESET); //发送完成标志
			
			m = CV_Value[1]>>8;
			USART3->DR = (m & (uint16_t)0x01FF);
			//USART3->DR = (k& (uint16_t)0x01FF);
			while((USART3->SR & 0x0040) == RESET); //发送完成标志
			
			USART3->DR = (CV_Value[1] & (uint16_t)0x01FF);
			//USART3->DR = (k& (uint16_t)0x01FF);
			while((USART3->SR & 0x0040) == RESET); //发送完成标志
			
			CV_Value[2]=Battery_Monitor();
			p = CV_Value[2];
			USART3->DR = (p & (uint16_t)0x01FF);
			while((USART3->SR & 0x0040) == RESET); //发送完成标志
			

				Led_Display_Data(1,Value[1]); 
			//delay_ms(2000);
			//LED_Display_Clear();             //清屏
			//LED_Control(Power_OFF);          //关闭数码管电源
    }
		//Value[1]++;
		//Led_Display_Data(1,Value[1]+1); 
		if(Value[1]==8)  
		{
			Value[1]=3; return;
		}	
		if(Value[1]==3)  
		{	
		  Value[1]=7; return;
		}	
		if(Value[1]==7)  
		{	
		  Value[1]=1; return;
		}	
		 if(Value[1]==1) 
    {  if(jj==0)  
			 {     
			  Value[1]=1;jj=1;
			 }
		   else 
			 {
			  Value[1]=8;jj=0;
			 }	 
		}	 
		//GPIO_ResetBits(GPIOB,GPIO_Pin_7);//拉低
	  //GPIO_SetBits(GPIOB,GPIO_Pin_8);//拉高      省电模式
		
}
