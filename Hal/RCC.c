#include "..\\STM32Lib\\stm32f10x.h"

RCC_ClocksTypeDef RCC_ClockFreq;

void RCC_Configuration(void)
{
	SystemInit();//Դ��system_stm32f10x.c�ļ�,ֻ��Ҫ���ô˺���,������RCC������.�����뿴2_RCC

	/**************************************************
	��ȡRCC����Ϣ,������
	��ο�RCC_ClocksTypeDef�ṹ�������,��ʱ��������ɺ�,
	���������ֵ��ֱ�ӷ�ӳ�������������ֵ�����Ƶ��
	***************************************************/
	RCC_GetClocksFreq(&RCC_ClockFreq);
	
	/* ������ÿ�ʹ�ⲿ����ͣ���ʱ��,����һ��NMI�ж�,����Ҫ�õĿ����ε�*/
	//RCC_ClockSecuritySystemCmd(ENABLE);
}
