// ModuleNumericPage.h : ヘッダー ファイル
//

#ifndef _MODULENUMERICPAGE_H_
#define _MODULENUMERICPAGE_H_

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleNumericPage ダイアログ

class ModuleNumericPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleNumericPage)

// コンストラクション
public:
	ModuleNumericPage();
	~ModuleNumericPage();

// ダイアログ データ
	//{{AFX_DATA(ModuleNumericPage)
	enum { IDD = IDD_MODULE_NUMERIC_PAGE };
		// メモ - ClassWizard はこの位置にデータ メンバを追加します。
		//    この位置に生成されるコードを編集しないでください。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(ModuleNumericPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleNumericPage)
	afx_msg void OnModuleAdd();
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

#endif
