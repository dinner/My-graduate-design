#if !defined(AFX_DLGINFO_H__C2A86B84_9204_4645_AD5F_B632EF95742C__INCLUDED_)
#define AFX_DLGINFO_H__C2A86B84_9204_4645_AD5F_B632EF95742C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo dialog
class CDlgClientInfo;
class CDlgInfo : public CDialog
{
// Construction
public:
	
	void setDlg(CDlgClientInfo* dlg);
	CDlgInfo(CWnd* pParent = NULL);   // standard constructor
	
public:
	CDlgClientInfo* m_pDlg;		//连接对话框指针
	BOOL m_bIsAdd;				//是否是增加用户
// Dialog Data
	//{{AFX_DATA(CDlgInfo)
	enum { IDD = IDD_DLG_INFO };
	CString	m_strNick;
	CString	m_strAge;
	CString	m_strPass;
	CString m_strID;
	CString m_strSex;
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
	virtual BOOL OnInitDialog();
	afx_msg void OnButConferm();
	afx_msg LRESULT ModifyUpdate(WPARAM wParam,LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINFO_H__C2A86B84_9204_4645_AD5F_B632EF95742C__INCLUDED_)
