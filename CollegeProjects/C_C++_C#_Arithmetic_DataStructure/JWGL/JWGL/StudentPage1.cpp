// StudentPage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "StudentPage1.h"
#include "afxdialogex.h"
#include "SDModifySDPassword.h"
#include "ClassStudent.h"

// StudentPage1 �Ի���

IMPLEMENT_DYNAMIC(StudentPage1, CPropertyPage)

StudentPage1::StudentPage1()
	: CPropertyPage(StudentPage1::IDD)
	, m_SDIFMTName(_T(""))
	, m_SDIFMTID(_T(""))
	, m_SDIFMTSex(_T(""))
	, m_SDIFMTTelephone(_T(""))
	, m_SDIFMTMajor(_T(""))
	, m_SDIFMTNoclass(_T(""))
	, m_SDIFMTPassword(_T(""))
{
	
}

StudentPage1::~StudentPage1()
{
}

void StudentPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SDIFMTName);
	DDX_Text(pDX, IDC_EDIT4, m_SDIFMTID);
	DDX_Text(pDX, IDC_EDIT3, m_SDIFMTSex);
	DDX_Text(pDX, IDC_EDIT2, m_SDIFMTTelephone);

	DDX_Text(pDX, IDC_EDIT5, m_SDIFMTMajor);
	DDX_Text(pDX, IDC_EDIT6, m_SDIFMTNoclass);
	DDX_Text(pDX, IDC_EDIT7, m_SDIFMTPassword);
}


BEGIN_MESSAGE_MAP(StudentPage1, CPropertyPage)
	ON_EN_CHANGE(IDC_EDIT3, &StudentPage1::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT1, &StudentPage1::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &StudentPage1::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// StudentPage1 ��Ϣ�������


void StudentPage1::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void StudentPage1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void StudentPage1::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSDModifySDPassword msdp;
	msdp.m_SDIFMTOld = m_SDIFMTPassword;
	msdp.modifypw.setinformation(m_SDIFMTID,m_SDIFMTPassword,m_SDIFMTName,m_SDIFMTTelephone,m_SDIFMTSex,m_SDIFMTMajor,m_SDIFMTNoclass);
	msdp.DoModal();
}


void StudentPage1::OnPaint()
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
