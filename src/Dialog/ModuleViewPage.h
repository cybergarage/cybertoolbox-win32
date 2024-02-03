#if !defined(AFX_MODULEVIEWPAGE_H__75555B61_211E_11D1_8689_0000E8A71353__INCLUDED_)
#define AFX_MODULEVIEWPAGE_H__75555B61_211E_11D1_8689_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModuleViewPage.h : �w�b�_�[ �t�@�C��
//

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleViewPage �_�C�A���O

class ModuleViewPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleViewPage)

// �R���X�g���N�V����
public:
	ModuleViewPage();
	~ModuleViewPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleViewPage)
	enum { IDD = IDD_MODULE_VIEW_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(ModuleViewPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ModuleViewPage)
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

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_MODULEVIEWPAGE_H__75555B61_211E_11D1_8689_0000E8A71353__INCLUDED_)
