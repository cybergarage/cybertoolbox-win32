#if !defined(AFX_DIALOGEVENTTIMER_H__E6911E04_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
#define AFX_DIALOGEVENTTIMER_H__E6911E04_19E7_11D2_A8B0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventTimer.h : ヘッダー ファイル
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventTimer ダイアログ

class DialogEventTimer : public CDialog, public DialogEvent
{
// コンストラクション
public:
	DialogEventTimer(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogEventTimer)
	enum { IDD = IDD_EVENT_TIMER };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogEventTimer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogEventTimer)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGEVENTTIMER_H__E6911E04_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
