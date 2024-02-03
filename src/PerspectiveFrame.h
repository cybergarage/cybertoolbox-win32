// PerspectiveFrame.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// PerspectiveFrame �t���[��

class PerspectiveFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(PerspectiveFrame)
protected:
	PerspectiveFrame();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B

// �A�g���r���[�g
public:

	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// �I�y���[�V����
public:

	void OnUpdateFrameTitle(BOOL bAddToTitle);

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(PerspectiveFrame)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~PerspectiveFrame();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(PerspectiveFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
