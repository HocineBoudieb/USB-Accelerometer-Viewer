// Draw.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "AccView.h"
#include "DrawWnd.h"


// CDraw

IMPLEMENT_DYNAMIC(CDraw, CWnd)

CDraw::CDraw(AccSensor* _sensor): sensor(_sensor),nech(0),white(PS_SOLID, 5, RGB(255,255, 255)),red(PS_SOLID, 5, RGB(255,0, 0)),green(PS_SOLID, 5, RGB(0,255, 0)),blue(PS_SOLID, 5, RGB(0,0, 255)),track(true)
{
	pen = &white;
}

CDraw::~CDraw()
{
	KillTimer(timer);
}


void CDraw::ShowFull(HWND parent)
{
	CreateEx(WS_EX_TOPMOST,
               AfxRegisterWndClass(0),
               _T("Draw Window"),
               WS_POPUP | WS_VISIBLE,
               0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
               parent, (HMENU)0);
	InitPoints();

	timer = SetTimer(1,100,0);
}

void CDraw::InitPoints()
{
	CRect clientRect;
    GetClientRect(&clientRect);
	for(int i = 0; i<100; i++){points[i].x = clientRect.Width()/2;points[i].y = clientRect.Height()/2;}
}

BEGIN_MESSAGE_MAP(CDraw, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()




// Gestionnaires de messages de CDraw



void CDraw::OnPaint()
{

	CPaintDC dc(this); // device context for painting
	CRect clientRect;
    GetClientRect(&clientRect);
    dc.FillSolidRect(&clientRect, RGB(0, 0, 0));

	CPen* oldPen;
	oldPen = dc.SelectObject(pen);
	dc.Polyline(points,nech>100?100:nech);
	dc.SelectObject(oldPen);
}

void CDraw::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
		case VK_ESCAPE:
			DestroyWindow();
			break;
		case VK_F1:
			if(pen == &red)pen = &white;
			else pen = &red;
			break;
		case VK_F2:
			if(pen == &green)pen = &white;
			else pen = &green;
			break;
		case VK_F3:
			if(pen == &blue)pen = &white;
			else pen = &blue;
			break;
		case VK_F12:
			if(timer){KillTimer(timer);timer = 0;}
			else timer = SetTimer(1,100,0);
			break;
		case VK_DELETE:
			nech = 0;
			break;
		default:
			CWnd::OnKeyUp(nChar, nRepCnt, nFlags);
			break;
	}
}
void CDraw::OnTimer(UINT_PTR nIDEvent)
{
	CRect r;
	GetClientRect(&r);
	short xyz[3];
	if(sensor->ReadAcc(xyz))
	{
		points[nech%100].x = -xyz[0]+r.Width()/2;
		points[nech%100].y = -xyz[1]+r.Height()/2;
		nech++;
		Invalidate();
	}
	else {
		KillTimer(timer);
		MessageBox(_T("Error"),_T("No Sensor"),MB_OK | MB_ICONWARNING);
	}
	CWnd::OnTimer(nIDEvent);
}
