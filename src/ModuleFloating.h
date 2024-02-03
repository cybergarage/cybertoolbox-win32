// ModuleFloating.h : ヘッダー ファイル
//

#ifndef _MODULEFLOATING_H_
#define _MODULEFLOATING_H_

#include "ModuleWorldPage.h"
#include "ModuleMathPage.h"
#include "ModuleNumericPage.h"
#include "ModuleObjectPage.h"
#include "ModuleBooleanPage.h"
#include "ModuleMiscPage.h"
#include "ModuleViewPage.h"
#include "ModuleMaterialPage.h"
#include "ModuleLightPage.h"
#include "ModuleFilterPage.h"
#include "ModuleInterpPage.h"
#include "ModuleGeomPage.h"
#include "ModuleNodePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleFloating

class ModuleFloating : public CPropertySheet
{
	DECLARE_DYNAMIC(ModuleFloating)

	//////////////////////////////
	//	PropertyPage
	//////////////////////////////
	ModuleWorldPage		mModuleWorldPage;
	ModuleObjectPage	mModuleObjectPage;
	ModuleMaterialPage	mModuleMaterialPage;
	ModuleViewPage		mModuleViewPage;
	ModuleLightPage		mModuleLightPage;
	ModuleMathPage		mModuleMathPage;
	ModuleNumericPage	mModuleNumericPage;
	ModuleBooleanPage	mModuleBooleanPage;
	ModuleMiscPage		mModuleMiscPage;
	ModuleFilterPage	mModuleFilterPage;
	ModuleNodePage		mModuleNodePage;
	ModuleInterpPage	mModuleInterpPage;
	ModuleGeomPage		mModuleGeomPage;

	bool				mbInitialized;
// コンストラクション
public:
	ModuleFloating(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	ModuleFloating(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(ModuleFloating)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~ModuleFloating();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(ModuleFloating)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif
