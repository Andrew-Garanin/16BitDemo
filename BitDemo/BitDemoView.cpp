
// BitDemoView.cpp: реализация класса CBitDemoView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "BitDemo.h"
#endif

#include "BitDemoDoc.h"
#include "BitDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBitDemoView

IMPLEMENT_DYNCREATE(CBitDemoView, CView)

BEGIN_MESSAGE_MAP(CBitDemoView, CView)
END_MESSAGE_MAP()

// Создание или уничтожение CBitDemoView

CBitDemoView::CBitDemoView() noexcept
{
	// TODO: добавьте код создания
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetObject(sizeof(BM), &BM);
	m_BitmapWidth = BM.bmWidth;
	m_BitmapHeight = BM.bmHeight;

}

CBitDemoView::~CBitDemoView()
{
}

BOOL CBitDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CBitDemoView

void CBitDemoView::OnDraw(CDC* pDC)
{
	CBitDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CDC MemDC;
	RECT ClientRect;
	// Создадим объект памяти КУ и выберем объект изображения 
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(&m_Bitmap);
	// Получим размеры окна представления 
	GetClientRect(&ClientRect);
	// Отобразим рисунок с растяжением или сжатием 
	pDC->StretchBlt
	(0, 0,              // верхний левый угол приемника
		ClientRect.right,  // ширина прямоугольника приемника
		ClientRect.bottom, // высота прямоугольника приемника
		&MemDC,            // объект КУ источника
		0, 0,              // верхний левый угол источника
		m_BitmapWidth,     // ширина прямоугольника источника
		m_BitmapHeight,    // высота прямоугольника источника
		SRCCOPY);          // код растровой операции

}


// Диагностика CBitDemoView

#ifdef _DEBUG
void CBitDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBitDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitDemoDoc* CBitDemoView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitDemoDoc)));
	return (CBitDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CBitDemoView
