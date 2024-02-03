#if !defined(AFX_USEREVENTTIMERPAGE_H__E6911E05_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
#define AFX_USEREVENTTIMERPAGE_H__E6911E05_19E7_11D2_A8B0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventTimerPage.h : ヘッダー ファイル
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventTimerPage ダイアログ

class UserEventTimerPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventTimerPage)

// コンストラクション
public:
	UserEventTimerPage();
	~UserEventTimerPage();

// ダイアログ データ
	//{{AFX_DATA(UserEventTimerPage)
	enum { IDD = IDD_USER_EVENT_TIMER };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(UserEventTimerPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(UserEventTimerPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_USEREVENTTIMERPAGE_H__E6911E05_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
