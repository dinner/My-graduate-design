// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__D19A592A_C4CD_4090_85DE_4DB2A7DB06B1__INCLUDED_)
#define AFX_STDAFX_H__D19A592A_C4CD_4090_85DE_4DB2A7DB06B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include   <afxdb.h>
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#include  <afxsock.h> 
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#define MAX_BUFFER_SIZE 2048	
#define WM_TEST WM_USER+102
struct Pag                         //数据包协议
{
	int nType;							//消息类型
	char Msg[200];						//发送的消息
	int nBack;							//登录时的回返参数
	int ID;								//发送方的客户端的ID号
	int FID;							//接受方的客户端的ID号
	int nPass;							//登录时提交的密码
	int nReback;						//
	char cNick[50];						//发送方的客户端的用户昵称
	char cFNick[50];					//接收方的客户端的用户昵称
	char Sound_Buffer[MAX_BUFFER_SIZE];	//声音消息
	int nFNum;							//好友个数
	char cFNickList[1024];				//好友列表
	int nState;							//状态
	int nSound;							//是否传送语音
	int nAge;							//年龄
	int nSex;							//性别 0为男性 1为女性
	int nRegist;						//注册 1为反馈	
	char cFOnline[10];					//在线好友 0为离线 1为在线
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__D19A592A_C4CD_4090_85DE_4DB2A7DB06B1__INCLUDED_)
