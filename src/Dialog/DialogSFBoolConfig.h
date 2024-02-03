#if !defined(AFX_DIALOGSFBOOLCONFIG_H__EBC3D5A1_54DA_11D1_A925_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFBOOLCONFIG_H__EBC3D5A1_54DA_11D1_A925_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFBoolConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFBoolConfig ダイアログ

class DialogSFBoolConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogSFBoolConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogSFBoolConfig)
	enum { IDD = IDD_SFBOOL };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogSFBoolConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogSFBoolConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGSFBOOLCONFIG_H__EBC3D5A1_54DA_11D1_A925_02608CA85C38__INCLUDED_)
