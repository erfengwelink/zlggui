/****************************************************************************************
* �ļ�����MENU.C
* ���ܣ��˵���ʾ������(����ʽ�˵�)��
* ���ߣ����ܱ�
* ���ڣ�2004.02.26
* ��ע��ʹ��GUI_SetBackColor()����������ʾ��ɫ������ɫ��
****************************************************************************************/
#include "config.h"


#if  GUI_MenuDown_EN==1
/****************************************************************************
* ���ƣ�GUI_MMenuDraw()
* ���ܣ���ʾ���˵������ϱ߿�
* ��ڲ�����men		���˵����
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
/*****************************************************************************
	������: if(current selected menu> client rectangle ����ʾ��menu�ĸ���)
	{
		draw menu form (menu selected- client rectangele �ĸ���)
		��֤��ǰѡ��Ĳ˵�������µ�һ����
	}else{
		�ӵ�һ���˵���ʼ��ʾ��
	}
	2013��3��31��22:07:24
*****************************************************************************/
uint8  GUI_MMenuDraw(MMENU *men){
// 	WINDOWS  *mwin;
// 	uint8  i;
// 	uint8  xx,yy,width,hight;
// 	uint8  menu_index;//����Ҫʵ�ֹ���Ч��������Ĳ˵�����������Ϊ��ʾ�Ĳ����ˡ�
// 								//����Ҫ���µ�����ʼ����������
// //	Rectangle ClientRec;

// 								/* �������� */
// 	if( (men->no)==0 ) return(0);

// 	mwin = men->win;		// ȡ�ô��ھ��
// 	/* �ж��Ƿ������ʾ���˵� */
// 	if( (mwin->hight)<50 ) return(0);
// 	if( (mwin->with)<50 ) return(0);
// 	xx = mwin->RecClient.x0;//mwin->x;
// 	yy=mwin->RecClient.y0;//mwin->y+TITILE_HIGHT;
// 	width=mwin->RecClient.with;
// 	hight=mwin->RecClient.hight;
// 	GUI_RectangleFill(xx+1,yy+1,xx+width-2, yy+hight-2,back_color);//����ͻ���	
// 	if(hight<MMENU_HIGHT) {return 0;}

// 	if(men->state<=hight/MMENU_HIGHT){	//ѡ��Ĳ˵���һ��Ļ������ʾ
// 		menu_index=0;

// 	}else{//Ҫ�����ˣ���֤���µ�ѡ�������һ����ʾ
// 		menu_index=men->state-hight/MMENU_HIGHT;
// 	}
// 	
// 	for(i=0; i<(hight/MMENU_HIGHT); i++)
// 		{  
// 			if( (yy+MMENU_HIGHT) > (yy + hight) ) return(0);

// 			GUI_HLine(mwin->x, yy+MMENU_HIGHT, mwin->x + mwin->with - 1, disp_color);

// 			GUI_PutNoStr(xx+2, yy+2, men->str[menu_index], 6);			// ��д���˵�����
// 			yy += MMENU_HIGHT;
// 			menu_index++;
// 		}

	return(1);
}
uint8  bkGUI_MMenuDraw(MMENU *men)//2013��4��1��9:56:34
 {  WINDOWS  *mwin;
//    uint8  i;
//    uint8  xx,yy;

//    /* �������� */
//    if( (men->no)==0 ) return(0);
//    
//    mwin = men->win;		// ȡ�ô��ھ��
//    /* �ж��Ƿ������ʾ���˵� */
//    if( (mwin->hight)<50 ) return(0);
//    if( (mwin->with)<50 ) return(0);
//    
// //    /* ���˵���������ʾ������ */
// //    GUI_HLine(mwin->x, mwin->y + 22, mwin->x + mwin->with - 1, disp_color);
//    
//    xx = mwin->x;
//    yy= mwin->y+12;
//    for(i=0; i<(men->no); i++)
//    {  
// //	  if( (xx+MMENU_WIDTH) > (mwin->x + mwin->with) ) return(0);
// 	   if( (yy+MMENU_HIGHT) > (mwin->y + mwin->hight) ) return(0);
//       
//       GUI_HLine(mwin->x, yy+MMENU_HIGHT, mwin->x + mwin->with - 1, disp_color);
// 	   
//  	  GUI_PutNoStr(xx+2, mwin->y+ 14+i*10, men->str[i], 6);			// ��д���˵�����
//        yy += MMENU_HIGHT;
// //       GUI_RLine(xx, mwin->y + 12, mwin->y + 22, disp_color);	// ��ʾ���˵��ֽ���      
//    }
//    
    return(1);
}


/****************************************************************************
* ���ƣ�GUI_MMenuSelect()
* ���ܣ���ǰ���˵������»��ߣ���ʾ��ǰ���˵���
* ��ڲ�����men		���˵����
*          no		��ѡ�����˵���
* ���ڲ�������
****************************************************************************/
void  GUI_MMenuSelect(MMENU *men, uint8 no)
{  WINDOWS  *mwin;
   uint8  xx,yy;

   /* �������� */
   if( (men->no)==0 ) return;
   if( no>(men->no) ) return;
  
   mwin = men->win;						// ȡ�ô��ھ��
   /* �ж��Ƿ������ʾ���˵� */
   if( (mwin->hight)<50 ) return;
   if( (mwin->with)<50 ) return;
   
   /* ��ʾ�»��� */
    xx = mwin->x ;//+ no*MMENU_WIDTH;
//   GUI_HLine(xx+1, mwin->y + 22-1, xx+MMENU_WIDTH- 1, disp_color);
	yy = mwin->y + (no)*MMENU_HIGHT+22-1;
	GUI_HLine(xx+1, yy, xx+MMENU_WIDTH- 1, disp_color);
}


/****************************************************************************
* ���ƣ�GUI_MMenuNSelect()
* ���ܣ�ȡ����ǰ���˵���ȥ���»��ߡ�
* ��ڲ�����men		���˵����
*          no		��ѡ�����˵���
* ���ڲ�������
****************************************************************************/
void  GUI_MMenuNSelect(MMENU *men, uint8 no)
{  WINDOWS  *mwin;
   uint8  xx,yy;

   /* �������� */
   if( (men->no)==0 ) return;
   if( no>(men->no) ) return;
  
   mwin = men->win;						// ȡ�ô��ھ��
   /* �ж��Ƿ������ʾ���˵� */
   if( (mwin->hight)<50 ) return;
   if( (mwin->with)<50 ) return;
   
   /* ��ʾ�»��� */
//    xx = mwin->x + no*MMENU_WIDTH;
//    GUI_HLine(xx+1, mwin->y + 22-1, xx+MMENU_WIDTH- 1, back_color);
	xx = mwin->x ;//+ no*MMENU_WIDTH;
//   GUI_HLine(xx+1, mwin->y + 22-1, xx+MMENU_WIDTH- 1, disp_color);
	yy = mwin->y + (no)*MMENU_HIGHT+22-1;
	GUI_HLine(xx+1, yy, xx+MMENU_WIDTH- 1, back_color);
}



/****************************************************************************
* ���ƣ�GUI_SMenuDraw()
* ���ܣ���ʾ�Ӳ˵������ϱ߿�
* ��ڲ�����men		�Ӳ˵����
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
uint8  bkGUI_SMenuDraw(SMENU *men)//��������޸ĵıȽϴ�
{  WINDOWS  *mwin;
   uint32   xx, yy;
   uint8    i;

   mwin = men->win;
   /* �ж��Ƿ������ʾ���˵� */
   if( (mwin->hight)<50 ) return(0);
   if( (mwin->with)<50 ) return(0);
    
   /* �����ӵ�������Ӳ˵�������������Ϊԭ�����ұ����������������ʾ */
   xx = mwin->x;
   xx += (men->mmenu_no)*MMENU_WIDTH;
   yy = mwin->y + 22;
   yy +=  (men->no) * 11 + 2;
   if( (xx+SMENU_WIDTH) <= (mwin->x + mwin->with - 1) ) 
   {  /* ��������Ϊԭ����ʾ�Ӳ˵� */
      if( (men->mmenu_no) == 0 )
      {  GUI_RLine(xx+SMENU_WIDTH, mwin->y + 22, yy, disp_color);
         GUI_HLine(xx, yy, xx+SMENU_WIDTH, disp_color);
      }
      else
      {  GUI_Rectangle(xx, mwin->y + 22, xx+SMENU_WIDTH, yy, disp_color);
      }
      GUI_HLine(xx+1, mwin->y + 22, xx+MMENU_WIDTH-1, back_color);
      
   }
   else
   {  /* ��������Ϊԭ�� */
      if( (xx+MMENU_WIDTH) == (mwin->x + mwin->with - 1) )
      {  GUI_RLine(xx-(SMENU_WIDTH-MMENU_WIDTH), mwin->y + 22, yy, disp_color);
         GUI_HLine(xx-(SMENU_WIDTH-MMENU_WIDTH), yy, xx+MMENU_WIDTH, disp_color);
         
      }
      else
      {  GUI_Rectangle(xx-(SMENU_WIDTH-MMENU_WIDTH), mwin->y + 22, xx+MMENU_WIDTH, yy, disp_color);
      }
      GUI_HLine(xx+1, mwin->y + 22, xx+MMENU_WIDTH-1, back_color);
      
      xx = xx-(SMENU_WIDTH-MMENU_WIDTH);
   }
   
   /* ��ʾ�˵����� */
   xx++;
   yy = mwin->y + 22 + 2;
   for(i=0; i<(men->no); i++)
   {  if( i == (men->state) )								// �ж���ѡ��Ĳ˵���
      {  /* ��ʾ����ɫ */
         GUI_RectangleFill(xx, yy, xx+SMENU_WIDTH-2, yy+10, disp_color);
         /* ��ʾ�˵��ַ� */
         GUI_ExchangeColor();
         GUI_PutNoStr(xx+1, yy+1, men->str[i], 8);			// ��д�Ӳ˵�����
         GUI_ExchangeColor();
      }
      else
      {  /* ��ʾ����ɫ */
         GUI_RectangleFill(xx, yy, xx+SMENU_WIDTH-2, yy+10, back_color);
         /* ��ʾ�˵��ַ� */
         GUI_PutNoStr(xx+1, yy+1, men->str[i], 8);			// ��д�Ӳ˵�����
      }   
      
      yy += 11;
   }
    
   return(1);
}
uint8  GUI_SMenuDraw(SMENU *men){
	WINDOWS  *mwin;
	uint32   xx, yy;
	uint8    i;

	mwin = men->win;
   /* �ж��Ƿ������ʾ���˵� */
	if( (mwin->hight)<50 ) return(0);
	if( (mwin->with)<50 ) return(0);
    //    /* ���˵���������ʾ������ */
//    GUI_HLine(mwin->x, mwin->y + 22, mwin->x + mwin->with - 1, disp_color);
   
   xx = mwin->x;
   yy= mwin->y+12;
   for(i=0; i<(men->no); i++)
   {  
//	  if( (xx+MMENU_WIDTH) > (mwin->x + mwin->with) ) return(0);
	   if( (yy+MMENU_HIGHT) > (mwin->y + mwin->hight) ) return(0);
      
      GUI_HLine(mwin->x, yy+MMENU_HIGHT, mwin->x + mwin->with - 1, disp_color);
	   
//  	  GUI_PutNoStr(xx+2, mwin->y+ 14+i*10, men->str[i], 8);			// ��д���˵�����
//        yy += MMENU_HIGHT;
	   if( i == (men->state) )								// �ж���ѡ��Ĳ˵���
      {  /* ��ʾ����ɫ */
         GUI_RectangleFill(xx, yy+1, xx+SMENU_WIDTH-2, yy+MMENU_HIGHT, disp_color);
         /* ��ʾ�˵��ַ� */
         GUI_ExchangeColor();
         GUI_PutNoStr(xx+2, yy+2, men->str[i], 8);			// ��д���˵�����
         GUI_ExchangeColor();
      }
      else
      {  /* ��ʾ����ɫ */
         GUI_RectangleFill(xx, yy, xx+SMENU_WIDTH-2, yy, disp_color);
         /* ��ʾ�˵��ַ� */
         GUI_PutNoStr(xx+2, yy+2, men->str[i], 8);			// ��д�Ӳ˵�����
      }  
	  
	  yy += MMENU_HIGHT;
 
   }

}


/****************************************************************************
* ���ƣ�GUI_SMenuSelect()
* ���ܣ�ѡ���µ��Ӳ˵���
* ��ڲ�����men		�Ӳ˵����
*          old_no	ԭ��ѡ����Ӳ˵���
*		   new_no	��Ҫѡ����Ӳ˵���
* ���ڲ�������
****************************************************************************/
void  GUI_SMenuSelect(SMENU *men, uint8 old_no, uint8 new_no)
{  WINDOWS  *mwin;
   uint8  xx, yy;

   /* �������� */ 
   if(old_no==new_no) return;
   xx = men->no;
   if( (old_no>xx) || (new_no>xx) ) return;
   
   /* �����µ�ѡ����Ӳ˵��� */
   men->state = new_no;
   
   /* ���в˵�������ʾ */
   mwin = men->win;	 
	xx = mwin->x;
	yy= mwin->y+12;
  // yy +=  (men->mmenu_no)*SMENU_HIGHT;
//    if( (xx+SMENU_WIDTH) > (mwin->x + mwin->with - 1) ) 
//    {  /* ��������Ϊԭ����ʾ�Ӳ˵�������xx��������� */
//       xx = xx-(SMENU_WIDTH-SMENU_WIDTH);
//    }
//    xx++;
 
   /* ȡ��ԭ�Ӳ˵�ѡ�� */  
   //yy = mwin->y + 22 + 2;
   yy += old_no*SMENU_HIGHT;
   GUI_RectangleFill(xx+1, yy+1, xx+SMENU_WIDTH-2, yy+SMENU_HIGHT-1, back_color);
   GUI_PutNoStr(xx+1, yy+1, men->str[old_no], 8);
   /* ѡ���µ��Ӳ˵� */
//   yy = mwin->y + 22 + 2;
   yy= mwin->y+12;
   yy += new_no*SMENU_HIGHT;
   GUI_RectangleFill(xx, yy, xx+SMENU_WIDTH-2, yy+SMENU_HIGHT-1, disp_color);
   GUI_ExchangeColor();
   GUI_PutNoStr(xx+1, yy+1, men->str[new_no], 8);
   GUI_ExchangeColor();
}



/****************************************************************************
* ���ƣ�GUI_SMenuHide()
* ���ܣ������Ӳ˵��
* ��ڲ�����men		�Ӳ˵����
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
uint8  GUI_SMenuHide(SMENU *men)
{  WINDOWS  *mwin;
   uint8    xx, yy;

   mwin = men->win;
   /* �ж��Ƿ������ʾ���˵� */
   if( (mwin->hight)<50 ) return(0);
   if( (mwin->with)<50 ) return(0);
	xx=mwin->x;
	yy=mwin->y+12;
	
	//GUI_RectangleFill(xx+1, yy+1, xx+SMENU_WIDTH-2, yy+SMENU_HIGHT-1, back_color);
	GUI_RectangleFill(xx+1, yy+1, mwin->x+mwin->with-2, mwin->y+mwin->hight-2-11, back_color);
	
//     
//    /* �����ӵ�������Ӳ˵�������������Ϊԭ�����ұ����������������ʾ */
//    xx = mwin->x;
//    xx +=  (men->mmenu_no)*MMENU_WIDTH;
//    yy = mwin->y + 22;
//    yy +=  (men->no) * 11 + 2;
//    if( (xx+SMENU_WIDTH) <= (mwin->x + mwin->with - 1) ) 
//    {  /* ��������Ϊԭ����ʾ�Ӳ˵� */
//       if( (men->mmenu_no) == 0 )
//       {  GUI_RectangleFill(xx+1, mwin->y + 22+1, xx+SMENU_WIDTH, yy, back_color);
//       }
//       else
//       {  GUI_RectangleFill(xx, mwin->y + 22+1, xx+SMENU_WIDTH, yy, back_color);
//       }
//       GUI_HLine(xx+1, mwin->y + 22, xx+MMENU_WIDTH-1, disp_color);
//    }
//    else
//    {  /* ��������Ϊԭ�� */
//       if( (xx+MMENU_WIDTH) == (mwin->x + mwin->with - 1) )
//       {  GUI_RectangleFill(xx-(SMENU_WIDTH-MMENU_WIDTH), mwin->y + 22+1, xx+MMENU_WIDTH-1, yy, back_color);
//       }
//       else
//       {  GUI_RectangleFill(xx-(SMENU_WIDTH-MMENU_WIDTH), mwin->y + 22+1, xx+MMENU_WIDTH, yy, back_color);
//       }
//       GUI_HLine(xx+1, mwin->y + 22, xx+MMENU_WIDTH-1, disp_color);
//    }
    
   return(1);
}
uint8  GUI_MenuDraw(MENU *men){
	WINDOWS  *mwin;
	uint32   xx, yy,width,hight;
	uint8    i;

	mwin = men->win;
   /* �ж��Ƿ������ʾ���˵� */
	if( (mwin->hight)<50 ) return(0);
	if( (mwin->with)<50 ) return(0);
    //    /* ���˵���������ʾ������ */
//    GUI_HLine(mwin->x, mwin->y + 22, mwin->x + mwin->with - 1, disp_color);
   
   xx = mwin->RecClient.x0;
   yy= mwin->RecClient.y0;
   width=mwin->RecClient.with;
   hight=mwin->RecClient.hight;
	
   
	GUI_RectangleFill(xx+1, yy+1, xx+width-2,yy+hight-2, back_color);
	for(i=0; i<men->disp_num; i++)
   {  
	   if( (yy+MENU_HIGHT) > (mwin->RecClient.y0+hight) ) return(0);
      
      GUI_HLine(mwin->x, yy+MENU_HIGHT, mwin->x + mwin->with - 1, disp_color);
	   if( i+men->start_disp == (men->state) )								// �ж���ѡ��Ĳ˵���
      {  /* ��ʾ����ɫ */
         GUI_RectangleFill(xx+1, yy+1, xx+MENU_WIDTH-2, yy+MENU_HIGHT-1, disp_color);
         /* ��ʾ�˵��ַ� */
         GUI_ExchangeColor();
         GUI_PutNoStr(xx+2, yy+2,men->item[i+men->start_disp].str, 12);			// ��д���˵�����
         GUI_ExchangeColor();
      }
      else
      {  /* ��ʾ����ɫ */
         GUI_RectangleFill(xx+1, yy+1, xx+MENU_WIDTH-2, yy+MENU_HIGHT-1, back_color);
         /* ��ʾ�˵��ַ� */
         GUI_PutNoStr(xx+2, yy+2, men->item[i+men->start_disp].str, 12);			// ��д�Ӳ˵�����
      }  
	  
	  yy += MENU_HIGHT;
 
   }

}

void  GUI_MenuSelect(MENU *men, uint8 old_no, uint8 new_no)
{

}

uint8  GUI_HideDraw(MENU *men){

}



#endif




#if  GUI_MenuIco_EN==1

/*--  ������һ��ͼ��C:\WINDOWS\Desktop\OK.bmp  --*/
/*--  ���x�߶�=49x14  --*/
/*--  ��Ȳ���8�ı������ֵ���Ϊ�����x�߶�=56x14  --*/
uint8  const  button_ok[] = 
{
0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x18,0x00,0x00,0x00,0x00,0x0C,0x00,0x20,0x00,
0x00,0x00,0x00,0x02,0x00,0x40,0x00,0x0E,0x76,0x00,0x01,0x00,0x80,0x00,0x11,0x24,
0x00,0x00,0x80,0x80,0x00,0x11,0x28,0x00,0x00,0x80,0x80,0x00,0x11,0x30,0x00,0x00,
0x80,0x80,0x00,0x11,0x28,0x00,0x00,0x80,0x80,0x00,0x11,0x28,0x00,0x00,0x80,0x80,
0x00,0x11,0x24,0x00,0x00,0x80,0x40,0x00,0x0E,0x76,0x00,0x01,0x00,0x20,0x00,0x00,
0x00,0x00,0x02,0x00,0x18,0x00,0x00,0x00,0x00,0x0C,0x00,0x07,0xFF,0xFF,0xFF,0xFF,
0xF0,0x00
};



/*--  ������һ��ͼ��C:\WINDOWS\Desktop\OK1.bmp  --*/
/*--  ���x�߶�=49x14  --*/
/*--  ��Ȳ���8�ı������ֵ���Ϊ�����x�߶�=56x14  --*/
uint8  const  button_ok1[] = 
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1F,0xFF,
0xFF,0xFF,0xFF,0xFC,0x00,0x3F,0xFF,0xF1,0x89,0xFF,0xFE,0x00,0x7F,0xFF,0xEE,0xDB,
0xFF,0xFF,0x00,0x7F,0xFF,0xEE,0xD7,0xFF,0xFF,0x00,0x7F,0xFF,0xEE,0xCF,0xFF,0xFF,
0x00,0x7F,0xFF,0xEE,0xD7,0xFF,0xFF,0x00,0x7F,0xFF,0xEE,0xD7,0xFF,0xFF,0x00,0x7F,
0xFF,0xEE,0xDB,0xFF,0xFF,0x00,0x3F,0xFF,0xF1,0x89,0xFF,0xFE,0x00,0x1F,0xFF,0xFF,
0xFF,0xFF,0xFC,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00
};



/*--  ������һ��ͼ��C:\WINDOWS\Desktop\Cancle.bmp  --*/
/*--  ���x�߶�=49x14  --*/
/*--  ��Ȳ���8�ı������ֵ���Ϊ�����x�߶�=56x14  --*/
uint8  const  button_cancle[] =
{
0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x18,0x00,0x00,0x00,0x00,0x0C,0x00,0x20,0x00,
0x00,0x00,0x00,0x02,0x00,0x40,0xF0,0x00,0x00,0x07,0x01,0x00,0x81,0x10,0x00,0x00,
0x01,0x00,0x80,0x81,0x00,0x00,0x00,0x01,0x00,0x80,0x81,0x01,0x9E,0x1C,0x61,0x00,
0x80,0x81,0x02,0x49,0x24,0x91,0x00,0x80,0x81,0x01,0xC9,0x20,0xF1,0x00,0x80,0x81,
0x12,0x49,0x20,0x81,0x00,0x80,0x40,0xE1,0xFD,0x9C,0x77,0xC1,0x00,0x20,0x00,0x00,
0x00,0x00,0x02,0x00,0x18,0x00,0x00,0x00,0x00,0x0C,0x00,0x07,0xFF,0xFF,0xFF,0xFF,
0xF0,0x00
};




/*--  ������һ��ͼ��C:\WINDOWS\Desktop\Cancle1.bmp  --*/
/*--  ���x�߶�=49x14  --*/
/*--  ��Ȳ���8�ı������ֵ���Ϊ�����x�߶�=56x14  --*/
uint8  const  button_cancle1[] =
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1F,0xFF,
0xFF,0xFF,0xFF,0xFC,0x00,0x3F,0x0F,0xFF,0xFF,0xF8,0xFE,0x00,0x7E,0xEF,0xFF,0xFF,
0xFE,0xFF,0x00,0x7E,0xFF,0xFF,0xFF,0xFE,0xFF,0x00,0x7E,0xFE,0x61,0xE3,0x9E,0xFF,
0x00,0x7E,0xFD,0xB6,0xDB,0x6E,0xFF,0x00,0x7E,0xFE,0x36,0xDF,0x0E,0xFF,0x00,0x7E,
0xED,0xB6,0xDF,0x7E,0xFF,0x00,0x3F,0x1E,0x02,0x63,0x88,0x3E,0x00,0x1F,0xFF,0xFF,
0xFF,0xFF,0xFC,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00
};




/****************************************************************************
* ���ƣ�GUI_Button49x14()
* ���ܣ���ʾ49*14��ť��
* ��ڲ����� x		ָ����ʾλ�ã�x����
*           y		ָ����ʾλ�ã�y����
*           dat		��ʾ�����ݵ�ַ
* ���ڲ�������
****************************************************************************/
void  GUI_Button49x14(uint32 x, uint32 y, uint8 *dat)
{  GUI_LoadPic(x, y, (uint8 *)dat, 49, 14);
}



/****************************************************************************
* ���ƣ�GUI_Button_OK()
* ���ܣ���ʾ49*14��ť"OK"��
* ��ڲ����� x		ָ����ʾλ�ã�x����
*           y		ָ����ʾλ�ã�y����
* ���ڲ�������
****************************************************************************/
void  GUI_Button_OK(uint32 x, uint32 y)
{  GUI_LoadPic(x, y, (uint8 *) button_ok, 49, 14);
}


/****************************************************************************
* ���ƣ�GUI_Button_OK1()
* ���ܣ���ʾ49*14��ť��ѡ��״̬��"OK"��
* ��ڲ����� x		ָ����ʾλ�ã�x����
*           y		ָ����ʾλ�ã�y����
* ���ڲ�������
****************************************************************************/
void  GUI_Button_OK1(uint32 x, uint32 y)
{  GUI_LoadPic(x, y, (uint8 *) button_ok1, 49, 14);
}


/****************************************************************************
* ���ƣ�GUI_Button_Cancle()
* ���ܣ���ʾ49*14��ť"Cancle"��
* ��ڲ����� x		ָ����ʾλ�ã�x����
*           y		ָ����ʾλ�ã�y����
* ���ڲ�������
****************************************************************************/
void  GUI_Button_Cancle(uint32 x, uint32 y)
{  GUI_LoadPic(x, y, (uint8 *) button_cancle, 49, 14);
}


/****************************************************************************
* ���ƣ�GUI_Button_Cancle1()
* ���ܣ���ʾ49*14��ť��ѡ��״̬��"Cancle"��
* ��ڲ����� x		ָ����ʾλ�ã�x����
*           y		ָ����ʾλ�ã�y����
* ���ڲ�������
****************************************************************************/
void  GUI_Button_Cancle1(uint32 x, uint32 y)
{  GUI_LoadPic(x, y, (uint8 *) button_cancle1, 49, 14);
}



/****************************************************************************
* ���ƣ�GUI_MenuIcoDraw()
* ���ܣ���ʾͼ��˵���
* ��ڲ�����ico		ͼ��˵����
* ���ڲ���������0��ʾ����ʧ�ܣ�����1��ʾ�����ɹ�
****************************************************************************/
uint8  GUI_MenuIcoDraw(MENUICO *ico)
{  
   /* �������� */
   if( ( (ico->x)<5 ) || ( (ico->x)>(GUI_LCM_XMAX-37 ) ) ) return(0);	// ��ʾ��ʼ��ַ�ж�
   if( ( (ico->icodat)==NULL ) || ( (ico->title)==NULL ) ) return(0);	// ��ʾ���������ж�
   
   GUI_LoadPic(ico->x, ico->y, (uint8 *) ico->icodat, 32, 32);			// ��ʾICOͼ
   GUI_HLine(ico->x-5, ico->y+32, ico->x+37, back_color);				// ��ʾһ����
   if( (ico->state)==0 )
   {  GUI_LoadPic(ico->x-5, ico->y+33, (uint8 *) ico->title, 42, 13);
   }
   else
   {  GUI_LoadPic1(ico->x-5, ico->y+33, (uint8 *) ico->title, 42, 13);
   }
   
   return(1);
}


///////****************************************************************////////
uint8 GUI_FullClient(){

}


///////****************************************************************////////
#endif

















