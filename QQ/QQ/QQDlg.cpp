// QQDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "QQDlg.h"
#include "Talk.h"
#include "Login.h"
#include "ClientSocket.h"
#include "type.h"

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
// CQQDlg dialog
CQQDlg::CQQDlg(CWnd* pParent /*=NULL*/)
: CDialog(CQQDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQQDlg)
	m_nick = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//   m_DiaSer = FALSE;
	m_IsCreated = FALSE;
	m_bIsConnect = FALSE;
	m_bIsExpand = FALSE;
	m_mTalkDlgList.clear();
}

void CQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQQDlg)
	DDX_Control(pDX, IDC_COMBO, m_condition);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Text(pDX, IDC_NICK, m_nick);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQQDlg, CDialog)
//{{AFX_MSG_MAP(CQQDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_NOTIFY(NM_DBLCLK, IDC_TREE, OnDblclkTree)
ON_WM_CLOSE()
ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)
ON_BN_CLICKED(IDC_BUT_REGIST, OnButRegist)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQQDlg message handlers

BOOL CQQDlg::OnInitDialog()
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
	SetWindowText("局域网聊天1.0");
    m_psocket.setQDlg(this);
	
	InitTree();
	
	m_condition.AddString("我在线上");
	m_condition.AddString("离开");
	m_condition.AddString("忙碌");
	m_condition.AddString("请勿打扰");
	m_condition.SetCurSel(3);
	
	CRect rc;
	GetClientRect(&rc);
	MoveWindow(1100,70,rc.Width(),rc.Height()+20);
	
	CLogin dlg;
	dlg.setQDlg(this);
    dlg.DoModal();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CQQDlg::OnPaint() 
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
HCURSOR CQQDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQQDlg::OnDblclkTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nIndex = 1;
	CPoint pt;
    GetCursorPos(&pt);
    m_tree.ScreenToClient(&pt);
    HTREEITEM hItem = m_tree.HitTest(pt);
	if(hItem)
    { 
        while(NULL != (hItem = m_tree.GetParentItem(hItem)))
        {
            nIndex++;
        }
    }
    if(nIndex==1)
	{
		if (m_bIsExpand)
		{
			m_tree.SetItemImage(htOnline,1,1);
			m_bIsExpand = FALSE;
		}
		else
		{
			m_tree.SetItemImage(htOnline,0,0);
			m_bIsExpand = TRUE;
		}
	}
    else
	{
		HTREEITEM hSel = m_tree.GetSelectedItem();
		CString FR = m_tree.GetItemText(hSel); 
		CTalk* pTalkDlg;
		map<CString ,CTalk*>::iterator iter;
		iter = m_mTalkDlgList.find(FR);
		if (iter != m_mTalkDlgList.end())
		{
			pTalkDlg = iter->second;
		}
		else
		{
			pTalkDlg = new CTalk;
			pTalkDlg->m_FR.Format("%s",FR);
			pTalkDlg->m_SELF.Format("%s",m_nick);
			pTalkDlg->SetQDlg(this);
			pTalkDlg->Create(IDD_TALK_DIALOG,this);
			m_mTalkDlgList[FR] = pTalkDlg;
		}
		pTalkDlg->ShowWindow(SW_SHOW);
	}
	*pResult = 0;
}


void CQQDlg::Receive(CClientSocket *psocket)
{
	Pag pag;
	char *buf = new char[sizeof(pag)];
	psocket->Receive(buf,sizeof(pag));
	memcpy(&pag,buf,sizeof(pag));
	Handle(psocket,pag);
}

void CQQDlg::Handle(CClientSocket *psocket, Pag pag)
{
	char *buf = new char[sizeof(pag)];
    CTime date = CTime::GetCurrentTime();
    CString Date = date.Format("[%H:%M:%S]");
	switch(pag.nType)
	{
	case Msg_SToSer:
		{
			break;
		}
	case Msg_SToIn://客户端之间通信
		{
			CString WinName;
			WinName.Format("%s",pag.cNick);
			map<CString,CTalk*>::iterator iter;
			iter = m_mTalkDlgList.find(WinName);
			CTalk* pTalkDlg;
			if (iter != m_mTalkDlgList.end())
			{
				pTalkDlg = iter->second;
			}
			else
			{
				pTalkDlg = new CTalk;
				pTalkDlg->m_FR.Format("%s",pag.cNick);
				pTalkDlg->m_SELF.Format("%s",pag.cFNick);
				pTalkDlg->Create(IDD_TALK_DIALOG,this);
				pTalkDlg->SetQDlg(this);
				m_mTalkDlgList[pTalkDlg->m_FR] = pTalkDlg;
			}
			
			if (pag.nSound == 1 && pTalkDlg->m_bIsStartRecord == TRUE)
			{	
			//	memcpy(pTalkDlg->m_cbufferOut,pag.Sound_Buffer,MAX_BUFFER_SIZE);
				
			//	pTalkDlg->FreePlayBuffer();
				CString strTemp;
				strTemp.Format("%s",pag.Sound_Buffer);
				pTalkDlg->m_lSoundList.push_back(strTemp);
				::SendMessage(pTalkDlg->m_hWnd,WM_TEST,0,0);
// 				memcpy(pTalkDlg->m_cbufferOut,pag.Sound_Buffer,MAX_BUFFER_SIZE);
// 				pTalkDlg->FreePlayBuffer();
			}
			if (pag.nSound == 0)
			{
				CString time;
				time.Format("%s %s：",Date,pag.cNick);
				
				CString M_sg;
				M_sg.Format("    %s",pag.Msg);
				int index = pTalkDlg->m_list.GetCount();
				
				pTalkDlg->m_list.InsertString(index,time);
				pTalkDlg->m_list.InsertString(index+1,M_sg);
			}
			pTalkDlg->ShowWindow(SW_SHOW);
			break;
		}
	case Msg_SToAll://服务器发来消息
		break;  
	case Msg_SON://好友上线
		{
			CString strFNick;
			CString strItem;
			strFNick.Format("%s",pag.cNick);
			HTREEITEM hChildItem= m_tree.GetChildItem(htOnline);
			while (hChildItem != NULL)
			{	
				strItem = m_tree.GetItemText(hChildItem);
				if (strItem == strFNick)
				{
					m_tree.SetItemImage(hChildItem,2,2);
					break;
				}
				hChildItem = m_tree.GetNextSiblingItem(hChildItem);
			}
			break;
		}
	case Msg_SOFF://好友下线
		{
			CString strFNick;
			CString strItem;
			strFNick.Format("%s",pag.cNick);
			HTREEITEM hChildItem= m_tree.GetChildItem(htOnline);
			while (hChildItem != NULL)
			{	
				strItem = m_tree.GetItemText(hChildItem);
				if (strItem == strFNick)
				{
					m_tree.SetItemImage(hChildItem,3,3);
					break;
				}
				hChildItem = m_tree.GetNextSiblingItem(hChildItem);
			}
			break;
		}
	}
}

void CQQDlg::OnClose() 
{
	if (m_bIsConnect)
	{
		Pag pag;
		char *cBuf = new char[sizeof(pag)];
		pag.nType = Msg_SOFF;
		CString Msg;//发送给服务器的下线消息
		CTime date = CTime::GetCurrentTime();//当前时间
		CString Date = date.Format("[%H:%M:%S]"); 
		Msg.Format("%s %s下线了",Date,m_nick);
		strcpy(pag.Msg,(LPTSTR)(LPCTSTR)Msg);
		strcpy(pag.cNick,m_nick);
		memcpy(cBuf,&pag,sizeof(pag));
		m_psocket.Send(cBuf,sizeof(pag));
		m_psocket.Close();
		m_mTalkDlgList.clear();	
		CDialog::OnClose();		
	}
	else
	{
		CDialog::OnClose();
	}
}

void CQQDlg::OnSelchangeCombo() 
{
	// TODO: Add your control notification handler code here
	Pag sPag;
	sPag.nType = Msg_SState;
	CString strNick("");
	GetDlgItemText(IDC_NICK,strNick);
	int nIndex = ((CComboBox*)GetDlgItem(IDC_COMBO))->GetCurSel();
//	memcpy(sPag.cNick,&strNick,sizeof(strNick));
	strcpy(sPag.cNick,strNick);
	switch(nIndex)
	{
	case 3:
		sPag.nState = State_ON;
		break;
	case 2:
		sPag.nState = State_UnDisturb;
		break;
	case 1:
		sPag.nState = State_Busy;
		break;
	case 0:
		sPag.nState = State_Leave;
		break;
	}
	char* cBuf = new char[LEN];
	memcpy(cBuf,&sPag,LEN);
	m_psocket.Send(cBuf,LEN);
}



void CQQDlg::OnButRegist() 
{
	// TODO: Add your control notification handler code here
}

void CQQDlg::InitTree()
{
	HICON icon[4];
	icon[0] = AfxGetApp()->LoadIcon(IDI_ICON_COLLAPSE);
	icon[1] = AfxGetApp()->LoadIcon(IDI_ICON_EXPAND);
	icon[2] = AfxGetApp()->LoadIcon(IDI_ICON_ONLINE);
	icon[3] = AfxGetApp()->LoadIcon(IDI_ICON_OFFLINE);
	CImageList* imgList = new CImageList;
	imgList->Create(16,16,ILC_COLOR32|ILC_MASK,0,3);
	imgList->Add(icon[0]);
	imgList->Add(icon[1]);
	imgList->Add(icon[2]);
	imgList->Add(icon[3]);
	
	m_tree.SetImageList(imgList,LVSIL_NORMAL);
	m_tree.SetBkColor(RGB(255,255,255));
	
    htOnline = this->m_tree.InsertItem("我的好友",1,0,TVI_ROOT,TVI_LAST);
}
