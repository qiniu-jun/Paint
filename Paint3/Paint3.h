﻿
// Paint3.h: Paint3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CPaint3App:
// 有关此类的实现，请参阅 Paint3.cpp
//

class CPaint3App : public CWinApp
{
public:
	CPaint3App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaint3App theApp;
