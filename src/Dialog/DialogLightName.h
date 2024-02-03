#if !defined(AFX_DIALOGLIGHTNAME_H__5651770B_21B1_11D1_8689_0000E8A71353__INCLUDED_)
#define AFX_DIALOGLIGHTNAME_H__5651770B_21B1_11D1_8689_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogLightName.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogLightName �_�C�A���O

enum {
LIGHTTYPE_DIRECTIONAL	=	0x01,
LIGHTTYPE_POINT			=	0x02,
LIGHTTYPE_SPOT			=	0x04,
};

class Node;

class DialogLightName : public CDialog
{
// �R���X�g���N�V����
public:
	DialogLightName(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

	int			mType;
	void		setType(int type)			{ mType = type; }
	int			getType()					{ return mType; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogLightName)
	enum { IDD = IDD_LIGHT_NAME };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogLightName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogLightName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGLIGHTNAME_H__5651770B_21B1_11D1_8689_0000E8A71353__INCLUDED_)
