
// PrintMonitoring.cpp : ���������� ��������� ������� ��� ����������.
//

#include "stdafx.h"
#include "PrintMonitoring.h"
#include "PrintMonitoringDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintMonitoringApp

BEGIN_MESSAGE_MAP(CPrintMonitoringApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
	ON_COMMAND(ID_EXIT_APP, &CPrintMonitoringApp::OnExitApp)
	ON_COMMAND(ID_OPENLOG, &CPrintMonitoringApp::OnOpenlog)
END_MESSAGE_MAP()


// �������� CPrintMonitoringApp

CPrintMonitoringApp::CPrintMonitoringApp()
{
	// ��������� ���������� ������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}


// ������������ ������ CPrintMonitoringApp

CPrintMonitoringApp theApp;


// ������������� CPrintMonitoringApp

BOOL CPrintMonitoringApp::InitInstance()
{
	// InitCommonControlsEx() ��������� ��� Windows XP, ���� ��������
	// ���������� ���������� ComCtl32.dll ������ 6 ��� ����� ������� ������ ��� ���������
	// ������ �����������.  � ��������� ������ ����� ��������� ���� ��� �������� ������ ����.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �������� ���� �������� ��� ��������� ���� ����� ������� ����������, ������� ���������� ������������
	// � ����� ����������.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ������� ��������� ��������, � ������, ���� ���������� ���� ��������
	// ������������� ������ �������� ��� �����-���� ��� �������� ����������.
	CShellManager *pShellManager = new CShellManager;

	// ��������� ����������� ���������� "������������ Windows" ��� ��������� ��������� ���������� MFC
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ����������� �������������
	SetRegistryKey(_T("Bilyk Studio"));

	CPrintMonitoringDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "��"
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ������� ��� ��� ��������� �������� ����������� ����
		//  � ������� ������ "������"
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "��������������. �� ������� ������� ���������� ����, ������� ������ ���������� ���������� ���������.\n");
		TRACE(traceAppMsg, 0, "��������������. ��� ������������� ��������� ���������� MFC ��� ����������� ���� ���������� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// ������� ��������� ��������, ��������� ����.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// ��������� ���������� ���� �������, ���������� �������� FALSE, ����� ����� ���� ����� ��
	//  ���������� ������ ������� ���������� ��������� ����������.
	return FALSE;
}



void CPrintMonitoringApp::OnExitApp()
{
	AfxGetMainWnd()->SendMessage(WM_CLOSE, 0, 0);
}


void CPrintMonitoringApp::OnOpenlog()
{
	if (GetFileAttributes(L"log.txt") != DWORD(-1)) {
		ShellExecute(NULL, NULL, L"log.txt", NULL, NULL, SW_RESTORE);
	}
	else
		MessageBox(NULL, L"File hasn`t created yet", L"Error", MB_ICONERROR);
}
