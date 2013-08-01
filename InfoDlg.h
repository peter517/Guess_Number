#if !defined(AFX_INFODLG_H__50E43955_F68B_486E_BCCC_55CB32770FD4__INCLUDED_)
#define AFX_INFODLG_H__50E43955_F68B_486E_BCCC_55CB32770FD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfoDlg dialog
#include "Guess_Number.h"/*必须的 要基于CDialog的调用*/

class CInfoDlg : public CDialog
{
// Construction
public:
	CInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInfoDlg)
	enum { IDD = IDD_DIALOG2 };/*对话框的ID号为……*/
	CTabCtrl	m_tab; /*控制选项卡的变量*/
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfoDlg)
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);/*控制选项卡*/
    virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFODLG_H__50E43955_F68B_486E_BCCC_55CB32770FD4__INCLUDED_)
