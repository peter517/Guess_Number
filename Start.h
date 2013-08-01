#if !defined(AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_)
#define AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Start.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStart dialog

#include "Guess_Number.h"
#include "time.h"
#include "MyEdit.h"
//#include "SetDlg.h"
#define MAX 100

class CStart : public CDialog
{
// Construction
public:
	CStart(CWnd* pParent = NULL);   // standard constructor

	void Play();/*游戏开始*/
    CString   Judge(int Guess_Num);/*对输入数字进行判断*/

    int m_Max;  /*要猜的数字上限*/
    int Target; /*目标数字*/
    int m_Min; /*要猜的数字下限*/
	int Person; /*人猜的数*/
	int Computer; /*电脑猜的数*/
// Dialog Data
	//{{AFX_DATA(CStart)
	enum { IDD = IDD_DIALOG1 }; /*枚举*/
	CMyEdit	m_ctrlEdit; /*用来控制玩家输入数字的格式，位数等等，在CMyEdit里进行描述 Onchar 什么的*/
	int		m_Person_Guess; /*获得玩家所输入的数字*/
	CString	m_Info; /*在对话框下部显示游戏进展*/
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStart)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog(); 
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStart)
	afx_msg void OnButton1(); /*确认输入*/
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor); /*对整个对话框进行颜色控制*/
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/*void CStart::Set_Max()
{
  int Max;
  cout<<"请输入被猜数值的上限: ";
  cin>>Max;
  m_Max = Max;
}*/


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_)
