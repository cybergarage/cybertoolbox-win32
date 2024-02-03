#if !defined(AFX_DIALOGOBJECTCOLLISION_H__AA8DD708_F01E_11D1_8740_0000E8A71353__INCLUDED_)
#define AFX_DIALOGOBJECTCOLLISION_H__AA8DD708_F01E_11D1_8740_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogObjectCollision.h : ヘッダー ファイル
//

class Node;

/////////////////////////////////////////////////////////////////////////////
// DialogObjectCollision ダイアログ

class DialogObjectCollision : public CDialog
{
// コンストラクション
public:
	DialogObjectCollision(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode1;
	void		setNode1(Node *node)		{ mNode1 = node; }
	Node		*getNode1()					{ return mNode1; }

	float		mRadius1;
	void		setRadius1(float radius)	{ mRadius1 = radius; }
	float		getRadius1()				{ return mRadius1; }

	Node		*mNode2;
	void		setNode2(Node *node)		{ mNode2 = node; }
	Node		*getNode2()					{ return mNode2; }

	float		mRadius2;
	void		setRadius2(float radius)	{ mRadius2 = radius; }
	float		getRadius2()				{ return mRadius2; }

// ダイアログ データ
	//{{AFX_DATA(DialogObjectCollision)
	enum { IDD = IDD_OBJECTNAME_2 };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogObjectCollision)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogObjectCollision)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGOBJECTCOLLISION_H__AA8DD708_F01E_11D1_8740_0000E8A71353__INCLUDED_)
