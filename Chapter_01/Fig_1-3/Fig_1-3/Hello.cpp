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
	dc.SelectStockObject(NULL_PEN);
	dc.SelectStockObject(LTGRAY_BRUSH);
	dc.Ellipse(0, 0, 100, 100);
}
