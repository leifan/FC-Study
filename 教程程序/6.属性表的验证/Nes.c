
#include "nes.h"  
#include "types.h"	 //类型定义文件			    

//---------------------------------------------
//对应坐标输出单个字符
//---------------------------------------------	
void put_char(uint8 x,uint8 y,uint8 c)	 
{
     uint16 adr=0x2000;

	 adr=adr+0x20*y+x;

	 address(0x2006)=adr>>8;  
	 address(0x2006)=(uint8)adr;   
	 address(0x2007)=c; 

} 
//---------------------------------------------
//设置背景调色板对应的调色板的颜色
//---------------------------------------------
//     n: 选择设定的调色板的标号
//     m: 选择设定的颜色号
// color: 设定的颜色值	
void set_color(uint8 n,uint8 m,uint8 color)
{
   address(0x2006)=0x3f;  
   address(0x2006)=0x00+n*4+m;   
   address(0x2007)=color;   
}  
//---------------------------------------------
//主函数
//---------------------------------------------
void main(void)
{
   uint8 i=0,j=0;

  //设置PPU
   address(0x2000)=0x00;   //PPU Control #1
   address(0x2001)=0x1c;   //PPU Control #2

   //背景配色
   set_color(0,0,0x0f);	//黑色
     
   //设置第0号--3号调色板的3号颜色
   set_color(0,3,0x30);	//亮白
   set_color(1,3,0x15);	//红色
   set_color(2,3,0x2a);	//亮绿
   set_color(3,3,0x34);	//粉色

   //显示4*4的字符数阵
   for(i=0;i<4;i++)
   	  for(j=0;j<4;j++)
	   {
		  if(j<2) 
		  {
		  	put_char(i,j,48+i/2+j/2);
		  }
		  else
		  {
		  	put_char(i,j,48+i/2+j/2+1);
		  }
	   }
	   	 
   //设定属性表
   address(0x2006)=0x23;  
   address(0x2006)=0xc0;   
   address(0x2007)=0xe4;   //1110 0100

   //控制水平，垂直滚动
   address(0x2005)=0x00; 
   address(0x2005)=0x00;  

   while(1)
   {
      ;
   }
}
