// DiagramFrame.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CDiagramFrame �t���[��

class CDiagramFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CDiagramFrame)
protected:
	CDiagramFrame();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CDiagramFrame)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	virtual ~CDiagramFrame();

protected:  // �R���g���[�� �o�[�p�����o
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDiagramFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
