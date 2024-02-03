#if !defined(AFX_DIALOGEVENTPICKUP_H__7F19A91B_5F5F_11D1_86D7_0000E8A71353__INCLUDED_)
#define AFX_DIALOGEVENTPICKUP_H__7F19A91B_5F5F_11D1_86D7_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventPickup.h : �w�b�_�[ �t�@�C��
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventPickup �_�C�A���O

class DialogEventPickup : public CDialog, public DialogEvent
{
// �R���X�g���N�V����
public:
	DialogEventPickup(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogEventPickup)
	enum { IDD = IDD_EVENT_PICKUP };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogEventPickup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogEventPickup)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGEVENTPICKUP_H__7F19A91B_5F5F_11D1_86D7_0000E8A71353__INCLUDED_)
