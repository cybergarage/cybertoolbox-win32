#if !defined(AFX_DIALOGEVENTCLOCK_H__7F19A91C_5F5F_11D1_86D7_0000E8A71353__INCLUDED_)
#define AFX_DIALOGEVENTCLOCK_H__7F19A91C_5F5F_11D1_86D7_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventClock.h : �w�b�_�[ �t�@�C��
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventClock �_�C�A���O

class DialogEventClock : public CDialog, public DialogEvent
{
// �R���X�g���N�V����
public:
	DialogEventClock(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogEventClock)
	enum { IDD = IDD_EVENT_CLOCK };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogEventClock)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogEventClock)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGEVENTCLOCK_H__7F19A91C_5F5F_11D1_86D7_0000E8A71353__INCLUDED_)
