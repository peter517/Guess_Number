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

    CString   Judge(int Guess_Num);/*���������ֽ����ж�*/

    int m_Max;  /*Ҫ�µ���������*/
	int m_Min; /*Ҫ�µ���������*/
    int m_targetNum; /*Ŀ������*/
	int m_personGuessNum; /*�˲µ���*/
	int m_computerGuessNum; /*���Բµ���*/
// Dialog Data
	//{{AFX_DATA(CStart)
	enum { IDD = IDD_DIALOG1 }; /*ö��*/
	CTextFormatCtrl	m_ctrlEdit; /*������������������ֵĸ�ʽ��λ���ȵȣ���CMyEdit��������� Onchar ʲô��*/
	int		m_guess_num; /*�����������������*/
	CString	m_Info; /*�ڶԻ����²���ʾ��Ϸ��չ*/
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
	afx_msg void OnBtnPersonGuess(); /*ȷ������*/
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor); /*�������Ի��������ɫ����*/
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif // !defined(AFX_START_H__7E3AEA50_BBD3_4C41_A77B_042EA2E1A907__INCLUDED_)
