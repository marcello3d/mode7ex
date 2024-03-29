// Object identifier "M7X1"
//#pragma message ("Do not forget to change the IDENTIFIER! Remove this message when it's done!")
#define IDENTIFIER	0x4D375831

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_LAST					0

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_ACTION_SHOW							0
#define	ACT_ACTION_HIDE							1
#define	ACT_ACTION_TRANS_ON						2
#define	ACT_ACTION_TRANS_OFF					3
#define	ACT_ACTION_LOAD_IMAGE					4
#define	ACT_ACTION_SET_WIDTH					5
#define	ACT_ACTION_SET_HEIGHT					6
#define	ACT_ACTION_SET_TILT						7
#define	ACT_ACTION_SET_ANGLE					8
#define ACT_ACTION_SET_ROLL						9
#define	ACT_ACTION_SET_XOFFSET					10
#define ACT_ACTION_SET_ELEVATION				11
#define	ACT_ACTION_SET_YOFFSET					12
#define	ACT_ACTION_SET_XCENTER					13
#define	ACT_ACTION_SET_YCENTER					14
#define	ACT_ACTION_SET_VANISH					15
#define ACT_ACTION_SET_ZOOM						16
#define	ACT_ACTION_REDRAW						17
#define ACT_ACTION_ADJUST_ANGLE					18
#define ACT_ACTION_ADJUST_XOFFSET				19
#define ACT_ACTION_ADJUST_YOFFSET				20
#define ACT_ACTION_ADJUST_ELEVATION				21
#define ACT_ACTION_WALK_FORWARD					22
#define ACT_ACTION_WALK_BACK					23
#define ACT_ACTION_WALK_LEFT					24
#define ACT_ACTION_WALK_RIGHT					25
#define ACT_ACTION_WRAPX_ON						26
#define ACT_ACTION_WRAPX_OFF					27
#define ACT_ACTION_WRAPY_ON						28
#define ACT_ACTION_WRAPY_OFF					29
#define ACT_ACTION_SET_RES						30
#define ACT_ACTION_SET_RESMODE					31
#define ACT_ACTION_SET_THICK					32
#define ACT_ACTION_ADJUST_TILT					33
#define ACT_ACTION_ADJUST_ROLL					34
#define ACT_ACTION_SET_XRES						35
#define ACT_ACTION_SET_YRES						36
#define ACT_ACTION_LOAD_IMAGENUM				37
#define ACT_ACTION_LOAD_IMAGENAME				38
#define ACT_ACTION_LOAD_IMAGE2					39
#define ACT_ACTION_LOAD_IMAGE2NUM				40
#define ACT_ACTION_LOAD_IMAGE2NAME				41
#define ACT_ACTION_LOAD_IMAGEH					42
#define ACT_ACTION_LOAD_IMAGEHNUM				43
#define ACT_ACTION_LOAD_IMAGEHNAME				44
#define ACT_ACTION_UNLOAD_IMAGE2				45
#define ACT_ACTION_UNLOAD_IMAGEH				46
#define ACT_ACTION_FOG_ON						47
#define ACT_ACTION_FOG_OFF						48
#define ACT_ACTION_CHOOSEFOGCOLOR				49
#define ACT_ACTION_SETFOGCOLOR					50
#define ACT_ACTION_SETFOGRED					51
#define ACT_ACTION_SETFOGGREEN					52
#define ACT_ACTION_SETFOGBLUE					53
#define ACT_ACTION_SETFOGDISTANCE				54
#define ACT_ACTION_SET_XOFFSET2					55
#define ACT_ACTION_SET_YOFFSET2					56
#define ACT_ACTION_ADJUST_XOFFSET2				57
#define ACT_ACTION_ADJUST_YOFFSET2				58
#define ACT_ACTION_SET_ANGLE2					59
#define ACT_ACTION_ADJUST_ANGLE2				60
#define	ACT_ACTION_SET_THICKNESSMODE			61
#define ACT_ACTION_INTERPOL_ON					62
#define ACT_ACTION_INTERPOL_OFF					63
#define ACT_ACTION_HINTERPOL_ON					64
#define	ACT_ACTION_HINTERPOL_OFF				65
#define ACT_ACTION_MIPMAP_ON					66
#define	ACT_ACTION_MIPMAP_OFF					67
#define ACT_ACTION_MIPMAP2_ON					68
#define ACT_ACTION_MIPMAP2_OFF					69
#define ACT_ACTION_MIPMAPH_ON					70
#define	ACT_ACTION_MIPMAPH_OFF					71
#define ACT_ACTION_AUTOREDRAW_ON       			72
#define ACT_ACTION_AUTOREDRAW_OFF      			73
#define ACT_ACTION_MIPMAP_TRANS        			74
#define ACT_ACTION_MIPMAP_TRANS_OFF    			75
#define	ACT_LAST								76

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define EXP_GET_WIDTH							0
#define	EXP_GET_HEIGHT							1
#define	EXP_GET_IMAGE_WIDTH						2
#define	EXP_GET_IMAGE_HEIGHT					3
#define	EXP_GET_FILE							4
#define	EXP_GET_TRANS							5
#define	EXP_GET_SHOW							6
#define	EXP_GET_TILT							7
#define	EXP_GET_ANGLE							8
#define EXP_GET_ROLL							9
#define	EXP_GET_XOFFSET							10
#define EXP_GET_ELEVATION						11
#define	EXP_GET_YOFFSET							12
#define	EXP_GET_XCENTER							13
#define	EXP_GET_YCENTER							14
#define	EXP_GET_VANISH							15
#define EXP_GET_ZOOM							16
#define EXP_GET_WRAPX							17
#define EXP_GET_WRAPY							18
#define EXP_GET_MAPX							19
#define EXP_GET_MAPY							20
#define EXP_GET_MAPXZ							21
#define EXP_GET_MAPYZ							22
#define EXP_GET_MAPWIDTH						23
#define EXP_GET_MAPHEIGHT						24
#define EXP_GET_MAPWIDTHZ						25
#define EXP_GET_MAPHEIGHTZ						26
#define EXP_GET_MAPANGLE						27
#define EXP_GET_MAPVISIBLE						28
#define EXP_GET_RESX							29
#define EXP_GET_RESY							30
#define EXP_GET_RESMODE							31
#define EXP_GET_RESMODEPARAM					32
#define EXP_GET_THICK							33
#define EXP_GET_IMAGE_NUM						34
#define EXP_GET_IMAGE2_WIDTH					35
#define EXP_GET_IMAGE2_HEIGHT					36
#define EXP_GET_IMAGE2_NUM						37
#define EXP_GET_IMAGE2_FILE						38
#define EXP_GET_IMAGEH_WIDTH					39
#define EXP_GET_IMAGEH_HEIGHT					40
#define EXP_GET_IMAGEH_NUM						41
#define EXP_GET_IMAGEH_FILE						42
#define EXP_GET_IMAGE_HEIGHT_AT					43
#define EXP_GET_FOG								44
#define EXP_GET_FOGRED							45
#define EXP_GET_FOGGREEN						46
#define EXP_GET_FOGBLUE							47
#define EXP_GET_FOGDISTANCE						48
#define EXP_GET_XOFFSET2						49
#define EXP_GET_YOFFSET2						50
#define EXP_GET_ANGLE2							51
#define	EXP_GET_THICKNESSMODE					52
#define EXP_GET_INTERPOL						53
#define	EXP_GET_HINTERPOL						54
#define	EXP_GET_MIPMAP							55
#define EXP_GET_MIPMAP2							56
#define	EXP_GET_MIPMAPH							57
#define EXP_GET_AUTOREDRAW         				58
#define EXP_GET_MAPVISIBLEZ						59
#define	EXP_LAST								60

// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------
typedef struct tagEDATA_V0
{
	extHeader		eHeader;
	short			swidth;
	short			sheight;

	// Setup option variables
	
	int				eImageNum;				// Internal Image ID
	int				eImage2Num;				// Internal Image ID
	int				eImageHNum;				// Internal Image ID


	bool			eTrans;					// Black-is-Trans mode

	bool			eRepeatX;
	bool			eRepeatY;
	bool			eFog;
	bool			eInterpolate;
	bool			eInterpolateHeight;
	bool			eMipmap;
	bool			eMipmap2;
	bool			eMipmapH;
	
	int				eResX;
	int				eResY;
	int				eResMode;
	int				eResModeParam;
	int				eThickness;
	int				eThicknessMode;
	COLORREF		eFogColor;
	int				eFogDistance;
	bool			eMipTrans;
	COLORREF		eMipTransColor;
	bool			eAutoRedraw;
	
	
	bool			eAutoCamera;

	// Internal Images
	//WORD			imgidx;

	WORD			eNImages;
	WORD			eCurrentImage;


} EDITDATA;
typedef EDITDATA _far *			LPEDATA;

#define	MAX_IMAGE_NAME		40

typedef struct internalImage {
	WORD			cImg;					// Image number
	char			cName[MAX_IMAGE_NAME];	// Name
} internalImage;
typedef internalImage _far *		LPINTERNALIMAGE;







// Object versions
#define	KCX_CURRENT_VERSION			1

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
typedef struct tagRDATA
{
	headerObject	rHo;					// Header

	// runtime settings
	rCom			rc;
	rMvt			rm;
	rSpr			rs;
	rVal			rv;

	LPSURFACE		rSf;					// Render-surface

	LPSURFACE		rImage;					// Map surface
	LPSURFACE		rImage2;				// Secondary map surface
	LPSURFACE		rImageH;				// Height map surface
	char			rImageFile[_MAX_PATH];	// Image filename
	char			rImage2File[_MAX_PATH];	// Secondary Image filename
	char			rImageHFile[_MAX_PATH];	// Height Image filename
	int				rImageNum;				// Internal Image ID
	int				rImage2Num;				// Internal Image ID
	int				rImageHNum;				// Internal Image ID

	LPSURFACE		rMipmaps[12];
	int				rNMipLevels;
	LPSURFACE		rMipmaps2[12];
	int				rNMipLevels2;
	LPSURFACE		rMipmapsH[12];
	int				rNMipLevelsH;
	
	// Mipmap transparency
	COLORREF		rMipTrans;
	COLORREF		rMipTrans2; // HACK: Due to color corruption

	// internal image handling
	WORD			rNImages;

	// original size
	int				rImageWidth;
	int				rImageHeight;
	int				rImage2Width;
	int				rImage2Height;
	int				rImageHWidth;
	int				rImageHHeight;

	// vars
	//
	//angles
	int				rTilt;
	int				rAngle;
	int				rRoll;
	// Origins
	double			rXOffset;
	double			rYOffset;
	int				rElevation;
		// secondary layer
	double			rXOffset2;
	double			rYOffset2;
	int				rAngle2;

	//extra
	int				rXCenter;
	int				rYCenter;
	float			rVanish;
	int				rZoom;
	int				rResX;
	int				rResY;
	int				rResMode;
	int				rResMode2;
	int				rResModeParam;
	int				rThickness;
	int				rThicknessMode;
	
	//Options
	bool			rTrans;
	bool			rShow;
	bool			rRepeatX;
	bool			rRepeatY;
	bool			rFog;
	bool			rInterpolate;
	bool			rInterpolateHeight;
	bool			rMipmap;
	bool			rMipmap2;
	bool			rMipmapH;
	bool			rAutoRedraw;
	
	// Redraw flag
	bool			rNeedRedraw;

	//Fog Settings
	COLORREF		rFogColor;
	int				rFogDistance;


} RUNDATA;
typedef	RUNDATA	_far *			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_INTERNALIMAGE			200
#define	MAX_EDITSIZE			(sizeof(EDITDATA) + MAX_INTERNALIMAGE*sizeof(internalImage))
//#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags
// -------------
#define	OEFLAGS      	(OEFLAG_SPRITES|OEFLAG_BACKSAVE|OEFLAG_MOVEMENTS|OEFLAG_SPRITES|OEFLAG_VALUES|OEFLAG_RUNBEFOREFADEIN)
#define	OEPREFS      	(OEPREFS_SCROLLINGINDEPENDANT|OEPREFS_INKEFFECTS|OEPREFS_GLOBAL|OEPREFS_BACKEFFECTS|OEPREFS_BACKSAVE|OEPREFS_LOADONCALL|OEPREFS_SLEEP|OEPREFS_KILL)

// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100

