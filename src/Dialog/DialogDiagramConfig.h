#if !defined(AFX_DIALOGDIAGRAMCONFIG_H__97B4E223_6236_11D1_A944_00605204B77B__INCLUDED_)
#define AFX_DIALOGDIAGRAMCONFIG_H__97B4E223_6236_11D1_A944_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogDiagramConfig.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogDiagramConfig ダイアログ

class TransformNode;

class DialogDiagramConfig : public CDialog
{
// コンストラクション
public:
	DialogDiagramConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

	TransformNode	*mTransformNode;

	void			setTransformNode(TransformNode *node)	{ mTransformNode = node; }
	TransformNode	*getTransformNode()					{ return mTransformNode; }

	//////////////////////////////////////////////////
	// Line Style
	//////////////////////////////////////////////////

	int		mLineStyle;

	void	setLineStyle(int style) { mLineStyle = style; }
	int		getLineStyle()			{ return mLineStyle; }

	//////////////////////////////////////////////////
	// Grid
	//////////////////////////////////////////////////
	
	bool	mGridSnap;
	bool	mGridDisplay;

	void	setGridSnap(bool on)	{ mGridSnap = on; }
	bool	getGridSnap()			{ return mGridSnap; }

	void	setGridDisplay(bool on)	{ mGridDisplay = on; }
	bool	getGridDisplay()		{ return mGridDisplay; }

// ダイアログ データ
	//{{AFX_DATA(DialogDiagramConfig)
	enum { IDD = IDD_DIAGRAM_CONFIG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogDiagramConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogDiagramConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGDIAGRAMCONFIG_H__97B4E223_6236_11D1_A944_00605204B77B__INCLUDED_)
