#if !defined(AFX_DIALOGGLOBALDATANAME_H__66520E87_0906_11D1_866C_0000E8A71353__INCLUDED_)
#define AFX_DIALOGGLOBALDATANAME_H__66520E87_0906_11D1_866C_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogGlobalDataName.h : ヘッダー ファイル
//

#include "SceneGraph.h"

/////////////////////////////////////////////////////////////////////////////
// DialogGlobalDataName ダイアログ

#define GLOBALDATA_SIZE		512

class DialogGlobalDataName : public CDialog
{
// コンストラクション
public:
	DialogGlobalDataName(CWnd* pParent = NULL);   // 標準のコンストラクタ

	char	mGlobalDataName[GLOBALDATA_SIZE];
	char	*getGlobalDataName()	{return mGlobalDataName;}

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// ダイアログ データ
	//{{AFX_DATA(DialogGlobalDataName)
	enum { IDD = IDD_GLOBALDATA_NAME };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogGlobalDataName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogGlobalDataName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGGLOBALDATANAME_H__66520E87_0906_11D1_866C_0000E8A71353__INCLUDED_)
