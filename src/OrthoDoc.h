#if !defined(AFX_ORTHODOC_H__D5746E06_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
#define AFX_ORTHODOC_H__D5746E06_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OrthoDoc.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// OrthoDoc ドキュメント

class OrthoDoc : public CDocument
{
protected:
	OrthoDoc();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(OrthoDoc)

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(OrthoDoc)
	public:
	virtual void Serialize(CArchive& ar);   // ドキュメント I/O に対してオーバーライドされます。
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~OrthoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// メッセージ マップ関数の生成
protected:
	//{{AFX_MSG(OrthoDoc)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ORTHODOC_H__D5746E06_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
