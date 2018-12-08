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
	static int x1 = 104, y1 = 100;
	static int x2 = x1 + 150, y2 = y1 + 100;

	CBrush brush(HS_DIAGCROSS, RGB(255, 255, 255));
	CPoint point(x1, y1);
	dc.LPtoDP(&point);
	point.x %= 8;
	point.y %= 8;
	brush.UnrealizeObject();
	dc.SetBrushOrg(point);
	dc.SelectObject(&brush);
	dc.SetBkColor(RGB(192, 192, 192));
	dc.Rectangle(x1, y1, x2, y2);
}
