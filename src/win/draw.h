/************************************************************************************************
* @file    win\draw.h
* @date    23:07:23 2019/4/23
* @brief   drawing
* @author  qyx
* @email   qiyuexin@yeah.net
* @Version V2.0.0
************************************************************************************************/

/*********************************************************************
*
*       colors
*
**********************************************************************
*/

// 34 135 146
// 221 211 72
// 242 77 81

#define COLOR_EYE0			( 225 << 16 | 225 << 8 | 225)	// ÒøºÓ°×
#define COLOR_EYE1			( 220 << 16 | 226 << 8 | 241)	// º£ÌìÀ¶
#define COLOR_EYE2			( 250 << 16 | 249 << 8 | 222)	// ÐÓÈÊ»Æ
#define COLOR_EYE3			( 199 << 16 | 237 << 8 | 204)	// ¶¹É³ÂÌ
#define COLOR_EYE5			( 227 << 16 | 237 << 8 | 205)	// Çà²ÝÂÌ
#define COLOR_EYE6			( 233 << 16 | 235 << 8 | 254)	// ¸ð½í×Ï
#define COLOR_EYE7			( 234 << 16 | 234 << 8 | 239)	// ¼«¹â»Ò
#define COLOR_EYE8			( 150 << 16 | 210 << 8 | 255)	// Ç³À¶

#define COLOR_TEXT			GUI_BLACK
#define COLOR_TEXT1			( 225 << 16 | 190 << 8 |   0)	// »ÆÉ«
#define COLOR_TEXT2			( 110 << 16 | 220 << 8 |  10)	// ÂÌÉ«
#define COLOR_TEXT3			( 250 << 16 |   0 << 8 |  62)	// ºìÉ«
#define COLOR_TEXT4			(  20 << 16 | 140 << 8 | 200)	// À¶É«

#define COLOR_BK0			( 168 << 16 | 227 << 8 | 175)
#define COLOR_BK1			( 208 << 16 | 248 << 8 | 208)

#define COLOR_BG			COLOR_EYE8
#define COLOR_TITLE			GUI_BLACK	//GUI_GRAY_3F
#define COLOR_LINE			GUI_GRAY_55
#define COLOR_DESKTOP		(  44 << 16 |   0 << 8 |  30)

#define COLOR_PLUG_SLOT		( 160 << 16 | 150 << 8 | 120)
#define COLOR_PLUG_BODY		( 100 << 16 | 100 << 8 | 100)
#define COLOR_PLUG_BODY2	( 130 << 16 | 130 << 8 | 130)
#define COLOR_PLUG_BODY3	(  70 << 16 | 134 << 8 |  80)	// green
#define COLOR_PLUG_BODY4	(  80 << 16 | 160 << 8 |  90)	// green
//#define COLOR_PLUG_BODY4	(  50 << 16 | 105 << 8 |  60)	// green
#define COLOR_PLUG_LABLE	( 174 << 16 | 174 << 8 | 174)
#define COLOR_PLUG_CABLE	(  61 << 16 |  63 << 8 |  62)
#define COLOR_PLUG_SCREW	(  80 << 16 | 100 << 8 | 100)

/*********************************************************************
*
*       Types & Variable
*
**********************************************************************
*/

typedef enum{
	PLUG_DB,
	PLUG_HDB,
	PLUG_FGW,
	PLUG_HC,
	PLUG_HCR,
	PLUG_KT,
	PLUG_ET,
	PLUG_OT,
	PLUG_USB,
	PLUG_RJ45,
	PLUG_LC,

	PLUG_ITEM,
}plugType_e;

extern char plugName[PLUG_ITEM][5];

////////////////////////////////////////////////////////////////////
//                    base
typedef struct
{
	int x, y, r;	// cicle
} drawCircle_t;

typedef struct
{
	int x, y, r;	// cicle
	GUI_RECT line1, line2;
} drawScrew_t;

typedef struct{
	GUI_POINT orgin;
	int scale;
}plugScrew_t;

typedef struct
{
	// pulg's x,y size
	int xSize, ySize;

	// cable's central pos
	int cableCx, cableCy, cableWidth;
}plugInfo_t;


////////////////////////////////////////////////////////////////////
//                    DB
typedef enum
{
	// rect first
	DB_SLOT = 0,
	DB_LABLE,
	DB_CABLE,
	DB_RECT,	// count of rect items

	// polygon
	DB_BODY = DB_RECT,
	DB_ITEMS,
}itemDb_t;

typedef struct{
	GUI_COLOR color[DB_ITEMS];

	GUI_RECT  rect[DB_RECT];	// slot, lable, cable
	GUI_POINT polygon[14];

	plugInfo_t info;
}drawDb_t;

extern const drawDb_t dbObj;
extern       drawDb_t dbMirror;

////////////////////////////////////////////////////////////////////
//                    FGW
typedef enum{
	// rect first
	FGW_SLOT = 0,
	FGW_BODY1,
	FGW_BODY2,
	FGW_BODY3,
	FGW_BODY4,
	FGW_BODY5,
	FGW_CABLE,
	FGW_RECT,

	// screw
	FGW_SCREW1 = FGW_RECT,
	FGW_SCREW2,
	FGW_ITEMS,
}itemFgw_e;

typedef struct{
	GUI_COLOR	color[FGW_ITEMS];

	GUI_RECT	rect[FGW_RECT];
	plugScrew_t	screw[2];
	plugInfo_t info;
}drawFgw_t;

extern const drawFgw_t fgwObj;
extern		 drawFgw_t fgwMirror;



////////////////////////////////////////////////////////////////////
//                    HDB
typedef enum{
	// rect first
	HDB_SLOT = 0,
	HDB_LABLE,
	HDB_CABLE,
	HDB_RECT,

	// body
	HDB_BODY = HDB_RECT,

	// screw
	HDB_SCREW1,
	HDB_SCREW2,
	HDB_ITEMS,

}itemHdb_e;

typedef struct{
	GUI_COLOR	color[HDB_ITEMS];

	GUI_RECT	rect[HDB_RECT];
	GUI_POINT	polygon[6];
	plugScrew_t	screw[2];

	plugInfo_t info;
}drawHdb_t;

extern const drawHdb_t hdbObj;
extern		 drawHdb_t hdbMirror;


////////////////////////////////////////////////////////////////////
//                    HC
typedef enum{
	// rect first
	HC_SLOT = 0,
	HC_BODY1,
	HC_BODY3,
	HC_BODY4,
	HC_CABLE,
	HC_RECT,

	// polygon
	HC_BODY2 = HC_RECT,

	// screw
	HC_SCREW1,
	HC_SCREW2,
	HC_ITEMS,

}itemHc_e;

typedef struct{
	GUI_COLOR	color[HC_ITEMS];

	GUI_RECT	rect[HC_RECT];
	GUI_POINT	polygon[8];
	plugScrew_t	screw[2];

	plugInfo_t info;
}drawHc_t;

extern const drawHc_t hcObj;
extern		 drawHc_t hcMirror;


////////////////////////////////////////////////////////////////////
//                    HCR
typedef enum{
	// rect first
	HCR_CABLE = 0,
	HCR_BODY2,
	HCR_BODY3,
	HCR_BODY4,
	HCR_RECT,

	// polygon
	HCR_BODY1 = HCR_RECT,

	// screw
	HCR_SCREW1,
	HCR_SCREW2,
	HCR_ITEMS,

}itemHcr_e;

typedef struct{
	GUI_COLOR	color[HCR_ITEMS];

	GUI_RECT	rect[HCR_RECT];
	GUI_POINT	polygon[20];
	plugScrew_t	screw[2];

	plugInfo_t info;
}drawHcr_t;

extern const drawHcr_t hcrObj;
extern		 drawHcr_t hcrMirror;


////////////////////////////////////////////////////////////////////
//                    KT
typedef enum{
	// rect first
	KT_CABLE = 0,
	KT_RECT,

	// polygon
	KT_SLOT = KT_RECT,
	KT_ITEMS,

}itemKt_e;

typedef struct{
	GUI_COLOR	color[KT_ITEMS];

	GUI_RECT	rect[KT_RECT];
	GUI_POINT	polygon[16];

	plugInfo_t info;
}drawKt_t;

extern const drawKt_t ktObj;
extern		 drawKt_t ktMirror;

////////////////////////////////////////////////////////////////////
//                    ET
typedef enum{
	// rect first
	ET_CABLE = 0,
	ET_SLOT,
	ET_RECT,

	ET_ITEMS = ET_RECT,
}itemEt_e;

typedef struct{
	GUI_COLOR	color[ET_ITEMS];

	GUI_RECT	rect[ET_RECT];

	plugInfo_t info;
}drawEt_t;

extern const drawEt_t etObj;
extern		 drawEt_t etMirror;

////////////////////////////////////////////////////////////////////
//                    OT
typedef enum{
	// rect first
	OT_CABLE = 0,
	OT_RECT,

	// polygon
	OT_SLOT1 = OT_RECT,

	// circle
	OT_SLOT2,
	OT_SLOT3,
	OT_ITEMS,

}itemOt_e;

typedef struct{
	GUI_COLOR	color[OT_ITEMS];

	GUI_RECT	rect[OT_RECT];
	GUI_POINT	polygon[4];
	drawCircle_t circle[2];
	
	plugInfo_t info;
}drawOt_t;

extern const drawOt_t otObj;
extern		 drawOt_t otMirror;

////////////////////////////////////////////////////////////////////
//                    USB
typedef enum{
	// rect first
	USB_SLOT = 0,
	USB_BODY2,
	USB_BODY3,
	USB_LABLE,
	USB_BODY4,
	USB_CABLE,
	USB_RECT,

	// polygon
	USB_BODY1 = USB_RECT,

	USB_ITEMS,

}itemUsb_e;

typedef struct{
	GUI_COLOR	color[USB_ITEMS];

	GUI_RECT	rect[USB_RECT];
	GUI_POINT	polygon[8];

	plugInfo_t info;
}drawUsb_t;

extern const drawUsb_t usbObj;
extern		 drawUsb_t usbMirror;

////////////////////////////////////////////////////////////////////
//                    RJ45
typedef enum{
	// rect first
	RJ45_BODY2 = 0,
	RJ45_CABLE,
	RJ45_BODY3,
	RJ45_RECT,

	// polygon
	RJ45_BODY1 = RJ45_RECT,

	RJ45_ITEMS,

}itemRj45_e;

typedef struct{
	GUI_COLOR	color[RJ45_ITEMS];

	GUI_RECT	rect[RJ45_RECT];
	GUI_POINT	polygon[9], up0, down0;

	plugInfo_t info;
}drawRj45_t;

extern const drawRj45_t rj45Obj;
extern		 drawRj45_t rj45Mirror;

////////////////////////////////////////////////////////////////////
//                    LC
typedef enum{
	// rect first
	LC_EDGE = 0,
	LC_BODY1,
	LC_BODY2,
	LC_BODY3,
	LC_BODY4,
	LC_BODY5,
	LC_RECT,

	// screw
	LC_SCREW = LC_RECT,
	LC_ITEMS,

}itemLc_e;

typedef struct{
	GUI_COLOR	color[LC_ITEMS];

	GUI_RECT	rect[LC_RECT];
	plugScrew_t	screw;
	int offY;
	plugInfo_t info;
}drawLc_t;

extern const drawLc_t lcObj;
extern		 drawLc_t lcMirror;




/*********************************************************************
*
*       functions
*
**********************************************************************
*/

/*-----------------------------------------------------------------
- @func    DrawObjInit
- @brief   MUST BE RUN before use drawing function
-----------------------------------------------------------------*/
void DrawObjInit(void);

/*-----------------------------------------------------------------
- @func    GetDbCablePos
- @brief   input origin position return CABLE position
- @para    cablePos: Cable position
-          orgX:     origin x position
-          orgY:     origin y position
- @rtn     void
- @date    2019/4/23
-----------------------------------------------------------------*/
void GetDbCablePos(GUI_POINT *cablePos, int orgX, int orgY);

/*-----------------------------------------------------------------
- @func    _DrawPlugDb
- @brief   draw Plug Db from origin X,Y
- @para    int x : origin X
-          int y : origin Y
- @rtn     void
- @date    2018/4/23
-----------------------------------------------------------------*/
void _DrawPlugDb(int x, int y, drawDb_t *obj);
#define DrawPlugDb(x, y)		 _DrawPlugDb(x, y, &dbObj)
#define DrawPlugDbMirror(x, y)   _DrawPlugDb(x, y, &dbMirror)


/*-----------------------------------------------------------------
- @func    _DrawPlugFgw
- @brief   Draw plug Fgw
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/4/24
-----------------------------------------------------------------*/
void _DrawPlugFgw(int x, int y, drawFgw_t *obj);
#define DrawPlugFgw(x, y)		 _DrawPlugFgw(x, y, &fgwObj)
#define DrawPlugFgwMirror(x, y)  _DrawPlugFgw(x, y, &fgwMirror)


/*-----------------------------------------------------------------
- @func    _DrawPlugHdb
- @brief   Draw plug Hdb
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugHdb(int x, int y, drawHdb_t *);
#define DrawPlugHdb(x, y)		 _DrawPlugHdb(x, y, &hdbObj)
#define DrawPlugHdbMirror(x, y)  _DrawPlugHdb(x, y, &hdbMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugHc
- @brief   Draw plug Hc
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugHc(int x, int y, drawHc_t *);
#define DrawPlugHc(x, y)		 _DrawPlugHc(x, y, &hcObj)
#define DrawPlugHcMirror(x, y)   _DrawPlugHc(x, y, &hcMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugHcr
- @brief   Draw plug Hcr
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugHcr(int x, int y, drawHcr_t *);
#define DrawPlugHcr(x, y)		 _DrawPlugHcr(x, y, &hcrObj)
#define DrawPlugHcrMirror(x, y)   _DrawPlugHcr(x, y, &hcrMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugKt
- @brief   Draw plug Kt
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugKt(int x, int y, drawKt_t *);
#define DrawPlugKt(x, y)		 _DrawPlugKt(x, y, &ktObj)
#define DrawPlugKtMirror(x, y)   _DrawPlugKt(x, y, &ktMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugEt
- @brief   Draw plug Et
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugEt(int x, int y, drawEt_t *);
#define DrawPlugEt(x, y)		 _DrawPlugEt(x, y, &etObj)
#define DrawPlugEtMirror(x, y)   _DrawPlugEt(x, y, &etMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugOt
- @brief   Draw plug Ot
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugOt(int x, int y, drawOt_t *obj);
#define DrawPlugOt(x, y)		 _DrawPlugOt(x, y, &otObj)
#define DrawPlugOtMirror(x, y)   _DrawPlugOt(x, y, &otMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugUsb
- @brief   Draw plug Usb
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugUsb(int x, int y, drawUsb_t *obj);
#define DrawPlugUsb(x, y)		  _DrawPlugUsb(x, y, &usbObj)
#define DrawPlugUsbMirror(x, y)   _DrawPlugUsb(x, y, &usbMirror)

/*-----------------------------------------------------------------
- @func    DrawPlugRj45
- @brief   Draw plug Rj45
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugRj45(int x, int y,	drawRj45_t *obj);
#define DrawPlugRj45(x, y)			_DrawPlugRj45(x, y, &rj45Obj)
#define DrawPlugRj45Mirror(x, y)	_DrawPlugRj45(x, y, &rj45Mirror)

/*-----------------------------------------------------------------
- @func    DrawPlugLc
- @brief   Draw plug Lc
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugLc(int x, int y,	 drawLc_t *obj);
#define DrawPlugLc2(x, y)		 _DrawPlugLc(x, y,  2, &lcObj)
#define DrawPlugLc2Mirror(x, y)   _DrawPlugLc(x, y, 2, &lcMirror)
#define DrawPlugLc3(x, y)		 _DrawPlugLc(x, y,  3, &lcObj)
#define DrawPlugLc3Mirror(x, y)   _DrawPlugLc(x, y, 3, &lcMirror)
#define DrawPlugLc4(x, y)		 _DrawPlugLc(x, y,  4, &lcObj)
#define DrawPlugLc4Mirror(x, y)   _DrawPlugLc(x, y, 4, &lcMirror)
#define DrawPlugLc5(x, y)		 _DrawPlugLc(x, y,  5, &lcObj)
#define DrawPlugLc5Mirror(x, y)   _DrawPlugLc(x, y, 5, &lcMirror)
#define DrawPlugLc6(x, y)		 _DrawPlugLc(x, y,  6, &lcObj)
#define DrawPlugLc6Mirror(x, y)   _DrawPlugLc(x, y, 6, &lcMirror)
#define DrawPlugLc7(x, y)		 _DrawPlugLc(x, y,  7, &lcObj)
#define DrawPlugLc7Mirror(x, y)   _DrawPlugLc(x, y, 7, &lcMirror)



