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
