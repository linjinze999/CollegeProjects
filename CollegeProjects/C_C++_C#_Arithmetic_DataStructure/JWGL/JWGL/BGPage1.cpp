// BGPage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGPage1.h"
#include "afxdialogex.h"
#include "BGAddTeacherUser.h"
#include "BGAddStudentUser.h"


// BGPage1 �Ի���

IMPLEMENT_DYNAMIC(BGPage1, CPropertyPage)

BGPage1::BGPage1()
	: CPropertyPage(BGPage1::IDD)
{

}

BGPage1::~BGPage1()
{
}

void BGPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BGPage1, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON2, &BGPage1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &BGPage1::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// BGPage1 ��Ϣ�������


void BGPage1::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBGAddTeacherUser atu;
	atu.DoModal();
}


void BGPage1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBGAddStudentUser asu;
	asu.DoModal();
}


void BGPage1::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
    CRect   rect;   
    GetClientRect(&rect);   
    CDC   dcMem;   
    dcMem.CreateCompatibleDC(&dc);   
    CBitmap   bmpBackground;   
    bmpBackground.LoadBitmap(IDB_BITMAP1);   
    BITMAP   bitmap;   
    bmpBackground.GetBitmap(&bitmap);   
    CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
    bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// ��Ϊ��ͼ��Ϣ���� CPropertyPage::OnPaint()
	
}
