// DlgInfo.cpp : implementation file
//

#include "stdafx.h"
#include "qq.h"
#include "DlgInfo.h"
#include "ClientSocket.h"
#include "type.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo dialog


CDlgInfo::CDlgInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInfo)
	m_strAge = _T("");
	m_strID = _T("");
	m_strNick = _T("");
	m_strPass = _T("");
	//}}AFX_DATA_INIT
}


void CDlgInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInfo)
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_NICK, m_strNick);
	DDX_Text(pDX, IDC_EDIT_PASS, m_strPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgInfo)
	ON_BN_CLICKED(IDC_BUT_CONFERM, OnButConferm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo message handlers

void CDlgInfo::OnButConferm() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if (m_strNick == "")
	{
		MessageBox("昵称不能为空");
		return;
	}
	if (m_strPass == "")
	{
		MessageBox("密码不能为空");
		return;
	}
	if (m_strAge == "")
	{
		MessageBox("年龄不能为空");
		return;
	}
	BOOL bIsCkeck = ((CButton*)GetDlgItem(IDC_RADIO_MAN))->GetCheck();
	m_pSocket = m_pDlgLogin->m_pSocket;
	Pag sPag;
	sPag.nType = Msg_SRegist;
	strcpy(sPag.cNick,m_strNick);
	sPag.ID = atoi(m_strID);
	sPag.nPass = atoi(m_strPass);
	sPag.nAge = atoi(m_strAge);
	sPag.nRegist = 1;
	if (bIsCkeck)
	{
		sPag.nSex = 0;
	}
	else
	{
		sPag.nSex = 1;
	}
	char* cBuf = new char[LEN];
	memcpy(cBuf,&sPag,LEN);
	m_pSocket->Send(cBuf,LEN);
	OnOK();
}

void CDlgInfo::setDlg(CLogin *dlg)
{
	m_pDlgLogin = dlg;
}

BOOL CDlgInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CButton*)GetDlgItem(IDC_RADIO_MAN))->SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


