#if !defined(AFX_DLGINFO_H__3F479711_FB27_4C43_8B75_981FC1FC5E16__INCLUDED_)
#define AFX_DLGINFO_H__3F479711_FB27_4C43_8B75_981FC1FC5E16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo dialog
class CClientSocket;
class CLogin;
class CDlgInfo : public CDialog
{
// Construction
public:
	CDlgInfo(CWnd* pParent = NULL);   // standard constructor


public:
	void setDlg(CLogin* dlg);
	CClientSocket* m_pSocket;
	CLogin* m_pDlgLogin;
// Dialog Data
	//{{AFX_DATA(CDlgInfo)
	enum { IDD = IDD_DLG_INFO };
	CString	m_strAge;
	CString	m_strID;
	CString	m_strNick;
	CString	m_strPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgInfo)
	afx_msg void OnButConferm();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFO_H__3F479711_FB27_4C43_8B75_981FC1FC5E16__INCLUDED_)
