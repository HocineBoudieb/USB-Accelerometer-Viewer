#pragma once
#include "AccSensor.h"

// CDraw

class CDraw : public CWnd
{
	DECLARE_DYNAMIC(CDraw)

	UINT_PTR timer;
	CPoint points[100];
	CPen* pen;
	CPen red;
	CPen blue;
	CPen green;
	CPen white;
	bool track;
	AccSensor* sensor;
	size_t nech;

public:
	CDraw(AccSensor* _sensor);
	virtual ~CDraw();
	void ShowFull(HWND parent);
	void InitPoints();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};