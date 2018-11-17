#include <afxwin.h>
#include "Hello.h"
#include <math.h>
#define SEGMENTS 500
#define PI 3.1415926

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
	CRect rect;
	GetClientRect(&rect);
	int nWidth = rect.Width();
	int nHeight = rect.Height();

	CPaintDC dc(this);
	CPoint aPoint[SEGMENTS];

	for (int i = 0; i < SEGMENTS; i++)
	{
		aPoint[i].x = (i * nWidth) / SEGMENTS;
		aPoint[i].y = (int)((nHeight / 2) * (1 - (sin((2 * PI * i) / SEGMENTS))));
	}
	dc.Polyline(aPoint, SEGMENTS);
}
