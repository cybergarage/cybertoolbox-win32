#if !defined(AFX_DIALOGSFVEC2FCONFIG_H__A344B542_55B2_11D1_A929_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFVEC2FCONFIG_H__A344B542_55B2_11D1_A929_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFVec2fConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFVec2fConfig ダイアログ

class DialogSFVec2fConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFVec2fConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFVec2fConfig)
	enum { IDD = IDD_SFVEC2F };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFVec2fConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFVec2fConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFVEC2FCONFIG_H__A344B542_55B2_11D1_A929_02608CA85C38__INCLUDED_)
