﻿
// Paint3View.h: CPaint3View 类的接口
//

#pragma once
#include "Grap.h"


class CPaint3View : public CView
{
protected: // 仅从序列化创建
	CPaint3View() noexcept;
	DECLARE_DYNCREATE(CPaint3View)

// 特性
public:
	CPaint3Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CPaint3View();
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
	bool m_Is_Pen;
public:
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawPen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileSetUp();
	UINT m_nwidth;
	int m_ntype;
	COLORREF m_color;
	CArray<Grap*> Graps;
	Grap* PenGrap;
//	virtual void Serialize(CArchive& ar);
};

#ifndef _DEBUG  // Paint3View.cpp 中的调试版本
inline CPaint3Doc* CPaint3View::GetDocument() const
   { return reinterpret_cast<CPaint3Doc*>(m_pDocument); }
#endif

