// CyberToolBoxDoc.cpp : CCyberToolBoxDoc クラスの動作の定義を行います。
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
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc クラスの構築/消滅

CCyberToolBoxDoc::CCyberToolBoxDoc()
{
	// TODO: この位置に１回だけ構築用のコードを追加してください。

}

CCyberToolBoxDoc::~CCyberToolBoxDoc()
{
}

BOOL CCyberToolBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc シリアライゼーション

void CCyberToolBoxDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: この位置に保存用のコードを追加してください。
	}
	else
	{
		// TODO: この位置に読み込み用のコードを追加してください。
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxDoc クラスの診断

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
// CCyberToolBoxDoc コマンド

