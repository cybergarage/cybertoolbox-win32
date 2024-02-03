#if !defined(AFX_DIALOGEVENTTIMER_H__E6911E04_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
#define AFX_DIALOGEVENTTIMER_H__E6911E04_19E7_11D2_A8B0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventTimer.h : �w�b�_�[ �t�@�C��
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventTimer �_�C�A���O

class DialogEventTimer : public CDialog, public DialogEvent
{
// �R���X�g���N�V����
public:
	DialogEventTimer(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogEventTimer)
	enum { IDD = IDD_EVENT_TIMER };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogEventTimer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogEventTimer)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGEVENTTIMER_H__E6911E04_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
