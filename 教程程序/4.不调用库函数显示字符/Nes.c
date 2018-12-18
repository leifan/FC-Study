#include "nes.h"  
#include "types.h"	 //类型定义文件				    
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
   address(0x2007)=0x11; 
     
   //文本颜色
   address(0x2006)=0x3f;  
   address(0x2006)=0x03;   
   address(0x2007)=0x30; 

   //显示字符’A'
   //adr=0x2000+x+y*0x20;
   address(0x2006)=0x23;  
   address(0x2006)=0x91;   
   address(0x2007)=65; 
   //控制水平，垂直滚动
   address(0x2005)=0x00; 
   address(0x2005)=0x00;  
   while(1)
   {
      ;
   }
}
