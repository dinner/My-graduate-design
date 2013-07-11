// UserSet.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "UserSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserSet

IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUserSet)
	m_ID = 0;
	m_NICK = _T("");
	m_PASS = 0;
	m_SEX = _T("");
	m_AGE = 0;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUserSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=UserData");
}

CString CUserSet::GetDefaultSQL()
{
	return _T("[User]");
}

void CUserSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUserSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Int(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[NICK]"), m_NICK);
	RFX_Long(pFX, _T("[PASS]"), m_PASS);
	RFX_Text(pFX, _T("[SEX]"), m_SEX);
	RFX_Long(pFX, _T("[AGE]"), m_AGE);
	RFX_Date(pFX, _T("[REGISTERTIME]"), m_REGISTERTIME);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUserSet diagnostics

#ifdef _DEBUG
void CUserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
