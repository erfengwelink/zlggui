
/**
**********************************************************************
*@file 
*@brief
*@author   ������ rundream1314@gmail.com
*@date
*@version
***********************************************************************
*/

/**
***********************************************************************
*@brief
*@author   ������ rundream1314@gmail.com
*@param
*@param
*@return
************************************************************************
*/

#include "..\\User\\Common.h"
#include "..\\Hal\\Hal.h"

//Audio_Amp_OFF;
/**
*************************************************************************************
*@brief
*@author ������  rundream@gmail.com
*@param
*@param
*@return
**************************************************************************************
*/
void AudioAmpCrl(Switch Param)
{
	if(Param==OFF){
		Audio_Amp_OFF;
	}else if(Param==ON){
		Audio_Amp_ON;
	}
	
};












/**************************************************************************************
*/