#if !defined(AFX_DIALOGEVENTAREA_H__B57B8B74_5EE4_11D1_A93C_00605204B77B__INCLUDED_)
#define AFX_DIALOGEVENTAREA_H__B57B8B74_5EE4_11D1_A93C_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventArea.h : ヘッダー ファイル
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventArea ダイアログ

class DialogEventArea : public CDialog, public DialogEvent
{
// コンストラクション
public:
	DialogEventArea(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogEventArea)
	enum { IDD = IDD_EVENT_AREA };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogEventArea)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogEventArea)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGEVENTAREA_H__B57B8B74_5EE4_11D1_A93C_00605204B77B__INCLUDED_)
