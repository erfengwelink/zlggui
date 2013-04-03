/***************************************************
**HAL.c
**��Ҫ����оƬӲ�����ڲ���Χ���ⲿ��Χ�ĳ�ʼ��������INIT����
**��MAIN�е��ã�ʹMAIN�����о�����Ӳ�����޹�
***************************************************/

#include "..\\STM32Lib\\stm32f10x.h"

#include "..\\USER\\AppOpts.h"
//#include "..\\Logger\\Debug.h"
#include ".\\hal.h"


//�����ڲ�Ӳ��ģ������ú���
extern void GPIO_Configuration(void);			//GPIO
extern void RCC_Configuration(void);			//RCC
extern void USART_Configuration(void);					//����


extern void NVIC_Configuration(void);			//NVIC
extern void OLED_Configuration(void);
extern void TIMER_Configuration(void);
extern char printf_buf[];
extern void init_printf(void* putp,void (*putf) (void*,char));
extern void tfp_printf(char *fmt, ...);
extern void uart1_putc(void * ptr,char c);

/*******************************
**������:ChipHalInit()
**����:Ƭ��Ӳ����ʼ��
*******************************/
void  ChipHalInit(void)
{
	//��ʼ��ʱ��Դ
	RCC_Configuration();
	
	//��ʼ��GPIO
	GPIO_Configuration();
	//��ʼ������
	USART_Configuration();
	init_printf(printf_buf,uart1_putc);
	tfp_printf("tfp_printf Inital over\n");

	TIMER_Configuration();

	//��ʼ���жϣ���ucos������ִ�У����а���������1�������ж����ȼ���2��ʹ���ж�
	//NVIC_Configuration();

//	OLED_Configuration();
}


/*********************************
**������:ChipOutHalInit()
**����:Ƭ��Ӳ����ʼ��
*********************************/
extern u8 CML_FirmwareDownload(void);
void  ChipOutHalInit(void)
{
// 	if(CML_FirmwareDownload()){
// 		
// 		LWIP_ERROR(("CML_FirmwareDownload fail\n"));
// 	}else{
// 	   	LWIP_DEBUGF(CML_DEBUG,("CML_FirmwareDownload success\n"));
// //		do { if (((CML_DEBUG) & DBG_ON)&& ((CML_DEBUG) & DBG_TYPES_ON)
// //		&& ((u16)((CML_DEBUG)& DBG_MASK_LEVEL) >= DBG_MIN_LEVEL))
// //		{LWIP_PLATFORM_DIAG(("*******CML_FirmwareDownload success\n")); 
// //			if ((CML_DEBUG) & DBG_HALT) while(1); } } while(0);
// 	}	
}
