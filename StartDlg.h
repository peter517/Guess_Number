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
#include "TextFormatCtrl.h"
//#include "SetDlg.h"
#define MAX 100

class CStartDlg : public CDialog
{
// Construction
public:
	CStartDlg(CWnd* pParent = NULL);   // standard constructor

    CString   Judge(int Guess_Num);/*对输入数字进行判断*/

    int m_Max;  /*要猜的数字上限*/
	int m_Min; /*要猜的数字下限*/
    int m_targetNum; /*目标数字*/
	int m_personGuessNum; /*人猜的数*/
	int m_computerGuessNum; /*电脑猜的数*/
// Dialog Data
	//{{AFX_DATA(CStart)
	enum { IDD = IDD_DIALOG1 }; /*枚举*/
	CTextFormatCtrl	m_ctrlEdit; /*用来控制玩家输入数字的格式，位数等等，在CMyEdit里进行描述 Onchar 什么的*/
	int		m_guess_num; /*获得玩家所输入的数字*/
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
	afx_msg void OnBtnPersonGuess(); /*确认输入*/
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor); /*对整个对话框进行颜色控制*/
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif // !defined(AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_)
