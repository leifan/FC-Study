#include "nes.h"  
#include "types.h"	 //���Ͷ����ļ�				    
//---------------------------------------------
//������
//---------------------------------------------
void main(void)
{
  //����PPU
   address(0x2000)=0x00;   //PPU Control #1
   address(0x2001)=0x1c;   //PPU Control #2

   //������ɫ
   address(0x2006)=0x3f;  
   address(0x2006)=0x00;   
   address(0x2007)=0x11; 
     
   //�ı���ɫ
   address(0x2006)=0x3f;  
   address(0x2006)=0x03;   
   address(0x2007)=0x30; 

   //��ʾ�ַ���A'
   //adr=0x2000+x+y*0x20;
   address(0x2006)=0x23;  
   address(0x2006)=0x91;   
   address(0x2007)=65; 
   //����ˮƽ����ֱ����
   address(0x2005)=0x00; 
   address(0x2005)=0x00;  
   while(1)
   {
      ;
   }
}
