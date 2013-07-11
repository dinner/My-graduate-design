#if !defined(AFX_USERFRIEND_H__8786FC7C_10D0_4D38_AA65_CD7EAAB70B47__INCLUDED_)
#define AFX_USERFRIEND_H__8786FC7C_10D0_4D38_AA65_CD7EAAB70B47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserFriend.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserFriend recordset

class CUserFriend : public CRecordset
{
public:
	CUserFriend(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserFriend)

// Field/Param Data
	//{{AFX_FIELD(CUserFriend, CRecordset)
	long	m_NUM;
	int		m_UFID;
	CString	m_UFNICK;
	int		m_UFFID;
	CString	m_UFFNICK;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserFriend)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERFRIEND_H__8786FC7C_10D0_4D38_AA65_CD7EAAB70B47__INCLUDED_)
