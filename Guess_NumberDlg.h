// Guess_NumberDlg.h : header file
//

#if !defined(AFX_GUESS_NUMBERDLG_H__C309904B_C915_4E9C_88B2_A5EAD462DB39__INCLUDED_)
#define AFX_GUESS_NUMBERDLG_H__C309904B_C915_4E9C_88B2_A5EAD462DB39__INCLUDED_

	// Added by ClassView
#include "StartDlg.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGuess_NumberDlg dialog

#include "windows.h"

#include "InfoDlg.h"                    /*这些头文件是必须包含的，一个Botton对应一个类一个头文件*/
#include "SetDlg.h"	

class CGuess_NumberDlg : public CDialog
{
// Construction
public:
	//CStart * m_InputDlg;
	CSetDlg * m_Set;/*指向游戏设置对话框*/
	CInfoDlg * m_Info;/*指向游戏介绍对话框*/
	CStartDlg * m_start;/*指向游戏开始对话框*/
	CGuess_NumberDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGuess_NumberDlg)
	enum { IDD = IDD_GUESS_NUMBER_DIALOG };
	//CBKListBox	m_list;/*设置背景的，没成功*/
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuess_NumberDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);/*点击对话框时要进行的数据交换*/	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGuess_NumberDlg)
	virtual BOOL OnInitDialog();/*对话框初始化*/
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);/*点击右上角关闭按钮时的控制函数*/
	afx_msg void OnPaint();/*很少用，设置对话框外观*/
	afx_msg HCURSOR OnQueryDragIcon();/*是当鼠标拖动到CWnd的窗口上的时候，系统自动调用这个函数来确定显示什么样的拖动图标*/
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUESS_NUMBERDLG_H__C309904B_C915_4E9C_88B2_A5EAD462DB39__INCLUDED_)
