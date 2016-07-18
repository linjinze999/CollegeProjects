// BGStat.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGStat.h"
#include "afxdialogex.h"
#include "ClassStudent.h"


// CBGStat �Ի���

IMPLEMENT_DYNAMIC(CBGStat, CDialogEx)

CBGStat::CBGStat(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGStat::IDD, pParent)
{

}

CBGStat::~CBGStat()
{
}

void CBGStat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BGStatCtllist);
}


BEGIN_MESSAGE_MAP(CBGStat, CDialogEx)
END_MESSAGE_MAP()


// CBGStat ��Ϣ�������


BOOL CBGStat::OnInitDialog()//ͳ��ҳ���ʼ��
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	student allstudent;
	CString allsdid[400];
	CString classname[20];
	int coursenumber = 0;
	CString coursename,classnumber;
	allstudent.getallstudent(allsdid);
	for(int i = 0;i<400;i++){
		allstudent.serch(allsdid[i]);
		allstudent.getyourcourse(classname,allstudent.getname());
		for(coursenumber=0;coursenumber<20;coursenumber++){
			if(_T("") == classname[coursenumber]){
				break;
			}
		}
	}
	CRect rect;   
	m_BGStatCtllist.GetClientRect(&rect);
	m_BGStatCtllist.SetExtendedStyle(m_BGStatCtllist.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	if(stattype == 1){//��רҵͳ��
		int hang = 0;
		CString classnm[200];
		m_BGStatCtllist.InsertColumn(0, _T("רҵ"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 0);    
		m_BGStatCtllist.InsertColumn(1, _T("�༶"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 1);  
		m_BGStatCtllist.InsertColumn(2, _T("�˺�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 2);    
		m_BGStatCtllist.InsertColumn(3, _T("����"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 3);  
		m_BGStatCtllist.InsertColumn(4, _T("����"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 4);  
		m_BGStatCtllist.InsertColumn(5, _T("�Ա�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 5);  
		m_BGStatCtllist.InsertColumn(6, _T("�绰"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 6); 
		for(int k=0;k<coursenumber;k++){
			m_BGStatCtllist.InsertColumn(7+2*k, _T("�γ�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 7+2*k);
			m_BGStatCtllist.InsertColumn(8+2*k, _T("�ɼ�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 8+2*k);
		}
		for(int c = 0;c<9;c++){
			if(c == 0){coursename = _T("�������");classnumber = _T("1��");}
			if(c == 1){coursename = _T("�������");classnumber = _T("2��");}
			if(c == 2){coursename = _T("�������");classnumber = _T("3��");}
			if(c == 3){coursename = _T("ͨ�ż���");classnumber = _T("1��");}
			if(c == 4){coursename = _T("ͨ�ż���");classnumber = _T("2��");}
			if(c == 5){coursename = _T("ͨ�ż���");classnumber = _T("3��");}
			if(c == 6){coursename = _T("�����");classnumber = _T("1��");}
			if(c == 7){coursename = _T("�����");classnumber = _T("2��");}
			if(c == 8){coursename = _T("�����");classnumber = _T("3��");}
			for(int i = 0;i<200;i++){
				if(_T("") == allsdid[i]){break;}
				allstudent.serch(allsdid[i]);
				if(allstudent.getmajor() == coursename && allstudent.getnoclass() == classnumber)
				{
					m_BGStatCtllist.InsertItem(hang, allstudent.getmajor());
					m_BGStatCtllist.SetItemText(hang, 1, allstudent.getnoclass());    
					m_BGStatCtllist.SetItemText(hang, 2, allstudent.getid());    
					m_BGStatCtllist.SetItemText(hang, 3, allstudent.getpassword()); 
					m_BGStatCtllist.SetItemText(hang, 4,allstudent.getname()); 
					m_BGStatCtllist.SetItemText(hang, 5, allstudent.getsex()); 
					m_BGStatCtllist.SetItemText(hang, 6, allstudent.gettelephone()); 
					allstudent.getyourcourse(classnm,allstudent.getname());
					for(int j=0;j<20;j++){
						if(_T("")==classnm[j]){break;}
					    m_BGStatCtllist.SetItemText(hang,7+2*j, classnm[j]); 
						m_BGStatCtllist.SetItemText(hang,8+2*j, allstudent.getsdscore(classnm[j],allstudent.getname()));
					}
					for(int z=0;z<200;z++){
					   if(_T("")==classnm[z]){break;}
					   else{
					       classnm[z] = _T("");
					   }
					}
					hang++;
				}
			}
		}
	}
	if(stattype == 2){//���ֶ�ͳ��
		CString allcourse[100];
		CString coursesdname[200];
		allstudent.getallcourse(allcourse);
		m_BGStatCtllist.InsertColumn(0, _T("�γ�"), LVCFMT_CENTER, rect.Width()/6, 0);    
		m_BGStatCtllist.InsertColumn(1, _T("�ɼ�"), LVCFMT_CENTER, rect.Width()/6, 1);  
		m_BGStatCtllist.InsertColumn(2, _T("����"), LVCFMT_CENTER, rect.Width()/6, 2);    
		m_BGStatCtllist.InsertColumn(3, _T("�Ա�"), LVCFMT_CENTER, rect.Width()/6, 3);  
		m_BGStatCtllist.InsertColumn(4, _T("רҵ"), LVCFMT_CENTER, rect.Width()/6, 4);
		m_BGStatCtllist.InsertColumn(5, _T("�༶"), LVCFMT_CENTER, rect.Width()/6, 5);
		int hang=0;
		for(int l=0;l<100;l++){
			if(_T("")==allcourse[l]){break;}
			for(int x=0;x<5;x++){
				int a;
				if(x==0){
					allstudent.GetTheCourseStudent(coursesdname,allcourse[l]);
					for(int n=0;n<200;n++){
						if(_T("") == coursesdname[n]){break;}
						a = _ttoi(allstudent.getsdscore(allcourse[l],coursesdname[n]));
						if(a>=90){
						    allstudent.serch(coursesdname[n]);
							m_BGStatCtllist.InsertItem(hang, allcourse[l]);
							m_BGStatCtllist.SetItemText(hang, 1, allstudent.getsdscore(allcourse[l],allstudent.getname()));
							m_BGStatCtllist.SetItemText(hang, 2, allstudent.getname());
							m_BGStatCtllist.SetItemText(hang, 3, allstudent.getsex());
							m_BGStatCtllist.SetItemText(hang, 4, allstudent.getmajor());
							m_BGStatCtllist.SetItemText(hang, 5, allstudent.getnoclass());
							hang++;
						}
					}
				}
				if(x==1){
					allstudent.GetTheCourseStudent(coursesdname,allcourse[l]);
					for(int n=0;n<200;n++){
						if(_T("") == coursesdname[n]){break;}
						a = _ttoi(allstudent.getsdscore(allcourse[l],coursesdname[n]));
						if(a<90 && a>=80){
						    allstudent.serch(coursesdname[n]);
							m_BGStatCtllist.InsertItem(hang, allcourse[l]);
							m_BGStatCtllist.SetItemText(hang, 1, allstudent.getsdscore(allcourse[l],allstudent.getname()));
							m_BGStatCtllist.SetItemText(hang, 2, allstudent.getname());
							m_BGStatCtllist.SetItemText(hang, 3, allstudent.getsex());
							m_BGStatCtllist.SetItemText(hang, 4, allstudent.getmajor());
							m_BGStatCtllist.SetItemText(hang, 5, allstudent.getnoclass());
							hang++;
						}
					}
				}
				if(x==2){
					allstudent.GetTheCourseStudent(coursesdname,allcourse[l]);
					for(int n=0;n<200;n++){
						if(_T("") == coursesdname[n]){break;}
						a = _ttoi(allstudent.getsdscore(allcourse[l],coursesdname[n]));
						if(a<80 && a>=70){
						    allstudent.serch(coursesdname[n]);
							m_BGStatCtllist.InsertItem(hang, allcourse[l]);
							m_BGStatCtllist.SetItemText(hang, 1, allstudent.getsdscore(allcourse[l],allstudent.getname()));
							m_BGStatCtllist.SetItemText(hang, 2, allstudent.getname());
							m_BGStatCtllist.SetItemText(hang, 3, allstudent.getsex());
							m_BGStatCtllist.SetItemText(hang, 4, allstudent.getmajor());
							m_BGStatCtllist.SetItemText(hang, 5, allstudent.getnoclass());
							hang++;
						}
					}
				}
				if(x==3){
					allstudent.GetTheCourseStudent(coursesdname,allcourse[l]);
					for(int n=0;n<200;n++){
						if(_T("") == coursesdname[n]){break;}
						a = _ttoi(allstudent.getsdscore(allcourse[l],coursesdname[n]));
						if(a<70 && a>=60){
						    allstudent.serch(coursesdname[n]);
							m_BGStatCtllist.InsertItem(hang, allcourse[l]);
							m_BGStatCtllist.SetItemText(hang, 1, allstudent.getsdscore(allcourse[l],allstudent.getname()));
							m_BGStatCtllist.SetItemText(hang, 2, allstudent.getname());
							m_BGStatCtllist.SetItemText(hang, 3, allstudent.getsex());
							m_BGStatCtllist.SetItemText(hang, 4, allstudent.getmajor());
							m_BGStatCtllist.SetItemText(hang, 5, allstudent.getnoclass());
							hang++;
						}
					}
				}
				if(x==4){
					allstudent.GetTheCourseStudent(coursesdname,allcourse[l]);
					for(int n=0;n<200;n++){
						if(_T("") == coursesdname[n]){break;}
						a = _ttoi(allstudent.getsdscore(allcourse[l],coursesdname[n]));
						if(a<60){
						    allstudent.serch(coursesdname[n]);
							m_BGStatCtllist.InsertItem(hang, allcourse[l]);
							m_BGStatCtllist.SetItemText(hang, 1, allstudent.getsdscore(allcourse[l],allstudent.getname()));
							m_BGStatCtllist.SetItemText(hang, 2, allstudent.getname());
							m_BGStatCtllist.SetItemText(hang, 3, allstudent.getsex());
							m_BGStatCtllist.SetItemText(hang, 4, allstudent.getmajor());
							m_BGStatCtllist.SetItemText(hang, 5, allstudent.getnoclass());
							hang++;
						}
					}
				}
			}
		}
	}
	if(stattype == 3){//���Ա�ͳ��
		int hang=0;
	    m_BGStatCtllist.InsertColumn(0, _T("�Ա�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 0);    
		m_BGStatCtllist.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 1);  
		m_BGStatCtllist.InsertColumn(2, _T("�˺�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 2);    
		m_BGStatCtllist.InsertColumn(3, _T("����"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 3);  
		m_BGStatCtllist.InsertColumn(4, _T("רҵ"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 4);  
		m_BGStatCtllist.InsertColumn(5, _T("�༶"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 5);  
		m_BGStatCtllist.InsertColumn(6, _T("�绰"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 6); 
		for(int k=0;k<coursenumber;k++){
			m_BGStatCtllist.InsertColumn(7+2*k, _T("�γ�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 7+2*k);
			m_BGStatCtllist.InsertColumn(8+2*k, _T("�ɼ�"), LVCFMT_CENTER, rect.Width()/7+2*coursenumber, 8+2*k);
		}
		for(int g=0;g<=1;g++){
			CString a;
			CString classnm[200];
			if(g==0){a = _T("��");}
			if(g==1){a = _T("Ů");}
		    for(int i = 0;i<200;i++){
				if(_T("") == allsdid[i]){break;}
				allstudent.serch(allsdid[i]);
				if(a == allstudent.getsex())
				{
					m_BGStatCtllist.InsertItem(hang, allstudent.getsex());
					m_BGStatCtllist.SetItemText(hang, 1, allstudent.getname());    
					m_BGStatCtllist.SetItemText(hang, 2, allstudent.getid());    
					m_BGStatCtllist.SetItemText(hang, 3, allstudent.getpassword()); 
					m_BGStatCtllist.SetItemText(hang, 4,allstudent.getmajor()); 
					m_BGStatCtllist.SetItemText(hang, 5, allstudent.getnoclass()); 
					m_BGStatCtllist.SetItemText(hang, 6, allstudent.gettelephone()); 
					allstudent.getyourcourse(classnm,allstudent.getname());
					for(int j=0;j<20;j++){
						if(_T("")==classnm[j]){break;}
					    m_BGStatCtllist.SetItemText(hang,7+2*j, classnm[j]); 
						m_BGStatCtllist.SetItemText(hang,8+2*j, allstudent.getsdscore(classnm[j],allstudent.getname()));
					}
					for(int z=0;z<200;z++){
					    if(_T("")==classnm[z]){break;}
						else{
					       classnm[z] = _T("");
					   }
					}
					hang++;
				}
			}
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
