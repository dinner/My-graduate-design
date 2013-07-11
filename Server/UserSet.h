#if !defined(AFX_USERSET_H__BE681D77_4860_423C_BDF8_3A4E1BACA5F5__INCLUDED_)
#define AFX_USERSET_H__BE681D77_4860_423C_BDF8_3A4E1BACA5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserSet recordset

class CUserSet : public CRecordset
{
public:
	CUserSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserSet)

// Field/Param Data
	//{{AFX_FIELD(CUserSet, CRecordset)
	int		m_ID;
	CString	m_NICK;
	long	m_PASS;
	CString	m_SEX;
	long	m_AGE;
	CTime	m_REGISTERTIME;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserSet)
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

#endif // !defined(AFX_USERSET_H__BE681D77_4860_423C_BDF8_3A4E1BACA5F5__INCLUDED_)
