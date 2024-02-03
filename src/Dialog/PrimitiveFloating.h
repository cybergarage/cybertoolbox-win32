#if !defined(AFX_PRIMITIVEFLOATING_H__F19D1083_D34D_11D1_872B_0000E8A71353__INCLUDED_)
#define AFX_PRIMITIVEFLOATING_H__F19D1083_D34D_11D1_872B_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PrimitiveFloating.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// PrimitiveFloating �_�C�A���O

enum {
PRIMITIVE_TYPE_SPHERE,
PRIMITIVE_TYPE_CONE,
PRIMITIVE_TYPE_BOX,
PRIMITIVE_TYPE_CYLINDER,
PRIMITIVE_TYPE_TEXT,
PRIMITIVE_TYPE_POLYGON,
};

class PrimitiveFloating : public CDialog
{
	int		mPrimitiveType;
// �R���X�g���N�V����
public:
	PrimitiveFloating(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	BOOL Create(CWnd* pParent = NULL);

	void setPrimitiveType(int type) {
		mPrimitiveType = type;
	}

	int getPrimitiveType() {
		return mPrimitiveType;
	}

	char *getPrimitiveName(int primitiveType);
	char *getMaterialName(int primitiveType);

// �_�C�A���O �f�[�^
	//{{AFX_DATA(PrimitiveFloating)
	enum { IDD = IDD_PRIMITIVE };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(PrimitiveFloating)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(PrimitiveFloating)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_PRIMITIVEFLOATING_H__F19D1083_D34D_11D1_872B_0000E8A71353__INCLUDED_)
