#if !defined(AFX_ORTHODOC_H__D5746E06_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
#define AFX_ORTHODOC_H__D5746E06_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OrthoDoc.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc �h�L�������g

class OrthoDoc : public CDocument
{
protected:
	OrthoDoc();           // ���I�����Ɏg�p�����v���e�N�g �R���X�g���N�^�B
	DECLARE_DYNCREATE(OrthoDoc)

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(OrthoDoc)
	public:
	virtual void Serialize(CArchive& ar);   // �h�L�������g I/O �ɑ΂��ăI�[�o�[���C�h����܂��B
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~OrthoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// ���b�Z�[�W �}�b�v�֐��̐���
protected:
	//{{AFX_MSG(OrthoDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ORTHODOC_H__D5746E06_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
