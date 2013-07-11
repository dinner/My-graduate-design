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
Descriptioin:	�Ի����ʼ��
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
	m_Socket.setDlg(this);								//����ָ��ָ��
	m_pTabDlgInfo = new CDlgClientInfo();
	m_pTabDlgLink = new CDlgClientLink();
	m_pTabDlgInfo->setDlg(this);						//�û���ϢTABҳָ��ָ��
	m_pTabDlgLink->setDlg(this);						//�û�������ϢTABҳָ��ָ��
	m_pTabDlgInfo->Create(IDD_DLG_CLIENTINFO,GetDlgItem(IDC_TAB_MENU));
	m_pTabDlgLink->Create(IDD_DLG_CLIENTLINK,GetDlgItem(IDC_TAB_MENU));
	m_Tab.InsertItem(TCIF_TEXT | TCIF_IMAGE | TCIF_PARAM,0,_T("����"),0,(LPARAM)m_pTabDlgLink,0,0);
	m_Tab.InsertItem(TCIF_TEXT | TCIF_IMAGE | TCIF_PARAM,1,_T("�ͻ�"),0,(LPARAM)m_pTabDlgInfo,0,0);
	m_Tab.SetCurSel(0);
	ShowTabDlg(0);
	m_bIsInit = TRUE;			//��ʼ�����
	
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
Descriptioin:	Tabҳ�л�
Input:			nItme��Tab��� ��0���л����û����ӶԻ�
����1�����û���Ϣ�Ի���
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
			m_Tab.GetClientRect(&rc);//���TABҳλ��
			ClientToScreen(&rc);	 //���TABҳ����
			m_Tab.AdjustRect(FALSE,&rc);
			rc.top += 15;
			m_pTabDlgLink->MoveWindow(&rc);
			m_pTabDlgLink->ShowWindow(SW_SHOW);
			m_pTabDlgInfo->ShowWindow(SW_HIDE);
		}
		break;
	case 1:
		{
			m_Tab.GetClientRect(&rc);//���TABҳλ��
			ClientToScreen(&rc);	//���TABҳ����
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
Descriptioin:	ѡ��ͬ��TAB����ʾ��Ӧ�ĶԻ���
Input:			
Return:
Others:
***********************************************/
void CServerDlg::OnSelchangeTabMenu(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	UINT nItem = m_Tab.GetCurSel();	//���TAB��ҳ��
	ShowTabDlg(nItem);				//��ʾ��Ӧ��TABҳ
	*pResult = 0;
}

void CServerDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	//�ж��Ƿ��ʼ����������л�TABҳ
	if (m_bIsInit)	
	{
		UINT nItem = m_Tab.GetCurSel();
		ShowTabDlg(nItem);
	}
	// TODO: Add your message handler code here
}

/***********************************************
Function:		ProcessAccept
Descriptioin:	socket���յ����Ӻ󣬽�����socket
�����ݼ�¼��CPtrList����
Input:			
Return:
Others:
***********************************************/
void CServerDlg::ProcessAccept()
{
	SOCKADDR_IN clientaddr;				//����SOCKET��IP��ַ
	int addrlen = sizeof(clientaddr);
    
	CClientSocket* psocket = new CClientSocket();	
	this->m_Socket.Accept(*psocket,
		(LPSOCKADDR)&clientaddr, &addrlen);
    
	psocket->m_addr	= clientaddr.sin_addr;
	psocket->m_port = clientaddr.sin_port;
    psocket->setDlg(this);				//����ָ��ָ��
	m_connectionList.AddTail(psocket);
}

/***********************************************
Function:		ProcessReceive
Descriptioin:	���ӵ��׽��ֽ��յ����ݺ�����ݽ�
�д���
Input:			pSocket�Ƿ�����Ϣ���׽���
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
Descriptioin:	���ӵ��׽��ֽ��յ����ݺ�����ݽ�
�д���
Input:			pSocket�Ƿ�����Ϣ���׽��֣�sPag
���͹�������Ϣ��
Return:
Others:
***********************************************/
void CServerDlg::DataHandle(CClientSocket *pSocket, Pag sPag)
{
	char* cBuf = new char[LEN];			 //���͵����ݻ�����
	CString strTime;
	CTime tTime = CTime::GetCurrentTime();
	strTime = tTime.Format("[%H:%M:%S]");//��ǰʱ��
	switch(sPag.nType)
	{
	case Msg_Login://��¼��Ϣ
		MsgLoginHandle(pSocket,sPag);
		break;
	case Msg_SToIn://�ͻ���֮��ͨ��
		MsgToIndHandle(sPag);
		break;
	case Msg_SON:  //�û�����֪ͨ
		MsgOnHandle(sPag);
		break;
	case Msg_SOFF:	//�û�����֪ͨ
		MsgOffHandle(sPag);
		break;
	case Msg_SState://״̬�л�
		MsgStateHandle(sPag);
		break;
	case Msg_SRegist://ע����Ϣ
		MsgRegistHandle(pSocket,sPag);
		break;
	}
}

/***********************************************
Function:		MsgLoginHandle
Descriptioin:	�����û���¼��Ϣ���ڴ˺����пͻ�
�˷����˺ź����룬����������ݿ�
�н��в��ҡ����ҵ��򷵻ص�¼�ɹ�
�ͻ��˳ɹ���¼
Input:			pSocket�Ƿ�����Ϣ���׽��֣�sPag
���͹�������Ϣ��
Return:
Others:
***********************************************/
void CServerDlg::MsgLoginHandle(CClientSocket* pSocket,Pag sPag)
{
	CUserSet oUserSet;
	CString strSQL;
	BOOL bIsLogin = FALSE;
	char* cBuf = new char[LEN];			//���͵����ݻ�����
	memset(cBuf,0,LEN);
	strSQL.Format("select* from User");
	oUserSet.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
	while (!oUserSet.IsEOF())
	{
		//�ж��Ƿ���ڶ�Ӧ���˺ź�����
		if (oUserSet.m_ID == sPag.ID && oUserSet.m_PASS == sPag.nPass)
		{
			//���ҵ��и��û����ҵ�½�ɹ�
			bIsLogin = TRUE;
			strcpy(sPag.cNick,oUserSet.m_NICK);
			break;
		}
		oUserSet.MoveNext();
	}
	oUserSet.Close();
	if (!bIsLogin)						//��¼ʧ��
	{
		sPag.nReback = Login_Fail;
		memcpy(cBuf,&sPag,LEN);
		pSocket->Send(cBuf,LEN);
	}
	else								//��¼�ɹ� ���͵�¼�ɹ���Ϣ
	{
		/*���û��ǳ���ӵ���Ӧ�û���SOCKET�ṹ��*/	
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
		CString strSQL;					//sql����ַ���
		CString strFNList;				//�û��ĺ����б��ַ���
		int nFNum = 0;
		strSQL.Format("select* from UserFriend where UFID = %d",sPag.ID);
		oUserFriend.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);//�����ݿ�
		while (!oUserFriend.IsEOF())	//����δ����
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
			nFNum ++;					//����������
			oUserFriend.MoveNext();
		}
		oUserSet.Close();				//�ر����ݿ�
		memcpy(sPag.cFNickList,strFNList,sizeof(sPag.cFNickList));
		sPag.nFNum = nFNum;
		
		/*������֤�ɹ���Ϣ*/
		sPag.nReback = Login_Success;
		memcpy(cBuf,&sPag,LEN);
		pSocket->Send(cBuf,LEN);
		
		//��ӵ�¼���û���Ϣ��LIST
		CListCtrl* pList = &m_pTabDlgLink->m_ListLink;
		int nIndex = pList->GetItemCount();
		CString strTemp;
		strTemp.Format("%d",sPag.ID);
		pList->InsertItem(nIndex,strTemp);
		strTemp.Format("%s",sPag.cNick);
		pList->SetItemText(nIndex,1,strTemp);
		strTemp.Format("��������");
		pList->SetItemText(nIndex,2,strTemp);
		CTime tTime = CTime::GetCurrentTime();
		strTemp = tTime.Format("%H:%M:%S");
		pList->SetItemText(nIndex,3,strTemp);
		
		sPag.nType = Msg_SON;			//������Ϣ
		SendToAll(sPag);				//֪ͨ���������û����û�����
	}
}

/***********************************************
Function:		MsgToIndHandle
Descriptioin:	�ͻ���֮��ͨ�ţ�����˽��ܵ�A�û�
���������ݰ����ٸ������ǳƷ��͵�
Ŀ���û�
Input:			sPag���͹�������Ϣ��
Return:
Others:
***********************************************/
void CServerDlg::MsgToIndHandle(Pag sPag)
{
	CString strFDNick;
	strFDNick.Format("%s",sPag.cFNick);
	//��m_connectionList�в���Ŀ�겢����
	POSITION ps = m_connectionList.GetHeadPosition();
	CClientSocket* psocket;
	while(ps)
	{
		psocket = (CClientSocket*)m_connectionList.GetNext(ps);
		if (psocket->m_ClientNick == strFDNick)//�����ǳƺ�socket�ǳ���ͬ�����ҵ���socket��������Ϣ
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
Descriptioin:	�����û�������Ϣ
Input:			sPag���͹�������Ϣ��
Return:
Others:
***********************************************/
void CServerDlg::MsgOnHandle(Pag sPag)
{
	return;
}

/***********************************************
Function:		MsgOffHandle
Descriptioin:	�����û�������Ϣ�����ߺ�������
Ϣ��¼��LIST����
Input:			sPag���͹�������Ϣ��
Return:
Others:
***********************************************/
void CServerDlg::MsgOffHandle(Pag sPag)
{
	//LIST�����������Ϣ
	CString strNick;						//�û��ǳ�
	CString strTime;						//����ʱ��
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
				pList->SetItemText(i,4,strTime);//���û�������ϢLIST���������ʱ��
				pList->SetItemText(i,2,"����");
				break;
			}
		}
	}
	
	//�������û���Ӧ��socketɾ��
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
	
	//vector��ɾ�����û��ǳ�
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
	
	//���������˸��û�����
	sPag.nType = Msg_SOFF;
	SendToAll(sPag);
}

/***********************************************
Function:		SendToAll
Descriptioin:	Ⱥ��
Input:			sPag�����͹�������Ϣ��
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
Descriptioin:	�����û�״̬�޸ģ�������ı����
���û����ӵ�LIST��
Input:			sPag�����͹�������Ϣ��
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
	switch(sPag.nState)					//�û�������Ϣ������״̬
	{
	case State_ON:
		pList->SetItemText(i,2,"��������");
		break;
	case State_Leave:
		pList->SetItemText(i,2,"�뿪");
		break;
	case State_Busy:
		pList->SetItemText(i,2,"æµ");
		break;
	case State_UnDisturb:
		pList->SetItemText(i,2,"�������");
		break;
	}
}

/***********************************************
Function:		MsgRegistHandle
Descriptioin:	�����û�ע����Ϣ������˽��յ�ע
��������˺ŷ��͵��ͻ��ˣ��ͻ�
�˷�����Ϣ������ˣ����ע��
Input:			PSocket���ͻ����׽��֣���Ӧע���
�ͻ����û�
sPag�����͹�������Ϣ��
Return:
Others:
***********************************************/
void CServerDlg::MsgRegistHandle(CClientSocket* pSocket,Pag sPag)
{
	if (sPag.nRegist == 1)
	{
		/*�������ݿ�,�����û���Ϣд��*/
		CDatabase oDatabase;
		oDatabase.OpenEx(_T("DSN=UserData"),CDatabase::noOdbcDialog);
		CRecordset recset(&oDatabase);
		CString strSQL;
		CString strSex;
		if (sPag.nSex == 0)
		{
			strSex = "��";
		}
		else
		{
			strSex = "Ů";
		}
		CTime tTime = CTime::GetCurrentTime();
		CString strTime = tTime.Format("%Y/%m/%d");
		
		/*������û���Ϣ*/
		strSQL.Format("insert into user values (%d,'%s',%d,'%s',%d,'%s')",sPag.ID,sPag.cNick,sPag.nPass,
			strSex,sPag.nAge,strTime);
		oDatabase.ExecuteSQL(strSQL);
		oDatabase.Close();
		
		/*��ӵ��û���Ϣ�б�*/
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
		
		/*��LIST��ɾ����socket��Ϣ*/
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
		/*�����û��˺ţ����˺���Ҫ����˸���*/
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
