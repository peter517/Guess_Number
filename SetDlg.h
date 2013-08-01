#if !defined(AFX_SETDLG_H__4048C173_6F7C_44BF_866E_A7B91EB2B880__INCLUDED_)
#define AFX_SETDLG_H__4048C173_6F7C_44BF_866E_A7B91EB2B880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog

#include "MyEdit.h"

class CSetDlg : public CDialog
{
// Construction
public:

	CSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetDlg)
	enum { IDD = IDD_DIALOG3 };/*对话框命名*/
	CSpinButtonCtrl	m_SetMax; /*控制上限编辑框的初始值和范围*/
	CSpinButtonCtrl	m_SetMin; /*控制下限编辑框的初始值和范围*/
	int		m_IconStyle;      /*控制单选按钮*/
	int		m_Set_To_Start_Min; /*把下限参数值传给CStart框*/
	int		m_Set_To_Start_Max; /*把上限参数值传给CStart框*/
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDLG_H__4048C173_6F7C_44BF_866E_A7B91EB2B880__INCLUDED_)
