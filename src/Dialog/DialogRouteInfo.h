#if !defined(AFX_DIALOGROUTEINFO_H__E2972F1F_8A4A_11D2_9BAA_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGROUTEINFO_H__E2972F1F_8A4A_11D2_9BAA_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogRouteInfo.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogRouteInfo ダイアログ

class Node;
class Field;

class DialogRouteInfo : public CDialog
{
// コンストラクション

	Node	*mInputNode;
	Field	*mInputField;

	Node	*mOutputNode;
	Field	*mOutputField;

public:

	DialogRouteInfo(CWnd* pParent = NULL);   // 標準のコンストラクタ

	void setInputNode(Node *node) {
		mInputNode = node;
	}

	void setInputField(Field *field) {
		mInputField = field;
	}

	Node *getInputNode() {
		return mInputNode;
	}

	Field *getInputField() {
		return mInputField;
	}

	void setOutputNode(Node *node) {
		mOutputNode = node;
	}

	void setOutputField(Field *field) {
		mOutputField = field;
	}

	Node *getOutputNode() {
		return mOutputNode;
	}

	Field *getOutputField() {
		return mOutputField;
	}

	void initializeNodeComboBox(int comboBox);

	void initializeInputNodeComboBox() {
		initializeNodeComboBox(IDC_EVENTIN_NODE);
	}

	void initializeOutputNodeComboBox() {
		initializeNodeComboBox(IDC_EVENTOUT_NODE);
	}

	void initializeInputFieldComboBox(Node *node);
	void initializeOutputFieldComboBox(Node *node);

	void setNodeComboBox(int comboBox, Node *node);
	void setFieldComboBox(int comboBox, Field *field);

	void setInputNodeComboBox(Node *node) {
		setNodeComboBox(IDC_EVENTIN_NODE, node);
		initializeInputFieldComboBox(getInputNodeFromComboBox());
	}

	void setInputFieldComboBox(Field *field) {
		setFieldComboBox(IDC_EVENTIN_FIELD, field);
	}

	void setOutputNodeComboBox(Node *node) {
		setNodeComboBox(IDC_EVENTOUT_NODE, node);
		initializeOutputFieldComboBox(getOutputNodeFromComboBox());
	}

	void setOutputFieldComboBox(Field *field) {
		setFieldComboBox(IDC_EVENTOUT_FIELD, field);
	}

	void	checkRouteInfo();

	Node	*getOutputNodeFromComboBox();
	Field	*getOutputFieldFromComboBox();
	Node	*getInputNodeFromComboBox();
	Field	*getInputFieldFromComboBox();

// ダイアログ データ
	//{{AFX_DATA(DialogRouteInfo)
	enum { IDD = IDD_ROUTE_CONFIG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogRouteInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogRouteInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeEventinNode();
	afx_msg void OnSelchangeEventoutNode();
	afx_msg void OnSelchangeEventinField();
	afx_msg void OnSelchangeEventoutField();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGROUTEINFO_H__E2972F1F_8A4A_11D2_9BAA_00A0C9B17B86__INCLUDED_)
