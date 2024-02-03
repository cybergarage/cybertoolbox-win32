#if !defined(AFX_DIALOGSFVEC3FCONFIG_H__9F803AF4_55B0_11D1_A929_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFVEC3FCONFIG_H__9F803AF4_55B0_11D1_A929_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFVec3fConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFVec3fConfig ダイアログ

class DialogSFVec3fConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFVec3fConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFVec3fConfig)
	enum { IDD = IDD_SFVEC3F };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFVec3fConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFVec3fConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFVEC3FCONFIG_H__9F803AF4_55B0_11D1_A929_02608CA85C38__INCLUDED_)
