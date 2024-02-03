// ModuleConfig.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// ModuleConfig ダイアログ

#include "CModuleType.h"
#include "Icon.h"

class ModuleConfig : public CDialog
{
	GrIcon		mIcon;
	CModuleType	*mModuleType;

public:
	void		setModuleType(CModuleType *cm)	{ mModuleType = cm; }
	CModuleType	*getModuleType()				{ return mModuleType; }
	void		updateEventField(Field *field[], int idcEventInName, int idcEventInType);
	void		updateEventField();
	void		updateDialogField();
	void		getDialogField();

// コンストラクション
public:
	ModuleConfig(CWnd* pParent = NULL);   // 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(ModuleConfig)
	enum { IDD = IDD_MODULE_CONFIG };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(ModuleConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(ModuleConfig)
	afx_msg void OnScriptSelect();
	afx_msg void OnModuleIconSelect();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
