#include "mcp2515.h"
#include "CAN.h"
#include <string.h>
/* CAN_INT 中断线
  EXTI_ClearITPendingBit(EXTI_Line17);
  EXTI_InitStructure.EXTI_Line = EXTI_Line17;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure); */
/**************************************************************
函数：unsigned char can_init(void)
功能：初始化
**************************************************************/
unsigned char can_init(void)
{
    mcp2515_clock();
    mcp2515_reset();
    mcp2515_init_can_buffers();
    mcp2515_config_rate();
    return 0;
}
/**************************************************************
函数：void init_message_struct(CAN_MESSAGE* msg)
功能：
**************************************************************/
void init_message_struct(CAN_MESSAGE* msg)
{
    memset(msg,0,sizeof(CAN_MESSAGE));
}
/**************************************************************
函数：unsigned char can_send_message(const CAN_MESSAGE* msg)
功能：CAN发送保文
**************************************************************/
unsigned char can_send_message(const CAN_MESSAGE* msg)
{
    unsigned char rec,free_txbuf;
    mcp2515_set_register(MCP_CANINTE,0x00);  //	clear the INT

    mcp2515_get_free_txbuf(&free_txbuf);   //get the free buffer for sending the data;
    mcp2515_write_can_msg(free_txbuf, msg);	//buffer 31h;

    mcp2515_start_transmit();  //start the transmit;
    return 0;
}
/**************************************************************
函数：unsigned char can_read_message(CAN_MESSAGE *msg)
功能：CAN接收保文
**************************************************************/
unsigned char can_read_message(CAN_MESSAGE *msg)
{
    unsigned char stat, res;
    stat = mcp2515_read_status();
    if( stat & 0x01 )
    {
        mcp2515_read_can_msg( MCP_RXB0SIDH, msg);	//
        mcp2515_modify_register(MCP_CANINTF, 0x01, 0);		//clear the receive interrupt identify;
        res = 1;
    }
    else if ( stat & 0x02 )
    {
        mcp2515_read_can_msg( MCP_RXB1SIDH, msg);
        mcp2515_modify_register(MCP_CANINTF, 0x02, 0);
        res = 1;
    }
    else {
        res = 0;
    }
    return res;
}
/**************************************************************
函数：unsigned char can_test_transmit(const unsigned char ext)
功能：发送测试数据
**************************************************************/
unsigned char can_test_transmit(const unsigned char ext)
{
    CAN_MESSAGE msg;

    init_message_struct(&msg);
    msg.identifier =  0xff;			//ID;
    msg.extended_identifier = ext;
    msg.dlc = 8;				   // the width of the data;
    msg.dta[0] = 0x56;			  //data;
    msg.dta[1] = 0xff;
    msg.dta[2] = 0x78;
    msg.dta[3]=0x55;
    msg.dta[4]=0x89;
    msg.dta[5]=0xab;
    msg.dta[6]=0X00;
    msg.dta[7]=0xbc;
    can_send_message(&msg);
    return 0;
}

