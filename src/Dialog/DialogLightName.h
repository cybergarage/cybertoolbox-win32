#if !defined(AFX_DIALOGLIGHTNAME_H__5651770B_21B1_11D1_8689_0000E8A71353__INCLUDED_)
#define AFX_DIALOGLIGHTNAME_H__5651770B_21B1_11D1_8689_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogLightName.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogLightName ダイアログ

enum {
LIGHTTYPE_DIRECTIONAL	=	0x01,
LIGHTTYPE_POINT			=	0x02,
LIGHTTYPE_SPOT			=	0x04,
};

class Node;

class DialogLightName : public CDialog
{
// コンストラクション
public:
	DialogLightName(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node		*mNode;
	void		setNode(Node *node)			{ mNode = node; }
	Node		*getNode()					{ return mNode; }

	int			mType;
	void		setType(int type)			{ mType = type; }
	int			getType()					{ return mType; }

// ダイアログ データ
	//{{AFX_DATA(DialogLightName)
	enum { IDD = IDD_LIGHT_NAME };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogLightName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogLightName)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGLIGHTNAME_H__5651770B_21B1_11D1_8689_0000E8A71353__INCLUDED_)
