// BGSearchSDFuzzy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGSearchSDFuzzy.h"
#include "afxdialogex.h"
#include "ClassStudent.h"


// CBGSearchSDFuzzy �Ի���
IMPLEMENT_DYNAMIC(CBGSearchSDFuzzy, CDialogEx)

CBGSearchSDFuzzy::CBGSearchSDFuzzy(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGSearchSDFuzzy::IDD, pParent)
{

}

CBGSearchSDFuzzy::~CBGSearchSDFuzzy()
{
}

void CBGSearchSDFuzzy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ctllistBGSearchSDFuzzy);
}


BEGIN_MESSAGE_MAP(CBGSearchSDFuzzy, CDialogEx)
END_MESSAGE_MAP()


// CBGSearchSDFuzzy ��Ϣ�������


BOOL CBGSearchSDFuzzy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;    
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С    
     m_ctllistBGSearchSDFuzzy.GetClientRect(&rect);    
   
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����    
     m_ctllistBGSearchSDFuzzy.SetExtendedStyle(m_ctllistBGSearchSDFuzzy.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);    
    
     // Ϊ�б���ͼ�ؼ��������    
     m_ctllistBGSearchSDFuzzy.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/7, 0);    
     m_ctllistBGSearchSDFuzzy.InsertColumn(1, _T("�˺�"), LVCFMT_CENTER, rect.Width()/7, 1);    
     m_ctllistBGSearchSDFuzzy.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/7, 2);    
	 m_ctllistBGSearchSDFuzzy.InsertColumn(3, _T("�Ա�"), LVCFMT_CENTER, rect.Width()/7, 3);  
	 m_ctllistBGSearchSDFuzzy.InsertColumn(4, _T("�绰"), LVCFMT_CENTER, rect.Width()/7, 4);  
	 m_ctllistBGSearchSDFuzzy.InsertColumn(5, _T("רҵ"), LVCFMT_CENTER, rect.Width()/7, 5);  
	 m_ctllistBGSearchSDFuzzy.InsertColumn(6, _T("�༶"), LVCFMT_CENTER, rect.Width()/7, 6);  
     // ���б���ͼ�ؼ��в����б���������б������ı� 
	 for(int i = 0;i<200;i++){
		 m_ctllistBGSearchSDFuzzy.InsertItem(i, searchsdfuzzy[i].getname());    
         m_ctllistBGSearchSDFuzzy.SetItemText(i, 1, searchsdfuzzy[i].getid());    
         m_ctllistBGSearchSDFuzzy.SetItemText(i, 2, searchsdfuzzy[i].getpassword());    
	     m_ctllistBGSearchSDFuzzy.SetItemText(i, 3, searchsdfuzzy[i].getsex()); 
	     m_ctllistBGSearchSDFuzzy.SetItemText(i, 4,searchsdfuzzy[i].gettelephone()); 
	     m_ctllistBGSearchSDFuzzy.SetItemText(i, 5, searchsdfuzzy[i].getmajor()); 
	     m_ctllistBGSearchSDFuzzy.SetItemText(i, 6, searchsdfuzzy[i].getnoclass()); 
	 if(_T("") == searchsdfuzzy[i].getid()){break;}
	 }
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
