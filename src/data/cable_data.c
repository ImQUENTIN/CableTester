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
File        : CABLE_data.c
Purpose     : storage the data of cable
Author      : qyx@knd
Date        : Mar. 5th, 2019.
---------------------------END-OF-HEADER------------------------------
*/

#include "CABLE_Sheet.h"

cableInfo_s cableStored[100];


void CableDataTest(void){
	cableInfo_s *pCable;

	pCable = cableStored;
	//
	// base information
	//
	CableSetName(pCable, "位置编码器反馈线缆");
	CableSetNo(pCable, "75011-1081");
	CableSetUsage(pCable, "ZD100T经济型驱动器到KND系统侧");
	CableSetVersion(pCable, "V1202");
	CableSetLength(pCable, "2米");
	CableSetMaterial(pCable, "RVVP-6*0.2mm^2+2*0.5mm^2（双绞）");
	CableSetNotes(pCable, "这是第1个线缆示例");
	CableSetPortAName(pCable, "系统侧");
	CableSetPortAType(pCable, "DB-15针");
	CableSetPortANotes(pCable, "屏蔽焊接在插头金属体上");
	CableSetPortBName(pCable, "主轴驱动器侧CN2");
	CableSetPortBType(pCable, "高密度14芯插头");
	CableSetPortBNotes(pCable, "无");

	// 
	// pin allocation
	//
	pinInfo_s pinA[10] = {
		{ 3,  "*PCS", "橙" },
		{ 4,  " PCS", "白" },
		{ 5,  "*PBS", "黄" },
		{ 6,  " PBS", "绿" },
		{ 7,  "*PAS", "蓝" },
		{ 8,  " PAS", "棕" },
		{ 14, " 0V ", "黑" },
	};

	pinInfo_s pinB[10] = {
		{ 3, "*PCS", "橙" },

	};
}
