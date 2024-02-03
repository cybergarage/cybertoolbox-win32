#if !defined(AFX_MODULEBOOLEANPAGE_H__3CE8C1F0_0E5A_11D1_8670_0000E8A71353__INCLUDED_)
#define AFX_MODULEBOOLEANPAGE_H__3CE8C1F0_0E5A_11D1_8670_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleBooleanPage.h : �w�b�_�[ �t�@�C��
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleBooleanPage �_�C�A���O

class ModuleBooleanPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleBooleanPage)

// �R���X�g���N�V����
public:
	ModuleBooleanPage();
	~ModuleBooleanPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleBooleanPage)
	enum { IDD = IDD_MODULE_BOOLEAN_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(ModuleBooleanPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ModuleBooleanPage)
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
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MODULEBOOLEANPAGE_H__3CE8C1F0_0E5A_11D1_8670_0000E8A71353__INCLUDED_)
