/**
*****************************************************************************************
*@file 
*@brief
*@author
*@date
*@version
*****************************************************************************************
*/
/**
*************************************************************************************
*@brief
*@author
*@param
*@param
*@return
**************************************************************************************
*/
#include "..\\User\\common.h"
#include "stm32f10x.h"
#include ".\\Hal.h"

u16 Time3_Counter = 0;
u16 nTime3 = 0;
u16 Time4_Counter = 0;
u16 nTime4 = 0;
#define MAX_100US_TIMER 8
sys_timeout time100us[MAX_100US_TIMER];

/*
void TIMER4_US_MS_Config(bool Magnitude)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	if(Magnitude == MS)
	{
		TIM_DeInit(TIM4);
		TIM_TimeBaseStructure.TIM_Period = 8000;//   
		TIM_TimeBaseStructure.TIM_Prescaler = SystemFrequency/8000000 - 1;    	//Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���
		TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;  	//
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���	
		TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	//	ʹ��Ԥװ��
		TIM_ARRPreloadConfig(TIM4, ENABLE);
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update);
	}
	else if(Magnitude == US)
	{
		TIM_DeInit(TIM4);
		TIM_TimeBaseStructure.TIM_Period = 8;
		TIM_TimeBaseStructure.TIM_Prescaler = SystemFrequency/8000000 - 1; //Ԥ��Ƶ,��ֵ+1Ϊ��Ƶ�ĳ���
		TIM_TimeBaseStructure.TIM_ClockDivision = 0;  //
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//���ϼ���	
		TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);			
		TIM_ARRPreloadConfig(TIM4, ENABLE);
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update);
	}
}
*/

void TIMER_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);


	/* TIM2 configuration */
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructure.TIM_Period =60000/100;//
	TIM_TimeBaseStructure.TIM_Prescaler =SystemFrequency/60000; //8000000
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	/*ʹ��Ԥװ��*/
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	TIM_ClearITPendingBit(TIM2, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4|TIM_IT_Update);
    /* Enable TIM2 Update interrupt [TIM2����ж�����]*/
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); 
    /* TIM2 enable counter [����tim2����]*/
    TIM_Cmd(TIM2, ENABLE);   

}



void Start_CountingKey(void)
{
	/*����������ж�*/
	TIM_ITConfig(TIM3,TIM_IT_Update, ENABLE);	
	/* ����TIM2��ʼ���� */
	TIM_Cmd(TIM3, ENABLE);
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

void TIM2_IRQ(void)
{
	
}

void Stop_CountingKey(void)
{
	/*����������ж�*/
	TIM_ITConfig(TIM3,TIM_IT_Update, DISABLE);	
	/* ����TIM2��ʼ���� */
	TIM_Cmd(TIM3, DISABLE);
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
bool ms_Timer_EN = FALSE;
void DelayUS(u16 Time)  //Millisecond = 1-->ms;= 0 --> us
{
	u16 i=10;
	while(Time--){
		i=10;
		while(i--);
	}
	

}

void DelayMS(u16 Time)
{
	u16 i=1200;
	while(Time--){
		i=1200;
		while(i--);
	}	
}


/**
***********************************************************************
*@brief	������10���Զ��������ʱ���Ľṹ��ռ�
typedef struct sys_timeout {
	u8 time_type;	   			//��ʱ���ͣ�һ���еģ��������ڵ�
  	struct sys_timeout *next;	//��һ��ʱ����	
	sys_timeout_handler handler;//�ص�����		
  	void *arg;			   		//�ص�����	
	u32 ticks_reload;			//���ڶ�ʱ������ֵ	
  	u32 ticks_counter;			//����ֵ	
}sys_timeout;
	һ��creat�˿���stop���ǲ�֧��del��del��ռ�Ҳ��û�л��գ�����������create

*@author   ������ rundream1314@gmail.com
*@param
*@param
*@return
************************************************************************
*/

SysTimeOut AppTimer[10];

void TimerWheel(SysTimeOut AppTimer[])
{
	u8 i=0;
//	while(AppTimer[i].next!=NULL)
for(i=0;i<MAX_TIMER_NUM;i++)
	{
		 //if(AppTimer[i].ticks_counter>0){}
		if(AppTimer[i].time_type==Preiod)
		{
			if(AppTimer[i].ticks_counter==0){

				AppTimer[i].handler(AppTimer[i].arg);//ִ�к���
				AppTimer[i].ticks_counter=AppTimer[i].ticks_reload;
			}
		   	AppTimer[i].ticks_counter--;
				
		}else if(AppTimer[i].time_type==Once){
			
			if(AppTimer[i].ticks_counter==1){//Ϊ�˱���==0��ʱ���ظ�ִ�У���������==1
				AppTimer[i].handler(AppTimer[i].arg);//ִ�к���			
			}
			if(AppTimer[i].ticks_counter){//ֻ���ڴ���0��ʱ���--��==0��ʱ��Ͳ�����
				AppTimer[i].ticks_counter--;		
			}
			
		}else if(AppTimer[i].time_type==Paulse){//���������ͣ��ʱ����
				
		};	
	}	
};

SysTimeOut * AppTimerCreat(enum TimerType time_type,sys_timeout_handler handler,void *arg,u32 ticks_reload)
{
	u8 i;
	for(i=0;(AppTimer[i].time_type!=UnUsed)&&(i<MAX_TIMER_NUM);i++);//Ѱ�ҿ��еĵ�һ��λ��
	if(i>=MAX_TIMER_NUM){
		ELOG("timer creat err\n");
		return NULL;
	}else{
		//AppTimer[i]
		if(i>0){
			AppTimer[i-1].next=&AppTimer[i];
		}
		AppTimer[i].time_type=time_type;
		AppTimer[i].handler=handler;
		AppTimer[i].arg=arg;
		AppTimer[i].ticks_reload=ticks_reload;
		AppTimer[i].ticks_counter=ticks_reload;
		return &AppTimer[i];
	}
			
}
/**
***********************************************************************
*@brief	 ����once���Ͷ�ʱ����
*@author   ������ rundream1314@gmail.com
*@param
*@param
*@return
************************************************************************
*/
void ResetOnce(SysTimeOut * pTimer,u32 Ticks){

	if(pTimer!=NULL){	
		pTimer->time_type=Once;
		pTimer->ticks_counter=Ticks;
	}
}



/************************************************************************
*/

