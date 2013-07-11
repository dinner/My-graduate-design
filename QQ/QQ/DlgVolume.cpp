// DlgVolume.cpp : implementation file
//

#include "stdafx.h"
#include "qq.h"
#include "DlgVolume.h"
#include "Talk.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgVolume dialog


CDlgVolume::CDlgVolume(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgVolume::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgVolume)
	//}}AFX_DATA_INIT
}


void CDlgVolume::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgVolume)
	DDX_Control(pDX, IDC_SLIDER_PITCH, m_Pitch);
	DDX_Control(pDX, IDC_SLIDER_VOLUME, m_Volume);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgVolume, CDialog)
	//{{AFX_MSG_MAP(CDlgVolume)
	ON_WM_CLOSE()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgVolume message handlers


void CDlgVolume::setDlg(CTalk* dlg)
{
	m_pDlgTalk = dlg;
}

void CDlgVolume::OnClose() 
{
	// TODO: Add your message handler code here and/or call default	
	this->ShowWindow(SW_HIDE);
}


void CDlgVolume::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	DWORD dwID = nSBCode;
	DWORD dwPos = nPos;
	CScrollBar* pScrollVolume = (CScrollBar*)GetDlgItem(IDC_SLIDER_VOLUME);
	CScrollBar* pScrollPitch = (CScrollBar*)GetDlgItem(IDC_SLIDER_PITCH);
	if (pScrollBar == pScrollVolume)
	{
		DWORD dwVolume = (double)m_Volume.GetPos() / 100 * 0xFFFFFFFF;
		waveOutSetVolume(m_pDlgTalk->hWaveOut,dwVolume);
	}
	else
	{
		DWORD dwPitch = (double)m_Pitch.GetPos() / 100 * 0x000F8000;
		waveOutSetPitch(m_pDlgTalk->hWaveOut,dwPitch);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


