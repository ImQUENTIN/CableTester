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
File        : CABLE_Sheet.h
Purpose     : contains the cable information displayed on the screen.
Author      : qyx@knd
Date        : Feb. 27th, 2019.
---------------------------END-OF-HEADER------------------------------
*/

#pragma once

#define CABLE_MAX_PIN		64		// define the maximum pin supported

// 
//	Definition of string length
//
#define STRLEN_CABLE_NO		10		// Number: 75011-1081
#define STRLEN_CABLE_NAME	30		// Name:
#define STRLEN_CABLE_USAGE	40		// Usage:
#define STRLEN_CABLE_VER	10		// Verison:
#define STRLEN_CABLE_MAT	30		// Material:
#define STRLEN_CABLE_LEN	30		// Length:
#define STRLEN_CABLE_NOTES	50		// Notes:

#define STRLEN_PORT_NAME	20		// Port's name:
#define STRLEN_PORT_TYPE	15		// Port's type:
#define STRLEN_PORT_NOTES	30		// Port's Notes:
//#define STRLEN_PIN_NO		3		// Pin's Number: use char type , not need.
#define STRLEN_PIN_NAME		15		// Pin's Name:
#define STRLEN_PIN_COLOR	6		// Pin's Color

//
//  pin's information
//
typedef struct{
	char no;
	char name[STRLEN_PIN_NAME];
	char color[STRLEN_PIN_COLOR];
}pinInfo_s;

//
//	port's information
//
typedef struct{
	char name[STRLEN_PORT_NAME];
	char type[STRLEN_PORT_TYPE];
	char Notes[STRLEN_PORT_NOTES];
	pinInfo_s pin[CABLE_MAX_PIN];
}portInfo_s;

//
//	cable's information
//
typedef struct{
	char no[STRLEN_CABLE_NO];
	char name[STRLEN_CABLE_NAME];
	char usage[STRLEN_CABLE_USAGE];
	char ver[STRLEN_CABLE_VER];
	char mat[STRLEN_CABLE_MAT];
	char len[STRLEN_CABLE_LEN];
	char notes[STRLEN_CABLE_NOTES];

	portInfo_s portA, portB;
}cableInfo_s;

////////////////////////////////////////////////////////////////////////////
//			functions
//

//  Cable string error type
#define CRTN_NO_ERR			0	
#define CRTN_IS_EMPTY		1
#define CRTN_IS_TOO_LARGE	2

//  base infomation of cable
int CableSetName(cableInfo_s *cable, char *newName);
int CableSetNo(cableInfo_s *cable, char *newNo);		// Number is string type
int CableSetUsage(cableInfo_s *cable, char *newUsage);
int CableSetVersion(cableInfo_s *cable, char *newVer);
int CableSetMaterial(cableInfo_s *cable, char *newMat);
int CableSetLength(cableInfo_s *cable, char *newLen);
int CableSetNotes(cableInfo_s *cable, char *newNotes);
int CableSetPortAName(cableInfo_s *cable, char *newName);
int CableSetPortAType(cableInfo_s *cable, char *newType);
int CableSetPortANotes(cableInfo_s *cable, char *newNotes);
int CableSetPortBName(cableInfo_s *cable, char *newName);
int CableSetPortBType(cableInfo_s *cable, char *newType);
int CableSetPortBNotes(cableInfo_s *cable, char *newNotes);

//  pin information
int CableSetPinANo(cableInfo_s *cable, char row, char newNo);
int CableSetPinAName(cableInfo_s *cable, char row, char *newName);
int CableSetPinAColor(cableInfo_s *cable, char row, char *newColor);
int CableSetPinBNo(cableInfo_s *cable, char row, char newNo);
int CableSetPinBName(cableInfo_s *cable, char row, char *newName);
int CableSetPinBColor(cableInfo_s *cable, char row, char *newColor);


