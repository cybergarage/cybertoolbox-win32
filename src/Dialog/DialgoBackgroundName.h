#if !defined(AFX_DIALGOBACKGROUNDNAME_H__1294C02F_961B_11D2_9BBE_00A0C9B17B86__INCLUDED_)
#define AFX_DIALGOBACKGROUNDNAME_H__1294C02F_961B_11D2_9BBE_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialgoBackgroundName.h : ヘッダー ファイル
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialgoBackgroundName ダイアログ

class DialgoBackgroundName : public CDialog
{
// コンストラクション
public:
	DialgoBackgroundName(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// ダイアログ データ
	//{{AFX_DATA(DialgoBackgroundName)
	enum { IDD = IDD_BACKGROUND_NAME };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialgoBackgroundName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialgoBackgroundName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALGOBACKGROUNDNAME_H__1294C02F_961B_11D2_9BBE_00A0C9B17B86__INCLUDED_)
