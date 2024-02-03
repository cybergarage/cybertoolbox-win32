// DiagramFrame.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CDiagramFrame フレーム

class CDiagramFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(CDiagramFrame)
protected:
	CDiagramFrame();           // 動的生成に使用されるプロテクト コンストラクタ。

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(CDiagramFrame)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CDiagramFrame();

protected:  // コントロール バー用メンバ
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CDiagramFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
