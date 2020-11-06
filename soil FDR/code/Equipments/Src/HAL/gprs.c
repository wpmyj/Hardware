#include "nbiotHAL.h"
#include "string.h"
#include "nbiotHW.h"

extern nbiotUart_stru nbiotUart;;
unsigned long  Time_Cont = 0;       //定时器计数器
unsigned int count = 0;

void phone(char *number)
{
  char send_buf[20] = {0};
  memset(send_buf, 0, 20);    //清空
  strcpy(send_buf, "ATD");
  strcat(send_buf, number);
  strcat(send_buf, ";\r\n");
  
  if (sendCommand(send_buf, "OK\r\n", 10000, 10) == Success);
  else errorLog(4);
}
unsigned char TimeOutFlag=0;
unsigned char RetryCount;
unsigned int sendCommand(unsigned char  *Command, char *Response, unsigned long Timeout, unsigned char Retry)
{
  unsigned char *USARTX_RX_BUF;
  USARTX_RX_BUF =nbiotUart.nbiotRxBuffer;

  if(TimeOutFlag == 0||TimeOutFlag == 2)
  {
    if(RetryCount<Retry)
    {
      if(Retry>0)
         NbiotUart_SendStr(Command); 		//发送GPRS指令  
      RetryCount = RetryCount +1;
      Time_Cont = 0;
	  TimeOutFlag = 1;
    }
    else
    {
        RetryCount = 0;
        TimeOutFlag = 2;
    }
    
  }
  
  if(TimeOutFlag==1)
  {
    Time_Cont++;
  } 
  if (Time_Cont >= Timeout)
  {
    Time_Cont = 0;
    TimeOutFlag = 0;
    if (strstr(USARTX_RX_BUF, Response) != NULL)
    {				
      NbiotUart_CLR_Buf();
      return Success;
    }
    else
    {
      NbiotUart_CLR_Buf();
      return Failure;
    } 
  }
  else
  {
	  if (strstr(USARTX_RX_BUF, Response) == NULL)
	  { 
	   Time_Cont = 0;
       TimeOutFlag = 2;
		NbiotUart_CLR_Buf();
		return Failure;
	  }

  }
    
} 




