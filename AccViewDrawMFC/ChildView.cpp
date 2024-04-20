// ChildView.cpp : implémentation de la classe CChildView
//

#include "stdafx.h"
#include "AccView.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView():scale(1),timer(0),timecpt(0)
{
	CChildView::InitTab();
}

CChildView::~CChildView()
{
	if(timer)KillTimer(timer);
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_ZOOM_IN, &CChildView::OnZoomIn)
	ON_COMMAND(ID_ZOOM_OUT, &CChildView::OnZoomOut)
	ON_COMMAND(ID_READ, &CChildView::OnRead)
	ON_WM_TIMER()
	ON_COMMAND(ID_START, &CChildView::OnStart)
	ON_COMMAND(ID_DRAW, &CChildView::OnDraw)
	ON_COMMAND(ID_SAVE, &CChildView::OnSave)
END_MESSAGE_MAP()



// gestionnaires de messages pour CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}
void CChildView::InitTab()
{
	for(int i = 0; i<MAX_ECH;i++)
		for (int j = 0; j<3;j++)
		{Acc3d[i+j*MAX_ECH].x = i; Acc3d[i+j*MAX_ECH].y = 0;}
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); 

	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(1,1);
	dc.SetViewportExt(1,scale);

	CRect WinRect;
	GetClientRect(&WinRect);
	int height = WinRect.Height();
	height/=4;

	CPen pens[3] = {
		CPen (PS_SOLID, 1, RGB(0, 0, 255)), // Bleu
		CPen (PS_SOLID, 1, RGB(0, 255, 0)), // Vert
		CPen (PS_SOLID, 1, RGB(255, 0, 0)), // Rouge
	};
	CPen dots[3] = {
		CPen (PS_DOT, 1, RGB(0, 0, 255)), // Bleu pointillé
		CPen (PS_DOT, 1, RGB(0, 255, 0)), // Vert pointillé
		CPen (PS_DOT, 1, RGB(255, 0, 0)), // Rouge pointillé
	};

	CPen* oldPen;

	for(int i=0; i<3;i++)
	{
		dc.SetViewportOrg(0, (i+1)*height);
		oldPen = dc.SelectObject(&dots[i]);
		
		dc.LineTo(WinRect.right, 0);
		dc.MoveTo(0, G);
		dc.LineTo(WinRect.right,G);
		dc.MoveTo(0, -G);
		dc.LineTo(WinRect.right,-G);
		dc.MoveTo(0, 0);

		oldPen = dc.SelectObject(&pens[i]);
		dc.Polyline(Acc3d+i*MAX_ECH,MAX_ECH);
	}
}


void CChildView::OnZoomIn()
{
	scale++;
	if(scale>8)scale = 8;
	else Invalidate();
}

void CChildView::OnZoomOut()
{
	scale--;
	if(scale<1)scale = 1;
	else Invalidate();
}
void CChildView::OnStart()
{
	timecpt = 0;
	if(timer){ KillTimer(timer);timer = 0;}
	else
	{
		InitTab();
		if(GetNbSensors()){
			sensors = GetSensor(0);
			timer = SetTimer(1,100,0);
		}
	}
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	short xyz[3];
	if(sensors->ReadAcc(xyz))
	{
		Acc3d[timecpt].y =-int(xyz[0]*(float)G/sensors->G_ACC);
		Acc3d[timecpt+MAX_ECH].y =-1*int(xyz[1]*(float)G/sensors->G_ACC);
		Acc3d[timecpt+2*MAX_ECH].y =-1*int(xyz[2]*(float)G/sensors->G_ACC);
	}
	else KillTimer(timer);
	timecpt++;
	CRect r;
	GetClientRect(&r);
	InvalidateRect(CRect(timecpt-5,0,timecpt+5,r.bottom));
}
void CChildView::OnDraw()
{

	if(GetNbSensors())
	{
		CDraw* draw = new CDraw(GetSensor(0));
		draw->ShowFull(GetSafeHwnd());
	}
	else
		MessageBox(_T("Error"),_T("No Sensor"),MB_OK | MB_ICONWARNING);
}
void CChildView::OnSave()
{
	KillTimer(timer);
	timer = 0;
	CFileDialog dlg(false);
	if(dlg.DoModal()==IDOK)
	{
		CString path = dlg.GetPathName();
		CFile file;
		if(file.Open(path,CFile::modeCreate|CFile::modeWrite))
		{
			for(int i = 0; i<timecpt;i++)
			{
				file.Write(&Acc3d[timecpt].y,sizeof(short));
				file.Write(&Acc3d[timecpt+MAX_ECH].y,sizeof(short));
				file.Write(&Acc3d[timecpt+2*MAX_ECH].y,sizeof(short));
			}
			file.Close();
		}
	}
}
void CChildView::OnRead()
{
	CFileDialog dlg(true,_T("*.ech"));
	if(dlg.DoModal()==IDOK)
	{
		InitTab();
		CString path = dlg.GetPathName();
		CFile file(path,CFile::modeRead);
		int _length = file.GetLength();
		for(int i = 0; i<_length;i++)
		{
			for (int j = 0; j<3;j++)
			{
				short acc;
				file.Read(&acc,sizeof(short));
				Acc3d[i+j*MAX_ECH].y = -int(acc*(float)G/sensors->G_ACC);;
			}
		}
		file.Close();
		Invalidate();

	}
}
