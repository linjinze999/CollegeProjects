// TeacherModifyPassword.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherModifyPassword.h"
#include "afxdialogex.h"
#include "ClassTeacher.h"


// CTeacherModifyPassword �Ի���

IMPLEMENT_DYNAMIC(CTeacherModifyPassword, CDialogEx)

CTeacherModifyPassword::CTeacherModifyPassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherModifyPassword::IDD, pParent)
	, m_TCModifyPWOld(_T(""))
	, m_TCModifyPWnew1(_T(""))
	, m_TCModifyPWnew2(_T(""))
{

}

CTeacherModifyPassword::~CTeacherModifyPassword()
{
}

void CTeacherModifyPassword::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TCModifyPWOld);
	DDX_Text(pDX, IDC_EDIT2, m_TCModifyPWnew1);
	DDX_Text(pDX, IDC_EDIT3, m_TCModifyPWnew2);
}


BEGIN_MESSAGE_MAP(CTeacherModifyPassword, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTeacherModifyPassword::OnBnClickedOk)
END_MESSAGE_MAP()


// CTeacherModifyPassword ��Ϣ�������


void CTeacherModifyPassword::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_TCModifyPWnew1 == m_TCModifyPWnew2){
		bool text;
		text = modify.modifyinformation(modify.getid(),modify.getid(),m_TCModifyPWnew1,modify.getname(),modify.getsex(),modify.gettelephone());
	    if(text){
		    MessageBox(_T("�޸ĳɹ���"));
		    CDialogEx::OnOK();}
		else{
			MessageBox(_T("�޸ĳ���"));
		}
	}
	else{
	    MessageBox(_T("ǰ�����벻һ�£�"));
	}
	CDialogEx::OnOK();
}
