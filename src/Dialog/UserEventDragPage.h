#if !defined(AFX_USEREVENTDRAGPAGE_H__BF12F41C_062F_11D1_866C_0000E8A71353__INCLUDED_)
#define AFX_USEREVENTDRAGPAGE_H__BF12F41C_062F_11D1_866C_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// UserEventDragPage.h : �w�b�_�[ �t�@�C��
//

#include "UserEventPage.h"

/////////////////////////////////////////////////////////////////////////////
// UserEventDragPage �_�C�A���O

class UserEventDragPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventDragPage)

// �R���X�g���N�V����
public:
	UserEventDragPage();
	~UserEventDragPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(UserEventDragPage)
	enum { IDD = IDD_USER_EVENT_DRAG_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(UserEventDragPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(UserEventDragPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_USEREVENTDRAGPAGE_H__BF12F41C_062F_11D1_866C_0000E8A71353__INCLUDED_)
