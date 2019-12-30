#pragma once
#include <afx.h>
#include "Paint3.h"
class Grap :
	public CObject
{
public:
	Grap(int Draw_Type,UINT m_width,
	UINT m_type,
	COLORREF m_color);
	Grap();
	void AddPoint(CPoint point1, CPoint point2);
	void AddPoint(CPoint point);
	void Draw(CDC* pdc);
public:DECLARE_SERIAL(Grap);
	~Grap();
public:
	UINT Draw_Type;
	UINT m_width;
	UINT m_type;
	COLORREF m_color;
	CArray<CPoint>points;
	virtual void Serialize(CArchive& ar);
};

