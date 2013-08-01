// MyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "TextFormatCtrl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEdit

CTextFormatCtrl::CTextFormatCtrl()
{
}

CTextFormatCtrl::~CTextFormatCtrl()
{
}


BEGIN_MESSAGE_MAP(CTextFormatCtrl, CEdit)
	//{{AFX_MSG_MAP(CMyEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEdit message handlers

void CTextFormatCtrl::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{

    if((nChar>='0')&&(nChar<='9'))
	CEdit::OnChar(nChar, nRepCnt, nFlags);
}
