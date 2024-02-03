// ModuleFloating.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "ModuleFloating.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModuleFloating

IMPLEMENT_DYNAMIC(ModuleFloating, CPropertySheet)

ModuleFloating::ModuleFloating(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&mModuleWorldPage);
	AddPage(&mModuleObjectPage);
	AddPage(&mModuleMaterialPage);
	AddPage(&mModuleViewPage);
	AddPage(&mModuleLightPage);
	AddPage(&mModuleInterpPage);
	AddPage(&mModuleNumericPage);
	AddPage(&mModuleMathPage);
	AddPage(&mModuleGeomPage);
	AddPage(&mModuleBooleanPage);
	AddPage(&mModuleFilterPage);
	AddPage(&mModuleMiscPage);

	mbInitialized = false;
}

ModuleFloating::ModuleFloating(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&mModuleWorldPage);
	AddPage(&mModuleObjectPage);
	AddPage(&mModuleMaterialPage);
	AddPage(&mModuleViewPage);
	AddPage(&mModuleLightPage);
	AddPage(&mModuleInterpPage);
	AddPage(&mModuleNumericPage);
	AddPage(&mModuleMathPage);
	AddPage(&mModuleGeomPage);
	AddPage(&mModuleBooleanPage);
	AddPage(&mModuleFilterPage);
	AddPage(&mModuleMiscPage);

	mbInitialized = false;
}

ModuleFloating::~ModuleFloating()
{
}


BEGIN_MESSAGE_MAP(ModuleFloating, CPropertySheet)
	//{{AFX_MSG_MAP(ModuleFloating)
	ON_WM_CREATE()
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModuleFloating ���b�Z�[�W �n���h��

BOOL ModuleFloating::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

int ModuleFloating::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPropertySheet::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void ModuleFloating::OnMove(int x, int y) 
{
	CPropertySheet::OnMove(x, y);
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������

	if (mbInitialized == false)
		return;

	RECT	rect;
	GetWindowRect(&rect);
	RegKeyWriteValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_DIAGRAMMODULE, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top);
}

BOOL ModuleFloating::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	return CPropertySheet::PreCreateWindow(cs);
}

void ModuleFloating::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	CPropertySheet::OnLButtonDown(nFlags, point);
}

void ModuleFloating::OnClose() 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	return;

	CPropertySheet::OnClose();
}

BOOL ModuleFloating::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// TODO: ���̈ʒu�ɌŗL�̃R�[�h��ǉ����Ă�������

	int	x, y, width, height;
	if (RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_DIAGRAMMODULE, &x, &y, &width, &height)) 
		SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE);
	else
		SetWindowPos(NULL, 0, 450, 0, 0, SWP_NOSIZE);

	static CFont	mFont;

	LOGFONT	lf;
	lf.lfHeight = 1200;
	strcpy(lf.lfFaceName, "Arial");

	lf.lfHeight = 90;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 700;
	lf.lfItalic = FALSE;
	lf.lfUnderline = FALSE;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = 0;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	
	mFont.DeleteObject();
	mFont.CreatePointFontIndirect(&lf);
	SetFont(&mFont);

	mbInitialized = true;
	
	return bResult;
}

BOOL ModuleFloating::DestroyWindow() 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������

	return CPropertySheet::DestroyWindow();
}
