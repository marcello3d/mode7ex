// ============================================================================
//
// This file contains routines that are handled during the Edittime.
//
// Including creation, display, and setup.
//
// ============================================================================

#ifndef RUN_ONLY

// Common
#include	"common.h"
#include	<commctrl.h>

// Prototype of setup procedure
BOOL CALLBACK DLLExport setupProc(HWND hDlg,uint msgType,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK DLLExport advsetupProc(HWND hDlg,uint msgType,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK DLLExport aboutProc(HWND hDlg,uint msgType,WPARAM wParam,LPARAM lParam);

// Prototype for functions...
LPBITMAPINFO CreateBitmapFromImage(npAppli, LPINTERNALIMAGE);

// Structure defined to pass edptr and mv into setup box
typedef struct tagSetP
{
	mv _far	*		kv;
	HFRAN			hFran;
	EDITDATA _far *	edpt;
	EDITDATA 		edPtr;
	//WORD			nCurrentImage;
	//WORD			nImages;
	internalImage	ci[MAX_INTERNALIMAGE];
} setupParams;
// Structure defined to pass edptr and mv into advsetup box
typedef struct tagSetP2
{
	mv _far	*		kv;
	HFRAN			hFran;
	EDITDATA 		edPtr;
	setupParams	_far * spa;
} setupParams2;

// -----------------
// BmpToImg
// -----------------
// Converts an image from the resource to an image displayable under CC&C
// Not used in this template, but it is a good example on how to create
// an image.
WORD BmpToImg(int bmID, npAppli idApp) {
	Img					ifo;
	WORD				img;
	HRSRC				hs;
	HGLOBAL				hgBuf;
	LPBYTE				adBuf;
	LPBITMAPINFOHEADER	adBmi;

	img = 0;
	if ((hs = FindResource(hInstLib, MAKEINTRESOURCE(bmID), RT_BITMAP)) != NULL)
	{
		if ((hgBuf = LoadResource(hInstLib, hs)) != NULL)
		{
			if ((adBuf = (LPBYTE)LockResource(hgBuf)) != NULL)
			{
				adBmi = (LPBITMAPINFOHEADER)adBuf;
				ifo.imgXSpot = ifo.imgYSpot = ifo.imgXAction = ifo.imgYAction = 0;
				if (adBmi->biBitCount > 4)
					RemapDib((LPBITMAPINFO)adBmi, idApp, NULL);
				img = DibToImage(idApp, &ifo, adBmi);
				UnlockResource(hgBuf);
			}
			FreeResource(hgBuf);
		}
	}
	return img;
}
WORD LoadBmpToImg(LPSTR str, npAppli idApp) {
	Img					ifo;
	WORD				img;
	//HRSRC				hs;
	//HGLOBAL				hgBuf;
	LPBYTE				adBuf;
	LPBITMAPINFOHEADER	adBmi;

	img = 0;
	//if ((hs = FindResource(hInstLib, MAKEINTRESOURCE(bmID), RT_BITMAP)) != NULL)
	//{
	//	if ((hgBuf = LoadResource(hInstLib, hs)) != NULL)
	//	{
	//		if ((adBuf = (LPBYTE)LockResource(hgBuf)) != NULL)
			if ((adBuf = (LPBYTE)LoadImage(hInstLib,str,IMAGE_BITMAP,0,0,LR_LOADFROMFILE)) != NULL)
			{
				adBmi = (LPBITMAPINFOHEADER)adBuf;
				ifo.imgXSpot = ifo.imgYSpot = ifo.imgXAction = ifo.imgYAction = 0;
				if (adBmi->biBitCount > 4)
					RemapDib((LPBITMAPINFO)adBmi, idApp, NULL);
				img = DibToImage(idApp, &ifo, adBmi);
	//			UnlockResource(hgBuf);
			}
	//		FreeResource(hgBuf);
	//	}
	//}
	return img;
}


// -----------------
// CreateBitmapFromImage
// -----------------
// Creates a bitmap from an internal image.  (Modified from Cursor Object)

LPBITMAPINFO CreateBitmapFromImage(npAppli idApp, LPINTERNALIMAGE pii) {
	LPBITMAPINFO	pDest = NULL;
	LPBITMAPINFO	adDib;
	HGLOBAL			hg;
	BOOL			bOK = FALSE;

	// Check parameters
	if ( idApp == NULL || pii == NULL || pii->cImg == 0)
		return FALSE;

	// 1. Create 24-bit DIB from image
	DWORD lsize = ImageToDib (idApp, pii->cImg, SM_24, NULL);
	if ( lsize != 0 && (hg = GlobalAlloc (GHND, lsize)) != NULL ) {
		adDib = (LPBITMAPINFO) GlobalLock (hg);
		ImageToDib (idApp, pii->cImg, SM_24, (LPBYTE)adDib);

		// 2. Create 24 bit 3 colors DIB from bitmap
		int		cxCursor = adDib->bmiHeader.biWidth;
		int		cyCursor = adDib->bmiHeader.biHeight;
		int		destWidthBytes = ((cxCursor * 3 + 3) & ~3);

		pDest = (LPBITMAPINFO)_fmalloc(sizeof(BITMAPINFOHEADER) + destWidthBytes * cyCursor);
		if ( pDest != NULL ) {
			_fmemcpy(pDest, adDib, sizeof(BITMAPINFOHEADER));
			pDest->bmiHeader.biWidth = cxCursor;
			pDest->bmiHeader.biHeight = cyCursor;

			int		dibWidthBytes = ((adDib->bmiHeader.biWidth * 3 + 3) & ~3);
			LPBYTE	pbase = (LPBYTE)adDib + sizeof(BITMAPINFOHEADER);
			LPBYTE	p;
			LPBYTE	pDestbase = (LPBYTE)pDest + sizeof(BITMAPINFOHEADER);
			LPBYTE	pdst;

			COLORREF trsp = GetSysColor(COLOR_3DFACE);
			BYTE	rt = GetRValue(trsp);
			BYTE	gt = GetGValue(trsp);
			BYTE	bt = GetBValue(trsp);

			for (int y=0; y<cyCursor; y++) {
				p = pbase;
				pbase += dibWidthBytes;
				pdst = pDestbase;
				pDestbase += destWidthBytes;

				for (int x=0; x<cxCursor; x++) {
					if ( *p == 0 && *(p+1) == 0 && *(p+2) == 0 ) {
						*pdst++ = bt;
						*pdst++ = gt;
						*pdst++ = rt;
						p += 3;
					} else {
						*pdst++ = *p++;
						*pdst++ = *p++;
						*pdst++ = *p++;
					}
				}
			}
		}
		GlobalUnlock(hg);
		GlobalFree(hg);
	}
	return pDest;
}


// -----------------
// Initialize
// -----------------
// Where you want to do COLD-START initialization. Only called ONCE per application.
//
int WINAPI DLLExport Initialize(mv _far *knpV, int quiet)
{
	// No errors
	return 0;
}

// -----------------
// Free
// -----------------
// Where you want to kill and initialized data opened in the above routine
// Called ONCE per application, just before freeing the DLL.
//
int WINAPI DLLExport Free(mv _far *knpV)
{
	// No errors
	return 0;
}

// --------------------
// UpdateEditStructure
// --------------------
// For you to update your object structure to newer versions
//
HGLOBAL WINAPI DLLExport UpdateEditStructure(mv __far *knpV, void __far * OldEdPtr)
{
	// We do nothing here
	return 0;
}

// -----------------
// LoadObject
// -----------------
// Routine called for each object, when the object is dropped in the frame.
// You can load data here, reserve memory etc...
// Called once per different object, just after loading extension data
int	WINAPI DLLExport LoadObject(mv _far *knpV, LPCSTR fileName, LPEDATA edPtr, int reserved) {
	return 0;
}

// -----------------
// UnloadObject
// -----------------
// The counterpart of the above routine: called just before the object is
// deleted from the frame
void WINAPI DLLExport UnloadObject(mv _far *knpV, LPEDATA edPtr, int reserved)
{
}

// --------------------
// UpdateFileNames
// --------------------
// If you store file names in your datazone, they have to be relocated when the
// application is moved: this routine does it.
//
void WINAPI DLLExport UpdateFileNames(mv _far *knpV, LPSTR gameName, LPEDATA edPtr, void (WINAPI * lpfnUpdate)(LPSTR, LPSTR))
{
	// Call MMF so that it relocates the pathname
	//if ( edPtr->eFilename[0]!=0 )
	//	lpfnUpdate (gameName, edPtr->eFilename);
}

// --------------------
// PutObject
// --------------------
// Called when each individual object is dropped in the frame.
//
void WINAPI	DLLExport PutObject(mv _far *knpV, fpLevObj loPtr, LPEDATA edPtr, ushort cpt)
{
#ifdef RUN_ONLY2
	MessageBox(0,"You are not supposed to be using this version!","Mode 7 Error!",MB_OK);
	loPtr->loOiNum = 0;			// Protection!!!!!!!!!!! Cannot use run-only extensions in editor!
#endif
}

// --------------------
// RemoveObject
// --------------------
// Called when each individual object is removed in the frame.
//
void WINAPI	DLLExport RemoveObject(mv _far *knpV, fpLevObj loPtr, LPEDATA edPtr, ushort cpt)
{
	// Is the last object removed?
    if (0 == cpt)
	{
		// Do whatever necessary to remove our data

	}

}

// --------------------
// MakeIcon
// --------------------
// Called once object is created or modified, just after setup.
//
int WINAPI DLLExport MakeIcon ( mv _far *knpV, BITMAPINFO FAR *lpBitmap, LPSTR lpName, fpObjInfo oiPtr, LPEDATA edPtr )
{
	int					error = -1;
	ushort				pSize, bSize;
	HRSRC				hs;
	HGLOBAL				hgBuf;
	LPBYTE				adBuf;
	LPBITMAPINFOHEADER	adBmi;

	// Here, we simply load the icon from the resource and convert it into a format understood by CC&C.
	// You could also generate the icon yourself from what the user has entered in the setup.
	if ((hs = FindResource(hInstLib, MAKEINTRESOURCE(EXO_ICON), RT_BITMAP)) != NULL)
	{
		if ((hgBuf = LoadResource(hInstLib, hs)) != NULL)
		{
			if ((adBuf = (LPBYTE)LockResource(hgBuf)) != NULL)
			{
				adBmi = (LPBITMAPINFOHEADER)adBuf;
				pSize = (adBmi->biBitCount > 8) ? 0 : (4 << (BYTE) adBmi->biBitCount);
				bSize = (((WORD)adBmi->biWidth * adBmi->biBitCount + 31) &~ 31) / 8 * (WORD)adBmi->biHeight;
				_fmemcpy(lpBitmap, adBuf, sizeof(BITMAPINFOHEADER) + pSize + bSize);
				error = FALSE;
				UnlockResource (hgBuf);
			}
			FreeResource(hgBuf);
		}
	}
	return error;
}

// --------------------
// AppendPopup
// --------------------
// Called just before opening the popup menu of the object under the editor.
// You can remove or add options to the default menu...
void WINAPI DLLExport AppendPopup(mv _far *knpV, HMENU hPopup, fpLevObj loPtr, LPEDATA edPtr, int nbSel)
{
}

// --------------------
// CreateObject
// --------------------
// Called when you choose "Create new object". It should display the setup box
// and initialize everything in the datazone.

int WINAPI DLLExport CreateObject(mv _far *knpV, fpLevObj loPtr, LPEDATA edPtr)
{
#ifdef RUN_ONLY2
	MessageBox(0,"You are not supposed to be using this version!","Mode 7 Error!",MB_OK);
	return 0;
#endif

	// Set default object flags
	edPtr->swidth = 320;
	edPtr->sheight = 200;
	edPtr->eNImages = 0;
	edPtr->eCurrentImage = 0;
	

	edPtr->eImageNum = 0;				// Internal Image ID
	edPtr->eImage2Num = 1;				// Internal Image ID
	edPtr->eImageHNum = -2;				// Internal Image ID

	edPtr->eTrans = false;

	edPtr->eRepeatX = false;
	edPtr->eRepeatY = false;
	edPtr->eFog = false;
	edPtr->eInterpolate = false;
	edPtr->eInterpolateHeight = false;
	edPtr->eMipmap = true;
	edPtr->eMipmap2 = true;
	edPtr->eMipmapH = false;
	
	edPtr->eResX = 1;
	edPtr->eResY = 1;
	edPtr->eResMode = 1;
	edPtr->eResModeParam = 128;
	edPtr->eThickness = 0;
	edPtr->eThicknessMode = 1;
	edPtr->eFogColor = 0;
	edPtr->eFogDistance = 1000;
	edPtr->eMipTrans = false;
	edPtr->eMipTransColor = 0;
	edPtr->eAutoRedraw = true;
	
	edPtr->eAutoCamera = true;
	
	
	//edPtr->imgidx = BmpToImg(EXO_ABOUT, knpV->mvIdAppli);

	// Call setup (remove this and return 0 if your object does not need a setup)
	//spa.edpt = edPtr;
	//spa.kv = knpV;
	return ((int) DialOpen(hInstLib, MAKEINTRESOURCE(DB_ABOUT), knpV->mvHEditWin, (FARPROC)aboutProc, 0, 0, DL_MODAL|DL_CENTER_WINDOW, 0));
	//return ((int) DialOpen(hInstLib, MAKEINTRESOURCE(DB_SETUP), knpV->mvHEditWin, (FARPROC)setupProc, 0, 0, DL_MODAL|DL_CENTER_WINDOW, (LPARAM)(LPBYTE)&spa));
return 0;
}

// --------------------
// SelectPopup
// --------------------
// One of the option from the menu has been selected, and not a default menu option
// automatically handled by CC&C: this routine is then called.
//
int WINAPI DLLExport SelectPopup(mv _far *knpV, int modif, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr, fpushort lpParams, int maxParams)
{
#ifdef RUN_ONLY2
	MessageBox(0,"You are not supposed to be using this version!","Mode 7 Error!",MB_OK);
	return 0;
#endif
	setupParams		spa;

	// Remove this if your object does not need a setup
	if (modif == ID_POP_SETUP)
	{

		memset(&spa, 0, sizeof(setupParams));
		spa.edpt = edPtr;
		spa.hFran = oiPtr->oiHFran;
		spa.kv = knpV;
		
		memcpy(&spa.edPtr, (LPBYTE)edPtr, sizeof(EDITDATA));
		
		//spa.nCurrentImage = edPtr->eCurrentImage;
		//spa.nImages = edPtr->eNImages;
		if (edPtr->eNImages)
			memcpy(spa.ci, (LPBYTE)edPtr + sizeof(EDITDATA), edPtr->eNImages * sizeof(internalImage));

		if (0 == DialOpen(hInstLib, MAKEINTRESOURCE(DB_SETUP), knpV->mvHEditWin, (FARPROC)setupProc, 0, 0, DL_MODAL | DL_CENTER_WINDOW, (LPARAM)(LPBYTE)&spa))
			return MODIF_HFRAN;
	}

	// If your object can be resized, remove the remark!
	if (MODIF_SIZE == modif)
	{
		edPtr->swidth = lpParams[2];
		edPtr->sheight = lpParams[3];
	}
	return 0;
}

BOOL CALLBACK DLLExport aboutProc(HWND hDlg,uint msgType,WPARAM wParam,LPARAM lParam) {
	switch (msgType) {
		case WM_INITDIALOG: {
			//SendDlgItemMessage(hDlg, ID_WEBSITE, BM_SETIMAGE, IMAGE_ICON, ID_ICONA);
			//HBITMAP hBitmap = LoadBitmap(hInstLib,MAKEINTRESOURCE(EXO_BUTTON));
		case WM_SYSCOLORCHANGE:
			HBITMAP hBitmap = (HBITMAP)LoadImage(hInstLib,MAKEINTRESOURCE(EXO_BUTTON),IMAGE_BITMAP,0,0,LR_LOADMAP3DCOLORS);
			SendDlgItemMessage(hDlg, ID_WEBSITE, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)(HANDLE)hBitmap);
			hBitmap = (HBITMAP)LoadImage(hInstLib,MAKEINTRESOURCE(EXO_ABOUT),IMAGE_BITMAP,0,0, LR_LOADMAP3DCOLORS|LR_LOADTRANSPARENT);
			SendDlgItemMessage(hDlg, ID_MODE7IMAGE, STM_SETIMAGE , IMAGE_BITMAP, (LPARAM)(HANDLE)hBitmap);
			return TRUE;
		}
		case WM_COMMAND:
			switch (wmCommandID) {
				case IDOK:
					// End dialog box
					EndDialog(hDlg, 0);
					return 0;
				case ID_WEBSITE:
					ShellExecute(hDlg, "open", "http://www.cellosoft.com/", NULL, NULL, SW_SHOWNORMAL);
					return 0;
			}
	}
	return FALSE;
}


// ----------------
// Adapted from Cursor Object
//


// Enable / Disable setup dialog buttons
static void UpdateDialog (HWND hDlg, setupParams FAR * ps, bool initialize= false) {
	// Enable Old External File edit/buttons
	//EnableWindow(GetDlgItem(hDlg, ID_EDITPATH), (ps->nImages == 0));
	//EnableWindow(GetDlgItem(hDlg, ID_EDITBROWSE), (ps->nImages == 0));

	// Enable "Edit" button
	EnableWindow(GetDlgItem(hDlg, ID_EDITDRAW), (ps->edPtr.eNImages != 0));

	// Enable Name edit box
	EnableWindow(GetDlgItem(hDlg, IDC_EDITIMAGENAME), (ps->edPtr.eNImages != 0));

	// Enable "Previous" button
	EnableWindow(GetDlgItem(hDlg, IDC_PREVIMAGE), (ps->edPtr.eCurrentImage > 0));

	// Enable "Next" button
	EnableWindow(GetDlgItem(hDlg, IDC_NEXTIMAGE), ((ps->edPtr.eCurrentImage+1) < ps->edPtr.eNImages));

	// Enable "Insert" buttons
	EnableWindow(GetDlgItem(hDlg, IDC_INSERTBEFORE), ps->edPtr.eNImages && (ps->edPtr.eNImages < MAX_INTERNALIMAGE));
	EnableWindow(GetDlgItem(hDlg, IDC_INSERTAFTER), (ps->edPtr.eNImages < MAX_INTERNALIMAGE));

	// Enable "Remove" button
	EnableWindow(GetDlgItem(hDlg, IDC_REMOVE), (ps->edPtr.eNImages != 0));

	// Set name text & hot spot coords
	if (ps->edPtr.eNImages) {
		SendDlgItemMessage(hDlg, IDC_EDITIMAGENAME, EM_LIMITTEXT, MAX_IMAGE_NAME-1, 0);
		SetDlgItemText(hDlg, IDC_EDITIMAGENAME, ps->ci[ps->edPtr.eCurrentImage].cName);
		SetDlgItemInt(hDlg, IDC_IMAGENUM, ps->edPtr.eCurrentImage, TRUE);
		SetDlgItemText(hDlg,IDC_INSERTAFTER, "Insert After");
	} else {
		SetDlgItemText(hDlg, IDC_EDITIMAGENAME, "");
		SetDlgItemText(hDlg,IDC_INSERTAFTER, "Add Image");
		SetDlgItemInt(hDlg, IDC_IMAGENUM, 0, TRUE);
	}
	EnableWindow(GetDlgItem(hDlg, IDC_MAIN_IMAGE),ps->edPtr.eNImages);
	EnableWindow(GetDlgItem(hDlg, IDC_SECOND_IMAGE),ps->edPtr.eNImages);
	EnableWindow(GetDlgItem(hDlg, IDC_HEIGHT_MAP),ps->edPtr.eNImages);
	
	CheckDlgButton(hDlg, IDC_MAIN_IMAGE, ps->edPtr.eNImages && (ps->edPtr.eImageNum == ps->edPtr.eCurrentImage));
	CheckDlgButton(hDlg, IDC_SECOND_IMAGE, ps->edPtr.eNImages && (ps->edPtr.eImage2Num == ps->edPtr.eCurrentImage));
	CheckDlgButton(hDlg, IDC_HEIGHT_MAP, ps->edPtr.eNImages && (ps->edPtr.eImageHNum == ps->edPtr.eCurrentImage));
	
	if (initialize) {
		// both checked
		if (ps->edPtr.eRepeatX && ps->edPtr.eRepeatY)
			CheckDlgButton(hDlg, IDC_WRAP, BST_CHECKED);
		// none checked
		else if (!ps->edPtr.eRepeatX && !ps->edPtr.eRepeatY)
			CheckDlgButton(hDlg, IDC_WRAP, BST_UNCHECKED);
		// other combo
		else
			SendDlgItemMessage(hDlg, IDC_WRAP, BM_SETCHECK, BST_INDETERMINATE, 0);
			
		// If mip map and mip map 2 checked ONLY
		if (ps->edPtr.eMipmap && ps->edPtr.eMipmap2 && !ps->edPtr.eMipmapH)
			CheckDlgButton(hDlg, IDC_MIP_MAP, BST_CHECKED);
		// If none are checked
		else if (!ps->edPtr.eMipmap && !ps->edPtr.eMipmap2 && !ps->edPtr.eMipmapH)
			CheckDlgButton(hDlg, IDC_MIP_MAP, BST_UNCHECKED);
		// If some other combination are checked
		else 
			SendDlgItemMessage(hDlg, IDC_MIP_MAP, BM_SETCHECK, BST_INDETERMINATE, 0);
			
		// Image interpolation checked
		if (ps->edPtr.eInterpolate && !ps->edPtr.eInterpolateHeight)
			CheckDlgButton(hDlg, IDC_INTERPOLATE, BST_CHECKED);
		// neither checked
		else if (!ps->edPtr.eInterpolate && !ps->edPtr.eInterpolateHeight)
			CheckDlgButton(hDlg, IDC_INTERPOLATE, BST_UNCHECKED);
		// other combo
		else 
			SendDlgItemMessage(hDlg, IDC_INTERPOLATE, BM_SETCHECK, BST_INDETERMINATE, 0);
			
		
		CheckDlgButton(hDlg, IDC_TRANS, ps->edPtr.eTrans);
		CheckDlgButton(hDlg, IDC_AUTO_REDRAW, ps->edPtr.eAutoRedraw);
		CheckDlgButton(hDlg, IDC_LOCATE, ps->edPtr.eAutoCamera);
		CheckDlgButton(hDlg, IDC_FOG, ps->edPtr.eFog);
	}
}

// Create unique image name
static BOOL CreateUniqueName(setupParams FAR * spa, WORD nImage)
{
	BOOL bModified = FALSE;
	LPSTR name = spa->ci[nImage].cName;

	// Create name ?
	if ( *name == 0 ) {
		bModified = TRUE;
		LoadString(hInstLib, IDS_DEFNAME, name, MAX_IMAGE_NAME-1);
	}
	// Make name unique
	for (WORD w=0; w<spa->edPtr.eNImages; w++) {
		if ( w != nImage && _fstricmp(spa->ci[w].cName, name) == 0 ) {
			int l = _fstrlen (name);
			if ( l > MAX_IMAGE_NAME - 3 )	// avoid overflow
				l = MAX_IMAGE_NAME - 3;
			char c = name[l-1];
			if ( c>='0' && c<='9' ) {
				char chNum[8];
				LPSTR ptr = &name[--l];
				int n = 0;
				int coef = 1;
				while ( l >= 0 && *ptr>='0' && *ptr<='9' ) {
					n += (*ptr-- - '0') * coef;
					coef *= 10;
					l--;
				}
				*(++ptr) = 0;
				_itoa (++n, chNum, 10);
				_fstrcat (ptr, chNum);
			} else {
				name[l] = ' ';
				name[l+1] = '2';
				name[l+2] = 0;
			}

			// Modified
			bModified = TRUE;

			// loop
			w = (WORD)-1;
		}
	}

	return bModified;
}

// Change image name
static void OnChangeName(HWND hDlg, setupParams FAR * spa) {
	if ( spa->edPtr.eNImages != 0 ) {
		char name[MAX_IMAGE_NAME];
		GetDlgItemText(hDlg, IDC_EDITIMAGENAME, name, MAX_IMAGE_NAME-1);
		// Name is empty ? create unique name
		if ( *name == 0 ) {
			CreateUniqueName(spa, spa->edPtr.eCurrentImage);
			UpdateDialog(hDlg, spa);
		} else { // Non empty name
			// Modified ?
			if ( _fstricmp(spa->ci[spa->edPtr.eCurrentImage].cName, name) != 0 ) {
				_fstrcpy(spa->ci[spa->edPtr.eCurrentImage].cName, name);
				if ( CreateUniqueName(spa, spa->edPtr.eCurrentImage) ) {
					MessageBox(hDlg, "The current image name has been modified because it was already used by another image", "Mode 7 ex", MB_OK);
					UpdateDialog(hDlg, spa);
				}
			}
		}
	}

}



// --------------------
// SetupProc
// --------------------
// This routine is yours. You may even not need a setup dialog box.
// I have put it as an example...
BOOL CALLBACK DLLExport advsetupProc(HWND hDlg,uint msgType,WPARAM wParam,LPARAM lParam) {
	setupParams2	_far *	spa = NULL;
	EDITDATA _far *		edPtr = NULL;
	BOOL				bEditCurrentImage = FALSE;
	
#ifdef RUN_ONLY2
	MessageBox(0,"You are not supposed to be using this version!","Mode 7 Error!",MB_OK);
#endif
	static COLORREF fogColor= 0;
	static COLORREF	mmColor = 0;

	static HBRUSH hStaticBrush;
			
	char buf[30];

	switch (msgType) {
		case WM_INITDIALOG: {

			// Store edPtr
			SetWindowLong(hDlg, DWL_USER, lParam);
			spa = (setupParams2 FAR *)lParam;
			//edPtr->imgidx=1;

			// Set up parameters
			
			// Populate Combo boxes
			SendDlgItemMessage(hDlg, IDC_THICKMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"Fast");
			SendDlgItemMessage(hDlg, IDC_THICKMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"Fill");
			SendDlgItemMessage(hDlg, IDC_THICKMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"Full");

			SendDlgItemMessage(hDlg, IDC_RESMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"Quick");
			SendDlgItemMessage(hDlg, IDC_RESMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"Full");
			SendDlgItemMessage(hDlg, IDC_RESMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"Scanlines");
			SendDlgItemMessage(hDlg, IDC_RESMODE, CB_ADDSTRING, 0, (LPARAM)(LPCTSTR)"% Scanlines");

			SendDlgItemMessage(hDlg, IDC_SLIDER, TBM_SETRANGE, TRUE, MAKELONG(0, 20000));
			SendDlgItemMessage(hDlg, IDC_SLIDER, TBM_SETTICFREQ, 1000,0);
			
			
			
			// Interpolation
			CheckDlgButton(hDlg, IDC_INTERPOLATE, spa->edPtr.eInterpolate);
			CheckDlgButton(hDlg, IDC_INTERPOLATEH, spa->edPtr.eInterpolateHeight);
			
			// Mipmapping
			CheckDlgButton(hDlg, IDC_MIP_MAP, spa->edPtr.eMipmap);
			CheckDlgButton(hDlg, IDC_MIP_MAP2, spa->edPtr.eMipmap2);
			CheckDlgButton(hDlg, IDC_MIP_MAPH, spa->edPtr.eMipmapH);
			CheckDlgButton(hDlg, IDC_MMTRANS, spa->edPtr.eMipTrans);
			mmColor = spa->edPtr.eMipTransColor;
			
			// Fog
			CheckDlgButton(hDlg, IDC_FOG2, spa->edPtr.eFog);
			ltoa(spa->edPtr.eFogDistance, buf, 10); SetDlgItemText(hDlg, IDC_FOGAMOUNT, buf);
			SendDlgItemMessage(hDlg, IDC_SLIDER, TBM_SETPOS, TRUE, spa->edPtr.eFogDistance);
			fogColor = spa->edPtr.eFogColor;
			
			// Wrap/Repeat modes
			CheckDlgButton(hDlg, IDC_WRAPH, spa->edPtr.eRepeatX);
			CheckDlgButton(hDlg, IDC_WRAPV, spa->edPtr.eRepeatY);
			
			// Thickness
			ltoa(spa->edPtr.eThickness, buf, 10); SetDlgItemText(hDlg, IDC_THICKNESS, buf);
			SendDlgItemMessage(hDlg, IDC_THICKMODE, CB_SETCURSEL, spa->edPtr.eThicknessMode, 0);
			
			
			// Resolution
			ltoa(spa->edPtr.eResX, buf, 10); SetDlgItemText(hDlg, IDC_RESX, buf);
			ltoa(spa->edPtr.eResY, buf, 10); SetDlgItemText(hDlg, IDC_RESY, buf);			
			SendDlgItemMessage(hDlg, IDC_RESMODE, CB_SETCURSEL, spa->edPtr.eResMode, 0);
			ltoa(spa->edPtr.eResModeParam, buf, 10); SetDlgItemText(hDlg, IDC_RESPARAM, buf);

			// Enable/Disable controls
			
			EnableWindow(GetDlgItem(hDlg, IDC_FOGAMOUNT), IsDlgButtonChecked(hDlg, IDC_FOG2));
			EnableWindow(GetDlgItem(hDlg, IDC_SLIDER), IsDlgButtonChecked(hDlg, IDC_FOG2));
			EnableWindow(GetDlgItem(hDlg, IDC_FOGCOLOR), IsDlgButtonChecked(hDlg, IDC_FOG2));
			
			EnableWindow(GetDlgItem(hDlg, IDC_MMCOLOR), IsDlgButtonChecked(hDlg, IDC_MMTRANS));
			EnableWindow(GetDlgItem(hDlg, IDC_RESPARAM), SendDlgItemMessage(hDlg, IDC_RESMODE, CB_GETCURSEL, 0, 0)==3);

			// Ok
			return TRUE;
		} break;
		// Slider control
		case WM_HSCROLL:
			char buf[30];
			ltoa(SendDlgItemMessage(hDlg,IDC_SLIDER1, TBM_GETPOS, 0, 0), buf, 10);
			SetDlgItemText(hDlg,IDC_FOGAMOUNT,buf);
			
			
			break;

		case WM_CTLCOLORSTATIC:
			if ( (HWND)lParam  == GetDlgItem(hDlg, IDC_MMCBOX) ) {
				if( hStaticBrush != NULL ) DeleteObject(hStaticBrush);

				hStaticBrush = CreateSolidBrush(mmColor);
				return reinterpret_cast<long>(hStaticBrush);
			}
			if ( (HWND)lParam  == GetDlgItem(hDlg, IDC_FOGCBOX) ) {
				if( hStaticBrush != NULL ) DeleteObject(hStaticBrush);

				hStaticBrush = CreateSolidBrush(fogColor);
				return reinterpret_cast<long>(hStaticBrush);
			}
			break;

		case WM_DESTROY:
			if( hStaticBrush != NULL ) DeleteObject(hStaticBrush);
			break;
		case WM_COMMAND:

			// Retrieve edPtr
			spa = (setupParams2 far *)GetWindowLong(hDlg, DWL_USER);

			// Command messages
			switch (wmCommandID) {
				case IDC_RESMODE:
					EnableWindow(GetDlgItem(hDlg, IDC_RESPARAM), SendDlgItemMessage(hDlg, IDC_RESMODE, CB_GETCURSEL, 0, 0)==3);
					break;
				case IDC_FOG2:
					EnableWindow(GetDlgItem(hDlg, IDC_FOGAMOUNT), IsDlgButtonChecked(hDlg, IDC_FOG2));
					EnableWindow(GetDlgItem(hDlg, IDC_SLIDER), IsDlgButtonChecked(hDlg, IDC_FOG2));
					EnableWindow(GetDlgItem(hDlg, IDC_FOGCOLOR), IsDlgButtonChecked(hDlg, IDC_FOG2));
					break;
				case IDC_FOGAMOUNT:
					char buf[30];
					GetDlgItemText(hDlg, IDC_FOGAMOUNT, buf, 30);
					SendDlgItemMessage(hDlg, IDC_SLIDER, TBM_SETPOS, TRUE, atol(buf));
					break;
				case IDC_MMTRANS:
					EnableWindow(GetDlgItem(hDlg, IDC_MMCOLOR), IsDlgButtonChecked(hDlg, IDC_MMTRANS));
					break;
				case IDC_MMCOLOR:
				case IDC_FOGCOLOR:
					static CHOOSECOLOR	ccf;
					static COLORREF 	crefCustColor[16];

					_fmemset(&ccf, 0, sizeof(CHOOSECOLOR));
					ccf.lStructSize = sizeof(CHOOSECOLOR);
					ccf.hwndOwner = hDlg;
					if (wmCommandID==IDC_MMCOLOR)
						ccf.rgbResult = mmColor;
					else 
						ccf.rgbResult = fogColor;
					ccf.lpCustColors = crefCustColor;
					ccf.Flags = CC_RGBINIT|CC_ANYCOLOR;
					if (ChooseColor(&ccf)) {
						if (wmCommandID==IDC_MMCOLOR)
							mmColor=ccf.rgbResult;
						else
							fogColor=ccf.rgbResult;
						InvalidateRect(hDlg, NULL, FALSE);
					}
					return 0;
				case IDOK:

					// Store options
					

					// Interpolation
					spa->edPtr.eInterpolate = IsDlgButtonChecked(hDlg, IDC_INTERPOLATE) ? true : false;
					spa->edPtr.eInterpolateHeight = IsDlgButtonChecked(hDlg, IDC_INTERPOLATEH) ? true : false;

					// Mipmapping
					spa->edPtr.eMipmap = IsDlgButtonChecked(hDlg, IDC_MIP_MAP) ? true : false;
					spa->edPtr.eMipmap2 = IsDlgButtonChecked(hDlg, IDC_MIP_MAP2) ? true : false;
					spa->edPtr.eMipmapH = IsDlgButtonChecked(hDlg, IDC_MIP_MAPH) ? true : false;
					spa->edPtr.eMipTrans = IsDlgButtonChecked(hDlg, IDC_MMTRANS) ? true : false;
					spa->edPtr.eMipTransColor = mmColor;

					// Fog
					spa->edPtr.eFog = IsDlgButtonChecked(hDlg, IDC_FOG2) ? true : false;

					GetDlgItemText(hDlg, IDC_FOGAMOUNT, buf, 30);
					spa->edPtr.eFogDistance = atoi(buf);

					spa->edPtr.eFogColor = fogColor;

					// Wrap/Repeat modes
					spa->edPtr.eRepeatX = IsDlgButtonChecked(hDlg, IDC_WRAPH) ? true : false;
					spa->edPtr.eRepeatY = IsDlgButtonChecked(hDlg, IDC_WRAPV) ? true : false;

					// Thickness
					GetDlgItemText(hDlg, IDC_THICKNESS, buf, 30);
					spa->edPtr.eThickness = atoi(buf);

					spa->edPtr.eThicknessMode = SendDlgItemMessage(hDlg, IDC_THICKMODE, CB_GETCURSEL, 0, 0);


					// Resolution
					GetDlgItemText(hDlg, IDC_RESX, buf, 30);
					spa->edPtr.eResX = atoi(buf);

					GetDlgItemText(hDlg, IDC_RESY, buf, 30);
					spa->edPtr.eResY = atoi(buf);
					spa->edPtr.eResMode = SendDlgItemMessage(hDlg, IDC_RESMODE, CB_GETCURSEL, 0, 0);

					GetDlgItemText(hDlg, IDC_RESPARAM, buf, 30);
					spa->edPtr.eResModeParam = atoi(buf);
					
					
					// Copy new info over
					memcpy(&spa->spa->edPtr, &spa->edPtr, sizeof(EDITDATA));

					// End dialog box
					EndDialog(hDlg, 0);
					return 0;
				case IDCANCEL:
					// End dialog box
					EndDialog(hDlg, -1);
					return 0;
			}
			break;
	}


	return FALSE;
}



// --------------------
// SetupProc
// --------------------
// This routine is yours. You may even not need a setup dialog box.
// I have put it as an example...
BOOL CALLBACK DLLExport setupProc(HWND hDlg,uint msgType,WPARAM wParam,LPARAM lParam) {
	setupParams	_far *	spa = NULL;
	EDITDATA _far *		edPtr = NULL;
	BOOL				bEditCurrentImage = FALSE;
	WORD				w;
#ifdef RUN_ONLY2
	MessageBox(0,"You are not supposed to be using this version!","Mode 7 Error!",MB_OK);
#endif

	switch (msgType) {
		case WM_INITDIALOG: {

			// Store edPtr
			SetWindowLong(hDlg, DWL_USER, lParam);
			spa = (setupParams FAR *)lParam;
			edPtr = spa->edpt;
			
			// Inc image counters and init spa variables
			for (w=0; w<spa->edPtr.eNImages; w++) {
				if ( spa->ci[w].cImg != 0 )
					IncImageCount(spa->kv->mvIdAppli, spa->ci[w].cImg);
			}
			
			// Update dialog controls
			UpdateDialog(hDlg, spa, true);

			// Ok
			return TRUE;
		} break;
		case WM_PAINT:
			spa = (setupParams far *)GetWindowLong(hDlg, DWL_USER);
			edPtr = spa->edpt;
			if ( spa != NULL ) {
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hDlg, &ps);
				if (hdc != NULL) {
					HWND hPreview = GetDlgItem(hDlg, ID_IMAGEVIEW);
					if ( hPreview != NULL ) {
						RECT rc;

						GetWindowRect(hPreview, &rc);
						ScreenToClient(hDlg, (LPPOINT)&rc.left);
						ScreenToClient(hDlg, (LPPOINT)&rc.right);

						// Background
						COLORREF color = GetSysColor(COLOR_3DFACE);
						HBRUSH hbr = CreateSolidBrush(color);
						FillRect(hdc, &rc, hbr);
						DeleteObject(hbr);

						// Draw image
						LPBITMAPINFO pBmi = CreateBitmapFromImage(spa->kv->mvIdAppli, &spa->ci[spa->edPtr.eCurrentImage]);
						if ( pBmi != NULL ) {
							int width,height,wi,hi;
							width = wi = pBmi->bmiHeader.biWidth;
							height = hi = pBmi->bmiHeader.biHeight;
							int maxwidth = rc.right-rc.left-4;
							int maxheight = rc.bottom-rc.top-4;
							if (width > maxwidth || height > maxheight) {
								float xprop = (float)width/maxwidth;
								float yprop = (float)height/maxheight;
								if (xprop < yprop) { wi=(int)(width/yprop); hi=maxheight; }
								else { wi=maxwidth; hi=(int)(height/xprop); }
							}
							int x=abs(maxwidth-wi)/2;
							int y=abs(maxheight-hi)/2;
							SetStretchBltMode(hdc,HALFTONE);
							SetBrushOrgEx(hdc,0,0,NULL);
							StretchDIBits(	hdc,
											rc.left+2+x, rc.top+2+y, wi, hi,
											0, 0, width, height,
											(LPBYTE)pBmi+sizeof(BITMAPINFOHEADER), pBmi,
											DIB_RGB_COLORS, SRCCOPY);
							_ffree(pBmi);
						}
					}
				}
				EndPaint(hDlg, &ps);
			}
			break;
		case WM_COMMAND: {

			// Retrieve edPtr
			spa = (setupParams far *)GetWindowLong(hDlg, DWL_USER);
			edPtr = spa->edpt;

			// Command messages
			switch (wmCommandID) {
				case IDC_MAIN_IMAGE:
					if (IsDlgButtonChecked(hDlg,IDC_MAIN_IMAGE))
						spa->edPtr.eImageNum = 	spa->edPtr.eCurrentImage;
					else if (spa->edPtr.eImageNum == spa->edPtr.eCurrentImage)
						spa->edPtr.eImageNum = -2;
					break;
					
				case IDC_SECOND_IMAGE:
					if (IsDlgButtonChecked(hDlg,IDC_SECOND_IMAGE))
						spa->edPtr.eImage2Num = spa->edPtr.eCurrentImage;
					else if (spa->edPtr.eImage2Num == spa->edPtr.eCurrentImage)
						spa->edPtr.eImage2Num = -2;
					break;

				case IDC_HEIGHT_MAP:
					if (IsDlgButtonChecked(hDlg,IDC_HEIGHT_MAP))
						spa->edPtr.eImageHNum = spa->edPtr.eCurrentImage;
					else if (spa->edPtr.eImageHNum == spa->edPtr.eCurrentImage)
						spa->edPtr.eImageHNum = -2;
					break;
					
					
				case IDC_WRAP:
					if (IsDlgButtonChecked(hDlg,IDC_WRAP)==BST_INDETERMINATE) CheckDlgButton(hDlg,IDC_WRAP,BST_UNCHECKED);
					spa->edPtr.eRepeatX=IsDlgButtonChecked(hDlg,IDC_WRAP) ? true : false;
					spa->edPtr.eRepeatY=IsDlgButtonChecked(hDlg,IDC_WRAP) ? true : false;
					break;
				case IDC_INTERPOLATE:
					if (IsDlgButtonChecked(hDlg,IDC_INTERPOLATE)==BST_INDETERMINATE) CheckDlgButton(hDlg,IDC_INTERPOLATE,BST_UNCHECKED);
					spa->edPtr.eInterpolate=IsDlgButtonChecked(hDlg,IDC_INTERPOLATE) ? true : false;
					spa->edPtr.eInterpolateHeight=false;
					break;
				case IDC_MIP_MAP:
					if (IsDlgButtonChecked(hDlg,IDC_MIP_MAP)==BST_INDETERMINATE) CheckDlgButton(hDlg,IDC_MIP_MAP,BST_UNCHECKED);
					spa->edPtr.eMipmap=IsDlgButtonChecked(hDlg,IDC_MIP_MAP) ? true : false;
					spa->edPtr.eMipmap2=IsDlgButtonChecked(hDlg,IDC_MIP_MAP) ? true : false;
					spa->edPtr.eMipmapH=false;
					break;
					
				case IDC_EDITIMAGENAME:
					if ( wmCommandNotif == EN_KILLFOCUS )
						OnChangeName(hDlg, spa);
					break;

				// Previous image
				case IDC_PREVIMAGE:
					if (spa->edPtr.eCurrentImage>0) {
						spa->edPtr.eCurrentImage--;
						UpdateDialog(hDlg, spa);
						InvalidateRect(hDlg, NULL, FALSE);
					}
					break;

				// Next image
				case IDC_NEXTIMAGE:
					if ((spa->edPtr.eCurrentImage+1) < spa->edPtr.eNImages) {
						spa->edPtr.eCurrentImage++;
						UpdateDialog(hDlg, spa);
						InvalidateRect(hDlg, NULL, FALSE);
					}
					break;

				// Insert before
				case IDC_INSERTBEFORE:
					if ( spa->edPtr.eNImages < MAX_INTERNALIMAGE ) {
						if (spa->edPtr.eNImages) {
							// Décaler les images supérieures
							_fmemmove(&spa->ci[spa->edPtr.eCurrentImage+1], &spa->ci[spa->edPtr.eCurrentImage], (spa->edPtr.eNImages-spa->edPtr.eCurrentImage) * sizeof(internalImage));

							// Incrémenter image usage count
							if (spa->ci[spa->edPtr.eCurrentImage].cImg)
								IncImageCount(spa->kv->mvIdAppli, spa->ci[spa->edPtr.eCurrentImage].cImg);
						}
						if (spa->edPtr.eImageNum>=spa->edPtr.eCurrentImage) spa->edPtr.eImageNum++;
						if (spa->edPtr.eImage2Num>=spa->edPtr.eCurrentImage) spa->edPtr.eImage2Num++;
						if (spa->edPtr.eImageHNum>=spa->edPtr.eCurrentImage) spa->edPtr.eImageHNum++;

						spa->edPtr.eNImages++;
						CreateUniqueName(spa, spa->edPtr.eCurrentImage);
						UpdateDialog(hDlg, spa);
						//InvalidateRect(hDlg, NULL, FALSE);
						if ( spa->kv->mvEditImage2) {
							bEditCurrentImage = TRUE;
							goto cok;
						}
					}
					break;

				// Insert after
				case IDC_INSERTAFTER:
					if (spa->edPtr.eNImages < MAX_INTERNALIMAGE) {
						if (spa->edPtr.eNImages) {
							// Décaler images supérieures
							_fmemmove(&spa->ci[spa->edPtr.eCurrentImage+1], &spa->ci[spa->edPtr.eCurrentImage], (spa->edPtr.eNImages-spa->edPtr.eCurrentImage) * sizeof(internalImage));

							// Increase image usage count
							spa->edPtr.eCurrentImage++;
							if (spa->ci[spa->edPtr.eCurrentImage].cImg)
								IncImageCount(spa->kv->mvIdAppli, spa->ci[spa->edPtr.eCurrentImage].cImg);
						}
						if (spa->edPtr.eNImages) {
							if (spa->edPtr.eImageNum>=spa->edPtr.eCurrentImage) spa->edPtr.eImageNum++;
							if (spa->edPtr.eImage2Num>=spa->edPtr.eCurrentImage) spa->edPtr.eImage2Num++;
							if (spa->edPtr.eImageHNum>=spa->edPtr.eCurrentImage) spa->edPtr.eImageHNum++;
						}

						spa->edPtr.eNImages++;
						CreateUniqueName(spa, spa->edPtr.eCurrentImage);
						UpdateDialog(hDlg, spa);
						//InvalidateRect(hDlg, NULL, FALSE);
						if ( spa->kv->mvEditImage2) {
							bEditCurrentImage = TRUE;
							goto cok;
						}
					}
					break;
				case IDC_IMPORTIMAGE: {
					/*
					if (spa->edPtr.eNImages < MAX_INTERNALIMAGE) {
						if (spa->edPtr.eNImages) {
							// Décaler images supérieures
							_fmemmove(&spa->ci[spa->edPtr.eCurrentImage+1], &spa->ci[spa->edPtr.eCurrentImage], (spa->edPtr.eNImages-spa->edPtr.eCurrentImage) * sizeof(internalImage));

							// Increase image usage count
							spa->edPtr.eCurrentImage++;
							if (spa->ci[spa->edPtr.eCurrentImage].cImg) {
								IncImageCount(spa->kv->mvIdAppli, spa->ci[spa->edPtr.eCurrentImage].cImg);
							}
						}

						spa->edPtr.eNImages++;
						CreateUniqueName(spa, spa->edPtr.eCurrentImage);
						//UpdateDialog(hDlg, spa);
						//InvalidateRect(hDlg, NULL, FALSE);
						//goto cok;
					}
					*/
				}
				// Remove current image
				case IDC_REMOVE:
					if (spa->edPtr.eNImages) {
						// Delete current image
						if ( spa->ci[spa->edPtr.eCurrentImage].cImg != 0 )
							DelImage(spa->kv->mvIdAppli, spa->ci[spa->edPtr.eCurrentImage].cImg);


						if (spa->edPtr.eImageNum==spa->edPtr.eCurrentImage) spa->edPtr.eImageNum=-2;
						else if (spa->edPtr.eImageNum>spa->edPtr.eCurrentImage) spa->edPtr.eImageNum--;
						
						if (spa->edPtr.eImage2Num==spa->edPtr.eCurrentImage) spa->edPtr.eImage2Num=-2;
						else if (spa->edPtr.eImage2Num>spa->edPtr.eCurrentImage) spa->edPtr.eImage2Num--;
						
						if (spa->edPtr.eImageHNum==spa->edPtr.eCurrentImage) spa->edPtr.eImageHNum=-2;
						else if (spa->edPtr.eImageHNum>spa->edPtr.eCurrentImage) spa->edPtr.eImageHNum--;
						
						// Remove structure
						if (spa->edPtr.eCurrentImage == (spa->edPtr.eNImages-1)) {
							if (spa->edPtr.eCurrentImage)
								spa->edPtr.eCurrentImage--;
						} else
							_fmemmove(&spa->ci[spa->edPtr.eCurrentImage], &spa->ci[spa->edPtr.eCurrentImage+1], sizeof(internalImage) * (spa->edPtr.eNImages - (spa->edPtr.eCurrentImage+1)));
							
						
						spa->edPtr.eNImages--;
						_fmemset(&spa->ci[spa->edPtr.eNImages], 0, sizeof(internalImage));
						UpdateDialog(hDlg, spa);
						InvalidateRect(hDlg, NULL, FALSE);
					}
					break;

/*
				case ID_EDITBROWSE: {
					OPENFILENAME	ofn;
					char			szFile[_MAX_PATH];

					// Set correct parameters
					_fmemset((LPVOID)&ofn, 0, sizeof(OPENFILENAME));
					ofn.lStructSize = sizeof(OPENFILENAME);
					ofn.hwndOwner = hDlg;
					ofn.lpstrFilter = "Picture files (*.bmp;*.pcx;*.gif)\0*.bmp;*.pcx;*.gif\0";
					ofn.nFilterIndex = 0;
					ofn.lpstrFile = szFile;
					_fstrcpy(szFile, edPtr->eFilename);
					ofn.nMaxFile = _MAX_PATH;
					ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;

					// Open dialog box
					if ( GetOpenFileName(&ofn) ) SetDlgItemText(hDlg, ID_EDITPATH, (LPSTR)ofn.lpstrFile);

					// Ok
					return 0;
				}*/
				case ID_ADVANCED:
					setupParams2 spa2;
					
					// Store single-state options
					spa->edPtr.eTrans = IsDlgButtonChecked(hDlg, IDC_TRANS) ? true : false;
					spa->edPtr.eAutoCamera = IsDlgButtonChecked(hDlg, IDC_LOCATE) ? true : false;
					spa->edPtr.eAutoRedraw = IsDlgButtonChecked(hDlg, IDC_AUTO_REDRAW) ? true : false;
					spa->edPtr.eFog = IsDlgButtonChecked(hDlg, IDC_FOG) ? true : false;
					
					spa2.spa = spa;
					spa2.kv = spa->kv;
					spa2.hFran = spa->hFran;
					
					memcpy(&spa2.edPtr, &spa->edPtr, sizeof(EDITDATA));
					
					DialOpen(hInstLib, MAKEINTRESOURCE(DB_ADVSETUP), hDlg, (FARPROC)advsetupProc, 0, 0, DL_MODAL|DL_CENTER_WINDOW, (LPARAM)(LPBYTE)&spa2);
						
					// Update dialog controls
					UpdateDialog(hDlg, spa, true);
					
					break;
				case ID_ABOUT:
					DialOpen(hInstLib, MAKEINTRESOURCE(DB_ABOUT), hDlg, (FARPROC)aboutProc, 0, 0, DL_MODAL|DL_CENTER_WINDOW, 0);
					return 0;
				case ID_EDITDRAW:
					if ( spa->kv->mvEditImage2) {
						bEditCurrentImage = TRUE;
						goto cok;
					}
					break;
				case IDOK:
					cok: {
					// Save parameters
					//GetDlgItemText(hDlg, ID_EDITPATH, edPtr->eFilename, _MAX_PATH);



					// Store single-state options
					spa->edPtr.eTrans = IsDlgButtonChecked(hDlg, IDC_TRANS) ? true : false;
					spa->edPtr.eAutoCamera = IsDlgButtonChecked(hDlg, IDC_LOCATE) ? true : false;
					spa->edPtr.eAutoRedraw = IsDlgButtonChecked(hDlg, IDC_AUTO_REDRAW) ? true : false;
					spa->edPtr.eFog = IsDlgButtonChecked(hDlg, IDC_FOG) ? true : false;

					// Update data
					OnChangeName(hDlg, spa);

					// Delete old images
					if (edPtr->eNImages) {
						LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)edPtr + sizeof(EDITDATA));
						for (w=0; w<edPtr->eNImages; w++, pii++)
							if (pii->cImg)
								DelImage(spa->kv->mvIdAppli, pii->cImg);
					}

					// Update edPtr
					//edPtr->eCurrentImage = spa->edPtr.eCurrentImage;
					//edPtr->eNImages = spa->edPtr.eNImages;
					
					// Copy temporary edit struct to real edit struct pointer
					memcpy((LPBYTE)edPtr, &spa->edPtr, sizeof(EDITDATA));
					
					if (spa->edPtr.eNImages)
						memcpy((LPBYTE)edPtr + sizeof(EDITDATA), spa->ci, spa->edPtr.eNImages * sizeof(internalImage));

					// Update size of edPtr
					edPtr->eHeader.extSize = sizeof(EDITDATA) + edPtr->eNImages * sizeof(internalImage);

					// Edit image ?
					if ( bEditCurrentImage )
						if (IS_COMPATIBLE(spa->kv)) // MMF 1.5-only feature
							spa->kv->mvEditAnimation((HFRAN)spa->hFran, (LPBYTE)edPtr, edPtr->eCurrentImage, 0);
						else
							spa->kv->mvEditImage2((DWORD)spa->hFran, (LPBYTE)edPtr, edPtr->eCurrentImage);
						
					// End dialog box
					EndDialog(hDlg, 0);
					return 0;
				}
				case IDCANCEL: {
					// Delete new images
					for (w=0; w<spa->edPtr.eNImages; w++) {
						if (spa->ci[w].cImg)
							DelImage(spa->kv->mvIdAppli, spa->ci[w].cImg);
					}

					// !!! This isn't needed, is it?
					// Update size of edPtr 
					//edPtr->eHeader.extSize = sizeof(EDITDATA) + edPtr->eNImages * sizeof(internalImage);
					
					
					// End dialog box
					EndDialog(hDlg, -1);
					return 0;
				}

			}
			break;
		} break;
	}
	return FALSE;
}

// --------------------
// ModifyObject
// --------------------
// Called by CC&C when the object has been modified
//
int WINAPI DLLExport ModifyObject(mv _far *knpV, LPEDATA edPtr, fpObjInfo oiPtr, fpLevObj loPtr, int modif, fpushort lpParams)
{

	// Modification in size?
	if (MODIF_SIZE == modif)
	{
		edPtr->swidth = lpParams[2];
		edPtr->sheight = lpParams[3];
	}
	// No errors...
	return 0;
}


// --------------------
// RebuildExt
// --------------------
// This routine rebuilds the new extension datazone from the old one, and the
// modifications done in the setup dialog
int WINAPI DLLExport RebuildExt(mv _far *knpV, LPEDATA edPtr, LPBYTE oldExtPtr, fpObjInfo oiPtr, fpLevObj loPtr, fpushort lpParams)
{
	// No errors
	return 0;
}


// --------------------
// EndModifyObject
// --------------------
// After all modifications are done, this routine is called.
// You can free any memory allocated here.
void WINAPI DLLExport EndModifyObject(mv _far *knpV, int modif, fpushort lpParams)
{
}

// --------------------
// GetObjectRect
// --------------------
// Returns the size of the rectangle of the object in the frame window
//
void WINAPI DLLExport GetObjectRect(mv _far *knpV, RECT FAR *rc, fpLevObj loPtr, LPEDATA edPtr)
{
	//Print("GetObjectRect");
	rc->right = rc->left + edPtr->swidth;
	rc->bottom = rc->top + edPtr->sheight;
	return;
}


// --------------------
// EditorDisplay
// --------------------
// Displays the object under the frame editor
//
void WINAPI DLLExport EditorDisplay(mv _far *knpV, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr, RECT FAR *rc)
{
#ifdef RUN_ONLY2
	MessageBox(0,"You are not supposed to be using this version!","Mode 7 Error!",MB_OK);
#endif

	LPSURFACE ps = WinGetSurface((int)knpV->mvIdEditWin);
	if ( ps != NULL )
	{
		int x = rc->left;
		int y = rc->top;
		int w = rc->right-rc->left;
		int h = rc->bottom-rc->top;

		cSurface sf;
		sf.Create(w,h, ps);

		sf.Fill(0,0,0);
		if (edPtr->eTrans) {
			sf.Line(0,0,w-1,h-1,3,RGB(0,32,0));
			sf.Line(w-1,0,0,h-1,3,RGB(0,32,0));
		}
		sf.Line(0,0,w-1,h-1,1,RGB(0,255,0));
		sf.Line(w-1,0,0,h-1,1,RGB(0,255,0));
		sf.Rectangle(1,1,w-1,h-1,1,RGB(0,255,0));
		sf.Rectangle(0,0,w,h,1,RGB(0,32,0));

		// Blit image surface to playfield surface
		sf.Blit(*ps, x, y,0, 0, w, h,edPtr->eTrans?BMODE_TRANSP:BMODE_OPAQUE);
	}
}


// --------------------
// IsTransparent
// --------------------
// This routine tells CC&C if the mouse pointer is over a transparent zone of the object.
//

extern "C" {
	BOOL WINAPI DLLExport IsTransparent(mv _far *knpV, fpLevObj loPtr, LPEDATA edPtr, int dx, int dy)
	{
		return FALSE;
	}
}

// --------------------
// PrepareToWriteObject
// --------------------
// Just before writing the datazone when saving the application, CC&C calls this routine.
//
void WINAPI	DLLExport PrepareToWriteObject(mv _far *knpV, LPEDATA edPtr, fpObjInfo adoi)
{
}

// --------------------
// UsesFile
// --------------------
// Triggers when a file is dropped onto the frame
BOOL WINAPI	DLLExport UsesFile (LPSTR fileName)
{
	BOOL	r = FALSE;
	NPSTR	ext, npath;

	if ( fileName != NULL ) {
		if ( (ext=(NPSTR)LocalAlloc(LPTR, _MAX_EXT)) != NULL ) {
			if ( (npath=(NPSTR)LocalAlloc(LPTR, _MAX_PATH)) != NULL ) {
				_fstrcpy(npath, fileName);
				_splitpath(npath, NULL, NULL, NULL, ext);

				// Return TRUE if the file can be used to create an object
				if ( _stricmp(ext, ".bmp") == 0 ||
					 _stricmp(ext, ".gif") == 0 ||
					 _stricmp(ext, ".pcx") == 0 )
					r = TRUE;		// can import
				LocalFree((HLOCAL)npath);
			}
			LocalFree((HLOCAL)ext);
		}
	}
	return r;

}


// --------------------
// CreateFromFile
// --------------------
// Creates a new object from file
void WINAPI	DLLExport CreateFromFile (LPSTR fileName, LPEDATA edPtr)
{
	// Set default object flags
	//_fstrcpy (edPtr->eFilename, fileName);

	// Get 65000 colors surface prototype
	//LPSURFACE proto;
	//GetSurfacePrototype(&proto, 16, ST_MEMORY, SD_DIB);

	// Create surface and load image
	//cSurface sf;
	//sf.Create(4, 4, proto);
	//sf.LoadImage(fileName);

	// Get image dimensions
	//edPtr->swidth = sf.GetWidth();
	//edPtr->sheight = sf.GetHeight();
}

// ---------------------
// EnumElts
// ---------------------
int WINAPI DLLExport EnumElts (mv __far *knpV, LPEDATA edPtr, ENUMELTPROC enumProc, ENUMELTPROC undoProc, LPARAM lp1, LPARAM lp2)
{
	int error = 0;
	LPINTERNALIMAGE pii = (LPINTERNALIMAGE)((LPBYTE)edPtr + sizeof(EDITDATA));

	// Enum images
	for (int i=0; i<edPtr->eNImages; i++) {
		if (error = enumProc(&pii->cImg, IMG_TAB, lp1, lp2)) {
			// Undo enum images
			for (int j=i; --j>=0;) {
				pii--;
				undoProc(&pii->cImg, IMG_TAB, lp1, lp2);
			}
			break;
		}
		pii++;
	}
	return error;
}

#endif //Not RUN_ONLY