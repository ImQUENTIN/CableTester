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
File        : winMain.h
Purpose     : main window
Author      : qyx@knd
Date        : Feb. 27th, 2019.
---------------------------END-OF-HEADER------------------------------
*/

#include "CABLE_Sheet.h"
#include "string.h"

//
//	Set String
//
static int _SetString(char *dst, char *src, int maxLen){
	int byte2copy = strlen(src), rtn = CRTN_NO_ERR;

	// err type
	if (byte2copy > maxLen){
		byte2copy = maxLen;
		rtn = CRTN_IS_TOO_LARGE;
	}
	else if (!byte2copy)
		rtn = CRTN_IS_EMPTY;
	
	// copy
	memcpy(dst, src, byte2copy);

	// handle the last chinese word garbled
	if (byte2copy < maxLen + 3){
		char tmp[3] = "☻\0";
		memcpy(dst + byte2copy, src, 3);
	}
	return rtn;
}

// 
// set cable's name
//
int CableSetName(cableInfo_s *cable, char *newName)
{
	return _SetString(cable->name, newName, STRLEN_CABLE_NAME);
}

//
// set cable's NO
//
int CableSetNo(cableInfo_s *cable, char *newNo)
{
	return _SetString(cable->no, newNo, STRLEN_CABLE_NO);
}

//
// set cable's Usage
//
int CableSetUsage(cableInfo_s *cable, char *newUsage)
{
	return _SetString(cable->usage, newUsage, STRLEN_CABLE_USAGE);
}

//
// set cable's Version
//
int CableSetVersion(cableInfo_s *cable, char *newVer)
{
	return _SetString(cable->ver, newVer, STRLEN_CABLE_VER);
}

//
// set cable's Material
//
int CableSetMaterial(cableInfo_s *cable, char *newMat)
{
	return _SetString(cable->mat, newMat, STRLEN_CABLE_MAT);
}

//
// set cable's Length
//
int CableSetLength(cableInfo_s *cable, char *newLen)
{
	return _SetString(cable->len, newLen, STRLEN_CABLE_LEN);
}

//
// set cable's Notes
//
int CableSetNotes(cableInfo_s *cable, char *newNotes)
{
	return _SetString(cable->mat, newNotes, STRLEN_CABLE_NOTES);
}

//
// set cable's Port A name
//
int CableSetPortAName(cableInfo_s *cable, char *newName)
{
	return _SetString(cable->portA.name, newName, STRLEN_PORT_NAME);
}

//
// set cable's Port A Type
//
int CableSetPortAType(cableInfo_s *cable, char *newType)
{
	return _SetString(cable->portA.type, newType, STRLEN_PORT_TYPE);
}

//
// set cable's Port A Notes
//
int CableSetPortANotes(cableInfo_s *cable, char *newNotes)
{
	return _SetString(cable->portA.Notes, newNotes, STRLEN_PORT_NOTES);
}

//
// set cable's Port B name
//
int CableSetPortBName(cableInfo_s *cable, char *newName)
{
	return _SetString(cable->portB.name, newName, STRLEN_PORT_NAME);
}

//
// set cable's Port B Type
//
int CableSetPortBType(cableInfo_s *cable, char *newType)
{
	return _SetString(cable->portB.type, newType, STRLEN_PORT_TYPE);
}

//
// set cable's Port B Notes
//
int CableSetPortBNotes(cableInfo_s *cable, char *newNotes)
{
	return _SetString(cable->portB.Notes, newNotes, STRLEN_PORT_NOTES);
}

//
// set pin's NO of Port A  
//
int CableSetPinANo(cableInfo_s *cable, char row, char newNo)
{
	cable->portA.pin[row].no = newNo;
	return CRTN_NO_ERR;
}

//
// set pin's Name of Port A  
//
int CableSetPinAName(cableInfo_s *cable, char row, char *newName)
{
	return _SetString(cable->portA.pin[row].name, newName, STRLEN_PIN_NAME);
}

//
// set pin's Color of Port A  
//
int CableSetPinAColor(cableInfo_s *cable, char row, char *newColor)
{
	return _SetString(cable->portA.pin[row].color, newColor, STRLEN_PIN_COLOR);
}

//
// set pin's NO of Port B  
//
int CableSetPinBNo(cableInfo_s *cable, char row, char newNo)
{
	cable->portB.pin[row].no = newNo;
	return CRTN_NO_ERR;
}

//
// set pin's Name of Port B  
//
int CableSetPinBName(cableInfo_s *cable, char row, char *newName)
{
	return _SetString(cable->portB.pin[row].name, newName, STRLEN_PIN_NAME);
}

//
// set pin's Color of Port B  
//
int CableSetPinBColor(cableInfo_s *cable, char row, char *newColor)
{
	return _SetString(cable->portB.pin[row].color, newColor, STRLEN_PIN_COLOR);
}

