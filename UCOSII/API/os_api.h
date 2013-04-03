//*------------------------------------------------------------------------------------------------
//* �ļ���			   : os_api.h
//* ��������		   : os_api.c��ͷ�ļ�
//* ����    		   : ������
//* �汾			   : 0.1
//* �������ڡ�ʱ��	   : 2006/06/10 10:48
//* ����޸����ڡ�ʱ�� : 
//* �޸�ԭ��		   : 
//*------------------------------------------------------------------------------------------------

#ifndef	__os_api_h
#define	__os_api_h

//*------------------------------- �ꡢ���������������ͼ��ṹ�嶨�� ---------------------------------
typedef	OS_EVENT*	HANDLER;

//* ����һ���µ��ź���
#define		OSAPISemNew(uwCnt)				OSSemCreate(uwCnt)
//* 0�ȴ�ʱ��鿴ָ�����ź����Ƿ���ã������Ƿ���ã����������������أ��ʺ�����ISR
#define		OSAPISemWaitWith0Delay(hSem)	OSSemAccept(hSem)
//* ����һ���ź�
#define		OSAPISemSend(hSem)				OSSemPost(hSem)
//* �˳�������Դ
#define		OSAPIBlockExit(hBlock)			OSMutexPost(hBlock)
//*--------------------------------------- ����ԭ������ -------------------------------------------
extern INT8U OSAPISemWait(HANDLER hSem, INT16U uwWaitMS);
extern void OSAPISemFree(HANDLER hSem);
extern void OSAPISemFreeExt(HANDLER hSem);
extern HANDLER OSAPIBlockNew(INT8U ubPIP);
extern INT8U OSAPIBlockEnter(HANDLER hBlock, INT16U uwWaitMS);
extern INT8U OSAPIQPost(HANDLER hQueue, void *pvMsg);
extern INT8U OSAPIQReceive(HANDLER hQueue, PP ppMsg, INT16U uwTimeout);

#endif

