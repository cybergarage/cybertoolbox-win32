#if !defined(AFX_DIALOGMFIELDCONFIG_H__6A7D6D83_54C5_11D1_A924_02608CA85C38__INCLUDED_)
#define AFX_DIALOGMFIELDCONFIG_H__6A7D6D83_54C5_11D1_A924_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogMFieldConfig.h : �w�b�_�[ �t�@�C��
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogMFieldConfig �_�C�A���O

class MField;

class DialogMFieldConfig : public CDialog, public DialogSFieldConfig
{
// �R���X�g���N�V����
public:
	DialogMFieldConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogMFieldConfig)
	enum { IDD = IDD_MFIELD };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA

	MField	*mOrgMField;

	void	saveOriginalMField(MField *mfield);
	MField	*getOriginalMField()						{ return mOrgMField; }

	int		getSelectedItem();
	Field	*createNewField(MField *mfield);
	void	insertItem(int n);
	void	resetMFieldNumber();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogMFieldConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogMFieldConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkSfvalueList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnInsert();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMFIELDCONFIG_H__6A7D6D83_54C5_11D1_A924_02608CA85C38__INCLUDED_)
