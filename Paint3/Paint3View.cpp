
// Paint3View.cpp: CPaint3View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Paint3.h"
#endif

#include "Paint3Doc.h"
#include "Paint3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "SetUp.h"



// CPaint3View

IMPLEMENT_DYNCREATE(CPaint3View, CView)

BEGIN_MESSAGE_MAP(CPaint3View, CView)
	ON_COMMAND(ID_DRAW_ELLIPSE, &CPaint3View::OnDrawEllipse)
	ON_COMMAND(ID_DRAW_LINE, &CPaint3View::OnDrawLine)
	ON_COMMAND(ID_DRAW_PEN, &CPaint3View::OnDrawPen)
	ON_COMMAND(ID_DRAW_RECT, &CPaint3View::OnDrawRect)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(ID_DRAW_ELLIPSE, &CPaint3View::OnUpdateDrawEllipse)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, &CPaint3View::OnUpdateDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_PEN, &CPaint3View::OnUpdateDrawPen)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, &CPaint3View::OnUpdateDrawRect)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FILE_SET_UP, &CPaint3View::OnFileSetUp)
END_MESSAGE_MAP()

// CPaint3View 构造/析构

CPaint3View::CPaint3View() noexcept
{
	// TODO: 在此处添加构造代码
	m_Draw_Type = Draw_Line;
	m_Is_Pen = FALSE;
	m_nwidth = 0;
	m_ntype = 0;
}

CPaint3View::~CPaint3View()
{
}

BOOL CPaint3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPaint3View 绘图

void CPaint3View::OnDraw(CDC* /*pDC*/)
{
	CPaint3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPaint3View 诊断

#ifdef _DEBUG
void CPaint3View::AssertValid() const
{
	CView::AssertValid();
}

void CPaint3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaint3Doc* CPaint3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaint3Doc)));
	return (CPaint3Doc*)m_pDocument;
}
#endif //_DEBUG


// CPaint3View 消息处理程序


void CPaint3View::OnDrawEllipse()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Ellipse;
}


void CPaint3View::OnDrawLine()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Line;
}


void CPaint3View::OnDrawPen()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Pen;
}


void CPaint3View::OnDrawRect()
{
	// TODO: 在此添加命令处理程序代码
	m_Draw_Type = Draw_Rect;
}


void CPaint3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(PS_SOLID, m_nwidth, RGB(1, 2, 3));

	CPen *oldpen = dc.SelectObject(&pen);
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
		m_Is_Pen = FALSE;
		break;
	default:
		break;
	}
	dc.SelectObject(oldpen);
	CView::OnLButtonUp(nFlags, point);
}


void CPaint3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_OldPoint = point;
	if (m_Draw_Type == Draw_Pen)
	{
		m_Is_Pen = TRUE;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CPaint3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(PS_SOLID, m_nwidth, RGB(1, 2, 3));

	CPen* oldpen = dc.SelectObject(&pen);

	CClientDC dc(this);
	if (m_Draw_Type == Draw_Pen&&m_Is_Pen)
	{
		dc.MoveTo(m_OldPoint);
		dc.LineTo(point);
		m_OldPoint = point;
	}
	CView::OnMouseMove(nFlags, point);
	dc.SelectObject(oldpen);
}


void CPaint3View::OnUpdateDrawEllipse(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Draw_Type == Draw_Ellipse);
}


void CPaint3View::OnUpdateDrawLine(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Draw_Type == Draw_Line);
}


void CPaint3View::OnUpdateDrawPen(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Draw_Type == Draw_Pen);
}


void CPaint3View::OnUpdateDrawRect(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_Draw_Type == Draw_Rect);
}


void CPaint3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu me;
	me.LoadMenu(IDR_MENU1);
	CMenu *menu = me.GetSubMenu(0);
	ClientToScreen(&point);
	menu->TrackPopupMenu(LVS_ALIGNLEFT, point.x, point.y, this);
	menu->Detach();
	CView::OnRButtonDown(nFlags, point);
	//me->Detach();
}


void CPaint3View::OnFileSetUp()
{
	// TODO: 在此添加命令处理程序代码
	SetUp setup;
	setup.m_nwidth = m_nwidth;
	setup.m_ntype =
	if (IDOK == setup.DoModal())
	{
		m_nwidth = setup.m_nwidth;
	}
}
