#include "DrawWnd.h"
// ChildView.h : interface de la classe CChildView
//


#pragma once
#define MAX_ECH 2000
// fenêtre CChildView

class CChildView : public CWnd, public AccManager
{

// Construction
public:
	CChildView();

// Attributs
private:
	CPoint Acc3d[3*MAX_ECH];
	char scale;
	UINT_PTR timer;
	int timecpt;
	AccSensor* sensors;
	CDraw* draw;
	// Opérations
private:
	void InitTab();
// Substitutions
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implémentation
public:
	virtual ~CChildView();

	// Fonctions générées de la table des messages
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnZoomIn();
	afx_msg void OnZoomOut();
	afx_msg void OnRead();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStart();
	afx_msg void OnDraw();
	afx_msg void OnSave();
};

