#if !defined(AFX_ORTHOFRAME_H__D5746E04_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
#define AFX_ORTHOFRAME_H__D5746E04_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OrthoFrame.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// OrthoFrame フレーム

class OrthoFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(OrthoFrame)
protected:
	OrthoFrame();           // 動的生成に使用されるプロテクト コンストラクタ。

// アトリビュート
public:

	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// オペレーション
public:

	void OnUpdateFrameTitle(BOOL bAddToTitle);

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(OrthoFrame)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~OrthoFrame();

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(OrthoFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ORTHOFRAME_H__D5746E04_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
