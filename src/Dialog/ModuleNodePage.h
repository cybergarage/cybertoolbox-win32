#if !defined(AFX_MODULENODEPAGE_H__5387FC3D_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_)
#define AFX_MODULENODEPAGE_H__5387FC3D_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleNodePage.h : �w�b�_�[ �t�@�C��
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleNodePage �_�C�A���O

class ModuleNodePage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleNodePage)

// �R���X�g���N�V����
public:
	ModuleNodePage();
	~ModuleNodePage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleNodePage)
	enum { IDD = IDD_MODULE_NODE_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(ModuleNodePage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MODULENODEPAGE_H__5387FC3D_8B43_11D2_9BAC_00A0C9B17B86__INCLUDED_)
