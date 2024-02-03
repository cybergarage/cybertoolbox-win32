/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CFontInfo.cpp
*
******************************************************************/
#include "CFontInfo.h"
#include "RegKey.h"

//////////////////////////////////////////////////
// CFontInfo::getTypeString
//////////////////////////////////////////////////

char *CFontInfo::getTypeString()
{
	switch (getType()) {
	case FONT_TYPE_SCENEGRAPH:
		return REGKEY_KEY_SCENEGRAPH_FONT;
	case FONT_TYPE_DIAGRAM:
		return REGKEY_KEY_DIAGRAM_FONT;
	case FONT_TYPE_ORTHOVIEW:
		return REGKEY_KEY_ORTHOVIEW_FONT;
	}
	
	return NULL;
}

//////////////////////////////////////////////////
// CFontInfo::getFontInfo
//////////////////////////////////////////////////

void CFontInfo::getInfo(FontInfo *fontInfo)
{
	char	fontsetting[128];
	if (RegKeyGetValue(REGKEY_SECTION_FONT, getTypeString(), fontsetting)) {
		if (!fontsetting && !strlen(fontsetting))
			return;
		// Profile format is "FontName,FontSize,Bold,Italic,UnderLine"->
		sscanf(fontsetting, "%s %d %d %d %d", fontInfo->name, &fontInfo->size, &fontInfo->bold, &fontInfo->italic, &fontInfo->underLine);
	}
	else {
		strcpy(fontInfo->name, "Arial");
		//fontInfo->size = -13; // 10 dot
		fontInfo->size = -MulDiv(10, 96, 72);
		fontInfo->bold = TRUE;
		fontInfo->italic = FALSE;
		fontInfo->underLine = FALSE;
	}
}

//////////////////////////////////////////////////
// CFontInfo::setFontInfo
//////////////////////////////////////////////////

void CFontInfo::setInfo(FontInfo *fontInfo)
{
	char	fontsetting[128];
	sprintf(fontsetting, "%s %d %d %d %d", fontInfo->name, fontInfo->size, fontInfo->bold, fontInfo->italic, fontInfo->underLine);

	RegKeyWriteValue(REGKEY_SECTION_FONT, getTypeString(), fontsetting);
}

//////////////////////////////////////////////////
// CFontInfo::getFontInfo
//////////////////////////////////////////////////

void CFontInfo::getInfo(LOGFONT *lf)
{
	FontInfo	fontInfo;

	getInfo(&fontInfo);

	lf->lfHeight = fontInfo.size;
	lf->lfWidth = 0;
	lf->lfEscapement = 0;
	lf->lfOrientation = 0;
	lf->lfWeight = fontInfo.bold ? 700 : 400;
	lf->lfItalic = fontInfo.italic ? TRUE : FALSE;
	lf->lfUnderline = fontInfo.underLine ? TRUE : FALSE;
	lf->lfStrikeOut = 0;
	lf->lfCharSet = 0;
	lf->lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf->lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf->lfQuality = DEFAULT_QUALITY;
	lf->lfPitchAndFamily = DEFAULT_PITCH;
	strcpy(lf->lfFaceName, fontInfo.name);
}

//////////////////////////////////////////////////
// CFontInfo::setFontInfo
//////////////////////////////////////////////////

void CFontInfo::setInfo(LOGFONT *lf)
{
	FontInfo	fontInfo;

	fontInfo.size = lf->lfHeight;
	fontInfo.bold = (lf->lfWeight == 700) ? TRUE : FALSE;
	fontInfo.italic = lf->lfItalic ? TRUE : FALSE;
	fontInfo.underLine = lf->lfUnderline ? TRUE : FALSE;
	strcpy(fontInfo.name, lf->lfFaceName);

	setInfo(&fontInfo);
}
