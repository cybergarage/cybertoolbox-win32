// DialogMFieldConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogMFieldConfig.h"
#include "SceneGraph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogMFieldConfig ダイアログ


DialogMFieldConfig::DialogMFieldConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogMFieldConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogMFieldConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogMFieldConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogMFieldConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogMFieldConfig, CDialog)
	//{{AFX_MSG_MAP(DialogMFieldConfig)
	ON_NOTIFY(NM_DBLCLK, IDC_SFVALUE_LIST, OnDblclkSfvalueList)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_INSERT, OnInsert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogMFieldConfig メッセージ ハンドラ

BOOL DialogMFieldConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CWaitCursor	cursor;

	setTitle(this);

	MField *mfield = (MField *)getField();

    CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_SFVALUE_LIST);

	pList->InsertColumn(0, "[n]", LVCFMT_LEFT, 50, 0);
	pList->InsertColumn(2, "Value", LVCFMT_LEFT, 170, 2);

	int		n;
	char	value[1024];

	int nSize = mfield->getSize();
	for (n=0; n<nSize; n++) {
		Field *field = mfield->getObject(n);
		sprintf(value, "[%d]", n);
		pList->InsertItem(n, value);
		pList->SetItem(n, 1, LVIF_TEXT, field->getValue(value, 1024), 0, 0, 0, 0);
	}

	saveOriginalMField(mfield);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

bool OpenFieldDialog(Node *node, Field *field, CWnd *parentWnd);

void DialogMFieldConfig::OnDblclkSfvalueList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	HWND hwnd = pNMHDR->hwndFrom;
	CPoint mpos;
	GetCursorPos(&mpos);
	::ScreenToClient(hwnd, &mpos);

    CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_SFVALUE_LIST);
	int item = pList->HitTest(mpos);

	MField *mfield = (MField *)getField();
	Field *field = mfield->getObject(item);
	if (field) {
		if (OpenFieldDialog(getNode(), field, this) == true) {
			char	value[1024];
			pList->SetItem(item, 1, LVIF_TEXT, field->getValue(value, 1024), 0, 0, 0, 0);
		}
	}

	*pResult = 0;
}

int DialogMFieldConfig::getSelectedItem()
{
	CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_SFVALUE_LIST);

	int item = -1;

	int nSize = pList->GetItemCount();
	for (int n=0; n<nSize; n++) {
		if (pList->GetItemState(n, LVIS_SELECTED)) {
			item = n;
			break;
		}
	}

	return item;
}

void DialogMFieldConfig::resetMFieldNumber()
{
	CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_SFVALUE_LIST);

	char value[32];

	int nSize = pList->GetItemCount();
	for (int n=0; n<nSize; n++) {
		sprintf(value, "[%d]", n);
		pList->SetItem(n, 0, LVIF_TEXT, value, 0, 0, 0, 0);
	}
}

void DialogMFieldConfig::saveOriginalMField(MField *mfield) 
{
	switch (mfield->getType()) {
	case fieldTypeMFFloat:
		mOrgMField = new MFFloat();
		break;
	case fieldTypeMFInt32:
		mOrgMField = new MFInt32();
		break;
	case fieldTypeMFVec2f:
		mOrgMField = new MFVec2f();
		break;
	case fieldTypeMFVec3f:
		mOrgMField = new MFVec3f();
		break;
	case fieldTypeMFString:
		mOrgMField = new MFString();
		break;
	case fieldTypeMFColor:
		mOrgMField = new MFColor();
		break;
	case fieldTypeMFTime:
		mOrgMField = new MFTime();
		break;
	case fieldTypeMFRotation:
		mOrgMField = new MFRotation();
		break;
	default:
		mOrgMField = NULL;
		break;
	}

	mOrgMField->setValue(mfield);
}

Field *DialogMFieldConfig::createNewField(MField *mfield) 
{
	Field *field = NULL;

	switch (mfield->getType()) {
	case fieldTypeMFFloat:
		field = new SFFloat();
		break;
	case fieldTypeMFInt32:
		field = new SFInt32();
		break;
	case fieldTypeMFVec2f:
		field = new SFVec2f();
		break;
	case fieldTypeMFVec3f:
		field = new SFVec3f();
		break;
	case fieldTypeMFString:
		field = new SFString();
		break;
	case fieldTypeMFColor:
		field = new SFColor();
		break;
	case fieldTypeMFTime:
		field = new SFTime();
		break;
	case fieldTypeMFRotation:
		field = new SFRotation();
		break;
	case fieldTypeMFNode:
		field = new SFNode();
		break;
	}
	
	return field;
}

void DialogMFieldConfig::insertItem(int n)
{
    CListCtrl	*pList = (CListCtrl*) GetDlgItem(IDC_SFVALUE_LIST);
	MField		*mfield = (MField *)getField();
	Field		*field = createNewField(mfield);
	
	mfield->add(field);

	char	value[1024];
	
	sprintf(value, "[%d]", n);
	pList->InsertItem(n, value);
	field->getValue(value, 1023);
	pList->SetItem(n, 1, LVIF_TEXT, value, 0, 0, 0, 0);
}

void DialogMFieldConfig::OnAdd() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください

	insertItem(((MField *)getField())->getSize());
}

void DialogMFieldConfig::OnDelete() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
    CListCtrl	*pList = (CListCtrl*) GetDlgItem(IDC_SFVALUE_LIST);
	MField		*mfield = (MField *)getField();

	int item = getSelectedItem();

	if (item != -1) {
		pList->DeleteItem(item);
		mfield->remove(item);
		resetMFieldNumber();
	}
}

void DialogMFieldConfig::OnInsert() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください

	int item = getSelectedItem();
	if (item != -1) {
		insertItem(item);
		resetMFieldNumber();
	}
}

void DialogMFieldConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	
	CDialog::OnOK();
}

void DialogMFieldConfig::OnCancel() 
{
	// TODO: この位置に特別な後処理を追加してください。
	MField		*mfield			= (MField *)getField();
	MField		*orgMField		= getOriginalMField();

	mfield->setValue(orgMField);
	
	CDialog::OnCancel();
}
