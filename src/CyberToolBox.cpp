// CyberToolBox.cpp : �A�v���P�[�V�����p�N���X�̋@�\��`���s���܂��B
//

#include "stdafx.h"
#include "CyberToolBox.h"

#include "MainFrm.h"
#include "CyberToolBoxDoc.h"
#include "CyberToolBoxView.h"

#include "OrthoView.h"
#include "OrthoFrame.h"
#include "OrthoDoc.h"

#include "PerspectiveView.h"
#include "PerspectiveFrame.h"
#include "PerspectiveDoc.h"

#include "DiagramView.h"
#include "DiagramFrame.h"
#include "DiagramDoc.h"

#include "ModuleFloating.h"
#include "PrimitiveFloating.h"

#include "RegKey.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

#include "LicenceCode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp

BEGIN_MESSAGE_MAP(CCyberToolBoxApp, CWinApp)
	//{{AFX_MSG_MAP(CCyberToolBoxApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
	// �W���̃t�@�C����{�h�L�������g �R�}���h
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// �W���̈���Z�b�g�A�b�v �R�}���h
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp �N���X�̍\�z

CCyberToolBoxApp::CCyberToolBoxApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCyberToolBoxApp �I�u�W�F�N�g

CCyberToolBoxApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp �N���X�̏�����

BOOL CCyberToolBoxApp::InitInstance()
{
	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������
	//  ��������Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ���
	//  ���폜���Ă��������B

#ifndef _DEBUG
#ifndef INSTALL_BIN_DIR
	char moduleFileName[_MAX_PATH];
	HMODULE module = GetModuleHandle(AfxGetAppName());
	GetModuleFileName(module, moduleFileName, sizeof(moduleFileName)-1);
	SetCurrentDirectory(GetDirectoryName(moduleFileName));
//	MessageBox(NULL, GetDirectoryName(moduleFileName), "Current Directory", IDOK);
#endif
#endif

	WorldInit();

#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL �̒��� MFC ���g�p����ꍇ�ɂ͂������Ăяo���Ă��������B
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N���Ă���ꍇ�ɂ͂������Ăяo���Ă��������B
#endif

	LoadStdProfileSettings();  // �W���� INI �t�@�C���̃I�v�V���������[�ނ��܂� (MRU ���܂�)

	// �A�v���P�[�V�����p�̃h�L�������g �e���v���[�g��o�^���܂��B�h�L�������g �e���v���[�g
	//  �̓h�L�������g�A�t���[�� �E�B���h�E�ƃr���[���������邽�߂ɋ@�\���܂��B

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCyberToolBoxDoc),
		RUNTIME_CLASS(CMainFrame),       // ���C�� SDI �t���[�� �E�B���h�E
		RUNTIME_CLASS(CCyberToolBoxView));
	AddDocTemplate(pDocTemplate);

	// DDE�Afile open �ȂǕW���̃V�F�� �R�}���h�̃R�}���h���C������͂��܂��B
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// �R�}���h���C���Ńf�B�X�p�b�` �R�}���h���w�肵�܂��B
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	mDgmDocTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDiagramDoc),
		RUNTIME_CLASS(CDiagramFrame),       // ���C�� SDI �t���[�� �E�B���h�E
		RUNTIME_CLASS(CDiagramView));
	AddDocTemplate(mDgmDocTemplate);

	mpPerspectiveDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(PerspectiveDoc),
		RUNTIME_CLASS(PerspectiveFrame),       // ���C�� SDI �t���[�� �E�B���h�E
		RUNTIME_CLASS(PerspectiveView));
	AddDocTemplate(mpPerspectiveDocTemplate);
	mpPerspectiveDocument = mpPerspectiveDocTemplate->OpenDocumentFile(NULL);

	mpOrthoDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(OrthoDoc),
		RUNTIME_CLASS(OrthoFrame),       // ���C�� SDI �t���[�� �E�B���h�E
		RUNTIME_CLASS(OrthoView));
	AddDocTemplate(mpOrthoDocTemplate);
	mpOrthoDocument = mpOrthoDocTemplate->OpenDocumentFile(NULL);

/*
	setSceneGraphView(view);
*/
//	GetWorld()->createJavaConsole();

	m_pMainWnd->SetWindowText(_T("CyberToolbox"));

	assert(SetPriorityClass(GetCurrentProcess(),HIGH_PRIORITY_CLASS) == TRUE);

	return TRUE;
}

CCyberToolBoxApp::~CCyberToolBoxApp()
{
//	GetWorld()->clearSceneGraph();
	WorldQuit();
}

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard ���z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnSetLicenceCode();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_SET_LICENCE_CODE, OnSetLicenceCode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// �_�C�A���O�����s���邽�߂̃A�v���P�[�V���� �R�}���h
void CCyberToolBoxApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp �R�}���h

void CCyberToolBoxApp::resetSceneGraphTree()
{
	mTreeView->resetSceneGraphTree();
}

////////////////////////////////////////
//	About�_�C�A���O
////////////////////////////////////////

int CAboutDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: ���̈ʒu�ɌŗL�̍쐬�p�R�[�h��ǉ����Ă�������
	
	return 0;
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������

#ifdef USE_LICENCE_CHK
	char id[64];
	if (RegKeyGetValue(REGKEY_SECTION_LICENCE, REGKEY_KEY_SOFTWARE_PRODUCT_ID, id) == FALSE || CheckSoftwareProductID(id) == false) {
		strcpy(id, GenerateSoftwareProductID());
		RegKeyWriteValue(REGKEY_SECTION_LICENCE, REGKEY_KEY_SOFTWARE_PRODUCT_ID, id);
	}

	SetDlgItemText(IDC_SOFTWARE_PRODUCT_ID, id);

	bool licence = false;
	char licenceCode[64];
	if (RegKeyGetValue(REGKEY_SECTION_LICENCE, REGKEY_KEY_LICENCE_CODE, licenceCode) == TRUE) 
		licence = CheckLicenceCode(licenceCode);
	
	if (licence = true)
		SetDlgItemText(IDC_LICENCECODE, licenceCode);
#endif

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CAboutDlg::OnSetLicenceCode() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char licenceCode[64];
	GetDlgItemText(IDC_LICENCECODE, licenceCode, 63);
	bool licence = CheckLicenceCode(licenceCode);
	
	if (licence == true) {
		RegKeyWriteValue(REGKEY_SECTION_LICENCE, REGKEY_KEY_LICENCE_CODE, licenceCode);
	}
	else {
		SetDlgItemText(IDC_LICENCECODE, "");
		MessageBeep(0);
	}

	CtbGetTreeView()->updateSaveButton();	
}



void CAboutDlg::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	OnSetLicenceCode();
	
	CDialog::OnOK();
}

////////////////////////////////////////
//	Global Functions
////////////////////////////////////////

void CtbModuleFloatingSetTopMost()
{
	HWND	hwnd = (theApp.getModuleFloating())->GetSafeHwnd();
	LONG	value = GetWindowLong(hwnd, GWL_EXSTYLE);
	
	SetWindowLong(hwnd, GWL_EXSTYLE, value |  WS_EX_TOPMOST);
}

void CtbModuleFloatingReleaseTopMost()
{
	HWND	hwnd = (theApp.getModuleFloating())->GetSafeHwnd();
	LONG	value = GetWindowLong(hwnd, GWL_EXSTYLE);
	if (value & WS_EX_TOPMOST)
		value ^= WS_EX_TOPMOST;
	SetWindowLong(hwnd, GWL_EXSTYLE, value);
}

ModuleFloating *CtbGetModuleFloating()
{
	return theApp.getModuleFloating();
}

void CtbModuleFloatingShowWindow(int nCmdShow)
{
	(theApp.getModuleFloating())->ShowWindow(nCmdShow);
}

void CtbPrimitiveFloatingShowWindow(int nCmdShow)
{
	CtbGetOrthoView()->getPrimitiveFloating()->ShowWindow(nCmdShow);
}

void CtbTreeAddNode(Node *node, Node *parentNode)
{
	CtbGetTreeView()->addSceneGraphNode(node, parentNode);
}

void CtbTreeDeleteNode(Node *node)
{
	CtbGetTreeView()->deleteSceneGraphNode(node);
}

CCyberToolBoxView *CtbGetTreeView()
{
	return ((CCyberToolBoxApp *)AfxGetApp())->getTreeView();
}

CCyberToolBoxApp *CtbGetApp()
{
	return (CCyberToolBoxApp *)AfxGetApp();
}

PerspectiveView *CtbGetPerspectiveView()
{
	POSITION pos = (((CCyberToolBoxApp *)AfxGetApp())->mpPerspectiveDocument)->GetFirstViewPosition();
	return (PerspectiveView *)(((CCyberToolBoxApp *)AfxGetApp())->mpPerspectiveDocument)->GetNextView(pos);
}

OrthoView *CtbGetOrthoView()
{
	POSITION pos = (((CCyberToolBoxApp *)AfxGetApp())->mpOrthoDocument)->GetFirstViewPosition();
	return (OrthoView *)(((CCyberToolBoxApp *)AfxGetApp())->mpOrthoDocument)->GetNextView(pos);
}

void CtbUpdatePerspectiveView()
{
	PerspectiveView *pview = CtbGetPerspectiveView();
	if (pview->IsWindowVisible()) {
		pview->InvalidateRect(NULL);
		pview->UpdateWindow();
	}
}

void CtbUpdateOrthoView()
{
	OrthoView *oview = CtbGetOrthoView();
	if (oview->IsWindowVisible()) {
		oview->InvalidateRect(NULL);
		oview->UpdateWindow();
	}
}

