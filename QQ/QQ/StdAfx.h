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
struct Pag                         //���ݰ�Э��
{
	int nType;							//��Ϣ����
	char Msg[200];						//���͵���Ϣ
	int nBack;							//��¼ʱ�Ļط�����
	int ID;								//���ͷ��Ŀͻ��˵�ID��
	int FID;							//���ܷ��Ŀͻ��˵�ID��
	int nPass;							//��¼ʱ�ύ������
	int nReback;						//
	char cNick[50];						//���ͷ��Ŀͻ��˵��û��ǳ�
	char cFNick[50];					//���շ��Ŀͻ��˵��û��ǳ�
	char Sound_Buffer[MAX_BUFFER_SIZE];	//������Ϣ
	int nFNum;							//���Ѹ���
	char cFNickList[1024];				//�����б�
	int nState;							//״̬
	int nSound;							//�Ƿ�������
	int nAge;							//����
	int nSex;							//�Ա� 0Ϊ���� 1ΪŮ��
	int nRegist;						//ע�� 1Ϊ����	
	char cFOnline[10];					//���ߺ��� 0Ϊ���� 1Ϊ����
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__D19A592A_C4CD_4090_85DE_4DB2A7DB06B1__INCLUDED_)
