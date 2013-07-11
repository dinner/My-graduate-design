// DlgClientLink.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "DlgClientLink.h"
#include "ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgClientLink dialog


CDlgClientLink::CDlgClientLink(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgClientLink::IDD, pParent)
	,m_bIsCreate(FALSE)
{
	//{{AFX_DATA_INIT(CDlgClientLink)
	m_iPort = 0;
	//}}AFX_DATA_INIT
}


void CDlgClientLink::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgClientLink)
	DDX_Control(pDX, IDC_LIST_CLIENTONOFF, m_ListLink);
	DDX_Text(pDX, IDC_EDIT_PORT, m_iPort);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgClientLink, CDialog)
	//{{AFX_MSG_MAP(CDlgClientLink)
	ON_BN_CLICKED(IDC_BUT_LINK, OnButLink)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_CLIENTONOFF, OnRclickListClientonoff)
	ON_COMMAND(IDC_MENUITEM_CLEAR, OnMenuitemClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgClientLink message handlers

/***************************************
Function:		OnInitDialog
Descriptioin:	���Ի����ʼ����������ʼ��
				LIST�ؼ�����Ӽ���column
Input:			
Return:
Others:
****************************************/
BOOL CDlgClientLink::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwStyle = m_ListLink.GetExtendedStyle();
	dwStyle = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_ONECLICKACTIVATE;
	m_ListLink.SetExtendedStyle(dwStyle);

	m_ListLink.InsertColumn(0,"�˺�",LVCFMT_CENTER,50);
	m_ListLink.InsertColumn(1,"�ǳ�",LVCFMT_CENTER,60);
	m_ListLink.InsertColumn(2,"״̬",LVCFMT_CENTER,80);
	m_ListLink.InsertColumn(3,"����ʱ��",LVCFMT_CENTER,80);
	m_ListLink.InsertColumn(4,"����ʱ��",LVCFMT_CENTER,80);

	m_iPort = 4000;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************
Function:		OnButLink
Descriptioin:	��������
Input:
Return:
Others:
****************************************/
void CDlgClientLink::OnButLink() 
{
	// TODO: Add your control notification handler code here
	if (!m_bIsCreate)
	{
		UpdateData();
		CServerSocket* m_psocket = &m_pDlg->m_Socket;
		m_psocket->Create(m_iPort);										//���������׽���
		m_psocket->Listen(5);											//����
		((CButton*)GetDlgItem(IDC_BUT_LINK))->SetWindowText("�Ͽ�����");//������������ӡ���BUTTON���ָı�Ϊ���Ͽ����ӡ�
		m_bIsCreate = TRUE;												//�Ѿ���������
	}
	else
	{
		CServerSocket* m_psocket = &m_pDlg->m_Socket;
		m_psocket->Close();												//�ر�����
		((CButton*)GetDlgItem(IDC_BUT_LINK))->SetWindowText("��������");//������Ͽ����ӡ���BUTTON���ָı�Ϊ���������ӡ�
		m_bIsCreate = FALSE;											//����δ����
	}
}

/***************************************
Function:		setDlg
Descriptioin:	�������Ի���ָ��ָ��
Input:			dlg���β�
Return:
Others:
****************************************/
void CDlgClientLink::setDlg(CServerDlg *dlg)
{
	m_pDlg = dlg;
}

/***************************************
Function:		OnRclickListClientonoff
Descriptioin:	����Ҽ����LIST����Ӧ����
Input:			
Return:
Others:
****************************************/
void CDlgClientLink::OnRclickListClientonoff(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPoint pt;
	GetCursorPos(&pt);
	/*�����Ҽ���������Ĳ˵�*/
	CMenu menu;
	menu.LoadMenu(IDR_MENU_LINK);
	CMenu* popmenu;
	popmenu = menu.GetSubMenu(0);
	popmenu->TrackPopupMenu(TPM_RIGHTBUTTON,pt.x,pt.y,this);
	*pResult = 0;
}

/***************************************
Function:		OnRclickListClientonoff
Descriptioin:	������ִ�еĲ���������
				��LIST������
Input:			
Return:
Others:
****************************************/
void CDlgClientLink::OnMenuitemClear() 
{
	// TODO: Add your command handler code here
	m_ListLink.DeleteAllItems();
}
