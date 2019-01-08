////////////////////////////////////////////////////////////////////////
//                         SST25VF016B操作函数
//1.默认使用SPI1进行通信，时钟上边沿锁存，需提前进行初始化
//2.STM32库版本v3.5
//3.片选管脚NSS需提前初始化为高电平，同时更改SelectDevice、UnselectDevice定义
////////////////////////////////////////////////////////////////////////

#include "stm32f10x.h"
#define SelectDevice GPIO_ResetBits(GPIOA, GPIO_Pin_4);
#define UnselectDevice GPIO_SetBits(GPIOA, GPIO_Pin_4);

u8 SPISend(u8 data)
{
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE)!=SET);
	SPI_I2S_SendData(SPI1, data);
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE)!=SET);
	return(SPI_I2S_ReceiveData(SPI1));	
}

////////////////////////////////////////////////////
//读取状态寄存器值
//返回读取值
u8 SST25VF016B_ReadReg(void)
{
	u8 Register;
	SelectDevice;
	SPISend(0x05);
	Register=SPISend(0x00);
	UnselectDevice;
	return (Register);
}

/////////////////////////////////////////////////////
//忙检测
//返回忙状态，0：空闲，!0：忙
u8 SST25VF016B_IsBusy(void)
{
	u8 Busy,Register;
	Register=SST25VF016B_ReadReg();
	Busy=Register & 0x01;
	return (Busy);
}

////////////////////////////////////////////////////////////
//读取数据
//u32 Address - 起始地址，范围：0x000000-0x1fffff
//u8 *Data - 读取值
//u32 nCount - 读取字节数
void SST25VF016B_Read(u32 Address,u8 *Data,u32 nCount)
{
	u32 temp;
	while(SST25VF016B_IsBusy());
	SelectDevice;
	SPISend(0x0b);
	SPISend((Address&0xffffff)>>16);
	SPISend((Address&0xffff)>>8);
	SPISend(Address&0xff);
	SPISend(0);
	for(temp=0;temp<nCount;temp++)
	{
		Data[temp]=SPISend(0x00);
	}
	UnselectDevice;
}

////////////////////////////////////////////////////
//写使能
void SST25VF016B_WriteEnable(void)
{
	SelectDevice;
	SPISend(0x06);
	SPISend(0x50);
	SPISend(0x01);
	SPISend(0x02);
	UnselectDevice;
}

////////////////////////////////////////////////////
//4KB块擦除
//u32 Address - 起始地址，范围：0-511
void SST25VF016B_4KBErase(u32 Address)
{
	Address<<=12;
	SST25VF016B_WriteEnable();
	SelectDevice;
	SPISend(0x20);
	SPISend((Address&0xffffff)>>16);
	SPISend((Address&0xffff)>>8);
	SPISend(Address&0xff);
	UnselectDevice;
	while(SST25VF016B_IsBusy());
}

////////////////////////////////////////////////////
//32KB块擦除
//u32 Address - 起始地址，范围：0-63
void SST25VF016B_32KBErase(u32 Address)
{
	Address<<=15;
	SST25VF016B_WriteEnable();
	SelectDevice;
	SPISend(0x52);
	SPISend((Address&0xffffff)>>16);
	SPISend((Address&0xffff)>>8);
	SPISend(Address&0xff);
	UnselectDevice;
	while(SST25VF016B_IsBusy());
}

////////////////////////////////////////////////////
//64KB块擦除
//u32 Address - 起始地址，范围：0-31
void SST25VF016B_64KBErase(u32 Address)
{
	Address<<=16;
	SST25VF016B_WriteEnable();
	SelectDevice;
	SPISend(0xd8);
	SPISend((Address&0xffffff)>>16);
	SPISend((Address&0xffff)>>8);
	SPISend(Address&0xff);
	UnselectDevice;
	while(SST25VF016B_IsBusy());
}

////////////////////////////////////////////////////
//整片擦除
void SST25VF016B_AllErase(void)
{
	SST25VF016B_WriteEnable();
	SelectDevice;
	SPISend(0x60);
	UnselectDevice;
	while(SST25VF016B_IsBusy());	
}

////////////////////////////////////////////////////
//写入数据
//u32 Address - 起始地址，范围：0x000000-0x1fffff
//u8 *Data - 待写值
//u32 nCount - 写入字节数
void SST25VF016B_Write(u32 Address,u8 *Data,u32 nCount)
{
	u32 temp;
	for (temp=0;temp<nCount;temp++)
	{
		SST25VF016B_WriteEnable();
		SelectDevice;
		SPISend(0x02);
		SPISend((Address&0xffffff)>>16);
		SPISend((Address&0xffff)>>8);
		SPISend(Address&0xff);
		SPISend(Data[temp]);
		UnselectDevice;	
		Address++;
		while(SST25VF016B_IsBusy());
	}
}}

/****************************************************************************
* 名    称：void FlashReadID(void)
* 功    能：读工厂码及型号的函数
* 入口参数：  
* 出口参数：无
* 说    明：
* 调用方法：无 
****************************************************************************/ 
unsigned char fac_id,dev_id;

void FlashReadID(void)
{
	while(SST25VF016B_IsBusy());
	SelectDevice;
  	SPISend(0x90);
	SPISend(0x00);
	SPISend(0x00);
	SPISend(0x00);
  	fac_id= SPISend(0x00);;		          //BFH: 工程码SST
	dev_id= SPISend(0x00);;	              //41H: 器件�  	fac_id= SPISend(0x00);;		          //BFH: 工程码SST
	dev_id= SPISend(0x00);;	              //41H: 器件型号SST25VF016B     
	UnselectDev	while(SST25VF016B_IsBusy());
	SelectDevice;
  	SPISend(0x90);
	SPISend(0x00);
	SPISend(0x00);
	SPISend(0x00);
  	fac_id= SPISend(0x00);;		          //BFH: 工程码SST
	dev_id= SPISend(0x00);;	              //41H: 器件型号SST25VF016B     
	UnselectDevice;
}

