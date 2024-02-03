#if !defined(AFX_DIALOGPERSPECTIVEVIEWCONFIG_H__542943C3_2101_11D2_A8BA_00605204B77B__INCLUDED_)
#define AFX_DIALOGPERSPECTIVEVIEWCONFIG_H__542943C3_2101_11D2_A8BA_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogPerspectiveViewConfig.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogPerspectiveViewConfig �_�C�A���O

class DialogPerspectiveViewConfig : public CDialog
{
// �R���X�g���N�V����
public:
	DialogPerspectiveViewConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogPerspectiveViewConfig)
	enum { IDD = IDD_PERSPECTIVE_CONFIG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA

	int			mRenderingMode;
	void		setRenderingMode(int mode)	{ mRenderingMode = mode; }
	int			getRenderingMode()			{ return mRenderingMode; }

	float		mSpeed;
	void		setSpeed(float speed)		{ mSpeed = speed; }
	float		getSpeed()					{ return mSpeed; }

	bool		mbHeadLight;
	bool		getHeadLight()				{ return mbHeadLight; }
	void		setHeadLight(bool on)		{ mbHeadLight = on; }

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogPerspectiveViewConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogPerspectiveViewConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposSpinNavigationinfoSpeed(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGPERSPECTIVEVIEWCONFIG_H__542943C3_2101_11D2_A8BA_00605204B77B__INCLUDED_)
