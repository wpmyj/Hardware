#ifndef RTC_H_
#define RTC_H_
#include "main.h"
typedef struct{
 unsigned char RtcWakeUP;
 
}RTC_STRU;
unsigned char *getRTC(void);
void  setRtc(unsigned char* p,unsigned char item);
void SetWakeUp(unsigned char *p);
RTC_STRU *getRtcStatus(void);
void MX_RTC_Init2(void);
u8 RTC_Init(void);              		//RTC��ʼ��

#endif

