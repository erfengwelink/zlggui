/**
**********************************************************************
*@file 
*@brief
*@author   ������ rundream1314@gmail.com
*@date
*@version
***********************************************************************
*/

#include "..\\User\\Common.h"
//#include "..\\User\\AppTask.h"
void 	TskGuiProc(void *p_arg)//30
{

	volatile	INT8U err;
		TLOG("TskGuiProc start Prio=%02d\n",OSTCBCur->OSTCBPrio);
		GUI_Initialize();				// ��ʼ��LCM
 		GUI_SetColor(1, 0);//����ǰ��ɫ�ͱ���ɫ��
		DispLog();						// ��ʾLOG
		RunMenuDemo();					// ��ʾ�˵�
		for(;;)
	{	   

		OSTimeDly(OS_TICKS_PER_SEC);//
		
	}
};
