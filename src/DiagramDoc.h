// DiagramDoc.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CDiagramDoc �h�L�������g

class CDiagramDoc : public CDocument
{
protected:
	CDiagramDoc();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(CDiagramDoc)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CDiagramDoc)
	public:
	virtual void Serialize(CArchive& ar);   // �h�L�������g I/O �ɑ΂��ăI�[�o�[���C�h����܂��B
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CDiagramDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// ���b�Z�[�W �}�b�v�֐��̐���
protected:
	//{{AFX_MSG(CDiagramDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
