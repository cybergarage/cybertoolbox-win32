#if !defined(AFX_DIALOGDIAGRAM_H__C3EFD60B_2462_11D1_868E_0000E8A71353__INCLUDED_)
#define AFX_DIALOGDIAGRAM_H__C3EFD60B_2462_11D1_868E_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogDiagram.h : ヘッダー ファイル
//

class TransformNode;

#include "SceneGraph.h"

/////////////////////////////////////////////////////////////////////////////
// DialogDiagram ダイアログ

class DialogDiagram : public CDialog
{
// コンストラクション
public:
	DialogDiagram(CWnd* pParent = NULL);   // 標準のコンストラクタ

	TransformNode	*mNode;
	void			setNode(TransformNode *node)		{ mNode = node; }
	TransformNode	*getNode()						{ return mNode; }
	
	String		mName;

	void		setName(char *name)				{ mName.setValue(name); }
	char		*getName()						{ return mName.getValue(); }

// ダイアログ データ
	//{{AFX_DATA(DialogDiagram)
	enum { IDD = IDD_DIAGRAM };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogDiagram)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogDiagram)
	virtual void OnOK();
	afx_msg void OnOpen();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGDIAGRAM_H__C3EFD60B_2462_11D1_868E_0000E8A71353__INCLUDED_)
