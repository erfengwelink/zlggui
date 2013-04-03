
/****************************************************************************************
* �ļ�����TEST.C
* ���ܣ�GUI���Լ���ʾ����
* ���ߣ����ܱ�
* ���ڣ�2003.09.09
****************************************************************************************/
// #include "..//STM32lib//stm32f10x.h"
// #include "..//STM32lib//stm32f10x_gpio.h"
// #include "stdio.h"
#include "..//User//common.h"
#include "..//User//KeyValDefine.h"
#include "..//ZLG_GUI//config.h""

/****************************************************************************
* ���ƣ�DelayNS()
* ���ܣ��������ʱ
* ��ڲ�����dly		��ʱ������ֵԽ����ʱԽ��
* ���ڲ�������
****************************************************************************/

void  DelayNS(uint32  dly)
{  uint32  i;

   for(; dly>0; dly--) 
      for(i=0; i<5000; i++);
}


/****************************************************************************
* ���ƣ�WaitKey()
* ���ܣ��ȴ�һ����Ч�����������ذ���ֵ����������ȥ�����ܡ�
* ��ڲ�������
* ���ڲ��������ذ�����ֵ��
****************************************************************************/

extern INT8U SimKeyPend(void);
uint8  WaitKey(void)
{  uint32  i;
   uint8   key;
   uint8   key_bak;
#if 0  
   key = 0;							// ���հ���
   while(0==key)
   {  key = GetKey();
      for(i=0; i<1000; i++);
   }
   
   key_bak = 1;
   while(0!=key_bak)				// �ȴ������ſ�
   {  key_bak =GetKey();
      for(i=0; i<1000; i++);
   }
#else
	 
	key=SimKeyPend();
#endif	 
   return(key);
}

/****************************************************************************
* ���ƣ�DispLog()
* ���ܣ���ʾLOG���ü��������Ļ(���0xAA)��
* ��ڲ�������
* ���ڲ�������
****************************************************************************/
void  DispLog(void)
{  GUI_FillSCR(0xaa);				// ���0xAA
   DelayNS(30);
}


/****************************************************************************
* ���ƣ�RunMenuDemo()
* ���ܣ����в˵�����ʾ������
* ��ڲ�������
* ���ڲ�������
****************************************************************************/

/*
typedef  struct
{  WINDOWS  *win;					// ��������
		
	uint8    no;						// ���˵�����
	uint8    state;				//	�����񣬵�ǰѡ�е���˵�
	uint8   start_disp;			//��ʼ��ʾ����
	uint8   end_disp;			//������ʾ������
	uint8   disp_num;			//����ʾ�Ĳ˵��ĸ�����
	MENU_ITEM  item[MMENU_NO];
} MENU;
*/

MENU  * pActiveMenu=NULL;//ָ��һ��ȫ�ֵĵ�ǰ�menu��ָ�롣

MENU * SetActiveMenu(MENU  * pMenu){
	pActiveMenu=pMenu;
	return pActiveMenu;
}
MENU * GetActiveMenu(void){
	return pActiveMenu;
}


void  RunMenuDemo(void)
{ 
	WINDOWS  mainwindows;
	MENU    mainmenu;
	MENU    submenu1[5];
	MENU  * p;
	void (*pFunction)(void);
	
	//   uint8    mselect;
	uint8    select=0, bak;
	uint8    key;
	  
	/* ���������ڲ���ʾ��� */
	mainwindows.x = 0;									
	mainwindows.y = 0;
	mainwindows.with = 128;
	mainwindows.hight = 64;
	mainwindows.title = (uint8 *) "liuxizhen";
	mainwindows.state = (uint8 *) "OK";
	GUI_RecDataFill(&mainwindows);	
	GUI_WindowsDraw(&mainwindows);						// ����������
	
	mainmenu.win=&mainwindows;
	mainmenu.parent_menu=NULL;
	mainmenu.name="main";
//	mainmenu.sub_menu=(struct MENU *)submenu1;//(MENU *)(&submenu1[0]);
	mainmenu.no=6;
	mainmenu.state=0;
	mainmenu.start_disp=0;
//	mainmenu.end_disp=mainwindows.hight/MENU_HIGHT;
	mainmenu.disp_num=mainwindows.RecClient.hight/MENU_HIGHT;
	mainmenu.item[0].str="1Contacts";
	mainmenu.item[0].Function=NULL;
	mainmenu.item[0].sub_menu=&submenu1[0];
	
	mainmenu.item[1].str="2Message";
	mainmenu.item[1].Function=NULL;
	mainmenu.item[1].sub_menu=&submenu1[1];

	mainmenu.item[2].str="3Setings";
	mainmenu.item[2].Function=NULL;
	mainmenu.item[2].sub_menu=&submenu1[2];
	
	mainmenu.item[3].str="4ProductInfo";
	mainmenu.item[3].Function=NULL;
	mainmenu.item[3].sub_menu=NULL;
	
	mainmenu.item[4].str="5Test";
	mainmenu.item[4].Function=NULL;
	mainmenu.item[4].sub_menu=NULL;
	
	mainmenu.item[5].str="6Debug";
	mainmenu.item[5].Function=NULL;
	mainmenu.item[5].sub_menu=NULL;
	
	submenu1[0].win=&mainwindows;
	submenu1[0].parent_menu=&mainmenu;
	submenu1[0].name="contacts";
	submenu1[0].no=2;
	submenu1[0].state=0;
	submenu1[0].start_disp=0;
//	submenu1[0].end_disp=mainwindows.hight/MENU_HIGHT;
	submenu1[0].disp_num=(submenu1[0].no<mainwindows.RecClient.hight/MENU_HIGHT)\
		?submenu1[0].no:mainwindows.RecClient.hight/MENU_HIGHT;
	submenu1[0].item[0].str="1Contacters";
	submenu1[0].item[0].Function=NULL;
	submenu1[0].item[0].sub_menu=NULL;
	submenu1[0].item[1].str="2Add New";
	submenu1[0].item[1].Function=NULL;
	submenu1[0].item[0].sub_menu=NULL;
	
	submenu1[1].win=&mainwindows;
	submenu1[1].parent_menu=&mainmenu;
	submenu1[1].name="Message";
	submenu1[1].no=2;
	submenu1[1].state=0;
	submenu1[1].start_disp=0;
	submenu1[1].disp_num=(submenu1[0].no<mainwindows.RecClient.hight/MENU_HIGHT)\
		?submenu1[0].no:mainwindows.RecClient.hight/MENU_HIGHT;
	submenu1[1].item[0].str="1NewMessage";
	submenu1[1].item[0].Function=NULL;
	submenu1[1].item[0].sub_menu=NULL;
	
	submenu1[1].item[1].str="2Receve";
	submenu1[1].item[1].Function=NULL;
	submenu1[1].item[1].sub_menu=NULL;
	
	submenu1[2].win=&mainwindows;
	submenu1[2].parent_menu=&mainmenu;
	submenu1[2].name="Setings";
	submenu1[2].no=2;
	submenu1[2].state=0;
	submenu1[2].start_disp=0;
	submenu1[2].disp_num=(submenu1[0].no<mainwindows.RecClient.hight/MENU_HIGHT)\
		?submenu1[0].no:mainwindows.RecClient.hight/MENU_HIGHT;
	submenu1[2].item[0].str="1Frenq";
	submenu1[2].item[0].Function=NULL;
	submenu1[2].item[0].sub_menu=NULL;
	
	submenu1[2].item[1].str="2Led";
	submenu1[2].item[1].Function=NULL;
	submenu1[2].item[1].sub_menu=NULL;

	
	SetActiveMenu(&mainmenu);
	GUI_MenuDraw(pActiveMenu);	
	while(1){	
		key  = WaitKey();

		switch(key){
		case(KEY_ENT):
			LWIP_DEBUGF(GUI_DEBUG|DBG_ON,("KEY_ENT:pActiveMenu->state=%d\n",pActiveMenu->state));
			if(pActiveMenu!=NULL){
				//�����������submenu��functionֻ������һ��ȥ��else�Ϳ���������Ҫ��
				if(pActiveMenu->item[pActiveMenu->state].sub_menu!=NULL){//��submenu
					SetActiveMenu((pActiveMenu->item[pActiveMenu->state].sub_menu));
					GUI_MenuDraw(pActiveMenu);
				}else if(pActiveMenu->item[pActiveMenu->state].Function!=NULL)//û���Ӳ˵����й��ܺ�������Ҫִ�й��ܺ�����
				{
					pFunction=pActiveMenu->item[pActiveMenu->state].Function;
					//(* )(void);
					(*pFunction)();//����к���ִ�к�����
				}
			}
		break;
		case(KEY_BACK):
			LWIP_DEBUGF(GUI_DEBUG|DBG_ON,("KEY_BACK:pActiveMenu->state=%d\n",pActiveMenu->state));
			if(pActiveMenu!=NULL){
				if(pActiveMenu->parent_menu!=NULL){//��submenu
					SetActiveMenu(pActiveMenu->parent_menu);
					GUI_MenuDraw(pActiveMenu);
				}
			}
		break;
		case(KEY_DOWN):
		{  
			
			LWIP_DEBUGF(GUI_DEBUG|DBG_ON,("KEY_UP:pActiveMenu->state=%d\n",pActiveMenu->state));			
			if(pActiveMenu->state<pActiveMenu->no-1){
					//pActiveMenu->state=0;
				pActiveMenu->state++;
				pActiveMenu->start_disp=pActiveMenu->state>(3)?(pActiveMenu->state-3):0;
				GUI_MenuDraw(pActiveMenu);
			}
		}	
		break;
		case(KEY_UP):
			LWIP_DEBUGF(GUI_DEBUG|DBG_ON,("KEY_DOWN:pActiveMenu->state=%d\n",pActiveMenu->state));
			if(pActiveMenu->state!=0){
				pActiveMenu->state--;
				pActiveMenu->start_disp=pActiveMenu->state>(3)?(pActiveMenu->state-3):0;
				GUI_MenuDraw(pActiveMenu);
			}
		break;
		default:break;
			
		}  
	}
		
	
	
}