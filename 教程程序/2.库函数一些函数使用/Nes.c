#include "stdio.h"
#include "conio.h"
#include "nes.h"  
#include "types.h"	 //���Ͷ����ļ�
//--------------------------------------------
//��������
const uint8 string[][25]={ "How are you ?        ",
                           "I'm fine,Thank you!  ",
						   "HohO,Let's study NES.",
						   "OK,Let's go!         ",
						   "_____________________"};	 
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

  uint8 i,x,y;

  clrscr();//����	
  //���ñ�����ɫ
  bgcolor(COLOR_BLUE);
//�����ע�����Ͼ�һ����˼ 	
//  address(0x2006) = 0x3F;  //�ߵ�ַ
//  address(0x2006) = 0x00;  //�͵�ַ
//  address(0x2007) = 0x02;  //����

  //�����ı���ɫ
  textcolor(0x30);//�������������,���������˺�
//    address(0x2006) = 0x3F; 
//    address(0x2006) = 0x03; //������ɫΪ������ɫ��ĵ�ɫ��0�ĵ�3����ɫ
//    address(0x2007) = 0x30; //����

	//����
	cputsxy(11,8,"LEI YIN");//�̶���������ı�
    gotoxy(10,5); 
    screensize(&x,&y); //��ȡ��Ļ�ߴ�
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
			delay(50);//��ʱ	
		}
		
  }
}

