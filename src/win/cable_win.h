/************************************************************************************************
* @file    win\cable_win.h
* @date    22:33:20 2019/3/10
* @brief   window fo cable tester
* @author  qyx
* @email   qiyuexin@yeah.net
* @Version V2.0.0
************************************************************************************************/

#pragma once
#include "DIALOG.h"


#define MAX_PAGE		7 
#define LEN_CODE		20
#define LEN_TITLE		50
#define LEN_USAGE		50

typedef struct{
	int vScrollPos;

}pageData_t;



///////////////////////////////////////////////////////////////////
//						functions
//

/*-----------------------------------------------------------------
- @func    EnterWinOfCableTester
- @brief   $brief$
- @para    void
- @rtn     void
- @date    2019/3/10
-----------------------------------------------------------------*/
void EnterWinOfCableTester(void);


