// DiagramDoc.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "DiagramDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiagramDoc

IMPLEMENT_DYNCREATE(CDiagramDoc, CDocument)

CDiagramDoc::CDiagramDoc()
{
}

BOOL CDiagramDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CDiagramDoc::~CDiagramDoc()
{
}


BEGIN_MESSAGE_MAP(CDiagramDoc, CDocument)
	//{{AFX_MSG_MAP(CDiagramDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramDoc �f�f

#ifdef _DEBUG
void CDiagramDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDiagramDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiagramDoc �V���A���C�Y

void CDiagramDoc::Serialize(CArchive& ar)
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
// CDiagramDoc �R�}���h
