#if !defined(AFX_DIALOGAUDIOCLIPNAME_H__3F415034_9BD5_11D2_9BC7_00A0C9B17B86__INCLUDED_)
#define AFX_DIALOGAUDIOCLIPNAME_H__3F415034_9BD5_11D2_9BC7_00A0C9B17B86__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogAudioClipName.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogAudioClipName �_�C�A���O

class Node;

class DialogAudioClipName : public CDialog
{
// �R���X�g���N�V����
public:
	DialogAudioClipName(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogAudioClipName)
	enum { IDD = IDD_AUDIOCLIP };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogAudioClipName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogAudioClipName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGAUDIOCLIPNAME_H__3F415034_9BD5_11D2_9BC7_00A0C9B17B86__INCLUDED_)
