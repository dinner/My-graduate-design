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
	CServerDlg* m_pDlg;		//���Ի���ָ��
	u_short m_port;			//�׽��ֶ˿ں�
	struct in_addr m_addr;	//�׽���IP��ַ
	CString m_ClientNick;	//�׽��ֶ�Ӧ���û����ǳ�

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
