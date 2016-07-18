// TeacherAddCourseWindow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherAddCourseWindow.h"
#include "afxdialogex.h"


// TeacherAddCourseWindow �Ի���

IMPLEMENT_DYNAMIC(TeacherAddCourseWindow, CDialogEx)

TeacherAddCourseWindow::TeacherAddCourseWindow(CWnd* pParent /*=NULL*/)
	: CDialogEx(TeacherAddCourseWindow::IDD, pParent)
	, m_TCAddCourseClassname(_T(""))
	, m_TCAddCourseClassMessage(_T(""))
{

}

TeacherAddCourseWindow::~TeacherAddCourseWindow()
{
}

void TeacherAddCourseWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TCAddCourseClassname);
	DDX_Text(pDX, IDC_EDIT2, m_TCAddCourseClassMessage);
}


BEGIN_MESSAGE_MAP(TeacherAddCourseWindow, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &TeacherAddCourseWindow::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &TeacherAddCourseWindow::OnBnClickedOk)
END_MESSAGE_MAP()


// TeacherAddCourseWindow ��Ϣ�������


void TeacherAddCourseWindow::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void TeacherAddCourseWindow::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(_T("") == m_TCAddCourseClassname){
	    MessageBox(_T("�γ����ֲ���Ϊ�գ�"));
	}
	else{
		addcourse.TCAddCourse(m_TCAddCourseClassname,m_TCAddCourseClassMessage,addcourse.name);
		MessageBox(_T("���ӳɹ������µ�¼��ˢ�����ݣ�"));
		CDialogEx::OnOK();
	}
}
