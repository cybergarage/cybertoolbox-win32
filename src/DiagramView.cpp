// DiagramView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "DiagramView.h"
#include "World.h"
#include "StringFn.h"
#include "CUndoActionFn.h"
#include "CGlobalData.h"

#include "DialogWorldConstant.h"
#include "DialogObjectName.h"
#include "DialogViewName.h"
#include "DialogLightName.h"
#include "DialogMaterialName.h"
#include "DialogGlobalDataName.h"
#include "DialogDiagramConfig.h"
#include "DialogFilterHigh.h"
#include "DialogFilterLow.h"
#include "DialogFilterRange.h"
#include "DialogFilterScale.h"
#include "DialogObjectCollision.h"
#include "DialogModuleStringVector.h"
#include "DialogModuleStringOrientation.h"
#include "DialogModuleStringPosition.h"
#include "DialogModuleStringBool.h"
#include "DialogModuleFilterScalarInterp.h"
#include "DialogModuleFilterPosition2DInterp.h"
#include "DialogModuleFilterPosition3DInterp.h"
#include "DialogModuleFilterOrientationInterp.h"
#include "DialogModuleMiscPlaySound.h"
#include "DialogModuleInterpColor.h"
#include "DialogModuleInterpPosition.h"
#include "DialogModuleInterpScalar.h"
#include "DialogModuleInterpOrientation.h"
#include "DialogModuleInterpNormal.h"
#include "DialogTextName.h"
#include "DialgoBackgroundName.h"
#include "DialogImageTextureName.h"
#include "DialogSwitchName.h"
#include "DialogAudioClipName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDiagramClipboard CDiagramView::mClipboard;

/////////////////////////////////////////////////////////////////////////////
// CDiagramView

IMPLEMENT_DYNCREATE(CDiagramView, CScrollView)

CDiagramView::CDiagramView()
{
	GetWorld()->addDiagramWindow((CWnd *)this);
	
	mDiagramNode = NULL;
	mbDragRect = FALSE;

	mFontInfo = new CFontInfo(FONT_TYPE_DIAGRAM);

	setModuleOperationMode(DIAGRAM_MODE_NONE);
	setSelectingModule(NULL);
	setDragOff();
	setGridSnap(true);
	setGridDisplay(true);
	setLineStyle(DIAGRAM_LINESTYLE_ZIGZAG);
	setSelectingBoxRect(0, 0, 0, 0);
	selectingBoxOff();
}

CDiagramView::~CDiagramView()
{
	GetWorld()->deleteDiagramWindow((CWnd *)this);
	delete	mFontInfo;
}


BEGIN_MESSAGE_MAP(CDiagramView, CScrollView)
	//{{AFX_MSG_MAP(CDiagramView)
	ON_COMMAND(ID_FONT_SETTING, OnFontSetting)
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_COMMAND(ID_UNDO, OnUndo)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_COMMAND(ID_DIAGRAM_CONFIG, OnDiagramConfig)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramView 描画

void CDiagramView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: このビュー全体のサイズを計算してください。
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CDiagramView::drawGrid(CDC* pDC, int width, int height)
{
	SFRotation	rot(1, 1, 1, 0);
	SFMatrix	mat;

	rot.getSFMatrix(&mat);

	CPen *oldPen;
	int x, y;

	CPen pen(PS_SOLID, 1, RGB(0xc0, 0xc0, 0xff));
	oldPen= pDC->SelectObject(&pen);
	for (x=0; x<width; x+=32/4) {
		pDC->MoveTo(x, 0);
		pDC->LineTo(x, height);
	}
	for (y=0; y<height; y+=32/4) {
		pDC->MoveTo(0, y);
		pDC->LineTo(width, y);
	}
	pDC->SelectObject(oldPen);

	CPen boldPen(PS_SOLID, 1, RGB(0xa0, 0xa0, 0xff));
	oldPen= pDC->SelectObject(&boldPen);
	for (x=0; x<width; x+=32) {
		pDC->MoveTo(x, 0);
		pDC->LineTo(x, height);
	}
	for (y=0; y<height; y+=32) {
		pDC->MoveTo(0, y);
		pDC->LineTo(width, y);
	}
	pDC->SelectObject(oldPen);
}

void CDiagramView::stripText(char *string, char *stripString)
{
	static char seps[] = ",";
	static char defaultString[512];
	static char doubleValueString[256];
	static char doubleValueString2[256];
	char	*token;

	strcpy(stripString, "");
	
	if (string == NULL)
		return; 

	strcpy(defaultString, string);

	token = strtok(defaultString, seps);
	while (token != NULL) {
		float doubleValue;
		if (sscanf(token, "%f", &doubleValue) == 1) {
			sprintf(doubleValueString, "%.2f", doubleValue);
			sprintf(doubleValueString2, "%g", atof(doubleValueString));
			strcat(stripString, doubleValueString2);
		}
		else
			strcat(stripString, token);

		token = strtok(NULL, seps);
		if (token != NULL)
			strcat(stripString, ",");
	}
}

void CDiagramView::drawText(CDC* pDC, int x, int y, char *string, COLORREF color)
{
	pDC->SetTextColor(0xffffff);
	pDC->TextOut(x+1, y+1, string, StringLength(string));
	pDC->SetTextColor(color);
	pDC->TextOut(x, y, string, StringLength(string));
}

void CDiagramView::drawLine(CDC* pDC, int sx, int sy, int ex, int ey, bool isXBold, bool isYBold)
{
	pDC->MoveTo(sx, sy);
	pDC->LineTo(ex, ey);
	
	if (isXBold == true) {
		pDC->MoveTo(sx+1, sy);
		pDC->LineTo(ex+1, ey);
	}

	if (isYBold == true) {
		pDC->MoveTo(sx, sy+1);
		pDC->LineTo(ex, ey+1);
	}
}

void CDiagramView::drawStraightLine(CDC* pDC, int sx, int sy, int ex, int ey)
{
	drawLine(pDC, sx, sy, ex, ey, false, true);
}

#define NODE_LINE_MARGIN (MODULE_SIZE/2)

void CDiagramView::drawZigzagLine(CDC* pDC, int outModuleX, int outModuleY, int outNodeX, int outNodeY, int inModuleX, int inModuleY, int inNodeX, int inNodeY, bool isExecutionNode)
{
	if (inNodeX < outNodeX) {
		drawLine(pDC, outNodeX, outNodeY, outNodeX+NODE_LINE_MARGIN, outNodeY, false, true);
		if (inNodeY < outNodeY) {
			drawLine(pDC, outNodeX+NODE_LINE_MARGIN, outNodeY, outNodeX+NODE_LINE_MARGIN, outModuleY-NODE_LINE_MARGIN, true, false);
			outNodeX = outNodeX+NODE_LINE_MARGIN;
			outNodeY = outModuleY-NODE_LINE_MARGIN;
		}
		else {
			drawLine(pDC, outNodeX+NODE_LINE_MARGIN, outNodeY, outNodeX+NODE_LINE_MARGIN, outModuleY+MODULE_SIZE+NODE_LINE_MARGIN, true, false);
			outNodeX = outNodeX+NODE_LINE_MARGIN;
			outNodeY = outModuleY+MODULE_SIZE+NODE_LINE_MARGIN;
		}
	}

	if (isExecutionNode == false) {
		int midx = (outNodeX + inNodeX)/2;
		drawLine(pDC, outNodeX, outNodeY, midx, outNodeY, false, true);
		if (inNodeX < outNodeX) {
			if (inNodeY < outNodeY) {
				drawLine(pDC, midx, outNodeY, midx, inModuleY + MODULE_SIZE + NODE_LINE_MARGIN, true, false);
				drawLine(pDC, midx, inModuleY + MODULE_SIZE + NODE_LINE_MARGIN, inModuleX - NODE_LINE_MARGIN, inModuleY + MODULE_SIZE + NODE_LINE_MARGIN, false, true);
				drawLine(pDC, inModuleX - NODE_LINE_MARGIN, inModuleY + MODULE_SIZE + NODE_LINE_MARGIN, inModuleX - NODE_LINE_MARGIN, inNodeY, true, false);
				drawLine(pDC, inModuleX - NODE_LINE_MARGIN, inNodeY, inNodeX, inNodeY, false, true);
			}
			else {
				drawLine(pDC, midx, outNodeY, midx, inModuleY - NODE_LINE_MARGIN, true, false);
				drawLine(pDC, midx, inModuleY - NODE_LINE_MARGIN, inModuleX - NODE_LINE_MARGIN, inModuleY - NODE_LINE_MARGIN, false, true);
				drawLine(pDC, inModuleX - NODE_LINE_MARGIN, inModuleY - NODE_LINE_MARGIN, inModuleX - NODE_LINE_MARGIN, inNodeY, true, false);
				drawLine(pDC, inModuleX - NODE_LINE_MARGIN, inNodeY, inNodeX, inNodeY, false, true);
			}
		}
		else {
			drawLine(pDC, midx, outNodeY, midx, inNodeY, true, false);
			drawLine(pDC, midx, inNodeY, inNodeX, inNodeY, false, true);
		}
	}
	else {
		if (inNodeY < outNodeY) {
			int midx = (outNodeX + inNodeX)/2;
			drawLine(pDC, outNodeX, outNodeY, midx, outNodeY, false, true);
			drawLine(pDC, midx, outNodeY, midx, inNodeY - NODE_LINE_MARGIN, true, false);
			drawLine(pDC, midx, inNodeY - NODE_LINE_MARGIN, inNodeX, inNodeY - NODE_LINE_MARGIN, false, true);
			drawLine(pDC, inNodeX, inNodeY - NODE_LINE_MARGIN, inNodeX, inNodeY, true, false);
		}
		else {
			drawLine(pDC, outNodeX, outNodeY, inNodeX, outNodeY, false, true);
			drawLine(pDC, inNodeX, outNodeY, inNodeX, inNodeY, true, false);
		}
	}
}

void CDiagramView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
	static char stripString[512];

	CDC *pMemDC;
	CBitmap hBitmap;

	CRect winRect;
	GetWindowRect(&winRect);
	int width = winRect.Width();
	int height = winRect.Height();
	CSize size = GetTotalSize();
	width	+= size.cx;
	height	+= size.cy;

	pMemDC = new CDC;
    pMemDC->CreateCompatibleDC(pDC);
	hBitmap.CreateCompatibleBitmap(pDC, width, height);
	pMemDC->SelectObject(&hBitmap);

	CBrush WhiteBrush(RGB(0xff,0xff,0xff));
	CBrush* pOldBrush = pMemDC->SelectObject(&WhiteBrush);

	CRect	rect(0, 0, width, height);
	pMemDC->FillRect(&rect, &WhiteBrush);

	pMemDC->SelectObject(&mFont);
	
	CDiagram dgm(getDiagramNode());

	int extents[2][2];
	dgm.getExtents(extents);
	static int maxExtents[2] = {0, 0};
	if (maxExtents[X] < extents[EXTENTS_MAX][X])
		maxExtents[X] = extents[EXTENTS_MAX][X];
	if (maxExtents[Y] < extents[EXTENTS_MAX][Y])
		maxExtents[Y] = extents[EXTENTS_MAX][Y];
	
	SIZE sizePage;
	sizePage.cy = (maxExtents[X] + 32) / 2;
	sizePage.cx = (maxExtents[Y] + 32) / 2;
	SetScrollSizes(MM_TEXT, CSize(maxExtents[X] + 32, maxExtents[Y] + 32), sizePage);

	size.cx = 1;
	size.cy = 1;

	LOGFONT lf;
	getFontInfo(&lf);
	setFont(&lf);

	if (getGridDisplay() == true) { 
		CPoint offset = GetScrollPosition ();
		drawGrid(pMemDC, width + offset.x, height + offset.y);
	}

	CPen *oldPen;
	CPen linePen(PS_SOLID, 1, RGB(0x40, 0x40, 0x40));
	oldPen= pMemDC->SelectObject(&linePen);
	for (Route *route = GetWorld()->getSceneGraph()->getRoutes(); route; route = route->next()) {
		if (dgm.hasRoute(route) == true) {
			CModule	moduleIn((ScriptNode *)route->getEventInNode());
			CModule	moduleOut((ScriptNode *)route->getEventOutNode());
			
			int	sx, sy, ex, ey;
			moduleOut.getRouteOutNodePosition(route->getEventOutField(), &sx, &sy);
			moduleIn.getRouteInNodePosition(route->getEventInField(), &ex, &ey);

			bool isExecutionNode = (route->getEventInField() == moduleIn.getExecutionField()) ? true : false;

			if (getLineStyle() == DIAGRAM_LINESTYLE_STRAIGHT)
				drawStraightLine(pMemDC, sx, sy, ex, ey);
			else {
				int ox, oy, ix, iy;
				moduleIn.getPosition(&ix, &iy);
				moduleOut.getPosition(&ox, &oy);
				drawZigzagLine(pMemDC, ox, oy, sx, sy, ix, iy, ex, ey, isExecutionNode);
			}
		}
	}
	pMemDC->SelectObject(oldPen);

	int nModule = dgm.getNModules();
	for (int n=0; n<nModule; n++) {
		ScriptNode	*script = dgm.getModule(n);
		CModule		module(script);
		CModuleType	*cmType = module.getModuleType();
		HICON		cmIcon = cmType->getIcon()->GetHandle();

		int			mx, my;
		int			n;
		int			nodeSize = module.getNodeSize();
		int			nodex, nodey;
		CRect		nodeRect;

		module.getPosition(&mx, &my);
		pMemDC->DrawIcon(mx, my, cmIcon);

		for (n=0; n<module.getNEventInNodes(); n++) {
			module.getEventInNodePosition(n, &nodex, &nodey);
			nodeRect.SetRect(nodex, nodey, nodex  + nodeSize, nodey + nodeSize);
			pMemDC->FillSolidRect(&nodeRect, RGB(0, 0, 0));
		}

		pMemDC->SetBkColor(RGB(255, 255, 255));
		pMemDC->SetBkMode(TRANSPARENT);
		COLORREF textColor = RGB(0, 0, 0);
		for (n=0; n<module.getNEventOutNodes(); n++) {
			module.getEventOutNodePosition(n, &nodex, &nodey);
			nodeRect.SetRect(nodex, nodey, nodex + nodeSize, nodey + nodeSize);
			pMemDC->FillSolidRect(&nodeRect, RGB(0, 0, 0));
			char *string = ((SFString *)module.getEventOutField(n))->getValue();
			stripText(string, stripString);
			CSize textSize = pMemDC->GetTextExtent(stripString, StringLength(stripString));
			drawText(pMemDC, nodex + nodeSize, nodey - nodeSize - textSize.cy/2, stripString, textColor);
		}

		CModuleType	*moduleType = module.getModuleType();

		if (!StringCompareIgnoreCase(moduleType->getClassName(), "OBJECT") || !StringCompareIgnoreCase(moduleType->getClassName(), "VIEW")		||
			!StringCompareIgnoreCase(moduleType->getClassName(), "LIGHT") || !StringCompareIgnoreCase(moduleType->getClassName(), "MATERIAL") ) {
			Node *node = NULL;
			if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3))
				node = module.getTargetNode();
			else if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
				node = module.getSourceNode();
			if (node) {
				char *nodeName = node->getName();
				CSize textSize = pMemDC->GetTextExtent(nodeName, StringLength(nodeName));
				drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, nodeName, textColor);
			}
		}
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "INTERP")) {
			Node *node = module.getTargetNode();
			if (node) {
				char *nodeName = node->getName();
				CSize textSize = pMemDC->GetTextExtent(nodeName, StringLength(nodeName));
				drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, nodeName, textColor);
			}
		}
		else if (!StringCompareIgnoreCase(moduleType->getClassName(), "STRING")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "Value")	||
				!StringCompareIgnoreCase(moduleType->getName(), "Direction")||
				!StringCompareIgnoreCase(moduleType->getName(), "Position")	||
				!StringCompareIgnoreCase(moduleType->getName(), "Rotation")	||
				!StringCompareIgnoreCase(moduleType->getName(), "Bool")	||
				!StringCompareIgnoreCase(moduleType->getName(), "Color")	) {
				char *value = module.getValue();
				stripText(value, stripString);
				CSize textSize = pMemDC->GetTextExtent(value, StringLength(stripString));
				drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, stripString, textColor);
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "SETVALUE") || !StringCompareIgnoreCase(moduleType->getName(), "GETVALUE") ||
					 !StringCompareIgnoreCase(moduleType->getName(), "SETARRAYVALUE") || !StringCompareIgnoreCase(moduleType->getName(), "GETARRAYVALUE") ) { 
				AnchorNode *node = NULL;
				if (!StringCompareIgnoreCase(moduleType->getName(), "SETVALUE") ||
					!StringCompareIgnoreCase(moduleType->getName(), "SETARRAYVALUE"))
					node = (AnchorNode *)module.getTargetNode();
				else if (!StringCompareIgnoreCase(moduleType->getName(), "GETVALUE") ||  
						 !StringCompareIgnoreCase(moduleType->getName(), "GETARRAYVALUE")) 
					node = (AnchorNode *)module.getSourceNode();
				if (node) {
					CGlobalData	gData(node);
					char *nodeName = gData.getName();
					CSize textSize = pMemDC->GetTextExtent(nodeName, StringLength(nodeName));
					drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, nodeName, textColor);
				}
			}
		}
		else if (!StringCompareIgnoreCase(moduleType->getClassName(), "MISC")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "PlaySound")) {
				Node *node = module.getTargetNode();
				if (node) {
					char *nodeName = node->getName();
					CSize textSize = pMemDC->GetTextExtent(nodeName, StringLength(nodeName));
					drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, nodeName, textColor);
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "SetText") ||
				!StringCompareIgnoreCase(moduleType->getName(), "SetSkyColor") ||
				!StringCompareIgnoreCase(moduleType->getName(), "SetImageTexture") ||
				!StringCompareIgnoreCase(moduleType->getName(), "SetSwitch") || 
				!StringCompareIgnoreCase(moduleType->getName(), "SetAudioClip") ) {
				Node *node = module.getTargetNode();
				if (node) {
					char *nodeName = node->getName();
					CSize textSize = pMemDC->GetTextExtent(nodeName, StringLength(nodeName));
					drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, nodeName, textColor);
				}
			}
		}
		else if (!StringCompareIgnoreCase(moduleType->getClassName(), "FILTER")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "High")		|| 
				!StringCompareIgnoreCase(moduleType->getName(), "Low")		||
				!StringCompareIgnoreCase(moduleType->getName(), "Range")	||
				!StringCompareIgnoreCase(moduleType->getName(), "Scale")	||
				!StringCompareIgnoreCase(moduleType->getName(), "ScalarInterpolator")		||
				!StringCompareIgnoreCase(moduleType->getName(), "Position2DInterpolator")	||
				!StringCompareIgnoreCase(moduleType->getName(), "Position3DInterpolator")	||
				!StringCompareIgnoreCase(moduleType->getName(), "OrientationInterpolator")) {
				char *value = module.getValue();
				CSize textSize = pMemDC->GetTextExtent(value, StringLength(value));
				drawText(pMemDC, mx + 32/2 - (textSize.cx/2), my + 32, value, textColor);
			}
		}

		if (module.hasExecutionNode()) {
			int x, y;
			module.getExecutionNodePosition(&x, &y);
			nodeRect.SetRect(x, y, x + nodeSize, y + nodeSize);
			pMemDC->FillSolidRect(&nodeRect, RGB(0, 0, 0));
		}

		if (getSelectingModule() == script) {
			if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE) {
				CRect	dragRect;
				dragRect.SetRect(mx, my, mx + 32, my + 32);
				pMemDC->DrawEdge(&dragRect, EDGE_BUMP , BF_RECT);
			}
			else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE) {
				module.getEventOutNodePosition(getSelectingEventOutNode(), &nodex, &nodey);
				nodeRect.SetRect(nodex-1, nodey-1, nodex + nodeSize + 1, nodey + nodeSize + 1);
				pMemDC->FillSolidRect(&nodeRect, RGB(0, 0, 0));
			}
			else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_INNODE) {
				module.getEventInNodePosition(getSelectingEventInNode(), &nodex, &nodey);
				nodeRect.SetRect(nodex-1, nodey-1, nodex + nodeSize + 1, nodey + nodeSize + 1);
				pMemDC->FillSolidRect(&nodeRect, RGB(0, 0, 0));
			}
			else if (getModuleOperationMode() & MODULE_INSIDE_EXECUTIONNODE) {
				module.getExecutionNodePosition(&nodex, &nodey);
				nodeRect.SetRect(nodex-1, nodey-1, nodex + nodeSize + 1, nodey + nodeSize + 1);
				pMemDC->FillSolidRect(&nodeRect, RGB(0, 0, 0));
			}
		}
	}

	// draw selecting box
	if (isSelectingBoxOn() == true) {
		int xmin, ymin, xmax, ymax;
		getSelectingBoxRect(&xmin, &ymin, &xmax, &ymax);
		CPen pen(PS_DOT, 1, RGB(50, 50, 255));   
		CPen *oldPen = pMemDC->SelectObject(&pen);
		pMemDC->MoveTo(xmin, ymin);
		pMemDC->LineTo(xmin, ymax);
		pMemDC->LineTo(xmax, ymax);
		pMemDC->LineTo(xmax, ymin);
		pMemDC->LineTo(xmin, ymin);
		pMemDC->SelectObject(oldPen);
	}

	pDC->BitBlt(0,0,width,height,pMemDC,0,0,SRCCOPY);
	delete pMemDC;
}

/////////////////////////////////////////////////////////////////////////////
// CDiagramView 診断

#ifdef _DEBUG
void CDiagramView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDiagramView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDiagramView メッセージ ハンドラ


///////////////////////////////////////////////////////////////////////////////
// Position
///////////////////////////////////////////////////////////////////////////////
	
void CDiagramView::updatePosition()
{
	CDiagram diagram(getDiagramNode());

	int x = diagram.getXPosition();
	int y = diagram.getYPosition();
	int width = diagram.getWidth();
	int height = diagram.getHeight();

	if (0 < width && 0 < height)
		GetParentFrame()->MoveWindow(x, y, width, height);

	GetParentFrame()->ShowWindow(SW_SHOW);
}

void CDiagramView::savePosition()
{
	CDiagram diagram(getDiagramNode());

	RECT rect;
	GetWindowRect(&rect);

	int x = rect.left;
	int y = rect.top;
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	diagram.setPosition(x, y);
	diagram.setWidth(width);
	diagram.setHeight(height);
}

void CDiagramView::updateScreenSize()
{
	return;

	CDiagram dgm(getDiagramNode());
	dgm.updateExtents();
	
	int extents[2][2];
	dgm.getExtents(extents);

	int xsize = extents[EXTENTS_MAX][X] - extents[EXTENTS_MIN][X];
	int ysize = extents[EXTENTS_MAX][Y] - extents[EXTENTS_MIN][Y];

	CRect	rect;
	GetWindowRect(&rect);
	if (xsize < rect.Width())
		xsize = rect.Width();
	if (ysize < rect.Height())
		ysize = rect.Height();

	CSize	sizeTotal(xsize, ysize);
	CSize	sizePage(xsize/2, ysize/2);
	CSize	sizeLine(xsize/10, ysize/10);
	
	SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
}

////////////////////////////////////////
//	Name
////////////////////////////////////////

char *CDiagramView::getWindowText()
{
	static char winText[1024];

	CDiagram	dgm(getDiagramNode());
	CEvent		event(dgm.getEventNode());

	strcpy(winText, event.getEventTypeName());
	if (event.getEventOptionName()) {
		strcat(winText, " - ");
		strcat(winText, event.getEventOptionName());
	}

	strcat(winText, " : ");
	strcat(winText, dgm.getName());
	
	return winText;
}

void CDiagramView::updateWindowText()
{
	GetParentFrame()->SetWindowText(getWindowText());
}


////////////////////////////////////////
//	SelectingBox
////////////////////////////////////////

void CDiagramView::deleteModulesInSelectingBox() 
{
	RouteList	routeList;
	NodeList	nodeList;

	int selBoxRect[4];
	getSelectingBoxRect(selBoxRect);

	CDiagram dgm(getDiagramNode());

	Route *route = GetWorld()->getSceneGraph()->getRoutes();
	while (route != NULL) {
		Route *nextRoute = route->next();
		if (dgm.hasRoute(route) == true) {
			CModule	moduleIn((ScriptNode *)route->getEventInNode());
			CModule	moduleOut((ScriptNode *)route->getEventOutNode());
			
			int	sx, sy, ex, ey;
			moduleOut.getRouteOutNodePosition(route->getEventOutField(), &sx, &sy);
			moduleIn.getRouteInNodePosition(route->getEventInField(), &ex, &ey);
			
			int nodeSize = moduleOut.getNodeSize();

			if (isRect(selBoxRect, sx, sy) == false || isRect(selBoxRect, sx+nodeSize, sy+nodeSize) == false) 
				continue;

			if (isRect(selBoxRect, ex, ey) == false || isRect(selBoxRect, ex+nodeSize, ey+nodeSize) == false) 
				continue;
			
			GetWorld()->getSceneGraph()->removeRoute(route);
		}
		route = nextRoute;
	}

	ScriptNode	*moduleNode = dgm.getModules();
	while (moduleNode != NULL) {
		ScriptNode	*nextModuleNode = moduleNode->next();
		if (dgm.hasModule(moduleNode) == true) {
			CModule		module(moduleNode);
			int mx = module.getPositionX();
			int my = module.getPositionY();
			int msize = module.getSize();
			if (isRect(selBoxRect, mx, my) == true && isRect(selBoxRect, mx+msize, my+msize) == true) 
				dgm.removeModule(&module);
		}
		moduleNode = nextModuleNode;
	}
}

void CDiagramView::copyModulesInSelectingBox(CDiagramClipboard *clipboard) 
{

	clipboard->clear();

	int selBoxRect[4];
	getSelectingBoxRect(selBoxRect);

	CDiagram dgm(getDiagramNode());

	int nModule = dgm.getNModules();
	for (int n=0; n<nModule; n++) {
		ScriptNode	*moduleNode = dgm.getModule(n);
		CModule		module(moduleNode);
		int mx = module.getPositionX();
		int my = module.getPositionY();
		int msize = module.getSize();
		if (isRect(selBoxRect, mx, my) == true && isRect(selBoxRect, mx+msize, my+msize) == true) 
			clipboard->addModuleNode(moduleNode);
	}

	for (Route *route = GetWorld()->getSceneGraph()->getRoutes(); route; route = route->next()) {
		if (dgm.hasRoute(route) == true) {
			CModule	moduleIn((ScriptNode *)route->getEventInNode());
			CModule	moduleOut((ScriptNode *)route->getEventOutNode());
			
			int	sx, sy, ex, ey;
			moduleOut.getRouteOutNodePosition(route->getEventOutField(), &sx, &sy);
			moduleIn.getRouteInNodePosition(route->getEventInField(), &ex, &ey);
			
			int nodeSize = moduleOut.getNodeSize();

			if (isRect(selBoxRect, sx, sy) == false || isRect(selBoxRect, sx+nodeSize, sy+nodeSize) == false) 
				continue;

			if (isRect(selBoxRect, ex, ey) == false || isRect(selBoxRect, ex+nodeSize, ey+nodeSize) == false) 
				continue;
			
			clipboard->addRoute(route);
		}
	}
}

////////////////////////////////////////
//	Windows Event Handler
////////////////////////////////////////

void CDiagramView::OnFontSetting() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	LOGFONT lf;
	getFontInfo(&lf);

	CFontDialog dlg(&lf, CF_SCREENFONTS|CF_INITTOLOGFONTSTRUCT, NULL, this);
	if (dlg.DoModal() == IDOK)
		setFont(&lf);
}

void CDiagramView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (GetWorld()->isSimulationActive()) {
		MessageBeep(0);
		return;
	}

	if (nChar == VK_DELETE) {
		if (getSelectingModule()) {
			if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE) {
				CDiagram	dgm(getDiagramNode());
				ScriptNode		*node = getSelectingModule();
				CModule		module(node);
				CModuleType *moduleType = module.getModuleType();
				if (moduleType->getAttribure() != MODULETYPE_ATTRIBUTE_SYSTEM) {
					enqueue(UndoDiagramModuleDeleteNew(getDiagramNode(), node), UndoDiagramModuleDeleteActionFn, UndoDiagramModuleDeleteFreeFn);
					dgm.removeModule(&module);
				}
				else
					MessageBeep(0);
			}
			else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE) {
				ScriptNode	*eventOutNode	= getSelectingModule();
				CModule	outModule(eventOutNode);
				Field	*eventOutField	= outModule.getEventOutField(getSelectingEventOutNode());
				Route	*route = GetWorld()->getSceneGraph()->getRoutes();
				while (route) {
					Route *nextRoute = route->next();
					if (route->getEventOutNode() == eventOutNode && route->getEventOutField() == eventOutField) {
						enqueue(UndoDiagramModuleDeleteInputLineNew((ScriptNode *)route->getEventInNode(), route->getEventInField(), (ScriptNode *)route->getEventOutNode(), route->getEventOutField()), UndoDiagramModuleDeleteInputLineFn);
						delete route;
					}
					route = nextRoute;
				}
			}
			else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_INNODE) {
				ScriptNode	*eventInNode	= getSelectingModule();
				CModule	inModule(eventInNode);
				Field	*eventInField	= inModule.getEventInField(getSelectingEventInNode());
				Route	*route = GetWorld()->getSceneGraph()->getRoutes();
				while (route) {
					Route *nextRoute = route->next();
					if (route->getEventInNode() == eventInNode && route->getEventInField() == eventInField) {
						enqueue(UndoDiagramModuleDeleteInputLineNew((ScriptNode *)route->getEventInNode(), route->getEventInField(), (ScriptNode *)route->getEventOutNode(), route->getEventOutField()), UndoDiagramModuleDeleteInputLineFn);
						delete route;
					}
					route = nextRoute;
				}
			}
			else if (getModuleOperationMode() & MODULE_INSIDE_EXECUTIONNODE) {
				ScriptNode	*eventInNode	= getSelectingModule();
				CModule	inModule(eventInNode);
				Field	*eventInField	= inModule.getExecutionField();
				Route	*route = GetWorld()->getSceneGraph()->getRoutes();
				while (route) {
					Route *nextRoute = route->next();
					if (route->getEventInNode() == eventInNode && route->getEventInField() == eventInField) {
						enqueue(UndoDiagramModuleDeleteInputLineNew((ScriptNode *)route->getEventInNode(), route->getEventInField(), (ScriptNode *)route->getEventOutNode(), route->getEventOutField()), UndoDiagramModuleDeleteInputLineFn);
						delete route;
					}
					route = nextRoute;
				}
			}
			setSelectingModule(NULL);
			setModuleOperationMode(DIAGRAM_MODE_NONE);			
			InvalidateRect(NULL);
			UpdateWindow();
		}
		else {
			if (isSelectingBoxOn() == true) {
				// Undo Action
				CDiagramClipboard *clipboard = new CDiagramClipboard();
				copyModulesInSelectingBox(clipboard);
				deleteModulesInSelectingBox();
				enqueue(UndoDiagramModuleCutNew(getDiagramNode(), clipboard), UndoDiagramModuleCutActionFn, UndoDiagramModuleCutFreeFn);
				InvalidateRect(NULL);
				UpdateWindow();
			}
		}
	}
	
	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CDiagramView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	LOGFONT lf;
	getFontInfo(&lf);
	setFont(&lf);
	
	return 0;
}

void CDiagramView::OnUndo() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (GetWorld()->isSimulationActive()) {
		MessageBeep(0);
		return;
	}

	if (0 < getNQueues()) {
		undo();
		InvalidateRect(NULL);
		UpdateWindow();
	}
	else
		MessageBeep(0);
}

void CDiagramView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (GetWorld()->isSimulationActive()) {
		MessageBeep(0);
		return;
	}

	CDiagram dgm(getDiagramNode());

	int		mode;
	ScriptNode	*module;
	module = dgm.getModule(point.x, point.y, &mode);
	setModuleOperationMode(mode);
	setSelectingModule(module);
	
	if (getModuleOperationMode()) {
		
		CtbModuleFloatingShowWindow(SW_HIDE);

		CModule		module(getSelectingModule());
		CModuleType	*moduleType = module.getModuleType();
		
		//// STRING /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "STRING")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "Value")) {
				DialogWorldConstant	dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "DIRECTION")) {
				DialogModuleStringVector dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "ROTATION")) {
				DialogModuleStringOrientation dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "POSITION")) {
				DialogModuleStringPosition dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "BOOL")) {
				DialogModuleStringBool dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "COLOR")) {
				
				BYTE	r, g, b;
				float	color[] = {1.0f, 1.0f, 1.0f};
				
				r = g = b = 255;

				char *moduleValue = module.getValue();
				if (moduleValue) {
					if (sscanf(moduleValue, "%f,%f,%f", &color[0], &color[1], &color[2]) == 3) {
						r = (BYTE)(color[0] / 1.0f * 255.0f);
						g = (BYTE)(color[1] / 1.0f * 255.0f);
						b = (BYTE)(color[2] / 1.0f * 255.0f);
					}
				}

				COLORREF rgbColor = RGB(r, g, b);
				CColorDialog dialog(rgbColor, CC_FULLOPEN, this);
				if (dialog.DoModal() == IDOK) {

					rgbColor = dialog.GetColor();
					color[0] = (float)GetRValue(rgbColor) / 255.0f;
					color[1] = (float)GetGValue(rgbColor) / 255.0f;
					color[2] = (float)GetBValue(rgbColor) / 255.0f;

					char colorString[256];
					sprintf(colorString, "%g,%g,%g", color[0], color[1], color[2]);
					module.setValue(colorString);

					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "SetValue") ||
					 !StringCompareIgnoreCase(moduleType->getName(), "SetArrayValue")) {
				DialogGlobalDataName	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					char	*gdataName = dialog.getGlobalDataName();
					StringReplaceChar(gdataName, ' ', '-');
					StringReplaceChar(gdataName, '_', '-');
					AnchorNode	*gdataNode = GetWorld()->getGlobalDataNode(gdataName);
					if (!gdataNode) 
						gdataNode = GetWorld()->addGlobalData(gdataName);
					module.setTargetNode(gdataNode);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "GetValue") ||
					 !StringCompareIgnoreCase(moduleType->getName(), "GetArrayValue")) {
				DialogGlobalDataName	dialog(this);
				dialog.setNode(module.getSourceNode());
				if (dialog.DoModal() == IDOK) {
					char	*gdataName = dialog.getGlobalDataName();
					AnchorNode	*gdataNode = GetWorld()->getGlobalDataNode(gdataName);
					if (gdataNode) 
						module.setSourceNode(gdataNode);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
		}


		//// FILTER /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "FILTER")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "HIGH")) {
				DialogFilterHigh dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "LOW")) {
				DialogFilterLow dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "RANGE")) {
				DialogFilterRange dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "SCALE")) {
				DialogFilterScale dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "SCALARINTERPOLATOR")) {
				DialogModuleFilterScalarInterp dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "POSITION2DINTERPOLATOR")) {
				DialogModuleFilterPosition2DInterp dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "POSITION3DINTERPOLATOR")) {
				DialogModuleFilterPosition3DInterp dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "ORIENTATIONINTERPOLATOR")) {
				DialogModuleFilterOrientationInterp dialog(this);
				dialog.setModule(&module);
				if (dialog.DoModal() == IDOK) {
					ScriptNode *script = module.getScriptNode();
					script->updateFields();
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
		}

		//// MISC /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "MISC")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "ObjectCollision")) {
				DialogObjectCollision	dialog(this);
				dialog.setNode1(module.getSourceNode());
				dialog.setNode2(module.getTargetNode());
				float radius1, radius2;
				char *value = module.getValue();
				if (value && sscanf(value, "%f,%f", &radius1, &radius2) == 2) {
					dialog.setRadius1(radius1);
					dialog.setRadius2(radius2);
				}
				else{
					dialog.setRadius1(1.0f);
					dialog.setRadius2(1.0f);
				}
				if (dialog.DoModal() == IDOK) {
					module.setSourceNode(dialog.getNode1());
					module.setTargetNode(dialog.getNode2());
					char radiusString[256];
					sprintf(radiusString, "%g,%g", dialog.getRadius1(), dialog.getRadius2());
					module.setValue(radiusString);

					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			else if (!StringCompareIgnoreCase(moduleType->getName(), "PlaySound")) {
				DialogModuleMiscPlaySound	dialog(this);
				Node *node = module.getTargetNode();
				dialog.setNode(node);
				if (dialog.DoModal() == IDOK) {
					node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
		}
	
		//// OBJECT /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "OBJECT")) {
			DialogObjectName	dialog(this);
			Node				*node = NULL;

			if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3))
				node = module.getTargetNode();
			else if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
				node = module.getSourceNode();

			dialog.setNode(node);
			if (dialog.DoModal() == IDOK) {
				node = dialog.getNode();
				if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3)) 
					module.setTargetNode(node);
				if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
					module.setSourceNode(node);
				InvalidateRect(NULL);
				UpdateWindow();
			}
		}

		//// VIEW /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "VIEW")) {
			DialogViewName	dialog(this);
			Node				*node = NULL;

			if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3))
				node = module.getTargetNode();
			else if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
				node = module.getSourceNode();

			dialog.setNode(node);
			if (dialog.DoModal() == IDOK) {
				node = dialog.getNode();
				if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3)) 
					module.setTargetNode(node);
				if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
					module.setSourceNode(node);
				InvalidateRect(NULL);
				UpdateWindow();
			}
		}

		//// MATERIAL /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "MATERIAL")) {
			DialogMaterialName	dialog(this);
			Node				*node = NULL;

			if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3))
				node = module.getTargetNode();
			if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
				node = module.getSourceNode();

			dialog.setNode(node);
			if (dialog.DoModal() == IDOK) {
				node = dialog.getNode();
				if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3)) 
					module.setTargetNode(node);
				else if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
					module.setSourceNode(node);
				InvalidateRect(NULL);
				UpdateWindow();
			}
		}

		//// LIGHT /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "LIGHT")) {
			DialogLightName		dialog(this);

			char *typeName = moduleType->getName();

			Node *node = NULL;
			if (!StringNCompareIgnoreCase(typeName, "SET", 3))
				node = module.getTargetNode();
			if (!StringNCompareIgnoreCase(typeName, "GET", 3)) 
				node = module.getSourceNode();
			dialog.setNode(node);

			int type = 0;
			if (!StringNCompareIgnoreCase(&typeName[3], "COLOR", 5))
				type = LIGHTTYPE_DIRECTIONAL | LIGHTTYPE_POINT | LIGHTTYPE_SPOT;
			if (!StringNCompareIgnoreCase(&typeName[3], "DIRECTION", 9))
				type = LIGHTTYPE_DIRECTIONAL | LIGHTTYPE_SPOT;
			if (!StringNCompareIgnoreCase(&typeName[3], "ON", 2))
				type = LIGHTTYPE_DIRECTIONAL | LIGHTTYPE_POINT | LIGHTTYPE_SPOT;
			if (!StringNCompareIgnoreCase(&typeName[3], "INTENSITY", 9))
				type = LIGHTTYPE_DIRECTIONAL | LIGHTTYPE_POINT | LIGHTTYPE_SPOT;
			if (!StringNCompareIgnoreCase(&typeName[3], "LOCATION", 9))
				type = LIGHTTYPE_POINT | LIGHTTYPE_SPOT;
			if (!StringNCompareIgnoreCase(&typeName[3], "RADIUS", 6))
				type = LIGHTTYPE_POINT | LIGHTTYPE_SPOT;
			dialog.setType(type);

			if (dialog.DoModal() == IDOK) {
				node = dialog.getNode();
				if (!StringNCompareIgnoreCase(moduleType->getName(), "SET", 3)) 
					module.setTargetNode(node);
				else if (!StringNCompareIgnoreCase(moduleType->getName(), "GET", 3)) 
					module.setSourceNode(node);
				InvalidateRect(NULL);
				UpdateWindow();
			}
		}

		//// INTERP /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "INTERP")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "Color")) {
				DialogModuleInterpColor	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "Position")) {
				DialogModuleInterpPosition	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "Orientation")) {
				DialogModuleInterpOrientation dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "Normal")) {
				DialogModuleInterpNormal dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "Scalar")) {
				DialogModuleInterpScalar dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
		}

		//// NODE /////////////////////////////////////////////////////////
		if (!StringCompareIgnoreCase(moduleType->getClassName(), "MISC")) {
			if (!StringCompareIgnoreCase(moduleType->getName(), "SetText")) {
				DialogTextName	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "SetSkyColor")) {
				DialgoBackgroundName	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "SetImageTexture")) {
				DialogImageTextureName	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "SetSwitch")) {
				DialogSwitchName	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
			if (!StringCompareIgnoreCase(moduleType->getName(), "SetAudioClip")) {
				DialogAudioClipName	dialog(this);
				dialog.setNode(module.getTargetNode());
				if (dialog.DoModal() == IDOK) {
					Node *node = dialog.getNode();
					module.setTargetNode(node);
					InvalidateRect(NULL);
					UpdateWindow();
				}
			}
		}

		CtbModuleFloatingShowWindow(SW_SHOW);
	}


	setModuleOperationMode(DIAGRAM_MODE_NONE);
	
	CScrollView::OnLButtonDblClk(nFlags, point);
}

void CDiagramView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	static CRect	dragRect;
	static int		mosx, mosy;

	SIZE	size;
	size.cx = 1;
	size.cy = 1;

	CDC *pDC = GetDC();

	if (isDragging()) {
		if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE) {

			int mxOffset, myOffset;
			getMouseOffset(&mxOffset, &myOffset);
			
			int newx = point.x + mxOffset;
			int newy = point.y + myOffset;
			if (getGridSnap()) {
				newx -= newx % (32/4);
				newy -= newy % (32/4);
			}

			CRect	oldDragRect = dragRect;
			dragRect.SetRect(newx, newy, newx + 32, newy + 32);

			if (mbDragRect && GetWorld()->isSimulationActive() == FALSE) {
				pDC->DrawDragRect(&dragRect, size, &oldDragRect, size);
			}
			else {
				pDC->DrawDragRect(&dragRect, size, NULL, size);
				mbDragRect = TRUE;
			}

		}
		else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE || getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_INNODE || getModuleOperationMode() & MODULE_INSIDE_EXECUTIONNODE) {

			CModule	module(getSelectingModule());
			int		nodeHalfSize = module.getNodeSize() / 2;
			int	sx, sy;
			
			if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE)
				module.getEventOutNodePosition(getSelectingEventOutNode(), &sx, &sy);
			else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_INNODE)
				module.getEventInNodePosition(getSelectingEventInNode(), &sx, &sy);
			else if (getModuleOperationMode() & MODULE_INSIDE_EXECUTIONNODE)
				module.getExecutionNodePosition(&sx, &sy);

			CPoint offset = GetScrollPosition ();
			sx -= offset.x;
			sy -= offset.y;
			if (mbDragRect) {
				int rop = pDC->SetROP2(R2_NOTXORPEN);
				pDC->MoveTo(sx + nodeHalfSize, sy + nodeHalfSize); pDC->LineTo(mosx, mosy);
				mosx =point.x; mosy = point.y;
				pDC->MoveTo(sx + nodeHalfSize, sy + nodeHalfSize); pDC->LineTo(mosx, mosy);
				pDC->SetROP2(rop);
			}
			else {
				int rop = pDC->SetROP2(R2_NOTXORPEN);
				mosx =point.x; mosy = point.y;
				pDC->MoveTo(sx + nodeHalfSize, sy + nodeHalfSize); pDC->LineTo(mosx, mosy);
				pDC->SetROP2(rop);
				mbDragRect = TRUE;
			}

		}
		else if (isSelectingBoxOn() == true) {

			int	selBoxRect[4];
			getSelectingBoxRect(selBoxRect);

			int mxOffset, myOffset;
			getMouseOffset(&mxOffset, &myOffset);
			
			int newx = point.x + mxOffset;
			int newy = point.y + myOffset;
			if (getGridSnap()) {
				newx -= newx % (32/4);
				newy -= newy % (32/4);
			}

			int width = selBoxRect[2] - selBoxRect[0];
			int height = selBoxRect[3] - selBoxRect[1];

			CRect	oldDragRect = dragRect;
			dragRect.SetRect(newx, newy, newx + width, newy + height);

			if (mbDragRect && GetWorld()->isSimulationActive() == FALSE) {
				pDC->DrawDragRect(&dragRect, size, &oldDragRect, size);
			}
			else {
				pDC->DrawDragRect(&dragRect, size, NULL, size);
				mbDragRect = TRUE;
			}

		}
		else {

			int	mxStart, myStart;
			getMouseStartPosition(&mxStart, &myStart);
			int xmin = min(mxStart, point.x);
			int xmax = max(mxStart, point.x);
			int ymin = min(myStart, point.y);
			int ymax = max(myStart, point.y);
			
			if (getGridSnap()) {
				xmin -= xmin % (32/4);
				xmax -= xmax % (32/4);
				ymin -= ymin % (32/4);
				ymax -= ymax % (32/4);
			}

			CRect	oldDragRect = dragRect;
			dragRect.SetRect(xmin, ymin, xmax, ymax);
			
			if (mbDragRect && GetWorld()->isSimulationActive() == FALSE) {
				pDC->DrawDragRect(&dragRect, size, &oldDragRect, size);
			}
			else {
				pDC->DrawDragRect(&dragRect, size, NULL, size);
				mbDragRect = TRUE;
			}
			
		}
	}

	ReleaseDC(pDC);

	CScrollView::OnMouseMove(nFlags, point);
}

void CDiagramView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CDiagram dgm(getDiagramNode());

	CPoint offset = GetScrollPosition ();

	if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE) {
		ScriptNode *node = getSelectingModule();
		CModule module(node);

		int mxOffset, myOffset;
		getMouseOffset(&mxOffset, &myOffset);

		int newx = point.x + mxOffset + offset.x;
		int newy = point.y + myOffset + offset.y;

		if (getGridSnap()) {
			newx -= newx % (32/4);
			newy -= newy % (32/4);
		}

		int	x, y;
		module.getPosition(&x, &y);

		if (x != newx || y != newy) {
			// Undo Action
			enqueue(UndoDiagramModuleMoveNew(node, x, y), UndoDiagramModuleMoveFn);
		
			module.setPosition(newx, newy);

			// Update Screen Size
			updateScreenSize();
		}
	}
	else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE) {
		ScriptNode	*eventOutNode	= getSelectingModule();
		Field	*eventOutField	= eventOutNode->getEventOut(getSelectingEventOutNode());

		int		mode;
		ScriptNode	*module;
		module = dgm.getModule(point.x  + offset.x, point.y  + offset.y, &mode);
		setModuleOperationMode(mode);
		setSelectingModule(module);

		if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_INNODE) {
			ScriptNode	*eventInNode	= getSelectingModule();
			CModule	inModule(eventInNode);
			Field	*eventInField	= inModule.getEventInField(getSelectingEventInNode());

			CModule	outModule(eventOutNode);
			outModule.setOutputRoute(eventOutField, eventInNode, eventInField);

			// Undo Action
			enqueue(UndoDiagramModuleCreateInputLineNew(eventOutNode, eventOutField, eventInNode, eventInField), UndoDiagramModuleCreateInputLineFn);
		}
		else if (getModuleOperationMode() & MODULE_INSIDE_EXECUTIONNODE) {
			ScriptNode	*eventInNode	= getSelectingModule();
			CModule	inModule(eventInNode);
			Field	*eventInField	= inModule.getExecutionField();

			CModule	outModule(eventOutNode);
			outModule.setOutputRoute(eventOutField, eventInNode, eventInField);

			// Undo Action
			enqueue(UndoDiagramModuleCreateInputLineNew(eventOutNode, eventOutField, eventInNode, eventInField), UndoDiagramModuleCreateInputLineFn);
		}
	}
	else if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_INNODE) {
		ScriptNode	*eventInNode	= getSelectingModule();
		CModule	inModule(eventInNode);
		Field	*eventInField	= inModule.getEventInField(getSelectingEventInNode());

		int		mode;
		ScriptNode	*module;
		module = dgm.getModule(point.x  + offset.x, point.y  + offset.y, &mode);
		setModuleOperationMode(mode);
		setSelectingModule(module);

		if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE) {
			ScriptNode	*eventOutNode	= getSelectingModule();
			CModule	outModule(eventOutNode);
			Field	*eventOutField	= outModule.getEventOutField(getSelectingEventOutNode());

			outModule.setOutputRoute(eventOutField, eventInNode, eventInField);

			// Undo Action
			enqueue(UndoDiagramModuleCreateInputLineNew(eventOutNode, eventOutField, eventInNode, eventInField), UndoDiagramModuleCreateInputLineFn);
		}
	}
	else if (getModuleOperationMode() & MODULE_INSIDE_EXECUTIONNODE) {
		ScriptNode	*eventInNode	= getSelectingModule();
		CModule	inModule(eventInNode);
		Field	*eventInField	= inModule.getExecutionField();

		int		mode;
		ScriptNode	*module;
		module = dgm.getModule(point.x  + offset.x, point.y  + offset.y, &mode);
		setModuleOperationMode(mode);
		setSelectingModule(module);

		if (getModuleOperationMode() & DIAGRAM_MODE_SELECTING_MODULE_OUTNODE) {
			ScriptNode	*eventOutNode	= getSelectingModule();
			CModule	outModule(eventOutNode);
			Field	*eventOutField	= outModule.getEventOutField(getSelectingEventOutNode());

			outModule.setOutputRoute(eventOutField, eventInNode, eventInField);

			// Undo Action
			enqueue(UndoDiagramModuleCreateInputLineNew(eventOutNode, eventOutField, eventInNode, eventInField), UndoDiagramModuleCreateInputLineFn);
		}
	}

	setMouseEndPosition(point.x, point.y);

//	setModuleOperationMode(DIAGRAM_MODE_NONE);
	setDragOff();

	if (getModuleOperationMode() == 0) {

		int mxStart, myStart;
		getMouseStartPosition(&mxStart, &myStart);

		if (getGridSnap()) {
			mxStart -= mxStart % (32/4);
			myStart -= myStart % (32/4);
		}

		if (getGridSnap()) {
			point.x -= point.x % (32/4);
			point.y -= point.y % (32/4);
		}

		int xoffset = point.x - mxStart;
		int yoffset = point.y - myStart;

		int	selBoxRect[4];
		getSelectingBoxRect(selBoxRect);

		if (isSelectingBoxOn() == true) {

			int nSelBoxModule = dgm.getNModules(selBoxRect);

			ScriptNode*	(*moduleNode)	= new (ScriptNode *[nSelBoxModule]);
			int			*mx				= new int[nSelBoxModule];
			int			*my				= new int[nSelBoxModule];

			int moduleNum = dgm.getNModules();
			int nModule = 0;
			for (int n=0; n<moduleNum; n++) {
				CModule		module(dgm.getModule(n));
				int modx = module.getPositionX();
				int mody = module.getPositionY();
				int modSize = module.getSize();
				if (isRect(selBoxRect, modx, mody) == true && isRect(selBoxRect, modx+modSize, mody+modSize) == true) {
					moduleNode[nModule] = dgm.getModule(n);
					mx[nModule] = modx;
					my[nModule] = mody;
					module.setPosition(modx + xoffset, mody + yoffset);
					nModule++;
				}
			}

			enqueue(UndoDiagramModuleMoveInSelectingBoxNew(nSelBoxModule, moduleNode, mx, my), UndoDiagramModuleMoveInSelectingBoxActionFn, UndoDiagramModuleMoveInSelectingBoxFreeFn);

			selBoxRect[0] += xoffset;
			selBoxRect[1] += yoffset;
			selBoxRect[2] += xoffset;
			selBoxRect[3] += yoffset;
			setSelectingBoxRect(selBoxRect);
		}
		else {

			int	mxStart, myStart;
			getMouseStartPosition(&mxStart, &myStart);

			if (mxStart != point.x && myStart != point.y) {
				int xmin = min(mxStart, point.x);
				int xmax = max(mxStart, point.x);
				int ymin = min(myStart, point.y);
				int ymax = max(myStart, point.y);

				xmin += offset.x;
				xmax += offset.x;
				ymin += offset.y;
				ymax += offset.y;

				if (getGridSnap()) {
					xmin -= xmin % (32/4);
					xmax -= xmax % (32/4);
					ymin -= ymin % (32/4);
					ymax -= ymax % (32/4);
				}

				setSelectingBoxRect(xmin, ymin, xmax, ymax);
				selectingBoxOn();
			}
			else
				selectingBoxOff();
		}
	}


	InvalidateRect(NULL);
	UpdateWindow();
	
	CScrollView::OnLButtonUp(nFlags, point);
}

void CDiagramView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CDiagram dgm(getDiagramNode());
	
	int		mode;
	ScriptNode	*moduleNode;
	CSize size = GetTotalSize();
	CPoint offset = GetScrollPosition ();

	moduleNode = dgm.getModule(point.x + offset.x, point.y + offset.y, &mode);

	if (GetWorld()->isSimulationActive()) {
		if (mode != 0 && mode != DIAGRAM_MODE_SELECTING_MODULE) {
			MessageBeep(0);
			return;
		}
	}

	setModuleOperationMode(mode);
	setSelectingModule(moduleNode);
	
	setMouseStartPosition(point.x, point.y);

	if (getModuleOperationMode()) { 
		CModule module(getSelectingModule());
		setMouseOffset(module.getPositionX() - (point.x + offset.x), module.getPositionY() - (point.y + offset.y));
		selectingBoxOff();
	}
	else {
		int	selBoxRect[4];
		getSelectingBoxRect(selBoxRect);
		setMouseOffset(selBoxRect[0] - (point.x + offset.x), selBoxRect[1] - (point.y + offset.y));
		if (isSelectingBoxOn() == true) {
			if (isRect(selBoxRect, point.x + offset.x, point.y + offset.y) == false) 
				selectingBoxOff();
		}
	}

	mbDragRect = FALSE;
	setDragOn();
	
	InvalidateRect(NULL);
	UpdateWindow();
	
	CScrollView::OnLButtonDown(nFlags, point);
}


BOOL CDiagramView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	return TRUE;
//	return CScrollView::OnEraseBkgnd(pDC);
}

BOOL CDiagramView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	InvalidateRect(NULL);
	UpdateWindow();
	
	return CScrollView::OnScroll(nScrollCode, nPos, bDoScroll);
}


void CDiagramView::OnDestroy() 
{
	CScrollView::OnDestroy();
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	savePosition();
}

void CDiagramView::OnDiagramConfig() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	DialogDiagramConfig	dialog(this);
	dialog.setTransformNode(getDiagramNode());
	dialog.setLineStyle(getLineStyle());
	dialog.setGridDisplay(getGridDisplay());
	dialog.setGridSnap(getGridSnap());

	if (dialog.DoModal() == IDOK) {
		CDiagram	diagram(getDiagramNode());
		updateWindowText();
		setLineStyle(dialog.getLineStyle());
		setGridDisplay(dialog.getGridDisplay());
		setGridSnap(dialog.getGridSnap());
		InvalidateRect(NULL);
	}
}


void CDiagramView::OnEditCopy() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	copyModulesInSelectingBox(getClipboard());
}

void CDiagramView::OnEditCut() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	OnEditCopy();

	deleteModulesInSelectingBox();

	// Undo Action
	CDiagramClipboard *clipboard = new CDiagramClipboard(getClipboard());
	enqueue(UndoDiagramModuleCutNew(getDiagramNode(), clipboard), UndoDiagramModuleCutActionFn, UndoDiagramModuleCutFreeFn);

	InvalidateRect(NULL);
	UpdateWindow();
}

void CDiagramView::OnEditPaste() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	CDiagramClipboard *clipboard = getClipboard();	

	CDiagram dgm(getDiagramNode());

	int nModule = clipboard->getNModuleNodes();
	
	ScriptNode*	(*moduleNode)[2] = new (ScriptNode *[nModule][2]);
	ScriptNode* (*undoModuleNode) = new (ScriptNode *[nModule]);
	
	for (int n=0; n<nModule; n++) {
		CModule		orgModule(clipboard->getModuleNode(n));
		CModule		copyModule(orgModule.getModuleType());
		copyModule.setPositionX(orgModule.getPositionX());
		copyModule.setPositionY(orgModule.getPositionY());
		dgm.addModule(&copyModule);
		undoModuleNode[n] = copyModule.getScriptNode();
		moduleNode[n][0] = orgModule.getScriptNode();
		moduleNode[n][1] = copyModule.getScriptNode();
	}

	int nRoute = clipboard->getNRoutes();

	Route* (*undoRoute) = new (Route *[nRoute]);

	for (n=0; n<nRoute; n++) {
		Route	*route = clipboard->getRoute(n);
		ScriptNode	*outModule = (ScriptNode *)route->getEventOutNode();
		for (int i=0; i<nModule; i++) {
			if (moduleNode[i][0] == outModule) {
				outModule = moduleNode[i][1];
				break;
			}
		}
		ScriptNode	*inModule = (ScriptNode *)route->getEventInNode();
		for (i=0; i<nModule; i++) {
			if (moduleNode[i][0] == inModule) {
				inModule = moduleNode[i][1];
				break;
			}
		}
		undoRoute[n] = GetWorld()->getSceneGraph()->addRoute(outModule->getName(), route->getEventOutField()->getName(), inModule->getName(), route->getEventInField()->getName());
	}
	
	delete []moduleNode;

	// Undo Action
	enqueue(UndoDiagramModulePasteNew(getDiagramNode(), nModule, undoModuleNode, nRoute, undoRoute), UndoDiagramModulePasteActionFn, UndoDiagramModulePasteFreeFn);

	InvalidateRect(NULL);
	UpdateWindow();
}
