#if !defined(AFX_DIALOGMODULEFILTERPOSITION3DINTERP_H__3BAF9A53_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEFILTERPOSITION3DINTERP_H__3BAF9A53_10B9_11D2_A8A0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleFilterPosition3DInterp.h : �w�b�_�[ �t�@�C��
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterPosition3DInterp �_�C�A���O

class DialogModuleFilterPosition3DInterp : public CDialog
{
// �R���X�g���N�V����
public:
	DialogModuleFilterPosition3DInterp(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;
	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogModuleFilterPosition3DInterp)
	enum { IDD = IDD_MODULE_FILTER_P3DINTERP };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogModuleFilterPosition3DInterp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogModuleFilterPosition3DInterp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposXspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMODULEFILTERPOSITION3DINTERP_H__3BAF9A53_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
