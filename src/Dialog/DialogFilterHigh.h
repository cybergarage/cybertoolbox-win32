#if !defined(AFX_DIALOGFILTERHIGH_H__9A12A0BF_C2EC_11D1_871F_0000E8A71353__INCLUDED_)
#define AFX_DIALOGFILTERHIGH_H__9A12A0BF_C2EC_11D1_871F_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogFilterHigh.h : �w�b�_�[ �t�@�C��
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogFilterHigh �_�C�A���O

class DialogFilterHigh : public CDialog
{
// �R���X�g���N�V����
public:
	DialogFilterHigh(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogFilterHigh)
	enum { IDD = IDD_MODULE_FILTER_HIGH };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogFilterHigh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogFilterHigh)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGFILTERHIGH_H__9A12A0BF_C2EC_11D1_871F_0000E8A71353__INCLUDED_)
