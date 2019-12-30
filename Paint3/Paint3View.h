
// Paint3View.h: CPaint3View 类的接口
//

#pragma once


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
};

#ifndef _DEBUG  // Paint3View.cpp 中的调试版本
inline CPaint3Doc* CPaint3View::GetDocument() const
   { return reinterpret_cast<CPaint3Doc*>(m_pDocument); }
#endif

