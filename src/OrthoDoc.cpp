// OrthoDoc.cpp : インプリメンテーション ファイル
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
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc 診断

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
// OrthoDoc シリアライズ

void OrthoDoc::Serialize(CArchive& ar)
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
// OrthoDoc コマンド
