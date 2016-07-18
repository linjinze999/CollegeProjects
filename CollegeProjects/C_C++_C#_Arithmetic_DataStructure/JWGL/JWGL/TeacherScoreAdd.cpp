// TeacherScoreAdd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherScoreAdd.h"
#include "afxdialogex.h"
#include "ClassCourseAndMessage.h"

// CTeacherScoreAdd �Ի���

IMPLEMENT_DYNAMIC(CTeacherScoreAdd, CDialogEx)

CTeacherScoreAdd::CTeacherScoreAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherScoreAdd::IDD, pParent)
	, m_TCScoreAddName(_T(""))
	, m_TCScoreAddScore(_T(""))
{

}

CTeacherScoreAdd::~CTeacherScoreAdd()
{
}

void CTeacherScoreAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_TCScoreAddName);
	DDX_Text(pDX, IDC_EDIT2, m_TCScoreAddScore);
	DDX_Control(pDX, IDC_LIST1, m_TCScoreAddCtllist);
}


BEGIN_MESSAGE_MAP(CTeacherScoreAdd, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTeacherScoreAdd::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CTeacherScoreAdd::OnNMClickList1)
END_MESSAGE_MAP()


// CTeacherScoreAdd ��Ϣ�������


BOOL CTeacherScoreAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	m_TCScoreAddCtllist.GetClientRect(&rect);
	m_TCScoreAddCtllist.SetExtendedStyle(m_TCScoreAddCtllist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_TCScoreAddCtllist.InsertColumn(0, _T("ѧ��������"),  LVCFMT_CENTER, rect.Width()/1, 0);
	CourseAndMessage thecoursestudent;
	CString sdname[200];
	thecoursestudent.GetTheCourseStudent(sdname,scorename);
	for(int i = 0;i<200;i++){
	    if(_T("") == sdname[i]){
		    break;
		}
		else{
		    m_TCScoreAddCtllist.InsertItem(i, sdname[i]);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTeacherScoreAdd::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(_T("")!=m_TCScoreAddName && _T("")!=m_TCScoreAddScore){
	    CourseAndMessage asd;
		asd.setscore(scorename,m_TCScoreAddName,m_TCScoreAddScore);
		MessageBox(_T("¼��ɹ���"));
	}
	else{
	    MessageBox(_T("��ѡ��ѧ��������ɼ���"));
	}
}


void CTeacherScoreAdd::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CString a;
	NMLISTVIEW *pNMListView = (NMLISTVIEW*)pNMHDR; 
	if (-1 != pNMListView->iItem){
	    a = m_TCScoreAddCtllist.GetItemText(pNMListView->iItem, 0); 
		SetDlgItemText(IDC_EDIT1, a); 
	}
}
