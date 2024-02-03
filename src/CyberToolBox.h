// CyberToolBox.h : CYBERTOOLBOX アプリケーションのメイン ヘッダー ファイル
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // メイン シンボル

class CCyberToolBoxView;
class ModuleFloating;
class PerspectiveView;
class OrthoView;
class Node;

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp:
// このクラスの動作の定義に関しては CyberToolBox.cpp ファイルを参照してください。
//

class CCyberToolBoxApp : public CWinApp
{
public:
	CCyberToolBoxApp();
	~CCyberToolBoxApp();

	CSingleDocTemplate	*mpOrthoDocTemplate;
	CDocument			*mpOrthoDocument;
	CSingleDocTemplate	*mpPerspectiveDocTemplate;
	CDocument			*mpPerspectiveDocument;
	CMultiDocTemplate	*mDgmDocTemplate;

	CCyberToolBoxView	*mTreeView;
	CCyberToolBoxView	*getTreeView()			{return mTreeView;}

	void				resetSceneGraphTree();

	ModuleFloating		*mModuleFloating;
	void				setModuleFloating(ModuleFloating *mod)	{mModuleFloating = mod;}
	ModuleFloating		*getModuleFloating()					{return mModuleFloating;}

	PerspectiveView		*getPerspectiveView();
	OrthoView			*getOrthoView();

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(CCyberToolBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CCyberToolBoxApp)
	afx_msg void OnAppAbout();
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////
//	Global Functions
////////////////////////////////////////

void				CtbModuleFloatingSetTopMost();
void				CtbModuleFloatingReleaseTopMost();
ModuleFloating		*CtbGetModuleFloating();
void				CtbModuleFloatingShowWindow(int nCmdShow);
void				CtbPrimitiveFloatingShowWindow(int nCmdShow);

void				CtbTreeAddNode(Node *node, Node *parentNode);

void				CtbTreeDeleteNode(Node *node);

CCyberToolBoxApp	*CtbGetApp();
CCyberToolBoxView	*CtbGetTreeView();
PerspectiveView		*CtbGetPerspectiveView();
OrthoView			*CtbGetOrthoView();

void				CtbUpdatePerspectiveView();
void				CtbUpdateOrthoView();
