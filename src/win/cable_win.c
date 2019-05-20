/************************************************************************************************
* @file    win\cable_win.c
* @date    22:32:30 2019/3/10
* @brief   windows for cable tester
* @author  qyx
* @email   qiyuexin@yeah.net
* @Version V2.0.0
************************************************************************************************/

#include <string.h>
#include "GUI.h"
#include "Dialog.h"
#include "MENU.h"
#include "MESSAGEBOX.h"
#include "scrollbar.h"

#include "win\cable_win.h"
#include "win\draw.h"
#include "font\myfont.h"



/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#if 0

#define COLOR_TEXT			GUI_WHITE //( 250 << 16 |  250 << 8 | 250)
#define COLOR_TEXT0			( GUI_GRAY_7C ) 
#define COLOR_TEXT1			( 50 << 16 | 240 << 8 | 240)
#define COLOR_TEXT2			(180 << 16 | 200 << 8 | 240)

#define COLOR_BK0			( 80 << 16 |  80 << 8 | 80)
#define COLOR_BK1			( 40 << 16 |  40 << 8 | 40)
#define COLOR_BK2			( 20 << 16 |  20 << 8 | 20)
#define COLOR_BK3			( 66 << 16 |  66 << 8 | 66)

// framewin
#define COLOR_FRAMEBAR0		COLOR_BK0		 
#define COLOR_FRAMEBAR1		COLOR_BK1
#define COLOR_FRAMECBK		COLOR_BK0		// bk of client
#define COLOR_FRAMEOUT		(  0 << 16 |   0 << 8 |  0)
#define COLOR_FRAMEINNER	(105 << 16 | 105 << 8 | 105)
#define COLOR_FRAMEAREA		( 26 << 16 |  26 << 8 | 26)
#define COLOR_FRAMETEXT		COLOR_TEXT1 

// menu
#define COLOR_MENUTOP	 	COLOR_BK0		 // bk horizontal, top
#define COLOR_MENUBTM	 	COLOR_BK1		 // bk horizontal, btm
#define COLOR_MENUVRT		COLOR_BK1		 // bk vertical
#define COLOR_MENUSELH0	 	COLOR_BK0		 // bk selection horizontal, top
#define COLOR_MENUSELH1	 	COLOR_BK1		 // bk selection horizontal, btm
#define COLOR_MENUSELV0	 	COLOR_BK0		 // bk selection vertical, left
#define COLOR_MENUSELV1	 	COLOR_BK1		 // bk selection vertical, right

#define COLOR_MENUTEXT		COLOR_TEXT		// text color of menu	
#define COLOR_MENUTEXT0		COLOR_TEXT0		// text color of menu when disabled

// Multipage
#define COLOR_MPAGEBK		COLOR_BG		// bk color
#define COLOR_MPAGEFRAME	COLOR_BK0		// frame color
#define COLOR_MPAGETEXT		COLOR_TEXT		// text color
#define COLOR_MPAGETG0		COLOR_BK0		// top gradient
#define COLOR_MPAGETG1		COLOR_BK1		// top gradient
#define COLOR_MPAGEBG0		COLOR_BK2		// btm gradient
#define COLOR_MPAGEBG1		COLOR_BK2		// btm gradient

// page
#define COLOR_PAGEDEMO_BK	COLOR_BG		// bk color of page

// edit
#define COLOR_EDITBK		COLOR_BG
#define COLOR_EDITBK1		COLOR_BK3

#endif


enum{
	IDNONE = 0,

	// Menu
	ID_MENU = GUI_ID_USER + 0,
	ID_MENU_CABLE_NEW,
	ID_MENU_CABLE_OPEN,
	ID_MENU_CABLE_SAVEAS,
	ID_MENU_CABLE_CLOSE,
	ID_MENU_CABLE_EXIT,
	ID_MENU_CABLE_RECENT,
	ID_MENU_RECENT_0,
	ID_MENU_RECENT_1,
	ID_MENU_RECENT_2,
	ID_MENU_RECENT_3,
	ID_MENU_RECENT_4,
	ID_MENU_RECENT_5,
	ID_MENU_RECENT_6,
	ID_MENU_EDIT_UNDO,
	ID_MENU_EDIT_REDO,
	ID_MENU_EDIT_COPY,
	ID_MENU_EDIT_PASTE,
	ID_MENU_EDIT_DELETE,
	ID_MENU_EDIT_PLUG,
	ID_MENU_HELP_ABOUT,

	// Multipage 
	ID_MULTIPAGE,
	ID_PAGEDEMO,

	// Dialog of cable
	ID_TEXT_TITLE,
	ID_EDIT_CODE,
	ID_TEXT_NAME,
	ID_EDIT_NAME,
	ID_TEXT_USAGE,
	ID_EDIT_USAGE,
	ID_TEXT_VERSION,
	ID_EDIT_VERSION,
	ID_TEXT_AUTHOR,		// 制卡者
	ID_EDIT_AUTHOR,
	ID_TEXT_ADATE,		// 
	ID_EDIT_ADATE,
	ID_TEXT_MODIFIER,		// 修改者
	ID_EDIT_MODIFIER,
	ID_TEXT_MDATE,
	ID_EDIT_MDATE,
	ID_TEXT_AUDITOR,	// 审核
	ID_EDIT_AUDITOR,
	ID_TEXT_NOTES,
	ID_MULTIEDIT_NOTES,

	ID_TEXT_PA,
	ID_TEXT_PB,
	ID_EDIT_PA,
	ID_EDIT_PB,
	ID_DROPDOWN_PA,
	ID_DROPDOWN_PB,
	ID_LISTVIEW_PA,
	ID_LISTVIEW_PB,

	ID_TEXT_CABLE_NAME,
	ID_EDIT_CABLE_NAME,
	ID_TEXT_CABLE_LABLE,
	ID_EDIT_CABLE_LABLE,
	ID_TEXT_CABLE_LEN,
	ID_EDIT_CABLE_LEN,

	// frm 56
	// ID_BUTTON_EDIT
	// ID_BUTTON_VIEW
	// ID_BUTTON_FIND
	// ID_BUTTON_RUN

};

/*********************************************************************
*
*       ID: start from 30
*
**********************************************************************
*/

/*********************************************************************
*
*       Position of item in the window of cable info.
*
**********************************************************************
*/

#define WC_PAGE_X0			(0)
#define WC_PAGE_Y0			(0)
#define WC_PAGE_XSIZE		(780)
#define WC_PAGE_YSIZE		(800)

#define WC_TITLE_Y0			(5)
#define WC_TITLE_X0			(WC_PAGE_XSIZE / 5)
#define WC_TITLE_XSIZE		(WC_PAGE_XSIZE / 2)
#define WC_TITLE_YSIZE		(33)

#define WC_CODE_Y0			(15)
#define WC_CODE_X0			(590)
#define WC_CODE_XSIZE		(170)	
#define WC_CODE_YSIZE		(20)

#define WC_LINE_HEIGHT		(1)
#define WC_LINE_LENGTH		(760)
#define WC_TEXT_HEIGHT		(16)
#define WC_TEXT_LENGTH		(70)

#define WC_LINE1_X0			(20)
#define WC_LINE1_Y0			(WC_TITLE_Y0 + 40)	// WC_TITLE_YSIZE * 1.25)

#define WC_NAME_X0			(WC_LINE1_X0 + 10) 
#define WC_NAME_Y0			(WC_LINE1_Y0 + 8)	// WC_TEXT_HEIGHT/2)

#define WC_USAGE_X0			WC_NAME_X0		
#define WC_USAGE_Y0			(WC_NAME_Y0 + 24)	// WC_TEXT_HEIGHT*1.5)

#define WC_VERSION_X0		(WC_NAME_X0	+ 500)
#define WC_VERSION_Y0		(WC_NAME_Y0)	

#define WC_NOTES_X0			WC_NAME_X0
#define WC_NOTES_Y0			(WC_USAGE_Y0 + 24)	// WC_TEXT_HEIGHT*1.5) 

#define WC_LINE2_X0			WC_LINE1_X0
#define WC_LINE2_Y0			(WC_NOTES_Y0 + 80)	// WC_TEXT_HEIGHT*5) 

#define WC_AUTHOR_X0		WC_NAME_X0		
#define WC_AUTHOR_Y0		(WC_LINE2_Y0 + 8)	// WC_TEXT_HEIGHT*0.5)

#define WC_ADATE_X0			(WC_LINE1_X0 + 280)
#define WC_ADATE_Y0			WC_AUTHOR_Y0

#define WC_MODIFIER_X0		WC_NAME_X0		
#define WC_MODIFIER_Y0		(WC_AUTHOR_Y0 + 24)		// WC_TEXT_HEIGHT*1.5)

#define WC_MDATE_X0			(WC_LINE1_X0 + 280) 
#define WC_MDATE_Y0			WC_MODIFIER_Y0

#define WC_AUDITOR_X0		(WC_MDATE_X0 + 280) 
#define WC_AUDITOR_Y0		WC_MODIFIER_Y0

#define WC_LINE3_X0			WC_LINE1_X0	
#define WC_LINE3_Y0			(WC_MODIFIER_Y0 + 24)	// WC_TEXT_HEIGHT*1.5) 

#define WC_PARTA_X0			WC_NAME_X0	
#define WC_PARTA_Y0			(WC_LINE3_Y0 + 24)

#define WC_PARTB_X0			(WC_NAME_X0 + 500)	
#define WC_PARTB_Y0			WC_PARTA_Y0

#define WC_CABLE_X0			(WC_NAME_X0 + 140)	
#define WC_CABLE_Y0			(WC_PARTA_Y0 + 200)

#define WC_EDIT_WIDTH		(650)					// (WC_PAGE_XSIZE * 5 / 6)
#define WC_EDIT_HEIGHT		(20)
#define WC_EDIT_YOFF		(1)			// ((WC_EDIT_HEIGHT - WC_TEXT_HEIGHT) / 3)

static const GUI_WIDGET_CREATE_INFO _aDialogCreatePage1[] = {
	{ WINDOW_CreateIndirect, "Cable Info", ID_PAGEDEMO, WC_PAGE_X0, WC_PAGE_Y0, WC_PAGE_XSIZE, WC_PAGE_YSIZE, FRAMEWIN_CF_MOVEABLE },

	{ TEXT_CreateIndirect, "电缆工艺卡~", ID_TEXT_TITLE, WC_TITLE_X0, WC_TITLE_Y0, WC_TITLE_XSIZE, WC_TITLE_YSIZE, TEXT_CF_HCENTER },
	{ TEXT_CreateIndirect, "1.名称:", ID_TEXT_NAME, WC_NAME_X0, WC_NAME_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "2.版本:", ID_TEXT_VERSION, WC_VERSION_X0, WC_VERSION_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "3.用途：", ID_TEXT_USAGE, WC_USAGE_X0, WC_USAGE_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "4.说明:", ID_TEXT_NOTES, WC_NOTES_X0, WC_NOTES_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "制卡者：", ID_TEXT_AUTHOR, WC_AUTHOR_X0, WC_AUTHOR_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "制卡日期:", ID_TEXT_ADATE, WC_ADATE_X0, WC_ADATE_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "修改者：", ID_TEXT_MODIFIER, WC_MODIFIER_X0, WC_MODIFIER_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "修改日期:", ID_TEXT_MDATE, WC_MDATE_X0, WC_MDATE_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "审核者：", ID_TEXT_AUDITOR, WC_AUDITOR_X0, WC_AUDITOR_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "PART A", ID_TEXT_PA, WC_PARTA_X0, WC_PARTA_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "PART B", ID_TEXT_PB, WC_PARTB_X0, WC_PARTB_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "线材:", ID_TEXT_CABLE_NAME, WC_CABLE_X0, WC_CABLE_Y0, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "标签:", ID_TEXT_CABLE_LABLE, WC_CABLE_X0, WC_CABLE_Y0 + 24, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },
	{ TEXT_CreateIndirect, "长度:", ID_TEXT_CABLE_LEN, WC_CABLE_X0, WC_CABLE_Y0 + 48, WC_TEXT_LENGTH, WC_TEXT_HEIGHT, TEXT_CF_LEFT },


	{ EDIT_CreateIndirect, "41205-2241", ID_EDIT_CODE, WC_CODE_X0, WC_CODE_Y0 - WC_EDIT_YOFF, WC_CODE_XSIZE, WC_CODE_YSIZE, TEXT_CF_HCENTER, 50, 0 },
	{ EDIT_CreateIndirect, "Edit_NAME", ID_EDIT_NAME, WC_NAME_X0 + WC_TEXT_LENGTH, WC_NAME_Y0 - WC_EDIT_YOFF, 400, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_USAGE", ID_EDIT_USAGE, WC_USAGE_X0 + WC_TEXT_LENGTH, WC_USAGE_Y0 - WC_EDIT_YOFF, WC_EDIT_WIDTH, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "Edit_VERSION", ID_EDIT_VERSION, WC_VERSION_X0 + WC_TEXT_LENGTH, WC_VERSION_Y0 - WC_EDIT_YOFF, 150, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ MULTIEDIT_CreateIndirect, "MultiEdit_NOTES", ID_MULTIEDIT_NOTES, WC_NOTES_X0 + WC_TEXT_LENGTH, WC_NOTES_Y0 - WC_EDIT_YOFF, WC_EDIT_WIDTH, 75, 0, 254, 0 },
	{ EDIT_CreateIndirect, "ID_EDIT_AUTHOR", ID_EDIT_AUTHOR, WC_AUTHOR_X0 + WC_TEXT_LENGTH, WC_AUTHOR_Y0 - WC_EDIT_YOFF, 100, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "ID_EDIT_ADATE", ID_EDIT_ADATE, WC_ADATE_X0 + WC_TEXT_LENGTH + 18, WC_ADATE_Y0 - WC_EDIT_YOFF, 100, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "ID_EDIT_MODIFIER", ID_EDIT_MODIFIER, WC_MODIFIER_X0 + WC_TEXT_LENGTH, WC_MODIFIER_Y0 - WC_EDIT_YOFF, 100, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "ID_EDIT_MDATE", ID_EDIT_MDATE, WC_MDATE_X0 + WC_TEXT_LENGTH + 18, WC_MDATE_Y0 - WC_EDIT_YOFF, 100, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "ID_EDIT_AUDITOR", ID_EDIT_AUDITOR, WC_AUDITOR_X0 + WC_TEXT_LENGTH, WC_AUDITOR_Y0 - WC_EDIT_YOFF, 100, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "PART_AName", ID_EDIT_PA, WC_PARTA_X0, WC_PARTA_Y0 + 23, 200, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "PART_BName", ID_EDIT_PB, WC_PARTB_X0, WC_PARTB_Y0 + 23, 200, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "CABLE_NAME", ID_EDIT_CABLE_NAME, WC_CABLE_X0 + 50, WC_CABLE_Y0, 400, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "CABLE_LABLE", ID_EDIT_CABLE_LABLE, WC_CABLE_X0 + 50, WC_CABLE_Y0 + 23, 400, WC_EDIT_HEIGHT, 0, 0x64, 0 },
	{ EDIT_CreateIndirect, "CABLE_LEN", ID_EDIT_CABLE_LEN, WC_CABLE_X0 + 50, WC_CABLE_Y0 + 47, 400, WC_EDIT_HEIGHT, 0, 0x64, 0 },

	{ DROPDOWN_CreateIndirect, "Dropdown_PA", ID_DROPDOWN_PA, WC_PARTA_X0, WC_PARTA_Y0 + 47, 200, 200, 0, 0x64, 0 },
	{ DROPDOWN_CreateIndirect, "Dropdown_PB", ID_DROPDOWN_PB, WC_PARTB_X0, WC_PARTB_Y0 + 47, 200, 200, 0, 0x64, 0 },

	/*
	{ TEXT_CreateIndirect, "PART_A Notes", ID_TEXT_PANOTES, 360, 390, 180, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "PART_B Notes", ID_TEXT_PBNOTES, 560, 390, 180, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "接口类型:", ID_TEXT_PA, 360, 45, 80, 20, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "接口类型:", ID_TEXT_PB, 560, 45, 80, 20, 0, 0x0, 0 },
	{ LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_PA, 360, 70, 180, 310, 0, 0x0, 0 },
	{ LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_PB, 560, 70, 180, 310, 0, 0x0, 0 },
	*/
	//{ EDIT_CreateIndirect, "Edit_CABLE", ID_EDIT_CABLE, 150, 15, 190, 30, 0, 0x64, 0 },
	//{ EDIT_CreateIndirect, "Edit_MAT", ID_EDIT_MAT, WC_NAME_X0  gc+ WC_TEXT_LENGTH, WC_TEXT_HEIGHT, 0, 0x64, 0 }, 
	//{ EDIT_CreateIndirect, "Edit_LEN", ID_EDIT_LEN, WC_NAME_X0  gc+ WC_TEXT_LENGTH, WC_TEXT_HEIGHT, 0, 0x64, 0 }, 
};

static const GUI_WIDGET_CREATE_INFO _aDialogCreateEditPlug[] = {
	/*
	{ FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 92, 127, 383, 240, 0, 0x0, 0 },
	{ MULTIPAGE_CreateIndirect, "Multipage", ID_MULTIPAGE_0, 9, 6, 358, 204, 0, 0x0, 0 },
	{ TEXT_CreateIndirect, "Text", ID_TEXT_0, 0, 17, 80, 3, 0, 0x0, 0 },
	{ LISTVIEW_CreateIndirect, "Listview", ID_LISTVIEW_0, 25, 27, 201, 150, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "New", ID_BUTTON_0, 244, 30, 50, 20, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "Copy", ID_BUTTON_1, 243, 56, 49, 20, 0, 0x0, 0 },
	{ BUTTON_CreateIndirect, "delete", ID_BUTTON_2, 246, 81, 44, 20, 0, 0x0, 0 },
	*/
};


//
// Recommended memory to run the sample with adequate performance
//
#define RECOMMENDED_MEMORY (1024L * 10)


/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


static char * _paDescription[] = {
	"Creates a new file",
	"Opens an existing file",
	"Closes the file",
	"Quits the application",
	" ",
	"Opens file 1",
	"Opens file 2",
	"Opens file 3",
	"Opens file 4",
	"Undoes the last action",
	"Redoes the previously undone action",
	"Copies to clipboard",
	"Inserts contents of clipboard",
	"Deletes the selection",
	"Displays program information"
};

static WM_HWIN  hFrame, hClient;
static WM_HWIN  hMenu, hMultiPage, hTextTips;
static WM_HWIN  hPageDemo;

static WM_SCROLL_STATE vScrollState;
static int iCurrentPage = 0;
pageData_t tPageData[MAX_PAGE];


/*********************************************************************
*
*       Static data
*
**********************************************************************
*/


/*********************************************************************
*
*       _SetWidgetEffect
*
* Function description
*   Sets the effect for the given widget and its child windows
*/
static void _SetWidgetEffect(WM_HWIN hWin, const WIDGET_EFFECT * pEffect) {
	WM_HWIN hChild;

	if (hWin) {
		WIDGET_SetEffect(hWin, pEffect);
		//
		// Iterate over the child windows
		//
		hChild = WM_GetFirstChild(hWin);
		while (hChild) {
			WIDGET_SetEffect(hChild, pEffect);
			hChild = WM_GetNextSibling(hChild);
		}
	}
}

/*********************************************************************
*
*       _AddMenuItem
*/
static void _AddMenuItem(MENU_Handle hMenu, MENU_Handle hSubmenu, const char* pText, U16 Id, U16 Flags) {
	MENU_ITEM_DATA Item;

	Item.pText = pText;
	Item.hSubmenu = hSubmenu;
	Item.Flags = Flags;
	Item.Id = Id;
	MENU_AddItem(hMenu, &Item);
}

/*********************************************************************
*
*       _CreateMenu
*
* Function description
*   Creates the menu widget
*/
static WM_HWIN _CreateMenu(WM_HWIN hParent) {
	MENU_Handle hMenu;
	MENU_Handle hMenuCable;
	MENU_Handle hMenuEdit;
	MENU_Handle hMenuHelp;
	MENU_Handle hMenuRecent;

	//
	// Create main menu
	//
	hMenu = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_HORIZONTAL, ID_MENU);
	//
	// Create sub menus
	//
	hMenuCable = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
	hMenuEdit = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
	hMenuHelp = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
	hMenuRecent = MENU_CreateEx(0, 0, 0, 0, WM_UNATTACHED, 0, MENU_CF_VERTICAL, 0);
	//
	// Add menu items to menu 'Recent'
	//
	_AddMenuItem(hMenuRecent, 0, "文件 1", ID_MENU_RECENT_0, 0);
	_AddMenuItem(hMenuRecent, 0, "文件 2", ID_MENU_RECENT_1, 0);
	_AddMenuItem(hMenuRecent, 0, "文件 3", ID_MENU_RECENT_2, 0);
	_AddMenuItem(hMenuRecent, 0, "文件 4", ID_MENU_RECENT_3, 0);
	//
	// Add menu items to menu 'File'
	//
	_AddMenuItem(hMenuCable, 0, "新建  ", ID_MENU_CABLE_NEW, MENU_IF_DISABLED);
	_AddMenuItem(hMenuCable, 0, "打开  ", ID_MENU_CABLE_OPEN, 0);
	_AddMenuItem(hMenuCable, 0, "关闭  ", ID_MENU_CABLE_CLOSE, MENU_IF_DISABLED);
	_AddMenuItem(hMenuCable, 0, 0, 0, MENU_IF_SEPARATOR);
	_AddMenuItem(hMenuCable, hMenuRecent, "最近打开", ID_MENU_CABLE_RECENT, 0);
	_AddMenuItem(hMenuCable, 0, 0, 0, MENU_IF_SEPARATOR);
	_AddMenuItem(hMenuCable, 0, " 退出~", ID_MENU_CABLE_EXIT, 0);
	//
	// Add menu items to menu 'Edit'
	//
	_AddMenuItem(hMenuEdit, 0, "撤销  ", ID_MENU_EDIT_UNDO, 0);
	_AddMenuItem(hMenuEdit, 0, "恢复  ", ID_MENU_EDIT_REDO, 0);
	_AddMenuItem(hMenuEdit, 0, 0, 0, MENU_IF_SEPARATOR);
	_AddMenuItem(hMenuEdit, 0, "复制  ", ID_MENU_EDIT_COPY, 0);
	_AddMenuItem(hMenuEdit, 0, "粘贴  ", ID_MENU_EDIT_PASTE, 0);
	_AddMenuItem(hMenuEdit, 0, "删除  ", ID_MENU_EDIT_DELETE, 0);
	_AddMenuItem(hMenuEdit, 0, "插头  ", ID_MENU_EDIT_PLUG, 0);

	//
	// Add menu items to menu 'Help'
	//
	_AddMenuItem(hMenuHelp, 0, "关于", ID_MENU_HELP_ABOUT, 0);
	//
	// Add menu items to main menu
	//
	_AddMenuItem(hMenu, hMenuCable, "线缆", 0, 0);
	_AddMenuItem(hMenu, hMenuEdit, "编辑", 0, 0);
	_AddMenuItem(hMenu, hMenuHelp, "帮助", 0, 0);
	//
	// Attach menu to parent window
	//
	FRAMEWIN_AddMenu(hParent, hMenu);
	return hMenu;
}

/*********************************************************************
*
*       _DrawGradientV
*
* Function description
*   Draws a vertical gradient
*/
static void _DrawGradientV(int x0, int y0, int x1, int y1, GUI_COLOR Color0, GUI_COLOR Color1) {
	int r0;
	int g0;
	int b0;
	int r1;
	int g1;
	int b1;
	int y;
	int ySize;
	int r;
	int g;
	//U32 a;
	I32 b;
	int Diff;

	ySize = y1 - y0 + 1;
	//a =
	r0 = (Color0 >> 0) & 0x000000ff;
	g0 = (Color0 >> 8) & 0x000000ff;
	b0 = (Color0 >> 16) & 0x000000ff;
	r1 = (Color1 >> 0) & 0x000000ff;
	g1 = (Color1 >> 8) & 0x000000ff;
	b1 = (Color1 >> 16) & 0x000000ff;
	for (y = y0; y <= y1; y++) {
		GUI_COLOR Color;
		Diff = y - y0;
		r = r0 + (r1 - r0) * Diff / ySize;
		g = g0 + (g1 - g0) * Diff / ySize;
		b = b0 + (b1 - b0) * Diff / ySize;
		Color = r | (g << 8) | (b << 16);
#if (GUI_USE_ARGB == 1)
		Color |= 0xFF000000;
#endif
		GUI_SetColor(Color);
		GUI_DrawHLine(y, x0, x1);
	}
}

/*********************************************************************
*
*       _MessageBox
*
* Function description
*   Creates and executes a modal message box
*/
static void _MessageBox(const char * pText, const char * pCaption) {
	WM_HWIN hBox;

	hBox = MESSAGEBOX_Create(pText, pCaption, GUI_MESSAGEBOX_CF_MODAL | GUI_MESSAGEBOX_CF_MOVEABLE);
	WM_SetStayOnTop(hBox, 1);
	WM_BringToTop(hBox);
	GUI_ExecCreatedDialog(hBox);
	WM_SetFocus(hMenu);
	MENU_SetSel(hMenu, -1);
}

/*********************************************************************
*
*       _cbClient
*
* Function description
*   Callback routine of client window which 'owns' the menu widget
*   and the status bar
*/
static void _cbClient(WM_MESSAGE * pMsg) {
	char acBuffer[50];
	int             Index;
	int             xSize;
	int             ySize;
	int             xPos;
	int             yPos;
	WM_HWIN         hWin;
	WM_HWIN         hClient;
	MENU_MSG_DATA * pData;
	MENU_ITEM_DATA  Data;
	int nCode, wId;

	hWin = pMsg->hWin;
	hClient = WM_GetClientWindow(hWin);
	xSize = WM_GetWindowSizeX(hClient);
	ySize = WM_GetWindowSizeY(hClient);
	switch (pMsg->MsgId) {

	case WM_SIZE:
		//
		// Adjusts text widget on changinmg the size
		//
		xPos = WM_GetWindowOrgX(hClient);
		yPos = WM_GetWindowOrgY(hClient);
		WM_SetWindowPos(hTextTips, xPos + 4, yPos + ySize - 10, xSize, 10);
		TEXT_SetText(hTextTips, "Ready");
		break;
	case WM_PAINT:

		break;
	case WM_MENU:
		pData = (MENU_MSG_DATA*)pMsg->Data.p;
		switch (pData->MsgType) {
		case MENU_ON_ITEMPRESSED:
			//
			// This message is send regardless of the item state is disabled or not
			//
			MENU_GetItem(pMsg->hWinSrc, pData->ItemId, &Data);
			if (Data.Flags & MENU_IF_DISABLED) {
				_MessageBox("The pressed item was disabled", "Message");
			}
			break;
		case MENU_ON_ITEMACTIVATE:
			//
			// This message is send on highlighting a menu item
			//
			Index = pData->ItemId - ID_MENU_CABLE_NEW;
			if (Index >= 0) {
				TEXT_SetText(hTextTips, _paDescription[pData->ItemId - ID_MENU_CABLE_NEW]);
			}
			else {
				TEXT_SetText(hTextTips, "准备就绪");
			}
			break;
		case MENU_ON_ITEMSELECT:
			//
			// This message is send only if an enabled item has been selected
			//
			sprintf(acBuffer, "ID of the selected\nitem is 0x%X", pData->ItemId);
			_MessageBox(acBuffer, "Message");
			break;
		default:
			break;
		}
		break;

	case WM_NOTIFY_PARENT:
		wId = WM_GetId(pMsg->hWinSrc);
		nCode = pMsg->Data.v;
		switch (nCode)
		{
		case WM_NOTIFICATION_VALUE_CHANGED:
			switch (wId){
			case ID_MULTIPAGE:
				// tap is clicked
				iCurrentPage = MULTIPAGE_GetSelection(pMsg->hWinSrc);

				// page recover
				xPos = WM_GetWinOrgX(hPageDemo);
				yPos = WM_GetWinOrgY(WM_GetParent(hPageDemo)) - tPageData[iCurrentPage].vScrollPos;
				WM_MoveTo(hPageDemo, xPos, yPos);

				// load corresponding data

				break;

			case GUI_ID_VSCROLL:
				WM_GetScrollState(pMsg->hWinSrc, &vScrollState);
				xPos = WM_GetWinOrgX(hPageDemo);
				yPos = WM_GetWinOrgY(WM_GetParent(hPageDemo)) - vScrollState.v;
				WM_MoveTo(hPageDemo, xPos, yPos);
				tPageData[iCurrentPage].vScrollPos = vScrollState.v;
				break;
			default:

				break;
			}
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}
	WM_DefaultProc(pMsg);
}


void _cbPageDemo(WM_MESSAGE * pMsg){
	WM_HWIN hItem;
	WM_HWIN hDlg;

	int             xSize;
	int             ySize;
	int             xPos;
	int             yPos;
	int ox, oy;

	hDlg = pMsg->hWin;
	xSize = WM_GetWindowSizeX(hDlg);
	ySize = WM_GetWindowSizeY(WM_GetParent(hDlg));
	switch (pMsg->MsgId)
	{
	case WM_INIT_DIALOG:
		WINDOW_SetBkColor(hDlg, COLOR_BG);

		hItem = WM_GetDialogItem(hDlg, ID_TEXT_TITLE);
		TEXT_SetFont(hItem, &GUI_Fontlishu_33a4);
		TEXT_SetTextColor(hItem, COLOR_TITLE);

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_CODE);
		//EDIT_SetText(hItem, "81001.03-1081xxxxxx2");
		EDIT_SetText(hItem, "81001.03-1081x2");
		//WIDGET_SetEffect(hItem, &WIDGET_Effect_None);

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_NAME);
		EDIT_SetText(hItem, "位置编码器反馈电缆（德州德隆专用）_");
		EDIT_EnableBlink(hItem, 300, 1);

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_VERSION);
		EDIT_SetText(hItem, "V1201");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_USAGE);
		EDIT_SetText(hItem, "ZD210驱动器到天津宜科编码器EB58MK-C10-1024型_");

		hItem = WM_GetDialogItem(hDlg, ID_MULTIEDIT_NOTES);
		MULTIEDIT_SetFont(hItem, &GUI_Fontsong_16);
		MULTIEDIT_SetText(hItem, "  凑行数_\n  电缆标签为：_\n  电缆散线侧套线标压接端子；圆形连接器自带电缆线，截短至50mm，再进行焊接。_\n  距插头100mm处固定标签；需要的情况下使用热缩管；_\n* 修改线材，更改端子。_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_AUTHOR);
		EDIT_SetText(hItem, "亓岳鑫_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_ADATE);
		EDIT_SetText(hItem, "2018-12-12");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_MODIFIER);
		EDIT_SetText(hItem, "欧阳九天_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_MDATE);
		EDIT_SetText(hItem, "2019-05-12");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_AUDITOR);
		EDIT_SetText(hItem, "就凑五个字_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_PA);
		EDIT_SetText(hItem, "驱动器侧X21端口_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_PB);
		EDIT_SetText(hItem, "FGW219-191-0.48M/M25");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_CABLE_NAME);
		EDIT_SetText(hItem, "RVVP-6*0.2+2*0.5mm^2（双绞）_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_CABLE_LABLE);
		EDIT_SetText(hItem, "71815.01-1081(ZD200/ZD210+晟昌SVM电机光电反馈）_");

		hItem = WM_GetDialogItem(hDlg, ID_EDIT_CABLE_LEN);
		EDIT_SetText(hItem, "见电缆清单。_");

		hItem = WM_GetDialogItem(hDlg, ID_DROPDOWN_PA);
		DROPDOWN_AddString(hItem, "删除");
		DROPDOWN_AddString(hItem, "DB");
		DROPDOWN_AddString(hItem, "HDB");
		DROPDOWN_AddString(hItem, "FGW219-191-0.48M/M25");
		DROPDOWN_AddString(hItem, "添加");

		//EDIT_SetBkColor(hItem, 1, COLOR_EDITBK);
		//WM_DisableWindow(hItem);
		//WIDGET_SetEffect(hItem, &WIDGET_Effect_None);

		//WM_HideWindow(hItem);

		break;
	case WM_PAINT:
		//
		// Draws the background of the client window
		//
		//_DrawGradientV(0, tPageData[iCurrentPage].vScrollPos, xSize - 1, \
			//tPageData[iCurrentPage].vScrollPos + ySize - 5, COLOR_BK0, COLOR_BK1);
		
		// Draw lines
		GUI_SetPenSize(WC_LINE_HEIGHT);

		GUI_SetColor(COLOR_LINE);
		GUI_DrawLine(WC_LINE1_X0, WC_LINE1_Y0, WC_LINE_LENGTH, WC_LINE1_Y0); 
		GUI_DrawLine(WC_LINE2_X0, WC_LINE2_Y0, WC_LINE_LENGTH, WC_LINE2_Y0); 
		GUI_DrawLine(WC_LINE3_X0, WC_LINE3_Y0, WC_LINE_LENGTH, WC_LINE3_Y0); 


		// 
		//hItem = WM_GetDialogItem(hDlg, ID_EDIT_NAME);
		//EDIT_SetText(hItem, "请输入线缆名称_");
		///*
		DrawPlugDb(WC_LINE3_X0, WC_LINE3_Y0 + 40);
		//DrawPlugDbMirror(WC_LINE3_X0 + 120, WC_LINE3_Y0 + 40);
		DrawPlugHdb(WC_LINE3_X0 + 160, WC_LINE3_Y0 + 40);
		//DrawPlugHdbMirror(WC_LINE3_X0 + 280, WC_LINE3_Y0 + 40);
		DrawPlugKt(WC_LINE3_X0 + 320, WC_LINE3_Y0 + 40);
		//DrawPlugKtMirror(WC_LINE3_X0 + 380, WC_LINE3_Y0 + 40);
		DrawPlugEt(WC_LINE3_X0 + 320, WC_LINE3_Y0 + 60);
		//DrawPlugEtMirror(WC_LINE3_X0 + 380, WC_LINE3_Y0 + 60);
		DrawPlugOt(WC_LINE3_X0 + 320, WC_LINE3_Y0 + 80);
		//DrawPlugOtMirror(WC_LINE3_X0 + 380, WC_LINE3_Y0 + 80);
		DrawPlugUsb(WC_LINE3_X0 + 450, WC_LINE3_Y0 + 40);
		//DrawPlugUsbMirror(WC_LINE3_X0 + 580, WC_LINE3_Y0 + 40);
		DrawPlugRj45(WC_LINE3_X0 + 660, WC_LINE3_Y0 + 40);
		//DrawPlugRj45Mirror(WC_LINE3_X0 + 660, WC_LINE3_Y0 + 80);

		DrawPlugFgw(WC_LINE3_X0, WC_LINE3_Y0 + 120);
		//DrawPlugFgwMirror(WC_LINE3_X0 + 120, WC_LINE3_Y0 + 120);
		DrawPlugHc(WC_LINE3_X0 + 160, WC_LINE3_Y0 + 120);
		//DrawPlugHcMirror(WC_LINE3_X0 + 280, WC_LINE3_Y0 + 120);
		DrawPlugHcr(WC_LINE3_X0 + 320, WC_LINE3_Y0 + 120);
		//DrawPlugHcrMirror(WC_LINE3_X0 + 450, WC_LINE3_Y0 + 120);
		DrawPlugLc4(WC_LINE3_X0 + 520, WC_LINE3_Y0 + 120);
		//DrawPlugLc6Mirror(WC_LINE3_X0 + 600, WC_LINE3_Y0 + 120);
//*/

		break;
	default:
		WM_DefaultProc(pMsg);
		break;
	}
}

#if 0
// Load default skin
static void LoadDefaultSkin(void)
{
	WM_SetDesktopColor(COLOR_DESKTOP); // desktop bk color

	// 1. frame:
	// skin
	FRAMEWIN_SKINFLEX_PROPS props;
	FRAMEWIN_GetSkinFlexProps(&props, FRAMEWIN_SKINFLEX_PI_ACTIVE);
	props.aColorTitle[0] = COLOR_FRAMEBAR0;
	props.aColorTitle[1] = COLOR_FRAMEBAR1;
	props.aColorFrame[0] = COLOR_FRAMEOUT;
	props.aColorFrame[1] = COLOR_FRAMEINNER;
	props.aColorFrame[2] = COLOR_FRAMEAREA;
	props.SpaceX = 0;
	FRAMEWIN_SetSkinFlexProps(&props, FRAMEWIN_SKINFLEX_PI_ACTIVE);

	// text's font & color:
	FRAMEWIN_SetDefaultTextColor(1, COLOR_FRAMETEXT);
	FRAMEWIN_SetDefaultClientColor(COLOR_FRAMECBK);

	// 2. Menu
	// skin
	MENU_SKINFLEX_PROPS mProps;
	MENU_GetSkinFlexProps(&mProps, MENU_SKINFLEX_PI_ENABLED);
	mProps.aBkColorH[0] = COLOR_MENUTOP;
	mProps.aBkColorH[1] = COLOR_MENUBTM;
	mProps.BkColorV = COLOR_MENUVRT;
	mProps.aSelColorH[0] = COLOR_MENUSELH0;
	mProps.aSelColorH[1] = COLOR_MENUSELH1;
	mProps.aSelColorV[0] = COLOR_MENUSELV0;
	mProps.aSelColorV[1] = COLOR_MENUSELV1;
	mProps.FrameColorSelH = mProps.FrameColorSelV;
	mProps.ArrowColor = COLOR_MENUTEXT;
	mProps.TextColor = COLOR_MENUTEXT;
	mProps.aSepColorH[0] = mProps.aSelColorH[0];
	mProps.aSepColorH[1] = mProps.TextColor;
	mProps.aSepColorV[0] = mProps.aSelColorV[0];
	mProps.aSepColorV[1] = mProps.TextColor;

	MENU_SetSkinFlexProps (&mProps, MENU_SKINFLEX_PI_ENABLED);
	MENU_SetSkinFlexProps (&mProps, MENU_SKINFLEX_PI_ACTIVE_SUBMENU);
	MENU_SetSkinFlexProps (&mProps, MENU_SKINFLEX_PI_SELECTED);

	mProps.TextColor = COLOR_MENUTEXT0;
	MENU_SetSkinFlexProps (&mProps, MENU_SKINFLEX_PI_DISABLED);

	// font & color of text
	MENU_SetDefaultEffect(&WIDGET_Effect_3D1L);

	// 3. Multipage
	MULTIPAGE_SKINFLEX_PROPS pProps;
	MULTIPAGE_GetSkinFlexProps(&pProps, MULTIPAGE_SKINFLEX_PI_ENABLED);
	pProps.TextColor = COLOR_MPAGETEXT;
	pProps.FrameColor = COLOR_MPAGEFRAME;
	pProps.aBkUpper[0] = COLOR_MPAGEBG0;
	pProps.aBkUpper[1] = COLOR_MPAGEBG1;
	pProps.aBkLower[0] = COLOR_MPAGETG0;
	pProps.aBkLower[1] = COLOR_MPAGETG1;
	pProps.BkColor = COLOR_MPAGEBK;
	MULTIPAGE_SetSkinFlexProps(&pProps, MULTIPAGE_SKINFLEX_PI_ENABLED);
	MULTIPAGE_SetSkinFlexProps(&pProps, MULTIPAGE_SKINFLEX_PI_SELECTED);
	//MULTIPAGE_SetSkinFlexProps(&pProps, MULTIPAGE_SKINFLEX_PI_DISABLED);

	

	// 4. Edit
	EDIT_SetDefaultBkColor(EDIT_CI_ENABELD, COLOR_EDITBK);
	EDIT_SetDefaultBkColor(EDIT_CI_DISABELD, COLOR_EDITBK);
	EDIT_SetDefaultBkColor(EDIT_CI_CURSOR, COLOR_EDITBK);
	EDIT_SetDefaultTextColor(EDIT_CI_ENABELD, COLOR_TEXT);


	// text
	TEXT_SetDefaultTextColor(COLOR_TEXT);


	DROPDOWN_SetDefaultColor(1, COLOR_TEXT);
	LISTVIEW_SetDefaultTextColor(1, COLOR_TEXT);

}
#endif

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       EnterWinOfCableTester
*/
void EnterWinOfCableTester(void) {
	int     xSize;
	int     ySize;
	WM_HWIN vScrollbar, hScrollbar;
	GUI_RECT RectClient, RectDlg;

	WM_SetCreateFlags(WM_CF_MEMDEV);
	GUI_Init();

	DrawObjInit();


	//
	// Check if recommended memory for the sample is available
	//
	if (GUI_ALLOC_GetNumFreeBytes() < RECOMMENDED_MEMORY) {
		GUI_ErrorOut("Not enough memory available.");
		return;
	}

	GUI_UC_SetEncodeUTF8();		// for using chinese
	GUI_CURSOR_Show();

	FRAMEWIN_SetDefaultFont(&GUI_Fontsong_16);
	MENU_SetDefaultFont(&GUI_Fontsong_16);
	MULTIPAGE_SetDefaultFont(&GUI_Fontsong_16);
	EDIT_SetDefaultFont(&GUI_Fontsong_16);
	MULTIPAGE_SetDefaultFont(&GUI_Fontsong_16);
	TEXT_SetDefaultFont(&GUI_Fontsong_16);
	DROPDOWN_SetDefaultFont(&GUI_Fontsong_16);
	LISTVIEW_SetDefaultFont(&GUI_Fontsong_16);
	//LoadDefaultSkin();

	//
	// Create frame window
	//
	hFrame = FRAMEWIN_CreateEx(0, 0, 800, 480, WM_HBKWIN, WM_CF_SHOW, 0, 0, "自动化线缆测试仪 V2.0", _cbClient);
	//FRAMEWIN_SetFont(hFrame, &GUI_Fontsong_16);
	//FRAMEWIN_AddMaxButton(hFrame, FRAMEWIN_BUTTON_RIGHT, 0);
	FRAMEWIN_AddMinButton(hFrame, FRAMEWIN_BUTTON_RIGHT, 2);

	//
	// Create menu widget
	//
	hMenu = _CreateMenu(hFrame);
	MENU_SetDefaultBkColor(0, COLOR_BG);
	MENU_SetDefaultBkColor(1, COLOR_BG);

	//
	// Create text widget as simple status bar
	//
	hClient = WM_GetClientWindow(hFrame);
	xSize = WM_GetWindowSizeX(hClient);
	ySize = WM_GetWindowSizeY(hClient);
	hTextTips = TEXT_CreateEx(4, ySize - 20, xSize, 20, hClient, WM_CF_SHOW, 0, GUI_ID_TEXT0, "初始化~");
	//TEXT_SetFont(hTextTips, &GUI_Font8_ASCII);

	//
	// Create multipage
	//
	hMultiPage = MULTIPAGE_CreateEx(0, 0, xSize - 10, ySize - 22, hClient, WM_CF_SHOW, 0, ID_MULTIPAGE);
	MULTIPAGE_SetAlign(hMultiPage, MULTIPAGE_ALIGN_LEFT | MULTIPAGE_ALIGN_BOTTOM);

	//
	// Attach scrollbar to framewindows client window and set its properties
	//
	vScrollbar = SCROLLBAR_CreateAttached(hClient, SCROLLBAR_CF_VERTICAL);
	WM_GetClientRectEx(WM_GetClientWindow(hMultiPage), &RectClient);
	SCROLLBAR_SetNumItems(vScrollbar, WC_PAGE_YSIZE);
	SCROLLBAR_SetPageSize(vScrollbar, RectClient.y1);

	// one page
	hPageDemo = GUI_CreateDialogBox(_aDialogCreatePage1, GUI_COUNTOF(_aDialogCreatePage1), _cbPageDemo, WM_UNATTACHED, 0, 0);
	MULTIPAGE_SetDefaultBkColor(COLOR_BG, 1);

	char _pageName[] = "线缆n";
	char _cableId[] = "75011-1081";
	for (int i = 0; i < MAX_PAGE; i++){
		MULTIPAGE_AddPage(hMultiPage, hPageDemo, _pageName);
		iCurrentPage = i;
		MULTIPAGE_SetText(hMultiPage, _cableId, i);
		_cableId[strlen(_cableId) - 1] ++;

	}


	GUI_Delay(500);

	//_SetWidgetEffect(hFrame, &WIDGET_Effect_3D);

	//
	// Set keyboard focus to menu widget
	//
	WM_SetFocus(hMenu);
	MENU_SetSel(hMenu, -1);

	while (1) {
		GUI_Delay(100);
	}
}

