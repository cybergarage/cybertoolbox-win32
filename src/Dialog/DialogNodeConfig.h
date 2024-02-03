// DialogNodeConfig.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogNodeConfig �_�C�A���O
#ifndef _DIALOGNODECONFIG_H_
#define _DIALOGNODECONFIG_H_

class Node;
class Field;
class MField;

bool	OpenFieldDialog(Node *node, Field *field, CWnd *parentWnd);

class DialogNodeConfig : public CDialog
{
// �R���X�g���N�V����
public:
	DialogNodeConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	Node	*mNode;
	void	setNode(Node *node)	{mNode = node;}
	Node	*getNode()			{return mNode;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogNodeConfig)
	enum { IDD = IDD_NODECONFIG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(DialogNodeConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogNodeConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkNodefield(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
