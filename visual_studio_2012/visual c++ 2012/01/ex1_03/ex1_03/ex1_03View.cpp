
// ex1_03View.cpp : Cex1_03View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ex1_03.h"
#endif

#include "ex1_03Doc.h"
#include "ex1_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cex1_03View

IMPLEMENT_DYNCREATE(Cex1_03View, CView)

BEGIN_MESSAGE_MAP(Cex1_03View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cex1_03View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cex1_03View ����/����

Cex1_03View::Cex1_03View()
{
	// TODO: �ڴ˴���ӹ������

}

Cex1_03View::~Cex1_03View()
{
}

BOOL Cex1_03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cex1_03View ����

void Cex1_03View::OnDraw(CDC* /*pDC*/)
{
	Cex1_03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cex1_03View ��ӡ


void Cex1_03View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cex1_03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cex1_03View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cex1_03View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Cex1_03View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cex1_03View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cex1_03View ���

#ifdef _DEBUG
void Cex1_03View::AssertValid() const
{
	CView::AssertValid();
}

void Cex1_03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cex1_03Doc* Cex1_03View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cex1_03Doc)));
	return (Cex1_03Doc*)m_pDocument;
}
#endif //_DEBUG


// Cex1_03View ��Ϣ�������
