#if !defined(AFX_DIALOGMODULESTRINGVECTOR_H__167F79B3_1076_11D2_A89E_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULESTRINGVECTOR_H__167F79B3_1076_11D2_A89E_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleStringVector.h : �w�b�_�[ �t�@�C��
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringVector �_�C�A���O

class DialogModuleStringVector : public CDialog
{
// �R���X�g���N�V����
public:
	DialogModuleStringVector(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogModuleStringVector)
	enum { IDD = IDD_MODULE_STRING_VECTOR };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogModuleStringVector)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogModuleStringVector)
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMODULESTRINGVECTOR_H__167F79B3_1076_11D2_A89E_00605204B77B__INCLUDED_)