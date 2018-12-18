//====================================================
//	接口驱动的.C文件
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
#define  comm_GLOBALS

#include "comm.h"

//----------------------------------------------------
//读手柄函数
//----------------------------------------------------
uint8 read_joystick(uint16 _joystick)			
{
	uint8 n=8,joy_state=0;
	address(_joystick)=01;		//对_joystick写01
	address(_joystick)=00;		//对_joystick写00
	while(n){
		joy_state=(joy_state<<1)|address(_joystick)&1;
		--n;
	}
	return joy_state;
}

