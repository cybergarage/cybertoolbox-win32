#if !defined(AFX_USEREVENTAREAPAGE_H__FC756E23_3164_11D1_86A1_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTAREAPAGE_H__FC756E23_3164_11D1_86A1_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventAreaPage.h : �w�b�_�[ �t�@�C��
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventAreaPage �_�C�A���O

class UserEventAreaPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventAreaPage)

// �R���X�g���N�V����
public:
	UserEventAreaPage();
	~UserEventAreaPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(UserEventAreaPage)
	enum { IDD = IDD_USER_EVENT_AREA };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(UserEventAreaPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(UserEventAreaPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_USEREVENTAREAPAGE_H__FC756E23_3164_11D1_86A1_0000E8A71353__INCLUDED_)
