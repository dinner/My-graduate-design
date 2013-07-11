#if !defined(AFX_DLGVOLUME_H__71D0CEF5_E02C_423A_B455_89834F132410__INCLUDED_)
#define AFX_DLGVOLUME_H__71D0CEF5_E02C_423A_B455_89834F132410__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgVolume.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgVolume dialog
class CTalk;
class CDlgVolume : public CDialog
{
// Construction
public:
	CDlgVolume(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgVolume)
	enum { IDD = IDD_DLG_VOLUME };
	CSliderCtrl	m_Pitch;
	CSliderCtrl	m_Volume;
	//}}AFX_DATA

public:
	CTalk* m_pDlgTalk;

public:
	void setDlg(CTalk* dlg);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgVolume)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgVolume)
	afx_msg void OnClose();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVOLUME_H__71D0CEF5_E02C_423A_B455_89834F132410__INCLUDED_)
