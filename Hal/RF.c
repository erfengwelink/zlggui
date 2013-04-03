/**
*****************************************************************************************
*@file 
*@brief
*@author
*@date
*@version
*****************************************************************************************
*/
#include "..\\User\\Common.h"
#include "..\\Hal\\CML.h"
#include "..\\Hal\\Hal.h"


typedef struct TxFreqParamType
{
	u32 *pTxParam1;
	u32 *pTxParam2;
	u16 *pTxMicroTune;
}TxFreqParamType;

typedef struct RxFreqParamType
{
	u32 *pRxParam1;
	u32 *pRxParam2;
	u32 *pRxParam3;
	u16 *pRxMicroTune; 
}RxFreqParamType;
typedef struct RfInfo{
RxTxType * pTRS;
TxFreqParamType* pTxFreqStruct;
RxFreqParamType* pRxFreqStruct;
BOOLEAN * IsInstall;
}RfInfo;


/**
*************************************************************************
*@brief	���¼������������Ƕ�״̬���õĲ�����Ϊ�˲�
	����״̬�����ｫ״̬�����ó��ˣ�static��Ȼ��ʹ�ú�����ͳһ�Ĳ�����
	ע��һ�㣬Get_S��ʱ�� ��Param����Ч�ģ�����Ҫ��һ������ֵ��
*@author ������  rundream@gmail.com
*@param
*@param
*@return
*************************************************************************
*/

//��Ƶ���Ʋ��ֵ�ȫ�ֱ�����״̬
static RxTxType TxRxStatus;//Ĭ�ϵķ���״̬��
//static u16 FreqMicroTune=0x8DEA;//
static BOOLEAN  IsRfInstall=0;//��־�Ƿ�����Ƶģ����ڣ�
//ֱ�ӿ���Ƶ�ʵĲ���
static u32 TxParam1=0x00023002;
static u32 TxParam2=0x0013EF83;;
static u16 TxMicroTune=0x8DEA;
static u32 RxParam1;
static u32 RxParam2;
static u32 RxParam3;
static u16 RxMicroTune;

TxFreqParamType TxFreqParam={&TxParam1,&TxParam2,&TxMicroTune};
RxFreqParamType	RxFreqParam={&RxParam1,&RxParam2,&RxParam3,&RxMicroTune};
RfInfo GlobalRFInfo={&TxRxStatus,&TxFreqParam,&RxFreqParam,&IsRfInstall};


RxTxType RfStateOperate(GetOrSet Oper,RxTxType Param)
{
	if(Oper==GET_S){
		return TxRxStatus;
	}else if(Oper==SET_S){
		TxRxStatus=Param;
		return Param;
	}
	ELOG("Param err\n");
	return 0;	
};
BOOLEAN IsRfInstallOperate(GetOrSet Oper,BOOLEAN Param)
{
	if(Oper==GET_S){
		return IsRfInstall;
	}else if(Oper==SET_S){
		IsRfInstall=Param;
		LWIP_DEBUGF(RF_DEBUG,("SET IsRfInstall TRUE\n"));
		return Param;
	}
	ELOG("Param err\n");
	return 0;	
};

u16 TxParamOperate(GetOrSet Oper ,u32* pParam1,u32* pParam2)
{
   if(Oper==GET_S){
		//return TxMicroTune;
		*pParam1=TxParam1;
		*pParam2=TxParam2;
		return 0;

	}else if(Oper==SET_S){
		TxParam1=*pParam1;
		TxParam2=*pParam2;
		return 0;
	}
	ELOG("Param err\n");
	return 0;
};
u16 TxFreqMOperate(GetOrSet Oper ,u16 Param)
{
   if(Oper==GET_S){
		return TxMicroTune;
	}else if(Oper==SET_S){
		TxMicroTune=Param;
		return Param;
	}
	ELOG("Param err\n");
	return 0;
};


/**
*************************************************************************************
*@brief
*@author   ������
*@param
*@param
*@return
**************************************************************************************
*/
void CML_RF_Config(DigAnalogType DorA,RxTxType TorR)
{
    EXT3V_ON;
    if(DorA==DigitalMod) {
	 	BWSW_D;
	}else if(DorA==AnalogMod){
	   	BWSW_A;
	}else{
		ELOG("err\n");
		return;
	}

	 if(TorR==TxMod){
        RXEN_OFF;
        TXEN_ON;
        TXVCOEN_ON;
		TLOG("Tx mode\n");
	 }else if(TorR==RxMod){	

        RXEN_ON;	 // ����ʹ�ܣ�������Ƶ�Ŵ󡢵����ʹ��
        TXEN_OFF;	 // ��Ƶ���俪�أ���������ˣ�����-˥���ϴ󣬼�С��ɢ����
        TXVCOEN_OFF;	   // ����VCO��
	 }else{
		ELOG("err\n");
		return;
	}
    DelayMS(1);
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
extern void CML_VCO_Config(u32 data);
extern void CBUS_Send16U(u16,u16);

void Ch_Freq_Config(RxTxType TorRm,u32 Freq)
{
	
//		u32 Param1=0x00023002;
//		u32 Param2=0x0013EF83;
		
		if(TxMod==TorRm)
		{
			TLOG("\tTxParam1=0x%08x;TxParam2=0x%08x;\n",TxParam1,TxParam2);
			CML_VCO_Config(TxParam1);
			CML_VCO_Config(TxParam2);			
			DelayMS(1);
			TLOG("\tTxMicroTune=0x%04x\n",TxMicroTune);
			CBUS_Send16U(AUXDAX_DATA_CTL,TxMicroTune);//Ƶ��΢��V1.6.4
			//CBUS_SendTwoByte(0xA8,0x8d,0xEA);//Ƶ��΢��//�������V1.6.4�Ļ����ϸĶ����İ汾
		}else if (RxMod==TorRm)
		{
			CML_VCO_Config(0x00023000);
			CML_VCO_Config(0x00137A1D);//44.54537
			CML_VCO_Config(0x00023002);
			//CML_VCO_Config(0x0007D4BF);//  401.1
			if(0)
				CML_VCO_Config(0x0013EAC3);
			else
				CML_VCO_Config(Freq);

//			printf("RX:%08x.\n",Freq);

			DelayMS(1);
			//CBUS_SendTwoByte(0xA8,0x8e,0x0f);//1.6v ΢�� pinlv
			CBUS_Send16U(AUXDAX_DATA_CTL,0x8e6f);//Ƶ��΢��V1.6.4
			//CBUS_SendTwoByte(0xA8,0x8d,0xF0);//Ƶ��΢��//�������V1.6.4�Ļ����ϸĶ����İ汾
		}

}
/************************************************************************
*/

