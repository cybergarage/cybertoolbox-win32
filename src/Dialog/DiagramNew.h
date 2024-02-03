// DiagramNew.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DiagramNew �_�C�A���O

#include "SceneGraph.h"

class DiagramNew : public CDialog
{
// �R���X�g���N�V����
public:
	DiagramNew(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	~DiagramNew();
	
	int			nEventNumber;
	String		mName;
	String		*mListBoxString;
	
	void		setEventNumber(int n)					{nEventNumber = n;}
	int			getEventNumber()						{return nEventNumber;}

	void		setName(char *value)					{mName.setValue(value);}
	char		*getName()								{return mName.getValue();}

	void		setListBoxString(int n, char *string)	{mListBoxString[n].setValue(string);}
	char		*getListBoxString(int n)				{return mListBoxString[n].getValue();}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DiagramNew)
	enum { IDD = IDD_DIAGRAM_NEW };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(DiagramNew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DiagramNew)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
