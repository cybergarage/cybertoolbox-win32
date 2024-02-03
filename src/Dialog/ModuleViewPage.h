#if !defined(AFX_MODULEVIEWPAGE_H__75555B61_211E_11D1_8689_0000E8A71353__INCLUDED_)
#define AFX_MODULEVIEWPAGE_H__75555B61_211E_11D1_8689_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleViewPage.h : ヘッダー ファイル
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleViewPage ダイアログ

class ModuleViewPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleViewPage)

// コンストラクション
public:
	ModuleViewPage();
	~ModuleViewPage();

// ダイアログ データ
	//{{AFX_DATA(ModuleViewPage)
	enum { IDD = IDD_MODULE_VIEW_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(ModuleViewPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleViewPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnBegindragModuleList(NMHDR* pNMHDR, LRESULT* pResult);
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

#endif // !defined(AFX_MODULEVIEWPAGE_H__75555B61_211E_11D1_8689_0000E8A71353__INCLUDED_)
