// TeacherPage4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherPage4.h"
#include "afxdialogex.h"
#include "TeacherModifyPassword.h"
#include "ClassTeacher.h"

// CTeacherPage4 �Ի���

IMPLEMENT_DYNAMIC(CTeacherPage4, CPropertyPage)

CTeacherPage4::CTeacherPage4()
	: CPropertyPage(CTeacherPage4::IDD)
	, m_TCIFMTName(_T(""))
	, m_TCIFMTID(_T(""))
	, m_TCIFMTSex(_T(""))
	, m_TCIFMTTelephone(_T(""))
	, m_TCIFMTPassword(_T(""))
{

}

CTeacherPage4::~CTeacherPage4()
{
}

void CTeacherPage4::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_TCIFMTName);
	DDX_Text(pDX, IDC_EDIT1, m_TCIFMTID);
	DDX_Text(pDX, IDC_EDIT5, m_TCIFMTSex);
	DDX_Text(pDX, IDC_EDIT2, m_TCIFMTTelephone);
	DDX_Text(pDX, IDC_EDIT3, m_TCIFMTPassword);
}


BEGIN_MESSAGE_MAP(CTeacherPage4, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherPage4::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CTeacherPage4 ��Ϣ�������


void CTeacherPage4::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTeacherModifyPassword tmp;
	tmp.m_TCModifyPWOld = m_TCIFMTPassword;
	tmp.modify.setinformation(m_TCIFMTID,m_TCIFMTPassword,m_TCIFMTName,m_TCIFMTTelephone,m_TCIFMTSex);
	tmp.DoModal();

}


void CTeacherPage4::OnPaint()
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
