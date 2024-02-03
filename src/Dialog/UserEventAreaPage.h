#if !defined(AFX_USEREVENTAREAPAGE_H__FC756E23_3164_11D1_86A1_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTAREAPAGE_H__FC756E23_3164_11D1_86A1_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventAreaPage.h : ヘッダー ファイル
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventAreaPage ダイアログ

class UserEventAreaPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventAreaPage)

// コンストラクション
public:
	UserEventAreaPage();
	~UserEventAreaPage();

// ダイアログ データ
	//{{AFX_DATA(UserEventAreaPage)
	enum { IDD = IDD_USER_EVENT_AREA };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(UserEventAreaPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(UserEventAreaPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_USEREVENTAREAPAGE_H__FC756E23_3164_11D1_86A1_0000E8A71353__INCLUDED_)
