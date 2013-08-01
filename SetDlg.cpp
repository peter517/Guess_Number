// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetDlg.h"
#include "Guess_Number.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//m_hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//{{AFX_DATA_INIT(CSetDlg)
	m_IconStyle = 1; /*默认选第二个单选框*/
	m_Set_To_Start_Min = Set_To_Start_Min; /*获取中间值(全局变量) stdAfx.cpp里面定义，stdAfx.h里面声明*/
	m_Set_To_Start_Max = Set_To_Start_Max; /*获取中间值(全局变量)*/
	//}}AFX_DATA_INIT
}

BOOL CSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_SetMax.SetRange(1,1000);
	m_SetMax.SetPos(100);
	m_SetMin.SetRange(1,1000);
	m_SetMin.SetPos(1);

	return TRUE; 
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
	DDX_Control(pDX, IDC_SPIN2, m_SetMax);
	DDX_Control(pDX, IDC_SPIN1, m_SetMin);
	DDX_Radio(pDX, IDC_RADIO1, m_IconStyle);
	DDX_Text(pDX, IDC_EDIT1, m_Set_To_Start_Min);
	DDX_Text(pDX, IDC_EDIT2, m_Set_To_Start_Max);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnBtnSetOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

void CSetDlg::OnBtnSetOk() 
{
	UpdateData(TRUE);  // 获取用户输入

	if (m_IconStyle == 0)  
		; 
	else if (m_IconStyle == 1)
		;
	else 
		;
	if(m_Set_To_Start_Max>m_Set_To_Start_Min)
	{
		Set_To_Start_Max=m_Set_To_Start_Max;
		Set_To_Start_Min=m_Set_To_Start_Min;

		CDialog::OnOK(); /*关闭对话框*/
	}
	else
	{
		MessageBox(_T("您输入的要猜的数字的下限比上限要大，请重新输入!"),_T("提示"),MB_ICONWARNING|MB_OK);
	}
}
