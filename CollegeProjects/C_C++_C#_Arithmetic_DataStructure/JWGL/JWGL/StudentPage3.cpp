// StudentPage3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "StudentPage3.h"
#include "afxdialogex.h"
#include "ClassCourseAndMessage.h"


// StudentPage3 �Ի���

IMPLEMENT_DYNAMIC(StudentPage3, CPropertyPage)

StudentPage3::StudentPage3()
	: CPropertyPage(StudentPage3::IDD)
{

}

StudentPage3::~StudentPage3()
{
}

void StudentPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SDSeeScore);
}


BEGIN_MESSAGE_MAP(StudentPage3, CPropertyPage)
END_MESSAGE_MAP()


// StudentPage3 ��Ϣ�������



BOOL StudentPage3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	m_SDSeeScore.GetClientRect(&rect);
	m_SDSeeScore.SetExtendedStyle(m_SDSeeScore.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_SDSeeScore.InsertColumn(0, _T("�γ����ƣ�"), LVCFMT_CENTER, rect.Width()/2, 0);
	m_SDSeeScore.InsertColumn(1, _T("�ɼ���"), LVCFMT_CENTER, rect.Width()/2, 1);
	CString sdcoursename[20];
	CourseAndMessage getsdscore;
	getsdscore.getyourcourse(sdcoursename,studentname);
	for(int i = 0;i<20;i++){
		if(_T("") == sdcoursename[i]){break;}
		else{
		    m_SDSeeScore.InsertItem(i, sdcoursename[i]);
			m_SDSeeScore.SetItemText(i, 1,getsdscore.getsdscore(sdcoursename[i],studentname));
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
