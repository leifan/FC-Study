#include "stdio.h"
#include "conio.h"
#include "nes.h"  
#include "types.h"	 //���Ͷ����ļ�
#include "comm.h"	 //���ú����ӿ�ͷ�ļ�
//--------------------------------------------
//��������	
uint8 key;  //����ֵ
uint8 okey; //������ֵ						    
//---------------------------------------------
//��ʱ����
//---------------------------------------------
void delay(int i)
{
   while(i--)
   {
		waitvblank();//�ȴ���ֱ�ж�
   }
}
//---------------------------------------------
//������
//---------------------------------------------
void main(void)
{

  uint8 x=0,y=0,ox,oy,c=23,oc=0;

    clrscr();//����	
  //���ñ�����ɫ
    bgcolor(COLOR_BLUE);
  //�����ı���ɫ
    textcolor(0x30);//�������������,���������˺�
	cprintf("please enter botton,and view.");
  while(1)
  {		
	  key=read_joy();   //��ȡ�ֱ�һ�ļ�ֵ
      if(presskey(button_RIGHT))x++; //presskey()�¼�
      if(presskey(button_LEFT)) x--;
      if(presskey(button_UP))   y--; 
      if(presskey(button_DOWN)) y++;
      if(downkey(button_SELECT))c++; //downkey()�¼�
      if(downkey(button_START)) c--;
      if(upkey(button_A))       c++; //upkey()�¼�
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
		  delay(10);//��ʱ 
		  ox=x;oy=y;oc=c;
	  }  
	  okey=key;    //ˢ��okey		
  }
}

