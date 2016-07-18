// StudentPage4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "StudentPage4.h"
#include "afxdialogex.h"
#include "ClassCourseAndMessage.h"


// StudentPage4 �Ի���

IMPLEMENT_DYNAMIC(StudentPage4, CPropertyPage)

StudentPage4::StudentPage4()
	: CPropertyPage(StudentPage4::IDD)
	, m_SDMessageToTC(_T(""))
	, m_SDMessageCourse(_T(""))
{

}

StudentPage4::~StudentPage4()
{
}

void StudentPage4::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SDMessageTC);
	DDX_Text(pDX, IDC_EDIT2, m_SDMessageToTC);
	DDX_CBString(pDX, IDC_COMBO1, m_SDMessageCourse);
	DDX_Control(pDX, IDC_COMBO1, m_SDMessageCourseName);
}


BEGIN_MESSAGE_MAP(StudentPage4, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &StudentPage4::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// StudentPage4 ��Ϣ�������


BOOL StudentPage4::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	m_SDMessageTC.GetClientRect(&rect);
	m_SDMessageTC.SetExtendedStyle(m_SDMessageTC.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_SDMessageTC.InsertColumn(0, _T("�γ����ƣ�"), LVCFMT_CENTER, rect.Width()/2, 0);
	m_SDMessageTC.InsertColumn(1, _T("���ԣ�"), LVCFMT_CENTER, rect.Width()/2, 1);
	CString sdcoursename[20];
	CourseAndMessage Message;
	Message.getyourcourse(sdcoursename,sdname);
	for(int i = 0;i<20;i++){
		if(_T("") == sdcoursename[i]){break;}
		else{
		    m_SDMessageTC.InsertItem(i, sdcoursename[i]);
			m_SDMessageTC.SetItemText(i, 1,Message.GetScoreMessage(sdcoursename[i]));
		}
	}
	for(int i = 0;i<20;i++){
	    if(_T("") ==sdcoursename[i]){break;}
		else{
		    m_SDMessageCourseName.AddString(sdcoursename[i]);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void StudentPage4::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(_T("") == m_SDMessageToTC){
		MessageBox(_T("���������ݣ�"));
	}
	else{
		if(_T("") == m_SDMessageCourse){
		    MessageBox(_T("��ѡ��γ̣�"));
		}
		else{
		    CourseAndMessage cam;
	        cam.StudentAddMessage(m_SDMessageCourse,m_SDMessageToTC);
	        MessageBox(_T("���ͳɹ�"));
		}
	}
	
}


void StudentPage4::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	CRect   rect;   
    GetClientRect(&rect);   
    CDC   dcMem;   
    dcMem.CreateCompatibleDC(&dc);   
    CBitmap   bmpBackground;   
    bmpBackground.LoadBitmap(IDB_BITMAP1);   
    BITMAP   bitmap;   
    bmpBackground.GetBitmap(&bitmap);   
    CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   
    bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// ��Ϊ��ͼ��Ϣ���� CPropertyPage::OnPaint()
}
