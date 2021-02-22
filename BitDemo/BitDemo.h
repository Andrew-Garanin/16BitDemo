
// BitDemo.h: основной файл заголовка для приложения BitDemo
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CBitDemoApp:
// Сведения о реализации этого класса: BitDemo.cpp
//

class CBitDemoApp : public CWinApp
{
public:
	CBitDemoApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBitDemoApp theApp;
