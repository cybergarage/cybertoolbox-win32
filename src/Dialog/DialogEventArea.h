#if !defined(AFX_DIALOGEVENTAREA_H__B57B8B74_5EE4_11D1_A93C_00605204B77B__INCLUDED_)
#define AFX_DIALOGEVENTAREA_H__B57B8B74_5EE4_11D1_A93C_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventArea.h : �w�b�_�[ �t�@�C��
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventArea �_�C�A���O

class DialogEventArea : public CDialog, public DialogEvent
{
// �R���X�g���N�V����
public:
	DialogEventArea(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogEventArea)
	enum { IDD = IDD_EVENT_AREA };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogEventArea)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogEventArea)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGEVENTAREA_H__B57B8B74_5EE4_11D1_A93C_00605204B77B__INCLUDED_)
