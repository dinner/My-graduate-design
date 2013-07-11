// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "ClientSocket.h"
#include "QQDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_QDlg->Receive(this);
	CSocket::OnReceive(nErrorCode);
}

void CClientSocket::setLoginDlg(CLogin *pdlg)
{
   m_pLDlg = pdlg;
}

void CClientSocket::setQDlg(CQQDlg *dlg)
{
   m_QDlg = dlg;
}  
