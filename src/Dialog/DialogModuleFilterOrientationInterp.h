#if !defined(AFX_DIALOGMODULEFILTERORIENTATIONINTERP_H__3BAF9A51_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEFILTERORIENTATIONINTERP_H__3BAF9A51_10B9_11D2_A8A0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleFilterOrientationInterp.h : ヘッダー ファイル
//
#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterOrientationInterp ダイアログ

class DialogModuleFilterOrientationInterp : public CDialog
{
// コンストラクション
public:
	DialogModuleFilterOrientationInterp(CWnd* pParent = NULL);   // 標準のコンストラクタ

	CModule	*mModule;
	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// ダイアログ データ
	//{{AFX_DATA(DialogModuleFilterOrientationInterp)
	enum { IDD = IDD_MODULE_FILTER_ORIINTERP };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogModuleFilterOrientationInterp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogModuleFilterOrientationInterp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposXspin3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposRspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposRspin2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMODULEFILTERORIENTATIONINTERP_H__3BAF9A51_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
