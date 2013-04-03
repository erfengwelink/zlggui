/**
	@file USART_Isr.c
	@brief �����жϵ�ʵ�ʴ�����
	����������������val.h��
	@author $liuxizhen
	@version v1.0
	@date 2011��12��23��9:06:19

*/
/**
	@brief ���յ��ַ����жϴ�������
	�������Ϊ��CR���ͷ��뻺����
	�����CR���ѻ�����ָ��ͳ��ȸ�ֵ����Ϣ��ָ�룬���� ��
	Ȼ������Ϣ��
*/
#include"..//User//Common.h"
#include "..//UCOSII//ucos_ii.h"
#include "..//Hal//hal.h"
#include "..//STM32Lib//stm32f10x.h"


#define CR 0x0d
#define LF 0x0a
#define USART_MAIN USART1
#define RCV_BUF_SIZE 0xff

extern OS_EVENT * pUSART1MsgQ;
extern OS_EVENT * pUSART2MsgQ;

TskComMsg UsartRcvDataMsge;

INT8U RcvDataCounter;
INT8U RcvDataBuf[RCV_BUF_SIZE];
INT8U RcvChar;

/**
	@brief ʵ�ʱ����õĵĴ���2���жϺ���
	���յ�CR�����Ϊ�ǽ���
*/


void UsartMainIsrFun(void )
{	
	
	RcvChar=USART_ReceiveData(USART_MAIN);
	//USART_SendData(USART_DEBUG,RcvChar);
//	if((RcvChar!=LF)&&(RcvChar!=CR)&&(RcvDataCounter<RCV_BUF_SIZE))
	if((RcvChar!=LF)&&(RcvDataCounter<RCV_BUF_SIZE))
	{
		
		RcvDataBuf[RcvDataCounter]=RcvChar;
		RcvDataCounter++;
	}
//else if((RcvChar==LF)||(RcvChar==CR)||(RcvDataCounter>=RCV_BUF_SIZE))//��������CR+LF��β�ġ�
	else if((RcvChar==LF)||(RcvDataCounter>=RCV_BUF_SIZE)) //������LF�жϽ�����
	{

		RcvDataBuf[RcvDataCounter]=RcvChar;//��һ���ǰ�LFҲcopy��ȥ
		RcvDataCounter++;//����һ���ǰ�LFҲ�����ˡ���������������CR��LF����յ��ĸ���
		UsartRcvDataMsge.MsgType=UsartMainISR;
		UsartRcvDataMsge.DataLen=RcvDataCounter;
		UsartRcvDataMsge.Data.Ptr=RcvDataBuf;
		//if((RcvChar==LF)||(RcvChar==CR))
		if(RcvDataCounter>RCV_BUF_SIZE)
		{
			ELOG("RcvBufFull, err\n");	
		}else if((RcvChar==LF)&&(UsartRcvDataMsge.DataLen>2))//������LF�жϽ�����	�����һ��������Ϊ�˱�������յ�CRLF��ʱ��Ҳ�ᷢ����Ϣ�����
		{		
			OSQPost(pUSART1MsgQ,&UsartRcvDataMsge) ;
		}else if((UsartRcvDataMsge.DataLen<=2)) //������ǽ����յ���CR LF�ĵط�  ��Ȼ����ϸ������ж��յ������ݲ���CRLF
		{	
			
		};

		RcvDataCounter=0;


	}
	
}







