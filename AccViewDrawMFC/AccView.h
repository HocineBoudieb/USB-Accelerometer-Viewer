
// AccView.h : fichier d'en-tête principal pour l'application AccView
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// CAccViewApp:
// Consultez AccView.cpp pour l'implémentation de cette classe
//

class CAccViewApp : public CWinApp
{
public:
	CAccViewApp();


// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAccViewApp theApp;
