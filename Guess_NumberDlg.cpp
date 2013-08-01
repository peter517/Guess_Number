// Guess_NumberDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Guess_NumberDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog/*�ֶ�����һ����*/
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuess_NumberDlg dialog

CGuess_NumberDlg::CGuess_NumberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGuess_NumberDlg::IDD, pParent)/*���캯��*/
{
	//{{AFX_DATA_INIT(CGuess_NumberDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGuess_NumberDlg::DoDataExchange(CDataExchange* pDX)/*�����õ�*/
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGuess_NumberDlg)
	//DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGuess_NumberDlg, CDialog)
	//{{AFX_MSG_MAP(CGuess_NumberDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuess_NumberDlg message handlers

BOOL CGuess_NumberDlg::OnInitDialog()/*�Ի����ʼ��*/
{
	CDialog::OnInitDialog();/*����Ǳ����*/

	// Add "About..." menu item to system menu.
    //m_list.m_Bitmap.LoadBitmap(IDB_BITMAP1);  // ����λͼ��Դ

    //m_list.AddString(_T("Ϊ�б���ؼ�����λͼ����"));  
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGuess_NumberDlg::OnSysCommand(UINT nID, LPARAM lParam)/*������Ͻǹرհ�ťʱ�Ŀ��ƺ���*/
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
        CAboutDlg dlgAbout;
		dlgAbout.DoModal();


	}

	else/*һ�㶼���������*/
	{

		CDialog::OnSysCommand(nID, lParam);
	/*	if(MessageBox("�Ƿ����Ҫ�˳�!","��ʾ",MB_ICONWARNING|MB_YESNO)==IDYES)/*IDYES�� int��
		{
        MessageBox("лл�������棬��ӭ�´�����!","��ʾ",MB_ICONASTERISK|MB_OK);
        CDialog::OnOK();/*�رնԻ���
		}
		else
        ;*/
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGuess_NumberDlg::OnPaint() /*�����ã����öԻ������*/
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);


		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else/*���ӱ������֣��򵥵���������һ��*/
	{

     CPaintDC dc(this); // device context for painting

     CString string1,string2,string3;
     string1="             Guess!";
	 string2="Guess!";
	 string3="Guess!";
     CFont m_fontLogo;

     m_fontLogo.CreateFont(44, 0, 0, 0, 55, FALSE, FALSE,0,0,0,0,0,0, _T("Arial")); 

     dc.SetBkMode(TRANSPARENT);
     CRect rectText;
     GetClientRect(&rectText);
     CFont * OldFont = dc.SelectObject(&m_fontLogo);

     COLORREF OldColor = dc.SetTextColor( ::GetSysColor( COLOR_3DHILIGHT));

     dc.DrawText( string1, rectText+CPoint(1,1) , DT_SINGLELINE | DT_LEFT | DT_VCENTER|DT_CENTER);/*����������ʾ��λ��*/
     dc.SetTextColor( ::GetSysColor( COLOR_3DSHADOW));
     dc.DrawText( string1, rectText, DT_SINGLELINE | DT_RIGHT | DT_VCENTER|DT_CENTER); 

	 dc.DrawText( string2, rectText+CPoint(15,45) , DT_SINGLELINE | DT_LEFT );

	 dc.DrawText( string3, rectText+CPoint(15,120) , DT_SINGLELINE | DT_LEFT );
	 

     dc.SetTextColor( OldColor);
     dc.SelectObject(OldFont);



	//CPaintDC dc(this);
	//CRect rect;
	//	GetClientRect(rect);
		
	//	dc.FillSolidRect(rect, RGB(0,0,255));������ɫ�����ɫ
	//	CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGuess_NumberDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGuess_NumberDlg::OnButton1()   /*DoModal()��ʾ����һֱͣ����ǰ��*/
{
	m_start = new CStart;
	m_start->DoModal();	
}

void CGuess_NumberDlg::OnButton2() 
{
   m_Info = new CInfoDlg; 
   m_Info->DoModal();
}

void CGuess_NumberDlg::OnButton3() 
{
	 m_Set = new CSetDlg; 
     m_Set->DoModal();	
}

void CGuess_NumberDlg::OnButton4() 
{
   if(MessageBox(_T("�Ƿ����Ҫ�˳�!"),_T("��ʾ"),MB_ICONWARNING|MB_YESNO|MB_TOPMOST)==IDYES)
   {
   MessageBox(_T("лл�������棬��ӭ�´�����!"),_T("��ʾ"),MB_ICONASTERISK|MB_OK);
   CDialog::OnOK();/*�رնԻ���*/
   }
}