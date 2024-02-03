#if !defined(AFX_DIALOGSFFLOATCONFIG_H__B2B10D55_5581_11D1_A927_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFFLOATCONFIG_H__B2B10D55_5581_11D1_A927_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFFloatConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFFloatConfig ダイアログ

class DialogSFFloatConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFFloatConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFFloatConfig)
	enum { IDD = IDD_SFFLOAT };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFFloatConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFFloatConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFFLOATCONFIG_H__B2B10D55_5581_11D1_A927_02608CA85C38__INCLUDED_)
