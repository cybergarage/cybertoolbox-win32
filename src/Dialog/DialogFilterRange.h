#if !defined(AFX_DIALOGFILTERRANGE_H__9A12A0C2_C2EC_11D1_871F_0000E8A71353__INCLUDED_)
#define AFX_DIALOGFILTERRANGE_H__9A12A0C2_C2EC_11D1_871F_0000E8A71353__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogFilterRange.h : ヘッダー ファイル
//

#include "CModule.h"

/////////////////////////////////////////////////////////////////////////////
// DialogFilterRange ダイアログ

class DialogFilterRange : public CDialog
{
// コンストラクション
public:
	DialogFilterRange(CWnd* pParent = NULL);   // 標準のコンストラクタ

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// ダイアログ データ
	//{{AFX_DATA(DialogFilterRange)
	enum { IDD = IDD_MODULE_FILTER_RANGE };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogFilterRange)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogFilterRange)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGFILTERRANGE_H__9A12A0C2_C2EC_11D1_871F_0000E8A71353__INCLUDED_)
