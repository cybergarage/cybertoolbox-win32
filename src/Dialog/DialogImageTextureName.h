#if !defined(AFX_DIALOGIMAGETEXTURENAME_H__DE460297_9BB1_11D2_9BC7_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGIMAGETEXTURENAME_H__DE460297_9BB1_11D2_9BC7_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogImageTextureName.h : ヘッダー ファイル
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialogImageTextureName ダイアログ

class DialogImageTextureName : public CDialog
{
// コンストラクション
public:
	DialogImageTextureName(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// ダイアログ データ
	//{{AFX_DATA(DialogImageTextureName)
	enum { IDD = IDD_IMAGETEXTURE_NAME };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogImageTextureName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogImageTextureName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGIMAGETEXTURENAME_H__DE460297_9BB1_11D2_9BC7_00A0C9B17B86__INCLUDED_)
