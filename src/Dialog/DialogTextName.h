#if !defined(AFX_DIALOGTEXTNAME_H__05FEFD79_93B6_11D2_9BBA_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGTEXTNAME_H__05FEFD79_93B6_11D2_9BBA_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogTextName.h : ヘッダー ファイル
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialogTextName ダイアログ

class DialogTextName : public CDialog
{
// コンストラクション
public:
	DialogTextName(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// ダイアログ データ
	//{{AFX_DATA(DialogTextName)
	enum { IDD = IDD_TEXT_NAME };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogTextName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogTextName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGTEXTNAME_H__05FEFD79_93B6_11D2_9BBA_00A0C9B17B86__INCLUDED_)
