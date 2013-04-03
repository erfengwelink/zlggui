

#include "main_include.h "

/**
*************************************************************************************
*@brief
*@author ������  rundream@gmail.com
*@param
*@param
*@return
**************************************************************************************
*/
int main(void)
{
	volatile u8 os_err;
	
	//����ʹ��UCOS,һ�µĳ�ʼ����Ȼ������OS����֮ǰ����,��ע���ʹ���κ��ж�.
//	CLI(); //�ر����ж� 
	ChipHalInit();			//Ƭ��Ӳ����ʼ��	 
	init_printf(printf_buf,uart1_putc);
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

void TaskStart(void *p_arg)
{
	volatile u8 os_err;
	INT8U TskIndex=0;
	
	
	OS_CPU_SysTickInit();	//ʹ��SYSTICK�ж�
	
#if (OS_TASK_STAT_EN > 0)
    OSStatInit();       /*�ⶫ�����Բ���CPUʹ���� */
#endif
	

	pUSART1MsgQ=OSQCreate(&UsartQue[0],N_Message);
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


