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

	DEBUGMSG("CreateRunObject() Init");

	fpry    ryPtr;
	fprh    rhPtr;
 	rhPtr = rdPtr->rHo.hoAdRunHeader;
  	ryPtr = (fpry)((fpchar)rhPtr + rhPtr->rhyOffset);

	// Set up parameters
	rdPtr->rHo.hoX = cobPtr->cobX;
	rdPtr->rHo.hoY = cobPtr->cobY;
	rdPtr->rHo.hoImgWidth = edPtr->swidth;
	rdPtr->rHo.hoImgHeight = edPtr->sheight;
	rdPtr->rShow = true;
	rdPtr->rTrans = edPtr->eTrans;
	rdPtr->rRepeatX = edPtr->eRepeatX;
	rdPtr->rRepeatY = edPtr->eRepeatY;
	
	rdPtr->rImageNum = -2;
	rdPtr->rImage2Num = -2;
	rdPtr->rImageHNum = -2;
	
	rdPtr->rZoom = 100;
	rdPtr->rResX = edPtr->eResX;
	rdPtr->rResY = edPtr->eResY;
	rdPtr->rResMode = rdPtr->rResMode2 = edPtr->eResMode; // Full draw mode
	rdPtr->rResModeParam = edPtr->eResModeParam;
	rdPtr->rThickness = edPtr->eThickness;
	rdPtr->rThicknessMode = edPtr->eThicknessMode; // Fill thickness mode
	rdPtr->rZoom = 100;
	rdPtr->rFog = edPtr->eFog;
	rdPtr->rFogColor = edPtr->eFogColor;
	rdPtr->rFogDistance = edPtr->eFogDistance;
	rdPtr->rMipmap = edPtr->eMipmap;
	rdPtr->rMipmap2 = edPtr->eMipmap2;
	rdPtr->rMipmapH = edPtr->eMipmapH;
	rdPtr->rAutoRedraw = edPtr->eAutoRedraw;
	rdPtr->rNeedRedraw = true;
	rdPtr->rInterpolate = edPtr->eInterpolate;
	rdPtr->rInterpolateHeight = edPtr->eInterpolateHeight;
		
	rdPtr->rElevation = 5000;
		
	rdPtr->rImageWidth=0;
	rdPtr->rImageHeight=0;
	rdPtr->rImage2Width=0;
	rdPtr->rImage2Height=0;
	rdPtr->rImageHWidth=0;
	rdPtr->rImageHHeight=0;

		
	// Internal image transfer

	rdPtr->rNImages = edPtr->eNImages;
	if ( edPtr->eNImages != 0 )
		memcpy((LPBYTE)rdPtr+sizeof(RUNDATA), (LPBYTE)edPtr+sizeof(EDITDATA), edPtr->eNImages * sizeof(internalImage));


	// Get playfield surface as prototype and create image surface
	LPSURFACE wSurf = WinGetSurface((int)rhPtr->rhIdEditWin);
	rdPtr->rSf = NULL;
	rdPtr->rImage = NULL;
	//if ( wSurf != NULL ) {}
	LPSURFACE pProto = NULL;
	if (GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DDRAW)||GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DIB)) {
		// OK
		rdPtr->rSf = new cSurface;
		rdPtr->rSf->Create(edPtr->swidth, edPtr->sheight, pProto);
		if (!rdPtr->rSf->IsValid()) {
			GetSurfacePrototype(&pProto, 24, ST_MEMORYWITHDC, SD_DIB);
			rdPtr->rSf->Create(edPtr->swidth, edPtr->sheight, pProto);
		}
		if (wSurf != NULL) {
			if ((rdPtr->rImage = new cSurface) != NULL)
				rdPtr->rImage->Create(1, 1, wSurf);

			if ((rdPtr->rImage2 = new cSurface) != NULL)
				rdPtr->rImage2->Create(1, 1, wSurf);

			if ((rdPtr->rImageH = new cSurface) != NULL)
				rdPtr->rImageH->Create(1, 1, wSurf);
		}
	}
	
	if (rdPtr->rSf != NULL && !rdPtr->rSf->IsValid()) {
		DEBUGMSG("rSf is NOT valid (deleting)!");
		delete rdPtr->rSf;
	}
	if (rdPtr->rImage != NULL && !rdPtr->rImage->IsValid()) {
		DEBUGMSG("rImage is NOT valid (deleting)!");
		delete rdPtr->rImage;
	}
	if (rdPtr->rImage2 != NULL && !rdPtr->rImage2->IsValid()) {
		DEBUGMSG("rImage2 is NOT valid (deleting)!");
		delete rdPtr->rImage2;
	}
	if (rdPtr->rImageH != NULL && !rdPtr->rImageH->IsValid()) {
		DEBUGMSG("rImageH is NOT valid (deleting)!");
		delete rdPtr->rImageH;
	}
	

/* alternative engine
	rdPtr->pBits;
	rdPtr->wb = ((edPtr->swidth*25/8 + 3) & ~3);
	rdPtr->adDib = new BYTE[rdPtr->rSf->GetDIBSize()];

	rdPtr->pBits = rdPtr->adDib + sizeof(BITMAPINFOHEADER);
	rdPtr->rSf->SaveImage ((LPBITMAPINFO)(rdPtr->adDib), rdPtr->pBits, SI_NONE);
*/
	if (rdPtr->rSf == NULL)
		DEBUGMSG("failed to create rSf!");

	// Transfer internal image to surface...
	
	// First check we have any images
	if (rdPtr->rNImages) { 
	
		// If main image is set and is a valid id
		if (edPtr->eImageNum>=0 && edPtr->eImageNum < rdPtr->rNImages) {
			// Get internal image struct (pointer to an array) from the end of run data struct
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			// cSurface object to load internal image into
			cSurface imageSurface;
			// LockImageSurface loads in a surface check valid
			if (::LockImageSurface (rhPtr->rhIdAppli, ((LPINTERNALIMAGE)(pii+(rdPtr->rImageNum = edPtr->eImageNum)))->cImg, imageSurface, LOCKIMAGE_READBLITONLY) && 
					imageSurface.IsValid()) {
				// Create new surface from our current prototype or the imageSurface's
				rdPtr->rImage->Create(imageSurface.GetWidth(), imageSurface.GetHeight(), pProto!=NULL ? pProto : &imageSurface);
				if (rdPtr->rImage->IsValid()) {
					rdPtr->rImageWidth = rdPtr->rImage->GetWidth();
					rdPtr->rImageHeight = rdPtr->rImage->GetHeight();
					imageSurface.Blit(*rdPtr->rImage, 0, 0, BMODE_OPAQUE, BOP_COPY, 0);
				}
			}
			::UnlockImageSurface (imageSurface);
		}
		
		// If secondary image is set and is a valid id
		if (edPtr->eImage2Num>=0 && edPtr->eImage2Num < rdPtr->rNImages) {
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			cSurface imageSurface;
			if (::LockImageSurface (rhPtr->rhIdAppli, ((LPINTERNALIMAGE)(pii+(rdPtr->rImage2Num = edPtr->eImage2Num)))->cImg, imageSurface, LOCKIMAGE_READBLITONLY)&&
					imageSurface.IsValid()) {
				rdPtr->rImage2->Create(imageSurface.GetWidth(), imageSurface.GetHeight(), pProto!=NULL ? pProto : &imageSurface);
				if (rdPtr->rImage2->IsValid()) {
					imageSurface.Blit(*rdPtr->rImage2, 0, 0, BMODE_OPAQUE, BOP_COPY, 0);
					rdPtr->rImage2Width = rdPtr->rImage2->GetWidth();
					rdPtr->rImage2Height = rdPtr->rImage2->GetHeight();
				}
			}
			::UnlockImageSurface (imageSurface);
		}
		
		// If height map image is set and is a valid id
		if (edPtr->eImageHNum>=0 && edPtr->eImageHNum < rdPtr->rNImages) {
			LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)rdPtr + sizeof(RUNDATA));
			cSurface imageSurface;
			if (::LockImageSurface (rhPtr->rhIdAppli, ((LPINTERNALIMAGE)(pii+(rdPtr->rImageHNum = edPtr->eImageHNum)))->cImg, imageSurface, LOCKIMAGE_READBLITONLY) &&
					imageSurface.IsValid()) {
				rdPtr->rImageH->Create(imageSurface.GetWidth(), imageSurface.GetHeight(), pProto!=NULL ? pProto : &imageSurface);
				if (rdPtr->rImageH->IsValid()) {
					imageSurface.Blit(*rdPtr->rImageH, 0, 0, BMODE_OPAQUE, BOP_COPY, 0);
					rdPtr->rImageHWidth = rdPtr->rImageH->GetWidth();
					rdPtr->rImageHHeight = rdPtr->rImageH->GetHeight();
				}
			}
			::UnlockImageSurface (imageSurface);
		}
	}


	if (edPtr->eAutoCamera) {
		rdPtr->rAngle = 180;
		rdPtr->rXOffset = rdPtr->rImageWidth >> 1;
		rdPtr->rYOffset = rdPtr->rImageHeight + rdPtr->rImageWidth;
	} else {
		rdPtr->rAngle = 0;
		rdPtr->rXOffset = 0;
		rdPtr->rYOffset = 0;
	}

	for (int i=12; --i>=0;) {
		rdPtr->rMipmaps[i]=new cSurface;
		rdPtr->rMipmaps2[i]=new cSurface;
		rdPtr->rMipmapsH[i]=new cSurface;
	}


	if (edPtr->eMipTrans) {
		rdPtr->rMipTrans = rdPtr->rMipTrans2 = edPtr->eMipTransColor;
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
	} else
		rdPtr->rMipTrans = 0;
		
	UpdateMipMaps(rdPtr);
	UpdateMipMaps2(rdPtr);
	UpdateMipMapsH(rdPtr);
	
	// Store dimensions
	rdPtr->rHo.hoImgWidth = edPtr->swidth;
	rdPtr->rHo.hoImgHeight = edPtr->sheight;


	DEBUGMSG("CreateRunObject() DONE");
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
	DEBUGMSG("DestroyRunObject() INIT");

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
	
	DEBUGMSG("DestroyRunObject() DONE");
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

