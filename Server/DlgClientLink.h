#if !defined(AFX_DLGCLIENTLINK_H__B57D516A_AF20_424E_AF82_982A26CC835A__INCLUDED_)
#define AFX_DLGCLIENTLINK_H__B57D516A_AF20_424E_AF82_982A26CC835A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgClientLink.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgClientLink dialog
class CServerDlg;
class CDlgClientLink : public CDialog
{
// Construction
public:
	CDlgClientLink(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgClientLink)
	enum { IDD = IDD_DLG_CLIENTLINK };
	CListCtrl	m_ListLink;
	int		m_iPort;
	//}}AFX_DATA
public:
	void setDlg(CServerDlg* dlg);
	BOOL m_bIsCreate;			//连接是否建立
	CServerDlg* m_pDlg;			//主对话框

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgClientLink)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgClientLink)
	virtual BOOL OnInitDialog();
	afx_msg void OnButLink();
	afx_msg void OnRclickListClientonoff(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCLIENTLINK_H__B57D516A_AF20_424E_AF82_982A26CC835A__INCLUDED_)
