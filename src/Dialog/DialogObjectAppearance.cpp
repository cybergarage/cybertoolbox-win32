// DialogObjectAppearance.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogObjectAppearance.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogObjectAppearance ダイアログ


DialogObjectAppearance::DialogObjectAppearance(CWnd* pParent /*=NULL*/)
	: CDialog(DialogObjectAppearance::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogObjectAppearance)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}

BOOL DialogObjectAppearance::Create()
{
	return CDialog::Create(DialogObjectAppearance::IDD);
}

void DialogObjectAppearance::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogObjectAppearance)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogObjectAppearance, CDialog)
	//{{AFX_MSG_MAP(DialogObjectAppearance)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_APPLY, OnApply)
	ON_BN_CLICKED(IDC_TEXTURE_SELECT, OnTextureSelect)
	ON_BN_CLICKED(IDC_TEXTURE_DELETE, OnTextureDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

DialogObjectAppearance::~DialogObjectAppearance()
{
	RGBColor24 *color = getImageTextureColor();
	if (color)
		delete []color;
}

/////////////////////////////////////////////////////////////////////////////
// DialogObjectAppearance メッセージ ハンドラ

static void Draw(CDC *cdc)
{
	cdc->TextOut(0, 0, "OBJECT", 5);
}

void DialogObjectAppearance::setOriginalImageTextureFilename(char *filename)
{
	if (filename != NULL)
		strcpy(mImageTextureFilename, filename); 
	else
		strcpy(mImageTextureFilename, ""); 
}

void DialogObjectAppearance::copyMaterialData(MaterialNode *srcMaterial, MaterialNode *dstMaterial)
{
	float	color[3];

	srcMaterial->getDiffuseColor(color);
	dstMaterial->setDiffuseColor(color);

	srcMaterial->getEmissiveColor(color);
	dstMaterial->setEmissiveColor(color);

	srcMaterial->getSpecularColor(color);
	dstMaterial->setSpecularColor(color);

	dstMaterial->setShininess(srcMaterial->getShininess());
	dstMaterial->setTransparency(srcMaterial->getTransparency());
	dstMaterial->setAmbientIntensity(srcMaterial->getAmbientIntensity());
}

#define SCROLLBAR_RANGE		100

void DialogObjectAppearance::setScrollBarText(int id)
{
	CScrollBar *sb = (CScrollBar *)GetDlgItem(id);
	int pos = sb->GetScrollPos();
	
	char value[32];
	sprintf(value, "%.2f", (float)pos/(float)SCROLLBAR_RANGE);

	switch (id) {
	case IDC_DIFFUSE_RCOLOR:	SetDlgItemText(IDC_DIFFUSE_RCOLOR_VALUE, value);	break;
	case IDC_DIFFUSE_GCOLOR:	SetDlgItemText(IDC_DIFFUSE_GCOLOR_VALUE, value);	break;
	case IDC_DIFFUSE_BCOLOR:	SetDlgItemText(IDC_DIFFUSE_BCOLOR_VALUE, value);	break;

	case IDC_EMISSIVE_RCOLOR:	SetDlgItemText(IDC_EMISSIVE_RCOLOR_VALUE, value);	break;
	case IDC_EMISSIVE_GCOLOR:	SetDlgItemText(IDC_EMISSIVE_GCOLOR_VALUE, value);	break;
	case IDC_EMISSIVE_BCOLOR:	SetDlgItemText(IDC_EMISSIVE_BCOLOR_VALUE, value);	break;

	case IDC_SPECULAR_RCOLOR:	SetDlgItemText(IDC_SPECULAR_RCOLOR_VALUE, value);	break;
	case IDC_SPECULAR_GCOLOR:	SetDlgItemText(IDC_SPECULAR_GCOLOR_VALUE, value);	break;
	case IDC_SPECULAR_BCOLOR:	SetDlgItemText(IDC_SPECULAR_BCOLOR_VALUE, value);	break;

	case IDC_AMBIENT_INTENSITY:	SetDlgItemText(IDC_AMBIENT_INTENSITY_VALUE, value);	break;
	case IDC_SHININESS:			SetDlgItemText(IDC_SHININESS_VALUE, value);			break;
	case IDC_TRANSPARENCY:		SetDlgItemText(IDC_TRANSPARENCY_VALUE, value);		break;
	}
}

float DialogObjectAppearance::getScrollBarValue(int id)
{
	CScrollBar *sb = (CScrollBar *)GetDlgItem(id);
	int pos = sb->GetScrollPos();
	return (float)pos/(float)SCROLLBAR_RANGE;
}	

int DialogObjectAppearance::getScrollBarID(CScrollBar *sb)
{
	if (sb == (CScrollBar *)GetDlgItem(IDC_DIFFUSE_RCOLOR))
		return IDC_DIFFUSE_RCOLOR;
	if (sb == (CScrollBar *)GetDlgItem(IDC_DIFFUSE_GCOLOR))
		return IDC_DIFFUSE_GCOLOR;
	if (sb == (CScrollBar *)GetDlgItem(IDC_DIFFUSE_BCOLOR))
		return IDC_DIFFUSE_BCOLOR;

	if (sb == (CScrollBar *)GetDlgItem(IDC_EMISSIVE_RCOLOR))
		return IDC_EMISSIVE_RCOLOR;
	if (sb == (CScrollBar *)GetDlgItem(IDC_EMISSIVE_GCOLOR))
		return IDC_EMISSIVE_GCOLOR;
	if (sb == (CScrollBar *)GetDlgItem(IDC_EMISSIVE_BCOLOR))
		return IDC_EMISSIVE_BCOLOR;

	if (sb == (CScrollBar *)GetDlgItem(IDC_SPECULAR_RCOLOR))
		return IDC_SPECULAR_RCOLOR;
	if (sb == (CScrollBar *)GetDlgItem(IDC_SPECULAR_GCOLOR))
		return IDC_SPECULAR_GCOLOR;
	if (sb == (CScrollBar *)GetDlgItem(IDC_SPECULAR_BCOLOR))
		return IDC_SPECULAR_BCOLOR;

	if (sb == (CScrollBar *)GetDlgItem(IDC_AMBIENT_INTENSITY))
		return IDC_AMBIENT_INTENSITY;
	if (sb == (CScrollBar *)GetDlgItem(IDC_SHININESS))
		return IDC_SHININESS;
	if (sb == (CScrollBar *)GetDlgItem(IDC_TRANSPARENCY))
		return IDC_TRANSPARENCY;

	return 0;
}

void DialogObjectAppearance::initializeScrollBar(int id, float value)
{
	CScrollBar *sb = (CScrollBar *)GetDlgItem(id);
	sb->SetScrollRange(0, SCROLLBAR_RANGE, FALSE);
	sb->SetScrollPos((int)(value/1.0f*(float)SCROLLBAR_RANGE));
	setScrollBarText(id);
}

MaterialNode *DialogObjectAppearance::getMaterialNode()
{
	AppearanceNode	*appearance = getAppearanceNode();
	assert(appearance);

	MaterialNode	*material	= appearance->getMaterialNodes();

	return material;
}

MaterialNode *DialogObjectAppearance::createMaterialNode()
{
	AppearanceNode	*appearance = getAppearanceNode();
	assert(appearance);

	MaterialNode *material = new MaterialNode();

	appearance->addChildNode(material);

	CtbTreeAddNode(material, appearance);

	return material;
}

ImageTextureNode *DialogObjectAppearance::getImageTextureNode()
{
	AppearanceNode	*appearance = getAppearanceNode();
	assert(appearance);

	ImageTextureNode *imgTex = appearance->getImageTextureNodes();

	return imgTex;
}

ImageTextureNode *DialogObjectAppearance::createImageTextureNode()
{
	AppearanceNode	*appearance = getAppearanceNode();
	assert(appearance);

	ImageTextureNode *imgTex = new ImageTextureNode();

	appearance->addChildNode(imgTex);

	CtbTreeAddNode(imgTex, appearance);

	return imgTex;
}


BOOL DialogObjectAppearance::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
/*	
	CStatic *sphereObject = new CStatic();
	CRect rect(0, 0, 64, 64);
	sphereObject->Create(NULL, WS_VISIBLE, rect, this, IDC_SPHERE_OBJECT);
*/
/*
	CWnd *wnd = GetDlgItem(IDC_SPHERE_OBJECT);

	OGLSetup();
    wglMakeCurrent(oglHdc, oglHrc);

    glDisable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glCullFace(GL_BACK);
	glDisable(GL_CULL_FACE);

	glDisable(GL_LIGHTING);
	glShadeModel(GL_FLAT);

    wglMakeCurrent(NULL, NULL);
*/	
	MaterialNode *material	= getMaterialNode();
	if (material == NULL)
		material = createMaterialNode();

	MaterialNode *orgMaterial = getOriginalMaterial();
	copyMaterialData(material, orgMaterial);

	float		color[3];

	material->getDiffuseColor(color);
	initializeScrollBar(IDC_DIFFUSE_RCOLOR, color[0]);
	initializeScrollBar(IDC_DIFFUSE_GCOLOR, color[1]);
	initializeScrollBar(IDC_DIFFUSE_BCOLOR, color[2]);

	material->getEmissiveColor(color);
	initializeScrollBar(IDC_EMISSIVE_RCOLOR, color[0]);
	initializeScrollBar(IDC_EMISSIVE_GCOLOR, color[1]);
	initializeScrollBar(IDC_EMISSIVE_BCOLOR, color[2]);

	material->getSpecularColor(color);
	initializeScrollBar(IDC_SPECULAR_RCOLOR, color[0]);
	initializeScrollBar(IDC_SPECULAR_GCOLOR, color[1]);
	initializeScrollBar(IDC_SPECULAR_BCOLOR, color[2]);

	initializeScrollBar(IDC_AMBIENT_INTENSITY, material->getAmbientIntensity());
	initializeScrollBar(IDC_SHININESS, material->getShininess());
	initializeScrollBar(IDC_TRANSPARENCY, material->getTransparency());

	ImageTextureNode *imgTex = getImageTextureNode();
	if (imgTex != NULL) {
		if (0 < imgTex->getNUrls()) {
			char *texFilename = imgTex->getUrl(0);
			setOriginalImageTextureFilename(texFilename);
		}
		else
			setOriginalImageTextureFilename("");
	}

	setImageTextureColor(NULL);

	displayTextureInfo(NULL);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogObjectAppearance::displayTextureInfo(FileImage *fileImage)
{
	if (fileImage == NULL) {
		SetDlgItemText(IDC_TEXTURE_FORMAT, "NONE");
		SetDlgItemInt(IDC_TEXTURE_WIDTH, 0);
		SetDlgItemInt(IDC_TEXTURE_HEIGHT, 0);
		return;
	}

	int format = fileImage->getFileType(); 
	switch(format) {
	case FILETYPE_JPEG:
		SetDlgItemText(IDC_TEXTURE_FORMAT, "JPEG"); break;
	case FILETYPE_GIF:
		SetDlgItemText(IDC_TEXTURE_FORMAT, "GIF"); break;
	case FILETYPE_PNG:
		SetDlgItemText(IDC_TEXTURE_FORMAT, "PNG"); break;
	case FILETYPE_TARGA:
		SetDlgItemText(IDC_TEXTURE_FORMAT, "TRAGA"); break;
	default:
		SetDlgItemText(IDC_TEXTURE_FORMAT, "NONE"); break;
	}

	int width = fileImage->getWidth(); 
	int height = fileImage->getHeight();
	SetDlgItemInt(IDC_TEXTURE_WIDTH, width);
	SetDlgItemInt(IDC_TEXTURE_HEIGHT, height);
}

RGBColor24 *DialogObjectAppearance::createImageTextureColor(ImageTextureNode *imgTex, int width, int height)
{
	if (imgTex == NULL)
		return NULL;

	FileImage *fileImage = imgTex->getFileImage();

	if (fileImage == NULL)
		return NULL;

	displayTextureInfo(fileImage);

	RGBColor24 *color = fileImage->getImage(width, height);

	return color;
}

void DialogObjectAppearance::drawImageTexture(CDC *dc, int width, int height)
{
	ImageTextureNode *imgTex = getImageTextureNode();

	if (imgTex == NULL)
		return;

	RGBColor24 *color = getImageTextureColor();

	if (color == NULL)
		return;

	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			int n = x + width*y;
			dc->SetPixel(x, y, RGB(color[n][0], color[n][1], color[n][2]));
		}
	}
}

void DialogObjectAppearance::drawImageTexture()
{
	ImageTextureNode *imgTex = getImageTextureNode();

	if (imgTex == NULL)
		return;

	CWnd *wnd = GetDlgItem(IDC_TEXTURE);

	RECT rect;
	wnd->GetClientRect(&rect);
	int width = rect.right;
	int height = rect.bottom;

	RGBColor24 *color = getImageTextureColor();

	if (color == NULL) {
		color = createImageTextureColor(imgTex, width, height);
		setImageTextureColor(color);
	}

	if (color == NULL)
		return;

	CDC *cdc = wnd->GetDC();

//	wnd->Invalidate();
//	wnd->UpdateWindow();

	CDC memDC;
	memDC.CreateCompatibleDC(cdc);

	CBitmap	bitmap;
	bitmap.CreateCompatibleBitmap(cdc, width, height);

	memDC.SelectObject(&bitmap);

	drawImageTexture(&memDC, width, height);

	cdc->BitBlt(0, 0, width, height, &memDC, 0, 0, SRCCOPY);
	
	wnd->ReleaseDC(cdc);
}

void DialogObjectAppearance::OnPaint() 
{
//	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
/*
	CWnd *wnd = GetDlgItem(IDC_SPHERE_OBJECT);
	
//	CDC *cdc = wnd->GetDC();
	
    wglMakeCurrent(oglHdc, oglHrc);
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 0.1f, 10000.0f);
	glViewport(0, 0, 64, 64);
	
	//wnd->Invalidate();
	//wnd->UpdateWindow();

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glFinish();
	SwapBuffers(wglGetCurrentDC());
	
	wglMakeCurrent(NULL, NULL);
	
	//cdc->TextOut(8, 8, "HELLO", 5);
	//wnd->ReleaseDC(cdc);
*/

	drawImageTexture();

	// 描画用メッセージとして CDialog::OnPaint() を呼び出してはいけません
}

void DialogObjectAppearance::updateMaterialNode()
{
	MaterialNode *material	= getMaterialNode();

	float	color[3];

	color[0] = getScrollBarValue(IDC_DIFFUSE_RCOLOR);
	color[1] = getScrollBarValue(IDC_DIFFUSE_GCOLOR);
	color[2] = getScrollBarValue(IDC_DIFFUSE_BCOLOR);
	material->setDiffuseColor(color);

	color[0] = getScrollBarValue(IDC_EMISSIVE_RCOLOR);
	color[1] = getScrollBarValue(IDC_EMISSIVE_GCOLOR);
	color[2] = getScrollBarValue(IDC_EMISSIVE_BCOLOR);
	material->setEmissiveColor(color);

	color[0] = getScrollBarValue(IDC_SPECULAR_RCOLOR);
	color[1] = getScrollBarValue(IDC_SPECULAR_GCOLOR);
	color[2] = getScrollBarValue(IDC_SPECULAR_BCOLOR);
	material->setSpecularColor(color);

	material->setAmbientIntensity(getScrollBarValue(IDC_AMBIENT_INTENSITY));
	material->setTransparency(getScrollBarValue(IDC_TRANSPARENCY));
	material->setShininess(getScrollBarValue(IDC_SHININESS));
}

void DialogObjectAppearance::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	int currentPos = pScrollBar->GetScrollPos();

	switch (nSBCode) {
	case SB_THUMBPOSITION:
		currentPos = nPos;
		break;
	case SB_LEFT:
	case SB_LINELEFT:
		currentPos--;
		break;
	case SB_RIGHT:
	case SB_LINERIGHT:
		currentPos++;
		break;
	case SB_PAGEUP:
		currentPos -= 10;
		break;
	case SB_PAGEDOWN:
		currentPos += 10;
		break;
	default:
		currentPos = currentPos;
	}

	if (currentPos < 0)
		currentPos = 0;

	if (255 < currentPos)
		currentPos = 255;

	pScrollBar->SetScrollPos(currentPos);
	setScrollBarText(getScrollBarID(pScrollBar));

	UpdatePerspectiveView();

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void DialogObjectAppearance::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	UpdatePerspectiveView();

	CDialog::OnOK();
}

void DialogObjectAppearance::OnCancel() 
{
	// TODO: この位置に特別な後処理を追加してください。
	MaterialNode *material	= getMaterialNode();

	MaterialNode *orgMaterial = getOriginalMaterial();
	copyMaterialData(orgMaterial, material);

	ImageTextureNode *imgTex = getImageTextureNode();
	if (imgTex != NULL) {
		char *orgFilename = getOriginalImageTextureFilename();
		int nUrls = imgTex->getNUrls();
		if(0 < nUrls) {
			CWaitCursor wait;
			imgTex->setUrl(0, orgFilename);
			imgTex->initialize();
		}
	}
	
	CDialog::OnCancel();
}

void DialogObjectAppearance::UpdatePerspectiveView() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	updateMaterialNode();	
	CtbUpdatePerspectiveView();
}

void DialogObjectAppearance::OnApply() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	UpdatePerspectiveView();	
}

static char BASED_CODE gTextureFileTypes[] = "JPEG Files (*.jpg)|*.jpg|GIF Files (*.gif)|*.gif|PNG Files (*.png)|*.png|TARGA Files (*.tga)|*.tga|All Files (*.*)|*.*||";

void DialogObjectAppearance::OnTextureSelect() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	CFileDialog dlg(TRUE, NULL, "*.jpg", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, gTextureFileTypes, this);
	if (dlg.DoModal() == IDOK) {
		CWaitCursor wait;
		ImageTextureNode *imgTex = getImageTextureNode();
		if (imgTex == NULL)
			imgTex = createImageTextureNode();
		
		char filename[1024];
		strcpy(filename, (char *)(LPCTSTR)dlg.GetPathName());

		int nUrls = imgTex->getNUrls();
		if(nUrls <= 0)
			imgTex->addUrl(filename);
		else
			imgTex->setUrl(0, filename);

		RGBColor24 *color = getImageTextureColor();
		if (color) {
			setImageTextureColor(NULL);
			delete []color;
		}

		imgTex->initialize();

	}

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);

	UpdatePerspectiveView();

	InvalidateRect(NULL);
	UpdateWindow();
}

void DialogObjectAppearance::OnTextureDelete() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください

	ImageTextureNode *imgTex = getImageTextureNode();
	if (imgTex != NULL) {
		int nUrls = imgTex->getNUrls();
		if(0 < nUrls) {
			CWaitCursor wait;
			imgTex->setUrl(0, "");
			imgTex->initialize();

			RGBColor24 *color = getImageTextureColor();
			if (color) {
				setImageTextureColor(NULL);
				delete []color;
			}
		}
	}

	UpdatePerspectiveView();

	InvalidateRect(NULL);
	UpdateWindow();
}

/////////////////////////////////////////////////////////////////////////////
//	OpenGL
/////////////////////////////////////////////////////////////////////////////

static unsigned char threeto8[8] = 
{
	0, 0111>>1, 0222>>1, 0333>>1, 0444>>1, 0555>>1, 0666>>1, 0377
};

static unsigned char twoto8[4] = 
{
	0, 0x55, 0xaa, 0xff
};

static unsigned char oneto8[2] = 
{
	0, 255
};

static int defaultOverride[13] = 
{
	0, 3, 24, 27, 64, 67, 88, 173, 181, 236, 247, 164, 91
};

static PALETTEENTRY defaultPalEntry[20] = 
{
	{ 0,   0,   0,    0 },
	{ 0x80,0,   0,    0 },
	{ 0,   0x80,0,    0 },
	{ 0x80,0x80,0,    0 },
	{ 0,   0,   0x80, 0 },
	{ 0x80,0,   0x80, 0 },
	{ 0,   0x80,0x80, 0 },
	{ 0xC0,0xC0,0xC0, 0 },

	{ 192, 220, 192,  0 },
	{ 166, 202, 240,  0 },
	{ 255, 251, 240,  0 },
	{ 160, 160, 164,  0 },

	{ 0x80,0x80,0x80, 0 },
	{ 0xFF,0,   0,    0 },
	{ 0,   0xFF,0,    0 },
	{ 0xFF,0xFF,0,    0 },
	{ 0,   0,   0xFF, 0 },
	{ 0xFF,0,   0xFF, 0 },
	{ 0,   0xFF,0xFF, 0 },
	{ 0xFF,0xFF,0xFF, 0 }
};

void DialogObjectAppearance::OGLSetup(CWnd *wnd)
{
    PIXELFORMATDESCRIPTOR pfd;
    int         n;
//	GLfloat		fMaxObjSize, fAspect;
//	GLfloat		fNearPlane, fFarPlane;

    oglDC = new CClientDC(wnd);

    ASSERT(oglDC != NULL);

    if (!OGLSetupPixelFormat())
        return;

    n = ::GetPixelFormat(oglDC->GetSafeHdc());
    ::DescribePixelFormat(oglDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	OGLCreateRGBPalette();

	oglHdc = oglDC->GetSafeHdc(); 
    oglHrc = wglCreateContext(oglHdc);
    wglMakeCurrent(oglHdc, oglHrc);

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);

    wglMakeCurrent(NULL, NULL);
}

BOOL DialogObjectAppearance::OGLSetupPixelFormat()
{
    static PIXELFORMATDESCRIPTOR pfd = 
	{
        sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
        1,                              // version number
        PFD_DRAW_TO_WINDOW |            // support window
        PFD_SUPPORT_OPENGL |			// support OpenGL
        PFD_DOUBLEBUFFER,				// double buffered
        PFD_TYPE_RGBA,                  // RGBA type
        24,                             // 24-bit color depth
        0, 0, 0, 0, 0, 0,               // color bits ignored
        0,                              // no alpha buffer
        0,                              // shift bit ignored
        0,                              // no accumulation buffer
        0, 0, 0, 0,                     // accum bits ignored
        32,                             // 32-bit z-buffer
        0,                              // no stencil buffer
        0,                              // no auxiliary buffer
        PFD_MAIN_PLANE,                 // main layer
        0,                              // reserved
        0, 0, 0                         // layer masks ignored
    };
    int pixelformat;

    if ( (pixelformat = ChoosePixelFormat(oglDC->GetSafeHdc(), &pfd)) == 0 )
    {
        MessageBox("ChoosePixelFormat failed");
        return FALSE;
    }

    if (SetPixelFormat(oglDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
    {
        MessageBox("SetPixelFormat failed");
        return FALSE;
    }

    return TRUE;
}

unsigned char DialogObjectAppearance::OGLComponentFromIndex(int i, UINT nbits, UINT shift)
{
    unsigned char val;

    val = (unsigned char) (i >> shift);
    switch (nbits) 
	{

    case 1:
        val &= 0x1;
        return oneto8[val];
    case 2:
        val &= 0x3;
        return twoto8[val];
    case 3:
        val &= 0x7;
        return threeto8[val];

    default:
        return 0;
    }
}


void DialogObjectAppearance::OGLCreateRGBPalette()
{
    PIXELFORMATDESCRIPTOR pfd;
    LOGPALETTE *pPal;
    int n, i;
 
    n = ::GetPixelFormat(oglDC->GetSafeHdc());
    ::DescribePixelFormat(oglDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

    if (pfd.dwFlags & PFD_NEED_PALETTE)
    {
        n = 1 << pfd.cColorBits;
        pPal = (PLOGPALETTE) new char[sizeof(LOGPALETTE) + n * sizeof(PALETTEENTRY)];

        ASSERT(pPal != NULL);

        pPal->palVersion = 0x300;
        pPal->palNumEntries = n;
        for (i=0; i<n; i++)
        {
            pPal->palPalEntry[i].peRed =
                    OGLComponentFromIndex(i, pfd.cRedBits, pfd.cRedShift);
            pPal->palPalEntry[i].peGreen =
                    OGLComponentFromIndex(i, pfd.cGreenBits, pfd.cGreenShift);
            pPal->palPalEntry[i].peBlue =
                    OGLComponentFromIndex(i, pfd.cBlueBits, pfd.cBlueShift);
            pPal->palPalEntry[i].peFlags = 0;
        }

        /* fix up the palette to include the default GDI palette */
        if ((pfd.cColorBits == 8)                           &&
            (pfd.cRedBits   == 3) && (pfd.cRedShift   == 0) &&
            (pfd.cGreenBits == 3) && (pfd.cGreenShift == 3) &&
            (pfd.cBlueBits  == 2) && (pfd.cBlueShift  == 6)
           )
        {
			for (i = 1 ; i <= 12 ; i++)
                pPal->palPalEntry[defaultOverride[i]] = defaultPalEntry[i];
        }

        oglPalette.CreatePalette(pPal);
        delete pPal;

        oglOldPalette = oglDC->SelectPalette(&oglPalette, FALSE);
        oglDC->RealizePalette();
    }
}

