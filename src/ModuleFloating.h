// ModuleFloating.h : �w�b�_�[ �t�@�C��
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
// �R���X�g���N�V����
public:
	ModuleFloating(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	ModuleFloating(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(ModuleFloating)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~ModuleFloating();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
