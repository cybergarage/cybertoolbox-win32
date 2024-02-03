#if !defined(AFX_DIALOGMODULEFILTERORIENTATIONINTERP_H__3BAF9A51_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEFILTERORIENTATIONINTERP_H__3BAF9A51_10B9_11D2_A8A0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleFilterOrientationInterp.h : �w�b�_�[ �t�@�C��
//
#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterOrientationInterp �_�C�A���O

class DialogModuleFilterOrientationInterp : public CDialog
{
// �R���X�g���N�V����
public:
	DialogModuleFilterOrientationInterp(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;
	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogModuleFilterOrientationInterp)
	enum { IDD = IDD_MODULE_FILTER_ORIINTERP };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogModuleFilterOrientationInterp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogModuleFilterOrientationInterp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposXspin3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposRspin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposRspin2(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMODULEFILTERORIENTATIONINTERP_H__3BAF9A51_10B9_11D2_A8A0_00605204B77B__INCLUDED_)
