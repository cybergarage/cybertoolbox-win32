#if !defined(AFX_DIALOGPERSPECTIVEVIEWCONFIG_H__542943C3_2101_11D2_A8BA_00605204B77B__INCLUDED_)
#define AFX_DIALOGPERSPECTIVEVIEWCONFIG_H__542943C3_2101_11D2_A8BA_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogPerspectiveViewConfig.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogPerspectiveViewConfig ダイアログ

class DialogPerspectiveViewConfig : public CDialog
{
// コンストラクション
public:
	DialogPerspectiveViewConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogPerspectiveViewConfig)
	enum { IDD = IDD_PERSPECTIVE_CONFIG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA

	int			mRenderingMode;
	void		setRenderingMode(int mode)	{ mRenderingMode = mode; }
	int			getRenderingMode()			{ return mRenderingMode; }

	float		mSpeed;
	void		setSpeed(float speed)		{ mSpeed = speed; }
	float		getSpeed()					{ return mSpeed; }

	bool		mbHeadLight;
	bool		getHeadLight()				{ return mbHeadLight; }
	void		setHeadLight(bool on)		{ mbHeadLight = on; }

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogPerspectiveViewConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogPerspectiveViewConfig)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposSpinNavigationinfoSpeed(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGPERSPECTIVEVIEWCONFIG_H__542943C3_2101_11D2_A8BA_00605204B77B__INCLUDED_)
