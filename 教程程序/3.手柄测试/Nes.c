#include "stdio.h"
#include "conio.h"
#include "nes.h"  
#include "types.h"	 //类型定义文件
#include "comm.h"	 //常用函数接口头文件
//--------------------------------------------
//变量定义	
uint8 key;  //按键值
uint8 okey; //按键旧值						    
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

  uint8 x=0,y=0,ox,oy,c=23,oc=0;

    clrscr();//清屏	
  //设置背景颜色
    bgcolor(COLOR_BLUE);
  //设置文本颜色
    textcolor(0x30);//这个函数不能用,在这里用了宏
	cprintf("please enter botton,and view.");
  while(1)
  {		
	  key=read_joy();   //读取手柄一的键值
      if(presskey(button_RIGHT))x++; //presskey()事件
      if(presskey(button_LEFT)) x--;
      if(presskey(button_UP))   y--; 
      if(presskey(button_DOWN)) y++;
      if(downkey(button_SELECT))c++; //downkey()事件
      if(downkey(button_START)) c--;
      if(upkey(button_A))       c++; //upkey()事件
      if(upkey(button_B))       c--;
	  if(x>=32)x=32;
	  if(x<=0) x=0;
	  if(y>=27)y=27;
	  if(y<=0) y=0;
	  if(x!=ox||y!=oy||oc!=c)
	  {
		  clrscr();
		  gotoxy(x,y);
		  cprintf("%u",c);
		  delay(10);//延时 
		  ox=x;oy=y;oc=c;
	  }  
	  okey=key;    //刷新okey		
  }
}

