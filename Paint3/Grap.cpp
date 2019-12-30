#include "pch.h"
#include "Grap.h"

IMPLEMENT_SERIAL(Grap, CObject, 1);
Grap::Grap(int Draw_Type,UINT width, UINT type, COLORREF color):m_color(color)
,m_type(type),m_width(width),Draw_Type(Draw_Type)
{
}

Grap::Grap()
{
}

void Grap::AddPoint(CPoint point1, CPoint point2)
{
	points.Add(point1);
	points.Add(point2);
}

void Grap::AddPoint(CPoint point)
{
	points.Add(point);
}

void Grap::Draw(CDC* pdc)
{
	int len = 0;
	switch (Draw_Type)
	{
	case Draw_Line:
		pdc->MoveTo(points.GetAt(0));
		pdc->LineTo(points.GetAt(1));
		break;
	case Draw_Ellipse:
		pdc->Ellipse(points.GetAt(0).x, points.GetAt(0).y, points.GetAt(1).x, points.GetAt(1).y);
		break;
	case Draw_Rect:
		pdc->Rectangle(points.GetAt(0).x, points.GetAt(0).y, points.GetAt(1).x, points.GetAt(1).y);
		break;
	case Draw_Pen:
		len =points.GetSize();
		for (int i = 0; i < len;)
		{
			pdc->MoveTo(points.GetAt(i));
			if (++i < len)
				pdc->LineTo(points.GetAt(i));
		}
		break;
	default:
		break;
	}
}

Grap::~Grap()
{
}


void Grap::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << Draw_Type << m_width << m_type << m_color;
	}
	else
	{	// loading code
		ar >> Draw_Type >> m_width >> m_type >> m_color;
	}
	points.Serialize(ar);
}
