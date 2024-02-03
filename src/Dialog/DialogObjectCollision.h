#if !defined(AFX_DIALOGOBJECTCOLLISION_H__AA8DD708_F01E_11D1_8740_0000E8A71353__INCLUDED_)
#define AFX_DIALOGOBJECTCOLLISION_H__AA8DD708_F01E_11D1_8740_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogObjectCollision.h : �w�b�_�[ �t�@�C��
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialogObjectCollision �_�C�A���O

class DialogObjectCollision : public CDialog
{
// �R���X�g���N�V����
public:
	DialogObjectCollision(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	Node		*mNode1;
	void		setNode1(Node *node)		{ mNode1 = node; }
	Node		*getNode1()					{ return mNode1; }

	float		mRadius1;
	void		setRadius1(float radius)	{ mRadius1 = radius; }
	float		getRadius1()				{ return mRadius1; }

	Node		*mNode2;
	void		setNode2(Node *node)		{ mNode2 = node; }
	Node		*getNode2()					{ return mNode2; }

	float		mRadius2;
	void		setRadius2(float radius)	{ mRadius2 = radius; }
	float		getRadius2()				{ return mRadius2; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogObjectCollision)
	enum { IDD = IDD_OBJECTNAME_2 };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogObjectCollision)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogObjectCollision)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGOBJECTCOLLISION_H__AA8DD708_F01E_11D1_8740_0000E8A71353__INCLUDED_)
