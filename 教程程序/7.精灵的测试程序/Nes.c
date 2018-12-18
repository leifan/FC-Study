#include "comm.h"    //接口驱动的.H文件
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
//设置精灵调色板对应的调色板的颜色
//--------------------------------------------- 	
void set_SPcolor(uint8 n,uint8 m,uint8 color)
{
   address(0x2006)=0x3f;  
   address(0x2006)=0x10+n*4+m;   
   address(0x2007)=color;   
} 	    
//---------------------------------------------
//主函数
//---------------------------------------------
void main(void)
{
    uint8 key,x=100,y=60;

      address(0x2000) = 0x80;     
      address(0x2001) = 0x1e;     

	  set_color(0,0,0x0f);   //背景
	  	
	  set_color(0,1,0x11);   //背景调色板0	
	  set_color(0,2,0x15);	
	  set_color(0,3,0x30);	

	  set_color(1,1,0x11);   //背景调色板1	
	  set_color(1,2,0x15);	
	  set_color(1,3,0x30);	
	
	  set_color(2,1,0x11);   //背景调色板2	
	  set_color(2,2,0x15);	
	  set_color(2,3,0x30);	

	  set_color(3,1,0x11);   //背景调色板3	
	  set_color(3,2,0x15);	
	  set_color(3,3,0x30);	

	  //精灵
	  set_SPcolor(0,1,0x11); //精灵调色板0	
	  set_SPcolor(0,2,0x15);	
	  set_SPcolor(0,3,0x30);	

	  set_SPcolor(1,1,0x11); //精灵调色板1	
	  set_SPcolor(1,2,0x15);	
	  set_SPcolor(1,3,0x30);	
	
	  set_SPcolor(2,1,0x11); //精灵调色板2	
	  set_SPcolor(2,2,0x15);	
	  set_SPcolor(2,3,0x30);	

	  set_SPcolor(3,1,0x11); //精灵调色板3	
	  set_SPcolor(3,2,0x15);	
	  set_SPcolor(3,3,0x30);	
 
      while(1)
	  {
           key=read_joy();

           if(presskey(button_UP))--y;
           if(presskey(button_DOWN))++y;
           if(presskey(button_LEFT))--x;
           if(presskey(button_RIGHT))++x;

           waitvblank();      

           putSP(0,x,y,255,0);

           gotoxy(0,0);
           cprintf("x:%-3d y:%-3d",x,y);     

      }
}
