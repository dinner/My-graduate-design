; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Server.h"

ClassCount=10
Class1=CServerApp
Class2=CServerDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_SERVER_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DLG_CLIENTLINK
Resource4=IDR_MENU_INFO
Class4=CDlgClientLink
Class5=CDlgClientInfo
Class6=CServerSocket
Resource5=IDD_ABOUTBOX
LastClass=CClientSocket
Resource6=IDD_DLG_INFO
Class7=CUserSet
Resource7=IDR_MENU_LINK
Class8=CUserFriend
Resource8=IDD_DLG_CLIENTINFO
Class9=CDlgInfo
Class10=CClientSocket
Resource9=IDR_ACCELERATOR

[CLS:CServerApp]
Type=0
HeaderFile=Server.h
ImplementationFile=Server.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CServerDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ServerDlg.h
ImplementationFile=ServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SERVER_DIALOG]
Type=1
Class=CServerDlg
ControlCount=1
Control1=IDC_TAB_MENU,SysTabControl32,1342177536

[DLG:IDD_DLG_CLIENTLINK]
Type=1
Class=CDlgClientLink
ControlCount=5
Control1=IDC_EDIT_PORT,edit,1350631552
Control2=IDC_BUT_LINK,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_LIST_CLIENTONOFF,SysListView32,1350631425

[DLG:IDD_DLG_CLIENTINFO]
Type=1
Class=CDlgClientInfo
ControlCount=2
Control1=IDC_STATIC,button,1342177287
Control2=IDC_LIST_CLIENTINFO,SysListView32,1350631425

[CLS:CDlgClientLink]
Type=0
HeaderFile=DlgClientLink.h
ImplementationFile=DlgClientLink.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_MENUITEM_CLEAR
VirtualFilter=dWC

[CLS:CDlgClientInfo]
Type=0
HeaderFile=DlgClientInfo.h
ImplementationFile=DlgClientInfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgClientInfo
VirtualFilter=dWC

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[MNU:IDR_MENU_INFO]
Type=1
Class=CDlgClientInfo
Command1=IDC_MENUITEM_ADD
Command2=IDC_MENUITEM_MODIFY
Command3=IDC_MENUITEM_DEL
CommandCount=3

[CLS:CUserSet]
Type=0
HeaderFile=UserSet.h
ImplementationFile=UserSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CUserSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[ID], 5, 2
Column2=[NICK], 12, 100
Column3=[PASS], 4, 4
Column4=[SEX], 12, 100
Column5=[AGE], 4, 4
Column6=[REGISTERTIME], 11, 16

[MNU:IDR_MENU_LINK]
Type=1
Class=CDlgClientLink
Command1=IDC_MENUITEM_CLEAR
CommandCount=1

[DLG:IDD_DLG_INFO]
Type=1
Class=CDlgInfo
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_NICK,edit,1350631552
Control6=IDC_EDIT_PASS,edit,1350631552
Control7=IDC_EDIT_AGE,edit,1350631552
Control8=IDC_STATIC,button,1342177287
Control9=IDC_RADIO_MAN,button,1342177289
Control10=IDC_RADIO_WOMAN,button,1342177289
Control11=IDC_BUT_CONFERM,button,1342242816
Control12=IDC_BUT_CONCEL,button,1342242816

[CLS:CUserFriend]
Type=0
HeaderFile=UserFriend.h
ImplementationFile=UserFriend.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CUserFriend

[DB:CUserFriend]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[NUM], 4, 4
Column2=[UFID], 5, 2
Column3=[UFNICK], 12, 100
Column4=[UFFID], 5, 2
Column5=[UFFNICK], 12, 100

[ACL:IDR_ACCELERATOR]
Type=1
Class=CDlgClientInfo
Command1=ID_EXCUTE
CommandCount=1

[CLS:CDlgInfo]
Type=0
HeaderFile=DlgInfo.h
ImplementationFile=DlgInfo.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgInfo
VirtualFilter=dWC

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

