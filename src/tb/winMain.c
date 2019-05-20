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


// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "GUI.h"
#include "myfont.h"


/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_MAIN (GUI_ID_USER + 0x00)

#define ID_TEXT_CABLE (GUI_ID_USER + 0x01)
#define ID_TEXT_NAME (GUI_ID_USER + 0x02)
#define ID_TEXT_USAGE (GUI_ID_USER + 0x03)
#define ID_TEXT_VER (GUI_ID_USER + 0x04)
#define ID_TEXT_MAT (GUI_ID_USER + 0x05)
#define ID_TEXT_LEN (GUI_ID_USER + 0x06)
#define ID_TEXT_NOTES (GUI_ID_USER + 0x07)

#define ID_EDIT_CABLE (GUI_ID_USER + 0x08)
#define ID_EDIT_NAME (GUI_ID_USER + 0x09)
#define ID_EDIT_USAGE (GUI_ID_USER + 0x0A)
#define ID_EDIT_VER (GUI_ID_USER + 0x0B)
#define ID_EDIT_MAT (GUI_ID_USER + 0x0C)
#define ID_EDIT_LEN (GUI_ID_USER + 0x0d)
#define ID_MULTIEDIT_NOTES (GUI_ID_USER + 0x0e)

#define ID_EDIT_PA (GUI_ID_USER + 0x0f)
#define ID_EDIT_PB (GUI_ID_USER + 0x10)
#define ID_TEXT_PA (GUI_ID_USER + 0x11)
#define ID_TEXT_PB (GUI_ID_USER + 0x12)
#define ID_DROPDOWN_PA (GUI_ID_USER + 0x13)
#define ID_DROPDOWN_PB (GUI_ID_USER + 0x14)
#define ID_LISTVIEW_PA (GUI_ID_USER + 0x15)
#define ID_LISTVIEW_PB (GUI_ID_USER + 0x16)

#define ID_BUTTON_EDIT (GUI_ID_USER + 0x17)
#define ID_BUTTON_VIEW (GUI_ID_USER + 0x18)
#define ID_BUTTON_FIND (GUI_ID_USER + 0x19)
#define ID_BUTTON_RUN (GUI_ID_USER + 0x20)


#define ID_TEXT_PANOTES (GUI_ID_USER + 0x21)
#define ID_TEXT_PBNOTES (GUI_ID_USER + 0x22)

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
	{ WINDOW_CreateIndirect, "Window", ID_WINDOW_MAIN, 20, 40, 760, 420, 0, 0x0, 0 },
	//	{ WINDOW_CreateIndirect, "WindowMask", ID_WINDOW_MASK, 20, 40, 760, 420, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "线缆编号:", ID_TEXT_CABLE, 40, 15, 100, 40, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "1.名称:", ID_TEXT_NAME, 15, 60, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "2.用途：", ID_TEXT_USAGE, 15, 90, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "3.版本:", ID_TEXT_VER, 15, 120, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "4.线材:", ID_TEXT_MAT, 15, 150, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "5.长度:", ID_TEXT_LEN, 15, 180, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "6.说明:", ID_TEXT_NOTES, 15, 210, 80, 20, 0, 0x0, 0 },

	{ EDIT_CreateIndirect, "Edit_CABLE", ID_EDIT_CABLE, 150, 15, 190, 30, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_NAME", ID_EDIT_NAME, 90, 60, 250, 25, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_USAGE", ID_EDIT_USAGE, 90, 90, 250, 25, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_VER", ID_EDIT_VER, 90, 120, 250, 25, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_MAT", ID_EDIT_MAT, 90, 150, 250, 25, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_LEN", ID_EDIT_LEN, 90, 180, 250, 25, 0, 0x64, 0 },
	{ MULTIEDIT_CreateIndirect, "Multiedit", ID_MULTIEDIT_NOTES, 90, 210, 250, 60, 0, 0x0, 0 },

	{ EDIT_CreateIndirect, "PART_AName", ID_EDIT_PA, 360, 10, 180, 30, 0, 0x0, 0 },
	{ EDIT_CreateIndirect, "PART_BName", ID_EDIT_PB, 560, 10, 180, 30, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "PART_A Notes", ID_TEXT_PANOTES, 360, 390, 180, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "PART_B Notes", ID_TEXT_PBNOTES, 560, 390, 180, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "接口类型:", ID_TEXT_PA, 360, 45, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "接口类型:", ID_TEXT_PB, 560, 45, 80, 20, 0, 0x0, 0 },
	{ DROPDOWN_CreateIndirect, "Dropdown_PA", ID_DROPDOWN_PA, 460, 45, 80, 20, 0, 0x64, 0 },
	{ DROPDOWN_CreateIndirect, "Dropdown_PB", ID_DROPDOWN_PB, 660, 45, 80, 20, 0, 0x64, 0 },
	{ LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_PA, 360, 70, 180, 310, 0, 0x0, 0 },
	{ LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_PB, 560, 70, 180, 310, 0, 0x0, 0 },

	// button
	{ BUTTON_CreateIndirect, "Find", ID_BUTTON_FIND, 160, 290, 80, 30, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Edit", ID_BUTTON_EDIT, 160, 330, 80, 30, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "View", ID_BUTTON_VIEW, 160, 370, 80, 30, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "RUN", ID_BUTTON_RUN, 260, 290, 80, 120, 0, 0x0, 0 },
	// USER START (Optionally insert additional widgets)
	// USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
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
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_CABLE);
		TEXT_SetFont(hItem, &GUI_Fonthei_24a4);

		// Port A Notes
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PANOTES);
		TEXT_SetFont(hItem, &GUI_Fontsong_16);
		TEXT_SetText(hItem, "屏蔽焊接在插头金属体上\u4f60:");

		// Port B Notes
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_PBNOTES);
		TEXT_SetFont(hItem, &GUI_Fontsong_16);

		//
		//Initialization of 'Listview'
		//
		char *tt[] = { "5", "信号名称", "红☻" };
		hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_PA);
		LISTVIEW_SetHeaderHeight(hItem, 30);		// set Header's height
		LISTVIEW_AddColumn(hItem, 50, "脚号", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 80, "名称", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 50, "颜色", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddRow(hItem, tt);
		LISTVIEW_SetAutoScrollV(hItem, 1);

		// set color
		int tn = LISTVIEW_GetNumRows;
		GUI_DispDecAt(tn, 0, 0, 4);
		for (int i = 0; i < 5; i += 2){
			for (int j = 0; j < 3; j++)
				LISTVIEW_SetItemBkColor(hItem, j, i, LISTVIEW_CI_UNSEL, GUI_RED);
		}

		LISTVIEW_SetGridVis(hItem, 1);
		//
		// Initialization of 'Listview'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_LISTVIEW_PB);
		LISTVIEW_AddColumn(hItem, 30, "hello,world.", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 50, "Name", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddColumn(hItem, 50, "Color", GUI_TA_HCENTER | GUI_TA_VCENTER);
		LISTVIEW_AddRow(hItem, NULL);
		LISTVIEW_SetGridVis(hItem, 1);
		LISTVIEW_SetAutoScrollV(hItem, 1);
		LISTVIEW_SetFont(hItem, &GUI_Fontsong_16);

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
		//
		// Initialization of 'Edit_LEN'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_LEN);
		EDIT_SetText(hItem, "不明");
		//
		// Initialization of 'EDIT_PA'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_PA);
		EDIT_SetText(hItem, "系统侧XS");
		//EDIT_SetFont(hItem, &GUI_Fonthei_20a4);
		EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		//
		// Initialization of 'EDIT_PB'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_EDIT_PB);
		EDIT_SetText(hItem, "主驱动器侧CN2");
		//EDIT_SetFont(hItem, &GUI_Fonthei_20);
		EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
		//
		// Initialization of 'DROPDOWN PA'
		hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_PA);
		DROPDOWN_AddString(hItem, "DB-15");
		//
		// Initialization of 'DROPDOWN PB'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_DROPDOWN_PB);
		DROPDOWN_AddString(hItem, "H -14");
		//
		// Initialization of 'Multiedit'
		//
		hItem = WM_GetDialogItem(pMsg->hWin, ID_MULTIEDIT_NOTES);
		MULTIEDIT_SetText(hItem, "Multiedit");
		MULTIEDIT_SetFont(hItem, GUI_FONT_16_ASCII);
		// USER START (Optionally insert additional code for further widget initialization)
		// USER END
		break;
	case WM_NOTIFY_PARENT:
		Id = WM_GetId(pMsg->hWinSrc);
		NCode = pMsg->Data.v;
		switch (Id) {
		case ID_LISTVIEW_PA: // Notifications sent by 'Listview'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_LISTVIEW_PB: // Notifications sent by 'Listview'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_SEL_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_EDIT_NAME: // Notifications sent by 'Edit_NAME'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_EDIT_USAGE: // Notifications sent by 'Edit_USAGE'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_EDIT_VER: // Notifications sent by 'Edit_VER'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_EDIT_MAT: // Notifications sent by 'Edit_MAT'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_EDIT_CABLE: // Notifications sent by 'Edit_CABLE'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_EDIT_LEN: // Notifications sent by 'Edit_LEN'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_DROPDOWN_PA: // Notifications sent by 'PORT A CONNECTOR'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_DROPDOWN_PB: // Notifications sent by 'PORT B CONNECTOR'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_MULTIEDIT_NOTES: // Notifications sent by 'Multiedit'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_EDIT: // Notifications sent by 'Edit'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_VIEW: // Notifications sent by 'View'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_FIND: // Notifications sent by 'Find'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
		case ID_BUTTON_RUN: // Notifications sent by 'RUN'
			switch (NCode) {
			case WM_NOTIFICATION_CLICKED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
			case WM_NOTIFICATION_RELEASED:
				// USER START (Optionally insert code for reacting on notification message)
				// USER END
				break;
				// USER START (Optionally insert additional code for further notification handling)
				// USER END
			}
			break;
			// USER START (Optionally insert additional code for further Ids)
			// USER END
		}
		break;
		// USER START (Optionally insert additional message handling)
		// USER END
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateWindow
*/
WM_HWIN CreateWindow(void);
WM_HWIN CreateWindow(void) {
	WM_HWIN hWin;

	hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
