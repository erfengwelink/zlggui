/**
**********************************************************************
*@file 
*@brief
*@author   ������ rundream1314@gmail.com
*@date
*@version
***********************************************************************
*/



extern OS_EVENT * pUSART1MsgQ;//����һ�����ڵ�����
extern OS_EVENT * pAppMsgQ;//����һ�����ڵ�����;//����һ�����ڵ�����

extern AT_Commnd CommandGroup[];

extern INT8U CommandParse(INT8U *pBuf,AT_Commnd AT_Group[]);



//CallOutType CurrentCall,OldCall;