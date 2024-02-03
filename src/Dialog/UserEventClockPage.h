#if !defined(AFX_USEREVENTCLOCKPAGE_H__BE4736F1_1317_11D1_8671_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTCLOCKPAGE_H__BE4736F1_1317_11D1_8671_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventClockPage.h : ヘッダー ファイル
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventClockPage ダイアログ

class UserEventClockPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventClockPage)

// コンストラクション
public:
	UserEventClockPage();
	~UserEventClockPage();

// ダイアログ データ
	//{{AFX_DATA(UserEventClockPage)
	enum { IDD = IDD_USER_EVENT_CLOCK_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(UserEventClockPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(UserEventClockPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_USEREVENTCLOCKPAGE_H__BE4736F1_1317_11D1_8671_0000E8A71353__INCLUDED_)
