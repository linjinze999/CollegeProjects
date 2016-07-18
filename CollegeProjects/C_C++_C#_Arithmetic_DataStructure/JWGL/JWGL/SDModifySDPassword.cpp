// SDModifySDPassword.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "SDModifySDPassword.h"
#include "afxdialogex.h"
#include "ClassStudent.h"
#include "StudentPage1.h"

// CSDModifySDPassword �Ի���

IMPLEMENT_DYNAMIC(CSDModifySDPassword, CDialogEx)

CSDModifySDPassword::CSDModifySDPassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSDModifySDPassword::IDD, pParent)
	, m_SDIFMTOld(_T(""))
	, m_SDIFMTNew1(_T(""))
	, m_SDIFMTNew2(_T(""))
{

}

CSDModifySDPassword::~CSDModifySDPassword()
{
}

void CSDModifySDPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SDIFMTOld);
	DDX_Text(pDX, IDC_EDIT2, m_SDIFMTNew1);
	DDX_Text(pDX, IDC_EDIT3, m_SDIFMTNew2);
}


BEGIN_MESSAGE_MAP(CSDModifySDPassword, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSDModifySDPassword::OnBnClickedOk)
END_MESSAGE_MAP()


// CSDModifySDPassword ��Ϣ�������


void CSDModifySDPassword::OnBnClickedOk()//ѧ���޸�����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_SDIFMTNew1 == m_SDIFMTNew2){
		bool text;
		text = modifypw.modifyinformation(modifypw.getid(),modifypw.getid(),m_SDIFMTNew2,modifypw.getname(),modifypw.getsex(),modifypw.gettelephone(),modifypw.getmajor(),modifypw.getnoclass());
	    if(text){
		    MessageBox(_T("�޸ĳɹ���"));
		    CDialogEx::OnOK();
		}
		else{
			MessageBox(_T("�޸ĳ���"));
		}
	}
	else{
	    MessageBox(_T("ǰ�����벻һ�£�"));
	}
}
