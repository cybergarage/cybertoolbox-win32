#if !defined(AFX_DIALOGFILTERRANGE_H__9A12A0C2_C2EC_11D1_871F_0000E8A71353__INCLUDED_)
#define AFX_DIALOGFILTERRANGE_H__9A12A0C2_C2EC_11D1_871F_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogFilterRange.h : �w�b�_�[ �t�@�C��
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogFilterRange �_�C�A���O

class DialogFilterRange : public CDialog
{
// �R���X�g���N�V����
public:
	DialogFilterRange(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogFilterRange)
	enum { IDD = IDD_MODULE_FILTER_RANGE };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogFilterRange)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogFilterRange)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGFILTERRANGE_H__9A12A0C2_C2EC_11D1_871F_0000E8A71353__INCLUDED_)
