#if !defined(AFX_DIALOGSFINT32CONFIG_H__B2B10D54_5581_11D1_A927_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFINT32CONFIG_H__B2B10D54_5581_11D1_A927_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFInt32Config.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFInt32Config ダイアログ

class DialogSFInt32Config : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFInt32Config(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFInt32Config)
	enum { IDD = IDD_SFINT32 };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFInt32Config)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFInt32Config)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFINT32CONFIG_H__B2B10D54_5581_11D1_A927_02608CA85C38__INCLUDED_)
