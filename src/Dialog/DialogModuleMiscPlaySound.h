#if !defined(AFX_DIALOGMODULEMISCPLAYSOUND_H__19FB8514_1466_11D2_A8A7_00605204B77B__INCLUDED_)
#define AFX_DIALOGMODULEMISCPLAYSOUND_H__19FB8514_1466_11D2_A8A7_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleMiscPlaySound.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogModuleMiscPlaySound �_�C�A���O

class Node;

class DialogModuleMiscPlaySound : public CDialog
{
// �R���X�g���N�V����
public:
	DialogModuleMiscPlaySound(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogModuleMiscPlaySound)
	enum { IDD = IDD_MODULE_MISC_PLAYSOUND };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogModuleMiscPlaySound)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogModuleMiscPlaySound)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMODULEMISCPLAYSOUND_H__19FB8514_1466_11D2_A8A7_00605204B77B__INCLUDED_)
