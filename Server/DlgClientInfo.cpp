// DlgClientInfo.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "DlgClientInfo.h"
#include "ServerDlg.h"
#include "UserSet.h"
#include "DlgInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgClientInfo dialog


CDlgClientInfo::CDlgClientInfo(CWnd* pParent /*=NULL*/)
: CDialog(CDlgClientInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgClientInfo)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgClientInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgClientInfo)
	DDX_Control(pDX, IDC_LIST_CLIENTINFO, m_ListInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgClientInfo, CDialog)
//{{AFX_MSG_MAP(CDlgClientInfo)
ON_NOTIFY(NM_RCLICK, IDC_LIST_CLIENTINFO, OnRclickListClientinfo)
ON_COMMAND(IDC_MENUITEM_ADD, OnMenuitemAdd)
	ON_COMMAND(IDC_MENUITEM_DEL, OnMenuitemDel)
	ON_COMMAND(IDC_MENUITEM_MODIFY, OnMenuitemModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgClientInfo message handlers
/***************************************
Function:		OnInitDialog
Descriptioin:	�Ի����ʼ��
Return:
Others:
****************************************/
BOOL CDlgClientInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_hAcc = LoadAccelerators(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDR_ACCELERATOR));
	
	InitList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************
Function:		OnRclickListClientinfo
Descriptioin:	��LIST�е������Ҽ�����
				�˵�ѡ��ֱ��������޸�
				ɾ�������Զ��û���Ϣ����
				��Ӧ����
Input:
Return:
Others:
****************************************/
void CDlgClientInfo::OnRclickListClientinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPoint pt;
	GetCursorPos(&pt);
	CMenu menu;
	menu.LoadMenu(IDR_MENU_INFO);
	CMenu* popmenu;
	popmenu = menu.GetSubMenu(0);
	popmenu->TrackPopupMenu(TPM_RIGHTBUTTON,pt.x,pt.y,this);
	*pResult = 0;
}

/***************************************
Function:		setDlg
Descriptioin:	����m_pDlgָ��ָ��ʹ��
				ָ��ǰ���Ի���
Input:			���Ի���ָ��
Return:
Others:
****************************************/
void CDlgClientInfo::setDlg(CServerDlg* dlg)
{
	m_pDlg = dlg;
}

/***************************************
Function:		InitList
Descriptioin:	��ʼ��LIST�ؼ�������˺�
				�ǳơ�����״̬������ʱ��
				����ʱ�伸��Column
Input:			
Return:
Others:
****************************************/
void CDlgClientInfo::InitList()
{
	DWORD dwStyle = m_ListInfo.GetExtendedStyle();
	dwStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_ONECLICKACTIVATE;
	m_ListInfo.SetExtendedStyle(dwStyle);
	
	m_ListInfo.InsertColumn(0,_T("�˺�"),LVCFMT_CENTER,60);
	m_ListInfo.InsertColumn(1,_T("�ǳ�"),LVCFMT_CENTER,60);
	m_ListInfo.InsertColumn(2,_T("����"),LVCFMT_CENTER,60);
	m_ListInfo.InsertColumn(3,_T("ע��ʱ��"),LVCFMT_CENTER,100);
	
	CUserSet oUserData;
	CString strsql;
	CString strID;
	CString strPass;
	CString strTime;
	int iIndex = 0;
	strsql.Format("select* from user");
	oUserData.Open(AFX_DB_USE_DEFAULT_TYPE,strsql);
	while (!oUserData.IsEOF())
	{
		strID.Format("%d",oUserData.m_ID);
		strPass.Format("%d",oUserData.m_PASS);
		strTime = oUserData.m_REGISTERTIME.Format("%Y/%m/%d");
		m_ListInfo.InsertItem(iIndex,strID);
		m_ListInfo.SetItemText(iIndex,1,oUserData.m_NICK);
		m_ListInfo.SetItemText(iIndex,2,strPass);
		m_ListInfo.SetItemText(iIndex,3,strTime);
		iIndex++;
		oUserData.MoveNext();
	}
	oUserData.Close();
}

/***************************************
Function:		OnMenuitemAdd
Descriptioin:	�����Ӳ˵�ѡ��ִ�����
				�û�����
Input:			
Return:
Others:
****************************************/
void CDlgClientInfo::OnMenuitemAdd() 
{
	// TODO: Add your command handler code here
	CDlgInfo* pDlgInfo = new CDlgInfo();
	pDlgInfo->m_bIsAdd = TRUE;
	pDlgInfo->setDlg(this);
	pDlgInfo->Create(IDD_DLG_INFO,this);
	pDlgInfo->ShowWindow(SW_SHOW);
}


BOOL CDlgClientInfo::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (!m_hAcc)
	{
		if (TranslateAccelerator(m_hWnd,m_hAcc,pMsg))
		{
			return TRUE;
		}
	}
	   return CDialog::PreTranslateMessage(pMsg);
}

/***************************************
Function:		OnMenuitemDel
Descriptioin:	���ɾ���˵�ѡ��ִ��ɾ��
				��Ӧ�û�����
Input:			
Return:
Others:
****************************************/
void CDlgClientInfo::OnMenuitemDel() 
{
	// TODO: Add your command handler code here
	CString strID;
	int nIndex = m_ListInfo.GetNextItem(-1, LVNI_SELECTED);
	strID = m_ListInfo.GetItemText(nIndex,0);
	m_ListInfo.DeleteItem(nIndex);

	CDatabase oDatabase;
	oDatabase.OpenEx(_T("DSN=UserData"),CDatabase::noOdbcDialog);
	CRecordset recset(&oDatabase);
	CString strSQL;
	strSQL.Format("delete from user where ID = %d",atoi(strID));
	oDatabase.ExecuteSQL(strSQL);
	oDatabase.Close();
}

/***************************************
Function:		OnMenuitemModify
Descriptioin:	����޸Ĳ˵�ѡ��ִ���޸�
				��Ӧ�û�����
Input:			
Return:
Others:
****************************************/
void CDlgClientInfo::OnMenuitemModify() 
{
	// TODO: Add your command handler code here
	int nIndex = m_ListInfo.GetNextItem(-1,LVNI_SELECTED);
	if (nIndex == -1)
	{
		return;
	}
	CString strID = "";
	strID = m_ListInfo.GetItemText(nIndex,0);
	CDlgInfo* oDlgInfo = new CDlgInfo();
	oDlgInfo->m_bIsAdd = FALSE;
	oDlgInfo->setDlg(this);
	oDlgInfo->Create(IDD_DLG_INFO,this);
	CString strSQL;
	strSQL.Format("select *from user where ID = %d",atoi(strID));
	::SendMessage(oDlgInfo->m_hWnd,WM_MODIFY,0,(LPARAM)&strSQL);
	oDlgInfo->ShowWindow(SW_SHOW);
}
