#pragma once


// SetUp 对话框

class SetUp : public CDialogEx
{
	DECLARE_DYNAMIC(SetUp)

public:
	SetUp(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetUp();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIA_SET_UP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:

//	CEdit m_nwidth;
//	UINT m_nwidth;
	int m_nwidth;
	virtual BOOL OnInitDialog();
	int m_ntype;
};
