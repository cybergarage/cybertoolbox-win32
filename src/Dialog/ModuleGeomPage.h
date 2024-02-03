#if !defined(AFX_MODULEGEOMPAGE_H__23B390B7_B9BD_11D2_9BF4_00A0C9B17B86__INCLUDED_)
#define AFX_MODULEGEOMPAGE_H__23B390B7_B9BD_11D2_9BF4_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleGeomPage.h : ヘッダー ファイル
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleGeomPage ダイアログ

class ModuleGeomPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleGeomPage)

// コンストラクション
public:
	ModuleGeomPage();
	~ModuleGeomPage();

// ダイアログ データ
	//{{AFX_DATA(ModuleGeomPage)
	enum { IDD = IDD_MODULE_GEOM_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(ModuleGeomPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleGeomPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MODULEGEOMPAGE_H__23B390B7_B9BD_11D2_9BF4_00A0C9B17B86__INCLUDED_)
