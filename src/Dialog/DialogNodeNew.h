#if !defined(AFX_DIALOGNODENEW_H__884A8AA4_4EC7_11D1_86C1_0000E8A71353__INCLUDED_)
#define AFX_DIALOGNODENEW_H__884A8AA4_4EC7_11D1_86C1_0000E8A71353__INCLUDED_

#include "SceneGraph.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogNodeNew.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogNodeNew �_�C�A���O

class DialogNodeNew : public CDialog
{
// �R���X�g���N�V����
public:
	DialogNodeNew(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

public:

	Node		*mParentNode;
	Node		*mSelectedNode;
	NodeList	mNodeList;
	int			mSelectedItem;

	CImageList	mItemImageList;
	CBitmap		mItemBitmap[54];

	void setParentNode(Node *node) {
		mParentNode = node;
		if (node)
			createNodeList();
	}

	void createImageList();

	CImageList *getImageList() {
		return &mItemImageList;
	}

	Node *getParentNode() {
		return mParentNode;
	}

	void setSelectedNode(Node *node) {
		mSelectedNode = node;
	}

	Node *getSelectedNode() {
		return mSelectedNode;
	}

	bool addNode(Node *node);

	Node *getNodes() {
		return (Node *)mNodeList.getNodes();		
	}

	int getNNodes() {
		return mNodeList.getNNodes();		
	}

	Node *getNode(int n) {
		return (Node *)mNodeList.getNode(n);		
	}

	void setSelectedItem(int n) {
		mSelectedItem = n;
	}

	int getSelectedItem() {
		return mSelectedItem;
	}

	void createNodeList();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogNodeNew)
	enum { IDD = IDD_NODE_NEW };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogNodeNew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogNodeNew)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedNodeList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkNodeList(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGNODENEW_H__884A8AA4_4EC7_11D1_86C1_0000E8A71353__INCLUDED_)
