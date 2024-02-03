#if !defined(AFX_DIALOGMODULEINTERPPOSITION_H__65E8E018_8D6F_11D2_9BAE_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGMODULEINTERPPOSITION_H__65E8E018_8D6F_11D2_9BAE_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleInterpPosition.h : ヘッダー ファイル
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialogModuleInterpPosition ダイアログ

class DialogModuleInterpPosition : public CDialog
{
// コンストラクション
public:
	DialogModuleInterpPosition(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// ダイアログ データ
	//{{AFX_DATA(DialogModuleInterpPosition)
	enum { IDD = IDD_MODULE_INTERP_POSITION };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogModuleInterpPosition)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogModuleInterpPosition)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMODULEINTERPPOSITION_H__65E8E018_8D6F_11D2_9BAE_00A0C9B17B86__INCLUDED_)
