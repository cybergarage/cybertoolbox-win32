// PerspectiveFrame.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// PerspectiveFrame フレーム

class PerspectiveFrame : public CFrameWnd
{
	DECLARE_DYNCREATE(PerspectiveFrame)
protected:
	PerspectiveFrame();           // 動的生成に使用されるプロテクト コンストラクタ。

// アトリビュート
public:

	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// オペレーション
public:

	void OnUpdateFrameTitle(BOOL bAddToTitle);

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(PerspectiveFrame)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~PerspectiveFrame();

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(PerspectiveFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
