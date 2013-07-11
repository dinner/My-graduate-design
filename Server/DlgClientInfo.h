#if !defined(AFX_DLGCLIENTINFO_H__DAD86EE2_F093_47AD_8FC5_411B73A25C22__INCLUDED_)
#define AFX_DLGCLIENTINFO_H__DAD86EE2_F093_47AD_8FC5_411B73A25C22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgClientInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgClientInfo dialog
class CServerDlg;
class CDlgClientInfo : public CDialog
{
// Construction
public:
	CDlgClientInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgClientInfo)
	enum { IDD = IDD_DLG_CLIENTINFO };
	CListCtrl	m_ListInfo;
	//}}AFX_DATA
public:
	CServerDlg* m_pDlg;
	HACCEL m_hAcc;

public:
	void InitList();				//用户信息的LIST的初始化
	void setDlg(CServerDlg* dlg);	//设置主对话框指针指向

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgClientInfo)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgClientInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnRclickListClientinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemAdd();
	afx_msg void OnMenuitemDel();
	afx_msg void OnMenuitemModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCLIENTINFO_H__DAD86EE2_F093_47AD_8FC5_411B73A25C22__INCLUDED_)
