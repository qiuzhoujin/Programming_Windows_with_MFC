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
	RECT rect;

	dc.SetBkMode(TRANSPARENT); // 如果背景模式为透明，则背景色将不再起作用。
	dc.SetBkColor(RGB(255, 0, 0));
	GetClientRect(&rect);

	dc.DrawText(TEXT("LAME"), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
