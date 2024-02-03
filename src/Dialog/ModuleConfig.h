// ModuleConfig.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// ModuleConfig �_�C�A���O

#include "CModuleType.h"
#include "Icon.h"

class ModuleConfig : public CDialog
{
	GrIcon		mIcon;
	CModuleType	*mModuleType;

public:
	void		setModuleType(CModuleType *cm)	{ mModuleType = cm; }
	CModuleType	*getModuleType()				{ return mModuleType; }
	void		updateEventField(Field *field[], int idcEventInName, int idcEventInType);
	void		updateEventField();
	void		updateDialogField();
	void		getDialogField();

// �R���X�g���N�V����
public:
	ModuleConfig(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(ModuleConfig)
	enum { IDD = IDD_MODULE_CONFIG };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(ModuleConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(ModuleConfig)
	afx_msg void OnScriptSelect();
	afx_msg void OnModuleIconSelect();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
