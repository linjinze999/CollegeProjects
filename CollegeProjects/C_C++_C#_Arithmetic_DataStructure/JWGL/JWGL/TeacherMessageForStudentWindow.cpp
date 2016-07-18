// TeacherMessageForStudentWindow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherMessageForStudentWindow.h"
#include "afxdialogex.h"
#include "ClassTeacher.h"
#include "ClassCourseAndMessage.h"


// TeacherMessageForStudentWindow �Ի���

IMPLEMENT_DYNAMIC(TeacherMessageForStudentWindow, CDialogEx)

TeacherMessageForStudentWindow::TeacherMessageForStudentWindow(CWnd* pParent /*=NULL*/)
	: CDialogEx(TeacherMessageForStudentWindow::IDD, pParent)
	, m_TCMessageForSD(_T(""))
	, m_TCMessageClassName(_T(""))
	, m_TCMessageMessage(_T(""))
{

}

TeacherMessageForStudentWindow::~TeacherMessageForStudentWindow()
{
}

void TeacherMessageForStudentWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_TCMessageForSD);
	DDX_CBString(pDX, IDC_COMBO1, m_TCMessageClassName);
	DDX_Text(pDX, IDC_EDIT1, m_TCMessageMessage);
	DDX_Control(pDX, IDC_COMBO1, m_TCMessageCourseName);
}


BEGIN_MESSAGE_MAP(TeacherMessageForStudentWindow, CDialogEx)
	ON_BN_CLICKED(IDOK, &TeacherMessageForStudentWindow::OnBnClickedOk)
END_MESSAGE_MAP()


// TeacherMessageForStudentWindow ��Ϣ�������


void TeacherMessageForStudentWindow::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	teacher modifymessage;
	if(_T("")==m_TCMessageClassName){
	    MessageBox(_T("��ѡ��γ̣�"));
	}
	else{
		if(m_TCMessageMessage == _T("")){
			modifymessage.TCMessageForStudent(m_TCMessageClassName,_T("0"));
			MessageBox(_T("����Ϊ�գ�Ĭ��������ԣ�"));
			CDialogEx::OnOK();
		}
		else{
			modifymessage.TCMessageForStudent(m_TCMessageClassName,m_TCMessageMessage);
			MessageBox(_T("���Գɹ���"));
			CDialogEx::OnOK();
		}
	}
}


BOOL TeacherMessageForStudentWindow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CourseAndMessage gettccoursename;
	CString CourseName[20];
	gettccoursename.getyourcourse(CourseName,m_TCMessageForSD);
	for(int i = 0;i<20;i++){
		if(_T("") == CourseName[i]){break;}
		else{
			m_TCMessageCourseName.AddString(CourseName[i]);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
