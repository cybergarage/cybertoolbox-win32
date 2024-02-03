#if !defined(AFX_DIALOGSFVEC2FCONFIG_H__A344B542_55B2_11D1_A929_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFVEC2FCONFIG_H__A344B542_55B2_11D1_A929_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFVec2fConfig.h : �w�b�_�[ �t�@�C��
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFVec2fConfig �_�C�A���O

class DialogSFVec2fConfig : public CDialog, public DialogSFieldConfig
{
// �R���X�g���N�V����
public:
	DialogSFVec2fConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogSFVec2fConfig)
	enum { IDD = IDD_SFVEC2F };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogSFVec2fConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogSFVec2fConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGSFVEC2FCONFIG_H__A344B542_55B2_11D1_A929_02608CA85C38__INCLUDED_)