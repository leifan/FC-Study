
#include "nes.h"  
#include "types.h"	 //类型定义文件
				    
//---------------------------------------------
//延时函数
//---------------------------------------------
void delay(int i)
{
   while(i--)
   {
		waitvblank();//等待垂直中断
   }
}		    
//---------------------------------------------
//主函数
//---------------------------------------------
void main(void)
{
  //设置PPU
   address(0x2000)=0x00;   //PPU Control #1
   address(0x2001)=0x1c;   //PPU Control #2

   //背景配色
   address(0x2006)=0x3f;  
   address(0x2006)=0x00;   
   address(0x2007)=0x11;   //蓝色

   //延时
   delay(50); 

   //精灵配色
   address(0x2006)=0x3f;  
   address(0x2006)=0x10;   
   address(0x2007)=0x30;   //亮白

   while(1)
   {
      ;
   }
}
