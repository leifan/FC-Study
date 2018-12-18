#include "stdio.h"
#include "conio.h"
#include "nes.h"  
#include "types.h"	 //类型定义文件
//--------------------------------------------
//变量定义
const uint8 string[][25]={ "How are you ?        ",
                           "I'm fine,Thank you!  ",
						   "HohO,Let's study NES.",
						   "OK,Let's go!         ",
						   "_____________________"};	 
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

  uint8 i,x,y;

  clrscr();//清屏	
  //设置背景颜色
  bgcolor(COLOR_BLUE);
//下面的注释与上句一个意思 	
//  address(0x2006) = 0x3F;  //高地址
//  address(0x2006) = 0x00;  //低地址
//  address(0x2007) = 0x02;  //数据

  //设置文本颜色
  textcolor(0x30);//这个函数不能用,在这里用了宏
//    address(0x2006) = 0x3F; 
//    address(0x2006) = 0x03; //文字颜色为背景调色板的调色板0的第3号颜色
//    address(0x2007) = 0x30; //亮白

	//画框
	cputsxy(11,8,"LEI YIN");//固定坐标输出文本
    gotoxy(10,5); 
    screensize(&x,&y); //读取屏幕尺寸
    cprintf("x=%u,y=%u",x,y);
	x=4,y=1;
    chlinexy(x,y,24);
	chlinexy(x,y+24,24);
    cvlinexy(x-1,y+1,23);
    cvlinexy(x+24,y+1,23);

  while(1)
  {		 
		for(i=0;i<4;i++)
		{
			if(i%2==0)
			{
			   cputsxy(6,12,string[i]);
			   cputsxy(6,14,string[4]);
			}
			else
			{
			   cputsxy(6,12,string[4]);
			   cputsxy(6,14,string[i]);
			}
			delay(50);//延时	
		}
		
  }
}

