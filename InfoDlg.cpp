// InfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "InfoDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog


CInfoDlg::CInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInfoDlg::IDD, pParent)
{

	//{{AFX_DATA_INIT(CInfoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

BOOL CInfoDlg::OnInitDialog()/*给每个选项卡命名和赋值*/
{
  CDialog::OnInitDialog();

  m_tab.InsertItem(0,_T("游戏规则"),0);
  m_tab.InsertItem(1,_T("软件信息"),1);

  return TRUE; 
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoDlg)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CInfoDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg message handlers

void CInfoDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
 int nTab=m_tab.GetCurSel();/*获取玩家对对话框的选择，数值化*/
 if(nTab==0)
 {
   GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);/*显示第一个静态文本*/
   GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
 }
 else
 {
    GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);/*显示第二个静态文本*/
    GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
 }
	*pResult = 0;
}
