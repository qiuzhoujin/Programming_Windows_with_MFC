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
	int nPlanes = cdc.GetDeviceCaps(PLANES);
	int nBPP = cdc.GetDeviceCaps(BITSPIXEL);
	int nColors = 1 << (nPlanes * nBPP);
	CString str;
	str.Format(TEXT("nPlanes:%d, nBPP:%d, nColors:%d"), nPlanes, nBPP, nColors);

	CRect rect;
	GetClientRect(&rect);

	dc.DrawText(str, -1, &rect,
		DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	dc.MoveTo(10, 10);
	dc.LineTo(500, 600);
	dc.LineTo(600, 600);
}
