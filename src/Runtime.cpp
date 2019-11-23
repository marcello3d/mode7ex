// ============================================================================
//
// This file contains routines that are handled during the Runtime.
//
// Including creating, display, and handling your object.
//
// ============================================================================

// Common Include
#include	"common.h"

// --------------------
// GetRunObjectDataSize
// --------------------
// Returns the size of the runtime datazone of the object
//
ushort WINAPI DLLExport GetRunObjectDataSize(fprh rhPtr, LPEDATA edPtr)
{
	return(sizeof(RUNDATA) + edPtr->eNImages * sizeof(internalImage));
}

// ---------------
// CreateRunObject
// ---------------
// The routine where the object is actually created
//
short WINAPI DLLExport CreateRunObject(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr) {

	fpry    ryPtr;
	fprh    rhPtr;
 	rhPtr = rdPtr->rHo.hoAdRunHeader;
  	ryPtr = (fpry)((fpchar)rhPtr + rhPtr->rhyOffset);

	// Set up parameters
	rdPtr->rHo.hoX = cobPtr->cobX;
	rdPtr->rHo.hoY = cobPtr->cobY;
	rdPtr->rHo.hoImgWidth = edPtr->swidth;
	rdPtr->rHo.hoImgHeight = edPtr->sheight;
	rdPtr->rTrans = edPtr->eTrans;
	rdPtr->rShow = true;
	rdPtr->rVanish = 100;
	rdPtr->rRepeat = edPtr->eRepeat;

	// Internal image transfer

	rdPtr->rNImages = edPtr->eNImages;
	if ( edPtr->eNImages != 0 )
		memcpy((LPBYTE)rdPtr+sizeof(RUNDATA), (LPBYTE)edPtr+sizeof(EDITDATA), edPtr->eNImages * sizeof(internalImage));


	// Get playfield surface as prototype and create image surface
	LPSURFACE wSurf = WinGetSurface((int)rhPtr->rhIdEditWin);
	rdPtr->rSf = NULL;
	rdPtr->rImage = NULL;
	//if ( wSurf != NULL ) {
	LPSURFACE pProto = NULL;
	if (GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DDRAW)||GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DIB)) {
		// OK
		rdPtr->rSf = new cSurface;
		rdPtr->rSf->Create(edPtr->swidth, edPtr->sheight, pProto);
		if (wSurf != NULL) {
			if ((rdPtr->rImage = new cSurface) != NULL)
				rdPtr->rImage->Create(1, 1, wSurf);
			if ((rdPtr->rImage2 = new cSurface) != NULL)
				rdPtr->rImage2->Create(1, 1, wSurf);
			if ((rdPtr->rImageH = new cSurface) != NULL)
				rdPtr->rImageH->Create(1, 1, wSurf);
		}
	}

/* alternative engine
	rdPtr->pBits;
	rdPtr->wb = ((edPtr->swidth*25/8 + 3) & ~3);
	rdPtr->adDib = new BYTE[rdPtr->rSf->GetDIBSize()];

	rdPtr->pBits = rdPtr->adDib + sizeof(BITMAPINFOHEADER);
	rdPtr->rSf->SaveImage ((LPBITMAPINFO)(rdPtr->adDib), rdPtr->pBits, SI_NONE);
*/


	// Load image into surface (remap it if 256 colors)
	if (rdPtr->rImage != NULL) {
		// Transfer internal image to surface...

		_fstrcpy(rdPtr->rImageFile, edPtr->eFilename);
		if (rdPtr->rImage->LoadImage(rdPtr->rImageFile, LI_REMAP))
			rdPtr->rImageNum = -1;
		else if (rdPtr->rNImages) {
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			cSurface imageSurface;
			::LockImageSurface (rhPtr->rhIdAppli, pii->cImg, imageSurface, LOCKIMAGE_READBLITONLY);
			rdPtr->rImage->Create(imageSurface.GetWidth(),imageSurface.GetHeight(),pProto);
			imageSurface.Blit(*rdPtr->rImage, 0, 0, BMODE_OPAQUE, BOP_COPY, 0);
			::UnlockImageSurface (imageSurface);
			rdPtr->rImageNum = 0;
		}

		rdPtr->rImageWidth = rdPtr->rImage->GetWidth();
		rdPtr->rImageHeight = rdPtr->rImage->GetHeight();
		rdPtr->rImage2Width = rdPtr->rImage2->GetWidth();
		rdPtr->rImage2Height = rdPtr->rImage2->GetHeight();
		rdPtr->rImageHWidth = rdPtr->rImageH->GetWidth();
		rdPtr->rImageHHeight = rdPtr->rImageH->GetHeight();
		rdPtr->rImage2Num = -2;
		rdPtr->rImageHNum = -2;
		rdPtr->rAngle = 180;
		rdPtr->rZoom = 100;
		rdPtr->rResX = 1;
		rdPtr->rResY = 1;
		rdPtr->rResMode = 1; // Full draw mode
		rdPtr->rResModeParam = 128;
		rdPtr->rThickness = 0;
		rdPtr->rThicknessMode = 1; // Fill thickness mode
		rdPtr->rZoom = 100;
		rdPtr->rXOffset = -rdPtr->rImageWidth / 2;
		rdPtr->rYOffset = -rdPtr->rImageHeight*2;
		rdPtr->rElevation = 5000;
		rdPtr->rFog = 0;
		rdPtr->rFogColor = RGB(0,0,0);
		rdPtr->rFogDistance = 1000;
		rdPtr->rMipmap = true;
		rdPtr->rMipmap2 = true;
		rdPtr->rMipmapH = false;
		rdPtr->rAutoRedraw = true;
		rdPtr->rNeedRedraw = false;
		rdPtr->rMipTrans = 0;
		
		
		for (int i=12; --i>=0;) {
			rdPtr->rMipmaps[i]=new cSurface;
			rdPtr->rMipmaps2[i]=new cSurface;
			rdPtr->rMipmapsH[i]=new cSurface;
		}
		UpdateMipMaps(rdPtr);
		UpdateMipMaps2(rdPtr);
		UpdateMipMapsH(rdPtr);
		// Store dimensions
		rdPtr->rHo.hoImgWidth = rdPtr->rSf->GetWidth();
		rdPtr->rHo.hoImgHeight = rdPtr->rSf->GetHeight();

		if (rdPtr->rSf != NULL)
			RedrawScene(rdPtr,0);
	}

	// No errors
	return 0;
}


// ----------------
// DestroyRunObject
// ----------------
// Destroys the run-time object
//
short WINAPI DLLExport DestroyRunObject(LPRDATA rdPtr, long fast)
{

	// Delete image surface
	if (rdPtr->rSf != NULL)
		delete rdPtr->rSf;
	if (rdPtr->rImage != NULL)
		delete rdPtr->rImage;
	if (rdPtr->rImage2 != NULL)
		delete rdPtr->rImage2;
	if (rdPtr->rImageH != NULL)
		delete rdPtr->rImageH;
	for (int i=12; --i>=0;) {
		if (rdPtr->rMipmaps[i]!=NULL) 
			delete rdPtr->rMipmaps[i];
		if (rdPtr->rMipmaps2[i]!=NULL) 
			delete rdPtr->rMipmaps2[i];
		if (rdPtr->rMipmapsH[i]!=NULL) 
			delete rdPtr->rMipmapsH[i];
	}

	callRunTimeFunction(rdPtr, RFUNCTION_REDISPLAY, 0, 0);

	// No errors
	return 0;
}


// ----------------
// HandleRunObject
// ----------------
// Called (if you want) each loop, this routine makes the object live
//
short WINAPI DLLExport HandleRunObject(LPRDATA rdPtr)
{
	// Will be called next loop, and needs to refresh display
	return REFLAG_DISPLAY;
}


#define MASK7Bit 0xFEFEFF  // mask for additive/subtractive shading
// Add ink effect
COLORREF CALLBACK BlitAddProc (COLORREF dest, COLORREF src, DWORD lUserParam) {
	//MessageBox(0,"BlitAddProc","Pic Object",MB_OK);
	COLORREF pixel= (dest&MASK7Bit) + (src&MASK7Bit);
	COLORREF overflow=pixel&0x1010100;
	overflow=overflow-(overflow>>8);
	return overflow|pixel;
}
COLORREF CALLBACK BlitRedProc (COLORREF dest, COLORREF src, DWORD lUserParam)
{
	//MessageBox(0,"BlitRedProc","Pic Object",MB_OK);
	return (src & lUserParam);
}

// ----------------
// DisplayRunObject
// ----------------
// Draw the object in the application screen.
//
short WINAPI DLLExport DisplayRunObject(LPRDATA rdPtr)
{

	fprh rhPtr = rdPtr->rHo.hoAdRunHeader;
	// Get playfield surface
	LPSURFACE pSf = WinGetSurface((int)rhPtr->rhIdEditWin);

	if (pSf != NULL && rdPtr->rSf != NULL) {
		RECT	rc;
		int x = rc.left = rdPtr->rHo.hoX - rhPtr->rhWindowX;
		int y = rc.top = rdPtr->rHo.hoY - rhPtr->rhWindowY;
		int w = rdPtr->rHo.hoImgWidth;
		int h = rdPtr->rHo.hoImgHeight;
		rc.right = x + w;
		rc.bottom = y + h;
		if (rdPtr->rNeedRedraw)
			RedrawScene(rdPtr,0);

		// Blit image surface to playfield surface
		rdPtr->rSf->BeginRaster();
		//rdPtr->rSf->FilterBlit	(*pSf, x, y+h,   0, 0, w, h, BMODE_TRANSP, (FILTERBLITPROC)BlitAddProc, 0xff);
		//rdPtr->rSf->FilterBlit	(*pSf, x, y+h*2, 0, 0, w, h, BMODE_TRANSP, (FILTERBLITPROC)BlitRedProc, 0xff);
		//rdPtr->rSf->Blit		(*pSf, x, y+h*3, 0, 0, w, h, rdPtr->rTrans?BMODE_TRANSP:BMODE_OPAQUE, (BlitOp)rdPtr->rs.rsEffect, rdPtr->rs.rsEffectParam);
		rdPtr->rSf->Blit		(*pSf, x, y,     0, 0, w, h, rdPtr->rTrans?BMODE_TRANSP:BMODE_OPAQUE, (BlitOp)rdPtr->rs.rsEffect, rdPtr->rs.rsEffectParam);
		rdPtr->rSf->EndRaster();

		WinAddZone(rhPtr->rhIdEditWin, &rc);
	}
	// Ok
	return 0;
}

// ----------------
// PauseRunObject
// ----------------
// Enters the pause mode
//
short WINAPI DLLExport PauseRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}


// -----------------
// ContinueRunObject
// -----------------
// Quits the pause mode
//
short WINAPI DLLExport ContinueRunObject(LPRDATA rdPtr)
{
	// Ok
	return 0;
}

