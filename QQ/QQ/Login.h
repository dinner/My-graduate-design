#if !defined(AFX_LOGIN_H__B2C5C5BB_4A43_473C_8C32_5A1DF97EA08E__INCLUDED_)
#define AFX_LOGIN_H__B2C5C5BB_4A43_473C_8C32_5A1DF97EA08E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog
class CClientSocket;
class CQQDlg;
class CLogin : public CDialog
{
// Construction
public:
	void setQDlg(CQQDlg *dlg);
	CQQDlg * m_pQDlg;
	void SettingDlg(BOOL m_show);
	CClientSocket* m_pSocket;
//	BOOL m_show;
	CLogin(CWnd* pParent = NULL);   // standard constructor
//    CClientSocket *m_psocket;
// Dialog Data
	//{{AFX_DATA(CLogin)
	enum { IDD = IDD_LOGIN };
	CIPAddressCtrl	m_ip;
	UINT	m_port;
	int		m_pass;
	int		m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogin)
	afx_msg void OnSetting();
	virtual BOOL OnInitDialog();
	afx_msg void OnLogin();
	afx_msg void OnClose();
	afx_msg void OnStaticRegist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_H__B2C5C5BB_4A43_473C_8C32_5A1DF97EA08E__INCLUDED_)
