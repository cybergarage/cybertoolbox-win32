// DialogNodeConfig.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogNodeConfig ダイアログ
#ifndef _DIALOGNODECONFIG_H_
#define _DIALOGNODECONFIG_H_

class Node;
class Field;
class MField;

bool	OpenFieldDialog(Node *node, Field *field, CWnd *parentWnd);

class DialogNodeConfig : public CDialog
{
// コンストラクション
public:
	DialogNodeConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

	Node	*mNode;
	void	setNode(Node *node)	{mNode = node;}
	Node	*getNode()			{return mNode;}

// ダイアログ データ
	//{{AFX_DATA(DialogNodeConfig)
	enum { IDD = IDD_NODECONFIG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(DialogNodeConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogNodeConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkNodefield(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
