// DialogRouteInfo.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogRouteInfo.h"

#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogRouteInfo ダイアログ


DialogRouteInfo::DialogRouteInfo(CWnd* pParent /*=NULL*/)
	: CDialog(DialogRouteInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogRouteInfo)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setInputNode(NULL);
	setInputField(NULL);
	setOutputNode(NULL);
	setOutputField(NULL);
}


void DialogRouteInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogRouteInfo)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogRouteInfo, CDialog)
	//{{AFX_MSG_MAP(DialogRouteInfo)
	ON_CBN_SELCHANGE(IDC_EVENTIN_NODE, OnSelchangeEventinNode)
	ON_CBN_SELCHANGE(IDC_EVENTOUT_NODE, OnSelchangeEventoutNode)
	ON_CBN_SELCHANGE(IDC_EVENTIN_FIELD, OnSelchangeEventinField)
	ON_CBN_SELCHANGE(IDC_EVENTOUT_FIELD, OnSelchangeEventoutField)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogRouteInfo メッセージ ハンドラ

void DialogRouteInfo::initializeNodeComboBox(int comboBox)
{
	char *firstComboItemText = NULL;

	SendDlgItemMessage(comboBox, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
		if (GetWorld()->isSystemNode(node) == true)
			continue;
		if (node->hasName() == false)
			continue;
		SendDlgItemMessage(comboBox, CB_ADDSTRING, 0, (LONG)(LPSTR)node->getName());
		if (firstComboItemText == NULL)
			firstComboItemText = node->getName();
	}

	if (firstComboItemText != NULL)
		SendDlgItemMessage(comboBox, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)firstComboItemText);
}

void DialogRouteInfo::initializeInputFieldComboBox(Node *inputNode)
{
	SendDlgItemMessage(IDC_EVENTIN_FIELD, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);

	if (inputNode == NULL) {
		for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
			if (GetWorld()->isSystemNode(node) == true)
				continue;
			if (node->hasName() == false)
				continue;
			inputNode = node; 
			break;
		}
	}

	if (inputNode == NULL) 
		return;	

	Field	*field;
	int		n, nFields;

	char *firstComboItemText = NULL;

	nFields = inputNode->getNEventIn();
	for (n=0; n<nFields; n++) {
		field = inputNode->getEventIn(n);			
		SendDlgItemMessage(IDC_EVENTIN_FIELD, CB_ADDSTRING, 0, (LONG)(LPSTR)field->getName());
		if (firstComboItemText == NULL)
			firstComboItemText = field->getName();
	}

	nFields = inputNode->getNExposedFields();
	for (n=0; n<nFields; n++) {
		field = inputNode->getExposedField(n);			
		SendDlgItemMessage(IDC_EVENTIN_FIELD, CB_ADDSTRING, 0, (LONG)(LPSTR)field->getName());
		if (firstComboItemText == NULL)
			firstComboItemText = field->getName();
	}

	if (firstComboItemText != NULL)
		SendDlgItemMessage(IDC_EVENTIN_FIELD, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)firstComboItemText);
}

void DialogRouteInfo::initializeOutputFieldComboBox(Node *outputNode)
{
	SendDlgItemMessage(IDC_EVENTOUT_FIELD, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);

	if (outputNode == NULL) {
		for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
			if (GetWorld()->isSystemNode(node) == true)
				continue;
			if (node->hasName() == false)
				continue;
			outputNode = node; 
			break;
		}
	}

	if (outputNode == NULL) 
		return;	

	Field	*field;
	int		n, nFields;

	char *firstComboItemText = NULL;

	nFields = outputNode->getNEventOut();
	for (n=0; n<nFields; n++) {
		field = outputNode->getEventOut(n);			
		SendDlgItemMessage(IDC_EVENTOUT_FIELD, CB_ADDSTRING, 0, (LONG)(LPSTR)field->getName());
		if (firstComboItemText == NULL)
			firstComboItemText = field->getName();
	}

	nFields = outputNode->getNExposedFields();
	for (n=0; n<nFields; n++) {
		field = outputNode->getExposedField(n);			
		SendDlgItemMessage(IDC_EVENTOUT_FIELD, CB_ADDSTRING, 0, (LONG)(LPSTR)field->getName());
		if (firstComboItemText == NULL)
			firstComboItemText = field->getName();
	}

	if (firstComboItemText != NULL)
		SendDlgItemMessage(IDC_EVENTOUT_FIELD, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)firstComboItemText);
}

void DialogRouteInfo::setNodeComboBox(int comboBox, Node *node) 
{
	if (node->hasName() == true)
		SendDlgItemMessage(comboBox, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
}

void DialogRouteInfo::setFieldComboBox(int comboBox, Field *field) 
{
	SendDlgItemMessage(comboBox, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)field->getName());
}

BOOL DialogRouteInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	initializeInputNodeComboBox();
	initializeInputFieldComboBox(NULL);

	initializeOutputNodeComboBox();
	initializeOutputFieldComboBox(NULL);

	Node *node;
	Field *field;
	
	node = getInputNode();
	if (node)
		setInputNodeComboBox(node);

	field = getInputField();
	if (field)
		setInputFieldComboBox(field);

	node = getOutputNode();
	if (node)
		setOutputNodeComboBox(node);

	field = getOutputField();
	if (field)
		setOutputFieldComboBox(field);

	checkRouteInfo();

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

Node *DialogRouteInfo::getOutputNodeFromComboBox()
{
	char	nodeName[256];
	CComboBox *comboBox = (CComboBox *)GetDlgItem(IDC_EVENTOUT_NODE);
	comboBox->GetLBText(comboBox->GetCurSel(), nodeName);
	return GetWorld()->getSceneGraph()->findNode(nodeName);
}

Field *DialogRouteInfo::getOutputFieldFromComboBox()
{
	Node *node = getOutputNodeFromComboBox();
	
	if (node == NULL)
		return NULL;

	char	fieldName[256];
	CComboBox *comboBox = (CComboBox *)GetDlgItem(IDC_EVENTOUT_FIELD);
	comboBox->GetLBText(comboBox->GetCurSel(), fieldName);

	Field *eventOutField = NULL;
	eventOutField = node->getEventOut(fieldName);
	if (eventOutField == NULL)
		eventOutField = node->getExposedField(fieldName);

	return eventOutField;
}

Node *DialogRouteInfo::getInputNodeFromComboBox()
{
	char	nodeName[256];
	CComboBox *comboBox = (CComboBox *)GetDlgItem(IDC_EVENTIN_NODE);
	comboBox->GetLBText(comboBox->GetCurSel(), nodeName);
	return GetWorld()->getSceneGraph()->findNode(nodeName);
}

Field *DialogRouteInfo::getInputFieldFromComboBox()
{
	Node *node = getInputNodeFromComboBox();
	
	if (node == NULL)
		return NULL;

	char	fieldName[256];
	CComboBox *comboBox = (CComboBox *)GetDlgItem(IDC_EVENTIN_FIELD);
	comboBox->GetLBText(comboBox->GetCurSel(), fieldName);

	Field *eventInField = NULL;
	eventInField = node->getEventIn(fieldName);
	if (eventInField == NULL)
		eventInField = node->getExposedField(fieldName);

	return eventInField;
}

void DialogRouteInfo::checkRouteInfo()
{
	Node	*outNode	= getOutputNodeFromComboBox();
	Field	*outField	= getOutputFieldFromComboBox();
	Node	*inNode		= getInputNodeFromComboBox();
	Field	*inField	= getInputFieldFromComboBox();

	if (outNode == NULL || outField == NULL || inNode == NULL || inField == NULL) {
		GetDlgItem(IDOK)->EnableWindow(false);
		return;
	}

	if (outNode == inNode && outField == inField) {
		GetDlgItem(IDOK)->EnableWindow(false);
		return;
	}

	if (outField->getType() != inField->getType()) {
		GetDlgItem(IDOK)->EnableWindow(false);
		return;
	}

	GetDlgItem(IDOK)->EnableWindow(true);
}


void DialogRouteInfo::OnSelchangeEventinNode() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	initializeInputFieldComboBox(getInputNodeFromComboBox());
	checkRouteInfo();	
}	


void DialogRouteInfo::OnSelchangeEventoutNode() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	initializeOutputFieldComboBox(getOutputNodeFromComboBox());
	checkRouteInfo();	
}

void DialogRouteInfo::OnSelchangeEventinField() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	checkRouteInfo();	
}

void DialogRouteInfo::OnSelchangeEventoutField() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	checkRouteInfo();	
}

void DialogRouteInfo::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	setOutputNode(getOutputNodeFromComboBox());
	setOutputField(getOutputFieldFromComboBox());
	setInputNode(getInputNodeFromComboBox());
	setInputField(getInputFieldFromComboBox());
	
	CDialog::OnOK();
}
