// UserFriend.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "UserFriend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserFriend

IMPLEMENT_DYNAMIC(CUserFriend, CRecordset)

CUserFriend::CUserFriend(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUserFriend)
	m_NUM = 0;
	m_UFID = 0;
	m_UFNICK = _T("");
	m_UFFID = 0;
	m_UFFNICK = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUserFriend::GetDefaultConnect()
{
	return _T("ODBC;DSN=UserData");
}

CString CUserFriend::GetDefaultSQL()
{
	return _T("[UserFriend]");
}

void CUserFriend::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUserFriend)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[NUM]"), m_NUM);
	RFX_Int(pFX, _T("[UFID]"), m_UFID);
	RFX_Text(pFX, _T("[UFNICK]"), m_UFNICK);
	RFX_Int(pFX, _T("[UFFID]"), m_UFFID);
	RFX_Text(pFX, _T("[UFFNICK]"), m_UFFNICK);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUserFriend diagnostics

#ifdef _DEBUG
void CUserFriend::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserFriend::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
