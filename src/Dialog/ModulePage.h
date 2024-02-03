/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	ModulePage.h
*
******************************************************************/

#ifndef _MODULE_PAGE_
#define _MODULE_PAGE_

#include <afxwin.h>
#include <afxcmn.h>
#include <afxdlgs.h>
#include "CModuleType.h"
#include "String.h"

enum {
MOUSE_BUTTON_NONE,
MOUSE_BUTTON_LEFT,
MOUSE_BUTTON_RIGHT,
};

class ModulePage {

public:
	CPropertyPage	*mPage;
    CImageList		mImageList;
	CFont			mFont;
	char			mClassName[32];
	int				mItem;

// コンストラクション
public:

	ModulePage();
	~ModulePage();

	////////////////////////////////////////
	//	Page
	////////////////////////////////////////

	void			setPage(CPropertyPage *page)	{mPage = page;}
	CPropertyPage	*getPage()						{return mPage;}

	////////////////////////////////////////
	//	Drag
	////////////////////////////////////////

	void	setDragItem(int item)	{ mItem = item; }
	int		getDragItem()			{ return mItem; }

	////////////////////////////////////////
	//	Font
	////////////////////////////////////////

	void setFont();

	////////////////////////////////////////
	//	ToolTip
	////////////////////////////////////////

	HWND		mhToolTip;
	TOOLINFO	mToolInfo;
	String		*mToolTipString;	
	int			nToolTipString;

	HWND		createToolTip();
	void		updateToolTip();

	////////////////////////////////////////
	//	ImageList
	////////////////////////////////////////

	int		mnImages;

	void	createImageList();
	void	drawImageList();
	void	setNImages(int n)	{mnImages = n;}
	int		getNImages()		{return mnImages;}

	int		getScrollBarPos();
	int		getNScrollbarElements();
	void	initializeScrollBar();
	void	setScrollBar(UINT nSBCode, UINT nPos);

	int		isInsideImageList(int screenx, int screeny);

	////////////////////////////////////////
	//	Module
	////////////////////////////////////////

	void addModuleType();
	void configModuleType(CModuleType *cmType);
	void deleteModuleType(CModuleType *cmType);

	////////////////////////////////////////
	//	Mouse
	////////////////////////////////////////

	int		mMouseButton;
	int		mousex, mousey;

	void	setMouseButton(int button)	{ mMouseButton = button; }
	int		getMouseButton()			{ return mMouseButton; }

	////////////////////////////////////////
	//	Drag
	////////////////////////////////////////

	bool	mDragging;
	void	setDragging(bool drag)	{mDragging = drag;}
	bool	isDragging()			{return mDragging;}
	void	DragBegin(int item);
	void	DragEnd(int screenx, int screeny);

	////////////////////////////////////////
	//	Class name
	////////////////////////////////////////

	char *getClassName() {
		getPage()->GetWindowText(mClassName, 32);
		return mClassName;
	}
};

#endif
