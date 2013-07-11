// ServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "ServerDlg.h"
#include "DlgClientInfo.h"
#include "DlgClientLink.h"
#include "UserSet.h"
#include "UserFriend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg dialog

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
: CDialog(CServerDlg::IDD, pParent)
,m_bIsInit(FALSE)
{
	//{{AFX_DATA_INIT(CServerDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerDlg)
	DDX_Control(pDX, IDC_TAB_MENU, m_Tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CServerDlg, CDialog)
//{{AFX_MSG_MAP(CServerDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MENU, OnSelchangeTabMenu)
ON_WM_MOVE()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDlg message handlers

/***************************************
Function:		OnInitDialog
Descriptioin:	对话框初始化
Return:
Others:
****************************************/
BOOL CServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	AfxSocketInit(NULL);
	m_Socket.setDlg(this);								//设置指针指向
	m_pTabDlgInfo = new CDlgClientInfo();
	m_pTabDlgLink = new CDlgClientLink();
	m_pTabDlgInfo->setDlg(this);						//用户信息TAB页指针指向
	m_pTabDlgLink->setDlg(this);						//用户连接信息TAB页指针指向
	m_pTabDlgInfo->Create(IDD_DLG_CLIENTINFO,GetDlgItem(IDC_TAB_MENU));
	m_pTabDlgLink->Create(IDD_DLG_CLIENTLINK,GetDlgItem(IDC_TAB_MENU));
	m_Tab.InsertItem(TCIF_TEXT | TCIF_IMAGE | TCIF_PARAM,0,_T("连接"),0,(LPARAM)m_pTabDlgLink,0,0);
	m_Tab.InsertItem(TCIF_TEXT | TCIF_IMAGE | TCIF_PARAM,1,_T("客户"),0,(LPARAM)m_pTabDlgInfo,0,0);
	m_Tab.SetCurSel(0);
	ShowTabDlg(0);
	m_bIsInit = TRUE;			//初始化完成
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/***********************************************
Function:		ShowTabDlg
Descriptioin:	Tab页切换
Input:			nItme是Tab编号 是0则切换到用户连接对话
框，是1则是用户消息对话框
Return:
Others:
***********************************************/
void CServerDlg::ShowTabDlg(UINT nItem)
{
	CRect rc;
	switch(nItem)
	{
	case 0:
		{
			m_Tab.GetClientRect(&rc);//获得TAB页位置
			ClientToScreen(&rc);	 //获得TAB页坐标
			m_Tab.AdjustRect(FALSE,&rc);
			rc.top += 15;
			m_pTabDlgLink->MoveWindow(&rc);
			m_pTabDlgLink->ShowWindow(SW_SHOW);
			m_pTabDlgInfo->ShowWindow(SW_HIDE);
		}
		break;
	case 1:
		{
			m_Tab.GetClientRect(&rc);//获得TAB页位置
			ClientToScreen(&rc);	//获得TAB页坐标
			m_Tab.AdjustRect(FALSE,&rc);
			rc.top += 15;
			m_pTabDlgInfo->MoveWindow(&rc);
			m_pTabDlgInfo->ShowWindow(SW_SHOW);
			m_pTabDlgLink->ShowWindow(SW_HIDE);
		}
		break;
	}
}

/***********************************************
Function:		OnSelchangeTabMenu
Descriptioin:	选择不同的TAB键显示相应的对话框
Input:			
Return:
Others:
***********************************************/
void CServerDlg::OnSelchangeTabMenu(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UINT nItem = m_Tab.GetCurSel();	//获得TAB的页码
	ShowTabDlg(nItem);				//显示相应的TAB页
	*pResult = 0;
}

void CServerDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	//判断是否初始化，便可以切换TAB页
	if (m_bIsInit)	
	{
		UINT nItem = m_Tab.GetCurSel();
		ShowTabDlg(nItem);
	}
	// TODO: Add your message handler code here
}

/***********************************************
Function:		ProcessAccept
Descriptioin:	socket接收到连接后，将连接socket
的数据记录到CPtrList里面
Input:			
Return:
Others:
***********************************************/
void CServerDlg::ProcessAccept()
{
	SOCKADDR_IN clientaddr;				//连接SOCKET的IP地址
	int addrlen = sizeof(clientaddr);
    
	CClientSocket* psocket = new CClientSocket();	
	this->m_Socket.Accept(*psocket,
		(LPSOCKADDR)&clientaddr, &addrlen);
    
	psocket->m_addr	= clientaddr.sin_addr;
	psocket->m_port = clientaddr.sin_port;
    psocket->setDlg(this);				//设置指针指向
	m_connectionList.AddTail(psocket);
}

/***********************************************
Function:		ProcessReceive
Descriptioin:	连接的套接字接收到数据后对数据进
行处理
Input:			pSocket是发送消息的套接字
Return:
Others:
***********************************************/
void CServerDlg::ProcessReceive(CClientSocket* pSocket)
{
	Pag sPag;
	char* cBuf = new char[LEN];
	pSocket->Receive(cBuf,LEN);
	memcpy(&sPag,cBuf,LEN);
	DataHandle(pSocket,sPag);
}

/***********************************************
Function:		DataHandle
Descriptioin:	连接的套接字接收到数据后对数据进
行处理
Input:			pSocket是发送消息的套接字，sPag
发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::DataHandle(CClientSocket *pSocket, Pag sPag)
{
	char* cBuf = new char[LEN];			 //发送的数据缓冲区
	CString strTime;
	CTime tTime = CTime::GetCurrentTime();
	strTime = tTime.Format("[%H:%M:%S]");//当前时间
	switch(sPag.nType)
	{
	case Msg_Login://登录消息
		MsgLoginHandle(pSocket,sPag);
		break;
	case Msg_SToIn://客户端之间通信
		MsgToIndHandle(sPag);
		break;
	case Msg_SON:  //用户上线通知
		MsgOnHandle(sPag);
		break;
	case Msg_SOFF:	//用户下线通知
		MsgOffHandle(sPag);
		break;
	case Msg_SState://状态切换
		MsgStateHandle(sPag);
		break;
	case Msg_SRegist://注册信息
		MsgRegistHandle(pSocket,sPag);
		break;
	}
}

/***********************************************
Function:		MsgLoginHandle
Descriptioin:	处理用户登录消息，在此函数中客户
端发来账号和密码，服务端在数据库
中进行查找。若找到则返回登录成功
客户端成功登录
Input:			pSocket是发送消息的套接字，sPag
发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::MsgLoginHandle(CClientSocket* pSocket,Pag sPag)
{
	CUserSet oUserSet;
	CString strSQL;
	BOOL bIsLogin = FALSE;
	char* cBuf = new char[LEN];			//发送的数据缓冲区
	memset(cBuf,0,LEN);
	strSQL.Format("select* from User");
	oUserSet.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
	while (!oUserSet.IsEOF())
	{
		//判断是否存在对应的账号和密码
		if (oUserSet.m_ID == sPag.ID && oUserSet.m_PASS == sPag.nPass)
		{
			//查找到有该用户并且登陆成功
			bIsLogin = TRUE;
			strcpy(sPag.cNick,oUserSet.m_NICK);
			break;
		}
		oUserSet.MoveNext();
	}
	oUserSet.Close();
	if (!bIsLogin)						//登录失败
	{
		sPag.nReback = Login_Fail;
		memcpy(cBuf,&sPag,LEN);
		pSocket->Send(cBuf,LEN);
	}
	else								//登录成功 发送登录成功消息
	{
		/*将用户昵称添加到对应用户的SOCKET结构中*/	
		POSITION pos = m_connectionList.GetHeadPosition();
		while (pos)
		{
			CClientSocket* pSock = (CClientSocket*)m_connectionList.GetNext(pos);
			if ((inet_ntoa(pSock->m_addr) == inet_ntoa(pSocket->m_addr))
				&&(ntohs(pSock->m_port) == ntohs(pSocket->m_port)))
			{
				pSock->m_ClientNick.Format("%s",sPag.cNick);
				m_vStrOnline.push_back(sPag.cNick);
				break;
			}
		}
		/**/
		CUserFriend oUserFriend;
		CString strSQL;					//sql语句字符串
		CString strFNList;				//用户的好友列表字符串
		int nFNum = 0;
		strSQL.Format("select* from UserFriend where UFID = %d",sPag.ID);
		oUserFriend.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);//打开数据库
		while (!oUserFriend.IsEOF())	//查找未结束
		{
			strFNList += oUserFriend.m_UFFNICK + " ";
			vector<CString>::iterator result; 
			result = find(m_vStrOnline.begin(),m_vStrOnline.end(),
				oUserFriend.m_UFFNICK);
			if (result == m_vStrOnline.end())
			{
				sPag.cFOnline[nFNum] = Off_Line;
			}
			else
			{
				sPag.cFOnline[nFNum] = On_Line;
			}
			nFNum ++;					//好友数叠加
			oUserFriend.MoveNext();
		}
		oUserSet.Close();				//关闭数据库
		memcpy(sPag.cFNickList,strFNList,sizeof(sPag.cFNickList));
		sPag.nFNum = nFNum;
		
		/*返回验证成功消息*/
		sPag.nReback = Login_Success;
		memcpy(cBuf,&sPag,LEN);
		pSocket->Send(cBuf,LEN);
		
		//添加登录的用户信息到LIST
		CListCtrl* pList = &m_pTabDlgLink->m_ListLink;
		int nIndex = pList->GetItemCount();
		CString strTemp;
		strTemp.Format("%d",sPag.ID);
		pList->InsertItem(nIndex,strTemp);
		strTemp.Format("%s",sPag.cNick);
		pList->SetItemText(nIndex,1,strTemp);
		strTemp.Format("我在线上");
		pList->SetItemText(nIndex,2,strTemp);
		CTime tTime = CTime::GetCurrentTime();
		strTemp = tTime.Format("%H:%M:%S");
		pList->SetItemText(nIndex,3,strTemp);
		
		sPag.nType = Msg_SON;			//上线消息
		SendToAll(sPag);				//通知所有在线用户该用户上线
	}
}

/***********************************************
Function:		MsgToIndHandle
Descriptioin:	客户端之间通信，服务端接受到A用户
发来的数据包，再根据其昵称发送到
目的用户
Input:			sPag发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::MsgToIndHandle(Pag sPag)
{
	CString strFDNick;
	strFDNick.Format("%s",sPag.cFNick);
	//在m_connectionList中查找目标并发送
	POSITION ps = m_connectionList.GetHeadPosition();
	CClientSocket* psocket;
	while(ps)
	{
		psocket = (CClientSocket*)m_connectionList.GetNext(ps);
		if (psocket->m_ClientNick == strFDNick)//好友昵称和socket昵称相同，则找到该socket并发送消息
		{
			char* cBuf = new char[LEN];
			memcpy(cBuf,&sPag,LEN);
			psocket->Send(cBuf,LEN);
			delete[] cBuf;
			break;
		}
	}
}

/***********************************************
Function:		MsgOnHandle
Descriptioin:	处理用户上线信息
Input:			sPag发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::MsgOnHandle(Pag sPag)
{
	return;
}

/***********************************************
Function:		MsgOffHandle
Descriptioin:	处理用户下线信息。下线后将下线信
息记录到LIST表中
Input:			sPag发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::MsgOffHandle(Pag sPag)
{
	//LIST中添加下线信息
	CString strNick;						//用户昵称
	CString strTime;						//下线时间
	CString strTemp;
	CTime tTime = CTime::GetCurrentTime();
	strNick.Format("%s",sPag.cNick);
	strTime = tTime.Format("%H:%M:%S");
	CListCtrl* pList = &m_pTabDlgLink->m_ListLink;
	int nIndex = pList->GetItemCount();
	for (int i = 0; i <= nIndex; i++)
	{
		strTemp = pList->GetItemText(i,1);
		if (strTemp == strNick)
		{
			if (pList->GetItemText(i,4) == "")
			{
				pList->SetItemText(i,4,strTime);//在用户连接信息LIST中添加下线时间
				pList->SetItemText(i,2,"下线");
				break;
			}
		}
	}
	
	//将下线用户对应的socket删除
	POSITION pos = m_connectionList.GetHeadPosition();
	while (pos)
	{
		POSITION t_pos = pos;
		CClientSocket* pSocket = (CClientSocket*)m_connectionList.GetNext(pos);
		if (pSocket->m_ClientNick == strNick)
		{
			delete pSocket;
			pSocket = NULL;
			m_connectionList.RemoveAt(t_pos);
			break;
		}
	}
	
	//vector中删除该用户昵称
	vector<CString>::iterator itr = m_vStrOnline.begin();
	while (itr != m_vStrOnline.end())
	{
		if (*itr == strNick)
		{
			m_vStrOnline.erase(itr);
			break;
		}
		++itr;
	}
	
	//告诉所有人该用户下线
	sPag.nType = Msg_SOFF;
	SendToAll(sPag);
}

/***********************************************
Function:		SendToAll
Descriptioin:	群发
Input:			sPag：发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::SendToAll(Pag sPag)
{
	char* cBuf = new char[LEN];
	memset(cBuf,0,LEN);
	memcpy(cBuf,&sPag,LEN);
	POSITION pos = m_connectionList.GetHeadPosition();
	while (pos)
	{
		CServerSocket* pSocket = (CServerSocket*)m_connectionList.GetNext(pos);
		pSocket->Send(cBuf,LEN);
	}
}

/***********************************************
Function:		MsgStateHandle
Descriptioin:	处理用户状态修改，并将其改变添加
到用户连接的LIST中
Input:			sPag：发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::MsgStateHandle(Pag sPag)
{
	CListCtrl* pList = &m_pTabDlgLink->m_ListLink;
	CString strNick("");
	strNick.Format("%s",sPag.cNick);
	int nIndex = pList->GetItemCount();
	for(int i = 0; i < nIndex; i++)
	{
		CString strTemp = pList->GetItemText(i,1);
		if (strTemp == strNick)
		{
			break;
		}
	}	
	int nState = sPag.nState;
	switch(sPag.nState)					//用户连接信息中设置状态
	{
	case State_ON:
		pList->SetItemText(i,2,"我在线上");
		break;
	case State_Leave:
		pList->SetItemText(i,2,"离开");
		break;
	case State_Busy:
		pList->SetItemText(i,2,"忙碌");
		break;
	case State_UnDisturb:
		pList->SetItemText(i,2,"请勿打扰");
		break;
	}
}

/***********************************************
Function:		MsgRegistHandle
Descriptioin:	处理用户注册消息，服务端接收到注
册请求后将账号发送到客户端，客户
端发送信息到服务端，完成注册
Input:			PSocket：客户端套接字，对应注册的
客户端用户
sPag：发送过来的消息包
Return:
Others:
***********************************************/
void CServerDlg::MsgRegistHandle(CClientSocket* pSocket,Pag sPag)
{
	if (sPag.nRegist == 1)
	{
		/*连接数据库,将新用户信息写入*/
		CDatabase oDatabase;
		oDatabase.OpenEx(_T("DSN=UserData"),CDatabase::noOdbcDialog);
		CRecordset recset(&oDatabase);
		CString strSQL;
		CString strSex;
		if (sPag.nSex == 0)
		{
			strSex = "男";
		}
		else
		{
			strSex = "女";
		}
		CTime tTime = CTime::GetCurrentTime();
		CString strTime = tTime.Format("%Y/%m/%d");
		
		/*添加新用户信息*/
		strSQL.Format("insert into user values (%d,'%s',%d,'%s',%d,'%s')",sPag.ID,sPag.cNick,sPag.nPass,
			strSex,sPag.nAge,strTime);
		oDatabase.ExecuteSQL(strSQL);
		oDatabase.Close();
		
		/*添加到用户信息列表*/
		CString strID;
		CString strNick;
		CString strPass;
		strID.Format("%d",sPag.ID);
		strNick.Format("%s",sPag.cNick);
		strPass.Format("%d",sPag.nPass);
		CListCtrl* pList = &m_pTabDlgInfo->m_ListInfo;
		int nIndex = pList->GetItemCount();
		pList->InsertItem(nIndex,strID);
		pList->SetItemText(nIndex,1,strNick);
		pList->SetItemText(nIndex,2,strPass);
		pList->SetItemText(nIndex,3,strTime);
		
		/*在LIST中删除该socket信息*/
		POSITION pos = m_connectionList.GetHeadPosition();
		while (pos)
		{
			POSITION t_pos = pos;
			CClientSocket* pSock = (CClientSocket*)m_connectionList.GetNext(pos);
			if ((pSock->m_port == pSocket->m_port) && (inet_ntoa(pSock->m_addr) == inet_ntoa(pSocket->m_addr)))
			{
				delete pSock;
				pSock = NULL;
				m_connectionList.RemoveAt(t_pos);
				break;
			}
		}
	}
	else
	{
		/*给新用户账号，此账号需要服务端给予*/
		CListCtrl* pList = &m_pTabDlgInfo->m_ListInfo;
		int nIndex = pList->GetItemCount();
		CString strID;
		int nID;
		strID = pList->GetItemText(nIndex-1,0);
		nID = atoi(strID) + 1;
		strID.Format("%d",nID);
		strcpy(sPag.Msg,strID);
		char* cBuf = new char[LEN];
		memcpy(cBuf,&sPag,LEN);
		pSocket->Send(cBuf,LEN);
	}
}
