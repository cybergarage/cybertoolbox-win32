#if !defined(AFX_USEREVENTCLOCKPAGE_H__BE4736F1_1317_11D1_8671_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTCLOCKPAGE_H__BE4736F1_1317_11D1_8671_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventClockPage.h : �w�b�_�[ �t�@�C��
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventClockPage �_�C�A���O

class UserEventClockPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventClockPage)

// �R���X�g���N�V����
public:
	UserEventClockPage();
	~UserEventClockPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(UserEventClockPage)
	enum { IDD = IDD_USER_EVENT_CLOCK_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(UserEventClockPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(UserEventClockPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_USEREVENTCLOCKPAGE_H__BE4736F1_1317_11D1_8671_0000E8A71353__INCLUDED_)
