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
// CStart dialog��

/*û�г�ʼ��������*/


CStartDlg::CStartDlg(CWnd* pParent /*=NULL*/)/*���캯������ʼ��*/
	: CDialog(CStartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStart)

	m_guess_num = 0; 
	m_Max = Set_To_Start_Max; /*���޸����������洫���Ĳ�����ʼ��*/
	m_Min = Set_To_Start_Min; /*ͬ��*/
	m_personGuessNum = 0;
	m_computerGuessNum = 0;
	m_Info = _T("");/*CString���͵ĳ�ʼ��*/
	//}}AFX_DATA_INIT

}

BOOL CStartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	srand(time(NULL));
	m_targetNum = rand()%m_Max + 1;/*�������һ��Ŀ����*/

	int maxBitLen=1;
	int tmp=Set_To_Start_Max;
	while(tmp/10!=0)
	{
		maxBitLen++; 
		tmp=tmp/10;
	}

	m_ctrlEdit.SetLimitText(maxBitLen);/*��������������ֵ�λ��*/

	CString str1,str;

	str.Format(_T("������Ҫ�µ����ַ�Χ:%d--%d"),m_Min,m_Max);

	/* MessageBox(str,"��ʾ",MB_ICONASTERISK|MB_OK|MB_RIGHT);*/

	m_Info = str;/*�Ի����·���ʾstr����Ϣ*/
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
			MessageBox(_T("�����������֣�����ʤ��!"),_T("��ʾ"),MB_ICONWARNING|MB_OK);
			str.Format(_T("�����������֣�����ʤ��!"));
		}
		else{
			MessageBox(_T("�����������֣����Ի�ʤ!"),_T("��ʾ"),MB_ICONWARNING|MB_OK);
		}

		str.Format(_T("�����������֣����Ի�ʤ!"));
		//if(MessageBox("�Ƿ����Ҫ����?","��ʾ",MB_ICONASTERISK|MB_YESNO)==IDYES)
		//CStart::OnButton1();
		CDialog::OnOK(); 

		return str;
	}

	else if(Guess_Num>m_targetNum) 
	{
		m_Max = Guess_Num;/*�ı�������ֵ������*/

		str.Format(_T(" Ҫ�µ����ַ�Χ:%d--%d"),m_Min,m_Max);
		MessageBox(str,_T("��ʾ"),MB_ICONASTERISK|MB_OK|MB_RIGHT);

		return str;
	}

	else if(Guess_Num<m_targetNum)
	{
		m_Min = Guess_Num;/*�ı�������ֵ������*/

		str.Format(_T(" Ҫ�µ����ַ�Χ:%d--%d"),m_Min,m_Max);
		MessageBox(str,_T("��ʾ"),MB_ICONASTERISK|MB_OK|MB_RIGHT);

		return str;
	}
	return str;
}

void CStartDlg::OnBtnPersonGuess() 
{
	CString str;

	UpdateData(TRUE);/*��ȡ�༭���������*/
	m_personGuessNum = m_guess_num;

	if((m_personGuessNum>=m_Max)||(m_personGuessNum<=m_Min)){
		MessageBox(_T("�밴��Ϸ��������!"),_T("��ʾ"),MB_ICONWARNING|MB_OK|MB_RIGHT);  
	}
	else
	{ 
		m_Info=Judge(m_personGuessNum);

		if(m_personGuessNum!=m_targetNum)
		{

			m_computerGuessNum = m_Min+rand()%(m_Max-m_Min-1)+1;/*�ӿ����ѡ��*/

			str.Format(_T("���Բµ����� %d"), m_computerGuessNum);
			MessageBox(str,_T("��ʾ"),MB_ICONASTERISK|MB_OK);

			m_Info=Judge(m_computerGuessNum);

			UpdateData(FALSE);/*���¶Ի���������ı�����*/

		}
	} 

}

HBRUSH CStartDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if(pWnd->GetDlgCtrlID()==IDC_STATIC1)/*��ID��ΪIDC_STATIC1���ı��������ɫ����*/
	{
		pDC->SetTextColor(RGB(255,0,0));
	}


	return hbr;
}

