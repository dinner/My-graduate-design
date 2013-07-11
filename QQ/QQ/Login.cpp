// Login.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "Login.h"
#include "QQDlg.h"
#include "type.h"
#include "DlgInfo.h"
#include "Login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog

BOOL m_show = TRUE;
CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
	m_port = 0;
	m_pass = 0;
	m_ID = 0;
	//}}AFX_DATA_INIT
//	m_show = FALSE;
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_IPADDRESS, m_ip);
	DDX_Text(pDX, IDC_PORT, m_port);
	DDX_Text(pDX, IDC_PASS, m_pass);
	DDX_Text(pDX, IDC_ID, m_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_BN_CLICKED(IDC_SETTING, OnSetting)
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_STATIC_REGIST, OnStaticRegist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

void CLogin::OnSetting() 
{
	// TODO: Add your control notification handler code here
	if (m_show)
	{
		SettingDlg(m_show);
		m_show = FALSE;
	}
	else
	{
		SettingDlg(m_show);	
		m_show = TRUE;
	}	
}

void CLogin::SettingDlg(BOOL m_show)
{
   	static CRect rectlarge(0,0,0,0);
	static CRect rectsmall(0,0,0,0);
	
	if (rectlarge.IsRectNull())
	{
		CRect rect;
		GetWindowRect(&rectlarge);
		GetDlgItem(IDC_BORDER)->GetWindowRect(&rect);
		rectsmall.left = rectlarge.left;
		rectsmall.top = rectlarge.top;
		rectsmall.right = rectlarge.right;
		rectsmall.bottom = rect.bottom;
	}

	if (m_show)
	{
		SetWindowPos(NULL,0,0,rectlarge.Width(),
		rectlarge.Height(),SWP_NOZORDER|SWP_NOMOVE);
	}
	else
		SetWindowPos(NULL,0,0,rectsmall.Width(),
		rectsmall.Height(),SWP_NOZORDER|SWP_NOMOVE);
}
CBitmapButton m_btlogin;
CBitmapButton m_btsetting;
BOOL CLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowText("用户登录");
	SettingDlg(FALSE);
	// TODO: Add extra initialization here
 //   m_btlogin.LoadBitmaps(IDB_BTLOGIN,NULL,NULL,NULL);
//    m_btlogin.SubclassDlgItem(IDC_LOGIN,this);
//	m_btlogin.SizeToContent();

//	m_btsetting.LoadBitmaps(IDB_SETT,NULL,NULL,NULL);
 //   m_btsetting.SubclassDlgItem(IDC_SETTING,this);
//	m_btsetting.SizeToContent();
    
	m_ip.SetAddress(127,0,0,1);
    m_port = 4000;
	m_ID = 1001;
	m_pass = 111;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLogin::OnLogin() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
    if(m_ID == NULL||m_pass == NULL)
	{
		SetDlgItemText(IDC_STA_TEXT,"用户名和密码不能为空");
	}
	else
	{
		CString strIP;
		m_ip.GetWindowText(strIP);
		
        AfxSocketInit(NULL);
		m_pQDlg->m_psocket.Create();
        BOOL result = m_pQDlg->m_psocket.Connect(strIP,m_port);
        if(!result)
		{
			SetDlgItemText(IDC_STA_TEXT,"连接失败。。。");
			m_pQDlg->m_psocket.Close();
			return;
		}
		else
		{
		//发送消息
		m_pQDlg->m_bIsConnect = TRUE;
		Pag log;
        log.nType = Msg_Login;
        log.ID = m_ID;
		log.nPass = m_pass;
		char *buf = new char[sizeof(log)];
		memcpy(buf,&log,sizeof(log));
		m_pQDlg->m_psocket.Send(buf,sizeof(log));
        
		//接收消息
        m_pQDlg->m_psocket.Receive(buf,sizeof(log));
		memcpy(&log,buf,sizeof(log));
		if(log.nReback == Login_Fail)
		{
			SetDlgItemText(IDC_STA_TEXT,"用户名或密码有误");
			m_pQDlg->m_psocket.Close();
		}
		if(log.nReback == Login_Success)
		{ 
			m_pQDlg->m_nick.Format("%s",log.cNick);
			m_pQDlg->SetDlgItemText(IDC_NICK,m_pQDlg->m_nick);
			SetDlgItemText(IDC_STA_TEXT,"登录成功");
			
			CTreeCtrl* pTree = &m_pQDlg->m_tree;
			CString strFNList;
			CString strFNick;
			CString strSub = " ";
			strFNList.Format("%s",log.cFNickList);
			HTREEITEM hTreeChild;
			for (int i = 0; i < log.nFNum; i++)
			{
				AfxExtractSubString(strFNick,(LPCTSTR)strFNList,i,' ');
				if (log.cFOnline[i] == On_Line)
				{
					hTreeChild = pTree->InsertItem(strFNick,2,2,m_pQDlg->htOnline);
				}
				else
				{
					hTreeChild = pTree->InsertItem(strFNick,3,3,m_pQDlg->htOnline);
				}
			}
			OnOK();
		}
		}
	}
}


void CLogin::setQDlg(CQQDlg *dlg)
{
    m_pQDlg = dlg;
}

void CLogin::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	m_pQDlg->SendMessage(WM_CLOSE);
	CDialog::OnClose();
//	PostMessage(WM_CLOSE);
}



void CLogin::OnStaticRegist() 
{
	// TODO: Add your control notification handler code here
	AfxSocketInit(NULL);
	CDlgInfo dlg;
	CString strIP;
	CString strPort;
	int nPort;
	GetDlgItemText(IDC_IPADDRESS,strIP);
	GetDlgItemText(IDC_PORT,strPort);
	nPort = atoi(strPort);
	dlg.setDlg(this);
	m_pSocket = new CClientSocket();
	m_pSocket->Create();
	if (!m_pSocket->Connect(strIP,nPort))
	{
		SetDlgItemText(IDC_STA_TEXT,"连接失败");
		return;
	}
	Pag sPag;
	sPag.nType = Msg_SRegist;
	char* cBuf = new char[LEN];
	memcpy(cBuf,&sPag,LEN);
	m_pSocket->Send(cBuf,LEN);
	m_pSocket->Receive(cBuf,LEN);
	memcpy(&sPag,cBuf,LEN);
	CString strID;
	strID.Format("%s",sPag.Msg);
	dlg.m_strID = strID;
	dlg.DoModal();
}
