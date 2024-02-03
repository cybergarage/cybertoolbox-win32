#if !defined(AFX_DIALOGPROGRESS_H__4045AFE2_3269_11D1_86A1_0000E8A71353__INCLUDED_)
#define AFX_DIALOGPROGRESS_H__4045AFE2_3269_11D1_86A1_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogProgress.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogProgress �_�C�A���O

class DialogProgress : public CDialog
{
// �R���X�g���N�V����
public:
	char			*mName;
	int				mRange;
	CProgressCtrl	*mProgressCtrl;

	DialogProgress(char *name, int range, CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	BOOL Create();
	void setPos(int pos);

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogProgress)
	enum { IDD = IDD_PROGRESS };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogProgress)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGPROGRESS_H__4045AFE2_3269_11D1_86A1_0000E8A71353__INCLUDED_)
