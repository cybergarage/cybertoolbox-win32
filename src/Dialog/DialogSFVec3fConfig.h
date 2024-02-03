#if !defined(AFX_DIALOGSFVEC3FCONFIG_H__9F803AF4_55B0_11D1_A929_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFVEC3FCONFIG_H__9F803AF4_55B0_11D1_A929_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFVec3fConfig.h : �w�b�_�[ �t�@�C��
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFVec3fConfig �_�C�A���O

class DialogSFVec3fConfig : public CDialog, public DialogSFieldConfig
{
// �R���X�g���N�V����
public:
	DialogSFVec3fConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogSFVec3fConfig)
	enum { IDD = IDD_SFVEC3F };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogSFVec3fConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogSFVec3fConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGSFVEC3FCONFIG_H__9F803AF4_55B0_11D1_A929_02608CA85C38__INCLUDED_)
