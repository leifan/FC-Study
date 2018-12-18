//====================================================
//	接口驱动的.H文件
//====================================================
//说明： 
//		原版时间：	2010-05-17 
//		作    者：    trbbadboy 
//             QQ:472497084 
//         E-mail:trbbadboy@qq.com 
//		修改者：    leiyin 
//      修改时间：  2011-8-18
//             QQ:675274588
//         E-mail:675274588@qq.com
//====================================================       
#ifndef _comm_h_
#define _comm_h_

#ifdef   comm_GLOBALS
#define  comm_EXT
#else
#define  comm_EXT  extern
#endif

//----------------------------------------------------
//头文件

#include "conio.h"	//包含CC65提供的库
#include "nes.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "types.h"	 //类型定义文件

//----------------------------------------------------
//宏定义

#define true	1
#define false	0
#define NULL	0

//二进制的形象表示方法，从左到右分别位第7 6 5 4 3 2 1 0位
#define bin(_a,_b,_c,_d,_e,_f,_g,_h) ((_a)<<7|(_b)<<6|(_c)<<5|(_d)<<4|(_e)<<3|(_f)<<2|(_g)<<1|(_h))	//二进制的表示

//位表示
#define bit0	0x01	//第0位
#define bit1	0x02	//第1位
#define bit2	0x04	//第2位
#define bit3	0x08	//第3位
#define bit4	0x10	//第4位
#define bit5	0x20	//第5位
#define bit6	0x40	//第6位
#define bit7	0x80	//第7位

#define upperbyte(_value)		((uint8)((_value)>>8))		//取高字节
#define lowerbyte(_value)		((uint8)(_value))			//取的字节

//手柄相关:
#define joystick_1	0x4016				//两个手柄的映射
#define joystick_2	0x4017

#define button_A		0x80			//按钮A
#define button_B		0x40			//按钮B
#define button_SELECT	0x20			//按钮SELECT
#define button_START	0x10			//按钮START
#define button_UP		0x08			//按钮UP
#define button_DOWN		0x04			//按钮DOWN
#define button_UD		0x0C			//上下键掩码
#define button_LEFT		0x02			//按钮LEFT
#define button_RIGHT	0x01			//按钮RIGHT
#define button_LR		0x03			//左右键掩码
#define button_DRT		0x0F			//方向键掩码
#define button_ANY		0xff			//任意键掩码

#define presskey(k)	(key & (k))
#define iskey(k)	(key == (k))
#define downkey(k)	(((k)&okey)!=((k)&key) && (k)&key )
#define upkey(k)	(((k)&okey)!=((k)&key) && (k)&okey)
#define read_joy()  read_joystick(joystick_1)//默认的手柄读取，读取手柄1的

//----------------------------------------------------
//函数和变量声明
uint8 read_joystick(uint16 _joystick);//读手柄函数

#endif //文件结束