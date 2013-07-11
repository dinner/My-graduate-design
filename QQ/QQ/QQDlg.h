// QQDlg.h : header file
//

#if !defined(AFX_QQDLG_H__7EA706B3_7E28_4CF2_9CD8_93836B92EAC9__INCLUDED_)
#define AFX_QQDLG_H__7EA706B3_7E28_4CF2_9CD8_93836B92EAC9__INCLUDED_
#include "ClientSocket.h"
#include <map>
#include<WINDOWS.H>
#include "Talk.h"
#include "type.h"
#include "stdafx.h"
#include <mmsystem.h>
#include <afxmt.h>
using namespace std; 
#if _MSC_VER > 1000
#pragma once
#pragma comment(lib,"winmm.lib")
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQQDlg dialog
class CLogin;
class CQQDlg : public CDialog
{
// Construction
public:
	map<CString,CTalk*> m_mTalkDlgList;
	BOOL m_IsCreated;
	CImageList m_ImageList;
//	int m_Diacount;

	UINT port;
	CString IP;
	CLogin * m_Ldlg;
	CClientSocket  m_psocket;
	HTREEITEM htOnline;
	CQQDlg(CWnd* pParent = NULL);	// standard constructor

// 	char m_cbufferIN[MAX_BUFFER_SIZE];
// 	char m_cbufferOut[MAX_BUFFER_SIZE];
// 	WAVEHDR m_hWaveHdIn,m_hWaveHdOut;
// 	WAVEFORMATEX m_waveformout;
// 	WAVEFORMATEX m_waveformin;
// 	HWAVEOUT hWaveOut;
// 	HWAVEIN hWaveIn;
 	BOOL m_bIsConnect;				//是否连接
	BOOL m_bIsExpand;				//根节点是否展开
// 	BOOL m_bIsStartRecord;

public:
	void InitTree();
	void Handle(CClientSocket *psocket,Pag pag);	//收到消息后不同消息的处理
	void Receive(CClientSocket *psocket);			//收到消息后的处理
// Dialog Data
	//{{AFX_DATA(CQQDlg)
	enum { IDD = IDD_QQ_DIALOG };
	CComboBox	m_condition;
	CTreeCtrl	m_tree;
	CString	m_nick;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQQDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnSelchangeCombo();
	afx_msg void OnButRegist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QQDLG_H__7EA706B3_7E28_4CF2_9CD8_93836B92EAC9__INCLUDED_)
