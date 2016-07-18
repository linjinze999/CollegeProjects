// TeacherScoreModify.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherScoreModify.h"
#include "afxdialogex.h"
#include "ClassStudent.h"
#include "ClassStudent.h"


// CTeacherScoreModify �Ի���

IMPLEMENT_DYNAMIC(CTeacherScoreModify, CDialogEx)

CTeacherScoreModify::CTeacherScoreModify(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherScoreModify::IDD, pParent)
	, m_TCScoreModifyID(_T(""))
	, m_TCScoreModifyScore(_T(""))
	, m_TCScoreModifyOld(_T(""))
{

}

CTeacherScoreModify::~CTeacherScoreModify()
{
}

void CTeacherScoreModify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TCScoreModifyID);
	DDX_Text(pDX, IDC_EDIT2, m_TCScoreModifyScore);
	DDX_Text(pDX, IDC_EDIT3, m_TCScoreModifyOld);
}


BEGIN_MESSAGE_MAP(CTeacherScoreModify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTeacherScoreModify::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CTeacherScoreModify::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CTeacherScoreModify ��Ϣ�������


void CTeacherScoreModify::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	student adl;
	bool k;
	k = adl.serch(m_TCScoreModifyID);
	if(k){
		if(_T("")==m_TCScoreModifyScore){
		    MessageBox(_T("�ɼ�����Ϊ�գ�"));
		}
		else{
			adl.setscore(classname,adl.getname(),m_TCScoreModifyScore);
			MessageBox(_T("�޸ĳɹ���"));
			CDialogEx::OnOK();
		}
	}
	else{
	    MessageBox(_T("���޴��ˣ�"));
	}
}


void CTeacherScoreModify::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	student ads;
	CString a;
	bool i;
	i = ads.serch(m_TCScoreModifyID);
	a = ads.getsdscore(classname,ads.getname());
	if(i){
	    SetDlgItemText(IDC_EDIT3, a);
	}
	else{
	    SetDlgItemText(IDC_EDIT3, _T(""));
	}
}
