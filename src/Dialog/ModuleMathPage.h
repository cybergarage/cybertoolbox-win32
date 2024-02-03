#if !defined(AFX_MODULEMATHPAGE_H__B93465F6_4FCE_11D1_86C3_0000E8A71353__INCLUDED_)
#define AFX_MODULEMATHPAGE_H__B93465F6_4FCE_11D1_86C3_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleMathPage.h : �w�b�_�[ �t�@�C��
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleMathPage �_�C�A���O

class ModuleMathPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleMathPage)

// �R���X�g���N�V����
public:
	ModuleMathPage();
	~ModuleMathPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleMathPage)
	enum { IDD = IDD_MODULE_MATH_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(ModuleMathPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ModuleMathPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnModuleAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MODULEMATHPAGE_H__B93465F6_4FCE_11D1_86C3_0000E8A71353__INCLUDED_)
