#if !defined(AFX_DIALOGGLOBALDATANAME_H__66520E87_0906_11D1_866C_0000E8A71353__INCLUDED_)
#define AFX_DIALOGGLOBALDATANAME_H__66520E87_0906_11D1_866C_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogGlobalDataName.h : �w�b�_�[ �t�@�C��
//

#include "SceneGraph.h"

/////////////////////////////////////////////////////////////////////////////
// DialogGlobalDataName �_�C�A���O

#define GLOBALDATA_SIZE		512

class DialogGlobalDataName : public CDialog
{
// �R���X�g���N�V����
public:
	DialogGlobalDataName(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	char	mGlobalDataName[GLOBALDATA_SIZE];
	char	*getGlobalDataName()	{return mGlobalDataName;}

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogGlobalDataName)
	enum { IDD = IDD_GLOBALDATA_NAME };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogGlobalDataName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogGlobalDataName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGGLOBALDATANAME_H__66520E87_0906_11D1_866C_0000E8A71353__INCLUDED_)
