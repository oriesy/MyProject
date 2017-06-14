// WLanOnOff.h : main header file for the WLANONOFF application
//

#if !defined(AFX_WLANONOFF_H__558EB159_4D89_427A_8565_F2933FC06357__INCLUDED_)
#define AFX_WLANONOFF_H__558EB159_4D89_427A_8565_F2933FC06357__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWLanOnOffApp:
// See WLanOnOff.cpp for the implementation of this class
//

class CWLanOnOffApp : public CWinApp
{
public:
	CWLanOnOffApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWLanOnOffApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWLanOnOffApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WLANONOFF_H__558EB159_4D89_427A_8565_F2933FC06357__INCLUDED_)
