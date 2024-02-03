// ModuleNumericPage.h : �w�b�_�[ �t�@�C��
//

#ifndef _MODULENUMERICPAGE_H_
#define _MODULENUMERICPAGE_H_

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleNumericPage �_�C�A���O

class ModuleNumericPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleNumericPage)

// �R���X�g���N�V����
public:
	ModuleNumericPage();
	~ModuleNumericPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleNumericPage)
	enum { IDD = IDD_MODULE_NUMERIC_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(ModuleNumericPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
