#include <stdarg.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "def.h"
#include "2416addr.h"
#include "2416lib.h"
#include "option.h"
#include "LCD.h"
#include "mmu.h"
#include "Nand.h"
#include "..\inc\download.h"
#include "..\inc\systemconf.h"
#include "..\inc\systemmenu.h"
#include "..\inc\function.h"
#include "..\inc\jiema.h"
#include "..\inc\communication.h"
#include "..\inc\test.h"
#include "..\inc\Rtc.h"
#include "..\inc\encrypt.h"

#include "..\inc\app.h"
#include "..\inc\appBase.h"





extern INTERALMEMORY g_InteralMemory;

//extern GLOBALVAR g_GlobalVar;

//extern INT16U PreScrNum;


extern unsigned int InPulseCount[7];		//��¼6·�����������������

extern int OutPulse_PreSet[4];	// 3·���������  ����Ԥ��ֵ
extern unsigned int OutPulse_Counter[4];	// 3·���������  ��ǰ���������

int flag1;
///Timer0  �����޸�  7-2*************************************************////
int Timer0_count,ShangXian_count,Timer0_SJ,number;
U32 flag_begin[NUMBER],flag_TimeUp[NUMBER],flag_ShangXian_T[NUMBER];
unsigned long int Tx_DQ,Tx_count_DQ,Tx_ShangXian_count_DQ;
U32 Time[NUMBER],Tx_0[NUMBER],Tx_count_0[NUMBER],Tx_ShangXian_count_0[NUMBER];
////******************************************************************///////


////�Ӵ˿�ʼ����û�����//////////////////////////////////



///////////////////////////////////////////////////////////////
//////	��ʼ��     //////////////////////////////////////////
//////	ÿ���ϵ�App_Init ִֻ��һ��	 //////////////////
//////////////////////////////////////////////////////////////
void App_Init(void)
{
	int i;
	
	X_In_Init();
	Y_Out_Init();
	Pulse_In_Init();
	Pulse_Out_Init();
	
	Timer0_Init();///////TJ timer0����
	//Timer2_Init();
	//	DA0_10_Init();

	// ���������ʼ��
	rGPBDAT |= ((1<<1));
	rGPBDAT |= ((1<<2));
	rGPEDAT |= ((1<<7));
	InPulse1_Start();
	InPulse2_Start();
	for(i=0; i<7; i++)
	{
		InPulseCount[i] = 0;
	}

}


void test_app(void){
	static U8 y1_status=0;
	static U8 y2_status=0;
	
	if (y1_start_button == 1 && y1_status == 0){
		y1_status=1;
		PulseOut_1_Start((y1_fre*2),-1);
	}
	else if (y1_start_button ==0 && y1_status == 1 ){
		PulseOut_1_Stop();
		y1_status=0;
	}
	
	if (y2_start_button == 1 && y2_status == 0){
		y2_status=1;
		PulseOut_2_Start((y2_fre*2),-1);
	}
	else if (y2_start_button ==0 && y2_status == 1 ){
		PulseOut_2_Stop();
		y2_status=0;
	}
	
	if (x1_qingling_button == 1)
		x1_display = 0;
	if (x2_qingling_button == 1)
		x2_display = 0;
	
}


///////////////////////////////////////////////////////////////
//////	Ӧ��������     //////////////////////////////////////////
//////	ϵͳÿ��ѭ�������һ��App_Operation	 //////////////////
//////////////////////////////////////////////////////////////
void App_Operation(void)
{
	//static int i;

	//Test_Run();
	//Test_RTC_SetTime();  // ��ť����
	//Test_RTC_ReadTime(); 
	

	// DA
	/* if(0 == g_InteralMemory.Bit[211])	// DA ��ǰ״ֹ̬ͣ
	{
		if(1 == g_InteralMemory.Bit[210])	// Set DA
		{
			DA0_10_Start(g_InteralMemory.Word[30]);
			g_InteralMemory.Bit[211] = g_InteralMemory.Bit[210];
		}
	}
	if(1 == g_InteralMemory.Bit[211])	// DA ��ǰ״̬����
	{
		if(0 == g_InteralMemory.Bit[210])	// ReSet DA
		{
			DA0_10_Stop();
			g_InteralMemory.Bit[211] = g_InteralMemory.Bit[210];
		}
	} */

 
/*	
	for(i=2; i<16; i++)
	{
		Set_Y_Value(i, TRUE);
		Set_Y_Value(i, FALSE);
	}
*/	

/////��ʱ����ȡ��ǰֵ ���ж�**************************
//����ǰֵ
  /* Tx_DQ = rTCNTO0;
  Tx_count_DQ = Timer0_count;
  Tx_ShangXian_count_DQ = ShangXian_count;

//���1 ʱ�䵽ʱδ�����жϴ�������ֵ
  if( flag_ShangXian_T[number] == 0 )   
   {
     if(( abs(Tx_0[number] - Tx_DQ) + Timer0_SJ * (Tx_count_DQ - Tx_count_0[number])) >= Time[number])//��ʱʱ�䵽  
     {
       flag_begin[number] = 0;
       flag_TimeUp[number] = 1;
     }
     else
     {
      flag_TimeUp[number]=0;
     }
   }
   
//���2 ��ʱʱ�䵽ʱ�����жϴ�������ֵ
   else if(flag_ShangXian_T[number]==1)  
   {
     if(( abs(Tx_0[number] - Tx_DQ) + Timer0_SJ * (Timer0_count_SX * (( Tx_ShangXian_count_DQ - Tx_ShangXian_count_0[number] ) - 1) + (Timer0_count_SX - Tx_count_0[number]) + Tx_count_DQ )) >= Time[number])
     {
       flag_ShangXian_T[number] = 0;
       flag_begin[number] = 0;
       flag_TimeUp[number] = 1;
     }
     else
     {
      flag_TimeUp[number]=0;
     }
   }   */
//////********************************************////



//////////////////////////////////////////////////////////////
/////////////////////�Ӵ˿�ʼ����û�����/////////////////////
//////////////////////////////////////////////////////////////

/*
g_InteralMemory.Bit[]
g_InteralMemory.KeepBit[]
g_InteralMemory.Word[]
g_InteralMemory.KeepWord[]
*/	


	test_app();














}





