
#include "nes.h"  
#include "types.h"	 //���Ͷ����ļ�			    

//---------------------------------------------
//��Ӧ������������ַ�
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
//������
//---------------------------------------------
void main(void)
{
   uint8 i=0,j=0;

  //����PPU
   address(0x2000)=0x00;   //PPU Control #1
   address(0x2001)=0x1c;   //PPU Control #2

   //������ɫ
   set_color(0,0,0x0f);	//��ɫ
     
   //���õ�0��--3�ŵ�ɫ���3����ɫ
   set_color(0,3,0x30);	//����
   set_color(1,3,0x15);	//��ɫ
   set_color(2,3,0x2a);	//����
   set_color(3,3,0x34);	//��ɫ

   //��ʾ4*4���ַ�����
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
	   	 
   //�趨���Ա�
   address(0x2006)=0x23;  
   address(0x2006)=0xc0;   
   address(0x2007)=0xe4;   //1110 0100

   //����ˮƽ����ֱ����
   address(0x2005)=0x00; 
   address(0x2005)=0x00;  

   while(1)
   {
      ;
   }
}
