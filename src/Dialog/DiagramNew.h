// DiagramNew.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DiagramNew ダイアログ

#include "SceneGraph.h"

class DiagramNew : public CDialog
{
// コンストラクション
public:
	DiagramNew(CWnd* pParent = NULL);   // 標準のコンストラクタ
	~DiagramNew();
	
	int			nEventNumber;
	String		mName;
	String		*mListBoxString;
	
	void		setEventNumber(int n)					{nEventNumber = n;}
	int			getEventNumber()						{return nEventNumber;}

	void		setName(char *value)					{mName.setValue(value);}
	char		*getName()								{return mName.getValue();}

	void		setListBoxString(int n, char *string)	{mListBoxString[n].setValue(string);}
	char		*getListBoxString(int n)				{return mListBoxString[n].getValue();}

// ダイアログ データ
	//{{AFX_DATA(DiagramNew)
	enum { IDD = IDD_DIAGRAM_NEW };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(DiagramNew)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DiagramNew)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
