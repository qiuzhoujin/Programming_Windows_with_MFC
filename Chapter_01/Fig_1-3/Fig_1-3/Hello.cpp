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
	CString str;

	CPaintDC dc(this);
	dc.SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
	dc.SetBkMode(TRANSPARENT);

	for (int i = 0; i < 3600; i += 150)
	{
		LOGFONT lf;
		::ZeroMemory(&lf, sizeof(lf));
		lf.lfHeight = 160;
		lf.lfWeight = FW_BOLD;
		lf.lfEscapement = i;
		lf.lfOrientation = i;
		::lstrcpy(lf.lfFaceName, TEXT("Lucida Console"));
		CFont font;
		font.CreatePointFontIndirect(&lf);

		CFont *pOldFont = dc.SelectObject(&font);
		str.Format(TEXT("%s[%d]"), TEXT("     Hello, MFC"), i / 10);
		dc.TextOut(0, 0, str);
		dc.SelectObject(pOldFont);
	}
}
