//====================================================
//	�ӿ�������.H�ļ�
//====================================================
//˵���� 
//		ԭ��ʱ�䣺	2010-05-17 
//		��    �ߣ�    trbbadboy 
//             QQ:472497084 
//         E-mail:trbbadboy@qq.com 
//		�޸��ߣ�    leiyin 
//      �޸�ʱ�䣺  2011-8-18
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
//ͷ�ļ�

#include "conio.h"	//����CC65�ṩ�Ŀ�
#include "nes.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "types.h"	 //���Ͷ����ļ�

//----------------------------------------------------
//�궨��

#define true	1
#define false	0
#define NULL	0

//�����Ƶ������ʾ�����������ҷֱ�λ��7 6 5 4 3 2 1 0λ
#define bin(_a,_b,_c,_d,_e,_f,_g,_h) ((_a)<<7|(_b)<<6|(_c)<<5|(_d)<<4|(_e)<<3|(_f)<<2|(_g)<<1|(_h))	//�����Ƶı�ʾ

//λ��ʾ
#define bit0	0x01	//��0λ
#define bit1	0x02	//��1λ
#define bit2	0x04	//��2λ
#define bit3	0x08	//��3λ
#define bit4	0x10	//��4λ
#define bit5	0x20	//��5λ
#define bit6	0x40	//��6λ
#define bit7	0x80	//��7λ

#define upperbyte(_value)		((uint8)((_value)>>8))		//ȡ���ֽ�
#define lowerbyte(_value)		((uint8)(_value))			//ȡ���ֽ�

//�ֱ����:
#define joystick_1	0x4016				//�����ֱ���ӳ��
#define joystick_2	0x4017

#define button_A		0x80			//��ťA
#define button_B		0x40			//��ťB
#define button_SELECT	0x20			//��ťSELECT
#define button_START	0x10			//��ťSTART
#define button_UP		0x08			//��ťUP
#define button_DOWN		0x04			//��ťDOWN
#define button_UD		0x0C			//���¼�����
#define button_LEFT		0x02			//��ťLEFT
#define button_RIGHT	0x01			//��ťRIGHT
#define button_LR		0x03			//���Ҽ�����
#define button_DRT		0x0F			//���������
#define button_ANY		0xff			//���������

#define presskey(k)	(key & (k))
#define iskey(k)	(key == (k))
#define downkey(k)	(((k)&okey)!=((k)&key) && (k)&key )
#define upkey(k)	(((k)&okey)!=((k)&key) && (k)&okey)
#define read_joy()  read_joystick(joystick_1)//Ĭ�ϵ��ֱ���ȡ����ȡ�ֱ�1��

//----------------------------------------------------
//�����ͱ�������
uint8 read_joystick(uint16 _joystick);//���ֱ�����

#endif //�ļ�����