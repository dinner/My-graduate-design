#if !defined(AFX_CLIENTSOCKET_H__030A1775_659B_4389_8680_9E56DD83BACC__INCLUDED_)
#define AFX_CLIENTSOCKET_H__030A1775_659B_4389_8680_9E56DD83BACC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//


#include   "afxsock.h "
#include "Login.h"
/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	CQQDlg *m_QDlg;
	void setQDlg(CQQDlg *dlg);
	CLogin *m_pLDlg;
	void setLoginDlg(CLogin *pdlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__030A1775_659B_4389_8680_9E56DD83BACC__INCLUDED_)
