#if !defined(AFX_DIALOGPROGRESS_H__4045AFE2_3269_11D1_86A1_0000E8A71353__INCLUDED_)
#define AFX_DIALOGPROGRESS_H__4045AFE2_3269_11D1_86A1_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogProgress.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogProgress ダイアログ

class DialogProgress : public CDialog
{
// コンストラクション
public:
	char			*mName;
	int				mRange;
	CProgressCtrl	*mProgressCtrl;

	DialogProgress(char *name, int range, CWnd* pParent = NULL);   // 標準のコンストラクタ
	BOOL Create();
	void setPos(int pos);

// ダイアログ データ
	//{{AFX_DATA(DialogProgress)
	enum { IDD = IDD_PROGRESS };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogProgress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogProgress)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGPROGRESS_H__4045AFE2_3269_11D1_86A1_0000E8A71353__INCLUDED_)
