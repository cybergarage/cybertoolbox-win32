// OrthoDoc.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "OrthoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc

IMPLEMENT_DYNCREATE(OrthoDoc, CDocument)

OrthoDoc::OrthoDoc()
{
}

BOOL OrthoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

OrthoDoc::~OrthoDoc()
{
}


BEGIN_MESSAGE_MAP(OrthoDoc, CDocument)
	//{{AFX_MSG_MAP(OrthoDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc �f�f

#ifdef _DEBUG
void OrthoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void OrthoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc �V���A���C�Y

void OrthoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă�������
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă�������
	}
}

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc �R�}���h
