#if !defined(AFX_USEREVENTCOLLISIONPAGE_H__FC756E24_3164_11D1_86A1_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTCOLLISIONPAGE_H__FC756E24_3164_11D1_86A1_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventCollisionPage.h : ヘッダー ファイル
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventCollisionPage ダイアログ

class UserEventCollisionPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventCollisionPage)

// コンストラクション
public:
	UserEventCollisionPage();
	~UserEventCollisionPage();

// ダイアログ データ
	//{{AFX_DATA(UserEventCollisionPage)
	enum { IDD = IDD_USER_EVENT_COLLISION_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(UserEventCollisionPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(UserEventCollisionPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_USEREVENTCOLLISIONPAGE_H__FC756E24_3164_11D1_86A1_0000E8A71353__INCLUDED_)
