#if !defined(AFX_PRIMITIVEFLOATING_H__F19D1083_D34D_11D1_872B_0000E8A71353__INCLUDED_)
#define AFX_PRIMITIVEFLOATING_H__F19D1083_D34D_11D1_872B_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// PrimitiveFloating.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// PrimitiveFloating ダイアログ

enum {
PRIMITIVE_TYPE_SPHERE,
PRIMITIVE_TYPE_CONE,
PRIMITIVE_TYPE_BOX,
PRIMITIVE_TYPE_CYLINDER,
PRIMITIVE_TYPE_TEXT,
PRIMITIVE_TYPE_POLYGON,
};

class PrimitiveFloating : public CDialog
{
	int		mPrimitiveType;
// コンストラクション
public:
	PrimitiveFloating(CWnd* pParent = NULL);   // 標準のコンストラクタ

	BOOL Create(CWnd* pParent = NULL);

	void setPrimitiveType(int type) {
		mPrimitiveType = type;
	}

	int getPrimitiveType() {
		return mPrimitiveType;
	}

	char *getPrimitiveName(int primitiveType);
	char *getMaterialName(int primitiveType);

// ダイアログ データ
	//{{AFX_DATA(PrimitiveFloating)
	enum { IDD = IDD_PRIMITIVE };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(PrimitiveFloating)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(PrimitiveFloating)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_PRIMITIVEFLOATING_H__F19D1083_D34D_11D1_872B_0000E8A71353__INCLUDED_)
