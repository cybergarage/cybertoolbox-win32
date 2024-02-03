#if !defined(AFX_DIALOGORTHVIEWCONFIG_H__F2CB6993_6079_11D1_A942_00605204B77B__INCLUDED_)
#define AFX_DIALOGORTHVIEWCONFIG_H__F2CB6993_6079_11D1_A942_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogOrthviewConfig.h : �w�b�_�[ �t�@�C��
//

#include "..\OrthoView.h"

/////////////////////////////////////////////////////////////////////////////
// DialogOrthviewConfig �_�C�A���O

class DialogOrthviewConfig : public CDialog, public OrthoConfig
{
// �R���X�g���N�V����
public:
	DialogOrthviewConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogOrthviewConfig)
	enum { IDD = IDD_ORTHVIEW_CONFIG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogOrthviewConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogOrthviewConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposSpinPosition(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinAngle(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGORTHVIEWCONFIG_H__F2CB6993_6079_11D1_A942_00605204B77B__INCLUDED_)
