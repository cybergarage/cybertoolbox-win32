// DialogNodeConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogNodeConfig.h"
#include "VRMLField.h"
#include "Node.h"
#include "DialogMFieldConfig.h"
#include "DialogSFBoolConfig.h"
#include "DialogSFStringConfig.h"
#include "DialogSFFloatConfig.h"
#include "DialogSFInt32Config.h"
#include "DialogSFTimeConfig.h"
#include "DialogSFRotationConfig.h"
#include "DialogSFVec2fConfig.h"
#include "DialogSFVec3fConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogNodeConfig ダイアログ


DialogNodeConfig::DialogNodeConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogNodeConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogNodeConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogNodeConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogNodeConfig)
                // メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogNodeConfig, CDialog)
	//{{AFX_MSG_MAP(DialogNodeConfig)
	ON_NOTIFY(NM_DBLCLK, IDC_NODEFIELD, OnDblclkNodefield)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogNodeConfig メッセージ ハンドラ

BOOL DialogNodeConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	Node	*node = getNode();

	char title[256];
	if (node->getName())
		sprintf(title, "%s : %s", node->getType(), node->getName());
	else
		sprintf(title, "%s", node->getType());
	SetWindowText(title);

	SetDlgItemText(IDC_NODENAME, node->getName());

    CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_NODEFIELD);

	pList->InsertColumn(0, "Name", LVCFMT_LEFT, 100, 1);
	pList->InsertColumn(1, "Type", LVCFMT_LEFT, 70, 0);
	pList->InsertColumn(2, "Value", LVCFMT_LEFT, 104, 2);

	int		n;
	char	value[1024];

	int nFields = node->getNFields();
	for (n=0; n<nFields; n++) {
		Field *field = node->getField(n);
		pList->InsertItem(n, field->getName());
		pList->SetItem(n, 1, LVIF_TEXT, field->getTypeName(), 0, 0, 0, 0);
		pList->SetItem(n, 2, LVIF_TEXT, field->getValue(value, 1024), 0, 0, 0, 0);
	}
	int nExposedFields = node->getNExposedFields();
	for (n=0; n<nExposedFields; n++) {
		Field *field = node->getExposedField(n);
		pList->InsertItem(n+nFields, field->getName());
		pList->SetItem(n+nFields, 1, LVIF_TEXT, field->getTypeName(), 0, 0, 0, 0);
		pList->SetItem(n+nFields, 2, LVIF_TEXT, field->getValue(value, 1024), 0, 0, 0, 0);
	}

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}


BOOL DialogNodeConfig::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	switch (LOWORD(wParam)) {
	case IDOK:
		{
			char	nodeName[512];
			GetDlgItemText(IDC_NODENAME, nodeName, 512);
			getNode()->setName(nodeName);
		}
		break;
	}

	return CDialog::OnCommand(wParam, lParam);
}
/*
void DialogNodeConfig::OnBeginlabeleditNodefield(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
//    CListCtrl	*pList = (CListCtrl*) GetDlgItem(IDC_NODEFIELD);
//	pList->EditLabel(pDispInfo->item.iItem);
	
	*pResult = 0;
}

void DialogNodeConfig::OnEndlabeleditNodefield(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
    CListCtrl	*pList = (CListCtrl*) GetDlgItem(IDC_NODEFIELD);

	int		nItem	= pDispInfo->item.iItem;
	char	*value	= pDispInfo->item.pszText;

	if (value) {
		Node	*node = getNode();
		Field	*field = node->getExposedField(nItem);
		field->setValue(value);
		char svalue[1024];
		pList->SetItem(nItem, 0, LVIF_TEXT, field->getValue(svalue, 1024), 0, 0, 0, 0);
	}
	
	*pResult = 0;
}
*/

void DialogNodeConfig::OnDblclkNodefield(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	HWND hwnd = pNMHDR->hwndFrom;
	CPoint mpos;
	GetCursorPos(&mpos);
	::ScreenToClient(hwnd, &mpos);

    CListCtrl* pList = (CListCtrl*) GetDlgItem(IDC_NODEFIELD);
	int item = pList->HitTest(mpos);

	Node	*node = getNode();

	Field *field = NULL;
	if (item < node->getNFields())
		field = node->getField(item);
	else
		field = node->getExposedField(item - node->getNFields());

	if (field) {
		if (OpenFieldDialog(node, field, this) == true) {
			char	value[1024];
			pList->SetItem(item, 2, LVIF_TEXT, field->getValue(value, 1024), 0, 0, 0, 0);
		}
	}

	*pResult = 0;
}

bool OpenFieldDialog(Node *node, Field *field, CWnd *parentWnd)
{
	char	title[256];

	sprintf(title, "%s::%s", node->getType(), field->getName() );

	switch (field->getType()) {
	case fieldTypeSFBool :
		{
			DialogSFBoolConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFFloat :
		{
			DialogSFFloatConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFInt32 :
		{
			DialogSFInt32Config dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFTime :
		{
			DialogSFTimeConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFString :
		{
			DialogSFStringConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFVec2f :
		{
			DialogSFVec2fConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFVec3f :
		{
			DialogSFVec3fConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;

	case fieldTypeSFColor :
		{
			SFColor *colorField = (SFColor *)field;
			BYTE r = (BYTE)(colorField->getRed() / 1.0f * 255.0f);
			BYTE g = (BYTE)(colorField->getGreen() / 1.0f * 255.0f);
			BYTE b = (BYTE)(colorField->getBlue() / 1.0f * 255.0f);
			COLORREF color = RGB(r, g, b);
			CColorDialog dialog(color, CC_FULLOPEN, parentWnd);
			if (dialog.DoModal() == IDOK) {
				COLORREF color = dialog.GetColor();
				float r = (float)GetRValue(color) / 255.0f;
				float g = (float)GetGValue(color) / 255.0f;
				float b = (float)GetBValue(color) / 255.0f;
				colorField->setValue(r, g, b);
				return true;
			}
		}
		break;

	case fieldTypeSFRotation :
		{
			DialogSFRotationConfig dialog;
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK)
				return true;
		}
		break;
	case fieldTypeMFString :
	case fieldTypeMFColor :
	case fieldTypeMFFloat :
	case fieldTypeMFInt32 :
	case fieldTypeMFRotation :
	case fieldTypeMFTime :
	case fieldTypeMFVec2f :
	case fieldTypeMFVec3f :
		{
			DialogMFieldConfig dialog(parentWnd);
			dialog.setNode(node);
			dialog.setField(field);
			if (dialog.DoModal() == IDOK) {
			}
		}
		break;
	default:
		MessageBeep(0);
	}

	return false;
}

