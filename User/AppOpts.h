/**
*************************************************************************
*@brief	 ����ȫ���ı���ѡ��
*@author ������  rundream@gmail.com
*@param
*@param
*@return
*************************************************************************
*/


#ifndef APP_OPTS_H
#define APP_OPTS_H
#include "..\\Logger\\Debug.h"
/////////////////////
#define MAX_TIMER_NUM 10







///////////////



/* ������LWIP �ĵ��Է�����Debugging options all default to off */


#ifndef DBG_TYPES_ON
#define DBG_TYPES_ON                    DBG_ON//���������ǲ�ͬ�ģ�Ӧ�ÿ����õ�ѡ����DBG_TRACEһ���
#endif

#ifndef DBG_MIN_LEVEL
#define DBG_MIN_LEVEL                   DBG_LEVEL_OFF
#endif

#ifndef GUI_DEBUG
#define GUI_DEBUG                    	DBG_ON
#endif

#ifndef LCD_DEBUG
#define LCD_DEBUG                    	DBG_ON
#endif
#endif

/*************************************************************************
*/

