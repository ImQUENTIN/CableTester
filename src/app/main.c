/************************************************************************************************
* @file    app\main.c
* @date    22:30:27 2019/3/10
* @brief   main task
* @author  qyx
* @email   qiyuexin@yeah.net
* @Version V2.0.0
************************************************************************************************/

#include "GUI.h"
#include "win\cable_win.h"

void MainTask(void)
{
	GUI_Init();

	EnterWinOfCableTester();

	for(;;);
	
}
