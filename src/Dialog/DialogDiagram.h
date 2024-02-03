#if !defined(AFX_DIALOGDIAGRAM_H__C3EFD60B_2462_11D1_868E_0000E8A71353__INCLUDED_)
#define AFX_DIALOGDIAGRAM_H__C3EFD60B_2462_11D1_868E_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogDiagram.h : �w�b�_�[ �t�@�C��
//

class TransformNode;

#include "SceneGraph.h"

/////////////////////////////////////////////////////////////////////////////
// DialogDiagram �_�C�A���O

class DialogDiagram : public CDialog
{
// �R���X�g���N�V����
public:
	DialogDiagram(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	TransformNode	*mNode;
	void			setNode(TransformNode *node)		{ mNode = node; }
	TransformNode	*getNode()						{ return mNode; }
	
	String		mName;

	void		setName(char *name)				{ mName.setValue(name); }
	char		*getName()						{ return mName.getValue(); }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogDiagram)
	enum { IDD = IDD_DIAGRAM };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogDiagram)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogDiagram)
	virtual void OnOK();
	afx_msg void OnOpen();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGDIAGRAM_H__C3EFD60B_2462_11D1_868E_0000E8A71353__INCLUDED_)
