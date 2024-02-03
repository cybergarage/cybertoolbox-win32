#if !defined(AFX_DIALOGMODULEFILTERPOSITION3DINTERP_H__3BAF9A53_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEFILTERPOSITION3DINTERP_H__3BAF9A53_10B9_11D2_A8A0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleFilterPosition3DInterp.h : ヘッダー ファイル
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterPosition3DInterp ダイアログ

class DialogModuleFilterPosition3DInterp : public CDialog
{
// コンストラクション
public:
	DialogModuleFilterPosition3DInterp(CWnd* pParent = NULL);   // 標準のコンストラクタ

	CModule	*mModule;
	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// ダイアログ データ
	//{{AFX_DATA(DialogModuleFilterPosition3DInterp)
	enum { IDD = IDD_MODULE_FILTER_P3DINTERP };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogModuleFilterPosition3DInterp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogModuleFilterPosition3DInterp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposXspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMODULEFILTERPOSITION3DINTERP_H__3BAF9A53_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
