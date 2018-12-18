#include "comm.h"    //�ӿ�������.H�ļ�
//---------------------------------------------
//���ñ�����ɫ���Ӧ�ĵ�ɫ�����ɫ
//---------------------------------------------
//     n: ѡ���趨�ĵ�ɫ��ı��
//     m: ѡ���趨����ɫ��
// color: �趨����ɫֵ	
void set_color(uint8 n,uint8 m,uint8 color)
{
   address(0x2006)=0x3f;  
   address(0x2006)=0x00+n*4+m;   
   address(0x2007)=color;   
} 
//---------------------------------------------
//���þ����ɫ���Ӧ�ĵ�ɫ�����ɫ
//--------------------------------------------- 	
void set_SPcolor(uint8 n,uint8 m,uint8 color)
{
   address(0x2006)=0x3f;  
   address(0x2006)=0x10+n*4+m;   
   address(0x2007)=color;   
} 	    
//---------------------------------------------
//������
//---------------------------------------------
void main(void)
{
    uint8 key,x=100,y=60;

      address(0x2000) = 0x80;     
      address(0x2001) = 0x1e;     

	  set_color(0,0,0x0f);   //����
	  	
	  set_color(0,1,0x11);   //������ɫ��0	
	  set_color(0,2,0x15);	
	  set_color(0,3,0x30);	

	  set_color(1,1,0x11);   //������ɫ��1	
	  set_color(1,2,0x15);	
	  set_color(1,3,0x30);	
	
	  set_color(2,1,0x11);   //������ɫ��2	
	  set_color(2,2,0x15);	
	  set_color(2,3,0x30);	

	  set_color(3,1,0x11);   //������ɫ��3	
	  set_color(3,2,0x15);	
	  set_color(3,3,0x30);	

	  //����
	  set_SPcolor(0,1,0x11); //�����ɫ��0	
	  set_SPcolor(0,2,0x15);	
	  set_SPcolor(0,3,0x30);	

	  set_SPcolor(1,1,0x11); //�����ɫ��1	
	  set_SPcolor(1,2,0x15);	
	  set_SPcolor(1,3,0x30);	
	
	  set_SPcolor(2,1,0x11); //�����ɫ��2	
	  set_SPcolor(2,2,0x15);	
	  set_SPcolor(2,3,0x30);	

	  set_SPcolor(3,1,0x11); //�����ɫ��3	
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
