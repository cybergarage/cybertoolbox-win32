// DialogEventArea.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventArea.h"
#include "CEvent.h"
#include "ProximitySensorNode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventArea ダイアログ


DialogEventArea::DialogEventArea(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventArea::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventArea)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogEventArea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventArea)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventArea, CDialog)
	//{{AFX_MSG_MAP(DialogEventArea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventArea メッセージ ハンドラ

BOOL DialogEventArea::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CEvent *event = getEvent();
	ProximitySensorNode *psensor = (ProximitySensorNode *)event->getNode();
	assert(psensor->isProximitySensorNode() == true);
	if (psensor->isProximitySensorNode() == false)
		return FALSE;
	
	char text[128];
	float center[3];
	psensor->getCenter(center);
	sprintf(text, "%g", center[0]);  SetDlgItemText(IDC_CENTER_X, text);
	sprintf(text, "%g", center[1]);  SetDlgItemText(IDC_CENTER_Y, text);
	sprintf(text, "%g", center[2]);  SetDlgItemText(IDC_CENTER_Z, text);

	float size[3];
	psensor->getSize(size);
	sprintf(text, "%g", size[0]);  SetDlgItemText(IDC_SIZE_X, text);
	sprintf(text, "%g", size[1]);  SetDlgItemText(IDC_SIZE_Y, text);
	sprintf(text, "%g", size[2]);  SetDlgItemText(IDC_SIZE_Z, text);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogEventArea::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	CEvent *event = getEvent();
	ProximitySensorNode *psensor = (ProximitySensorNode *)event->getNode();
	assert(psensor->isProximitySensorNode() == true);
	if (psensor->isProximitySensorNode() == false)
		return;

	char	value[512];
	float	cx, cy, cz;
	float	sx, sy, sz;
	int		nValue = 0;
					
	GetDlgItemText(IDC_CENTER_X, value, 512);
	if (sscanf(value, "%f", &cx) == 1)
		nValue++;

	GetDlgItemText(IDC_CENTER_Y, value, 512);
	if (sscanf(value, "%f", &cy) == 1)
		nValue++;

	GetDlgItemText(IDC_CENTER_Z, value, 512);
	if (sscanf(value, "%f", &cz) == 1)
		nValue++;

	GetDlgItemText(IDC_SIZE_X, value, 512);
	if (sscanf(value, "%f", &sx) == 1)
		nValue++;

	GetDlgItemText(IDC_SIZE_Y, value, 512);
	if (sscanf(value, "%f", &sy) == 1)
		nValue++;

	GetDlgItemText(IDC_SIZE_Z, value, 512);
	if (sscanf(value, "%f", &sz) == 1)
		nValue++;

	if (nValue == 6) {
		char optionString[128];
		sprintf(optionString, "%g:%g:%g:%g:%g:%g", cx, cy, cz, sx, sy, sz);
		event->setOptionString(optionString);
	}
	else
		MessageBeep(0);

	CDialog::OnOK();
}
