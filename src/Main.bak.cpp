// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
//
// ============================================================================

// Common Include
#include	"common.h"

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each condition
short conditionsInfos[1];//=
		//{
		//};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ACTION_SHOW,				M_ACTION_SHOW,				ACT_ACTION_SHOW, 				0, 0,
		IDMN_ACTION_HIDE,				M_ACTION_HIDE,				ACT_ACTION_HIDE,				0, 0,
		IDMN_ACTION_TRANS_ON,			M_ACTION_TRANS_ON,			ACT_ACTION_TRANS_ON,			0, 0,
		IDMN_ACTION_TRANS_OFF,			M_ACTION_TRANS_OFF,			ACT_ACTION_TRANS_OFF,			0, 0,
		IDMN_ACTION_LOAD_IMAGE,			M_ACTION_LOAD_IMAGE,		ACT_ACTION_LOAD_IMAGE,			0, 1, PARAM_FILENAME,	M_ACT_IMAGEFILE,
		IDMN_ACTION_SET_WIDTH,			M_ACTION_SET_WIDTH,			ACT_ACTION_SET_WIDTH,			0, 1, PARAM_EXPRESSION, 0,
		IDMN_ACTION_SET_HEIGHT,			M_ACTION_SET_HEIGHT,		ACT_ACTION_SET_HEIGHT,			0, 1, PARAM_EXPRESSION, 0,
		IDMN_ACTION_SET_TILT,			M_ACTION_SET_TILT,			ACT_ACTION_SET_TILT,			0, 1, PARAM_EXPRESSION, M_ACT_ANGLE,
		IDMN_ACTION_SET_ANGLE,			M_ACTION_SET_ANGLE,			ACT_ACTION_SET_ANGLE,			0, 1, PARAM_EXPRESSION, M_ACT_ANGLE,
		IDMN_ACTION_SET_ROLL,			M_ACTION_SET_ROLL,			ACT_ACTION_SET_ROLL,			0, 1, PARAM_EXPRESSION, M_ACT_ANGLE,
		IDMN_ACTION_SET_XOFFSET,		M_ACTION_SET_XOFFSET,		ACT_ACTION_SET_XOFFSET,			0, 1, PARAM_EXPRESSION, M_ACT_COORDINATE,
		IDMN_ACTION_SET_ELEVATION,		M_ACTION_SET_ELEVATION,		ACT_ACTION_SET_ELEVATION,		0, 1, PARAM_EXPRESSION, M_ACT_COORDINATE,
		IDMN_ACTION_SET_YOFFSET,		M_ACTION_SET_YOFFSET,		ACT_ACTION_SET_YOFFSET,			0, 1, PARAM_EXPRESSION, M_ACT_COORDINATE,
		IDMN_ACTION_SET_XCENTER,		M_ACTION_SET_XCENTER,		ACT_ACTION_SET_XCENTER,			0, 1, PARAM_EXPRESSION, 0,
		IDMN_ACTION_SET_YCENTER,		M_ACTION_SET_YCENTER,		ACT_ACTION_SET_YCENTER,			0, 1, PARAM_EXPRESSION, 0,
		IDMN_ACTION_SET_VANISH,			M_ACTION_SET_VANISH,		ACT_ACTION_SET_VANISH, 			0, 1, PARAM_EXPRESSION, 0,
		IDMN_ACTION_SET_ZOOM,			M_ACTION_SET_ZOOM,			ACT_ACTION_SET_ZOOM, 			0, 1, PARAM_EXPRESSION, M_ACT_PERCENT,
		IDMN_ACTION_REDRAW,				M_ACTION_REDRAW,			ACT_ACTION_REDRAW, 				0, 0,
		IDMN_ACTION_ADJUST_ANGLE,		M_ACTION_ADJUST_ANGLE,		ACT_ACTION_ADJUST_ANGLE, 		0, 1, PARAM_EXPRESSION, M_ACT_AANGLE,
		IDMN_ACTION_ADJUST_XOFFSET,		M_ACTION_ADJUST_XOFFSET,	ACT_ACTION_ADJUST_XOFFSET, 		0, 1, PARAM_EXPRESSION, M_ACT_ACOORDINATE,
		IDMN_ACTION_ADJUST_YOFFSET,		M_ACTION_ADJUST_YOFFSET,	ACT_ACTION_ADJUST_YOFFSET,		0, 1, PARAM_EXPRESSION, M_ACT_ACOORDINATE,
		IDMN_ACTION_ADJUST_ELEVATION,	M_ACTION_ADJUST_ELEVATION,	ACT_ACTION_ADJUST_ELEVATION,	0, 1, PARAM_EXPRESSION, M_ACT_ACOORDINATE,
		IDMN_ACTION_WALK_FORWARD,		M_ACTION_WALK_FORWARD,		ACT_ACTION_WALK_FORWARD, 		0, 1, PARAM_EXPRESSION, M_ACT_DISTANCE,
		IDMN_ACTION_WALK_BACK,			M_ACTION_WALK_BACK,			ACT_ACTION_WALK_BACK, 			0, 1, PARAM_EXPRESSION, M_ACT_DISTANCE,
		IDMN_ACTION_WALK_LEFT,			M_ACTION_WALK_LEFT,			ACT_ACTION_WALK_LEFT, 			0, 1, PARAM_EXPRESSION, M_ACT_DISTANCE,
		IDMN_ACTION_WALK_RIGHT,			M_ACTION_WALK_RIGHT,		ACT_ACTION_WALK_RIGHT,			0, 1, PARAM_EXPRESSION, M_ACT_DISTANCE,
		IDMN_ACTION_WRAPX_ON,			M_ACTION_WRAPX_ON,			ACT_ACTION_WRAPX_ON, 			0, 0,
		IDMN_ACTION_WRAPX_OFF,			M_ACTION_WRAPX_OFF,			ACT_ACTION_WRAPX_OFF, 			0, 0,
		IDMN_ACTION_WRAPY_ON,			M_ACTION_WRAPY_ON,			ACT_ACTION_WRAPY_ON, 			0, 0,
		IDMN_ACTION_WRAPY_OFF,			M_ACTION_WRAPY_OFF,			ACT_ACTION_WRAPY_OFF, 			0, 0,
		IDMN_ACTION_SET_RES,			M_ACTION_SET_RES,			ACT_ACTION_SET_RES, 			0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACT_RESX, M_ACT_RESY,
		IDMN_ACTION_SET_RESMODE,		M_ACTION_SET_RESMODE,		ACT_ACTION_SET_RESMODE, 		0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACT_RESMODE, M_ACT_RESMODE2,
		IDMN_ACTION_SET_THICK,			M_ACTION_SET_THICK,			ACT_ACTION_SET_THICK, 			0, 1, PARAM_EXPRESSION, M_ACT_THICK,
		IDMN_ACTION_ADJUST_TILT,		M_ACTION_ADJUST_TILT,		ACT_ACTION_ADJUST_TILT, 		0, 1, PARAM_EXPRESSION, M_ACT_AANGLE,
		IDMN_ACTION_ADJUST_ROLL,		M_ACTION_ADJUST_ROLL,		ACT_ACTION_ADJUST_ROLL, 		0, 1, PARAM_EXPRESSION, M_ACT_AANGLE,
		IDMN_ACTION_SET_XRES,			M_ACTION_SET_XRES,			ACT_ACTION_SET_XRES, 			0, 1, PARAM_EXPRESSION, M_ACT_RESX,
		IDMN_ACTION_SET_YRES,			M_ACTION_SET_YRES,			ACT_ACTION_SET_YRES, 			0, 1, PARAM_EXPRESSION, M_ACT_RESY,
		IDMN_ACTION_LOAD_IMAGENUM,		M_ACTION_LOAD_IMAGENUM,		ACT_ACTION_LOAD_IMAGENUM, 		0, 1, PARAM_EXPRESSION, M_ACT_IMAGEID,
		IDMN_ACTION_LOAD_IMAGENAME,		M_ACTION_LOAD_IMAGENAME,	ACT_ACTION_LOAD_IMAGENAME, 		0, 1, PARAM_EXPSTRING,  M_ACT_IMAGENAME,
		IDMN_ACTION_LOAD_IMAGE2,		M_ACTION_LOAD_IMAGE2,		ACT_ACTION_LOAD_IMAGE2, 		0, 1, PARAM_FILENAME,   M_ACT_IMAGEFILE,
		IDMN_ACTION_LOAD_IMAGE2NUM,		M_ACTION_LOAD_IMAGE2NUM,	ACT_ACTION_LOAD_IMAGE2NUM, 		0, 1, PARAM_EXPRESSION, M_ACT_IMAGEID,
		IDMN_ACTION_LOAD_IMAGE2NAME,	M_ACTION_LOAD_IMAGE2NAME,	ACT_ACTION_LOAD_IMAGE2NAME, 	0, 1, PARAM_EXPSTRING,  M_ACT_IMAGENAME,
		IDMN_ACTION_LOAD_IMAGEH,		M_ACTION_LOAD_IMAGEH,		ACT_ACTION_LOAD_IMAGEH, 		0, 1, PARAM_FILENAME,   M_ACT_IMAGEFILE,
		IDMN_ACTION_LOAD_IMAGEHNUM,		M_ACTION_LOAD_IMAGEHNUM,	ACT_ACTION_LOAD_IMAGEHNUM, 		0, 1, PARAM_EXPRESSION, M_ACT_IMAGEID,
		IDMN_ACTION_LOAD_IMAGEHNAME,	M_ACTION_LOAD_IMAGEHNAME,	ACT_ACTION_LOAD_IMAGEHNAME, 	0, 1, PARAM_EXPSTRING,  M_ACT_IMAGENAME,
		IDMN_ACTION_UNLOAD_IMAGE2,		M_ACTION_UNLOAD_IMAGE2,		ACT_ACTION_UNLOAD_IMAGE2,		0, 0,
		IDMN_ACTION_UNLOAD_IMAGEH,		M_ACTION_UNLOAD_IMAGEH,		ACT_ACTION_UNLOAD_IMAGEH,		0, 0,
		IDMN_ACTION_FOG_ON,				M_ACTION_FOG_ON,			ACT_ACTION_FOG_ON,				0, 0,
		IDMN_ACTION_FOG_OFF,			M_ACTION_FOG_OFF,			ACT_ACTION_FOG_OFF,				0, 0,
		IDMN_ACTION_CHOOSEFOGCOLOR,		M_ACTION_CHOOSEFOGCOLOR,	ACT_ACTION_CHOOSEFOGCOLOR,		0, 1, PARAM_COLOUR,  M_ACT_FOGCOLOR,
		IDMN_ACTION_SETFOGCOLOR,		M_ACTION_SETFOGCOLOR,		ACT_ACTION_SETFOGCOLOR,			0, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACT_RED, M_ACT_GREEN, M_ACT_BLUE,
		IDMN_ACTION_SETFOGRED,			M_ACTION_SETFOGRED,			ACT_ACTION_SETFOGRED,			0, 1, PARAM_EXPRESSION,  M_ACT_RED,
		IDMN_ACTION_SETFOGGREEN,		M_ACTION_SETFOGGREEN,		ACT_ACTION_SETFOGGREEN,			0, 1, PARAM_EXPRESSION,  M_ACT_GREEN,
		IDMN_ACTION_SETFOGBLUE,			M_ACTION_SETFOGBLUE,		ACT_ACTION_SETFOGBLUE,			0, 1, PARAM_EXPRESSION,  M_ACT_BLUE,
		IDMN_ACTION_SETFOGDISTANCE,		M_ACTION_SETFOGDISTANCE,	ACT_ACTION_SETFOGDISTANCE,		0, 1, PARAM_EXPRESSION,  M_ACT_FOGDISTANCE,
		IDMN_ACTION_SET_XOFFSET2,		M_ACTION_SET_XOFFSET2,		ACT_ACTION_SET_XOFFSET,			0, 1, PARAM_EXPRESSION, M_ACT_COORDINATE,
		IDMN_ACTION_SET_YOFFSET2,		M_ACTION_SET_YOFFSET2,		ACT_ACTION_SET_YOFFSET,			0, 1, PARAM_EXPRESSION, M_ACT_COORDINATE,
		IDMN_ACTION_ADJUST_XOFFSET2,	M_ACTION_ADJUST_XOFFSET2,	ACT_ACTION_ADJUST_XOFFSET2, 	0, 1, PARAM_EXPRESSION, M_ACT_ACOORDINATE,
		IDMN_ACTION_ADJUST_YOFFSET2,	M_ACTION_ADJUST_YOFFSET2,	ACT_ACTION_ADJUST_YOFFSET2,		0, 1, PARAM_EXPRESSION, M_ACT_ACOORDINATE,
		IDMN_ACTION_ADJUST_ANGLE2,		M_ACTION_ADJUST_ANGLE2,		ACT_ACTION_ADJUST_ANGLE2, 		0, 1, PARAM_EXPRESSION, M_ACT_AANGLE,
		IDMN_ACTION_SET_THICKNESSMODE,	M_ACTION_SET_THICKNESSMODE,	ACT_ACTION_SET_THICKNESSMODE, 	0, 1, PARAM_EXPRESSION, M_ACT_THICKNESSMODE,
		IDMN_ACTION_INTERPOL_ON,		M_ACTION_INTERPOL_ON,		ACT_ACTION_INTERPOL_ON,			0, 0,
		IDMN_ACTION_INTERPOL_OFF,		M_ACTION_INTERPOL_OFF,		ACT_ACTION_INTERPOL_OFF,		0, 0,
		IDMN_ACTION_HINTERPOL_ON,		M_ACTION_HINTERPOL_ON,		ACT_ACTION_HINTERPOL_ON,		0, 0,
		IDMN_ACTION_HINTERPOL_OFF,		M_ACTION_HINTERPOL_OFF,		ACT_ACTION_HINTERPOL_OFF,		0, 0,
		IDMN_ACTION_MIPMAP_ON,			M_ACTION_MIPMAP_ON,			ACT_ACTION_MIPMAP_ON,			0, 0,
		IDMN_ACTION_MIPMAP_OFF,			M_ACTION_MIPMAP_OFF,		ACT_ACTION_MIPMAP_OFF,			0, 0,
		IDMN_ACTION_MIPMAP2_ON,			M_ACTION_MIPMAP2_ON,		ACT_ACTION_MIPMAP2_ON,			0, 0,
		IDMN_ACTION_MIPMAP2_OFF,		M_ACTION_MIPMAP2_OFF,		ACT_ACTION_MIPMAP2_OFF,			0, 0,
		IDMN_ACTION_MIPMAPH_ON,			M_ACTION_MIPMAPH_ON,		ACT_ACTION_MIPMAPH_ON,			0, 0,
		IDMN_ACTION_MIPMAPH_OFF,		M_ACTION_MIPMAPH_OFF,		ACT_ACTION_MIPMAPH_OFF,			0, 0,
		IDMN_ACTION_AUTOREDRAW_ON,		M_ACTION_AUTOREDRAW_ON ,	ACT_ACTION_AUTOREDRAW_ON,		0, 0,
		IDMN_ACTION_AUTOREDRAW_OFF,		M_ACTION_AUTOREDRAW_OFF,	ACT_ACTION_AUTOREDRAW_OFF,		0, 0,
		IDMN_ACTION_MIPMAP_TRANS,		M_ACTION_MIPMAP_TRANS,		ACT_ACTION_MIPMAP_TRANS,		0, 1, PARAM_COLOUR,  M_ACT_MIPTRANSCOLOR,
		IDMN_ACTION_MIPMAP_TRANS_OFF,	M_ACTION_MIPMAP_TRANS_OFF,	ACT_ACTION_MIPMAP_TRANS_OFF,	0, 0,
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_EXP_GET_WIDTH,				M_EXP_GET_WIDTH,			EXP_GET_WIDTH, 				0, 0,
		IDMN_EXP_GET_HEIGHT,			M_EXP_GET_HEIGHT,			EXP_GET_HEIGHT, 			0, 0,
		IDMN_EXP_GET_IMAGE_WIDTH,		M_EXP_GET_IMAGE_WIDTH,		EXP_GET_IMAGE_WIDTH, 		0, 0,
		IDMN_EXP_GET_IMAGE_HEIGHT,		M_EXP_GET_IMAGE_HEIGHT,		EXP_GET_IMAGE_HEIGHT, 		0, 0,
		IDMN_EXP_GET_FILE,				M_EXP_GET_FILE,				EXP_GET_FILE, 				EXPFLAG_STRING, 0,
		IDMN_EXP_GET_TRANS,				M_EXP_GET_TRANS,			EXP_GET_TRANS, 				0, 0,
		IDMN_EXP_GET_SHOW,				M_EXP_GET_SHOW,				EXP_GET_SHOW, 				0, 0,
		IDMN_EXP_GET_TILT,				M_EXP_GET_TILT,				EXP_GET_TILT, 				0, 0,
		IDMN_EXP_GET_ANGLE,				M_EXP_GET_ANGLE,			EXP_GET_ANGLE, 				0, 0,
		IDMN_EXP_GET_ROLL,				M_EXP_GET_ROLL,				EXP_GET_ROLL, 				0, 0,
		IDMN_EXP_GET_XOFFSET,			M_EXP_GET_XOFFSET,			EXP_GET_XOFFSET, 			0, 0,
		IDMN_EXP_GET_ELEVATION,			M_EXP_GET_ELEVATION,		EXP_GET_ELEVATION, 			0, 0,
		IDMN_EXP_GET_YOFFSET,			M_EXP_GET_YOFFSET,			EXP_GET_YOFFSET, 			0, 0,
		IDMN_EXP_GET_XCENTER,			M_EXP_GET_XCENTER,			EXP_GET_XCENTER, 			0, 0,
		IDMN_EXP_GET_YCENTER,			M_EXP_GET_YCENTER,			EXP_GET_YCENTER, 			0, 0,
		IDMN_EXP_GET_VANISH,			M_EXP_GET_VANISH,			EXP_GET_VANISH, 			0, 0,
		IDMN_EXP_GET_ZOOM,				M_EXP_GET_ZOOM,				EXP_GET_ZOOM, 				0, 0,
		IDMN_EXP_GET_WRAPX,				M_EXP_GET_WRAPX,			EXP_GET_WRAPX, 				0, 0,
		IDMN_EXP_GET_WRAPY,				M_EXP_GET_WRAPY,			EXP_GET_WRAPY, 				0, 0,
		IDMN_EXP_GET_MAPX,				M_EXP_GET_MAPX,				EXP_GET_MAPX, 				0, 2, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY,
		IDMN_EXP_GET_MAPY,				M_EXP_GET_MAPY,				EXP_GET_MAPY, 				0, 2, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY,
		IDMN_EXP_GET_MAPXZ,				M_EXP_GET_MAPXZ,			EXP_GET_MAPXZ, 				0, 3, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SZ,
		IDMN_EXP_GET_MAPYZ,				M_EXP_GET_MAPYZ,			EXP_GET_MAPYZ, 				0, 3, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SZ,
		IDMN_EXP_GET_MAPWIDTH,			M_EXP_GET_MAPWIDTH,			EXP_GET_MAPWIDTH, 			0, 4, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SWIDTH, M_ACT_SHEIGHT,
		IDMN_EXP_GET_MAPHEIGHT,			M_EXP_GET_MAPHEIGHT,		EXP_GET_MAPHEIGHT,	 		0, 4, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SWIDTH, M_ACT_SHEIGHT,
		IDMN_EXP_GET_MAPWIDTHZ,			M_EXP_GET_MAPWIDTHZ,		EXP_GET_MAPWIDTHZ, 			0, 5, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SZ, M_ACT_SWIDTH, M_ACT_SHEIGHT,
		IDMN_EXP_GET_MAPHEIGHTZ,		M_EXP_GET_MAPHEIGHTZ,		EXP_GET_MAPHEIGHTZ, 		0, 4, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SZ, M_ACT_SHEIGHT,
		IDMN_EXP_GET_MAPANGLE,			M_EXP_GET_MAPANGLE,			EXP_GET_MAPANGLE, 			0, 3, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SANGLE,
		IDMN_EXP_GET_MAPVISIBLE,		M_EXP_GET_MAPVISIBLE,		EXP_GET_MAPVISIBLE, 		0, 4, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY, M_ACT_SWIDTH, M_ACT_SHEIGHT,
		IDMN_EXP_GET_RESX,				M_EXP_GET_RESX,				EXP_GET_RESX,	 			0, 0,
		IDMN_EXP_GET_RESY,				M_EXP_GET_RESY,				EXP_GET_RESY,	 			0, 0,
		IDMN_EXP_GET_RESMODE,			M_EXP_GET_RESMODE,			EXP_GET_RESMODE,			0, 0,
		IDMN_EXP_GET_RESMODEPARAM,		M_EXP_GET_RESMODEPARAM,		EXP_GET_RESMODEPARAM,		0, 0,
		IDMN_EXP_GET_THICK,				M_EXP_GET_THICK,			EXP_GET_THICK, 				0, 0,
		IDMN_EXP_GET_IMAGE_NUM,			M_EXP_GET_IMAGE_NUM,		EXP_GET_IMAGE_NUM, 			0, 0,
		IDMN_EXP_GET_IMAGE2_WIDTH,		M_EXP_GET_IMAGE2_WIDTH,		EXP_GET_IMAGE2_WIDTH, 		0, 0,
		IDMN_EXP_GET_IMAGE2_HEIGHT,		M_EXP_GET_IMAGE2_HEIGHT,	EXP_GET_IMAGE2_HEIGHT, 		0, 0,
		IDMN_EXP_GET_IMAGE2_NUM,		M_EXP_GET_IMAGE2_NUM,		EXP_GET_IMAGE2_NUM, 		0, 0,
		IDMN_EXP_GET_IMAGE2_FILE,		M_EXP_GET_IMAGE2_FILE,		EXP_GET_IMAGE2_FILE, 		EXPFLAG_STRING, 0,
		IDMN_EXP_GET_IMAGEH_WIDTH,		M_EXP_GET_IMAGEH_WIDTH,		EXP_GET_IMAGEH_WIDTH, 		0, 0,
		IDMN_EXP_GET_IMAGEH_HEIGHT,		M_EXP_GET_IMAGEH_HEIGHT,	EXP_GET_IMAGEH_HEIGHT, 		0, 0,
		IDMN_EXP_GET_IMAGEH_NUM,		M_EXP_GET_IMAGEH_NUM,		EXP_GET_IMAGEH_NUM, 		0, 0,
		IDMN_EXP_GET_IMAGEH_FILE,		M_EXP_GET_IMAGEH_FILE,		EXP_GET_IMAGEH_FILE, 		EXPFLAG_STRING, 0,
		IDMN_EXP_GET_IMAGE_HEIGHT_AT,	M_EXP_GET_IMAGE_HEIGHT_AT,	EXP_GET_IMAGE_HEIGHT_AT, 	0, 2, EXPPARAM_LONG, EXPPARAM_LONG, M_ACT_SX, M_ACT_SY,
		IDMN_EXP_GET_FOG,				M_EXP_GET_FOG,				EXP_GET_FOG, 				0, 0,
		IDMN_EXP_GET_FOGRED,			M_EXP_GET_FOGRED,			EXP_GET_FOGRED, 			0, 0,
		IDMN_EXP_GET_FOGGREEN,			M_EXP_GET_FOGGREEN,			EXP_GET_FOGGREEN, 			0, 0,
		IDMN_EXP_GET_FOGBLUE,			M_EXP_GET_FOGBLUE,			EXP_GET_FOGBLUE, 			0, 0,
		IDMN_EXP_GET_FOGDISTANCE,		M_EXP_GET_FOGDISTANCE,		EXP_GET_FOGDISTANCE, 		0, 0,
		IDMN_EXP_GET_XOFFSET2,			M_EXP_GET_XOFFSET2,			EXP_GET_XOFFSET2, 			0, 0,
		IDMN_EXP_GET_YOFFSET2,			M_EXP_GET_YOFFSET2,			EXP_GET_YOFFSET2, 			0, 0,
		IDMN_EXP_GET_ANGLE2,			M_EXP_GET_ANGLE2,			EXP_GET_ANGLE2, 			0, 0,
		IDMN_EXP_GET_THICKNESSMODE,		M_EXP_GET_THICKNESSMODE,	EXP_GET_THICKNESSMODE, 		0, 0,
		IDMN_EXP_GET_INTERPOL,			M_EXP_GET_INTERPOL,			EXP_GET_INTERPOL, 			0, 0,
		IDMN_EXP_GET_HINTERPOL,			M_EXP_GET_HINTERPOL,		EXP_GET_HINTERPOL, 			0, 0,
		IDMN_EXP_GET_MIPMAP,			M_EXP_GET_MIPMAP,			EXP_GET_MIPMAP, 			0, 0,
		IDMN_EXP_GET_MIPMAP2,			M_EXP_GET_MIPMAP2,			EXP_GET_MIPMAP2, 			0, 0,
		IDMN_EXP_GET_MIPMAPH,			M_EXP_GET_MIPMAPH,			EXP_GET_MIPMAPH, 			0, 0,
		IDMN_EXP_GET_AUTOREDRAW,		M_EXP_GET_AUTOREDRAW,		EXP_GET_AUTOREDRAW, 		0, 0,
		};

char emptyString[] = "";


// ============================================================================
//
// User function and macros
//
// ============================================================================

#define MOD(x,y)  ((x)-(y)*(int)((x) / (y)))
#define MOD1(x,y)  (((x%y)+y)%y)
#define MOD2(x,y)  MOD((MOD(x,y)+y),y)

int transparency(int color2, int color1, int blend) {
	if (blend<=0) return color2;
	if (blend>=255) return color1;

	return	(((blend*(((color1>>16)&255)-((color2>>16)&255))>>8)+((color2>>16)&255))<<16) |
			(((blend*(((color1>>8)&255)-((color2>>8)&255))>>8)+((color2>>8)&255))<<8) |
			 ((blend*((color1&255)-(color2&255))>>8)+(color2&255));
}
int transparency2(int color2, int color1, int blend) {
	if (blend<=0) return color2;
	if (blend>=255) return color1;
	if (!color2) return color1;
	if (!color1) return color2;

	return	(((blend*(((color1>>16)&255)-((color2>>16)&255))>>8)+((color2>>16)&255))<<16) |
			(((blend*(((color1>>8)&255)-((color2>>8)&255))>>8)+((color2>>8)&255))<<8) |
			 ((blend*((color1&255)-(color2&255))>>8)+(color2&255));
}
int transparency256(BYTE color2, BYTE color1, BYTE blend) {
	if (blend<=0) return color2;
	if (blend>=255) return color1;
	return (blend*((color1)-(color2))>>8)+(color2);
}
int getPixel(LPSURFACE surface, float x, float y) {
	int xi=(int)x;
	int yi=(int)y;
	float xf=x-xi;
	float yf=y-yi;
	if (xf==0&&yf==0) {
		COLORREF tempColor=0; surface->GetPixel(xi,yi,tempColor);
		return tempColor;
	}
	int xp=0, yp=0, c1=0, c2=0, c3=0, c4=0, c12, c34;
	if (xf!=0) {
		xp=(int)(xf*0xFF);
		surface->GetPixel(xi,  yi,c1);
		surface->GetPixel(xi+1,yi,c2);
		c12=transparency(c1, c2, xp);
	} else surface->GetPixel(xi,yi,c12);
	if (yf!=0) {
		yp=(int)(yf*0xFF);
		surface->GetPixel(xi,yi++,c3);
		surface->GetPixel(xi+1,yi,c4);
		c34=transparency(c3, c4, xp);
	} else return c12;
	return transparency(c12, c34, yp);
}
int getPixel2(LPSURFACE surface, int width, int height, bool repeatx, bool repeaty, float x, float y) {
	int xi=(int)x;
	int yi=(int)y;
	float xf=x-xi;
	float yf=y-yi;
	if (xf==0&&yf==0) {
		COLORREF tempColor=0; surface->GetPixel(xi,yi,tempColor);
		return tempColor;
	}
	int xp=0, yp=0, c1=0, c2=0, c3=0, c4=0, c12, c34;
	int xi1=repeatx?MOD1(xi+1,width):min(xi+1,width);
	if (xf!=0) {
		xp=(int)(xf*0xFF);
		surface->GetPixel(xi, yi,c1);
		surface->GetPixel(xi1,yi,c2);
		c12=transparency2(c1, c2, xp);
	} else surface->GetPixel(xi,yi,c12);
	int yi1=repeaty?MOD1(yi+1,height):min(yi+1,height);
	if (yf!=0) {
		yp=(int)(yf*0xFF);
		surface->GetPixel(xi, yi1,c3);
		surface->GetPixel(xi1,yi1,c4);
		c34=transparency2(c3, c4, xp);
	} else return c12;
	return transparency2(c12, c34, yp);
}
BYTE getPixel256(LPSURFACE surface, int width, int height, bool repeatx, bool repeaty, float x, float y) {
	int xi=(int)x;
	int yi=(int)y;
	float xf=x-xi;
	float yf=y-yi;
	if (xf==0&&yf==0) {
		COLORREF tempColor=0; surface->GetPixel(xi,yi,tempColor);
		return GetRValue(tempColor);
	}
	int xp=0, yp=0, c1=0, c2=0, c3=0, c4=0, c12, c34;
	int xi1=repeatx?MOD1(xi+1,width):min(xi+1,width);
	if (xf!=0) {
		xp=(int)(xf*0xFF);
		surface->GetPixel(xi, yi,c1);
		surface->GetPixel(xi1,yi,c2);
		c1=GetRValue(c1);
		c2=GetRValue(c2);
		c12=transparency256(c1, c2, xp);
	} else surface->GetPixel(xi,yi,c12);
	int yi1=repeaty?MOD1(yi+1,height):min(yi+1,height);
	if (yf!=0) {
		yp=(int)(yf*0xFF);
		surface->GetPixel(xi, yi1,c3);
		surface->GetPixel(xi1,yi1,c4);
		c3=GetRValue(c3);
		c4=GetRValue(c4);
		c34=transparency256(c3, c4, xp);
	} else return c12;
	return transparency256(c12, c34, yp);
}
#define SETPIX(x,y,c)	(rdPtr->rResMode2?setPixel(rdPtr,x,y,c):rdPtr->rSf->SetPixel(x,y,c))
void setPixel(LPRDATA rdPtr, int x, int y, COLORREF color) {
	if (rdPtr->rElevation>=0) y--;
	//else y++;
	if (x<0||y<0) return;
	if (x>=rdPtr->rHo.hoImgWidth) return;
	if (y>=rdPtr->rHo.hoImgHeight) return;
	if (rdPtr->rResMode2==0) { rdPtr->rSf->SetPixel(x,y,color); return; }
	int xx,yy;
	if (rdPtr->rResMode2==1) {
		for (yy=min(rdPtr->rResY+y,rdPtr->rHo.hoImgHeight); --yy>=y;)
			for (xx=min(rdPtr->rResX+x,rdPtr->rHo.hoImgWidth); --xx>=x;)
				rdPtr->rSf->SetPixel(xx,yy,color);
		return;
	}
	if (rdPtr->rResMode2==2) {
		for (xx=min(rdPtr->rResX+x,rdPtr->rHo.hoImgWidth); --xx>=x;)
			rdPtr->rSf->SetPixel(xx,y,color);
		return;
	}
	for (xx=min(rdPtr->rResX+x,rdPtr->rHo.hoImgWidth); --xx>=x;)
		rdPtr->rSf->SetPixel(xx,y,color);
	// No need to draw extra lines if res is low
	if (rdPtr->rResY==1) return;
	y++;
	color = transparency(color,0,rdPtr->rResModeParam);
	for (xx=min(rdPtr->rResX+x,rdPtr->rHo.hoImgWidth); --xx>=x;)
		rdPtr->rSf->SetPixel(xx,y,color);
}
void UpdateMipMaps(LPRDATA rdPtr) {
	if (rdPtr->rMipmap) {
		int ow=rdPtr->rImageWidth,oh=rdPtr->rImageHeight;
		rdPtr->rNMipLevels=0;
		for (int i=0; i<12; i++)
			if (1<<i>ow || 1<<i>oh) {
				rdPtr->rNMipLevels=i;
				break;
			}

		int ml=rdPtr->rNMipLevels=min(max(rdPtr->rNMipLevels,0),12);
		int w=0,h=0;
		if (ml) {
			if (rdPtr->rMipTrans) {
				rdPtr->rImage->BeginRaster();
				rdPtr->rImage->ReplaceColor(rdPtr->rMipTrans,0);
				rdPtr->rImage->EndRaster();
			}
			HDC srcdc = rdPtr->rImage->GetDC();
			SetStretchBltMode(srcdc,HALFTONE);
			SetBrushOrgEx(srcdc,0,0,NULL);
			for (int i=ml; --i>=0;) {
				w=1<<i;
				h=1<<i;
				if (rdPtr->rMipmaps[i]!=NULL) {
					if (rdPtr->rMipmaps[i]->GetWidth()!=w || rdPtr->rMipmaps[i]->GetHeight()!=h)
						rdPtr->rMipmaps[i]->Create(w,h,rdPtr->rImage);
					HDC dstdc = rdPtr->rMipmaps[i]->GetDC();
					SetStretchBltMode(dstdc,HALFTONE);
					SetBrushOrgEx(srcdc,0,0,NULL);
					StretchBlt(dstdc, 0, 0, w, h, srcdc, 0 , 0, ow, oh, SRCCOPY);
					rdPtr->rMipmaps[i]->ReleaseDC(dstdc);
					if (rdPtr->rMipTrans) {
						rdPtr->rMipmaps[i]->BeginRaster();
						rdPtr->rMipmaps[i]->ReplaceColor(0,rdPtr->rMipTrans2);
						/*if (i==ml-2) {
							char text[128];
							int c = 0, c2 = 0;
							{
								LPSURFACE dsf = new cSurface;
								dsf->Create(4,4,rdPtr->rImage);
								dsf->Fill(rdPtr->rMipTrans);
								HDC ddc = dsf->GetDC();
								SetStretchBltMode(ddc,HALFTONE);
								SetBrushOrgEx(ddc,0,0,NULL);
								StretchBlt(ddc, 0, 0, 1, 1, ddc, 1, 0, 3, 4, SRCCOPY);
								dsf->GetPixel(0,0,c2);
								dsf->ReleaseDC(ddc);
								delete dsf;
							}
							rdPtr->rMipmaps[i]->GetPixel(0,0,c);
							sprintf(text,"trans color(%i,%i,%i) color@0,0:(%i,%i,%i) color2(%i,%i,%i)",GetRValue(rdPtr->rMipTrans),GetGValue(rdPtr->rMipTrans),GetBValue(rdPtr->rMipTrans),GetRValue(c),GetGValue(c),GetBValue(c),GetRValue(c2),GetGValue(c2),GetBValue(c2));
							MessageBox(0,text,"mode 7 debug",MB_OK);
						}*/
						rdPtr->rMipmaps[i]->EndRaster();
					}

				}
			}
			rdPtr->rImage->ReleaseDC(srcdc);
			if (rdPtr->rMipTrans) {
				rdPtr->rImage->BeginRaster();
				rdPtr->rImage->ReplaceColor(0,rdPtr->rMipTrans);
				rdPtr->rImage->EndRaster();
			}
		}
	}
}
void UpdateMipMaps2(LPRDATA rdPtr) {
	if (rdPtr->rMipmap2) {
		int ow=rdPtr->rImage2Width,oh=rdPtr->rImage2Height;
		rdPtr->rNMipLevels2=0;
		for (int i=0; i<12; i++)
			if (1<<i>ow || 1<<i>oh) {
				rdPtr->rNMipLevels2=i;
				break;
			}

		int ml=rdPtr->rNMipLevels2=min(max(rdPtr->rNMipLevels2,0),12);
		int w=0,h=0;
		if (ml) {
			HDC srcdc = rdPtr->rImage2->GetDC();
			SetStretchBltMode(srcdc,HALFTONE);
			SetBrushOrgEx(srcdc,0,0,NULL);
			for (int i=ml; --i>=0;) {
				w=1<<i;
				h=1<<i;
				if (rdPtr->rMipmaps2[i]!=NULL) {
					if (rdPtr->rMipmaps2[i]->GetWidth()!=w || rdPtr->rMipmaps2[i]->GetHeight()!=h)
						rdPtr->rMipmaps2[i]->Create(w,h,rdPtr->rImage2);
					HDC dstdc = rdPtr->rMipmaps2[i]->GetDC();
					SetStretchBltMode(dstdc,HALFTONE);
					SetBrushOrgEx(srcdc,0,0,NULL);
					StretchBlt(dstdc, 0, 0, w, h, srcdc, 0 , 0, ow, oh, SRCCOPY);
					rdPtr->rMipmaps2[i]->ReleaseDC(dstdc);

				}
			}
			rdPtr->rImage2->ReleaseDC(srcdc);
		}
	}
}
void UpdateMipMapsH(LPRDATA rdPtr) {
	if (rdPtr->rMipmapH) {
		int ow=rdPtr->rImageHWidth,oh=rdPtr->rImageHHeight;
		rdPtr->rNMipLevelsH=0;
		for (int i=0; i<12; i++)
			if (1<<i>ow || 1<<i>oh) {
				rdPtr->rNMipLevelsH=i;
				break;
			}

		int ml=rdPtr->rNMipLevelsH=min(max(rdPtr->rNMipLevelsH,0),12);
		int w=0,h=0;
		if (ml) {
			HDC srcdc = rdPtr->rImageH->GetDC();
			SetStretchBltMode(srcdc,HALFTONE);
			SetBrushOrgEx(srcdc,0,0,NULL);
			for (int i=ml; --i>=0;) {
				w=1<<i;
				h=1<<i;
				if (rdPtr->rMipmapsH[i]!=NULL) {
					if (rdPtr->rMipmapsH[i]->GetWidth()!=w || rdPtr->rMipmapsH[i]->GetHeight()!=h)
						rdPtr->rMipmapsH[i]->Create(w,h,rdPtr->rImageH);
					HDC dstdc = rdPtr->rMipmapsH[i]->GetDC();
					SetStretchBltMode(dstdc,HALFTONE);
					SetBrushOrgEx(srcdc,0,0,NULL);
					StretchBlt(dstdc, 0, 0, w, h, srcdc, 0 , 0, ow, oh, SRCCOPY);
					rdPtr->rMipmapsH[i]->ReleaseDC(dstdc);

				}
			}
			rdPtr->rImageH->ReleaseDC(srcdc);
		}
	}
}
void RedrawScene(LPRDATA rdPtr, bool redraw) {
	if ( rdPtr->rSf != NULL ) {
		COLORREF	tempColor;
	//	COLORREF	fadeColor = RGB(0,0,0);
		double dtr = 3.1415926535897932384626433832795 / 180;
		//double rtd = 180 / 3.1415926535897932384626433832795;

		double zcos=cos(rdPtr->rAngle * dtr);
		double zsin=sin(rdPtr->rAngle * dtr);
		double zcos2=cos(rdPtr->rAngle2 * dtr);
		double zsin2=sin(rdPtr->rAngle2 * dtr);
		double xcos=cos(rdPtr->rTilt * dtr);
		double xsin=sin(rdPtr->rTilt * dtr);
		int xoff=rdPtr->rHo.hoImgWidth>>1;
		int yoff=rdPtr->rHo.hoImgHeight>>1;

		// Original Map Image width height:
		// rImageWidth, rImageHeight

		// Rendersurface width height
		// rHo.hoImgWidth rHo.hoImgHeight

		rdPtr->rSf->BeginRaster();
		rdPtr->rImage->BeginRaster();
		rdPtr->rImage2->BeginRaster();
		rdPtr->rImageH->BeginRaster();

		rdPtr->rSf->Fill(0,0,0);


		// precalcs
		int vlimit=rdPtr->rHo.hoImgHeight;
		int vlimitmin = rdPtr->rHo.hoImgHeight+rdPtr->rResY;
		int vlimitmax = rdPtr->rHo.hoImgHeight<<3;
		bool interpolate = rdPtr->rInterpolate||rdPtr->rInterpolateHeight;

		if (rdPtr->rElevation)
		for (int y=rdPtr->rElevation>=0; y<=vlimit; y+=rdPtr->rResY) {
		//for (int y=rdPtr->rHo.hoImgHeight; --y>0;) {}
			double v=(double)abs(rdPtr->rElevation)/(rdPtr->rElevation<0?rdPtr->rHo.hoImgHeight-y+1:y);
			//double vv=xcos*v-xsin*y;
			BYTE blend =(BYTE)(max(min(abs(rdPtr->rFogDistance)/(rdPtr->rElevation<0?rdPtr->rHo.hoImgHeight-y+1:y),255),0));

			//double v=xsin*rdPtr->rElevation+xcos*y;

			//double w=(double)((y-yoff)*xcos/xoff+xsin);
			//double z=rdPtr->rElevation/w;
			//double v=(double)(xcos-(y-yoff)*xsin/xoff)*z;
			//for (int x=0; x<rdPtr->rHo.hoImgWidth; x++) {}
			//for (int x=rdPtr->rHo.hoImgWidth; (x-=rdPtr->rResX)>=0;) {}
			for (int x=0; x<rdPtr->rHo.hoImgWidth; x+=rdPtr->rResX) 
				if (rdPtr->rFog&&blend==255&&((rdPtr->rRepeatX&&rdPtr->rRepeatY)||rdPtr->rImage2Num>=-1))
					setPixel(rdPtr,x,y,rdPtr->rFogColor);
				else {
				//double u=(x/xoff-1)*z;

				//double u=(xoff-x)*(xcos*v)/rdPtr->rHo.hoImgWidth;
				//u=xcos*u-xsin*(xoff-x);
				double u=(xoff-x)*v/rdPtr->rHo.hoImgWidth;
				float imgx = (float)((zcos*u-zsin*v+rdPtr->rXOffset)*rdPtr->rZoom/100);
				float imgy = (float)((zsin*u+zcos*v+rdPtr->rYOffset)*rdPtr->rZoom/100);
				//int xi = (int)(imgx*rdPtr->rZoom)/100;
				//int yi = (int)(imgy*rdPtr->rZoom)/100;
				
				double distance=0;
				if (rdPtr->rMipmap) {
					int yy = y+1;//rdPtr->rResY;
					double cv=(double)abs(rdPtr->rElevation)/(rdPtr->rElevation<0?rdPtr->rHo.hoImgHeight-yy+1:yy);
					double cu=(xoff-x)*cv/rdPtr->rHo.hoImgWidth;
					float cimgx = (float)(((zcos*cu - zsin*cv + rdPtr->rXOffset)*rdPtr->rZoom)/100);
					float cimgy = (float)(((zsin*cu + zcos*cv + rdPtr->rYOffset)*rdPtr->rZoom)/100);
					distance = sqrt((cimgx-imgx)*(cimgx-imgx)+(cimgy-imgy)*(cimgy-imgy)) - 0.3f;
				}

				//	distance = sqrt(	(rdPtr->rXOffset+imgx)*(rdPtr->rXOffset+imgx) + // x
				//						(rdPtr->rYOffset+imgy)*(rdPtr->rYOffset+imgy) + // y
				//						(rdPtr->rElevation*rdPtr->rElevation/1000)		// z
				//						);
				/*if (y==10&&x==50) {
		char buf[128];
		sprintf(buf,"distance:%f",distance);
		MessageBox(0,buf,"mode 7 debug",MB_OK);
				}*/
				if (rdPtr->rRepeatX && interpolate) imgx=MOD2(imgx,rdPtr->rImageWidth);
				if (rdPtr->rRepeatY && interpolate) imgy=MOD2(imgy,rdPtr->rImageHeight);
				int xi = (int)imgx;
				int yi = (int)imgy;
				if (rdPtr->rRepeatX && !interpolate) xi=MOD1(xi,rdPtr->rImageWidth);
				if (rdPtr->rRepeatY && !interpolate) yi=MOD1(yi,rdPtr->rImageHeight);
				
				if ((rdPtr->rRepeatX || (xi>=0 && xi<rdPtr->rImageWidth)) && (rdPtr->rRepeatY || (yi>=0 && yi<rdPtr->rImageHeight))) {
					if (rdPtr->rMipmap) {
						//for (int i=0; i<rdPtr->rNMipLevels; i++) 
						//	if (distance<100+(50<<i)) break;
						//if (i==0) {}
						if (distance<=1) {
							if (rdPtr->rInterpolate)
								tempColor = getPixel2(rdPtr->rImage,rdPtr->rImageWidth,rdPtr->rImageHeight,rdPtr->rRepeatX,rdPtr->rRepeatY,imgx,imgy);
							else
								rdPtr->rImage->GetPixel(xi,yi,tempColor); 
						} else {
							for (int i=0; i<rdPtr->rNMipLevels; i++) 
								if (distance<1<<i) break;
							i=rdPtr->rNMipLevels-i;
							i=max(i,0);
							int w=1<<i,h=1<<i;
							if (rdPtr->rInterpolate)
								tempColor = getPixel2(rdPtr->rMipmaps[i],w,h,rdPtr->rRepeatX,rdPtr->rRepeatY,imgx*w/rdPtr->rImageWidth,imgy*h/rdPtr->rImageHeight);
							else
								rdPtr->rMipmaps[i]->GetPixel(xi*w/rdPtr->rImageWidth,yi*h/rdPtr->rImageHeight,tempColor); 
						}
					} else {
						if (rdPtr->rInterpolate)
							tempColor = getPixel2(rdPtr->rImage,rdPtr->rImageWidth,rdPtr->rImageHeight,rdPtr->rRepeatX,rdPtr->rRepeatY,imgx,imgy);
						else
							rdPtr->rImage->GetPixel(xi,yi,tempColor); 
					}
				} else tempColor=0;

				if (tempColor>0) {
					if (rdPtr->rFog) tempColor = transparency(tempColor,rdPtr->rFogColor,blend);
					if (rdPtr->rThickness) {
						int thick = rdPtr->rThickness;
						if (rdPtr->rImageHNum>=-1) {
							BYTE rvalue=0;
							if (rdPtr->rInterpolateHeight) {
								float imgx2=MOD2(imgx,rdPtr->rImageHWidth);
								float imgy2=MOD2(imgy,rdPtr->rImageHHeight);
								if (!rdPtr->rMipmapH||distance<=1)
									rvalue = getPixel256(	rdPtr->rImageH,
															rdPtr->rImageHWidth,
															rdPtr->rImageHHeight,
															1,1,
															imgx2,imgy2);
								else {
									for (int i=0; i<rdPtr->rNMipLevelsH; i++) 
										if (distance<1<<i) break;
									i=rdPtr->rNMipLevelsH-i;
									i=max(i,0);
									int w=1<<i,h=1<<i;
									rvalue = getPixel256(	rdPtr->rMipmapsH[i],
															w,h,
															1,1,
															imgx2*w/rdPtr->rImageHWidth,imgy2*h/rdPtr->rImageHHeight);
								}
							} else {
								COLORREF tempColor2 = 0;
								int xi2=MOD1(xi,rdPtr->rImageHWidth);
								int yi2=MOD1(yi,rdPtr->rImageHHeight);
								if (!rdPtr->rMipmapH||distance<=1)
									rdPtr->rImageH->GetPixel(xi2, yi2, tempColor2);
								else {
									for (int i=0; i<rdPtr->rNMipLevelsH; i++) 
										if (distance<1<<i) break;
									i=rdPtr->rNMipLevelsH-i;
									i=max(i,0);
									int w=1<<i,h=1<<i;
									rdPtr->rMipmapsH[i]->GetPixel(xi2*w/rdPtr->rImageHWidth,yi2*h/rdPtr->rImageHHeight,tempColor2); 
								}
								rvalue=GetRValue(tempColor2);
							}	
							thick = (thick*rvalue)>>8;
						}
						int y1=(int)((rdPtr->rElevation-thick)*(y)/rdPtr->rElevation);
						int y2=0;
						bool check=true;
						// Next Row-height
						// (Optimized height routine! Saves hundreds of pixel draws)
						if (y+rdPtr->rResY>=vlimit) {
							check=false;
							if (rdPtr->rThicknessMode==1) y2=y;
							else if (rdPtr->rThicknessMode==2 &&
										y1 < rdPtr->rHo.hoImgHeight) {
								vlimit += rdPtr->rResY<<2;
								if (vlimit>=vlimitmax) {
									vlimit = max(min(vlimitmax,vlimit),vlimitmin);
									y2=y;
								} else check=true;
							}
						} 
						if (check) {
							int yy = y+rdPtr->rResY;
							double cv=(double)abs(rdPtr->rElevation)/(rdPtr->rElevation<0?rdPtr->rHo.hoImgHeight-yy+1:yy);
							double cu=(xoff-x) * cv / rdPtr->rHo.hoImgWidth;
							float cimgx = (float)(((zcos*cu - zsin*cv + rdPtr->rXOffset)*rdPtr->rZoom)/100);
							float cimgy = (float)(((zsin*cu + zcos*cv + rdPtr->rYOffset)*rdPtr->rZoom)/100);
							
							double distance2=0;
							if (rdPtr->rMipmapH) {
								int myy = yy+1;//rdPtr->rResY;
								double mcv=(double)abs(rdPtr->rElevation)/(rdPtr->rElevation<0?rdPtr->rHo.hoImgHeight-myy+1:myy);
								double mcu=(xoff-x)*mcv/rdPtr->rHo.hoImgWidth;
								float mcimgx = (float)(((zcos*mcu - zsin*mcv + rdPtr->rXOffset)*rdPtr->rZoom)/100);
								float mcimgy = (float)(((zsin*mcu + zcos*mcv + rdPtr->rYOffset)*rdPtr->rZoom)/100);
								distance2 = sqrt((mcimgx-cimgx)*(mcimgx-cimgx)+(mcimgy-cimgy)*(mcimgy-cimgy)) - 0.3f;
							}

							if (rdPtr->rRepeatX && rdPtr->rInterpolateHeight) cimgx=MOD2(cimgx,rdPtr->rImageWidth);
							if (rdPtr->rRepeatY && rdPtr->rInterpolateHeight) cimgy=MOD2(cimgy,rdPtr->rImageHeight);
							int cxi = (int)cimgx;
							int cyi = (int)cimgy;
							if (rdPtr->rRepeatX && !rdPtr->rInterpolateHeight) cxi=MOD1(cxi,rdPtr->rImageWidth);
							if (rdPtr->rRepeatY && !rdPtr->rInterpolateHeight) cyi=MOD1(cyi,rdPtr->rImageHeight);

							COLORREF tempColor3 = 0;
							if ((rdPtr->rRepeatX || (cxi>=0 && cxi<rdPtr->rImageWidth)) && (rdPtr->rRepeatY || (cyi>=0 && cyi<rdPtr->rImageHeight)))
								rdPtr->rImage->GetPixel(cxi, cyi, tempColor3);
							
							//if (rdPtr->rRepeat || (xi>=0 && xi<rdPtr->rImageWidth && yi>=0 && yi<rdPtr->rImageHeight))
							//	rdPtr->rImage->GetPixel(xi, yi, tempColor3);
							
							int thick2 = rdPtr->rThickness;
							if (tempColor3) {
								if (rdPtr->rImageHNum>=-1) {
									BYTE rvalue=0;
									if (rdPtr->rInterpolateHeight) {
										if (!rdPtr->rRepeatX) cimgx=MOD2(cimgx,rdPtr->rImageHWidth);
										if (!rdPtr->rRepeatY) cimgy=MOD2(cimgy,rdPtr->rImageHHeight);
										if (!rdPtr->rMipmapH||distance2<=1)
											rvalue = getPixel256(	rdPtr->rImageH,
																	rdPtr->rImageHWidth,
																	rdPtr->rImageHHeight,
																	1,1,
																	cimgx,cimgy);
										else {
											for (int i=0; i<rdPtr->rNMipLevelsH; i++) 
												if (distance2<1<<i) break;
											i=rdPtr->rNMipLevelsH-i;
											i=max(i,0);
											int w=1<<i,h=1<<i;
											rvalue = getPixel256(	rdPtr->rMipmapsH[i],
																	w,h,
																	1,1,
																	cimgx*w/rdPtr->rImageHWidth,cimgy*h/rdPtr->rImageHHeight);
										}
									} else {
										if (!rdPtr->rRepeatX) cxi=MOD1(cxi,rdPtr->rImageHWidth);
										if (!rdPtr->rRepeatY) cyi=MOD1(cyi,rdPtr->rImageHHeight);
										if (!rdPtr->rMipmapH||distance2<=1)
											rdPtr->rImageH->GetPixel(cxi, cyi, tempColor3);
										else {
											for (int i=0; i<rdPtr->rNMipLevelsH; i++) 
												if (distance2<1<<i) break;
											i=rdPtr->rNMipLevelsH-i;
											i=max(i,0);
											int w=1<<i,h=1<<i;
											rdPtr->rMipmapsH[i]->GetPixel(cxi*w/rdPtr->rImageHWidth,cyi*h/rdPtr->rImageHHeight,tempColor3); 
										}
										rvalue=GetRValue(tempColor3);
									}
									thick2 = (thick2*rvalue)>>8;
								}
							} else
								thick2=0;
							y2=(int)((rdPtr->rElevation-thick2)*yy/rdPtr->rElevation);
						}
						y1=max(min(y1,rdPtr->rHo.hoImgHeight),0);
						y2=max(min(y2,rdPtr->rHo.hoImgHeight),0);
						y2+=rdPtr->rResY;
						for (; y1<=y2; y1+=rdPtr->rResY)
							setPixel(rdPtr,x,y1,tempColor);
					} else
						setPixel(rdPtr,x,y,tempColor);
				} else if (rdPtr->rImage2Num>=-1) {
					float xi2=(float)(zcos2*imgx-zsin2*imgy + rdPtr->rXOffset2);
					float yi2=(float)(zsin2*imgx+zcos2*imgy + rdPtr->rYOffset2);
					if (rdPtr->rInterpolate) {
						xi2=MOD2(xi2,rdPtr->rImage2Width);
						yi2=MOD2(yi2,rdPtr->rImage2Height);
						if (!rdPtr->rMipmap2||distance<=2)
							tempColor = getPixel2(rdPtr->rImage2,rdPtr->rImage2Width,rdPtr->rImage2Height,1,1,xi2,yi2);
						else {
							for (int i=0; i<rdPtr->rNMipLevels2; i++) 
								if (distance<2<<i) break;
							i=rdPtr->rNMipLevels2-i;
							i=max(i,0);
							int w=1<<i,h=1<<i;
							tempColor = getPixel2(rdPtr->rMipmaps2[i],w,h,rdPtr->rRepeatX,rdPtr->rRepeatY,xi2*w/rdPtr->rImage2Width,yi2*h/rdPtr->rImage2Height);
						}
					} else {
						int xii=(int)xi2;
						int yii=(int)yi2;
						xii=MOD1(xii,rdPtr->rImage2Width);
						yii=MOD1(yii,rdPtr->rImage2Height);
						if (!rdPtr->rMipmap2||distance<=2)
							rdPtr->rImage2->GetPixel(xii,yii,tempColor);
						else {
							for (int i=0; i<rdPtr->rNMipLevels2; i++) 
								if (distance<2<<i) break;
							i=rdPtr->rNMipLevels2-i;
							i=max(i,0);
							int w=1<<i,h=1<<i;
							rdPtr->rMipmaps2[i]->GetPixel(xii*w/rdPtr->rImage2Width,yii*h/rdPtr->rImage2Height,tempColor); 
						}
					}
					if (rdPtr->rFog) tempColor = transparency(tempColor,rdPtr->rFogColor,blend);
					setPixel(rdPtr,x,y,tempColor);
				}
			}
		}

		rdPtr->rSf->EndRaster();
		rdPtr->rImage->EndRaster();
		rdPtr->rImage2->EndRaster();
		rdPtr->rImageH->EndRaster();
		rdPtr->rNeedRedraw=false;
		if (redraw) callRunTimeFunction(rdPtr, RFUNCTION_REDRAW, 0, 0);
	}
}


// ============================================================================
//
// CONDITION ROUTINES
//
// ============================================================================

/// No conditions

// ============================================================================
//
// ACTIONS ROUTINES
//
// ============================================================================


short WINAPI DLLExport Act_Show(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->rShow = true;
	return 0;
}
short WINAPI DLLExport Act_Hide(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->rShow = false;
	return 0;
}
short WINAPI DLLExport Act_TransOn(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->rTrans = true;
	return 0;
}
short WINAPI DLLExport Act_TransOff(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->rTrans = false;
	return 0;
}


// Load picture file
short WINAPI DLLExport Act_LoadImage(LPRDATA rdPtr, long param1, long param2) {
	// Nothing to do if image file already loaded
	if (rdPtr->rImage != NULL) { // && _fstricmp (rdPtr->rImageFile,(LPSTR)param1)!=0) {
		_fstrcpy (rdPtr->rImageFile,(LPSTR)param1);
		// Load image into surface
		rdPtr->rImage->LoadImage(rdPtr->rImageFile, LI_REMAP);
		rdPtr->rImageNum = -1;
		rdPtr->rImageWidth = rdPtr->rImage->GetWidth();
		rdPtr->rImageHeight = rdPtr->rImage->GetHeight();
		UpdateMipMaps(rdPtr);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_SetWidth(LPRDATA rdPtr, long param1, long param2) {
	int newWidth = max(param1, 1);
	if (rdPtr->rHo.hoImgWidth != newWidth) {
		rdPtr->rHo.hoImgWidth = newWidth;
		LPSURFACE pProto = NULL;
		if (GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DDRAW)||GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DIB))
			rdPtr->rSf->Create(rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight, pProto);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_SetHeight(LPRDATA rdPtr, long param1, long param2) {
	int newHeight = max(param1, 1);
	if (rdPtr->rHo.hoImgHeight != newHeight ) {
		rdPtr->rHo.hoImgHeight = newHeight;
		LPSURFACE pProto = NULL;
		if (GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DDRAW)||GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DIB))
			rdPtr->rSf->Create(rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight, pProto);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_SetTilt(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rTilt == (int)(param1)) return 0;
	rdPtr->rTilt = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetAngle(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rAngle == (int)(param1)) return 0;
	rdPtr->rAngle = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetRoll(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rRoll == (int)(param1)) return 0;
	rdPtr->rRoll = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetXOffset(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rXOffset == (int)(param1)) return 0;
	rdPtr->rXOffset = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetElevation(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rElevation == (int)(param1)) return 0;
	rdPtr->rElevation = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetYOffset(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rYOffset == (int)(param1)) return 0;
	rdPtr->rYOffset = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetXCenter(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rXCenter == (int)(param1)) return 0;
	rdPtr->rXCenter = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetYCenter(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rYCenter == (int)(param1)) return 0;
	rdPtr->rYCenter = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

short WINAPI DLLExport Act_SetVanish(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rVanish == (float)(max( (short)param1 , 0 ))) return 0;
	rdPtr->rVanish = (float)(max( (short)param1 , 0 ));
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetZoom(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rZoom == (int)param1) return 0;
	rdPtr->rZoom = (int)param1;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

short WINAPI DLLExport Act_Redraw(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	else RedrawScene(rdPtr,1);
	return 0;
}
short WINAPI DLLExport Act_AdjustAngle(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	rdPtr->rAngle += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustXOffset(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	rdPtr->rXOffset += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustElevation(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	rdPtr->rElevation += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustYOffset(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	rdPtr->rYOffset += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_WalkForward(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	double dtr = 3.1415926535897932384626433832795 / 180;
	rdPtr->rXOffset += sin(-rdPtr->rAngle * dtr)*(int)(param1);
	rdPtr->rYOffset += cos(-rdPtr->rAngle * dtr)*(int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_WalkBack(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	double dtr = 3.1415926535897932384626433832795 / 180;
	rdPtr->rXOffset -= sin(-rdPtr->rAngle * dtr)*(int)(param1);
	rdPtr->rYOffset -= cos(-rdPtr->rAngle * dtr)*(int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_WalkLeft(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	double dtr = 3.1415926535897932384626433832795 / 180;
	rdPtr->rXOffset += sin(-(rdPtr->rAngle-90) * dtr)*(int)(param1);
	rdPtr->rYOffset += cos(-(rdPtr->rAngle-90) * dtr)*(int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

short WINAPI DLLExport Act_WalkRight(LPRDATA rdPtr, long param1, long param2)
{
	if (!param1) return 0;
	double dtr = 3.1415926535897932384626433832795 / 180;
	rdPtr->rXOffset -= sin(-(rdPtr->rAngle-90) * dtr)*(int)(param1);
	rdPtr->rYOffset -= cos(-(rdPtr->rAngle-90) * dtr)*(int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}


short WINAPI DLLExport Act_WrapXOn(LPRDATA rdPtr, long param1, long param2)
{
	DEBUGMSG("Wrap x ON");
	if (rdPtr->rRepeatX) return 0;
	rdPtr->rRepeatX = true;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_WrapXOff(LPRDATA rdPtr, long param1, long param2)
{
	DEBUGMSG("Wrap x OFF");
	if (!rdPtr->rRepeatX) return 0;
	rdPtr->rRepeatX = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_WrapYOn(LPRDATA rdPtr, long param1, long param2)
{
	DEBUGMSG("Wrap y ON");
	if (rdPtr->rRepeatY) return 0;
	rdPtr->rRepeatY = true;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_WrapYOff(LPRDATA rdPtr, long param1, long param2)
{
	DEBUGMSG("Wrap y OFF");
	if (!rdPtr->rRepeatY) return 0;
	rdPtr->rRepeatY = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}



short WINAPI DLLExport Act_SetResolution(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rResX == min(max( (int)param1 , 1 ),1000)&&
		rdPtr->rResY == min(max( (int)param2 , 1 ),1000)) return 0;
	rdPtr->rResX = min(max( (int)param1 , 1 ),1000);
	rdPtr->rResY = min(max( (int)param2 , 1 ),1000);
	if (rdPtr->rResX==1&&rdPtr->rResY==1) rdPtr->rResMode2=0;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetResolutionMode(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rResMode == min(max( (int)param1 , 0 ),3)&&
		rdPtr->rResModeParam == min(max( (int)param2 , 0 ),255)) return 0;
	rdPtr->rResMode = min(max( (int)param1 , 0 ),3);
	rdPtr->rResModeParam = min(max( (int)param2 , 0 ),255);
	
	// Optimized res mode
	if (rdPtr->rResX==1&&rdPtr->rResY==1) rdPtr->rResMode2=0;
	else rdPtr->rResMode2=rdPtr->rResMode;
	
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetThickness(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rThickness == max( (int)param1 , 0 )) return 0;
	rdPtr->rThickness = max( (int)param1 , 0 );
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustTilt(LPRDATA rdPtr, long param1, long param2) {
	if (!param1) return 0;
	rdPtr->rTilt += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustRoll(LPRDATA rdPtr, long param1, long param2) {
	if (!param1) return 0;
	rdPtr->rRoll += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetXResolution(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rResX == min(max( (int)param1 , 1 ),1000)) return 0;
	rdPtr->rResX = min(max( (int)param1 , 1 ),1000);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetYResolution(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rResY = min(max( (int)param1 , 1 ),1000)) return 0;
	rdPtr->rResY = min(max( (int)param1 , 1 ),1000);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
int LoadImageToSurface(LPRDATA rdPtr, DWORD param, cSurface *surface) {
	if (rdPtr->rNImages) {
		if ( param >= rdPtr->rNImages )
			param = (param % rdPtr->rNImages);
		fprh rhPtr = rdPtr->rHo.hoAdRunHeader;
		LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
		cSurface imageSurface;
		::LockImageSurface (rhPtr->rhIdAppli, ((LPINTERNALIMAGE)(pii+param))->cImg, imageSurface);

		LPSURFACE pProto = NULL;
		if (GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DDRAW)||GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DIB)) {
			surface->Create(imageSurface.GetWidth(),imageSurface.GetHeight(),pProto);
			imageSurface.Blit(*surface, 0, 0, BMODE_OPAQUE, BOP_COPY, 0);
		}
		::UnlockImageSurface (imageSurface);
		//delete imageSurface;
		return 1;
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImageNumber(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImage != NULL && rdPtr->rImageNum != param1 && LoadImageToSurface(rdPtr,param1,rdPtr->rImage)) {
		rdPtr->rImageNum = param1;
		rdPtr->rImageWidth = rdPtr->rImage->GetWidth();
		rdPtr->rImageHeight = rdPtr->rImage->GetHeight();
		UpdateMipMaps(rdPtr);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImageName(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImage != NULL) {
		DWORD dwNum = 0;
		if (param1 != NULL) {
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			for (WORD w=0; w<rdPtr->rNImages; w++, pii++)
				if ( _fstricmp(pii->cName, (LPSTR)param1) == 0 ) {
					_fstrcpy (rdPtr->rImageFile,(LPSTR)param1);
					dwNum = (DWORD)w;
					rdPtr->rImageNum = dwNum;
					break;
				}
		}
		if ((DWORD)rdPtr->rImageNum != dwNum && LoadImageToSurface(rdPtr, dwNum,rdPtr->rImage)) {
			rdPtr->rImageNum = dwNum;
			rdPtr->rImageWidth = rdPtr->rImage->GetWidth();
			rdPtr->rImageHeight = rdPtr->rImage->GetHeight();
			UpdateMipMaps(rdPtr);
			if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
		}
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImage2(LPRDATA rdPtr, long param1, long param2) {
	// Nothing to do if image file already loaded
	if (rdPtr->rImage2 != NULL && _fstricmp (rdPtr->rImage2File,(LPSTR)param1)!=0) {
		_fstrcpy (rdPtr->rImage2File,(LPSTR)param1);
		// Load image into surface
		rdPtr->rImage2->LoadImage(rdPtr->rImage2File, LI_REMAP);
		rdPtr->rImage2Num = -1;
		rdPtr->rImage2Width = rdPtr->rImage2->GetWidth();
		rdPtr->rImage2Height = rdPtr->rImage2->GetHeight();
		UpdateMipMaps2(rdPtr);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImage2Number(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImage2 != NULL && rdPtr->rImage2Num != param1 && LoadImageToSurface(rdPtr,param1,rdPtr->rImage2)) {
		rdPtr->rImage2Num = param1;
		rdPtr->rImage2Width = rdPtr->rImage2->GetWidth();
		rdPtr->rImage2Height = rdPtr->rImage2->GetHeight();
		UpdateMipMaps2(rdPtr);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImage2Name(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImage2 != NULL) {
		DWORD dwNum = 0;
		if (param1 != NULL) {
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			for (WORD w=0; w<rdPtr->rNImages; w++, pii++)
				if ( _fstricmp(pii->cName, (LPSTR)param1) == 0 ) {
					_fstrcpy (rdPtr->rImage2File,(LPSTR)param1);
					dwNum = (DWORD)w;
					break;
				}
		}
		if ((DWORD)rdPtr->rImage2Num != dwNum && LoadImageToSurface(rdPtr, dwNum, rdPtr->rImage2)) {
			rdPtr->rImage2Num = dwNum;
			rdPtr->rImage2Width = rdPtr->rImage2->GetWidth();
			rdPtr->rImage2Height = rdPtr->rImage2->GetHeight();
			UpdateMipMaps2(rdPtr);
			if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
		}
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImageH(LPRDATA rdPtr, long param1, long param2) {
	// Nothing to do if image file already loaded
	if (rdPtr->rImageH != NULL && _fstricmp (rdPtr->rImageHFile,(LPSTR)param1)!=0) {
		_fstrcpy (rdPtr->rImageHFile,(LPSTR)param1);
		// Load image into surface
		rdPtr->rImageH->LoadImage(rdPtr->rImageHFile, LI_REMAP);
		rdPtr->rImageHWidth = rdPtr->rImageH->GetWidth();
		rdPtr->rImageHHeight = rdPtr->rImageH->GetHeight();
		rdPtr->rImageHNum = -1;
		UpdateMipMapsH(rdPtr);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImageHNumber(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImageH != NULL && rdPtr->rImageHNum != param1 && LoadImageToSurface(rdPtr,param1,rdPtr->rImageH)) {
		rdPtr->rImageHNum = param1;
		rdPtr->rImageHWidth = rdPtr->rImageH->GetWidth();
		rdPtr->rImageHHeight = rdPtr->rImageH->GetHeight();
		UpdateMipMapsH(rdPtr);
		if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	}
	return 0;
}
short WINAPI DLLExport Act_LoadImageHName(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImageH != NULL) {
		DWORD dwNum = 0;
		if (param1 != NULL) {
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			for (WORD w=0; w<rdPtr->rNImages; w++, pii++)
				if ( _fstricmp(pii->cName, (LPSTR)param1) == 0 ) {
					_fstrcpy (rdPtr->rImageHFile,(LPSTR)param1);
					dwNum = (DWORD)w;
					break;
				}
		}
		if ((DWORD)rdPtr->rImageHNum != dwNum && LoadImageToSurface(rdPtr, dwNum, rdPtr->rImageH)) {
			rdPtr->rImageHNum = dwNum;
			rdPtr->rImageHWidth = rdPtr->rImageH->GetWidth();
			rdPtr->rImageHHeight = rdPtr->rImageH->GetHeight();
			UpdateMipMapsH(rdPtr);
			if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
		}
	}
	return 0;
}
short WINAPI DLLExport Act_UnloadImage2(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImage2Num == -2) return 0;
	rdPtr->rImage2Num = -2;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_UnloadImageH(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rImageHNum == -2) return 0;
	rdPtr->rImageHNum = -2;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_FogOn(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rFog) return 0;
	rdPtr->rFog = true;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_FogOff(LPRDATA rdPtr, long param1, long param2)
{
	if (!rdPtr->rFog) return 0;
	rdPtr->rFog = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_ChooseFogColor(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rFogColor == (COLORREF)param1) return 0;
	rdPtr->rFogColor = (COLORREF)param1;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetFogColor(LPRDATA rdPtr, long param1, long param2)
{
	long p1 = CNC_GetParameter(rdPtr);
	long p2 = CNC_GetParameter(rdPtr);
	long p3 = CNC_GetParameter(rdPtr);
	if (rdPtr->rFogColor == RGB((BYTE)p1,(BYTE)p2,(BYTE)p3)) return 0;
	rdPtr->rFogColor = RGB((BYTE)p1,(BYTE)p2,(BYTE)p3);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetFogRed(LPRDATA rdPtr, long param1, long param2)
{
	if ((BYTE)param1 == GetRValue(rdPtr->rFogColor)) return 0;
	BYTE g = GetGValue(rdPtr->rFogColor);
	BYTE b = GetBValue(rdPtr->rFogColor);
	rdPtr->rFogColor = RGB((BYTE)param1,g,b);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetFogGreen(LPRDATA rdPtr, long param1, long param2)
{
	if ((BYTE)param1 == GetGValue(rdPtr->rFogColor)) return 0;
	BYTE r = GetRValue(rdPtr->rFogColor);
	BYTE b = GetBValue(rdPtr->rFogColor);
	rdPtr->rFogColor = RGB(r,(BYTE)param1,b);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetFogBlue(LPRDATA rdPtr, long param1, long param2)
{
	if ((BYTE)param1 == GetBValue(rdPtr->rFogColor)) return 0;
	BYTE r = GetRValue(rdPtr->rFogColor);
	BYTE g = GetGValue(rdPtr->rFogColor);
	rdPtr->rFogColor = RGB(r,g,(BYTE)param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetFogDistance(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rFogDistance == (int)param1) return 0;
	rdPtr->rFogDistance = (int)param1;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetXOffset2(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rXOffset2 == (int)(param1)) return 0;
	rdPtr->rXOffset2 = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetYOffset2(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rYOffset2 == (int)(param1)) return 0;
	rdPtr->rYOffset2 = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustXOffset2(LPRDATA rdPtr, long param1, long param2) {
	if (!param1) return 0;
	rdPtr->rXOffset2 += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustYOffset2(LPRDATA rdPtr, long param1, long param2) {
	if (!param1) return 0;
	rdPtr->rYOffset2 += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetAngle2(LPRDATA rdPtr, long param1, long param2) {
	if (rdPtr->rAngle2 == (int)(param1)) return 0;
	rdPtr->rAngle2 = (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AdjustAngle2(LPRDATA rdPtr, long param1, long param2) {
	if (!param1) return 0;
	rdPtr->rAngle2 += (int)(param1);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_SetThicknessMode(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rThicknessMode == min(max( (int)param1 , 0 ),2)) return 0;
	rdPtr->rThicknessMode = min(max( (int)param1 , 0 ),2);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_InterpolationOn(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rInterpolate) return 0;
	rdPtr->rInterpolate = true;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_InterpolationOff(LPRDATA rdPtr, long param1, long param2)
{
	if (!rdPtr->rInterpolate) return 0;
	rdPtr->rInterpolate = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_HeightInterpolationOn(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rInterpolateHeight) return 0;
	rdPtr->rInterpolateHeight = true;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_HeightInterpolationOff(LPRDATA rdPtr, long param1, long param2)
{
	if (!rdPtr->rInterpolateHeight) return 0;
	rdPtr->rInterpolateHeight = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

short WINAPI DLLExport Act_MipMapOn(LPRDATA rdPtr, long param1, long param2) 
{
	if (rdPtr->rMipmap) return 0;
	rdPtr->rMipmap = true;
	UpdateMipMaps(rdPtr);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_MipMapOff(LPRDATA rdPtr, long param1, long param2) 
{
	if (!rdPtr->rMipmap) return 0;
	rdPtr->rMipmap = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

short WINAPI DLLExport Act_MipMap2On(LPRDATA rdPtr, long param1, long param2) 
{
	if (rdPtr->rMipmap2) return 0;
	rdPtr->rMipmap2 = true;
	UpdateMipMaps2(rdPtr);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_MipMap2Off(LPRDATA rdPtr, long param1, long param2) 
{
	if (!rdPtr->rMipmap2) return 0;
	rdPtr->rMipmap2 = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

short WINAPI DLLExport Act_MipMapHOn(LPRDATA rdPtr, long param1, long param2) 
{
	if (rdPtr->rMipmapH) return 0;
	rdPtr->rMipmapH = true;
	UpdateMipMapsH(rdPtr);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_MipMapHOff(LPRDATA rdPtr, long param1, long param2) 
{
	if (!rdPtr->rMipmapH) return 0;
	rdPtr->rMipmapH = false;
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AutoRedrawOn(LPRDATA rdPtr, long param1, long param2) 
{
	if (rdPtr->rAutoRedraw) return 0;
	rdPtr->rAutoRedraw=true;
	rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_AutoRedrawOff(LPRDATA rdPtr, long param1, long param2) 
{
	if (!rdPtr->rAutoRedraw) return 0;
	rdPtr->rAutoRedraw=false;
	return 0;
}

short WINAPI DLLExport Act_SetMipTrans(LPRDATA rdPtr, long param1, long param2)
{
	if (rdPtr->rMipTrans == (COLORREF)param1) return 0;
	rdPtr->rMipTrans = rdPtr->rMipTrans2 = (COLORREF)param1;
	// Workaround due to color glitching
	LPSURFACE dsf = new cSurface;
	dsf->Create(4,4,rdPtr->rImage);
	dsf->Fill(rdPtr->rMipTrans);
	HDC ddc = dsf->GetDC();
	SetStretchBltMode(ddc,HALFTONE);
	SetBrushOrgEx(ddc,0,0,NULL);
	StretchBlt(ddc, 0, 0, 1, 1, ddc, 1, 0, 3, 4, SRCCOPY);
	dsf->GetPixel(0,0,rdPtr->rMipTrans2);
	dsf->ReleaseDC(ddc);
	delete dsf;

	UpdateMipMaps(rdPtr);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}
short WINAPI DLLExport Act_MipTransOff(LPRDATA rdPtr, long param1, long param2)
{
	if (!rdPtr->rMipTrans) return 0;
	rdPtr->rMipTrans = rdPtr->rMipTrans2 = 0;
	UpdateMipMaps(rdPtr);
	if (rdPtr->rAutoRedraw) rdPtr->rNeedRedraw=true;
	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
//
// ============================================================================


long WINAPI DLLExport Exp_GetWidth(LPRDATA rdPtr,long param1) {
	return rdPtr->rHo.hoImgWidth;
}
long WINAPI DLLExport Exp_GetHeight(LPRDATA rdPtr,long param1) {
	return rdPtr->rHo.hoImgHeight;
}
long WINAPI DLLExport Exp_GetImageWidth(LPRDATA rdPtr,long param1) {
	return rdPtr->rImageWidth;
}
long WINAPI DLLExport Exp_GetImageHeight(LPRDATA rdPtr,long param1) {
	return rdPtr->rImageHeight;
}
long WINAPI DLLExport Exp_GetFile(LPRDATA rdPtr,long param1) {
	rdPtr->rHo.hoFlags |= HOF_STRING;
	char* temp;
	char Filename[_MAX_PATH];
	_fstrcpy(Filename,rdPtr->rImageFile);
	temp = (LPSTR)Filename;
	return (long)temp;
}
long WINAPI DLLExport Exp_GetTrans(LPRDATA rdPtr,long param1) {
	return rdPtr->rTrans;
}
long WINAPI DLLExport Exp_GetWrapX(LPRDATA rdPtr,long param1) {
	return rdPtr->rRepeatX;
}
long WINAPI DLLExport Exp_GetWrapY(LPRDATA rdPtr,long param1) {
	return rdPtr->rRepeatY;
}
long WINAPI DLLExport Exp_GetShow(LPRDATA rdPtr,long param1) {
	return rdPtr->rShow;
}
long WINAPI DLLExport Exp_GetTilt(LPRDATA rdPtr,long param1) {
	return rdPtr->rTilt;
}
long WINAPI DLLExport Exp_GetAngle(LPRDATA rdPtr,long param1) {
	return rdPtr->rAngle;
}
long WINAPI DLLExport Exp_GetRoll(LPRDATA rdPtr,long param1) {
	return rdPtr->rRoll;
}
long WINAPI DLLExport Exp_GetXOffset(LPRDATA rdPtr,long param1) {
	return (int)rdPtr->rXOffset;
}
long WINAPI DLLExport Exp_GetElevation(LPRDATA rdPtr,long param1) {
	return rdPtr->rElevation;
}
long WINAPI DLLExport Exp_GetYOffset(LPRDATA rdPtr,long param1) {
	return (int)rdPtr->rYOffset;
}
long WINAPI DLLExport Exp_GetXCenter(LPRDATA rdPtr,long param1) {
	return rdPtr->rXCenter;
}
long WINAPI DLLExport Exp_GetYCenter(LPRDATA rdPtr,long param1) {
	return rdPtr->rYCenter;
}
long WINAPI DLLExport Exp_GetVanish(LPRDATA rdPtr,long param1) {
	return (int)(rdPtr->rVanish);
}
long WINAPI DLLExport Exp_GetZoom(LPRDATA rdPtr,long param1) {
	return rdPtr->rZoom;
}
long WINAPI DLLExport Exp_GetMapX(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = rdPtr->rElevation/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/(rdPtr->rElevation/y1))+xoff;

	return (long)(x1+rdPtr->rHo.hoX);
}
long WINAPI DLLExport Exp_GetMapY(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = rdPtr->rElevation/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/(rdPtr->rElevation/y1))+xoff;

	return (long)(y1+rdPtr->rHo.hoY);

}
long WINAPI DLLExport Exp_GetMapXZ(LPRDATA rdPtr,long param1)
{

	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long p3 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	//float fx = *(float *)&p1;
	//float fy = *(float *)&p2;
	//float fz = *(float *)&p3;


	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = (rdPtr->rElevation-p3)/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/((rdPtr->rElevation-p3)/y1))+xoff;

	return (int)(x1+rdPtr->rHo.hoY);
}
long WINAPI DLLExport Exp_GetMapYZ(LPRDATA rdPtr,long param1)
{

	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long p3 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	//float fx = *(float *)&p1;
	//float fy = *(float *)&p2;
	//float fz = *(float *)&p3;


	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = (rdPtr->rElevation-p3)/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/((rdPtr->rElevation-p3)/y1))+xoff;

	return (int)(y1+rdPtr->rHo.hoY);
}
/*
long WINAPI DLLExport Exp_GetMapWidth(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long w = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long h = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom+rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom+rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = ((double)rdPtr->rElevation/yy)-(((double)rdPtr->rElevation+h*40)/yy);

	return (long)(abs((int)(y1*w/h)));

}
long WINAPI DLLExport Exp_GetMapHeight(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long h = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom+rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom+rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = (rdPtr->rElevation/yy)-((rdPtr->rElevation+h*40)/yy);

	return (int)(abs((int)(y1)));
}
*/


// Non functional
long WINAPI DLLExport Exp_GetMapWidthZ(LPRDATA rdPtr,long param1) { return 0; }
// Non functional
long WINAPI DLLExport Exp_GetMapHeightZ(LPRDATA rdPtr,long param1) { return 0; }

long WINAPI DLLExport Exp_GetMapAngle(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long a = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);


	a+=rdPtr->rAngle;
	return MOD1(a,360);
}
/*
long WINAPI DLLExport Exp_GetMapVisible(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long w = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long h = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);


	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom+rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom+rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = rdPtr->rElevation/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/(rdPtr->rElevation/y1))+xoff;


	int zw = (int)(abs((int)(((double)rdPtr->rElevation/yy)-(((double)rdPtr->rElevation+h*40)/yy))));
	int zh = (int)(abs((int)((rdPtr->rElevation/yy)-((rdPtr->rElevation+h*40)/yy))));
	zw>>=1;
	zh>>=1;

	return (long)((x1>=0)&&(x1<=rdPtr->rHo.hoImgWidth)&&(y1>=0)&&(y1<=rdPtr->rHo.hoImgHeight));
	return (long)((	(x1 >= -zw) &&
					(x1 <= rdPtr->rHo.hoImgWidth + zw) &&
					(y1 >= -zh) &&
					(y1 <= rdPtr->rHo.hoImgHeight + zh)
					) ? 1 : 0);
}
*/
long WINAPI DLLExport Exp_GetResolutionX(LPRDATA rdPtr,long param1) {
	return rdPtr->rResX;
}
long WINAPI DLLExport Exp_GetResolutionY(LPRDATA rdPtr,long param1) {
	return rdPtr->rResY;
}
long WINAPI DLLExport Exp_GetResolutionMode(LPRDATA rdPtr,long param1) {
	return rdPtr->rResMode;
}
long WINAPI DLLExport Exp_GetResolutionModeParam(LPRDATA rdPtr,long param1) {
	return rdPtr->rResModeParam;
}
long WINAPI DLLExport Exp_GetThickness(LPRDATA rdPtr,long param1) {
	return rdPtr->rThickness;
}
long WINAPI DLLExport Exp_GetImageNumber(LPRDATA rdPtr,long param1) {
	return rdPtr->rImageNum;
}
long WINAPI DLLExport Exp_GetImage2Width(LPRDATA rdPtr,long param1) {
	return rdPtr->rImage2Width;
}
long WINAPI DLLExport Exp_GetImage2Height(LPRDATA rdPtr,long param1) {
	return rdPtr->rImage2Height;
}
long WINAPI DLLExport Exp_GetImage2Number(LPRDATA rdPtr,long param1) {
	return rdPtr->rImage2Num;
}
long WINAPI DLLExport Exp_GetImage2File(LPRDATA rdPtr,long param1) {
	rdPtr->rHo.hoFlags |= HOF_STRING;
	char* temp;
	char Filename[_MAX_PATH];
	_fstrcpy(Filename,rdPtr->rImage2File);
	temp = (LPSTR)Filename;
	return (long)temp;
}
long WINAPI DLLExport Exp_GetImageHWidth(LPRDATA rdPtr,long param1) {
	return rdPtr->rImageHWidth;
}
long WINAPI DLLExport Exp_GetImageHHeight(LPRDATA rdPtr,long param1) {
	return rdPtr->rImageHHeight;
}
long WINAPI DLLExport Exp_GetImageHNumber(LPRDATA rdPtr,long param1) {
	return rdPtr->rImageHNum;
}
long WINAPI DLLExport Exp_GetImageHFile(LPRDATA rdPtr,long param1) {
	rdPtr->rHo.hoFlags |= HOF_STRING;
	char* temp;
	char Filename[_MAX_PATH];
	_fstrcpy(Filename,rdPtr->rImageHFile);
	temp = (LPSTR)Filename;
	return (long)temp;
}
long WINAPI DLLExport Exp_GetHeightAt(LPRDATA rdPtr,long param1) {

	long x = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long y = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	COLORREF tempColor = 0;
	int xi=x,yi=y;
	if (rdPtr->rRepeatX) xi=MOD1(x,rdPtr->rImageWidth);
	if (rdPtr->rRepeatY) yi=MOD1(y,rdPtr->rImageHeight);
	
	if ((rdPtr->rRepeatX || (xi>=0 && xi<rdPtr->rImageWidth))  && (rdPtr->rRepeatY || (yi>=0 && yi<rdPtr->rImageHeight))) {
		rdPtr->rImage->GetPixel(xi, yi, tempColor);
		if (tempColor) {
			//MessageBox(0,"Step 1 (not transparent))","Mode 7 Debug",MB_OK);
			if (rdPtr->rImageHNum<-1) return rdPtr->rThickness;
			//MessageBox(0,"Step 2 (variable thickness)","Mode 7 Debug",MB_OK);
			int xi3=MOD1(xi,rdPtr->rImageHWidth);
			int yi3=MOD1(yi,rdPtr->rImageHHeight);
			rdPtr->rImageH->GetPixel(xi3, yi3, tempColor);
			return (GetRValue(tempColor)*rdPtr->rThickness)>>8;
		} //else MessageBox(0,"Step 0 (transparent)","Mode 7 Debug",MB_OK);
	}
	return 0;
}
long WINAPI DLLExport Exp_GetFog(LPRDATA rdPtr,long param1) {
	return rdPtr->rFog;
}
long WINAPI DLLExport Exp_GetFogRed(LPRDATA rdPtr,long param1) {
	return GetRValue(rdPtr->rFogColor);
}
long WINAPI DLLExport Exp_GetFogGreen(LPRDATA rdPtr,long param1) {
	return GetGValue(rdPtr->rFogColor);
}
long WINAPI DLLExport Exp_GetFogBlue(LPRDATA rdPtr,long param1) {
	return GetBValue(rdPtr->rFogColor);
}
long WINAPI DLLExport Exp_GetFogDistance(LPRDATA rdPtr,long param1) {
	return rdPtr->rFogDistance;
}
long WINAPI DLLExport Exp_GetXOffset2(LPRDATA rdPtr,long param1) {
	return (int)rdPtr->rXOffset2;
}
long WINAPI DLLExport Exp_GetYOffset2(LPRDATA rdPtr,long param1) {
	return (int)rdPtr->rYOffset2;
}
long WINAPI DLLExport Exp_GetAngle2(LPRDATA rdPtr,long param1) {
	return rdPtr->rAngle2;
}
long WINAPI DLLExport Exp_GetThicknessMode(LPRDATA rdPtr,long param1) {
	return rdPtr->rThicknessMode;
}
long WINAPI DLLExport Exp_GetInterpolation(LPRDATA rdPtr,long param1) {
	return rdPtr->rInterpolate;
}
long WINAPI DLLExport Exp_GetHeightInterpolation(LPRDATA rdPtr,long param1) {
	return rdPtr->rInterpolateHeight;
}

long WINAPI DLLExport Exp_GetMipMap(LPRDATA rdPtr,long param1) {
	return rdPtr->rMipmap;
}
long WINAPI DLLExport Exp_GetMipMap2(LPRDATA rdPtr,long param1) {
	return rdPtr->rMipmap2;
}
long WINAPI DLLExport Exp_GetMipMapH(LPRDATA rdPtr,long param1) {
	return rdPtr->rMipmapH;
}
long WINAPI DLLExport Exp_GetAutoRedraw(LPRDATA rdPtr,long param1) {
	return rdPtr->rAutoRedraw;
}




long WINAPI DLLExport Exp_GetMapWidth(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long w = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long h = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;
	
	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;

	double y1 = rdPtr->rElevation/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/(rdPtr->rElevation/y1))+xoff;
	double x2 = ((-rdPtr->rHo.hoImgWidth*(xx+w))/(rdPtr->rElevation/y1))+xoff;

	return abs((int)(x1-x2));
}
long WINAPI DLLExport Exp_GetMapHeight(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long w = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long h = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;
	
	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;

	double y1 = rdPtr->rElevation/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/(rdPtr->rElevation/y1))+xoff;
	double x2 = ((-rdPtr->rHo.hoImgWidth*(xx+w))/(rdPtr->rElevation/y1))+xoff;

	return abs((int)((x1-x2)*h/w));
}

long WINAPI DLLExport Exp_GetMapVisible(LPRDATA rdPtr,long param1)
{
	long p1 = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long w = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	long h = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);


	//float fp1 = *(float *)&p1;
	//float fp2 = *(float *)&p2;

	double x = p1*100/rdPtr->rZoom-rdPtr->rXOffset;
	double y = p2*100/rdPtr->rZoom-rdPtr->rYOffset;

	int xoff=rdPtr->rHo.hoImgWidth>>1;
	double dtr = 3.1415926535897932384626433832795 / 180;

	double zcos=cos(-rdPtr->rAngle * dtr);
	double zsin=sin(-rdPtr->rAngle * dtr);
	double xx = zcos*x-zsin*y;
	double yy = zsin*x+zcos*y;


	double y1 = rdPtr->rElevation/yy;
	double x1 = ((-rdPtr->rHo.hoImgWidth*xx)/(rdPtr->rElevation/y1))+xoff;
	double x2 = ((-rdPtr->rHo.hoImgWidth*(xx+w))/(rdPtr->rElevation/y1))+xoff;


	int zw = abs((int)(x1-x2));
	int zh = abs((int)((x1-x2)*h/w));
	zw>>=1;
	zh>>=1;

	return (long)((	(x1 >= -zw) &&
					(x1 <= rdPtr->rHo.hoImgWidth + zw) &&
					(y1 >= -zh) &&
					(y1 <= rdPtr->rHo.hoImgHeight)
					) ? 1 : 0);
}





// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			0
			};

short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			Act_Show,
			Act_Hide,
			Act_TransOn,
			Act_TransOff,
			Act_LoadImage,
			Act_SetWidth,
			Act_SetHeight,
			Act_SetTilt,
			Act_SetAngle,
			Act_SetRoll,
			Act_SetXOffset,
			Act_SetElevation,
			Act_SetYOffset,
			Act_SetXCenter,
			Act_SetYCenter,
			Act_SetVanish,
			Act_SetZoom,
			Act_Redraw,
			Act_AdjustAngle,
			Act_AdjustXOffset,
			Act_AdjustYOffset,
			Act_AdjustElevation,
			Act_WalkForward,
			Act_WalkBack,
			Act_WalkLeft,
			Act_WalkRight,
			Act_WrapXOn,
			Act_WrapXOff,
			Act_WrapYOn,
			Act_WrapYOff,
			Act_SetResolution,
			Act_SetResolutionMode,
			Act_SetThickness,
			Act_AdjustTilt,
			Act_AdjustRoll,
			Act_SetXResolution,
			Act_SetYResolution,
			Act_LoadImageNumber,
			Act_LoadImageName,
			Act_LoadImage2,
			Act_LoadImage2Number,
			Act_LoadImage2Name,
			Act_LoadImageH,
			Act_LoadImageHNumber,
			Act_LoadImageHName,
			Act_UnloadImage2,
			Act_UnloadImageH,
			Act_FogOn,
			Act_FogOff,
			Act_ChooseFogColor,
			Act_SetFogColor,
			Act_SetFogRed,
			Act_SetFogGreen,
			Act_SetFogBlue,
			Act_SetFogDistance,
			Act_SetXOffset2,
			Act_SetYOffset2,
			Act_AdjustXOffset2,
			Act_AdjustYOffset2,
			Act_SetAngle2,
			Act_AdjustAngle2,
			Act_SetThicknessMode,
			Act_InterpolationOn,
			Act_InterpolationOff,
			Act_HeightInterpolationOn,
			Act_HeightInterpolationOff,
			Act_MipMapOn,
			Act_MipMapOff,
			Act_MipMap2On,
			Act_MipMap2Off,
			Act_MipMapHOn,
			Act_MipMapHOff,
			Act_AutoRedrawOn,
			Act_AutoRedrawOff,
			Act_SetMipTrans,
			Act_MipTransOff,
			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) =
			{
			Exp_GetWidth,
			Exp_GetHeight,
			Exp_GetImageWidth,
			Exp_GetImageHeight,
			Exp_GetFile,
			Exp_GetTrans,
			Exp_GetShow,
			Exp_GetTilt,
			Exp_GetAngle,
			Exp_GetRoll,
			Exp_GetXOffset,
			Exp_GetElevation,
			Exp_GetYOffset,
			Exp_GetXCenter,
			Exp_GetYCenter,
			Exp_GetVanish,
			Exp_GetZoom,
			Exp_GetWrapX,
			Exp_GetWrapY,
			Exp_GetMapX,
			Exp_GetMapY,
			Exp_GetMapXZ,
			Exp_GetMapYZ,
			Exp_GetMapWidth,
			Exp_GetMapHeight,
			Exp_GetMapWidthZ,
			Exp_GetMapHeightZ,
			Exp_GetMapAngle,
			Exp_GetMapVisible,
			Exp_GetResolutionX,
			Exp_GetResolutionY,
			Exp_GetResolutionMode,
			Exp_GetResolutionModeParam,
			Exp_GetThickness,
			Exp_GetImageNumber,
			Exp_GetImage2Width,
			Exp_GetImage2Height,
			Exp_GetImage2Number,
			Exp_GetImage2File,
			Exp_GetImageHWidth,
			Exp_GetImageHHeight,
			Exp_GetImageHNumber,
			Exp_GetImageHFile,
			Exp_GetHeightAt,
			Exp_GetFog,
			Exp_GetFogRed,
			Exp_GetFogGreen,
			Exp_GetFogBlue,
			Exp_GetFogDistance,
			Exp_GetXOffset2,
			Exp_GetYOffset2,
			Exp_GetAngle2,
			Exp_GetThicknessMode,
			Exp_GetInterpolation,
			Exp_GetHeightInterpolation,
			Exp_GetMipMap,
			Exp_GetMipMap2,
			Exp_GetMipMapH,			
			Exp_GetAutoRedraw,

			0
			};