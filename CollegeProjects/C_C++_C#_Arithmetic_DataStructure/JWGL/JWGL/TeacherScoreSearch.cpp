// TeacherScoreSearch.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherScoreSearch.h"
#include "afxdialogex.h"
#include "ClassCourseAndMessage.h"
#include "ClassStudent.h"


// CTeacherScoreSearch �Ի���

IMPLEMENT_DYNAMIC(CTeacherScoreSearch, CDialogEx)

CTeacherScoreSearch::CTeacherScoreSearch(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherScoreSearch::IDD, pParent)
	, m_TCScoreSearchID(_T(""))
{

}

CTeacherScoreSearch::~CTeacherScoreSearch()
{
}

void CTeacherScoreSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TCScoreSearchID);
}


BEGIN_MESSAGE_MAP(CTeacherScoreSearch, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherScoreSearch::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTeacherScoreSearch ��Ϣ�������


void CTeacherScoreSearch::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	student sdf;
	bool s;
	s = sdf.serch(m_TCScoreSearchID);
	if(s){
		CString a;
		a = sdf.getsdscore(classname,sdf.getname());
		SetDlgItemText(IDC_EDIT2, a); 
	}
	else{
	    MessageBox(_T("���޴��ˣ�"));
	}
}
