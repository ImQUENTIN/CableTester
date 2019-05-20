/************************************************************************************************
* @file    win\cable_info.c
* @date    8:01:39 2019/3/11
* @brief   draw cable's information
* @author  qyx
* @email   qiyuexin@yeah.net
* @Version V2.0.0
************************************************************************************************/

#include "font\myfont.h"
#include "win\cable_info.h"

static void _cbDialog(WM_MESSAGE * pMsg){
	WM_HWIN hItem;
	int     NCode;
	int     Id;
	// USER START (Optionally insert additional variables)
	// USER END

	switch (pMsg->MsgId) {
	case WM_INIT_DIALOG:
		//
		// Initialization of 'Window'
		//
		hItem = pMsg->hWin;
		WINDOW_SetBkColor(hItem, GUI_MAKE_COLOR(0x00BE8D3A));

		//
		// Text 
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_CODE);
		TEXT_SetFont(hItem, &GUI_Fonthei_24a4);

		// Port A Notes
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PANOTES);
		TEXT_SetFont(hItem, &GUI_Fontsong_16);
		TEXT_SetText(hItem, "屏蔽焊接在插头金属体上\u4f60:");

		// Port B Notes
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PBNOTES);
		TEXT_SetFont(hItem, &GUI_Fontsong_16);
		//
		// Initialization of 'Edit_NAME'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_NAME);
		EDIT_SetText(hItem, "位置编码器反馈线缆\n");
		//
		// Initialization of 'Edit_USAGE'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_USAGE);
		EDIT_SetText(hItem, "ZD100T经济型驱动器到KND系统侧\n");
		//
		// Initialization of 'Edit_VER'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_VER);
		EDIT_SetText(hItem, "V1202");
		//
		// Initialization of 'Edit_MAT'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_MAT);
		EDIT_SetText(hItem, "RVVP-6*0.2MM^2+2*0.5MM^2");
		//
		// Initialization of 'Edit_CABLE'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_CABLE);
		EDIT_SetText(hItem, "75011-1081");
		//EDIT_SetFont(hItem, &GUI_Fonthei_24a4);
		EDIT_SetFont(hItem, GUI_FONT_24_ASCII);

void wc_CableInfoTest(void)
{
	GUI_Clear();
}



#if 0
void wc_PrintTiTle(char *title)
{
    GUI_SetFont(&GUI_Fontlishu_33a4);
    GUI_DispStringHCenterAt(title, WC_TITLE_X0, WC_TITLE_Y0);
    GUI_SetPenSize(WC_LINE1_HEIGHT);
    GUI_DrawHLine(WC_LINE1_Y0, WC_LINE1_X0, WC_PAGE_XSIZE - WC_LINE1_X0);
    GUI_SetPenSize(WC_LINE2_HEIGHT);
    GUI_DrawHLine(WC_LINE2_Y0, WC_LINE2_X0, WC_PAGE_XSIZE - WC_LINE2_X0);
    GUI_SetPenSize(WC_LINE3_HEIGHT);
    GUI_DrawHLine(WC_LINE3_Y0, WC_LINE3_X0, WC_PAGE_XSIZE - WC_LINE3_X0);
}

void wc_PrintCode(char *code)
{
    GUI_RECT rect = { WC_CODE_X0, WC_CODE_Y0, WC_CODE_X0 + WC_CODE_XSIZE, WC_CODE_Y0 + WC_CODE_YSIZE };
    GUI_SetFont(&GUI_Font24B_ASCII);
    GUI_SetPenSize(1);
    GUI_DrawRectEx(&rect);
    GUI_DispStringInRectEx(code, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER, 10, GUI_ROTATE_0);
}

/*-----------------------------------------------------------------
- @func    wc_PrintString
- @brief   print a string at certain position with certain font.
- @para    newFont 		: font to use;
-          itemName		: item's name to display
-          itemContent	: item's content to display
-          x0			: x pos to start
-          y0			: y pos to start 
- @rtn     void
- @date    2019/3/11
-----------------------------------------------------------------*/
void wc_PrintString(GUI_FONT *newFont, int x0, int y0, char *itemName, char *itemContent)
{
    GUI_SetFont(newFont);
    GUI_DispStringAtCEOL(itemName, x0, y0);
    GUI_DispString(itemContent);
}



    wc_PrintTiTle("电缆W760工艺卡（1/1）；");
    wc_PrintCode("32203.01-1022");              // ASCII
    
	wc_PrintString(&GUI_Fontsong_16, WC_NAME_X0, WC_NAME_Y0, "1. 电缆名称:  \t", "位置编码器反馈电缆（德州德隆专用）；");
	wc_PrintString(&GUI_Fontsong_16, WC_USAGE_X0, WC_USAGE_Y0, "2. 使用范围:  \t", "ZD210驱动器到天津宜科编码器EB58MK-C10-1024型；");
	wc_PrintString(&GUI_Font16_ASCII, WC_VERSION_X0, WC_VERSION_Y0, "3. 资料版本:  \t", "V1101");
	wc_PrintString(&GUI_Fontsong_16, WC_AUTHOR_X0, WC_AUTHOR_Y0, "制卡者:  \t", "亓岳鑫");
	wc_PrintString(&GUI_Font16_ASCII, WC_ADATE_X0, WC_ADATE_Y0, "日期:  \t", "2018-12-26");
	wc_PrintString(&GUI_Fontsong_16, WC_USAGE_X0, WC_USAGE_Y0, "日期:  \t", "型；");
"3. 资料版本:  \t",
"制卡者：  \t", WC_AUTHOR_X0, WC_AUTHOR_Y0
"日期:  \t", WC_ADATE_X0, WC_ADATE_Y0);
"修改者：  \t", WC_MODIFIER_X0, WC_MODIFIER_Y0);
"日期:  \t", WC_MDATE_X0, WC_MDATE_Y0);
"审核:  \t", WC_AUDITOR_X0, WC_AUDITOR_Y0);


    wc_PrintCableVersion("V1101");           // ASCII
    wc_PrintCableAuthor("亓岳鑫；");
    wc_PrintCableADate("2018-12-26");        // ASCII
    wc_PrintCableModifier("欧阳九天\n");
    wc_PrintCableMDate("2019-3-6");          // ASCII
    wc_PrintCableAuditor("贾明\n");
    wc_DrawDbConn(WC_LINE3_X0 + 30, WC_LINE3_Y0 + 50, 2);

    wc_DrawTable(100, 100);

    //
    // Set default font of widget
    //
	GUI_UC_SetEncodeUTF8();

    TEXT_SetDefaultFont(&GUI_Fontsong_16);
    EDIT_SetDefaultFont(&GUI_Fontsong_16);
    EDIT_SetDefaultTextAlign(GUI_TA_LEFT | GUI_TA_VCENTER);
    LISTVIEW_SetDefaultFont(&GUI_Fontsong_16);
    HEADER_SetDefaultFont(&GUI_Fontsong_16);        // the name of column can display chinese by this line.
	FRAMEWIN_SetDefaultFont(&GUI_Fontsong_16);

    WM_HWIN hwin = CreateMainWin();
    GUI_Delay(10);      // for display


}

void wc_DrawDbConn(int x, int y, int scale)
{
    GUI_SetPenSize(1);

    GUI_DrawRect(x - 2 * scale, y + 8 * scale, x, y + 24 * scale);
    GUI_DrawRect(x, y, x + 5 * scale, y + 32 * scale);
    GUI_DrawRect(x + 5 * scale, y + 6 * scale, x + 15 * scale, y + 26 * scale);
    //GUI_DrawRect(x + 15 * scale, y + 10* scale, x + 18* scale, y + 22 * scale);


}
#endif


