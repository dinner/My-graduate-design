#if !defined(AFX_SERVERSOCKET_H__F3C242A5_F4AC_448A_8E9A_6EABC3EAE7A0__INCLUDED_)
#define AFX_SERVERSOCKET_H__F3C242A5_F4AC_448A_8E9A_6EABC3EAE7A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerSocket.h : header file
//

#include "afxsock.h"
/////////////////////////////////////////////////////////////////////////////
// CServerSocket command target
class CServerDlg;
class CServerSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CServerSocket();
	virtual ~CServerSocket();

	// Overrides
public:
	CServerDlg* m_pDlg;				//住对话框指针
	void setDlg(CServerDlg* dlg);	//设置指针指向
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERSOCKET_H__F3C242A5_F4AC_448A_8E9A_6EABC3EAE7A0__INCLUDED_)
