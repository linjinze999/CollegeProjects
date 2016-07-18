// TeacherPage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "TeacherPage2.h"
#include "afxdialogex.h"
#include "ClassCourseAndMessage.h"
#include "TeacherScoreAdd.h"
#include "TeacherScoreModify.h"
#include "TeacherScoreSee.h"
#include "TeacherScoreSearch.h"


// TeacherPage2 �Ի���

IMPLEMENT_DYNAMIC(TeacherPage2, CPropertyPage)

TeacherPage2::TeacherPage2()
	: CPropertyPage(TeacherPage2::IDD)
	, m_TCScore(_T(""))
	, m_TCScoreCourseNM(_T(""))
{

}

TeacherPage2::~TeacherPage2()
{
}

void TeacherPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_TCScore);
	DDX_Control(pDX, IDC_COMBO2, m_TCScoreCourseName);
	DDX_CBString(pDX, IDC_COMBO2, m_TCScoreCourseNM);
}


BEGIN_MESSAGE_MAP(TeacherPage2, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &TeacherPage2::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// TeacherPage2 ��Ϣ�������


BOOL TeacherPage2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CourseAndMessage zxs;
	CString zxsname[20];
	zxs.getyourcourse(zxsname,tcname);
	for(int i = 0;i<20;i++){
		if(_T("")==zxsname[i]){break;}
		else{
			m_TCScoreCourseName.AddString(zxsname[i]);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void TeacherPage2::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(_T("") == m_TCScoreCourseNM){
		MessageBox(_T("��ѡ��γ̣�"));
	}
	else{
		if(m_TCScore == _T("¼��ѧ���ɼ�")){
			CTeacherScoreAdd tsa;
			tsa.scorename = m_TCScoreCourseNM;
			tsa.DoModal();
		}
		else{
			if(m_TCScore == _T("�޸�ѧ���ɼ�")){
				CTeacherScoreModify tsm;
				tsm.classname = m_TCScoreCourseNM;
				tsm.DoModal();
			}
			else{
				if(m_TCScore == _T("���ѧ���ɼ�")){
					CTeacherScoreSee tss;
					tss.classname = m_TCScoreCourseNM;
					tss.DoModal();
				}
				else{
					if(m_TCScore == _T("��ѯѧ���ɼ�")){
						CTeacherScoreSearch tss;
						tss.classname = m_TCScoreCourseNM;
						tss.DoModal();
					}
					else{
					    MessageBox(_T("��ѡ���ܣ�"));
					}
				}
			}
		}
	}
}


void TeacherPage2::OnPaint()
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
