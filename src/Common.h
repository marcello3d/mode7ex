#ifndef COMMON_H
#define COMMON_H

#if defined(_DEBUG) && defined(WIN32)
	#define	_CRTDBG_MAP_ALLOC	1
#endif

#define	IN_KPX				1


#if (0 == DEBUG)
#define	NDEBUG				1
#endif

#define	IN_EXT_VERSION2		1
#define	RUN_TIME

#define	IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_15)

// General includes
#include	"..\inc\ccxhdr.h"
#include	"..\inc\ccx.h"
#include	"..\inc\surface.h"

// Specific to this kcx
#include	"resource.h"
#include	"main.h"

//Globals and Prototypes
extern HINSTANCE hInstLib;
extern short conditionsInfos[];
extern short actionsInfos[];
extern short expressionsInfos[];

long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2);
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2);
long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param);

void RedrawScene(LPRDATA,bool);
void UpdateMipMaps(LPRDATA);
void UpdateMipMaps2(LPRDATA);
void UpdateMipMapsH(LPRDATA);


#ifdef _DEBUG
#define DEBUGMSG(s)		MessageBox(0,s,"Mode 7 ex " VERSION_STR,MB_OK)
#else
#define DEBUGMSG(s)
#endif

#define CNC_RETURN_FLOAT(f)		float _freturn=(float)f;\
								long _lreturn;\
								memcpy((void *)&_lreturn,(void *)&_freturn,sizeof(float));\
								rdPtr->rHo.hoFlags |= HOF_FLOAT;\
								return((long)_lreturn)

//#define CNC_FLOAT_PARAM1()		*((float*)CNC_GetFloatValue(rdPtr, 0))
#define CNC_FLOAT_PARAM1()		(float)(int)param1;//*((float*)CNC_GetFloatParameter(rdPtr))

#endif
