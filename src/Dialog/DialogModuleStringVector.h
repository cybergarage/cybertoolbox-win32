#if !defined(AFX_DIALOGMODULESTRINGVECTOR_H__167F79B3_1076_11D2_A89E_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULESTRINGVECTOR_H__167F79B3_1076_11D2_A89E_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleStringVector.h : ヘッダー ファイル
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringVector ダイアログ

class DialogModuleStringVector : public CDialog
{
// コンストラクション
public:
	DialogModuleStringVector(CWnd* pParent = NULL);   // 標準のコンストラクタ

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// ダイアログ データ
	//{{AFX_DATA(DialogModuleStringVector)
	enum { IDD = IDD_MODULE_STRING_VECTOR };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogModuleStringVector)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogModuleStringVector)
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMODULESTRINGVECTOR_H__167F79B3_1076_11D2_A89E_00605204B77B__INCLUDED_)
