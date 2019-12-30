
// Paint2View.cpp: CPaint2View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Paint2.h"
#endif

#include "Paint2Doc.h"
#include "Paint2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaint2View

IMPLEMENT_DYNCREATE(CPaint2View, CView)

BEGIN_MESSAGE_MAP(CPaint2View, CView)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CPaint2View::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, &CPaint2View::OnDrawLine)
	ON_COMMAND(ID_DRAW_PEN, &CPaint2View::OnDrawPen)
	ON_COMMAND(ID_DRAW_RECT, &CPaint2View::OnDrawRect)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CPaint2View 构造/析构

CPaint2View::CPaint2View() noexcept
{
	// TODO: 在此处添加构造代码

}

CPaint2View::~CPaint2View()
{
}

BOOL CPaint2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPaint2View 绘图

void CPaint2View::OnDraw(CDC* /*pDC*/)
{
	CPaint2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPaint2View 诊断

#ifdef _DEBUG
void CPaint2View::AssertValid() const
{
	CView::AssertValid();
}

void CPaint2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaint2Doc* CPaint2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaint2Doc)));
	return (CPaint2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPaint2View 消息处理程序


void CPaint2View::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Ellipse;
}


void CPaint2View::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Line;
}


void CPaint2View::OnDrawPen()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Pen;
}


void CPaint2View::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Rect;
}


void CPaint2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	switch (m_Draw_Type)
	{
	case Draw_Line:
		dc.MoveTo(m_OldPoint);
		dc.LineTo(point);
		break;
	case Draw_Ellipse:
		dc.Ellipse(m_OldPoint.x, m_OldPoint.y, point.x, point.y);
		break;
	case Draw_Rect:
		dc.Rectangle(m_OldPoint.x, m_OldPoint.y, point.x, point.y);
		break;
	case Draw_Pen:

		break;
	default:
		break;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CPaint2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_OldPoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void CPaint2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
