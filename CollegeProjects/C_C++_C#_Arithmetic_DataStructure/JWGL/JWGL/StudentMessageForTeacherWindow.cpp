// StudentMessageForTeacherWindow.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "StudentMessageForTeacherWindow.h"
#include "afxdialogex.h"
#include "ClassCourseAndMessage.h"


// StudentMessageForTeacherWindow �Ի���

IMPLEMENT_DYNAMIC(StudentMessageForTeacherWindow, CDialogEx)

StudentMessageForTeacherWindow::StudentMessageForTeacherWindow(CWnd* pParent /*=NULL*/)
	: CDialogEx(StudentMessageForTeacherWindow::IDD, pParent)
{

}

StudentMessageForTeacherWindow::~StudentMessageForTeacherWindow()
{
}

void StudentMessageForTeacherWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctllistSDMessageForTC);
}


BEGIN_MESSAGE_MAP(StudentMessageForTeacherWindow, CDialogEx)
END_MESSAGE_MAP()


// StudentMessageForTeacherWindow ��Ϣ�������


BOOL StudentMessageForTeacherWindow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;    
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С    
    m_ctllistSDMessageForTC.GetClientRect(&rect);    
   
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����    
     m_ctllistSDMessageForTC.SetExtendedStyle(m_ctllistSDMessageForTC.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);    
    
     // Ϊ�б���ͼ�ؼ��������    
     m_ctllistSDMessageForTC.InsertColumn(0, _T("�γ�����"), LVCFMT_CENTER, rect.Width()/2, 0);    
     m_ctllistSDMessageForTC.InsertColumn(1, _T("������Ϣ"), LVCFMT_CENTER, rect.Width()/2, 1);       
     // ���б���ͼ�ؼ��в����б���������б������ı�  
	 CourseAndMessage tcgetmessage;
	 CString coursename[20];
	 tcgetmessage.getyourcourse(coursename,tcname);
	 int hang=0;
	 for(int a = 0;a<20;a++){
		 if(_T("") == coursename[a]){break;}
		 else{
	         CString tcmessage[200];
	         tcgetmessage.TCGetSDMessage(tcmessage,coursename[a]);
			 for(int i=0;i<200;i++){
				 if(_T("") == tcmessage[i]){break;}
				 else{
                     m_ctllistSDMessageForTC.InsertItem(hang, coursename[a]);
                     m_ctllistSDMessageForTC.SetItemText(hang, 1,tcmessage[i]);
					 hang++;
				 }
			 }
		 }
	 }

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
