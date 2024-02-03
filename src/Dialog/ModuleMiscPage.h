#if !defined(AFX_MODULEMISCPAGE_H__3CE8C1F1_0E5A_11D1_8670_0000E8A71353__INCLUDED_)
#define AFX_MODULEMISCPAGE_H__3CE8C1F1_0E5A_11D1_8670_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleMiscPage.h : ヘッダー ファイル
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleMiscPage ダイアログ

class ModuleMiscPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleMiscPage)

// コンストラクション
public:
	ModuleMiscPage();
	~ModuleMiscPage();

// ダイアログ データ
	//{{AFX_DATA(ModuleMiscPage)
	enum { IDD = IDD_MODULE_MISC_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(ModuleMiscPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleMiscPage)
	afx_msg void OnModuleAdd();
	afx_msg void OnBegindragModuleList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MODULEMISCPAGE_H__3CE8C1F1_0E5A_11D1_8670_0000E8A71353__INCLUDED_)
