

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_MENU					(GUI_ID_USER +  0)
#define ID_MENU_CABLE_NEW		(GUI_ID_USER +  1)
#define ID_MENU_CABLE_OPEN		(GUI_ID_USER +  2)
#define ID_MENU_CABLE_CLOSE		(GUI_ID_USER +  3)
#define ID_MENU_CABLE_EXIT		(GUI_ID_USER +  4)
#define ID_MENU_CABLE_RECENT	(GUI_ID_USER +  5)
#define ID_MENU_RECENT_0	    (GUI_ID_USER +  6)
#define ID_MENU_RECENT_1	    (GUI_ID_USER +  7)
#define ID_MENU_RECENT_2	    (GUI_ID_USER +  8)
#define ID_MENU_RECENT_3		(GUI_ID_USER +  9)
#define ID_MENU_EDIT_UNDO		(GUI_ID_USER + 10)
#define ID_MENU_EDIT_REDO		(GUI_ID_USER + 11)
#define ID_MENU_EDIT_COPY		(GUI_ID_USER + 12)
#define ID_MENU_EDIT_PASTE		(GUI_ID_USER + 13)
#define ID_MENU_EDIT_DELETE		(GUI_ID_USER + 14)
#define ID_MENU_HELP_ABOUT		(GUI_ID_USER + 15)

#define ID_FRAME_WINDOW			(GUI_ID_USER + 20)

GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    {
        FRAMEWIN_CreateIndirect, "自动化线缆测试仪 V2.0", ID_FRAME_WINDOW,
        WC_FWINDOW_X0, WC_FWINDOW_Y0, WC_FWINDOW_XSIZE, WC_FWINDOW_YSIZE, 0, 0
    },
};


static void _cbDialog(WM_MESSAGE *pMsg)
{
    WM_HWIN hItem;
    int     nCode;
    int     id;

    switch (pMsg->MsgId)
    {

        case WM_INIT_DIALOG:
			hItem = pMsg->hWin;
			//////////////////////////////////////////////////////////
			//  FWin's Title
			// button: close, max, min
			FRAMEWIN_AddCloseButton(hItem, FRAMEWIN_BUTTON_RIGHT, 1);
			FRAMEWIN_AddMaxButton(hItem, FRAMEWIN_BUTTON_RIGHT, 1);
			FRAMEWIN_AddMinButton(hItem, FRAMEWIN_BUTTON_RIGHT, 1);
			
            break;
        case WM_NOTIFY_PARENT:
            id = WM_GetId(pMsg->hWinSrc);
            nCode = pMsg->Data.v;
            switch (id)
            {
                default:
                    break;
            }
        default:
            break;
    }
}

WM_HWIN CreateMainWin(void)
{
    WM_HWIN hwin;

    hwin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hwin;
}


/*-----------------------------------------------------------------
- @func    EnterWinOfCableTester
- @brief   $brief$
- @para    void
- @rtn     void
- @date    2019/3/10
-----------------------------------------------------------------*/
void EnterWinOfCableTester(void)
{
#if 0
    GUI_Clear();
    WcPrintTiTle("电缆W760工艺卡（1/1）；");
    WcPrintCode("41205-2241");              // ASCII
    WcPrintCableName("位置编码器反馈电缆（德州德隆专用）；");
    WcPrintCableUsage("ZD210驱动器到天津宜科编码器EB58MK-C10-1024型；");
    WcPrintCableVersion("V1101");           // ASCII
    WcPrintCableAuthor("亓岳鑫；");
    WcPrintCableADate("2018-12-26");        // ASCII
    WcPrintCableModifier("欧阳九天\n");
    WcPrintCableMDate("2019-3-6");          // ASCII
    WcPrintCableAuditor("贾明\n");
    WcDrawDbConn(WC_LINE3_X0 + 30, WC_LINE3_Y0 + 50, 2);

    WcDrawTable(100, 100);
#endif

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

#if 0
void WcPrintTiTle(char *title)
{
    GUI_SetFont(&GUI_Fontlishu_33a4);
    GUI_DispStringHCenterAt(title, WC_TITLE_X0, WC_TITLE_Y0);
    GUI_SetPenSize(WC_LINE1_HEIGHT);
    GUI_DrawHLine(WC_LINE1_Y0, WC_LINE1_X0, SCREEN_XSIZE - WC_LINE1_X0);
    GUI_SetPenSize(WC_LINE2_HEIGHT);
    GUI_DrawHLine(WC_LINE2_Y0, WC_LINE2_X0, SCREEN_XSIZE - WC_LINE2_X0);
    GUI_SetPenSize(WC_LINE3_HEIGHT);
    GUI_DrawHLine(WC_LINE3_Y0, WC_LINE3_X0, SCREEN_XSIZE - WC_LINE3_X0);
}

void WcPrintCode(char *string)
{
    GUI_RECT rect = { WC_CODE_X0, WC_CODE_Y0, WC_CODE_X0 + WC_CODE_XSIZE, WC_CODE_Y0 + WC_CODE_YSIZE };
    GUI_SetFont(&GUI_Font24B_ASCII);
    GUI_SetPenSize(1);
    GUI_DrawRectEx(&rect);
    GUI_DispStringInRectEx(string, &rect, GUI_TA_HCENTER | GUI_TA_VCENTER, 10, GUI_ROTATE_0);
}

void WcPrintCableName(char *name)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("1. 电缆名称:  \t", WC_NAME_X0, WC_NAME_Y0);
    GUI_DispString(name);
}

void WcPrintCableUsage(char *usage)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("2. 使用范围:  \t", WC_USAGE_X0, WC_USAGE_Y0);
    GUI_DispString(usage);
}

void WcPrintCableVersion(char *version)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("3. 资料版本:  \t", WC_VERSION_X0, WC_VERSION_Y0);
    //GUI_SetFont(&GUI_Font20_1);
    GUI_DispString(version);
}

void WcPrintCableAuthor(char *string)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("制卡者：  \t", WC_AUTHOR_X0, WC_AUTHOR_Y0);
    GUI_DispString(string);
}

void WcPrintCableADate(char *string)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("日期:  \t", WC_ADATE_X0, WC_ADATE_Y0);
    //GUI_SetFont(&GUI_Font20_1);
    GUI_DispString(string);
}

void WcPrintCableModifier(char *string)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("修改者：  \t", WC_MODIFIER_X0, WC_MODIFIER_Y0);
    GUI_DispString(string);
}

void WcPrintCableMDate(char *string)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("日期:  \t", WC_MDATE_X0, WC_MDATE_Y0);
    //GUI_SetFont(&GUI_Font20_1);
    GUI_DispString(string);
}

void WcPrintCableAuditor(char *string)
{
    GUI_SetFont(&GUI_Fontsong_16);
    GUI_DispStringAtCEOL("审核:  \t", WC_AUDITOR_X0, WC_AUDITOR_Y0);
    GUI_DispString(string);
}

void WcDrawDbConn(int x, int y, int scale)
{
    GUI_SetPenSize(1);

    GUI_DrawRect(x - 2 * scale, y + 8 * scale, x, y + 24 * scale);
    GUI_DrawRect(x, y, x + 5 * scale, y + 32 * scale);
    GUI_DrawRect(x + 5 * scale, y + 6 * scale, x + 15 * scale, y + 26 * scale);
    //GUI_DrawRect(x + 15 * scale, y + 10* scale, x + 18* scale, y + 22 * scale);


}


void WcDrawTable(int x, int y)
{
    //CreateListviewdemo();
    //WM_SetCallback(WM_HBKWIN, )
}

#endif

