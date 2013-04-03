/**
*************************************************************************
*@brief
*@author ������  rundream@gmail.com
*@param
*@param
*@return
*************************************************************************
*/

 #include "..//User//common.h"
 #include "..//Command//Command.h"
 #include "..//Hal//hal.h"
 #include "string.h"


/**
 ****************************************************************************************
 	@brief �ѷ�������Ϣ�е����ĵط���cr lf����0x00�������൱�����ַ�����

	@param
	@param
	@return    ָ����TskComMsg�е�data.ptr
****************************************************************************************
*/
char * Convert2Str(TskComMsg * ptr_msg)
{
	u8 *  pch1,* pch2;
	u16 len=ptr_msg->DataLen;
	u8 * ptr_data=ptr_msg->Data.Ptr;

	pch1=(ptr_data+len-1);
	pch2=(ptr_data+len);
	
	if((*(pch1)==CR)||(*(pch1)==LF)){
		*(pch1)=0x00;
		return ((char*)(ptr_data));	
	}else if((*(pch2)==CR)||(*(pch2)==LF)){
		*(pch2)=0x00;
		return ((char*)(ptr_data));	
	}else{		
		ELOG("convert_to_str erro\n:%s:%d",__FILE__,__LINE__);
		return (NULL);
	}
}

/**
****************************************************************************************
	@brief
	@param
	@param
	@return   
	@note ���ص���ch�����һ��ָ�룬������ch��
****************************************************************************************
*/

char * my_strchar(char * pstr,char ch)
{
	u8 len;
	if(pstr==NULL){
		ELOG("erro\n:%s:%d",__FILE__,__LINE__);
		return (NULL);	
	}
	len= strlen(pstr);

	while(len--){
		if(*(pstr++)==ch){
			return pstr;
		}
	} 
	ELOG("erro\n:%s:%d",__FILE__,__LINE__);
	return NULL;		
}


/**
****************************************************************************************
	@brief
	@param
	@param
	@return 
	INT16U Myatoi16u(INT8U * pstr,INT8U Len)
{
	INT8U i;
	INT16U num=0;
	if(pstr==NULL)
	{
		ELOG("Myatoi16u:err\n");
		return(0xff);	
	}
	if(Len<5)
	{
		for(i=0;i<Len;i++)
		{
		if (*pstr >= '0' && *pstr <= '9')
	        {
	            num = 10 * num + (*pstr++ - '0');
	        }
		}
		return(num);
	}
	return(0xff);
		

}
****************************************************************************************
*/

u32 atoi_hex(char * pstr)
{
	u32 num=0;
	u8 i;
	u8 len=strlen(pstr);
	if(len>4)
	{
		TLOG("error atoi_hex  %s:%d\n",__FILE__,__LINE__);
		return(0xffffffff);		
	}

	for(i=0;i<len;i++)
		{
			if (*pstr >= '0' && *pstr <= '9') {
	            num = 0x10 * num + (*pstr++ - '0');
	        }else if (*pstr >= 'a' && *pstr <= 'f')	{
			  	num = 0x10 * num + (*pstr++ - 'a')+10;
			}else if (*pstr >= 'A' && *pstr <= 'F')	{
			  	num = 0x10 * num + (*pstr++ - 'A')+10;
			}else{
			 	TLOG("error atoi_hex  %s:%d\n",__FILE__,__LINE__);
				return(0xffffffff);	
			}
		}
		return(num);

}
/**
****************************************************************************************
	@brief	   ����һ���ַ�����Ȼ���ҵ���һ��ch�󣬽���һ��copy��*dst�У�
				�����dst�������һ����\0����ʾ�ַ�������
	@param
	@param
	@return 
****************************************************************************************
*/

char * FindSession(char * psrc,char *dst,char ch)
{
	char * pch;
	if((psrc!=NULL)&&(dst!=NULL))
	{
		pch=strchr(psrc,ch);
		if(pch!=NULL){
		 	memcpy(dst,psrc,abs(pch-psrc));
			dst[abs(pch-psrc)]='\0';		
		}else{
			TLOG("error  %s:%d\n",__FILE__,__LINE__); 			
		}
		return pch;//	 ���ص��ǡ�ch��ָ��
		
	}else {
		TLOG("error  %s:%d\n",__FILE__,__LINE__);
			return NULL;	
	}
}


/**
*************************************************************************
*@brief
*@author ������  rundream@gmail.com
*@param
*@param
*@return
*************************************************************************
*/
extern void SimKeyPost(INT8U KeyVal);
 INT8U  SimKeyCommand(INT8U *pBuf,INT8U* pCmd)
 {
		char Temp[32];
		char * pStr;
		INT8U KeyVal;
		pStr=Convert2Str((TskComMsg * )pBuf);
		ASSERT(pStr!=NULL);
		pStr=FindSession(pStr, Temp,':')+1;
		ASSERT(pStr!=NULL);
			{
				LWIP_DEBUGF(GUI_DEBUG,("Key:%s\n",Temp));
			}
		pStr=FindSession(pStr, Temp,';')+1;
		ASSERT(pStr!=NULL);
		{
			KeyVal=atoi_hex(Temp);
			LWIP_DEBUGF(GUI_DEBUG,("Keyval:0x%x\n",KeyVal));
			SimKeyPost(KeyVal);
		}
	return 0;
 }
 

/*************************************************************************
*/