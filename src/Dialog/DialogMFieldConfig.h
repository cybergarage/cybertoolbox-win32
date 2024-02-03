#if !defined(AFX_DIALOGMFIELDCONFIG_H__6A7D6D83_54C5_11D1_A924_02608CA85C38__INCLUDED_)
#define AFX_DIALOGMFIELDCONFIG_H__6A7D6D83_54C5_11D1_A924_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogMFieldConfig.h : ヘッダー ファイル
//

#include "DialogSFieldConfig.h"

/////////////////////////////////////////////////////////////////////////////
// DialogMFieldConfig ダイアログ

class MField;

class DialogMFieldConfig : public CDialog, public DialogSFieldConfig
{
// コンストラクション
public:
	DialogMFieldConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(DialogMFieldConfig)
	enum { IDD = IDD_MFIELD };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA

	MField	*mOrgMField;

	void	saveOriginalMField(MField *mfield);
	MField	*getOriginalMField()						{ return mOrgMField; }

	int		getSelectedItem();
	Field	*createNewField(MField *mfield);
	void	insertItem(int n);
	void	resetMFieldNumber();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogMFieldConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogMFieldConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkSfvalueList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnInsert();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGMFIELDCONFIG_H__6A7D6D83_54C5_11D1_A924_02608CA85C38__INCLUDED_)
