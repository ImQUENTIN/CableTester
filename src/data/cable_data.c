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
	CableSetName(pCable, "λ�ñ�������������");
	CableSetNo(pCable, "75011-1081");
	CableSetUsage(pCable, "ZD100T��������������KNDϵͳ��");
	CableSetVersion(pCable, "V1202");
	CableSetLength(pCable, "2��");
	CableSetMaterial(pCable, "RVVP-6*0.2mm^2+2*0.5mm^2��˫�ʣ�");
	CableSetNotes(pCable, "���ǵ�1������ʾ��");
	CableSetPortAName(pCable, "ϵͳ��");
	CableSetPortAType(pCable, "DB-15��");
	CableSetPortANotes(pCable, "���κ����ڲ�ͷ��������");
	CableSetPortBName(pCable, "������������CN2");
	CableSetPortBType(pCable, "���ܶ�14о��ͷ");
	CableSetPortBNotes(pCable, "��");

	// 
	// pin allocation
	//
	pinInfo_s pinA[10] = {
		{ 3,  "*PCS", "��" },
		{ 4,  " PCS", "��" },
		{ 5,  "*PBS", "��" },
		{ 6,  " PBS", "��" },
		{ 7,  "*PAS", "��" },
		{ 8,  " PAS", "��" },
		{ 14, " 0V ", "��" },
	};

	pinInfo_s pinB[10] = {
		{ 3, "*PCS", "��" },

	};
}
