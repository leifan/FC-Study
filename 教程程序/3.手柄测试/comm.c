//====================================================
//	�ӿ�������.C�ļ�
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
#define  comm_GLOBALS

#include "comm.h"

//----------------------------------------------------
//���ֱ�����
//----------------------------------------------------
uint8 read_joystick(uint16 _joystick)			
{
	uint8 n=8,joy_state=0;
	address(_joystick)=01;		//��_joystickд01
	address(_joystick)=00;		//��_joystickд00
	while(n){
		joy_state=(joy_state<<1)|address(_joystick)&1;
		--n;
	}
	return joy_state;
}

