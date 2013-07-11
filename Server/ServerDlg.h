// ServerDlg.h : header file
//
/***************************************************
Copyright 2013
File name:		ServerDlg.h
Author:			zhanglingxiang
Description:	服务端主对话框。该对话框中的TAB页中
				有两个页面，分别是用户信息和用户连接
				信息页面
Others:
FunctionList:
***************************************************/
#if !defined(AFX_SERVERDLG_H__675B2D32_E302_489A_A64D_4CF21689DCF4__INCLUDED_)
#define AFX_SERVERDLG_H__675B2D32_E302_489A_A64D_4CF21689DCF4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ServerSocket.h"
#include "ClientSocket.h"
#include "type.h"
#include <vector>
#include <algorithm>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog
class CDlgClientInfo;
class CDlgClientLink;
class CServerDlg : public CDialog
{
// Construction
public:
	CServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CServerDlg)
	enum { IDD = IDD_SERVER_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	public:
		CDlgClientLink* m_pTabDlgLink;		//连接TAB页
		CDlgClientInfo* m_pTabDlgInfo;		//用户信息TAB页
		BOOL m_bIsInit;						//初始化窗口是否完成
		BOOL m_bIsCreate;					//连接是否建立
		CPtrList m_connectionList;			//存储连接socket的结构
		CServerSocket m_Socket;				//监听套接字
		vector<CString> m_vStrOnline;		//在线用户

	public:

		void DataHandle(CClientSocket* pSocket,Pag sPag);		//接受到数据后处理
		void ProcessReceive(CClientSocket* pSocket);			//socket接受到数据
		void ProcessAccept();									//接收到连接后的处理
		void ShowTabDlg(UINT nItem);							//TAB页显示
		void MsgStateHandle(Pag sPag);							//处理用户状态改变
		void MsgLoginHandle(CClientSocket* pSocket,Pag sPag);	//处理用户登录
		void MsgRegistHandle(CClientSocket* pSocket,Pag sPag);	//处理用户注册
		void MsgToIndHandle(Pag sPag);							//处理用户之间数据传输
		void MsgOnHandle(Pag sPag);								//处理用户上线
		void MsgOffHandle(Pag sPag);							//处理用户下线
		void SendToAll(Pag sPag);								//发送给全部用户
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabMenu(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERDLG_H__675B2D32_E302_489A_A64D_4CF21689DCF4__INCLUDED_)
