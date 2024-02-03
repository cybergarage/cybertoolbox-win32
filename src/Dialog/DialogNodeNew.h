#if !defined(AFX_DIALOGNODENEW_H__884A8AA4_4EC7_11D1_86C1_0000E8A71353__INCLUDED_)
#define AFX_DIALOGNODENEW_H__884A8AA4_4EC7_11D1_86C1_0000E8A71353__INCLUDED_

#include "SceneGraph.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogNodeNew.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogNodeNew ダイアログ

class DialogNodeNew : public CDialog
{
// コンストラクション
public:
	DialogNodeNew(CWnd* pParent = NULL);   // 標準のコンストラクタ

public:

	Node		*mParentNode;
	Node		*mSelectedNode;
	NodeList	mNodeList;
	int			mSelectedItem;

	CImageList	mItemImageList;
	CBitmap		mItemBitmap[54];

	void setParentNode(Node *node) {
		mParentNode = node;
		if (node)
			createNodeList();
	}

	void createImageList();

	CImageList *getImageList() {
		return &mItemImageList;
	}

	Node *getParentNode() {
		return mParentNode;
	}

	void setSelectedNode(Node *node) {
		mSelectedNode = node;
	}

	Node *getSelectedNode() {
		return mSelectedNode;
	}

	bool addNode(Node *node);

	Node *getNodes() {
		return (Node *)mNodeList.getNodes();		
	}

	int getNNodes() {
		return mNodeList.getNNodes();		
	}

	Node *getNode(int n) {
		return (Node *)mNodeList.getNode(n);		
	}

	void setSelectedItem(int n) {
		mSelectedItem = n;
	}

	int getSelectedItem() {
		return mSelectedItem;
	}

	void createNodeList();

// ダイアログ データ
	//{{AFX_DATA(DialogNodeNew)
	enum { IDD = IDD_NODE_NEW };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogNodeNew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogNodeNew)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedNodeList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkNodeList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGNODENEW_H__884A8AA4_4EC7_11D1_86C1_0000E8A71353__INCLUDED_)
