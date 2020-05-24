#include "stm8l15x_flash.h"
#include "bsp.h"
#include "stm8l15x_it.h"
#include "lcd.h"
#include "Protocal.h"
#include "gprs_app.h"
extern unsigned char RtcWakeUp;

uint32_t tick = 0;


// extern  unsigned int wakeupcount;
void main(void)
{
  
  
  HardwareInit();
  GSMInit();
  module_prams_init();
  RtcWakeUp = 1;
  LCD_Congfig();
  
  while(1)
  {
    if(RtcWakeUp == 1)
    {
      
      parseGpsBuffer();
      module_process(); 
      //GPIO_ResetBits( PORT_FLOW, PIN_FLOW );
      // GPIO_SetBits( PORT_FLOW, PIN_FLOW );  
    }
    
  }
}
