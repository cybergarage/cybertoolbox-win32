// CyberToolBoxDoc.cpp : CCyberToolBoxDoc �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "CyberToolBox.h"

#include "CyberToolBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc

IMPLEMENT_DYNCREATE(CCyberToolBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CCyberToolBoxDoc, CDocument)
	//{{AFX_MSG_MAP(CCyberToolBoxDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc �N���X�̍\�z/����

CCyberToolBoxDoc::CCyberToolBoxDoc()
{
	// TODO: ���̈ʒu�ɂP�񂾂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CCyberToolBoxDoc::~CCyberToolBoxDoc()
{
}

BOOL CCyberToolBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc �V���A���C�[�[�V����

void CCyberToolBoxDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���̈ʒu�ɕۑ��p�̃R�[�h��ǉ����Ă��������B
	}
	else
	{
		// TODO: ���̈ʒu�ɓǂݍ��ݗp�̃R�[�h��ǉ����Ă��������B
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc �N���X�̐f�f

#ifdef _DEBUG
void CCyberToolBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCyberToolBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc �R�}���h

