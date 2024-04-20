
// AccView.cpp : D�finit les comportements de classe pour l'application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "AccView.h"
#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAccViewApp

BEGIN_MESSAGE_MAP(CAccViewApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CAccViewApp::OnAppAbout)
END_MESSAGE_MAP()


// construction CAccViewApp

CAccViewApp::CAccViewApp()
{

	// TODO�: ajoutez ici du code de construction,
	// Placez toutes les initialisations significatives dans InitInstance
}

// Seul et unique objet CAccViewApp

CAccViewApp theApp;


// initialisation de CAccViewApp

BOOL CAccViewApp::InitInstance()
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// Initialisation standard
	// Si vous n'utilisez pas ces fonctionnalit�s et que vous souhaitez r�duire la taille
	// de votre ex�cutable final, vous devez supprimer ci-dessous
	// les routines d'initialisation sp�cifiques dont vous n'avez pas besoin.
	// Changez la cl� de Registre sous laquelle nos param�tres sont enregistr�s
	// TODO : modifiez cette cha�ne avec des informations appropri�es,
	// telles que le nom de votre soci�t� ou organisation
	SetRegistryKey(_T("Applications locales g�n�r�es par AppWizard"));

	// Pour cr�er la fen�tre principale, ce code cr�e un nouvel objet fen�tre frame
	// qu'il d�finit ensuite en tant qu'objet fen�tre principale de l'application
	CMainFrame* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// cr�e et charge le frame avec ses ressources
	pFrame->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL,
		NULL);






	// La seule fen�tre a �t� initialis�e et peut donc �tre affich�e et mise � jour
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	// appelle DragAcceptFiles uniquement s'il y a un suffixe
	//  Dans une application SDI, cet appel doit avoir lieu juste apr�s ProcessShellCommand
	return TRUE;
}


// gestionnaires de messages pour CAccViewApp




// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// Commande App pour ex�cuter la bo�te de dialogue
void CAccViewApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// gestionnaires de messages pour CAccViewApp



