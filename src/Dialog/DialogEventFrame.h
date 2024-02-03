#if !defined(AFX_DIALOGEVENTFRAME_H__B57B8B73_5EE4_11D1_A93C_00605204B77B__INCLUDED_)
#define AFX_DIALOGEVENTFRAME_H__B57B8B73_5EE4_11D1_A93C_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventFrame.h : �w�b�_�[ �t�@�C��
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventFrame �_�C�A���O

class DialogEventFrame : public CDialog, public DialogEvent
{
// �R���X�g���N�V����
public:
	DialogEventFrame(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogEventFrame)
	enum { IDD = IDD_EVENT_FRAME };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogEventFrame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogEventFrame)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGEVENTFRAME_H__B57B8B73_5EE4_11D1_A93C_00605204B77B__INCLUDED_)
