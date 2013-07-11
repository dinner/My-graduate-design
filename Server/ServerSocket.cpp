// ServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerSocket.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}

/***********************************************
Function:		setDlg
Descriptioin:	设置主对话框指针指向
Input:			dlg:主对话框指针形参
Return:
Others:
***********************************************/
void CServerSocket::setDlg(CServerDlg* dlg)
{
	m_pDlg = dlg;
}
// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CServerSocket, CSocket)
	//{{AFX_MSG_MAP(CServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CServerSocket member functions

/***********************************************
Function:		OnAccept
Descriptioin:	连接套接字接收到连接的处理函数
Input:			
Return:
Others:
***********************************************/
void CServerSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_pDlg->ProcessAccept();
	CSocket::OnAccept(nErrorCode);
}


