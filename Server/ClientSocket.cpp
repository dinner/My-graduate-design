// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ClientSocket.h"
#include "ServerDlg.h"

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

/***********************************************
Function:		OnReceive
Descriptioin:	socket接收到数据后的处理函数
Input:			
Return:
Others:
***********************************************/
void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pDlg->ProcessReceive(this);
	CSocket::OnReceive(nErrorCode);
}

/***********************************************
Function:		OnReceive
Descriptioin:	设置主对话框指针指向
Input:			dlg:主对话框指针
Return:
Others:
***********************************************/
void CClientSocket::setDlg(CServerDlg *dlg)
{
	m_pDlg = dlg;
}
