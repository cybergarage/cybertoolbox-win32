// PerspectiveDoc.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "PerspectiveDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PerspectiveDoc

IMPLEMENT_DYNCREATE(PerspectiveDoc, CDocument)

PerspectiveDoc::PerspectiveDoc()
{
}

BOOL PerspectiveDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

PerspectiveDoc::~PerspectiveDoc()
{
}


BEGIN_MESSAGE_MAP(PerspectiveDoc, CDocument)
	//{{AFX_MSG_MAP(PerspectiveDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PerspectiveDoc �f�f

#ifdef _DEBUG
void PerspectiveDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void PerspectiveDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// PerspectiveDoc �V���A���C�Y

void PerspectiveDoc::Serialize(CArchive& ar)
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
// PerspectiveDoc �R�}���h
