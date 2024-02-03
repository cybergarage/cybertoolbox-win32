#if !defined(AFX_DIALOGOBJECTAPPEARANCE_H__1A7C5844_0FBF_11D2_A89D_00605204B77B__INCLUDED_)
#define AFX_DIALOGOBJECTAPPEARANCE_H__1A7C5844_0FBF_11D2_A89D_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogObjectAppearance.h : ヘッダー ファイル
//

#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneGraph.h"

/////////////////////////////////////////////////////////////////////////////
// DialogObjectAppearance ダイアログ

class DialogObjectAppearance : public CDialog
{
// コンストラクション
public:
	DialogObjectAppearance(CWnd* pParent = NULL);   // 標準のコンストラクタ

	BOOL Create();

	~DialogObjectAppearance();

// ダイアログ データ
	//{{AFX_DATA(DialogObjectAppearance)
	enum { IDD = IDD_OBJECT_APPEARANCE };
		// メモ: ClassWizard はこの位置にデータ メンバを追加します。
	//}}AFX_DATA


	AppearanceNode	*mAppearanceNode;
	void			setAppearanceNode(AppearanceNode *node)	{ mAppearanceNode = node; }
	AppearanceNode	*getAppearanceNode()					{ return mAppearanceNode; }

	//////////////////////////////////
	// Material
	//////////////////////////////////

	MaterialNode	*getMaterialNode();
	MaterialNode	*createMaterialNode();
	MaterialNode		mOriginalMaterial;
	MaterialNode		*getOriginalMaterial()				{ return &mOriginalMaterial; }
		
	void			copyMaterialData(MaterialNode *srcMaterial, MaterialNode *dstMaterial);

	//////////////////////////////////
	// ImageTexture
	//////////////////////////////////

	ImageTextureNode	*getImageTextureNode();
	ImageTextureNode	*createImageTextureNode();
	
	char			mImageTextureFilename[1024];
	void			setOriginalImageTextureFilename(char *filename);
	char			*getOriginalImageTextureFilename()				{ return mImageTextureFilename; }

	RGBColor24		*mImageTextureColor;
	void			setImageTextureColor(RGBColor24 *color)			{ mImageTextureColor= color; }
	RGBColor24		*getImageTextureColor()							{ return mImageTextureColor; }
	RGBColor24		*createImageTextureColor(ImageTextureNode *imgTex, int width, int height);

	void			drawImageTexture();
	void			drawImageTexture(CDC *dc, int width, int height);
	void			displayTextureInfo(FileImage *fileImage);

	//////////////////////////////////
	// Scroll bar
	//////////////////////////////////

	void			setScrollBarText(int id);
	int				getScrollBarID(CScrollBar *sb);
	void			initializeScrollBar(int id, float value);
	float			getScrollBarValue(int id);
	
	void			updateMaterialNode();

	void			UpdatePerspectiveView();

	//////////////////////////////////
	// OpenGL
	//////////////////////////////////
	
    CPalette		oglPalette;
    CPalette		*oglOldPalette;
	CClientDC		*oglDC;
	HDC				oglHdc;
	HGLRC			oglHrc;

	void			OGLSetup(CWnd *wnd);
	BOOL			OGLSetupPixelFormat();
	void			OGLCreateRGBPalette();
	unsigned char	OGLComponentFromIndex(int i, UINT nbits, UINT shift);

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。

	//{{AFX_VIRTUAL(DialogObjectAppearance)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(DialogObjectAppearance)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnApply();
	afx_msg void OnTextureSelect();
	afx_msg void OnTextureDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_DIALOGOBJECTAPPEARANCE_H__1A7C5844_0FBF_11D2_A89D_00605204B77B__INCLUDED_)
