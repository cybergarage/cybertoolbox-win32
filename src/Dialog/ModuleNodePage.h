#if !defined(AFX_MODULENODEPAGE_H__5387FC3D_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_)
#define AFX_MODULENODEPAGE_H__5387FC3D_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleNodePage.h : ヘッダー ファイル
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleNodePage ダイアログ

class ModuleNodePage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleNodePage)

// コンストラクション
public:
	ModuleNodePage();
	~ModuleNodePage();

// ダイアログ データ
	//{{AFX_DATA(ModuleNodePage)
	enum { IDD = IDD_MODULE_NODE_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(ModuleNodePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleNodePage)
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

#endif // !defined(AFX_MODULENODEPAGE_H__5387FC3D_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_)
