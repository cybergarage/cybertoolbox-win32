#if !defined(AFX_DIALOGMODULESTRINGBOOL_H__AA5DEEED_42C6_11D2_9AFB_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGMODULESTRINGBOOL_H__AA5DEEED_42C6_11D2_9AFB_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleStringBool.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringBool �_�C�A���O

#include "CModule.h"

class DialogModuleStringBool : public CDialog
{
// �R���X�g���N�V����
public:
	DialogModuleStringBool(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogModuleStringBool)
	enum { IDD = IDD_STRING_BOOL };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogModuleStringBool)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogModuleStringBool)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMODULESTRINGBOOL_H__AA5DEEED_42C6_11D2_9AFB_00A0C9B17B86__INCLUDED_)
