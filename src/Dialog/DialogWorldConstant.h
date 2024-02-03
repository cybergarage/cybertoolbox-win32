// DialogWorldConstant.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogWorldConstant ダイアログ

#include "CModule.h"

class DialogWorldConstant : public CDialog
{
// コンストラクション
public:
	DialogWorldConstant(CWnd* pParent = NULL);   // 標準のコンストラクタ

	CModule	*mModule;

	void	setModule(CModule *module)	{mModule = module;}
	CModule	*getModule()				{return mModule;}

// ダイアログ データ
	//{{AFX_DATA(DialogWorldConstant)
	enum { IDD = IDD_WORLDCONSTANT };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(DialogWorldConstant)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogWorldConstant)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
