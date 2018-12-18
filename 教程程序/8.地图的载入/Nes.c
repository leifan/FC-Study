#include "comm.h"    //�ӿ�������.H�ļ�
#include "map.h" //��ͼ����
#include "col.h" //��ɫ����Ϣ

//---------------------------------------------
//������
//---------------------------------------------
void main(void)
{
    uint8 key,okey;
	disable_graphics(); //����ʾ
	load_full_name_0((uint8*)map); //�����ͼ����
	load_BG_palette((uint8*)col);//���뱳����ɫ��
	load_SP_palette((uint8*)col);//���뾫���ɫ��
	enable_graphics();  //����ʾ
	sound_init();	//������
	while(1)
	{  
	    key = read_joy();
	    if(downkey(button_A))
	    {	
			sound(sound_chn_0,0x8f,0xaa,0xaa,0x80);		//����0����
		}						   
		if(downkey(button_B))
		{
			sound(sound_chn_1,0x89,0x89,0xef,0x08);	 	//����1����
		}
		okey=key;
	}
}
