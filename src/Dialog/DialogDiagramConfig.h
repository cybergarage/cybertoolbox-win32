#if !defined(AFX_DIALOGDIAGRAMCONFIG_H__97B4E223_6236_11D1_A944_00605204B77B__INCLUDED_)
#define AFX_DIALOGDIAGRAMCONFIG_H__97B4E223_6236_11D1_A944_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogDiagramConfig.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogDiagramConfig �_�C�A���O

class TransformNode;

class DialogDiagramConfig : public CDialog
{
// �R���X�g���N�V����
public:
	DialogDiagramConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	TransformNode	*mTransformNode;

	void			setTransformNode(TransformNode *node)	{ mTransformNode = node; }
	TransformNode	*getTransformNode()					{ return mTransformNode; }

	//////////////////////////////////////////////////
	// Line Style
	//////////////////////////////////////////////////

	int		mLineStyle;

	void	setLineStyle(int style) { mLineStyle = style; }
	int		getLineStyle()			{ return mLineStyle; }

	//////////////////////////////////////////////////
	// Grid
	//////////////////////////////////////////////////
	
	bool	mGridSnap;
	bool	mGridDisplay;

	void	setGridSnap(bool on)	{ mGridSnap = on; }
	bool	getGridSnap()			{ return mGridSnap; }

	void	setGridDisplay(bool on)	{ mGridDisplay = on; }
	bool	getGridDisplay()		{ return mGridDisplay; }

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogDiagramConfig)
	enum { IDD = IDD_DIAGRAM_CONFIG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogDiagramConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogDiagramConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGDIAGRAMCONFIG_H__97B4E223_6236_11D1_A944_00605204B77B__INCLUDED_)
