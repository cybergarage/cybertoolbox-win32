#if !defined(AFX_MODULEINTERPPAGE_H__5387FC3E_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_)
#define AFX_MODULEINTERPPAGE_H__5387FC3E_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleInterpPage.h : �w�b�_�[ �t�@�C��
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleInterpPage �_�C�A���O

class ModuleInterpPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleInterpPage)

// �R���X�g���N�V����
public:
	ModuleInterpPage();
	~ModuleInterpPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleInterpPage)
	enum { IDD = IDD_MODULE_INTERP_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(ModuleInterpPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ModuleInterpPage)
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
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MODULEINTERPPAGE_H__5387FC3E_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_)
