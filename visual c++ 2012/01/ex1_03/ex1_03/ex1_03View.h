
// ex1_03View.h : Cex1_03View ��Ľӿ�
//

#pragma once


class Cex1_03View : public CView
{
protected: // �������л�����
	Cex1_03View();
	DECLARE_DYNCREATE(Cex1_03View)

// ����
public:
	Cex1_03Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cex1_03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ex1_03View.cpp �еĵ��԰汾
inline Cex1_03Doc* Cex1_03View::GetDocument() const
   { return reinterpret_cast<Cex1_03Doc*>(m_pDocument); }
#endif

