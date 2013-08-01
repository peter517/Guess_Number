// BKListBox.cpp : implementation file
//

#include "stdafx.h"
#include "Guess_Number.h"
#include "BKListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBKListBox
/*设置背景失败了*/

CBKListBox::CBKListBox()
{
m_brHollow.CreateStockObject(HOLLOW_BRUSH);  // 创建空心画刷
}

CBKListBox::~CBKListBox()
{
}

HBRUSH CBKListBox::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetBkMode(TRANSPARENT); // 设置背景透明模式
	return m_brHollow;	  // 返回空心画刷
}

BOOL CBKListBox::OnEraseBkgnd(CDC* pDC) 
{
	RECT rc;
	GetClientRect(&rc);  // 获取列表框客户区域
	int rcWidth = rc.right-rc.left;  // 列表框客户区域宽度
	int rcHeight = rc.bottom-rc.top;  // 列表框客户区域高度
	BITMAP bitmap;  // 位图句柄
	m_Bitmap.GetBitmap(&bitmap);  // 载入位图
	CDC dcMem;  // 内存绘图设备
	dcMem.CreateCompatibleDC(pDC);
	CBitmap* pOldBitmap = dcMem.SelectObject(&m_Bitmap);
	// 绘制背景位图
	pDC->StretchBlt(0,0,rcWidth,rcHeight,&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
	dcMem.SelectObject(pOldBitmap);	
	return CListBox::OnEraseBkgnd(pDC);
}

void CBKListBox::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	Invalidate();
	CListBox::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CBKListBox::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	Invalidate();	
	CListBox::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CBKListBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	Invalidate();	
	CListBox::OnLButtonDown(nFlags, point);
}

void CBKListBox::OnSelchange() 
{
	Invalidate();	
}

BEGIN_MESSAGE_MAP(CBKListBox, CListBox)
	//{{AFX_MSG_MAP(CBKListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBKListBox message handlers
