#if !defined(AFX_MODULEGEOMPAGE_H__23B390B7_B9BD_11D2_9BF4_00A0C9B17B86__INCLUDED_)
#define AFX_MODULEGEOMPAGE_H__23B390B7_B9BD_11D2_9BF4_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleGeomPage.h : �w�b�_�[ �t�@�C��
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleGeomPage �_�C�A���O

class ModuleGeomPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleGeomPage)

// �R���X�g���N�V����
public:
	ModuleGeomPage();
	~ModuleGeomPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleGeomPage)
	enum { IDD = IDD_MODULE_GEOM_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(ModuleGeomPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MODULEGEOMPAGE_H__23B390B7_B9BD_11D2_9BF4_00A0C9B17B86__INCLUDED_)
