#if !defined(AFX_DIALOGEVENTDRAG_H__5E597FA3_30B4_11D2_A8D0_00605204B77B__INCLUDED_)
#define AFX_DIALOGEVENTDRAG_H__5E597FA3_30B4_11D2_A8D0_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogEventDrag.h : ヘッダー ファイル
//

#include "DialogEvent.h"

/////////////////////////////////////////////////////////////////////////////
// DialogEventDrag ダイアログ

class DialogEventDrag : public CDialog, public DialogEvent
{
// コンストラクション
public:
	DialogEventDrag(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogEventDrag)
	enum { IDD = IDD_EVENT_DRAG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogEventDrag)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogEventDrag)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGEVENTDRAG_H__5E597FA3_30B4_11D2_A8D0_00605204B77B__INCLUDED_)
