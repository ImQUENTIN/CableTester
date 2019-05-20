
#include "GUI.h"
#include "win\draw.h"

char plugName[PLUG_ITEM][5] = {
	"DB",	// PLUG_DB,
	"HDB",	// PLUG_HDB,
	"FGW",  // PLUG_FGW,
	"HC",	// PLUG_HC,
	"HCR",	// PLUG_HCR,
	"KT",	// PLUG_KT,
	"ET",	// PLUG_ET,
	"OT",	// PLUG_OT,
	"USB",	// PLUG_USB,
	"RJ45",	// PLUG_RJ45,
	"LC",	// PLUG_LC,
};


/*********************************************************************
*
*       Definations
*
**********************************************************************
*/
//-------------------------------------------------------
//                 Screw
//-------------------------------------------------------
const drawScrew_t screwObj = {
	// circle
	0, 0, 2,

	// line 1
	-1, -1, 1, 1,

	// line 2
	1, -1, -1, 1
};

//-------------------------------------------------------
//                 DB
//-------------------------------------------------------
drawDb_t  dbMirror;
const drawDb_t dbObj = {
	.color = {
		COLOR_PLUG_SLOT,
		COLOR_PLUG_LABLE,
		COLOR_PLUG_CABLE,
		COLOR_PLUG_BODY,
	},

	.rect = {
		{ 0, 14, 3, 50 },	// slot
		{ 16, 24, 24, 40 },	// lable
		{ 43, 26, 60, 38 }, // cable
		},

		.polygon = {
			{ 4, 0 },		// 1
			{ 4, 64 },
			{ 10, 64 },
			{ 14, 60 },
			{ 14, 54 },		// 5
			{ 16, 50 },
			{ 36, 50 },
			{ 42, 46 },
			{ 42, 20 },
			{ 36, 14 },		// 10
			{ 16, 14 },
			{ 14, 10 },
			{ 14, 4 },
			{ 10, 0 }		// 14
		},

		.info = {
				42, 64,
				43, 32, 12
			},
};

//-------------------------------------------------------
//                 FGW
//-------------------------------------------------------
drawFgw_t fgwMirror;
const drawFgw_t fgwObj = {
	.color = {
		COLOR_PLUG_SLOT,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_BODY,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_BODY,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_CABLE,
		COLOR_PLUG_SCREW,
		COLOR_PLUG_SCREW,
	},

	.rect = {
		{ 0, 6, 4, 46 },	// slot
		{ 4, 0, 7, 52 },	// body1
		{ 7, 0, 10, 52 },	// body2
		{ 10, 0, 13, 52 },	// body3
		{ 13, 0, 36, 52 },	// body4
		{ 37, 10, 44, 42 },	// body5

		{ 45, 20, 60, 32 },	// cable
		},

		.screw = {
			// screw 1
			{ 40, 15, 1, },

			// screw 2
			{ 40, 37, 1, }
		},

		.info = {
				44, 52,
				45, 20, 12
			}
};

//-------------------------------------------------------
//                 HDB
//-------------------------------------------------------
drawHdb_t hdbMirror;
const drawHdb_t hdbObj = {
	.color = {
		COLOR_PLUG_SLOT,
		COLOR_PLUG_LABLE,
		COLOR_PLUG_CABLE,
		COLOR_PLUG_BODY,
		COLOR_PLUG_SCREW,
		COLOR_PLUG_SCREW,
	},

	.rect = {
		{ 0, 6, 4, 54 },	// slot
		{ 12, 14, 22, 46 },	// label
		{ 43, 18, 60, 42 },	// cable
		},

		.polygon = {
			{ 4, 0 },
			{ 4, 60 },
			{ 36, 60 },
			{ 42, 54 },
			{ 42, 6 },
			{ 36, 0 },
		},

		.screw = {
				// screw 1
			{ 34, 12, 2, },

			// screw 2
			{ 34, 48, 2, },
			},

			.info = {
				43, 60,
				43, 30, 24
			}
};

//-------------------------------------------------------
//                 HC
//-------------------------------------------------------
drawHc_t hcMirror;
const drawHc_t hcObj = {
	.color = {
		COLOR_PLUG_SLOT,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_BODY,
		COLOR_PLUG_CABLE,

		COLOR_PLUG_BODY,
		COLOR_PLUG_SCREW,
		COLOR_PLUG_SCREW,
	},

	.rect = {
		{ 0,   4, 10, 32 },	// slot
		{ 10,  0, 14, 36 },	// body1
		{ 30,  5, 32, 31 },	// body3
		{ 32,  3, 38, 33 },	// body4
		{ 38, 12, 60, 24 },	// cable
		},

		.polygon = {
			{ 14, 6 },
			{ 14, 30 },
			{ 18, 34 },
			{ 24, 34 },
			{ 30, 32 },
			{ 30, 4 },
			{ 24, 2 },
			{ 18, 2 },	
		},

		.screw = {
				// screw 1
			{ 21,  6, 2},

			// screw 2
			{ 21, 30, 2},
			},

			.info = {
				38, 36,
				38, 18, 12
			}
};


//-------------------------------------------------------
//                 HCR
//-------------------------------------------------------
drawHcr_t hcrMirror;
const drawHcr_t hcrObj = {
	.color = {
		COLOR_PLUG_CABLE,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_SLOT,
		COLOR_PLUG_BODY2,

		COLOR_PLUG_BODY,
		COLOR_PLUG_SCREW,
		COLOR_PLUG_SCREW,
	},

	.rect = {
		{ 0, 8, 10, 20 },	// cable
		{ 14, 0, 24, 28 },	// body2
		{ 34, 41, 62, 53 },	// body3
		{ 34, 44, 62, 50 },	// body4
	},

		.polygon = {
			{ 32, 2 },
			{ 37, 3 },
			{ 40, 4 },
			{ 44, 6 },
			{ 47, 8 },
			{ 50, 10 },
			{ 55, 16 },
			{ 58, 22 },
			{ 59, 25 },
			{ 60, 30 },
			{ 60, 33 },
			{ 60, 57 },
			{ 36, 57 },
			{ 36, 33 },
			{ 36, 32 },
			{ 35, 29 },
			{ 33, 27 },
			{ 30, 26 },
			{ 10, 26 },
			{ 10,  2 },
	},

		.screw = {
				// screw 1
			{ 19, 5, 1 },

			// screw 2
			{ 19, 23, 1 },
			},

			.info = {
				38, 36,
				38, 18, 12
			}
};

//-------------------------------------------------------
//                 KT
//-------------------------------------------------------
drawKt_t ktMirror;
const drawKt_t ktObj = {
	.color = {
		COLOR_PLUG_CABLE,
		COLOR_PLUG_SLOT,
	},

	.rect = {
		{ 0, 2,  8,  8 },	// cable
	},
		.polygon = {
			{  7, 2 },
			{ 10, 2 },
			{ 11, 1 },
			{ 13, 0 },
			{ 23, 0 },
			{ 23, 2 },
			{ 16, 2 },
			{ 14, 4 },
			{ 14, 6 },
			{ 16, 8 },
			{ 23, 8 },
			{ 23, 10 },
			{ 13, 10 },
			{ 11, 9 },
			{ 10, 8 },
			{  7, 8 },
},
			.info = {
				38, 36,
				38, 18, 12
			}
};

//-------------------------------------------------------
//                 ET
//-------------------------------------------------------
drawEt_t etMirror;
const drawEt_t etObj = {
	.color = {
		COLOR_PLUG_CABLE,
		COLOR_PLUG_SLOT,
	},

	.rect = {
		{ 0, 0,  8, 7 },	// cable
		{ 9, 2, 22, 5},		// slot
	},

		.info = {
				38, 36,
				38, 18, 12
			}
};

//-------------------------------------------------------
//                 OT
//-------------------------------------------------------
drawOt_t otMirror;
const drawOt_t otObj = {
	.color = {
		COLOR_PLUG_CABLE,
		COLOR_PLUG_SLOT,
		COLOR_PLUG_SLOT,
		COLOR_BG,
	},

	.rect = {
		{ 0, 3, 9, 9 },  // cable
	},
		.polygon = {
			{ 9, 3 },
			{ 17, 0 },
			{ 17, 11 },
			{ 9, 9 },
},

.circle = {
	{ 19, 6, 6 },
	{ 19, 6, 3 },
			},

			.info = {
				38, 36,
				38, 18, 12
			}
};

//-------------------------------------------------------
//                 USB
//-------------------------------------------------------
drawUsb_t usbMirror;
const drawUsb_t usbObj = {
	.color = {
		COLOR_PLUG_SLOT,
		COLOR_PLUG_BODY,
		COLOR_PLUG_BODY,
		COLOR_PLUG_LABLE,
		COLOR_PLUG_BODY2,
		COLOR_PLUG_CABLE,

		COLOR_PLUG_BODY,
	},

	.rect = {
		{  0,  4, 14, 18 },    // slot
		{  5,  6,  8,  9 },    // body2
		{  5, 13,  8, 16 },    // body3
		{ 18,  4, 32, 18 },    // label
		{ 50,  5, 58, 17 },    // body4
		{ 58,  7, 62, 15 },    // cable
	},

		.polygon = {
			{ 14, 0 },
			{ 36, 0 },
			{ 40, 4 },
			{ 50, 4 },
			{ 50, 18 },
			{ 40, 18 },
			{ 36, 22 },
			{ 14, 22 },
	},

			.info = {
				38, 36,
				38, 18, 12
			}
};

//-------------------------------------------------------
//                 RJ45
//-------------------------------------------------------
drawRj45_t rj45Mirror;
const drawRj45_t rj45Obj = {
	.color = {
		COLOR_PLUG_LABLE,
		COLOR_PLUG_CABLE,
		COLOR_PLUG_CABLE,
		COLOR_PLUG_LABLE,
	},

	.rect = {
		{ 32, 0, 52, 14 },    // body2
		{ 52, 3, 58, 11 },    // cable
		{ 0, 0, 2, 5 },    // body3
	},

		.polygon = {
			{ 0, -2 },
			{ 24, -8 },
			{ 24, -5 },
			{ 4, 0 },
			{ 32, 0 },
			{ 32, 14 },
			{ 20, 14 },
			{ 20, 11 },
			{ 0, 11 },
	},

	.up0 = {36, 1},		// x += 2; 3 times;

	.down0 = {36, 8},	// x += 2; 3 times;

			.info = {
				38, 36,
				38, 18, 12
			}
};

//-------------------------------------------------------
//                 LC
//-------------------------------------------------------
drawLc_t lcMirror;
const drawLc_t lcObj = {
	.color = {
		COLOR_PLUG_BODY3,
		COLOR_PLUG_BODY4,
		COLOR_PLUG_BODY3,
		COLOR_PLUG_BODY3,
		COLOR_PLUG_BODY3,
		COLOR_PLUG_BODY4,

		COLOR_PLUG_BODY3,
	},

	.rect = {
			/*
			{  9,  0, 32, 18 },    // edge
		{  0, 18, 32, 36 },    // body1
		{  4, 23,  7, 31 },    // body2
		{ 30, 18, 32, 36 },    // body3
		{ 32, 18, 60, 36 },    // body4
		{ 32, 22, 60, 32 },    // body5
*/
			/*
		{  3,  0, 11, 6 },    // edge
		{  0, 6, 11, 12 },    // body1
		{  1, 8,  2, 10 },    // body2
		{ 10, 6, 11, 12 },    // body3
		{ 11, 6, 20, 12 },    // body4
		{ 11, 8, 20, 10 },    // body5
		*/
		{  5,  0, 16, 9 },    // edge
		{  0, 9, 16, 18 },    // body1
		{  2, 12,  4, 16 },    // body2
		{ 15, 9, 16, 18 },    // body3
		{ 16, 9, 30, 18 },    // body4
		{ 16, 11, 30, 16 },    // body5
		},

		.screw = { 9, 14, 1 },

		.offY = 9,

			.info = {
				38, 36,
				38, 18, 12
			}
};







/*********************************************************************
*
*       Functions
*
**********************************************************************
*/

static void _MirrorRects(GUI_RECT*rect, int items){
	int tmp;

	for (int i = 0; i < items; i++){
		tmp = -rect[i].x0;
		rect[i].x0 = -rect[i].x1;
		rect[i].x1 = tmp;
	}
}

static void _MirrorPoints(GUI_POINT *point, int items){

	for (int i = 0; i < items; i++){
		point[i].x = -point[i].x;
	}
}

static void _MirrorScrews(plugScrew_t *screw, int items){

	for (int i = 0; i < items; i++){
		screw[i].orgin.x = -screw[i].orgin.x;
	}
}

static void _MirrorCircles(drawCircle_t *circle, int items){

	for (int i = 0; i < items; i++){
		circle[i].x = -circle[i].x;
	}
}



static void _DrawRectsAt(int x, int y, GUI_RECT *rect, GUI_COLOR *color, int items)
{
	// Drawing
	for (int item = 0; item < items; item++){
		GUI_SetColor(color[item]);
		GUI_FillRect(x + rect[item].x0, y + rect[item].y0,
			x + rect[item].x1, y + rect[item].y1);
	}
}

static void _DrawScrewAt(int x, int y, plugScrew_t *obj, GUI_COLOR color)
{
	int scale = obj->scale;

	x += obj->orgin.x;
	y += obj->orgin.y;

	GUI_SetColor(color);
	GUI_FillCircle(screwObj.x + x, screwObj.y + y, scale * screwObj.r);

	GUI_SetColor(COLOR_PLUG_CABLE);
	GUI_SetPenSize(1);
	//GUI_DrawCircle(screwObj.x + x, screwObj.y + y, scale * screwObj.r + 1);
	GUI_DrawCircle(x, y, scale * screwObj.r + 1);
	

	GUI_SetColor(GUI_WHITE);
	GUI_DrawLine(scale * screwObj.line1.x0 + x, scale * screwObj.line1.y0 + y,
		scale * screwObj.line1.x1 + x, scale * screwObj.line1.y1 + y);
	GUI_DrawLine(scale * screwObj.line2.x0 + x, scale * screwObj.line2.y0 + y,
		scale * screwObj.line2.x1 + x, scale * screwObj.line2.y1 + y);
}

/*-----------------------------------------------------------------
- @func    DrawObjInit
- @brief   MUST BE RUN before use drawing function
- @para    $params$
-          $params$
- @rtn     $type$
- @date    2019/4/24
-----------------------------------------------------------------*/
void DrawObjInit(void)
{
	// mirror DB
	GUI__memcpy(&dbMirror, &dbObj, sizeof(dbObj));
	_MirrorPoints(dbMirror.polygon, GUI_COUNTOF(dbMirror.polygon));
	_MirrorRects(dbMirror.rect, GUI_COUNTOF(dbMirror.rect));

	// mirror FGW
	GUI__memcpy(&fgwMirror, &fgwObj, sizeof(fgwObj));
	_MirrorRects(fgwMirror.rect, GUI_COUNTOF(fgwMirror.rect));
	_MirrorScrews(fgwMirror.screw, GUI_COUNTOF(fgwMirror.screw));

	// mirror HDB
	GUI__memcpy(&hdbMirror, &hdbObj, sizeof(hdbObj));
	_MirrorRects(hdbMirror.rect, GUI_COUNTOF(hdbMirror.rect));
	_MirrorScrews(hdbMirror.screw, GUI_COUNTOF(hdbMirror.screw));
	_MirrorPoints(hdbMirror.polygon, GUI_COUNTOF(hdbMirror.polygon));

	// mirror HC
	GUI__memcpy(&hcMirror, &hcObj, sizeof(hcObj));
	_MirrorRects(hcMirror.rect, GUI_COUNTOF(hcMirror.rect));
	_MirrorScrews(hcMirror.screw, GUI_COUNTOF(hcMirror.screw));
	_MirrorPoints(hcMirror.polygon, GUI_COUNTOF(hcMirror.polygon));

	// mirror HCR
	GUI__memcpy(&hcrMirror, &hcrObj, sizeof(hcrObj));
	_MirrorRects(hcrMirror.rect, GUI_COUNTOF(hcrMirror.rect));
	_MirrorScrews(hcrMirror.screw, GUI_COUNTOF(hcrMirror.screw));
	_MirrorPoints(hcrMirror.polygon, GUI_COUNTOF(hcrMirror.polygon));

	// mirror KT
	GUI__memcpy(&ktMirror, &ktObj, sizeof(ktObj));
	_MirrorRects(ktMirror.rect, GUI_COUNTOF(ktMirror.rect));
	_MirrorPoints(ktMirror.polygon, GUI_COUNTOF(ktMirror.polygon));

	// mirror ET
	GUI__memcpy(&etMirror, &etObj, sizeof(etObj));
	_MirrorRects(etMirror.rect, GUI_COUNTOF(etMirror.rect));

	// mirror OT
	GUI__memcpy(&otMirror, &otObj, sizeof(otObj));
	_MirrorRects(otMirror.rect, GUI_COUNTOF(otMirror.rect));
	_MirrorPoints(otMirror.polygon, GUI_COUNTOF(otMirror.polygon));
	_MirrorCircles(otMirror.circle, GUI_COUNTOF(otMirror.circle));

	// mirror USB
	GUI__memcpy(&usbMirror, &usbObj, sizeof(usbObj));
	_MirrorRects(usbMirror.rect, GUI_COUNTOF(usbMirror.rect));
	_MirrorPoints(usbMirror.polygon, GUI_COUNTOF(usbMirror.polygon));

	// mirror RJ45
	GUI__memcpy(&rj45Mirror, &rj45Obj, sizeof(rj45Obj));
	_MirrorRects(rj45Mirror.rect, GUI_COUNTOF(rj45Mirror.rect));
	_MirrorPoints(rj45Mirror.polygon, 2 + GUI_COUNTOF(rj45Mirror.polygon));

	// mirror LC
	GUI__memcpy(&lcMirror, &lcObj, sizeof(lcObj));
	_MirrorRects(lcMirror.rect, GUI_COUNTOF(lcMirror.rect));
	_MirrorScrews(&lcMirror.screw, 1);

}

/*-----------------------------------------------------------------
- @func    GetDbCablePos
- @brief   input origin position return CABLE position
- @para    cablePos: Cable position
-          orgX:     origin x position
-          orgY:     origin y position
- @rtn     void
- @date    2019/4/23
-----------------------------------------------------------------*/
void GetDbCablePos(GUI_POINT *cablePos, int orgX, int orgY)
{
	GUI_RECT *dbCable = &dbObj.rect[DB_CABLE];
	cablePos->x = dbCable->x1 + orgX;
	cablePos->y = dbCable->y0 + orgY;
}

/*-----------------------------------------------------------------
- @func    GetDbOrgPos
- @brief   input cable position then return ORIGIN postion
- @para    GUI_POINT *orgPos
-          int cableX, int cableY: cable positon X,Y
- @rtn     void
- @date    2019/4/23
-----------------------------------------------------------------*/
void GetDbOrgPos(GUI_POINT *orgPos, int cableX, int cableY)
{
	GUI_RECT *dbCable = &dbObj.rect[DB_CABLE];
	orgPos->x = cableX - dbCable->x1;
	orgPos->y = cableY - dbCable->y0;
}

/*-----------------------------------------------------------------
- @func    DrawPlugDb
- @brief   draw Plug Db from origin X,Y
- @para    int x : origin X
-          int y : origin Y
- @rtn     void
- @date    2018/4/23
-----------------------------------------------------------------*/
void _DrawPlugDb(int x, int y, drawDb_t *obj)
{
	GUI_SetColor(obj->color[DB_BODY]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// slot, lable, cable
	_DrawRectsAt(x, y, obj->rect, obj->color, DB_RECT);
}

/*-----------------------------------------------------------------
- @func    DrawPlugFgw
- @brief   Draw plug Fgw
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/4/24
-----------------------------------------------------------------*/
void _DrawPlugFgw(int x, int y, drawFgw_t *obj)
{
	// slot, body 1-5, cable
	_DrawRectsAt(x, y, obj->rect, obj->color, FGW_RECT);

	_DrawScrewAt(x, y, obj->screw, obj->color[FGW_SCREW1]);
	_DrawScrewAt(x, y, obj->screw + 1, obj->color[FGW_SCREW2]);
}

/*-----------------------------------------------------------------
- @func    DrawPlugHdb
- @brief   Draw plug Hdb
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugHdb(int x, int y, drawHdb_t *obj)
{
	// body
	GUI_SetColor(obj->color[HDB_BODY]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// slot, lable, cable
	_DrawRectsAt(x, y, obj->rect, obj->color, HDB_RECT);

	// screw
	_DrawScrewAt(x, y, obj->screw, obj->color[HDB_SCREW1]);
	_DrawScrewAt(x, y, obj->screw + 1, obj->color[HDB_SCREW2]);
}


/*-----------------------------------------------------------------
- @func    DrawPlugHc
- @brief   Draw plug Hc
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugHc(int x, int y, drawHc_t *obj)
{
	GUI_RECT *slot = &obj->rect[HC_SLOT];
	int x0 = x + slot->x0 + 1;
	int y0 = y + slot->y1;
	int x1 = x0 + 2;
	int y1 = y + slot->y0;

	// body
	GUI_SetColor(obj->color[HC_BODY2]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// slot, lable, cable
	_DrawRectsAt(x, y, obj->rect, obj->color, HC_RECT);

	// screw
	_DrawScrewAt(x, y, obj->screw, obj->color[HC_SCREW1]);
	_DrawScrewAt(x, y, obj->screw + 1, obj->color[HC_SCREW2]);

	// lines
	GUI_SetPenSize(1);
	GUI_SetColor(COLOR_PLUG_LABLE);
	if (slot->x0 > obj->rect[HC_CABLE].x0){
		// mirror mode
		y0 = y + slot->y0;
		y1 = y + slot->y1;
	}

	for (int i = 0; i < 4; i++){
		GUI_DrawLine(x0, y0, x1, y1);
		x0 += 2;
		x1 += 2;
	}
	
}

/*-----------------------------------------------------------------
- @func    DrawPlugHcr
- @brief   Draw plug Hcr
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugHcr(int x, int y, drawHcr_t *obj)
{
	GUI_RECT *slot = &obj->rect[HCR_BODY3];
	int x0 = x + slot->x0 + 1;
	int y0 = y + slot->y0;
	int x1 = x0;
	int y1 = y + slot->y1;

	// body1
	GUI_SetColor(obj->color[HCR_BODY1]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// cable, body2~4 
	_DrawRectsAt(x, y, obj->rect, obj->color, HCR_RECT);

	// screw
	_DrawScrewAt(x, y, obj->screw, obj->color[HCR_SCREW1]);
	_DrawScrewAt(x, y, obj->screw + 1, obj->color[HCR_SCREW2]);

	// lines
	GUI_SetPenSize(1);
	GUI_SetColor(COLOR_PLUG_LABLE);
	for (int i = 0; i < 14; i++){
		GUI_DrawLine(x0, y0, x1, y1);
		x0 += 2;
		x1 = x0;
	}
	
}


/*-----------------------------------------------------------------
- @func    DrawPlugKt
- @brief   Draw plug Kt
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugKt(int x, int y, drawKt_t *obj)
{
	// body
	GUI_SetColor(obj->color[KT_SLOT]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// cable
	_DrawRectsAt(x, y, obj->rect, obj->color, KT_RECT);
}


/*-----------------------------------------------------------------
- @func    DrawPlugEt
- @brief   Draw plug Et
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugEt(int x, int y, drawEt_t *obj)
{
	// cable, slot
	_DrawRectsAt(x, y, obj->rect, obj->color, ET_RECT);
}

/*-----------------------------------------------------------------
- @func    DrawPlugOt
- @brief   Draw plug Ot
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugOt(int x, int y, drawOt_t *obj)
{
	// body
	GUI_SetColor(obj->color[OT_SLOT1]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// cable
	_DrawRectsAt(x, y, obj->rect, obj->color, OT_RECT);

	// cicle
	for (int i = 0; i < GUI_COUNTOF(obj->circle); i++){
	GUI_SetColor(obj->color[OT_SLOT2 + i]);
	GUI_FillCircle(obj->circle[i].x + x, obj->circle[i].y + y, obj->circle[i].r);
	}
	
}


/*-----------------------------------------------------------------
- @func    DrawPlugUsb
- @brief   Draw plug Usb
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugUsb(int x, int y, drawUsb_t *obj)
{
	GUI_RECT *rect = &obj->rect[USB_BODY4];
	int x0 = x + rect->x0 + 1;
	int y0 = y + rect->y0;
	int x1 = x0;
	int y1 = y + rect->y1;

	// body1
	GUI_SetColor(obj->color[USB_BODY1]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// slot, body2~4, lable, cable 
	_DrawRectsAt(x, y, obj->rect, obj->color, USB_RECT);

	// lines
	GUI_SetPenSize(1);
	GUI_SetColor(COLOR_PLUG_CABLE);
	for (int i = rect->x0; i < rect->x1; i+=3){
		GUI_DrawLine(x0, y0, x1, y1);
		x0 += 2;
		x1 = x0;
	}

}

/*-----------------------------------------------------------------
- @func    DrawPlugRj45
- @brief   Draw plug Rj45
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugRj45(int x, int y, drawRj45_t *obj)
{
	int xUp = obj->up0.x + x;
	int yUp = obj->up0.y + y;
	int yDown = obj->down0.y + y;
	int xOff = 1 + 2 * (obj->rect[RJ45_BODY3].x1 - obj->rect[RJ45_BODY3].x0);

	if (obj->rect[RJ45_CABLE].x0 < obj->rect[RJ45_BODY2].x0)
		xOff = -xOff;

	// body1
	GUI_SetColor(obj->color[RJ45_BODY1]);
	GUI_FillPolygon(obj->polygon, GUI_COUNTOF(obj->polygon), x, y);

	// body2, cable 
	_DrawRectsAt(x, y, obj->rect, obj->color, RJ45_RECT - 1);

	// body3
	for (int i = 0; i < 3; i++){
		_DrawRectsAt(xUp, yUp, &obj->rect[RJ45_BODY3], &obj->color[RJ45_BODY3], 1);
		_DrawRectsAt(xUp, yDown, &obj->rect[RJ45_BODY3], &obj->color[RJ45_BODY3], 1);
		xUp += xOff;
	}
}


/*-----------------------------------------------------------------
- @func    DrawPlugLc
- @brief   Draw plug Lc
- @para    int x,y: orign X,Y
- @rtn	   void
- @date    2019/5/6
-----------------------------------------------------------------*/
void _DrawPlugLc(int x, int y, int pin, drawLc_t *obj)
{
	int yPos = 1;

	// body_edge, body1~5
	_DrawRectsAt(x, y, obj->rect, obj->color, 1);

	// pins
	for (int i = 0; i < pin; i++){
		_DrawRectsAt(x, y + yPos, obj->rect + 1, obj->color + 1, LC_RECT - 1);
		_DrawScrewAt(x, y + yPos, &obj->screw, obj->color[LC_SCREW]);
		yPos +=  obj->offY; 
	}

	// body_edege
	yPos +=  obj->offY + 1; 
	_DrawRectsAt(x, y + yPos, obj->rect, obj->color, 1);

}


