#if !defined(AFX_DIALOGEVENTCLOCK_H__7F19A91C_5F5F_11D1_86D7_0000E8A71353__INCLUDED_)
#define AFX_DIALOGEVENTCLOCK_H__7F19A91C_5F5F_11D1_86D7_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventClock.h : ヘッダー ファイル
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventClock ダイアログ

class DialogEventClock : public CDialog, public DialogEvent
{
// コンストラクション
public:
	DialogEventClock(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogEventClock)
	enum { IDD = IDD_EVENT_CLOCK };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogEventClock)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogEventClock)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGEVENTCLOCK_H__7F19A91C_5F5F_11D1_86D7_0000E8A71353__INCLUDED_)
