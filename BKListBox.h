#if !defined(AFX_BKLISTBOX_H__A344C957_54C5_45B8_93F3_47D88867735A__INCLUDED_)
#define AFX_BKLISTBOX_H__A344C957_54C5_45B8_93F3_47D88867735A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BKListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBKListBox window

/*…Ë÷√±≥æ∞ ß∞‹¡À*/

class CBKListBox : public CListBox
{
// Construction
public:
	CBKListBox();
	CBitmap m_Bitmap;
	CBrush m_brHollow;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBKListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBKListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBKListBox)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSelchange();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BKLISTBOX_H__A344C957_54C5_45B8_93F3_47D88867735A__INCLUDED_)
