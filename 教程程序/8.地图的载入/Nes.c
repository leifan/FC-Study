#include "comm.h"    //接口驱动的.H文件
#include "map.h" //地图数据
#include "col.h" //调色板信息

//---------------------------------------------
//主函数
//---------------------------------------------
void main(void)
{
    uint8 key,okey;
	disable_graphics(); //关显示
	load_full_name_0((uint8*)map); //载入地图数据
	load_BG_palette((uint8*)col);//载入背景调色板
	load_SP_palette((uint8*)col);//载入精灵调色板
	enable_graphics();  //开显示
	sound_init();	//打开声音
	while(1)
	{  
	    key = read_joy();
	    if(downkey(button_A))
	    {	
			sound(sound_chn_0,0x8f,0xaa,0xaa,0x80);		//声道0发声
		}						   
		if(downkey(button_B))
		{
			sound(sound_chn_1,0x89,0x89,0xef,0x08);	 	//声道1发声
		}
		okey=key;
	}
}
