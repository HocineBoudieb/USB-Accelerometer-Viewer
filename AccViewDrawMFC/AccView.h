
// AccView.h�: fichier d'en-t�te principal pour l'application AccView
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CAccViewApp:
// Consultez AccView.cpp pour l'impl�mentation de cette classe
//

class CAccViewApp : public CWinApp
{
public:
	CAccViewApp();


// Substitutions
public:
	virtual BOOL InitInstance();

// Impl�mentation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAccViewApp theApp;
