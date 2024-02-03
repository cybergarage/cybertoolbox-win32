// CyberToolBox.cpp : アプリケーション用クラスの機能定義を行います。
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
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
	// 標準のファイル基本ドキュメント コマンド
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// 標準の印刷セットアップ コマンド
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp クラスの構築

CCyberToolBoxApp::CCyberToolBoxApp()
{
	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCyberToolBoxApp オブジェクト

CCyberToolBoxApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp クラスの初期化

BOOL CCyberToolBoxApp::InitInstance()
{
	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さく
	//  したければ以下の特定の初期化ルーチンの中から不必要なもの
	//  を削除してください。

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
	Enable3dControls();			// 共有 DLL の中で MFC を使用する場合にはここを呼び出してください。
#else
	Enable3dControlsStatic();	// MFC と静的にリンクしている場合にはここを呼び出してください。
#endif

	LoadStdProfileSettings();  // 標準の INI ファイルのオプションをローﾄﾞします (MRU を含む)

	// アプリケーション用のドキュメント テンプレートを登録します。ドキュメント テンプレート
	//  はドキュメント、フレーム ウィンドウとビューを結合するために機能します。

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CCyberToolBoxDoc),
		RUNTIME_CLASS(CMainFrame),       // メイン SDI フレーム ウィンドウ
		RUNTIME_CLASS(CCyberToolBoxView));
	AddDocTemplate(pDocTemplate);

	// DDE、file open など標準のシェル コマンドのコマンドラインを解析します。
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// コマンドラインでディスパッチ コマンドを指定します。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	mDgmDocTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDiagramDoc),
		RUNTIME_CLASS(CDiagramFrame),       // メイン SDI フレーム ウィンドウ
		RUNTIME_CLASS(CDiagramView));
	AddDocTemplate(mDgmDocTemplate);

	mpPerspectiveDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(PerspectiveDoc),
		RUNTIME_CLASS(PerspectiveFrame),       // メイン SDI フレーム ウィンドウ
		RUNTIME_CLASS(PerspectiveView));
	AddDocTemplate(mpPerspectiveDocTemplate);
	mpPerspectiveDocument = mpPerspectiveDocTemplate->OpenDocumentFile(NULL);

	mpOrthoDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(OrthoDoc),
		RUNTIME_CLASS(OrthoFrame),       // メイン SDI フレーム ウィンドウ
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
// アプリケーションのバージョン情報で使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard 仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
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

// ダイアログを実行するためのアプリケーション コマンド
void CCyberToolBoxApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp コマンド

void CCyberToolBoxApp::resetSceneGraphTree()
{
	mTreeView->resetSceneGraphTree();
}

////////////////////////////////////////
//	Aboutダイアログ
////////////////////////////////////////

int CAboutDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	
	return 0;
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください

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

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void CAboutDlg::OnSetLicenceCode() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
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
	// TODO: この位置にその他の検証用のコードを追加してください
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

