// BGSearchTCFuzzy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGSearchTCFuzzy.h"
#include "afxdialogex.h"


// CBGSearchTCFuzzy �Ի���

IMPLEMENT_DYNAMIC(CBGSearchTCFuzzy, CDialogEx)

CBGSearchTCFuzzy::CBGSearchTCFuzzy(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGSearchTCFuzzy::IDD, pParent)
{

}

CBGSearchTCFuzzy::~CBGSearchTCFuzzy()
{
}

void CBGSearchTCFuzzy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctllistBGSearchTCfUZZY);
}


BEGIN_MESSAGE_MAP(CBGSearchTCFuzzy, CDialogEx)
END_MESSAGE_MAP()


// CBGSearchTCFuzzy ��Ϣ�������


BOOL CBGSearchTCFuzzy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;    
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С    
     m_ctllistBGSearchTCfUZZY.GetClientRect(&rect);    
   
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����    
     m_ctllistBGSearchTCfUZZY.SetExtendedStyle(m_ctllistBGSearchTCfUZZY.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);    
    
     // Ϊ�б���ͼ�ؼ��������    
     m_ctllistBGSearchTCfUZZY.InsertColumn(0, _T("����"), LVCFMT_CENTER, rect.Width()/5, 0);    
     m_ctllistBGSearchTCfUZZY.InsertColumn(1, _T("�˺�"), LVCFMT_CENTER, rect.Width()/5, 1);    
     m_ctllistBGSearchTCfUZZY.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/5, 2);    
	 m_ctllistBGSearchTCfUZZY.InsertColumn(3, _T("�Ա�"), LVCFMT_CENTER, rect.Width()/5, 3);  
	 m_ctllistBGSearchTCfUZZY.InsertColumn(4, _T("�绰"), LVCFMT_CENTER, rect.Width()/5, 4);  
     // ���б���ͼ�ؼ��в����б���������б������ı� 
	 for(int i = 0;i<200;i++){
		 m_ctllistBGSearchTCfUZZY.InsertItem(i, searchtcfuzzy[i].getname());    
         m_ctllistBGSearchTCfUZZY.SetItemText(i, 1, searchtcfuzzy[i].getid());    
         m_ctllistBGSearchTCfUZZY.SetItemText(i, 2, searchtcfuzzy[i].getpassword());    
	     m_ctllistBGSearchTCfUZZY.SetItemText(i, 3, searchtcfuzzy[i].getsex()); 
	     m_ctllistBGSearchTCfUZZY.SetItemText(i, 4,searchtcfuzzy[i].gettelephone()); 
	     if(_T("") == searchtcfuzzy[i].getid()){break;}
	 }

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
