#if !defined(AFX_DIALOGSFTIMECONFIG_H__B2B10D56_5581_11D1_A927_02608CA85C38__INCLUDED_)
#define AFX_DIALOGSFTIMECONFIG_H__B2B10D56_5581_11D1_A927_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogSFTimeConfig.h : �w�b�_�[ �t�@�C��
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogSFTimeConfig �_�C�A���O

class DialogSFTimeConfig : public CDialog, public DialogSFieldConfig
{
// �R���X�g���N�V����
public:
	DialogSFTimeConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogSFTimeConfig)
	enum { IDD = IDD_SFTIME };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogSFTimeConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogSFTimeConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGSFTIMECONFIG_H__B2B10D56_5581_11D1_A927_02608CA85C38__INCLUDED_)
