
// Paint2View.h: CPaint2View 类的接口
//

#pragma once

enum Draw_Type
{
	Draw_Line,
	Draw_Ellipse,
	Draw_Rect,
	Draw_Pen,
};

class CPaint2View : public CView
{
protected: // 仅从序列化创建
	CPaint2View() noexcept;
	DECLARE_DYNCREATE(CPaint2View)

// 特性
public:
	CPaint2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CPaint2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	Draw_Type m_Draw_Type;
public:
	afx_msg void OnDrawEllipse();
	afx_msg void OnDrawLine();
	afx_msg void OnDrawPen();
	afx_msg void OnDrawRect();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
protected:
	CPoint m_OldPoint;
};

#ifndef _DEBUG  // Paint2View.cpp 中的调试版本
inline CPaint2Doc* CPaint2View::GetDocument() const
   { return reinterpret_cast<CPaint2Doc*>(m_pDocument); }
#endif

