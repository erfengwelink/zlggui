/**
	@file TypeDef.h
	@brief SCDMA project 
	@author liuxizhen
	@date 2012��1��17��16:45:08
	@version V0.1
*/
/**
	@brief �������ŵ����Լ������һЩ��Ϣ���͡������в���������
	���������͵��������궨��Ҳ������

*/
#ifndef TYPE_DEF_H
	#define TYPE_DEF_H

#include "..//STM32Lib//stm32f10x.h"
#include "..//UCOSII//ucos_ii.h"

#define N_Message 32

#define NULL (void * ) 0
//������һ������ָ�� 2012��9��25��21:38:15 ������
typedef void (*TskFunPtr)(void * parg);

///////////////////////////
/**
	@brief 	����䴫����Ϣ�Ľṹ��
*/
typedef struct
{
	INT8U		MsgType;
	INT8U 		SubMsgType;//���������Ҫ�����������ڴ��ڴ����������У����ĸ�����
						   //�ģ��ر�����Ҫ�������ݿ��ʱ��union��ָ���ʱ�����������������
	union{
		INT8U *	Ptr;
		INT32U	Val;
		 }Data;
	
	INT8U		DataLen;	
	//INT8U_t		flag;
}TskComMsg;

typedef enum MessgeTypeId {	KeyType=1,
							UsartMainISR,
							TskStateType,
							UsartDebugIsrType,
							TskUsartType,
							StateRpType,
							EmergencyType}
							MessgeTypeId;//����MessageType�е�
typedef struct AT_Commnd
{
	INT8U * pCommand;
	INT8U  Len;
	INT8U (* Judge)(INT8U *pBuf,INT8U* pCmd,INT8U CmdSize);//�ж��ǲ��Ǹ�����
	INT8U (* ParaseFun)(INT8U *pBuf,INT8U* pCmd);//����Ǹ�������һ��Ҫ����
	INT8U * Comment;	
}AT_Commnd;

typedef enum   MagnitudeType{
							US=0,
							MS	
}MagnitudeType;


typedef enum DigAnalogType
{
	AnalogMod=1,
	DigitalMod
	
}DigAnalogType;

typedef enum RxTxType
{
	RxMod=1,
	TxMod
}RxTxType;

typedef enum IsfCsfType
{
	ISF=1,
	CSF
}IsfCsfType;

typedef enum GetOrSet
{
	GET_S=1,
	SET_S
}GetOrSet;

typedef enum  e_comm_mode
{
	 comm_mode_voice = 0x0,				//000,            Voice Communication
	 comm_mode_voice_sld = 0x1,			//001,            Voice+SLD
	 comm_mode_t1_data = 0x2,			//010,            T1 Data Communication
	 comm_mode_t2_data = 0x3,			//011,            T2 Data Communicaiton
	 comm_mode_t3_data = 0x4,			//100,            T3 Data Communication
	 comm_mode_voice_append_data = 0x5	//101            //Voice+Appended Data(T2)
}e_comm_mode;

typedef struct 
{
     INT16U   caller_id[2];  //24 bits         
     INT16U   callee_id[2];  //24 bits
     e_comm_mode 	 comm_mode;  //3 bits
     INT8U   color_code[3]; //24 bits
}CallOutType;

//typedef call_out CallOutType;

//�����һ���ṹ��������һ�κ��У�
//asc���룬Ƶ�㣬ʱ�䣬����ʱ�䣨in s����tx rx���ͣ�����������ͣ�dpmr���룬
typedef struct {
	INT8U AsicId[8];//"1234567" 7�����룬���һ���ǡ�\0��,�������Ҷ���ģ�
	INT8U FreqPoint;
	INT8U HHMMSS[8];//asci�����Ҫ��'\0'
	INT8U YYMMDD[8];
	IsfCsfType IsfCsf;
	INT8U LiveTicks;

	/////////////////////////�������ϲ�Ӧ��ʹ�õ�����
	//�����ǵײ�ʹ�õ����ϲ�����²��ʱ�򣬸�����������ݣ�
	//������²���Ҫ�����ݣ�
	//�²�����ϲ��ʱ��Ҳ�������ģ�

	CallOutType Call;
	INT32U FreqParam1;
	INT32U FreqParam2;
	RxTxType TxRx;	
}CallInfoType;










typedef enum AudioSwithch{
	OFF,
	ON	
}Switch;


typedef struct FirmInfo
{
	const char Tag[64];
	const	u32 Len1;
	const	u16 * pData1;
	const	u32 Len2;
	const	u16 * pData2;
}FirmInfo;

/**
***********************************************************************
*@brief
 	������lwip����������ʱ����ʵ�ַ�ʽ			
*@author   ������ rundream1314@gmail.com
*@param
*@param
*@return
************************************************************************
*/
	
typedef void (* sys_timeout_handler)(void *arg);//��ʱ���Ļص�������

enum TimerType
{
	UnUsed=0,
	Preiod,
	Once,
	Paulse
};

typedef struct sys_timeout {
	enum TimerType time_type;	   			//��ʱ���ͣ�һ���еģ��������ڵ�
  	struct sys_timeout *next;	//��һ��ʱ����	
	sys_timeout_handler handler;//�ص�����		
  	void *arg;			   		//�ص�����	
	u32 ticks_reload;			//���ڶ�ʱ������ֵ	
  	u32 ticks_counter;			//����ֵ	
}sys_timeout;
typedef sys_timeout SysTimeOut;

typedef enum LedType
{
	LED1=1,
	LED2,
	LED3
}LedType;
//��led�Ĳ������ͣ�
typedef enum LedOptType
{
	LedOff,
	LedOn,
	LedToggle,
	LedPolling
}LedOptType;

typedef struct FreqConfigType
{
	char FreqChannel;	//��ʾ��ť�ϵĵڼ���Ƶ��(Asc)
	char FreqAsc[10];	//Asc��ʽ��Ƶ��403000000\0
	///������дƵ���Ӧ�÷��͵ģ������ǽ��յ�дƵ��������ݺ�Ӧ������
	int 	FreqInt;		//FreqAscת�����Ƶ��
	int  	TxParam;		//������Ҫд��Ĵ�����ֵ
	int 	RXParam;	//����
//	int 	RxParam2;
}FreqConfigType;




#endif

