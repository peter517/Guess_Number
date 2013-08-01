// Guess_Number.h : main header file for the GUESS_NUMBER application
//

#if !defined(AFX_GUESS_NUMBER_H__E31232B6_2DC7_4719_9055_3DE88571F685__INCLUDED_)
#define AFX_GUESS_NUMBER_H__E31232B6_2DC7_4719_9055_3DE88571F685__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGuess_NumberApp:
// See Guess_Number.cpp for the implementation of this class
//

class CGuess_NumberApp : public CWinApp
{
public:
	CGuess_NumberApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuess_NumberApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGuess_NumberApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUESS_NUMBER_H__E31232B6_2DC7_4719_9055_3DE88571F685__INCLUDED_)
