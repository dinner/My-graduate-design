// ServerDlg.h : header file
//
/***************************************************
Copyright 2013
File name:		ServerDlg.h
Author:			zhanglingxiang
Description:	��������Ի��򡣸öԻ����е�TABҳ��
				������ҳ�棬�ֱ����û���Ϣ���û�����
				��Ϣҳ��
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
		CDlgClientLink* m_pTabDlgLink;		//����TABҳ
		CDlgClientInfo* m_pTabDlgInfo;		//�û���ϢTABҳ
		BOOL m_bIsInit;						//��ʼ�������Ƿ����
		BOOL m_bIsCreate;					//�����Ƿ���
		CPtrList m_connectionList;			//�洢����socket�Ľṹ
		CServerSocket m_Socket;				//�����׽���
		vector<CString> m_vStrOnline;		//�����û�

	public:

		void DataHandle(CClientSocket* pSocket,Pag sPag);		//���ܵ����ݺ���
		void ProcessReceive(CClientSocket* pSocket);			//socket���ܵ�����
		void ProcessAccept();									//���յ����Ӻ�Ĵ���
		void ShowTabDlg(UINT nItem);							//TABҳ��ʾ
		void MsgStateHandle(Pag sPag);							//�����û�״̬�ı�
		void MsgLoginHandle(CClientSocket* pSocket,Pag sPag);	//�����û���¼
		void MsgRegistHandle(CClientSocket* pSocket,Pag sPag);	//�����û�ע��
		void MsgToIndHandle(Pag sPag);							//�����û�֮�����ݴ���
		void MsgOnHandle(Pag sPag);								//�����û�����
		void MsgOffHandle(Pag sPag);							//�����û�����
		void SendToAll(Pag sPag);								//���͸�ȫ���û�
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
