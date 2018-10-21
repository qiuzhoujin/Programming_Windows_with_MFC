#include <afxwin.h>
#include "Hello.h"

CMyApp myApp;

///////////////////////////////////////////////////////
// CMyApp member functions
BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

///////////////////////////////////////////////////////
// CMainWindow message map and member functions
BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	Create(NULL, TEXT("The Hello Application"));
}

void CMainWindow::OnPaint()
{
	CPaintDC dc(this);
	CClientDC cdc(this);
	int cx = cdc.GetDeviceCaps(HORZRES);
	int cy = cdc.GetDeviceCaps(VERTRES);
	CString str;
	str.Format(TEXT("cx:%d, cy:%d"), cx, cy);

	CRect rect;
	GetClientRect(&rect);

	dc.DrawText(str, -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}