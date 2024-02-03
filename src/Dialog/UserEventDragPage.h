#if !defined(AFX_USEREVENTDRAGPAGE_H__BF12F41C_062F_11D1_866C_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTDRAGPAGE_H__BF12F41C_062F_11D1_866C_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventDragPage.h : ヘッダー ファイル
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventDragPage ダイアログ

class UserEventDragPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventDragPage)

// コンストラクション
public:
	UserEventDragPage();
	~UserEventDragPage();

// ダイアログ データ
	//{{AFX_DATA(UserEventDragPage)
	enum { IDD = IDD_USER_EVENT_DRAG_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(UserEventDragPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(UserEventDragPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_USEREVENTDRAGPAGE_H__BF12F41C_062F_11D1_866C_0000E8A71353__INCLUDED_)
