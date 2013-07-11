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
Descriptioin:	主对话框初始化函数，初始化
				LIST控件，添加几个column
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

	m_ListLink.InsertColumn(0,"账号",LVCFMT_CENTER,50);
	m_ListLink.InsertColumn(1,"昵称",LVCFMT_CENTER,60);
	m_ListLink.InsertColumn(2,"状态",LVCFMT_CENTER,80);
	m_ListLink.InsertColumn(3,"上线时间",LVCFMT_CENTER,80);
	m_ListLink.InsertColumn(4,"下线时间",LVCFMT_CENTER,80);

	m_iPort = 4000;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/***************************************
Function:		OnButLink
Descriptioin:	建立连接
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
		m_psocket->Create(m_iPort);										//建立连接套接字
		m_psocket->Listen(5);											//监听
		((CButton*)GetDlgItem(IDC_BUT_LINK))->SetWindowText("断开连接");//点击“建立连接”后BUTTON文字改变为“断开连接”
		m_bIsCreate = TRUE;												//已经建立连接
	}
	else
	{
		CServerSocket* m_psocket = &m_pDlg->m_Socket;
		m_psocket->Close();												//关闭连接
		((CButton*)GetDlgItem(IDC_BUT_LINK))->SetWindowText("建立连接");//点击“断开连接”后BUTTON文字改变为“建立连接”
		m_bIsCreate = FALSE;											//连接未建立
	}
}

/***************************************
Function:		setDlg
Descriptioin:	设置主对话框指针指向
Input:			dlg：形参
Return:
Others:
****************************************/
void CDlgClientLink::setDlg(CServerDlg *dlg)
{
	m_pDlg = dlg;
}

/***************************************
Function:		OnRclickListClientonoff
Descriptioin:	鼠标右键点击LIST的响应函数
Input:			
Return:
Others:
****************************************/
void CDlgClientLink::OnRclickListClientonoff(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CPoint pt;
	GetCursorPos(&pt);
	/*设置右键点击出来的菜单*/
	CMenu menu;
	menu.LoadMenu(IDR_MENU_LINK);
	CMenu* popmenu;
	popmenu = menu.GetSubMenu(0);
	popmenu->TrackPopupMenu(TPM_RIGHTBUTTON,pt.x,pt.y,this);
	*pResult = 0;
}

/***************************************
Function:		OnRclickListClientonoff
Descriptioin:	点击清空执行的操作，即清
				空LIST的内容
Input:			
Return:
Others:
****************************************/
void CDlgClientLink::OnMenuitemClear() 
{
	// TODO: Add your command handler code here
	m_ListLink.DeleteAllItems();
}
