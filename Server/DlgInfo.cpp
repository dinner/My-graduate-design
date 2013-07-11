// DlgInfo.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "DlgInfo.h"
#include "DlgClientInfo.h"

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
	m_strNick = _T("");
	m_strAge = _T("");
	m_strPass = _T("");
	m_strSex = _T("");
	m_bIsAdd = FALSE;
	//}}AFX_DATA_INIT
}


void CDlgInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInfo)
	DDX_Text(pDX, IDC_EDIT_NICK, m_strNick);
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_Text(pDX, IDC_EDIT_PASS, m_strPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgInfo)
	ON_BN_CLICKED(IDC_BUT_CONFERM, OnButConferm)
	ON_MESSAGE(WM_MODIFY,ModifyUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInfo message handlers

/***************************************
Function:		OnInitDialog
Descriptioin:	�Ի����ʼ�����������ݲ���
				�������öԻ�������
Input:			
Return:
Others:
****************************************/
BOOL CDlgInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strOper;
	if (m_bIsAdd)
	{
		strOper.Format("���");
	}
	else
	{
		strOper.Format("�޸�");
	}
	SetWindowText(strOper);
	SetDlgItemText(IDC_BUT_CONFERM,strOper);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************
Function:		setDlg
Descriptioin:	�����û�������Ϣ�Ի���ָ
				��ָ��
Input:			dlg:�û�������Ϣ�Ի���ָ
				��
Return:
Others:
****************************************/
void CDlgInfo::setDlg(CDlgClientInfo *dlg)
{
	m_pDlg = dlg;
}

/***************************************
Function:		OnButConferm
Descriptioin:	�����ȷ������ť��Ĳ���
				����
Input:			
Return:
Others:
****************************************/
void CDlgInfo::OnButConferm() 
{
	// TODO: Add your control notification handler code here
	CString strNick;
	strNick = m_strNick;

	CDatabase oDatabase;
	oDatabase.OpenEx(_T("DSN=UserData"),CDatabase::noOdbcDialog);
	CRecordset recset(&oDatabase);

	UpdateData();
	CString strWin("");
	GetWindowText(strWin);
	if (m_strNick == "")
	{
		MessageBox("�ǳƲ���Ϊ��");
		return;
	}
	if (m_strPass == "")
	{
		MessageBox("���벻��Ϊ��");
		return;
	}
	if (m_strAge == "")
	{
		MessageBox("���䲻��Ϊ��");
		return;
	}
	CString strSex = "";
	BOOL bIsCkeck = ((CButton*)GetDlgItem(IDC_RADIO_MAN))->GetCheck();
	if (bIsCkeck)
	{
		strSex = "��";
	}
	else
	{
		strSex = "Ů";
	}
	if (strWin == "���")
	{
		int nID;
		CListCtrl* pList = &m_pDlg->m_ListInfo;
		int nIndex = 0;
		CTime tTime = CTime::GetCurrentTime();
		CString strTime = tTime.Format("%Y/%m/%d");
		nIndex = pList->GetItemCount();
		nIndex = atoi(pList->GetItemText(nIndex-1,0)) + 1;
		CString strSQL = "";
		strSQL.Format("insert into user (ID,NICK,PASS,SEX,AGE,REGISTERTIME) values(%d,'%s',%d,'%s',%d,'%s')",nIndex,m_strNick,atoi(m_strPass),strSex,atoi
			(m_strAge),strTime);
		oDatabase.ExecuteSQL(strSQL);
		oDatabase.Close();	
		CString strID;
		int nRow;
		strID.Format("%d",nIndex);
		nRow = pList->GetItemCount();
		pList->InsertItem(nRow,strID);
		pList->SetItemText(nRow,1,m_strNick);
		pList->SetItemText(nRow,2,m_strPass);
		pList->SetItemText(nRow,3,strTime);
	}
	else
	{
		CString strSQL;
		strSQL.Format("update user set NICK = '%s',PASS = '%d',SEX = '%s',AGE = '%d' where NICK = '%s'",m_strNick,atoi(m_strPass),strSex,atoi
			(m_strAge),strNick);
		oDatabase.ExecuteSQL(strSQL);
		oDatabase.Close();
		CListCtrl* pList = &m_pDlg->m_ListInfo;
		int nIndex = pList->GetNextItem(-1,LVNI_SELECTED);
		pList->SetItemText(nIndex,1,m_strNick);
		pList->SetItemText(nIndex,2,m_strPass);
	}
	OnOK();
}

/***************************************
Function:		ModifyUpdate
Descriptioin:	�޸��û�����
Input:			
Return:
Others:
****************************************/
LRESULT CDlgInfo::ModifyUpdate(WPARAM wParam,LPARAM lParam)
{
	CDatabase oDataBase;
	oDataBase.OpenEx(_T("DSN=UserData"),CDatabase::noOdbcDialog);
	CRecordset recset(&oDataBase);
	CString strSQL("");
	strSQL = *(CString*)lParam;
	recset.Open(CRecordset::forwardOnly,strSQL,CRecordset::readOnly);
	CString strTemp = "";
	while(!recset.IsEOF())
	{
		recset.GetFieldValue("NICK",strTemp);
		m_strNick = strTemp;
		recset.GetFieldValue("PASS",strTemp);
		m_strPass = strTemp;
		recset.GetFieldValue("SEX",strTemp);
		m_strSex = strTemp;
		recset.GetFieldValue("AGE",strTemp);
		m_strAge = strTemp;
		recset.MoveNext();
	}
	if (m_strSex == "��")
	{
		((CButton*)GetDlgItem(IDC_RADIO_MAN))->SetCheck(1);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO_MAN))->SetCheck(1);
	}
	recset.Close();
	UpdateData(FALSE);
	return 0;
}
