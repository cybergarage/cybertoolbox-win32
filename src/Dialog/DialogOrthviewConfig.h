#if !defined(AFX_DIALOGORTHVIEWCONFIG_H__F2CB6993_6079_11D1_A942_00605204B77B__INCLUDED_)
#define AFX_DIALOGORTHVIEWCONFIG_H__F2CB6993_6079_11D1_A942_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogOrthviewConfig.h : ヘッダー ファイル
//

#include "..\OrthoView.h"

/////////////////////////////////////////////////////////////////////////////
// DialogOrthviewConfig ダイアログ

class DialogOrthviewConfig : public CDialog, public OrthoConfig
{
// コンストラクション
public:
	DialogOrthviewConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogOrthviewConfig)
	enum { IDD = IDD_ORTHVIEW_CONFIG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogOrthviewConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogOrthviewConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposSpinPosition(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinAngle(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGORTHVIEWCONFIG_H__F2CB6993_6079_11D1_A942_00605204B77B__INCLUDED_)
