// TeacherPage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherPage1.h"
#include "afxdialogex.h"
#include "TeacherAddCourseWindow.h"
#include "ClassCourseAndMessage.h"


// TeacherPage1 �Ի���

IMPLEMENT_DYNAMIC(TeacherPage1, CPropertyPage)

TeacherPage1::TeacherPage1()
	: CPropertyPage(TeacherPage1::IDD)
	, m_TCCourseName(_T(""))
{

}

TeacherPage1::~TeacherPage1()
{
}

void TeacherPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TCCourseName);
	DDX_Control(pDX, IDC_LIST1, m_TCCourseClassList);
}


BEGIN_MESSAGE_MAP(TeacherPage1, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &TeacherPage1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TeacherPage1::OnBnClickedButton2)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &TeacherPage1::OnNMClickList1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// TeacherPage1 ��Ϣ�������


void TeacherPage1::OnBnClickedButton1()//��ʦ���ӿγ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TeacherAddCourseWindow tacw;
	tacw.addcourse.setname(m_TCCourseName);
	tacw.DoModal();
}


void TeacherPage1::OnBnClickedButton2()//��ʦɾ���γ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CourseAndMessage deleteclass;
	if(_T("") == tcdeleteclass){
	    MessageBox(_T("��ѡ��γ̣�"));
	}
	else{
		if(_T("C++�����ޣ�") == tcdeleteclass||_T("Ӣ����ޣ�") == tcdeleteclass||_T("JAVA�����ޣ�") == tcdeleteclass){
		    MessageBox(_T("���޿��޷�ɾ����"));
		}
		else{
		    deleteclass.TCDeleteCourse(tcdeleteclass,m_TCCourseName);
			MessageBox(_T("ɾ���ɹ������µ�¼��ˢ�����ݡ�"));
		}
	}	
}


BOOL TeacherPage1::OnInitDialog()//�����ʦӵ�еĿγ�
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect; 
	m_TCCourseClassList.GetClientRect(&rect);
	m_TCCourseClassList.SetExtendedStyle(m_TCCourseClassList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);    
	m_TCCourseClassList.InsertColumn(0, _T("�γ����ƣ�"), LVCFMT_CENTER, rect.Width()/1, 0);
	CourseAndMessage getclassname;
	CString classname[20];
	getclassname.getyourcourse(classname,m_TCCourseName);
	for(int i = 0;i<20;i++){
		m_TCCourseClassList.InsertItem(i, classname[i]);   
		if(_T("") == classname[i]){
		    break;
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void TeacherPage1::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)//��ȡ�û����б��ѡ��
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR;
	if (-1 != pNMListView->iItem){
	    tcdeleteclass = m_TCCourseClassList.GetItemText(pNMListView->iItem, 0);
	}
}


void TeacherPage1::OnPaint()
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
