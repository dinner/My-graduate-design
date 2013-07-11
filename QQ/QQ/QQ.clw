; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgInfo
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "qq.h"
LastPage=0

ClassCount=8
Class1=CClientSocket
Class2=CDlgVolume
Class3=CLogin
Class4=CQQApp
Class5=CAboutDlg
Class6=CQQDlg
Class7=CTalk

ResourceCount=6
Resource1=IDD_DLG_VOLUME
Resource2=IDD_TALK_DIALOG
Resource3=IDD_ABOUTBOX
Resource4=IDD_LOGIN
Resource5=IDD_QQ_DIALOG
Class8=CDlgInfo
Resource6=IDD_DLG_INFO

[CLS:CClientSocket]
Type=0
BaseClass=CSocket
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp

[CLS:CDlgVolume]
Type=0
BaseClass=CDialog
HeaderFile=DlgVolume.h
ImplementationFile=DlgVolume.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_SLIDER_PITCH

[CLS:CLogin]
Type=0
BaseClass=CDialog
HeaderFile=Login.h
ImplementationFile=Login.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_STATIC_REGIST

[CLS:CQQApp]
Type=0
BaseClass=CWinApp
HeaderFile=QQ.h
ImplementationFile=QQ.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=QQDlg.cpp
ImplementationFile=QQDlg.cpp
LastObject=IDOK

[CLS:CQQDlg]
Type=0
BaseClass=CDialog
HeaderFile=QQDlg.h
ImplementationFile=QQDlg.cpp

[CLS:CTalk]
Type=0
BaseClass=CDialog
HeaderFile=Talk.h
ImplementationFile=Talk.cpp

[DLG:IDD_DLG_VOLUME]
Type=1
Class=CDlgVolume
ControlCount=4
Control1=IDC_SLIDER_VOLUME,msctls_trackbar32,1342242840
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_SLIDER_PITCH,msctls_trackbar32,1342242840

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=12
Control1=IDC_ID,edit,1350631552
Control2=IDC_PASS,edit,1350631552
Control3=IDC_LOGIN,button,1342242816
Control4=IDC_SETTING,button,1342242816
Control5=IDC_BORDER,static,1350570247
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_IPADDRESS,SysIPAddress32,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PORT,edit,1350631552
Control11=IDC_STA_TEXT,static,1342308352
Control12=IDC_STATIC_REGIST,static,1342308608

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_QQ_DIALOG]
Type=1
Class=CQQDlg
ControlCount=6
Control1=IDC_NICK,edit,1350633856
Control2=IDC_TREE,SysTreeView32,1342251136
Control3=IDC_STATIC,static,1342177294
Control4=IDC_COMBO,combobox,1344340226
Control5=IDC_STATIC,button,1342177287
Control6=IDC_BUT_ADDFRIEND,button,1342242816

[DLG:IDD_TALK_DIALOG]
Type=1
Class=CTalk
ControlCount=8
Control1=IDC_SEND,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_SM,edit,1350631552
Control5=IDC_CLEAN,button,1342242816
Control6=IDC_LIST,listbox,1352728835
Control7=IDC_BUTRECORD,button,1342242816
Control8=IDC_BUT_VOLUME,button,1342242816

[DLG:IDD_DLG_INFO]
Type=1
Class=CDlgInfo
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_ID,edit,1350631552
Control6=IDC_EDIT_NICK,edit,1350631552
Control7=IDC_EDIT_PASS,edit,1350631552
Control8=IDC_EDIT_AGE,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_RADIO_MAN,button,1342177289
Control11=IDC_RADIO_WOMAN,button,1342177289
Control12=IDC_BUT_CONFERM,button,1342242816
Control13=IDC_BUT_CONCEL,button,1342242816

[CLS:CDlgInfo]
Type=0
HeaderFile=DlgInfo.h
ImplementationFile=DlgInfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgInfo
VirtualFilter=dWC

