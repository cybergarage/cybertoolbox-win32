// DialogNewUserEvent.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// DialogNewUserEvent
#include "UserEventPickupPage.h"
#include "UserEventDragPage.h"
#include "UserEventClockPage.h"
#include "UserEventAreaPage.h"
#include "UserEventCollisionPage.h"
#include "UserEventTimerPage.h"
#include "SceneGraph.h"

enum {
USER_EVENT_CLOCK_PAGE,
USER_EVENT_TIMER_PAGE,
USER_EVENT_PICKUP_PAGE,
USER_EVENT_DRAG_PAGE,
USER_EVENT_AREA_PAGE,
};

class DialogNewUserEvent : public CPropertySheet
{
	DECLARE_DYNAMIC(DialogNewUserEvent)

// コンストラクション
public:
	DialogNewUserEvent(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	DialogNewUserEvent(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

	BOOL OnInitDialog();

public:
	//////////////////////////////
	//	Page
	//////////////////////////////
	int					mPage;
	void				setPage(int Page)	{mPage = Page;}
	int					getPage()			{return mPage;}

	//////////////////////////////
	//	Clock
	//////////////////////////////
	UserEventClockPage	mUserEventClockPage;
	double				mIntervalTime;
	void				setIntervalTime(double	time)	{mIntervalTime = time;}
	double				getIntervalTime()				{return mIntervalTime;}

	//////////////////////////////
	//	Timer
	//////////////////////////////
	UserEventTimerPage	mUserEventTimerPage;
	double				mWakeUpTime;
	void				setWakeUpTime(double	time)	{mWakeUpTime = time;}
	double				getWakeUpTime()					{return mWakeUpTime;}

	//////////////////////////////
	//	Picking
	//////////////////////////////
	UserEventPickupPage	mUserEventPickupPage;
	String				mPickupNodeName;
	void				setPickupNodeName(char *name)	{mPickupNodeName.setValue(name);}
	char				*getPickupNodeName()			{return mPickupNodeName.getValue();}

	//////////////////////////////
	//	Drag
	//////////////////////////////
	UserEventDragPage	mUserEventDragPage;
	String				mDragNodeName;
	void				setDragNodeName(char *name)		{mDragNodeName.setValue(name);}
	char				*getDragNodeName()				{return mDragNodeName.getValue();}

	//////////////////////////////
	//	Area
	//////////////////////////////
	UserEventAreaPage	mUserEventAreaPage;
	float				mCenter[3];
	float				mSize[3];
	void				setCenter(float x, float y, float z)	{ mCenter[0] = x; mCenter[1] = y; mCenter[2] = z; }
	void				setSize(float x, float y, float z)		{ mSize[0] = x; mSize[1] = y; mSize[2] = z; }
	void				getCenter(float *x, float *y, float *z)	{ *x = mCenter[0]; *y = mCenter[1]; *z = mCenter[2]; }
	void				getSize(float *x, float *y, float *z)	{ *x = mSize[0]; *y = mSize[1]; *z = mSize[2]; }
	void				getCenter(float center[])				{ center[0] = mCenter[0]; center[1] = mCenter[1]; center[2] = mCenter[2]; }
	void				getSize(float size[])					{ size[0] = mSize[0]; size[1] = mSize[1]; size[2] = mSize[2]; }

	//////////////////////////////
	//	Drag
	//////////////////////////////
	UserEventCollisionPage	mUserEventCollisionPage;

// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(DialogNewUserEvent)
	protected:
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~DialogNewUserEvent();

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(DialogNewUserEvent)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
