#if !defined(AFX_USEREVENTTIMERPAGE_H__E6911E05_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
#define AFX_USEREVENTTIMERPAGE_H__E6911E05_19E7_11D2_A8B0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventTimerPage.h : �w�b�_�[ �t�@�C��
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventTimerPage �_�C�A���O

class UserEventTimerPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventTimerPage)

// �R���X�g���N�V����
public:
	UserEventTimerPage();
	~UserEventTimerPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(UserEventTimerPage)
	enum { IDD = IDD_USER_EVENT_TIMER };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(UserEventTimerPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(UserEventTimerPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_USEREVENTTIMERPAGE_H__E6911E05_19E7_11D2_A8B0_00605204B77B__INCLUDED_)
