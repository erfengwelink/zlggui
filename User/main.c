/**
**********************************************************************
*@file 
*@brief
*@author   ������ rundream1314@gmail.com
*@date
*@version
***********************************************************************
*/

#include "main_include.h "

/**
*************************************************************************
*@brief
*@author ������  rundream@gmail.com
*@param
*@param
*@return
*************************************************************************
*/
int main(void)
{
	volatile INT8U os_err;
	
	//����ʹ��UCOS,һ�µĳ�ʼ����Ȼ������OS����֮ǰ����,��ע���ʹ���κ��ж�.
	CLI(); //�ر����ж� 
	ChipHalInit();			//Ƭ��Ӳ����ʼ��	 

	ChipOutHalInit();		//Ƭ��Ӳ����ʼ��
	OSInit();				//UCOS INIT~

	os_err = OSTaskCreate( TaskStart,									//��һ������0
                          (void          * ) 0,							//��������
                          (OS_STK        * )&TaskStartStk[128-1],			//��ջָ��
                          (INT8U           ) START_TSK_PRIO				//���ȼ�
                         );
	OSStart(); 
	
	while(1);
}
/**
*************************************************************************************
*@brief
*@author ������  rundream@gmail.com
*@param
*@param
*@return
**************************************************************************************
*/
void OS_EventInital(void);

void TaskStart(void *p_arg)
{
	volatile INT8U os_err;
	INT8U TskIndex=0;
	
	
	OS_CPU_SysTickInit();	//ʹ��SYSTICK�ж�
	
#if (OS_TASK_STAT_EN > 0)
    OSStatInit();       /*�ⶫ�����Բ���CPUʹ���� */
#endif
	

	//��ʼ����Ҫ���ź�����os ��ʱ�������ݡ�
	OS_EventInital();
	
	while(TskFunArray[TskIndex]!=NULL)
	{
	 	os_err=OSTaskCreate(TskFunArray[TskIndex],
						(void *)0,
						(OS_STK*)&TaskStk[TskIndex][TSK_STK_DEPTH-1],
						(INT8U)(APP_BASE_TSK_PRIO+TskIndex*2+1)
						);
		switch(os_err)
		{
			case(OS_ERR_NONE):	break; 
			default:
				ELOG("error:TskIndex==%d\n",TskIndex);
				while(1);
					break;					 		
		}
		TskIndex++;		
	}
	
		//ʹ�����������ж�
	NVIC_Configuration();
	SEI(); //�������ж�
	
	for(;;)
	{
		OSTimeDly(OS_TICKS_PER_SEC);
		LedOperate(LED1,LedOn);
		OSTimeDly(OS_TICKS_PER_SEC);
		LedOperate(LED1,LedOff);
	}

}
/**
***********************************************************************
*@brief
*@author   ������ rundream1314@gmail.com
*@param
*@param
*@return
************************************************************************
*/
void OS_EventInital(void)
{
		INT8U os_err;
		pUSART1MsgQ=OSQCreate(&UsartQue[0],N_Message);
		pAppMsgQ=OSQCreate(&AppQue[0],N_Message);
	  pSimKeyMsgQ=OSQCreate(&SimKeyQue[0],N_Message);
		/*OS_TMR  *OSTmrCreate (
					  INT32U           dly,
                      INT32U           period,
                      INT8U            opt,
                      OS_TMR_CALLBACK  callback,
                      void            *callback_arg,
                      INT8U           *pname,
                      INT8U           *perr)*/
		pSoftTmr1=OSTmrCreate(
						2,
						1,
						OS_TMR_OPT_PERIODIC,
						NULL,
						NULL,
						"SoftTmr1",
						&os_err
						);
		pCMX7141ScanTimer=AppTimerCreat(Preiod,Led1Toggle,NULL,10);	
		
}

/**************************************************************************************
*/

