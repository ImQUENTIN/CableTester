/*********************************************************************
*                                                                    *
*               Solution for cable tester		                     * 
*                                                                    * 
**********************************************************************
*                                                                    *
*        (c) 2018 - 2019  BEIJING KND CNC TECHNIQUE CO.,LTD.         *
*                                                                    *
*        Internet: www.knd.com.cn    Support:  qiyuexin@knd.com.cn   *
*                                                                    *
**********************************************************************

----------------------------------------------------------------------
File        : SelfTest.c
Purpose     : Check all periphs supported by this system.
Author      : qyx@knd
Date        : Feb. 27th, 2019.
---------------------------END-OF-HEADER------------------------------
*/

#include "GUI.h"
#include "SelfTest.h"

/*  
*/
void ShowTestInfo(char *item, char *info)
{
	GUI_COLOR cl = GUI_GetColor();

	GUI_SetColor(GUI_WHITE);
	GUI_DispString(item);
	GUI_DispString("...\t");
	
	if (!strlen(info)){
		GUI_SetColor(GUI_YELLOW);
		GUI_DispString("unknown");
	} else if (info[0] < '0' || info[0] > '9'){
			
		switch (info[0]){
		case 'o': case 'O': case 'c': case 'C':
			// for 'checked', 'OK'
			GUI_SetColor(GUI_GREEN);
			break;

		case 'f': case 'F':
			GUI_SetColor(GUI_RED);
			break;

		default:
			GUI_SetColor(GUI_YELLOW);
			break;

		}
	}
		GUI_DispString(info);
		GUI_DispString("\n");

	GUI_SetColor(cl);
}


void SelfTest_tb(void){

	ShowTestInfo("CPU", "STM32F215, 180Mhz");
	ShowTestInfo("SRAM", "256KB");
	ShowTestInfo("NOR", "18MB");
	ShowTestInfo("NAND", "128MB");

	ShowTestInfo("GPIO", "OK");
	ShowTestInfo("SDCard", "Failed");
	ShowTestInfo("USB Keyboard", "unknown");
	ShowTestInfo("PC Comm", "disconnect");
	ShowTestInfo("Harness A", "checked");
	ShowTestInfo("Harness B", "checked");


	}