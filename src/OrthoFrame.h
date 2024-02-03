#if !defined(AFX_ORTHOFRAME_H__D5746E04_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
#define AFX_ORTHOFRAME_H__D5746E04_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OrthoFrame.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// OrthoFrame �t���[��

class OrthoFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(OrthoFrame)
protected:
	OrthoFrame();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B

// �A�g���r���[�g
public:

	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// �I�y���[�V����
public:

	void OnUpdateFrameTitle(BOOL bAddToTitle);

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(OrthoFrame)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~OrthoFrame();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(OrthoFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ORTHOFRAME_H__D5746E04_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
