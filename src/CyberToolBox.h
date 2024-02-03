// CyberToolBox.h : CYBERTOOLBOX �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ���C�� �V���{��

class CCyberToolBoxView;
class ModuleFloating;
class PerspectiveView;
class OrthoView;
class Node;

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� CyberToolBox.cpp �t�@�C�����Q�Ƃ��Ă��������B
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

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CCyberToolBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CCyberToolBoxApp)
	afx_msg void OnAppAbout();
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
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
