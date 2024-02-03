// DiagramDoc.cpp : インプリメンテーション ファイル
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
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramDoc 診断

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
// CDiagramDoc シリアライズ

void CDiagramDoc::Serialize(CArchive& ar)
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
// CDiagramDoc コマンド
