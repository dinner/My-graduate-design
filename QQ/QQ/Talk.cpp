// Talk.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "Talk.h"
#include "QQDlg.h"
#include "type.h"
#include "DlgVolume.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTalk dialog


CTalk::CTalk(CWnd* pParent /*=NULL*/)
	: CDialog(CTalk::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTalk)
	m_Msg = _T("");
	//}}AFX_DATA_INIT
	m_IsOpen = FALSE;
	m_bIsStartRecord = FALSE;
	m_bIsVolume = FALSE;
	m_lSoundList.clear();
}


void CTalk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTalk)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Text(pDX, IDC_SM, m_Msg);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTalk, CDialog)
	//{{AFX_MSG_MAP(CTalk)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_BN_CLICKED(IDC_CLEAN, OnClean)
	ON_BN_CLICKED(IDC_FONT, OnFont)
	ON_BN_CLICKED(IDC_BUTRECORD, OnButrecord)
	ON_MESSAGE(MM_WIM_DATA,OnMM_WIM_DATA)
	ON_BN_CLICKED(IDC_BUT_VOLUME, OnButVolume)
	ON_MESSAGE(WM_TEST,OnPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTalk message handlers

BOOL CTalk::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetWindowText(m_SELF+"与"+m_FR+"聊天");
	((CButton*)GetDlgItem(IDC_BUT_VOLUME))->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTalk::SetQDlg(CQQDlg *dlg)
{
    m_Qdlg = dlg;
}

void CTalk::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
//	m_IsOpen = FALSE;
//	m_Qdlg->m_IsCreated = FALSE;
//	CDialog::OnClose();	
	ShowWindow(SW_HIDE);
}

void CTalk::OnSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Pag pag;
	char *buf  = new char[sizeof(pag)];
	if(m_FR == "服务器")
	{
	strcpy(pag.Msg,(LPTSTR)(LPCTSTR)m_Msg);
	strcpy(pag.cNick,(LPTSTR)(LPCTSTR)m_SELF);
	pag.nType = Msg_SToSer;//发送给服务器
	}

	else
	{
      strcpy(pag.Msg,(LPTSTR)(LPCTSTR)m_Msg);
      strcpy(pag.cNick,(LPTSTR)(LPCTSTR)m_SELF);
	  strcpy(pag.cFNick,(LPTSTR)(LPCTSTR)m_FR);
	  pag.nType = Msg_SToIn;
	  pag.nSound = 0;
	//  pag.Fnick = m_FR;	
	}
      memcpy(buf,&pag,sizeof(pag));
      m_Qdlg->m_psocket.Send(buf,sizeof(pag));

	  CTime date = CTime::GetCurrentTime();
	  CString Date = date.Format("[%H:%M:%S]"); 
	  Date+=" "+m_SELF+"：";
	  
	  int row = m_list.GetCount();
	  m_list.InsertString(row,Date);
      m_list.InsertString(row+1,"   "+m_Msg);

	//清除发送框内容
    m_Msg = "";
	UpdateData(FALSE);
}

void CTalk::OnClean() 
{
	// TODO: Add your control notification handler code here
	m_list.ResetContent();
 }


void CTalk::OnFont() 
{
	// TODO: Add your control notification handler code here
// 	CFont   ft;   
// 	CFontDialog   fdlg;   
// 	LOGFONT   lf;   
// 	if(fdlg.DoModal()==IDOK)   
// 	{   
// 		fdlg.GetCurrentFont(&lf);   
// 		ft.DeleteObject();
// 		ft.CreateFontIndirect(&lf);   
// 	}  
// 
// 	CWnd * pEdit = GetDlgItem(IDC_SM); 
//     pEdit->SetFont(&ft,TRUE); 

	CFont * f; 
	f = new CFont; 
	f->CreateFont(22, // nHeight 
		0, // nWidth 
		0, // nEscapement 
		0, // nOrientation 
		FW_BOLD, // nWeight 
		TRUE, // bItalic 
		FALSE, // bUnderline 
		0, // cStrikeOut 
		ANSI_CHARSET, // nCharSet 
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		CLIP_DEFAULT_PRECIS, // nClipPrecision 
		DEFAULT_QUALITY, // nQuality 
		DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily 
		_T("Arial")); // lpszFac 
        GetDlgItem(IDC_SM)->SetFont(f); 
}

void CTalk::OnButrecord() 
{
	// TODO: Add your control notification handler code here
	if (m_IsOpen == FALSE)
	{
		Recording();
		SetDlgItemText(IDC_BUTRECORD,"停止");
		m_IsOpen = TRUE;
		m_bIsStartRecord = TRUE;
		((CButton*)GetDlgItem(IDC_BUT_VOLUME))->EnableWindow(TRUE);
	}
	else
	{
		StopRecord();
		SetDlgItemText(IDC_BUTRECORD,"录音");
		m_IsOpen = FALSE;
		m_bIsStartRecord = FALSE;
		((CButton*)GetDlgItem(IDC_BUT_VOLUME))->EnableWindow(FALSE);
	}
}

void CTalk::OnMM_WIM_DATA(UINT wParam,LONG lParam)
{
	char *buf=new char[LEN];
	Pag pag;
	pag.nType = Msg_SToIn;
	pag.nSound = 1;
	strcpy(pag.cNick,(LPTSTR)(LPCTSTR)m_SELF);
	strcpy(pag.cFNick,(LPTSTR)(LPCTSTR)m_FR);
	memcpy(pag.Sound_Buffer,m_cbufferIN,MAX_BUFFER_SIZE);
	memcpy(buf,&pag,LEN);
	m_Qdlg->m_psocket.Send(buf,LEN);
	
	FreeRecordBuffer();
}

//释放play的buffer
void CTalk::FreePlayBuffer(char cSound[])
{
	//清除
	waveOutUnprepareHeader(hWaveOut,&m_hWaveHdOut,sizeof(WAVEHDR));
	memcpy(m_cbufferOut,cSound,MAX_BUFFER_SIZE);

	m_hWaveHdOut.lpData=m_cbufferOut;
	m_hWaveHdOut.dwBufferLength=MAX_BUFFER_SIZE;
	m_hWaveHdOut.dwBytesRecorded=0;
	m_hWaveHdOut.dwUser=0;
	m_hWaveHdOut.dwFlags=0;
	m_hWaveHdOut.dwLoops=1;
	m_hWaveHdOut.lpNext=NULL;
	m_hWaveHdOut.reserved=0;
	//准备
	if(waveOutPrepareHeader(hWaveOut,&m_hWaveHdOut,sizeof(WAVEHDR))!=MMSYSERR_NOERROR)
	{
		AfxMessageBox("error");
		return;
	}
	//发送
	if(waveOutWrite(hWaveOut,&m_hWaveHdOut,sizeof(WAVEHDR))!=MMSYSERR_NOERROR)
	{
		AfxMessageBox("error");
		return;
	}
}


void CTalk::FreeRecordBuffer()
{
	//清除为输入设备准备的缓冲
	if(waveInUnprepareHeader(hWaveIn,&m_hWaveHdIn,sizeof(WAVEHDR))!=MMSYSERR_NOERROR)
	{
		AfxMessageBox("Record buffer free error");
		return;
	}
	m_hWaveHdIn.lpData=m_cbufferIN;
	m_hWaveHdIn.dwBufferLength=MAX_BUFFER_SIZE;
	m_hWaveHdIn.dwBytesRecorded=0;
	m_hWaveHdIn.dwUser=0;
	m_hWaveHdIn.dwFlags=0;
	m_hWaveHdIn.dwLoops=1;
	m_hWaveHdIn.lpNext=NULL;
	m_hWaveHdIn.reserved=0;
	//为输入设备准备一个缓冲
	if(waveInPrepareHeader(hWaveIn,&m_hWaveHdIn,sizeof(WAVEHDR))!=MMSYSERR_NOERROR)
	{
		AfxMessageBox("Memery error");
		return;
	}
	//发送一个缓冲到输入设备
    if(waveInAddBuffer(hWaveIn,&m_hWaveHdIn,sizeof(WAVEHDR))!=MMSYSERR_NOERROR)
	{
		AfxMessageBox("Buffer add  error");
		return;
	}
}

//录音
void CTalk::Recording()
{
	memset(m_cbufferIN,0,MAX_BUFFER_SIZE);
	memset(m_cbufferOut,0,MAX_BUFFER_SIZE);
    m_waveformin.wFormatTag=WAVE_FORMAT_PCM;
	m_waveformin.nChannels=1;
	m_waveformin.nSamplesPerSec=11025;//采样频率
	m_waveformin.nAvgBytesPerSec=11025;
	m_waveformin.nBlockAlign=1;
	m_waveformin.wBitsPerSample=8;
	m_waveformin.cbSize=0;
	
	m_hWaveHdIn.lpData=m_cbufferIN;
	m_hWaveHdIn.dwBufferLength=MAX_BUFFER_SIZE;
	m_hWaveHdIn.dwBytesRecorded=0;
	m_hWaveHdIn.dwUser=0;
	m_hWaveHdIn.dwFlags=0;
	m_hWaveHdIn.dwLoops=1;
	m_hWaveHdIn.lpNext=NULL;
	m_hWaveHdIn.reserved=0;
	
	m_hWaveHdOut.lpData=m_cbufferOut;
	m_hWaveHdOut.dwBufferLength=MAX_BUFFER_SIZE;
	m_hWaveHdOut.dwBytesRecorded=0;
	m_hWaveHdOut.dwUser=0;
	m_hWaveHdOut.dwFlags=0;
	m_hWaveHdOut.dwLoops=1;
	m_hWaveHdOut.lpNext=NULL;
	m_hWaveHdOut.reserved=0;
	//打开输入设备
	if(waveInOpen(&hWaveIn,WAVE_MAPPER,&m_waveformin,(DWORD)this->m_hWnd,NULL,CALLBACK_WINDOW)!=MMSYSERR_NOERROR)
	{
		AfxMessageBox("HWAVEIN start error!");
		return;
	}			
	waveInPrepareHeader(hWaveIn,&m_hWaveHdIn,sizeof(WAVEHDR));
	waveInAddBuffer(hWaveIn,&m_hWaveHdIn,sizeof(WAVEHDR));
	//打开输出设备
	if (waveOutOpen(&hWaveOut,WAVE_MAPPER,&m_waveformin,(DWORD)this->m_hWnd,NULL,CALLBACK_WINDOW)!=MMSYSERR_NOERROR)
	{
		MessageBeep(MB_ICONEXCLAMATION);
		AfxMessageBox("Audio output");
		return;
	}
	waveOutPrepareHeader(hWaveOut,&m_hWaveHdOut,sizeof(WAVEHDR));
	waveOutWrite(hWaveOut,&m_hWaveHdOut,sizeof(WAVEHDR));
	Start();
	DWORD dwVolume = 0xAAAAAAAA;
	if (waveOutSetVolume(hWaveOut,dwVolume) != MMSYSERR_NOERROR)
	{
		MessageBox("Volume setting error");
	}
}
//waveOutSetPitch 
void CTalk::Start()
{
	if(waveInStart(hWaveIn)!=MMSYSERR_NOERROR)
    {
		AfxMessageBox("HWAVEIN open error");
	}
}

void CTalk::StopRecord()
{
	waveInStop(hWaveIn);
	waveOutClose(hWaveOut);
}

void CTalk::OnButVolume() 
{
	// TODO: Add your control notification handler code here
	if (!m_bIsVolume)
	{
		m_pDlgVolume = new CDlgVolume();
		m_pDlgVolume->setDlg(this);
		m_pDlgVolume->Create(IDD_DLG_VOLUME,this);
		m_pDlgVolume->ShowWindow(SW_SHOW);
		m_bIsVolume = TRUE;
	}
	else
	{
		m_pDlgVolume->ShowWindow(SW_SHOW);
	}
}

void CTalk::OnPlay()
{
	while (!m_lSoundList.empty())
	{	
	char* cBuf = new char[MAX_BUFFER_SIZE];
	CString strTemp;
	strTemp = m_lSoundList.front();
	
	memcpy(cBuf,strTemp,MAX_BUFFER_SIZE);
	FreePlayBuffer(cBuf);
	m_lSoundList.erase(m_lSoundList.begin());
	}
}
