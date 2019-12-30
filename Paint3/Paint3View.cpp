
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


// CPaint3View

IMPLEMENT_DYNCREATE(CPaint3View, CView)

BEGIN_MESSAGE_MAP(CPaint3View, CView)
END_MESSAGE_MAP()

// CPaint3View 构造/析构

CPaint3View::CPaint3View() noexcept
{
	// TODO: 在此处添加构造代码

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
