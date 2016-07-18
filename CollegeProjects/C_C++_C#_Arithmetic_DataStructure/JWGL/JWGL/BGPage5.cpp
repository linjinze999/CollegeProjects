// BGPage5.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGPage5.h"
#include "afxdialogex.h"
#include "BGStat.h"


// BGPage5 �Ի���

IMPLEMENT_DYNAMIC(BGPage5, CPropertyPage)

BGPage5::BGPage5()
	: CPropertyPage(BGPage5::IDD)
	, m_BGStatType(_T(""))
{

}

BGPage5::~BGPage5()
{
}

void BGPage5::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_BGStatType);
}


BEGIN_MESSAGE_MAP(BGPage5, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &BGPage5::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// BGPage5 ��Ϣ�������


void BGPage5::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CBGStat bgs;
	if(_T("") == m_BGStatType){
	    MessageBox(_T("��ѡ��ͳ�����ͣ�"));
	}
	else{
		if(_T("רҵ") == m_BGStatType){
			bgs.stattype = 1;
			bgs.DoModal();
		}
		else{
			if(_T("�ֶ�") == m_BGStatType){
			    bgs.stattype = 2;
			    bgs.DoModal();
			}
			else{
			    if(_T("�Ա�") == m_BGStatType){
			        bgs.stattype = 3;
			        bgs.DoModal();
			    }
				else{
				     MessageBox(_T("��ѡ����ȷͳ�����ͣ�"));
				}
			}
		}
	}

}


void BGPage5::OnPaint()
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
