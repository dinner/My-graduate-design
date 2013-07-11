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
Descriptioin:	�������Ի���ָ��ָ��
Input:			dlg:���Ի���ָ���β�
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
Descriptioin:	�����׽��ֽ��յ����ӵĴ�����
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


