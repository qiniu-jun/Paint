// SetUp.cpp: 实现文件
//

#include "pch.h"
#include "Paint3.h"
#include "SetUp.h"
#include "afxdialogex.h"


// SetUp 对话框

IMPLEMENT_DYNAMIC(SetUp, CDialogEx)

SetUp::SetUp(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIA_SET_UP, pParent)
	, m_nwidth(0)
	, m_ntype(0)
{

}

SetUp::~SetUp()
{
}

void SetUp::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_nwidth);
	DDX_Slider(pDX, IDC_SLIDER1, m_nwidth);
	DDX_Radio(pDX, IDC_RADIO1, m_ntype);
}


BEGIN_MESSAGE_MAP(SetUp, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_COLOR, &SetUp::OnBnClickedButColor)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_RADIO1, &SetUp::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &SetUp::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &SetUp::OnBnClickedRadio3)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// SetUp 消息处理程序


BOOL SetUp::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CSliderCtrl* sli = (CSliderCtrl*)GetDlgItem(IDC_SLIDER1);
	sli->SetRange(1, 30);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void SetUp::OnBnClickedButColor()
{
	// TODO: 在此添加控件通知处理程序代码
	CColorDialog color;
	color.m_cc.Flags |= CC_RGBINIT;
	color.m_cc.rgbResult = m_color;
	if (IDOK == color.DoModal())
	{
		m_color = color.m_cc.rgbResult;
	}
	Invalidate();
}


void SetUp::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	UpdateData();
	CRect rect;
	GetDlgItem(IDC_STA)->GetWindowRect(rect);
	CPen pen(m_ntype, m_nwidth, m_color);
	CPen* oldpen = dc.SelectObject(&pen);
	ScreenToClient(rect);
	dc.MoveTo(rect.left + 20, rect.top + rect.Height() / 2);
	dc.LineTo(rect.right - 20, rect.top + rect.Height() / 2);
	dc.SelectObject(oldpen);
}


//void SetUp::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//	//Invalidate();
//}


void SetUp::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void SetUp::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void SetUp::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	Invalidate();
}


void SetUp::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
