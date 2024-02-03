#if !defined(AFX_DIALOGSFROTATIONCONFIG_H__A344B541_55B2_11D1_A929_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFROTATIONCONFIG_H__A344B541_55B2_11D1_A929_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFRotationConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFRotationConfig ダイアログ

class DialogSFRotationConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFRotationConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFRotationConfig)
	enum { IDD = IDD_SFROTATION };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFRotationConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFRotationConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposRspin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFROTATIONCONFIG_H__A344B541_55B2_11D1_A929_02608CA85C38__INCLUDED_)
