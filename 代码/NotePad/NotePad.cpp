// NotePad.cpp : Defines the class behaviors for the application.
// 定义应用程序的类行为。
// 该项目使用了MFC 对话框实现
#include "stdafx.h"
#include "NotePad.h"
#include "NotePadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotePadApp
//消息拦截了，捕获消息
BEGIN_MESSAGE_MAP(CNotePadApp, CWinApp)
	//{{AFX_MSG_MAP(CNotePadApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotePadApp construction
// CNotePadApp 构建
CNotePadApp::CNotePadApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNotePadApp object

CNotePadApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNotePadApp initialization
/* CNotePadApp初始化*/
BOOL CNotePadApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CNotePadDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
