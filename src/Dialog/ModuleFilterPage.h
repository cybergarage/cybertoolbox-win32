#if !defined(AFX_MODULEFILTERPAGE_H__71368905_C0CA_11D1_871D_0000E8A71353__INCLUDED_)
#define AFX_MODULEFILTERPAGE_H__71368905_C0CA_11D1_871D_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleFilterPage.h : ヘッダー ファイル
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleFilterPage ダイアログ

class ModuleFilterPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleFilterPage)

// コンストラクション
public:
	ModuleFilterPage();
	~ModuleFilterPage();

// ダイアログ データ
	//{{AFX_DATA(ModuleFilterPage)
	enum { IDD = IDD_MODULE_FILTER_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(ModuleFilterPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleFilterPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MODULEFILTERPAGE_H__71368905_C0CA_11D1_871D_0000E8A71353__INCLUDED_)
