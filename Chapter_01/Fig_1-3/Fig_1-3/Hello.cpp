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

	CRect rect;
	GetClientRect(&rect);

	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	dc.SetMapMode(MM_ISOTROPIC);
	//dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(500, 500);
	dc.SetViewportExt(rect.Width(), rect.Height());
	dc.Ellipse(0, 0, 500, 500);
	
	/*
	dc.DrawText(TEXT("Hello, MFC"), -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	*/
}
