// QQ.h : main header file for the QQ application
//

#if !defined(AFX_QQ_H__EB89E6F9_A4AB_4B3A_B452_7062387A5024__INCLUDED_)
#define AFX_QQ_H__EB89E6F9_A4AB_4B3A_B452_7062387A5024__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQQApp:
// See QQ.cpp for the implementation of this class
//

class CQQApp : public CWinApp
{
public:
	CQQApp();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL
// Implementation

	//{{AFX_MSG(CQQApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQ_H__EB89E6F9_A4AB_4B3A_B452_7062387A5024__INCLUDED_)
