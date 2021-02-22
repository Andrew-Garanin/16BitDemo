
// BitDemoView.h: интерфейс класса CBitDemoView
//

#pragma once


class CBitDemoView : public CView
{
protected: // создать только из сериализации
	CBitDemoView() noexcept;
	DECLARE_DYNCREATE(CBitDemoView)
protected:
	CBitmap m_Bitmap;
	int m_BitmapHeight;
	int m_BitmapWidth;

// Атрибуты
public:
	CBitDemoDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CBitDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в BitDemoView.cpp
inline CBitDemoDoc* CBitDemoView::GetDocument() const
   { return reinterpret_cast<CBitDemoDoc*>(m_pDocument); }
#endif

