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
	CRect rect;
	GetClientRect(&rect);

	CFont font;
	font.CreatePointFont(720, TEXT("Lucida Console"));

	CPaintDC dc(this);
	dc.SelectObject(&font);
	dc.SetBkMode(TRANSPARENT);

	CString string = TEXT("Hello, MFC");
	rect.OffsetRect(16, 16);
	dc.SetTextColor(RGB(192, 192, 192));
	dc.DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	rect.OffsetRect(-16, -16);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.DrawText(string, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
