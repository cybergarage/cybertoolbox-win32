// PerspectiveDoc.cpp : インプリメンテーション ファイル
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
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PerspectiveDoc 診断

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
// PerspectiveDoc シリアライズ

void PerspectiveDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください
	}
}

/////////////////////////////////////////////////////////////////////////////
// PerspectiveDoc コマンド
