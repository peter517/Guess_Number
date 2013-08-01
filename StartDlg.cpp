// Start.cpp : implementation file
//

#include "stdafx.h"
#include "StartDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStart dialog、

/*没有初始化过对象*/


CStartDlg::CStartDlg(CWnd* pParent /*=NULL*/)/*构造函数，初始化*/
	: CDialog(CStartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStart)

	m_guess_num = 0; 
	m_Max = Set_To_Start_Max; /*上限根据设置里面传来的参数初始化*/
	m_Min = Set_To_Start_Min; /*同上*/
	m_personGuessNum = 0;
	m_computerGuessNum = 0;
	m_Info = _T("");/*CString类型的初始化*/
	//}}AFX_DATA_INIT

}

BOOL CStartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	srand(time(NULL));
	m_targetNum = rand()%m_Max + 1;/*随机产生一个目标数*/

	int maxBitLen=1;
	int tmp=Set_To_Start_Max;
	while(tmp/10!=0)
	{
		maxBitLen++; 
		tmp=tmp/10;
	}

	m_ctrlEdit.SetLimitText(maxBitLen);/*限制玩家输入数字的位数*/

	CString str1,str;

	str.Format(_T("您本次要猜的数字范围:%d--%d"),m_Min,m_Max);

	/* MessageBox(str,"提示",MB_ICONASTERISK|MB_OK|MB_RIGHT);*/

	m_Info = str;/*对话框下方显示str的信息*/
	UpdateData(FALSE);

	return TRUE;
}

void CStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStart)
	DDX_Control(pDX, IDC_EDIT1, m_ctrlEdit);
	DDX_Text(pDX, IDC_EDIT1, m_guess_num);
	DDX_Text(pDX, IDC_STATIC1, m_Info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStartDlg, CDialog)
	//{{AFX_MSG_MAP(CStart)
	ON_BN_CLICKED(IDC_BUTTON1, OnBtnPersonGuess)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStart message handlers
CString  CStartDlg::Judge(int Guess_Num)
{

	CString str1,str;

	if(m_personGuessNum==m_targetNum || m_computerGuessNum==m_targetNum)
	{

		if(m_computerGuessNum==m_targetNum)
		{
			MessageBox(_T("电脑中了数字，您获胜了!"),_T("提示"),MB_ICONWARNING|MB_OK);
			str.Format(_T("电脑中了数字，您获胜了!"));
		}
		else{
			MessageBox(_T("您猜中了数字，电脑获胜!"),_T("提示"),MB_ICONWARNING|MB_OK);
		}

		str.Format(_T("您猜中了数字，电脑获胜!"));
		//if(MessageBox("是否真的要继续?","提示",MB_ICONASTERISK|MB_YESNO)==IDYES)
		//CStart::OnButton1();
		CDialog::OnOK(); 

		return str;
	}

	else if(Guess_Num>m_targetNum) 
	{
		m_Max = Guess_Num;/*改变所猜数值的上限*/

		str.Format(_T(" 要猜的数字范围:%d--%d"),m_Min,m_Max);
		MessageBox(str,_T("提示"),MB_ICONASTERISK|MB_OK|MB_RIGHT);

		return str;
	}

	else if(Guess_Num<m_targetNum)
	{
		m_Min = Guess_Num;/*改变所猜数值的下限*/

		str.Format(_T(" 要猜的数字范围:%d--%d"),m_Min,m_Max);
		MessageBox(str,_T("提示"),MB_ICONASTERISK|MB_OK|MB_RIGHT);

		return str;
	}
	return str;
}

void CStartDlg::OnBtnPersonGuess() 
{
	CString str;

	UpdateData(TRUE);/*获取编辑框里的数据*/
	m_personGuessNum = m_guess_num;

	if((m_personGuessNum>=m_Max)||(m_personGuessNum<=m_Min)){
		MessageBox(_T("请按游戏规则输入!"),_T("提示"),MB_ICONWARNING|MB_OK|MB_RIGHT);  
	}
	else
	{ 
		m_Info=Judge(m_personGuessNum);

		if(m_personGuessNum!=m_targetNum)
		{

			m_computerGuessNum = m_Min+rand()%(m_Max-m_Min-1)+1;/*加快电脑选数*/

			str.Format(_T("电脑猜的数是 %d"), m_computerGuessNum);
			MessageBox(str,_T("提示"),MB_ICONASTERISK|MB_OK);

			m_Info=Judge(m_computerGuessNum);

			UpdateData(FALSE);/*更新对话框里面的文本数据*/

		}
	} 

}

HBRUSH CStartDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)/*对ID号为IDC_STATIC1的文本框进行颜色更改*/
	{
		pDC->SetTextColor(RGB(255,0,0));
	}


	return hbr;
}

