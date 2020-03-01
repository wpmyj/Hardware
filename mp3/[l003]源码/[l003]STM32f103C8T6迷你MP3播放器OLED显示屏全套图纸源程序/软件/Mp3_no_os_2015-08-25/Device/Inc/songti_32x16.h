
/*********************************  (C) COPYRIGHT 2014 waft_wind  *********  BEGIN OF FILE  ********************************/

/**********************************************************************
* file           : songti_32x16.h
* author         : waft_wind
* version        : V1.0
* date           : 2014-11-6
* brief          : Header for oled.c module
* Description    : --
**********************************************************************/

/* Define to prevent recursive inclusion ----------------------------*/
#ifndef __SONGTI_32X16_H
#define __SONGTI_32X16_H

 

/* Includes  == 文件包含 --------------------------------------------*/
#include "stm32f10x.h"



/* Private typedef    ==  私有类型 ----------------------------------*/
/* Private define     ==  私有定义 ----------------------------------*/

//-----------------------------------------//
u8 ascii32x16[] =
{
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//- -*****"0"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x0F, 0x00, 0x03, 0xE0, 0xFF, 0x87, 0x07,
0xE0, 0x0F, 0x80, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-!-*****"1"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00,
0xE0, 0x01, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x38, 0x04, 0x00, 0x00,
0x80, 0x03, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-"-*****"2"

0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x18, 0xF0, 0x07,
0x00, 0xF8, 0x3F, 0x00, 0xC0, 0x1F, 0x30, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x18, 0x30, 0x00,
0x00, 0x18, 0x30, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x18, 0xF0, 0x07, 0x00, 0xF8, 0x3F, 0x00,
0xC0, 0x1F, 0x30, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00,//-#-*****"3"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x1E, 0xE0, 0x03,
0x00, 0x3F, 0x60, 0x02, 0x80, 0x70, 0x00, 0x04, 0xC0, 0xE0, 0x00, 0x04, 0x40, 0xC0, 0x01, 0x04,
0xF0, 0xFF, 0xFF, 0x3F, 0x40, 0x80, 0x03, 0x04, 0x40, 0x00, 0x07, 0x06, 0x80, 0x0C, 0x0E, 0x02,
0x80, 0x0F, 0xFC, 0x01, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-$-*****"4"

0x00, 0x7F, 0x00, 0x00, 0x80, 0xFF, 0x00, 0x00, 0xC0, 0x80, 0x01, 0x00, 0x40, 0x00, 0x01, 0x06,
0xC0, 0x80, 0x81, 0x03, 0x80, 0xFF, 0xE0, 0x00, 0x00, 0x7F, 0x18, 0x00, 0x00, 0x00, 0x07, 0x00,
0x00, 0xC0, 0xFD, 0x00, 0x00, 0x30, 0xFF, 0x03, 0x00, 0x8E, 0x01, 0x06, 0x80, 0x83, 0x00, 0x04,
0xC0, 0x80, 0x01, 0x06, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,//-%-*****"5"

0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0xFE, 0x03, 0x00, 0x3F, 0x03, 0x03, 0x80, 0xFF, 0x01, 0x06,
0xC0, 0xC0, 0x07, 0x04, 0x40, 0x40, 0x1E, 0x04, 0x40, 0x60, 0x78, 0x04, 0xC0, 0x3F, 0xE0, 0x02,
0x80, 0x0F, 0xC0, 0x01, 0x00, 0x80, 0xC0, 0x03, 0x00, 0x80, 0x38, 0x06, 0x00, 0x80, 0x07, 0x04,
0x00, 0x80, 0x00, 0x04, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00,//-&-*****"6"

0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x38, 0x06, 0x00, 0x00, 0x38, 0x02, 0x00, 0x00,
0xF8, 0x01, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-'-*****"7"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00,
0x00, 0xFC, 0xFF, 0x00, 0x00, 0x1E, 0xE0, 0x03, 0x80, 0x03, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x0C,
0x20, 0x00, 0x00, 0x10, 0x10, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,//-(-*****"8"

0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x40, 0x10, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x10,
0xC0, 0x00, 0x00, 0x0C, 0x80, 0x03, 0x00, 0x07, 0x00, 0x1E, 0xE0, 0x03, 0x00, 0xFC, 0xFF, 0x00,
0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-)-*****"9"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x70, 0x1C, 0x00,
0x00, 0x70, 0x1C, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0xC0, 0x06, 0x00, 0x00, 0x86, 0xC2, 0x01,
0x00, 0xFF, 0xFF, 0x01, 0x00, 0x86, 0xC2, 0x00, 0x00, 0xC0, 0x06, 0x00, 0x00, 0x60, 0x0C, 0x00,
0x00, 0x70, 0x1C, 0x00, 0x00, 0x70, 0x1C, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,//-*-*****"10"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,//-+-*****"11"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xC7, 0x00, 0x00, 0x00, 0x47,
0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-,-*****"12"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,//---*****"13"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x07,
0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-.-*****"14"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x07,
0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x07, 0x00,
0x00, 0xC0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
0xC0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-/-*****"15"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0xFE, 0xFF, 0x00,
0x00, 0x0F, 0xE0, 0x01, 0x80, 0x01, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x06, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0x00, 0x00, 0x06, 0x80, 0x01, 0x00, 0x03,
0x00, 0x07, 0xC0, 0x01, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,//-0-*****"16"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04,
0x00, 0x01, 0x00, 0x04, 0x00, 0x01, 0x00, 0x04, 0x00, 0x01, 0x00, 0x06, 0x80, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-1-*****"17"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x07, 0x00, 0x19, 0x80, 0x06,
0x80, 0x00, 0x40, 0x06, 0x40, 0x00, 0x20, 0x06, 0x40, 0x00, 0x10, 0x06, 0x40, 0x00, 0x08, 0x06,
0x40, 0x00, 0x04, 0x06, 0x40, 0x00, 0x02, 0x06, 0xC0, 0x00, 0x01, 0x06, 0x80, 0xC1, 0x00, 0x06,
0x80, 0x7F, 0x00, 0x07, 0x00, 0x3E, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-2-*****"18"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xE0, 0x01, 0x80, 0x0F, 0xE0, 0x03,
0x80, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04,
0x40, 0x80, 0x00, 0x04, 0xC0, 0xC0, 0x01, 0x04, 0x80, 0x61, 0x01, 0x02, 0x80, 0x3F, 0x03, 0x03,
0x00, 0x1E, 0xFE, 0x01, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-3-*****"19"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x12, 0x00,
0x00, 0x80, 0x11, 0x00, 0x00, 0x60, 0x10, 0x00, 0x00, 0x30, 0x10, 0x08, 0x00, 0x0C, 0x10, 0x08,
0x00, 0x02, 0x10, 0x08, 0x80, 0xFF, 0xFF, 0x0F, 0xC0, 0xFF, 0xFF, 0x0F, 0xC0, 0xFF, 0xFF, 0x0F,
0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00,//-4-*****"20"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0xF8, 0x61, 0x02,
0xC0, 0x87, 0x00, 0x04, 0xC0, 0x40, 0x00, 0x04, 0xC0, 0x20, 0x00, 0x04, 0xC0, 0x20, 0x00, 0x04,
0xC0, 0x20, 0x00, 0x04, 0xC0, 0x20, 0x00, 0x04, 0xC0, 0x60, 0x00, 0x02, 0xC0, 0xC0, 0x80, 0x03,
0xC0, 0x80, 0xFF, 0x01, 0xC0, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-5-*****"21"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0x00, 0x00, 0xFC, 0xFF, 0x00,
0x00, 0x0E, 0xC3, 0x01, 0x00, 0x81, 0x01, 0x03, 0x80, 0x80, 0x00, 0x06, 0xC0, 0x40, 0x00, 0x04,
0x40, 0x40, 0x00, 0x04, 0x40, 0x40, 0x00, 0x04, 0x40, 0x40, 0x00, 0x04, 0x40, 0xC0, 0x00, 0x02,
0x80, 0x83, 0x01, 0x03, 0x00, 0x03, 0xFF, 0x01, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,//-6-*****"22"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00,
0xC0, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0xE0, 0x07, 0xC0, 0x00, 0xFC, 0x07,
0xC0, 0x80, 0x03, 0x00, 0xC0, 0x60, 0x00, 0x00, 0xC0, 0x18, 0x00, 0x00, 0xC0, 0x06, 0x00, 0x00,
0xC0, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-7-*****"23"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x1E, 0xFC, 0x01, 0x00, 0x3F, 0x06, 0x03,
0x80, 0x71, 0x03, 0x02, 0xC0, 0xE0, 0x01, 0x04, 0x40, 0xC0, 0x00, 0x04, 0x40, 0x80, 0x01, 0x04,
0x40, 0x80, 0x01, 0x04, 0x40, 0x80, 0x03, 0x04, 0xC0, 0x80, 0x07, 0x02, 0x80, 0x61, 0x0E, 0x03,
0x00, 0x3F, 0xFC, 0x01, 0x00, 0x1E, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-8-*****"24"

0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0x81, 0x03, 0x80, 0x03, 0x83, 0x03,
0x80, 0x00, 0x06, 0x04, 0x40, 0x00, 0x04, 0x04, 0x40, 0x00, 0x04, 0x04, 0x40, 0x00, 0x04, 0x04,
0x40, 0x00, 0x04, 0x06, 0x40, 0x00, 0x02, 0x03, 0x80, 0x00, 0x83, 0x01, 0x00, 0x83, 0xF1, 0x00,
0x00, 0xFE, 0x7F, 0x00, 0x00, 0xF8, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-9-*****"25"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x03, 0x00, 0xE0, 0x81, 0x07,
0x00, 0xE0, 0x81, 0x07, 0x00, 0xC0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-:-*****"26"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x66, 0x00, 0x60, 0x00, 0x1E,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-;-*****"27"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x03, 0x00,
0x00, 0xC0, 0x06, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x18, 0x30, 0x00,
0x00, 0x0C, 0x60, 0x00, 0x00, 0x06, 0xC0, 0x00, 0x00, 0x03, 0x80, 0x01, 0x80, 0x00, 0x00, 0x02,
0x40, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-<-*****"28"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00,
0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00,
0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00,
0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,//-=-*****"29"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x08, 0x40, 0x00, 0x00, 0x04,
0x80, 0x00, 0x00, 0x02, 0x00, 0x03, 0x80, 0x01, 0x00, 0x06, 0xC0, 0x00, 0x00, 0x0C, 0x60, 0x00,
0x00, 0x18, 0x30, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x60, 0x0C, 0x00, 0x00, 0xC0, 0x06, 0x00,
0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//->-*****"30"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x80, 0x1F, 0x00, 0x00,
0x40, 0x1C, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x03, 0x20, 0x00, 0x9E, 0x07,
0x20, 0x00, 0x81, 0x07, 0x20, 0x80, 0x00, 0x03, 0x20, 0xC0, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00,
0xC0, 0x60, 0x00, 0x00, 0x80, 0x3F, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-?-*****"31"

0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0xFC, 0x7F, 0x00, 0x00, 0x0E, 0xE0, 0x01,
0x00, 0x03, 0x00, 0x03, 0x80, 0x80, 0x1F, 0x02, 0xC0, 0xE0, 0x3F, 0x04, 0x40, 0x78, 0x20, 0x04,
0x40, 0x0C, 0x10, 0x04, 0x40, 0x04, 0x0C, 0x04, 0x40, 0xFC, 0x3F, 0x04, 0x80, 0xFC, 0x20, 0x02,
0x80, 0x01, 0x30, 0x03, 0x00, 0x07, 0x8C, 0x01, 0x00, 0xF8, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00,//-@-*****"32"

0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x7C, 0x04,
0x00, 0xC0, 0x07, 0x04, 0x00, 0x7C, 0x04, 0x00, 0xC0, 0x07, 0x04, 0x00, 0xC0, 0x01, 0x04, 0x00,
0xE0, 0x3F, 0x04, 0x00, 0x00, 0xFC, 0x07, 0x00, 0x00, 0xC0, 0x7F, 0x04, 0x00, 0x00, 0xFC, 0x07,
0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-A-*****"33"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04,
0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0xC0, 0xC0, 0x00, 0x04, 0x80, 0x61, 0x01, 0x06,
0x80, 0x3F, 0x03, 0x03, 0x00, 0x1F, 0xFE, 0x01, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,//-B-*****"34"

0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x0E, 0xE0, 0x01,
0x00, 0x03, 0x00, 0x03, 0x80, 0x00, 0x00, 0x02, 0xC0, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x02,
0x80, 0x01, 0x00, 0x03, 0xC0, 0x03, 0x80, 0x01, 0x00, 0x0C, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,//-C-*****"35"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0xC0, 0x00, 0x00, 0x06, 0x80, 0x00, 0x00, 0x02, 0x80, 0x01, 0x00, 0x03,
0x00, 0x0F, 0xE0, 0x01, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,//-D-*****"36"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04,
0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0x40, 0xC0, 0x01, 0x04, 0x40, 0xF0, 0x07, 0x04,
0xC0, 0x00, 0x00, 0x06, 0xC0, 0x03, 0x00, 0x07, 0x00, 0x06, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,//-E-*****"37"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x00,
0x40, 0x80, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x40, 0xC0, 0x01, 0x00,
0xC0, 0xF0, 0x07, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,//-F-*****"38"

0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xFC, 0x7F, 0x00, 0x00, 0x0E, 0xE0, 0x01,
0x80, 0x03, 0x80, 0x03, 0x80, 0x00, 0x00, 0x02, 0xC0, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x80, 0x00, 0x04, 0x04, 0x80, 0x00, 0x04, 0x02,
0xC0, 0x03, 0xFC, 0x01, 0x00, 0x0C, 0xFC, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00,//-G-*****"39"

0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07, 0xC0, 0xFF, 0xFF, 0x07,
0x40, 0x00, 0x01, 0x04, 0x40, 0x00, 0x01, 0x04, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x40, 0x00, 0x01, 0x04, 0x40, 0x00, 0x01, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-H-*****"40"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-I-*****"41"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xF0,
0x00, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0xC0,
0x40, 0x00, 0x00, 0x60, 0xC0, 0xFF, 0xFF, 0x3F, 0xC0, 0xFF, 0xFF, 0x1F, 0x40, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-J-*****"42"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x03, 0x04, 0x40, 0x80, 0x00, 0x04, 0x00, 0xE0, 0x01, 0x00,
0x00, 0xF0, 0x07, 0x00, 0x00, 0x0C, 0x1F, 0x00, 0x40, 0x06, 0x7C, 0x04, 0xC0, 0x01, 0xF0, 0x04,
0xC0, 0x00, 0xC0, 0x07, 0x40, 0x00, 0x00, 0x07, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,//-K-*****"43"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,//-L-*****"44"

0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07, 0xC0, 0x07, 0x00, 0x04,
0xC0, 0xFF, 0x00, 0x04, 0x00, 0xF8, 0x0F, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0xF0, 0x07,
0x00, 0x00, 0x78, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x7C, 0x00, 0x04, 0xC0, 0x07, 0x00, 0x04,
0xC0, 0xFF, 0xFF, 0x07, 0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04,//-M-*****"45"

0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07, 0xC0, 0x01, 0x00, 0x04,
0xC0, 0x0F, 0x00, 0x04, 0x00, 0x3F, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x00,
0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x40, 0x00, 0xF8, 0x01, 0x40, 0x00, 0xE0, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-N-*****"46"

0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0xFC, 0x7F, 0x00, 0x00, 0x0F, 0xE0, 0x01,
0x80, 0x01, 0x00, 0x03, 0x80, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x80, 0x00, 0x00, 0x02, 0x80, 0x01, 0x00, 0x03,
0x00, 0x0F, 0xC0, 0x01, 0x00, 0xFC, 0x7F, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,//-O-*****"47"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x01, 0x04, 0x40, 0x00, 0x01, 0x04, 0x40, 0x00, 0x01, 0x00,
0x40, 0x00, 0x01, 0x00, 0x40, 0x00, 0x01, 0x00, 0x40, 0x00, 0x01, 0x00, 0xC0, 0x80, 0x01, 0x00,
0x80, 0xC1, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-P-*****"48"

0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0x0F, 0xC0, 0x01,
0x80, 0x01, 0x80, 0x03, 0x80, 0x00, 0x60, 0x02, 0x40, 0x00, 0x20, 0x04, 0x40, 0x00, 0x20, 0x04,
0x40, 0x00, 0x60, 0x04, 0x40, 0x00, 0xC0, 0x07, 0x80, 0x00, 0x00, 0x1F, 0x80, 0x01, 0x00, 0x3A,
0x00, 0x07, 0xC0, 0x31, 0x00, 0xFC, 0xFF, 0x30, 0x00, 0xF0, 0x3F, 0x18, 0x00, 0x00, 0x00, 0x00,//-Q-*****"49"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x00, 0x04, 0x40, 0x80, 0x01, 0x00,
0x40, 0x80, 0x07, 0x00, 0x40, 0x80, 0x3F, 0x00, 0xC0, 0xC0, 0xFC, 0x01, 0x80, 0x61, 0xE0, 0x07,
0x80, 0x3F, 0x00, 0x07, 0x00, 0x1F, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-R-*****"50"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x60, 0x00, 0x00, 0x7F, 0x80, 0x07,
0x80, 0x61, 0x00, 0x03, 0xC0, 0xC0, 0x00, 0x02, 0x40, 0xC0, 0x00, 0x04, 0x40, 0x80, 0x01, 0x04,
0x40, 0x80, 0x01, 0x04, 0x40, 0x80, 0x03, 0x04, 0x40, 0x00, 0x03, 0x04, 0x80, 0x00, 0x07, 0x06,
0x80, 0x01, 0x0E, 0x03, 0xC0, 0x07, 0xFC, 0x01, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00,//-S-*****"51"

0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xC0, 0xFF, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-T-*****"52"

0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0x00, 0xC0, 0xFF, 0xFF, 0x03,
0x40, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x01,
0xC0, 0xFF, 0xFF, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-U-*****"53"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00,
0xC0, 0x3F, 0x00, 0x00, 0x40, 0xFC, 0x03, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x00, 0x00, 0xFE, 0x01,
0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x40, 0xC0, 0x03, 0x00,
0x40, 0x3C, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,//-V-*****"54"

0x40, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0xC0, 0xFF, 0x01, 0x00, 0x40, 0xFC, 0x7F, 0x00,
0x40, 0x00, 0xFE, 0x07, 0x00, 0x00, 0xF0, 0x00, 0x40, 0x00, 0x0F, 0x00, 0xC0, 0xF7, 0x00, 0x00,
0xC0, 0xFF, 0x01, 0x00, 0x40, 0xF0, 0x7F, 0x00, 0x00, 0x00, 0xFC, 0x07, 0x00, 0x00, 0xF8, 0x00,
0x40, 0xE0, 0x07, 0x00, 0xC0, 0x1F, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,//-W-*****"55"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0x01, 0x00, 0x07,
0xC0, 0x0F, 0xC0, 0x04, 0x40, 0x3F, 0x30, 0x04, 0x40, 0xF8, 0x0C, 0x00, 0x00, 0xE0, 0x03, 0x00,
0x00, 0xE0, 0x0F, 0x00, 0x40, 0x18, 0x3E, 0x00, 0x40, 0x06, 0xF8, 0x04, 0xC0, 0x01, 0xC0, 0x07,
0x40, 0x00, 0x00, 0x07, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-X-*****"56"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00,
0xC0, 0x1F, 0x00, 0x00, 0x40, 0x7C, 0x00, 0x04, 0x40, 0xF0, 0x03, 0x04, 0x00, 0x80, 0xFF, 0x07,
0x00, 0x00, 0xFE, 0x07, 0x00, 0xC0, 0x01, 0x04, 0x40, 0x38, 0x00, 0x04, 0x40, 0x0E, 0x00, 0x00,
0xC0, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-Y-*****"57"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x06, 0x00, 0x07, 0xC0, 0x01, 0xC0, 0x07,
0xC0, 0x00, 0xF0, 0x05, 0x40, 0x00, 0x7C, 0x04, 0x40, 0x00, 0x1F, 0x04, 0x40, 0xC0, 0x07, 0x04,
0x40, 0xF0, 0x01, 0x04, 0x40, 0x7C, 0x00, 0x04, 0x40, 0x1E, 0x00, 0x04, 0xC0, 0x07, 0x00, 0x06,
0xC0, 0x01, 0x00, 0x07, 0x40, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-Z-*****"58"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0x3F, 0x08, 0x00, 0x00, 0x20,
0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20,
0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-[-*****"59"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
0xC0, 0x03, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xC0, 0x03, 0x00,
0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x0F,
0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-\-*****"60"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20,
0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00, 0x20,
0x08, 0x00, 0x00, 0x20, 0xF8, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-]-*****"61"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-^-*****"62"

0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80,
0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80,
0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80,
0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80,//-_-*****"63"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-`-*****"64"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x80, 0xF1, 0x03, 0x00, 0xC0, 0x31, 0x06,
0x00, 0x60, 0x18, 0x04, 0x00, 0x20, 0x08, 0x04, 0x00, 0x20, 0x08, 0x04, 0x00, 0x20, 0x04, 0x04,
0x00, 0x20, 0x04, 0x02, 0x00, 0x60, 0x04, 0x02, 0x00, 0xC0, 0xFF, 0x03, 0x00, 0x80, 0xFF, 0x07,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,//-a-*****"65"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0x07,
0xE0, 0xFF, 0xFF, 0x03, 0x00, 0x80, 0x01, 0x03, 0x00, 0x40, 0x00, 0x06, 0x00, 0x40, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x02,
0x00, 0xC0, 0x00, 0x03, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,//-b-*****"66"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x80, 0xFF, 0x01,
0x00, 0xC0, 0x81, 0x03, 0x00, 0x40, 0x00, 0x02, 0x00, 0x60, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x04, 0x00, 0xC0, 0x03, 0x02,
0x00, 0x80, 0x03, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-c-*****"67"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x80, 0xFF, 0x01,
0x00, 0xC0, 0x01, 0x03, 0x00, 0x60, 0x00, 0x06, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x40, 0x20, 0x00, 0x02, 0x40, 0x40, 0x00, 0x01, 0xC0, 0xFF, 0xFF, 0x07,
0xE0, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,//-d-*****"68"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x80, 0xFF, 0x01,
0x00, 0xC0, 0x88, 0x03, 0x00, 0x40, 0x08, 0x02, 0x00, 0x20, 0x08, 0x06, 0x00, 0x20, 0x08, 0x04,
0x00, 0x20, 0x08, 0x04, 0x00, 0x20, 0x08, 0x04, 0x00, 0x60, 0x08, 0x04, 0x00, 0xC0, 0x08, 0x02,
0x00, 0x80, 0x0F, 0x03, 0x00, 0x00, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-e-*****"69"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0xFE, 0xFF, 0x07, 0x80, 0xFF, 0xFF, 0x07,
0x80, 0x20, 0x00, 0x04, 0xC0, 0x20, 0x00, 0x04, 0x40, 0x20, 0x00, 0x04, 0x40, 0x20, 0x00, 0x04,
0x40, 0x20, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00,//-f-*****"70"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0xC7, 0x7C,
0x00, 0xC0, 0xFF, 0x43, 0x00, 0x40, 0x30, 0xC3, 0x00, 0x20, 0x20, 0x83, 0x00, 0x20, 0x20, 0x83,
0x00, 0x20, 0x20, 0x83, 0x00, 0x20, 0x20, 0x83, 0x00, 0x60, 0x30, 0x83, 0x00, 0xC0, 0x1F, 0xC3,
0x00, 0xA0, 0x0F, 0x46, 0x00, 0x60, 0x00, 0x7E, 0x00, 0x60, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00,//-g-*****"71"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xE0, 0xFF, 0xFF, 0x07, 0x00, 0x80, 0x00, 0x04, 0x00, 0x40, 0x00, 0x04, 0x00, 0x60, 0x00, 0x00,
0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x04,
0x00, 0xC0, 0xFF, 0x07, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,//-h-*****"72"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0xC0, 0xE1, 0xFF, 0x07,
0xC0, 0xF1, 0xFF, 0x07, 0xC0, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-i-*****"73"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x20, 0x00, 0x80,
0x00, 0x20, 0x00, 0x80, 0x00, 0x20, 0x00, 0xC0, 0x00, 0x20, 0x00, 0x60, 0xC0, 0xE1, 0xFF, 0x3F,
0xC0, 0xF1, 0xFF, 0x1F, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-j-*****"74"

0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xE0, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x10, 0x04, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x0C, 0x00,
0x00, 0x00, 0x3F, 0x00, 0x00, 0xA0, 0x71, 0x00, 0x00, 0xE0, 0xE0, 0x05, 0x00, 0x60, 0x80, 0x07,
0x00, 0x20, 0x00, 0x07, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-k-*****"75"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04,
0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x04, 0xC0, 0xFF, 0xFF, 0x07,
0xE0, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-l-*****"76"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0xF0, 0xFF, 0x07,
0x00, 0x40, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0xE0, 0xFF, 0x07,
0x00, 0xC0, 0xFF, 0x07, 0x00, 0x40, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04,
0x00, 0xE0, 0xFF, 0x07, 0x00, 0xC0, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-m-*****"77"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0xE0, 0xFF, 0x07,
0x00, 0xF0, 0xFF, 0x07, 0x00, 0x80, 0x00, 0x04, 0x00, 0x40, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00,
0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x04,
0x00, 0xC0, 0xFF, 0x07, 0x00, 0x80, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,//-n-*****"78"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0xFF, 0x01,
0x00, 0xC0, 0x81, 0x03, 0x00, 0x40, 0x00, 0x02, 0x00, 0x60, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x04, 0x00, 0x40, 0x00, 0x02,
0x00, 0xC0, 0x81, 0x03, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,//-o-*****"79"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x80, 0x00, 0x20, 0x00, 0x80, 0x00, 0xE0, 0xFF, 0xFF,
0x00, 0xF0, 0xFF, 0xFF, 0x00, 0x80, 0x00, 0x83, 0x00, 0x40, 0x00, 0x82, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x60, 0x00, 0x02,
0x00, 0xC0, 0x80, 0x03, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00,//-p-*****"80"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x80, 0xFF, 0x01,
0x00, 0xC0, 0x01, 0x03, 0x00, 0x40, 0x00, 0x06, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x40, 0x00, 0x82, 0x00, 0xC0, 0x00, 0x83,
0x00, 0xC0, 0xFF, 0xFF, 0x00, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80,//-q-*****"81"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x04, 0x00, 0xF0, 0xFF, 0x07, 0x00, 0xF0, 0xFF, 0x07, 0x00, 0x00, 0x03, 0x04,
0x00, 0x80, 0x00, 0x04, 0x00, 0x40, 0x00, 0x04, 0x00, 0x60, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00,
0x00, 0x20, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-r-*****"82"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x80, 0x03, 0x07,
0x00, 0xC0, 0x07, 0x02, 0x00, 0x60, 0x0C, 0x04, 0x00, 0x20, 0x0C, 0x04, 0x00, 0x20, 0x18, 0x04,
0x00, 0x20, 0x18, 0x04, 0x00, 0x20, 0x18, 0x04, 0x00, 0x20, 0x30, 0x04, 0x00, 0x40, 0x30, 0x06,
0x00, 0xC0, 0xE0, 0x03, 0x00, 0xE0, 0xC1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-s-*****"83"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
0x00, 0x20, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0x01, 0x00, 0xFF, 0xFF, 0x03,
0x00, 0x20, 0x00, 0x06, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04,
0x00, 0x20, 0x00, 0x02, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-t-*****"84"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x01,
0x00, 0xF0, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04,
0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x20, 0x00, 0x02, 0x00, 0x20, 0x00, 0x01,
0x00, 0xE0, 0xFF, 0x07, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02,//-u-*****"85"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00,
0x00, 0xE0, 0x0F, 0x00, 0x00, 0x20, 0x7F, 0x00, 0x00, 0x20, 0xF8, 0x03, 0x00, 0x00, 0xC0, 0x07,
0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x38, 0x00, 0x00, 0x20, 0x06, 0x00, 0x00, 0xE0, 0x01, 0x00,
0x00, 0x60, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-v-*****"86"

0x00, 0x20, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0xE0, 0x3F, 0x00,
0x00, 0x20, 0xFC, 0x01, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x20, 0xF0, 0x01, 0x00, 0x60, 0x0F, 0x00,
0x00, 0xE0, 0x0F, 0x00, 0x00, 0xE0, 0xFF, 0x01, 0x00, 0x20, 0xF0, 0x07, 0x00, 0x00, 0xC0, 0x01,
0x00, 0x20, 0x3C, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,//-w-*****"87"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x20, 0x00, 0x04, 0x00, 0x20, 0x00, 0x06,
0x00, 0xE0, 0x00, 0x07, 0x00, 0xE0, 0xC1, 0x04, 0x00, 0xE0, 0x67, 0x00, 0x00, 0x20, 0x1F, 0x00,
0x00, 0x00, 0x3C, 0x00, 0x00, 0x20, 0x7A, 0x04, 0x00, 0xA0, 0xE1, 0x05, 0x00, 0x60, 0x80, 0x07,
0x00, 0x20, 0x00, 0x06, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,//-x-*****"88"

0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0xC0, 0x00, 0xE0, 0x00, 0xC0,
0x00, 0xE0, 0x07, 0x80, 0x00, 0x20, 0x1F, 0x80, 0x00, 0x20, 0xF8, 0x40, 0x00, 0x00, 0xE0, 0x3F,
0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x20, 0x1C, 0x00, 0x00, 0xE0, 0x03, 0x00,
0x00, 0x60, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-y-*****"89"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x06, 0x00, 0x60, 0x00, 0x07,
0x00, 0x20, 0xC0, 0x07, 0x00, 0x20, 0xE0, 0x05, 0x00, 0x20, 0x70, 0x04, 0x00, 0x20, 0x3C, 0x04,
0x00, 0x20, 0x0E, 0x04, 0x00, 0xA0, 0x07, 0x04, 0x00, 0xE0, 0x01, 0x04, 0x00, 0xE0, 0x00, 0x06,
0x00, 0x20, 0x00, 0x07, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-z-*****"90"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x02, 0x00, 0xE0, 0x7F, 0xFC, 0x1F, 0x10, 0x00, 0x00, 0x20,
0x08, 0x00, 0x00, 0x40, 0x08, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-{-*****"91"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-|-*****"92"

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x40, 0x08, 0x00, 0x00, 0x40,
0x10, 0x00, 0x00, 0x20, 0xE0, 0x7F, 0xFC, 0x1F, 0x00, 0x80, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-}-*****"93"

0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00,
0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
0x40, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//-~-*****"94"

};



/* Private macro      ==  私有宏 ------------------------------------*/
/* Private variables  ==  私有变量 ----------------------------------*/



/* Private function prototypes  ==  私有函数声明 --------------------*/



/* Define to prevent recursive inclusion ----------------------------*/
#endif /* __SONGTI_32X16_H */




/*********************************  (C) COPYRIGHT 2014 waft_wind  *********  END OF FILE  **********************************/
