#if !defined(AFX_DIALOGMODULEINTERPNORMAL_H__65E8E01B_8D6F_11D2_9BAE_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGMODULEINTERPNORMAL_H__65E8E01B_8D6F_11D2_9BAE_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogModuleInterpNormal.h : �w�b�_�[ �t�@�C��
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialogModuleInterpNormal �_�C�A���O

class DialogModuleInterpNormal : public CDialog
{
// �R���X�g���N�V����
public:
	DialogModuleInterpNormal(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogModuleInterpNormal)
	enum { IDD = IDD_MODULE_INTERP_NORMAL };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogModuleInterpNormal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogModuleInterpNormal)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGMODULEINTERPNORMAL_H__65E8E01B_8D6F_11D2_9BAE_00A0C9B17B86__INCLUDED_)
