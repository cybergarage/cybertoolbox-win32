#if !defined(AFX_DIALOGSFSTRINGCONFIG_H__B2B10D53_5581_11D1_A927_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFSTRINGCONFIG_H__B2B10D53_5581_11D1_A927_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFStringConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFStringConfig ダイアログ

class DialogSFStringConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFStringConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFStringConfig)
	enum { IDD = IDD_SFSTRING };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFStringConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFStringConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFSTRINGCONFIG_H__B2B10D53_5581_11D1_A927_02608CA85C38__INCLUDED_)
