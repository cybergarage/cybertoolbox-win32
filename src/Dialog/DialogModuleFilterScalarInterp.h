#if !defined(AFX_DIALOGMODULEFILTERSCALARINTERP_H__3BAF9A57_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEFILTERSCALARINTERP_H__3BAF9A57_10B9_11D2_A8A0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleFilterScalarInterp.h : ヘッダー ファイル
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterScalarInterp ダイアログ

class DialogModuleFilterScalarInterp : public CDialog
{
// コンストラクション
public:
	DialogModuleFilterScalarInterp(CWnd* pParent = NULL);   // 標準のコンストラクタ

	CModule	*mModule;
	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// ダイアログ データ
	//{{AFX_DATA(DialogModuleFilterScalarInterp)
	enum { IDD = IDD_MODULE_FILTER_SCALAINTERP };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogModuleFilterScalarInterp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogModuleFilterScalarInterp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMODULEFILTERSCALARINTERP_H__3BAF9A57_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
