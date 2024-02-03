// ModuleWorldPage.h : �w�b�_�[ �t�@�C��
//

#ifndef _MODULEWORLDPAGE_H_
#define _MODULEWORLDPAGE_H_

#include "ModulePage.h"

/////////////////////////////////////////////////////////////////////////////
// ModuleWorldPage �_�C�A���O

class ModuleWorldPage : public CPropertyPage, public ModulePage
{
	DECLARE_DYNCREATE(ModuleWorldPage)

public:

// �R���X�g���N�V����
public:
	ModuleWorldPage();
	~ModuleWorldPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleWorldPage)
	enum { IDD = IDD_MODULE_WORLD_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(ModuleWorldPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ModuleWorldPage)
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
