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


#endif
