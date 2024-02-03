#if !defined(AFX_DIALOGOBJECTAPPEARANCE_H__1A7C5844_0FBF_11D2_A89D_00605204B77B__INCLUDED_)
#define AFX_DIALOGOBJECTAPPEARANCE_H__1A7C5844_0FBF_11D2_A89D_00605204B77B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// DialogObjectAppearance.h : �w�b�_�[ �t�@�C��
//

#include <GL/gl.h>
#include <GL/glu.h>

#include "SceneGraph.h"

/////////////////////////////////////////////////////////////////////////////
// DialogObjectAppearance �_�C�A���O

class DialogObjectAppearance : public CDialog
{
// �R���X�g���N�V����
public:
	DialogObjectAppearance(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

	BOOL Create();

	~DialogObjectAppearance();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(DialogObjectAppearance)
	enum { IDD = IDD_OBJECT_APPEARANCE };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
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

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(DialogObjectAppearance)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DIALOGOBJECTAPPEARANCE_H__1A7C5844_0FBF_11D2_A89D_00605204B77B__INCLUDED_)
