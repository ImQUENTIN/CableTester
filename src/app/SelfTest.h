/*********************************************************************
*                                                                    *
*               Solution for wire harness tester                     * 
*                                                                    * 
**********************************************************************
*                                                                    *
*        (c) 2018 - 2019  BEIJING KND CNC TECHNIQUE CO.,LTD.         *
*                                                                    *
*        Internet: www.knd.com.cn    Support:  qiyuexin@knd.com.cn   *
*                                                                    *
**********************************************************************

----------------------------------------------------------------------
File        : SelfTest.h
Purpose     : Check all periphs supported by this system.
Author      : qyx@knd
Date        : Feb. 27th, 2019.
---------------------------END-OF-HEADER------------------------------
*/

#pragma once

void ShowTestInfo(char *item, char *info);

void SelfTest_tb(void);
