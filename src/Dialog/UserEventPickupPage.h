// UserEventPickuPpage.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// UserEventPickupPage �_�C�A���O

#include "UserEventPage.h"

class UserEventPickupPage : public CPropertyPage, public UserEventPage
{
	DECLARE_DYNCREATE(UserEventPickupPage)

// �R���X�g���N�V����
public:
	UserEventPickupPage();
	~UserEventPickupPage();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(UserEventPickupPage)
	enum { IDD = IDD_USER_EVENT_PICKUP_PAGE };
		// ���� - ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
		//    ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(UserEventPickupPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(UserEventPickupPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
