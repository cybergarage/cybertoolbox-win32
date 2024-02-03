#if !defined(AFX_DIALOGMODULEMISCPLAYSOUND_H__19FB8514_1466_11D2_A8A7_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEMISCPLAYSOUND_H__19FB8514_1466_11D2_A8A7_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleMiscPlaySound.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogModuleMiscPlaySound ダイアログ

class Node;

class DialogModuleMiscPlaySound : public CDialog
{
// コンストラクション
public:
	DialogModuleMiscPlaySound(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// ダイアログ データ
	//{{AFX_DATA(DialogModuleMiscPlaySound)
	enum { IDD = IDD_MODULE_MISC_PLAYSOUND };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogModuleMiscPlaySound)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogModuleMiscPlaySound)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMODULEMISCPLAYSOUND_H__19FB8514_1466_11D2_A8A7_00605204B77B__INCLUDED_)
