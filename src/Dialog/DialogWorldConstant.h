// DialogWorldConstant.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// DialogWorldConstant �_�C�A���O

#include "CModule.h"

class DialogWorldConstant : public CDialog
{
// �R���X�g���N�V����
public:
	DialogWorldConstant(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogWorldConstant)
	enum { IDD = IDD_WORLDCONSTANT };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(DialogWorldConstant)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(DialogWorldConstant)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
