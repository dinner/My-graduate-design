#if !defined(AFX_TALK_H__5CD655DC_3B03_4DAF_B5A7_68D8AA618F3E__INCLUDED_)
#define AFX_TALK_H__5CD655DC_3B03_4DAF_B5A7_68D8AA618F3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Talk.h : header file
#include<WINDOWS.H>
#include <afxmt.h>
#include "stdafx.h"
#include <mmsystem.h>
#include <list>
#pragma comment(lib,"winmm.lib")
/////////////////////////////////////////////////////////////////////////////
// CTalk dialog
class CQQDlg;
class CDlgVolume;
using namespace std;
class CTalk : public CDialog
{
// Construction
public:
	CString m_SELF;
	BOOL m_IsOpen;
	CQQDlg * m_Qdlg;
	void SetQDlg(CQQDlg *dlg);
	CString m_FR;
	CTalk(CWnd* pParent = NULL);   // standard constructor

	char m_cbufferIN[MAX_BUFFER_SIZE];	//�����豸�Ļ�����
	char m_cbufferOut[MAX_BUFFER_SIZE];	//����豸�Ļ�����
	WAVEHDR m_hWaveHdIn,m_hWaveHdOut;	//��Ƶ���ݿ黺��ṹ
	WAVEFORMATEX m_waveformout;			//����豸������Ƶ�������ݽṹ
	WAVEFORMATEX m_waveformin;			//�����豸�Ĳ�����Ƶ�����ݽṹ
	HWAVEOUT hWaveOut;					//����豸
	HWAVEIN hWaveIn;					//�����豸
	BOOL m_bIsConnect;					//�Ƿ�����
	BOOL m_bIsStartRecord;				
	CDlgVolume* m_pDlgVolume;		
	BOOL m_bIsVolume;
	list<CString> m_lSoundList;

	void FreeRecordBuffer();
	void FreePlayBuffer(char cSound[]);
	void Start();
	void StopRecord();
	void Recording();

// Dialog Data
	//{{AFX_DATA(CTalk)
	enum { IDD = IDD_TALK_DIALOG };
	CListBox	m_list;
	CEdit	m_ReM;
	CString	m_Msg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTalk)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTalk)
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnSend();
	afx_msg void OnClean();
	afx_msg void OnFont();
	afx_msg void OnButrecord();
	afx_msg void OnMM_WIM_DATA(UINT wParam,LONG lParam);
	afx_msg void OnButVolume();
	afx_msg void OnPlay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TALK_H__5CD655DC_3B03_4DAF_B5A7_68D8AA618F3E__INCLUDED_)
