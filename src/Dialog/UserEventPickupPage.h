// UserEventPickuPpage.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// UserEventPickupPage ダイアログ

#include "UserEventPage.h"

class UserEventPickupPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventPickupPage)

// コンストラクション
public:
	UserEventPickupPage();
	~UserEventPickupPage();

// ダイアログ データ
	//{{AFX_DATA(UserEventPickupPage)
	enum { IDD = IDD_USER_EVENT_PICKUP_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(UserEventPickupPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(UserEventPickupPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
