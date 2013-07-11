#if !defined(AFX_CLIENTSOCKET_H__F4C14A7F_7817_4F87_B5B0_CC2035017673__INCLUDED_)
#define AFX_CLIENTSOCKET_H__F4C14A7F_7817_4F87_B5B0_CC2035017673__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//

#include "afxsock.h"

/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target
class CServerDlg;
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
	CServerDlg* m_pDlg;		//主对话框指针
	u_short m_port;			//套接字端口号
	struct in_addr m_addr;	//套接字IP地址
	CString m_ClientNick;	//套接字对应的用户的昵称

	void setDlg(CServerDlg* dlg);
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

#endif // !defined(AFX_CLIENTSOCKET_H__F4C14A7F_7817_4F87_B5B0_CC2035017673__INCLUDED_)
