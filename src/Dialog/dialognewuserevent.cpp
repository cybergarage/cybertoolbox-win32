// DialogNewUserEvent.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogNewUserEvent.h"
#include "UserMessage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogNewUserEvent

IMPLEMENT_DYNAMIC(DialogNewUserEvent, CPropertySheet)


DialogNewUserEvent::DialogNewUserEvent(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&mUserEventClockPage);
	AddPage(&mUserEventTimerPage);
	AddPage(&mUserEventPickupPage);
	AddPage(&mUserEventDragPage);
	AddPage(&mUserEventAreaPage);
//	AddPage(&mUserEventCollisionPage);

	m_psh.dwFlags |= PSH_NOAPPLYNOW;

	setCenter(0, 0, 0);
	setSize(0, 0, 0);
}

DialogNewUserEvent::DialogNewUserEvent(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&mUserEventClockPage);
	AddPage(&mUserEventTimerPage);
	AddPage(&mUserEventPickupPage);
	AddPage(&mUserEventDragPage);
	AddPage(&mUserEventAreaPage);
//	AddPage(&mUserEventCollisionPage);

	m_psh.dwFlags |= PSH_NOAPPLYNOW;

	setCenter(0, 0, 0);
	setSize(0, 0, 0);
}

DialogNewUserEvent::~DialogNewUserEvent()
{
}


BEGIN_MESSAGE_MAP(DialogNewUserEvent, CPropertySheet)
	//{{AFX_MSG_MAP(DialogNewUserEvent)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogNewUserEvent メッセージ ハンドラ

BOOL DialogNewUserEvent::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	switch (LOWORD(wParam)) {
	case IDOK:
		{
			char	value[512];
			int nPage = GetActiveIndex();
			setPage(nPage);
			CPropertyPage *page = GetPage(nPage);
			switch (nPage) {
			case USER_EVENT_CLOCK_PAGE: // CLOCK
				{
					page->GetDlgItemText(IDC_INTREVAL_TIME, value, 512);
					double	time = atof(value);
					if (time <= 0.0) {
						UsrMsgSetParentWindow(this);
						UsrMsgWarning("Bad Number : %s", value);
						return FALSE;
					}
					setIntervalTime(time);
				}
				break;
			case USER_EVENT_TIMER_PAGE: // 
				{
					page->GetDlgItemText(IDC_WAKEUP_TIME, value, 512);
					double	time = atof(value);
					if (time <= 0.0) {
						UsrMsgSetParentWindow(this);
						UsrMsgWarning("Bad Number : %s", value);
						return FALSE;
					}
					setWakeUpTime(time);
				}
				break;
			case USER_EVENT_PICKUP_PAGE: // PICKUP
				{
					page->GetDlgItemText(IDC_NODE_NAME, value, 512);
					setPickupNodeName(value);
				}
				break;

			case USER_EVENT_AREA_PAGE: // AREA
				{
					float	cx, cy, cz;
					float	sx, sy, sz;
					int		nValue = 0;
					
					page->GetDlgItemText(IDC_CENTER_X, value, 512);
					if (sscanf(value, "%f", &cx) == 1)
						nValue++;

					page->GetDlgItemText(IDC_CENTER_Y, value, 512);
					if (sscanf(value, "%f", &cy) == 1)
						nValue++;

					page->GetDlgItemText(IDC_CENTER_Z, value, 512);
					if (sscanf(value, "%f", &cz) == 1)
						nValue++;

					page->GetDlgItemText(IDC_SIZE_X, value, 512);
					if (sscanf(value, "%f", &sx) == 1)
						nValue++;

					page->GetDlgItemText(IDC_SIZE_Y, value, 512);
					if (sscanf(value, "%f", &sy) == 1)
						nValue++;

					page->GetDlgItemText(IDC_SIZE_Z, value, 512);
					if (sscanf(value, "%f", &sz) == 1)
						nValue++;

					if (nValue == 6) {
						setCenter(cx, cy, cz);
						setSize(sx, sy, sz);
					}
					else
						MessageBeep(0);
				}
				break;

			case USER_EVENT_DRAG_PAGE: // Drag
				{
					char	nodeName[512];
					page->GetDlgItemText(IDC_NODE_NAME, nodeName, 512);
					setDragNodeName(nodeName);
				}
				break;
			}

		}
		break;
	}
	
	
	return CPropertySheet::OnCommand(wParam, lParam);
}

#define _countof(array) (sizeof(array)/sizeof(array[0]))
static int rgiButtons[] = { IDOK, IDCANCEL, ID_APPLY_NOW, IDHELP };

BOOL DialogNewUserEvent::OnInitDialog()
{
	if (!(m_psh.dwFlags & PSH_WIZARD))
	{
		// resize the tab control so the layout is less restrictive
		HWND hWnd = (HWND)::GetDlgItem(m_hWnd, AFX_IDC_TAB_CONTROL);
		ASSERT(hWnd != NULL);
		CRect rectOld;
		::GetWindowRect(hWnd, &rectOld);
		ScreenToClient(rectOld);

		int offset = rectOld.Width() - 250;
		
		CRect rectNew(0, 0, 0, 32);
		::MapDialogRect(m_hWnd, &rectNew);
		if (rectNew.bottom < rectOld.bottom)
		{
			// move tab control
			int cyDiff = rectOld.Height() - rectNew.bottom;
			::SetWindowPos(hWnd, NULL, 0, 0, rectOld.Width() - offset, rectNew.bottom,
				SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

			// move buttons by similar amount
			for (int i = 0; i < _countof(rgiButtons); i++)
			{
				hWnd = ::GetDlgItem(m_hWnd, rgiButtons[i]);
				if (hWnd != NULL)
				{
					::GetWindowRect(hWnd, &rectOld);
					ScreenToClient(&rectOld);

					::SetWindowPos(hWnd, NULL,
						rectOld.left - offset, rectOld.top - cyDiff,
						0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
				}
			}

			// resize property sheet itself similarly
			GetWindowRect(&rectOld);

			SetWindowPos(NULL, 0, 0, rectOld.Width() - offset, rectOld.Height() - cyDiff,
				SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		}
	}

	BOOL bResult = (BOOL)Default();

	// change tab style if scrolling tabs desired (stacked tabs are default)
	if (!m_bStacked)
	{
		HWND hWndTab = (HWND)SendMessage(PSM_GETTABCONTROL);
		if (hWndTab != NULL)
			CWnd::ModifyStyle(hWndTab, TCS_MULTILINE, TCS_SINGLELINE, 0);
	}

	if (m_bModeless && !(m_psh.dwFlags & PSH_WIZARD))
	{
		// layout property sheet so button area is not accounted for
		CRect rectWnd;
		GetWindowRect(rectWnd);
		CRect rectButton;
		HWND hWnd = ::GetDlgItem(m_hWnd, IDOK);
		ASSERT(hWnd != NULL);
		::GetWindowRect(hWnd, rectButton);
		SetWindowPos(NULL, 0, 0,
			rectWnd.Width(), rectButton.top - rectWnd.top,
			SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

		// remove standard buttons for modeless dialogs
		for (int i = 0; i < _countof(rgiButtons); i++)
		{
			HWND hWnd = ::GetDlgItem(m_hWnd, rgiButtons[i]);
			if (hWnd != NULL)
			{
				::ShowWindow(hWnd, SW_HIDE);
				::EnableWindow(hWnd, FALSE);
			}
		}
	}

	// center the property sheet relative to the parent window
	if (!(GetStyle() & WS_CHILD))
		CenterWindow();

	return bResult;
}

int DialogNewUserEvent::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPropertySheet::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	/*
	RECT	rect;
	GetWindowRect(&rect);
	MoveWindow(rect.left, rect.top, 300, rect.bottom - rect.top);
	GetClientRect(&rect);
*/
//	TabCtrl_AdjustRect(mUserEventClockPage.m_hWnd, FALSE, &rect);
//	mUserEventClockPage.MoveWindow(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

	return 0;
}
