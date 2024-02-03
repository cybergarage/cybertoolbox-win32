// ModuleConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "ModuleConfig.h"
#include "StringFn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModuleConfig ダイアログ


ModuleConfig::ModuleConfig(CWnd* pParent /*=NULL*/)
	: CDialog(ModuleConfig::IDD, pParent)
{
	mIcon = NULL;
	setModuleType(NULL);

	//{{AFX_DATA_INIT(ModuleConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void ModuleConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModuleConfig)
                // メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModuleConfig, CDialog)
	//{{AFX_MSG_MAP(ModuleConfig)
	ON_BN_CLICKED(IDC_SCRIPT_SELECT, OnScriptSelect)
	ON_BN_CLICKED(IDC_MODULE_ICON_SELECT, OnModuleIconSelect)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////
//
//	Event Field
//
///////////////////////////////////////////////////////////////////////////

void ModuleConfig::updateEventField(Field *field[], int idcEventInName, int idcEventInType) 
{
	BOOL		bEventIn	= TRUE;
	BOOL		bEventOut	= TRUE;

	for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		Field	*eventField = field[n];
		CWnd	*eventTypeWnd = GetDlgItem(idcEventInType+n);
		CWnd	*eventNameWnd = GetDlgItem(idcEventInName+n);
		if (eventField->getType() || bEventIn) {
			if (eventField->getType()) {
				eventTypeWnd->EnableWindow(TRUE);
				eventNameWnd->EnableWindow(TRUE);
				CheckDlgButton(idcEventInType+n, 1);
				SetDlgItemText(idcEventInName+n, eventField->getName());
			}
			else {
				eventTypeWnd->EnableWindow(TRUE);
				eventNameWnd->EnableWindow(FALSE);
				CheckDlgButton(idcEventInType+n, 0);
				SetDlgItemText(idcEventInName+n, NULL);
				bEventIn = FALSE;
			}
		}
		else {
			eventTypeWnd->EnableWindow(FALSE);
			eventNameWnd->EnableWindow(FALSE);
			SetDlgItemText(idcEventInName+n, NULL);
			bEventIn = FALSE;
		}
	}
}

void ModuleConfig::updateEventField() 
{
	CModuleType *cmType = getModuleType();

	char	eventName[255];
	for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		Field	*eventIn = cmType->getEventInField(n);
		if (eventIn->getType()) {
			GetDlgItemText(IDC_EVENTIN_NAME1+n, eventName, 255);
			eventIn->setName(eventName);
		}
		Field	*eventOut = cmType->getEventOutField(n);
		if (eventOut->getType()) {
			GetDlgItemText(IDC_EVENTOUT_NAME1+n, eventName, 255);
			eventOut->setName(eventName);
		}
	}

	cmType->compact();

	updateEventField(cmType->mEventInType, IDC_EVENTIN_NAME1, IDC_EVENTIN_ACTIVE1);
	updateEventField(cmType->mEventOutType, IDC_EVENTOUT_NAME1, IDC_EVENTOUT_ACTIVE1);
}

void ModuleConfig::updateDialogField()
{
	CModuleType *cmType = getModuleType();
	SendDlgItemMessage(IDC_CLASS_NAME, CB_SELECTSTRING, 0, (DWORD)cmType->getClassName());

	updateEventField();	
}

#define NAME_MAXLEN		128
#define PATH_MAXLEN		512

void ModuleConfig::getDialogField()
{
	char	className		[NAME_MAXLEN];
	char	moduleName		[NAME_MAXLEN];
	char	fieldInName		[MODULE_INOUTNODE_MAXNUM][NAME_MAXLEN];
	char	fieldOutName	[MODULE_INOUTNODE_MAXNUM][NAME_MAXLEN];
	char	scriptName		[PATH_MAXLEN];
	char	iconName		[PATH_MAXLEN];
	BOOL	executionNode;
	int		n;

	GetDlgItemText(IDC_CLASS_NAME, className, NAME_MAXLEN);
	GetDlgItemText(IDC_MODULE_NAME, moduleName, NAME_MAXLEN);
	GetDlgItemText(IDC_SCRIPT_NAME, scriptName, PATH_MAXLEN);
	GetDlgItemText(IDC_MODULE_ICON_NAME, iconName, PATH_MAXLEN);

	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		if (IsDlgButtonChecked(IDC_EVENTIN_ACTIVE1+n))
			GetDlgItemText(IDC_EVENTIN_NAME1+n,		fieldInName[n],			NAME_MAXLEN);
		else
			fieldInName[n][0] = '\0'; 

		if (IsDlgButtonChecked(IDC_EVENTOUT_ACTIVE1+n))
			GetDlgItemText(IDC_EVENTOUT_NAME1+n,	fieldOutName[n],		NAME_MAXLEN);
		else
			fieldOutName[n][0] = '\0'; 
	}

	executionNode = IsDlgButtonChecked(IDC_EXECUTION_NODE);


	CModuleType *cmType = getModuleType();
	
	cmType->setClassName(className);
	cmType->setName(moduleName);
	cmType->setScriptName(scriptName);
	cmType->setIconName(iconName);
	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		if (StringLength(fieldInName[n]))
			cmType->setEventInField(n, fieldInName[n], "SFString");
		if (StringLength(fieldOutName[n]))
			cmType->setEventOutField(n, fieldOutName[n], "SFString");
	}

	cmType->setExecutionNode(executionNode);
}

/////////////////////////////////////////////////////////////////////////////
// ModuleConfig メッセージ ハンドラ

static char BASED_CODE gJavaFileTypes[] = "Java Class Files (*.class)|*.class|All Files (*.*)|*.*||";

void ModuleConfig::OnScriptSelect() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CFileDialog dlg(TRUE, "class", "*.class", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, gJavaFileTypes, this);
	if (dlg.DoModal() == IDOK) {
		CWaitCursor wait;
		SetDlgItemText(IDC_SCRIPT_NAME, (char *)(LPCTSTR)dlg.GetPathName());
	}
	
}

char BASED_CODE gIconFileTypes[] = "ICON Files (*.ico)|*.ico|All Files (*.*)|*.*||";

void ModuleConfig::OnModuleIconSelect() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CFileDialog dlg(TRUE, "ico", "*.ico", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, gIconFileTypes, this);
	if (dlg.DoModal() == IDOK) {
		CWaitCursor wait;
		SetDlgItemText(IDC_MODULE_ICON_NAME, (char *)(LPCTSTR)dlg.GetPathName());
		mIcon = LoadIconFromFile((char *)(LPCTSTR)dlg.GetPathName());
		InvalidateRect(NULL);
	}
}

void ModuleConfig::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	if (mIcon) {
		CWnd *wnd = GetDlgItem(IDC_MODULE_ICON);
		CPaintDC dc(wnd);
		dc.DrawIcon(0, 0, mIcon->GetHandle());
	}
	// 描画用メッセージとして CDialog::OnPaint() を呼び出してはいけません
}

BOOL ModuleConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	updateDialogField();
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

BOOL ModuleConfig::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
//	switch (HIWORD(wParam)) {
//	case CBN_SELCHANGE:
		switch (LOWORD(wParam)) {
		case IDC_EVENTIN_ACTIVE1:
		case IDC_EVENTIN_ACTIVE2:
		case IDC_EVENTIN_ACTIVE3:
		case IDC_EVENTIN_ACTIVE4:
			{
				CModuleType *cmType = getModuleType();
				if (IsDlgButtonChecked(LOWORD(wParam)))
					cmType->setEventInFieldType(LOWORD(wParam) - IDC_EVENTIN_ACTIVE1, "SFString");
				else
					cmType->setEventInFieldType(LOWORD(wParam) - IDC_EVENTIN_ACTIVE1, NULL);
				updateEventField();
			}
			break;
		case IDC_EVENTOUT_ACTIVE1:
		case IDC_EVENTOUT_ACTIVE2:
		case IDC_EVENTOUT_ACTIVE3:
		case IDC_EVENTOUT_ACTIVE4:
			{
				CModuleType *cmType = getModuleType();
				if (IsDlgButtonChecked(LOWORD(wParam)))
					cmType->setEventOutFieldType(LOWORD(wParam) - IDC_EVENTOUT_ACTIVE1, "SFString");
				else
					cmType->setEventOutFieldType(LOWORD(wParam) - IDC_EVENTOUT_ACTIVE1, NULL);
				updateEventField();
			}
			break;
		}
//		break;
//	}
	return CDialog::OnCommand(wParam, lParam);
}

void ModuleConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	getDialogField();
	CDialog::OnOK();
}

void ModuleConfig::OnCancel() 
{
	// TODO: この位置に特別な後処理を追加してください。
	
	CDialog::OnCancel();
}
