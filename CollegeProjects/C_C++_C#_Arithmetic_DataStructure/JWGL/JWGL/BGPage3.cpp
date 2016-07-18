// BGPage3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGPage3.h"
#include "afxdialogex.h"
#include "ClassStudent.h"
#include "ClassTeacher.h"


// BGPage3 �Ի���
int deletetype = 0;

IMPLEMENT_DYNAMIC(BGPage3, CPropertyPage)

BGPage3::BGPage3()
	: CPropertyPage(BGPage3::IDD)
	, m_BGDeleteTCID(_T(""))
	, m_BGDeleteUserBegin(0)
	, m_BGDeleteUserEnd(0)
{

}

BGPage3::~BGPage3()
{
}

void BGPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_BGDeleteTCID);
	DDX_Text(pDX, IDC_EDIT2, m_BGDeleteUserBegin);
	DDX_Text(pDX, IDC_EDIT3, m_BGDeleteUserEnd);
}


BEGIN_MESSAGE_MAP(BGPage3, CPropertyPage)
	ON_BN_CLICKED(IDC_RADIO1, &BGPage3::OnBnClickedRadio1)
	ON_EN_CHANGE(IDC_EDIT2, &BGPage3::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &BGPage3::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO2, &BGPage3::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &BGPage3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &BGPage3::OnBnClickedButton2)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// BGPage3 ��Ϣ�������


void BGPage3::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	deletetype = 1;
}


void BGPage3::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void BGPage3::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void BGPage3::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	deletetype = 2;
}


void BGPage3::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	teacher dlt;
	if(deletetype == 1){
		bool dele;
		dele = dlt.deleteteacher(m_BGDeleteTCID);
		if(dele){
		    MessageBox(_T("ɾ���ɹ���"));
		}
		else{
		    MessageBox(_T("���޴��ˣ�"));
		}
	}
	else{
		if(deletetype == 2){
		    CString user;
			if(0 == m_BGDeleteUserBegin || 0 == m_BGDeleteUserEnd){
			    MessageBox(_T("��������ʼ����ֵֹ��"));
			}
			else{
				if( m_BGDeleteUserBegin>m_BGDeleteUserEnd){
				     MessageBox(_T("������ʼֵ����ֵֹ��"));
				}
				else{
					for(long i = m_BGDeleteUserBegin;i <= m_BGDeleteUserEnd;i++){
						user.Format(_T("%ld"),i);
						dlt.deleteteacher(user);
					}
					MessageBox(_T("ɾ���ɹ���"));
				}
			}
		}
		else{
		    MessageBox(_T("��ѡ��ɾ�����ͣ�"));
		}
	}
}


void BGPage3::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������UpdateData(true);
	UpdateData(true);
	student dlt;
	if(deletetype == 1){
		bool dele;
		dele = dlt.deletestudent(m_BGDeleteTCID);
		if(dele){
		    MessageBox(_T("ɾ���ɹ���"));
		}
		else{
		    MessageBox(_T("���޴��ˣ�"));
		}
	}
	else{
		if(deletetype == 2){
		    CString user;
			if(0 == m_BGDeleteUserBegin || 0 == m_BGDeleteUserEnd){
			    MessageBox(_T("��������ʼ����ֵֹ��"));
			}
			else{
				if( m_BGDeleteUserBegin>m_BGDeleteUserEnd){
				     MessageBox(_T("������ʼֵ����ֵֹ��"));
				}
				else{
					for(long i = m_BGDeleteUserBegin;i <= m_BGDeleteUserEnd;i++){
						user.Format(_T("%ld"),i);
						dlt.deletestudent(user);
					}
					MessageBox(_T("ɾ���ɹ���"));
				}
			}
		}
		else{
		    MessageBox(_T("��ѡ��ɾ�����ͣ�"));
		}
	}

}


void BGPage3::OnPaint()
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
