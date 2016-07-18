// BGAddStudentUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGAddStudentUser.h"
#include "afxdialogex.h"
#include "ClassStudent.h"


// CBGAddStudentUser �Ի���

IMPLEMENT_DYNAMIC(CBGAddStudentUser, CDialogEx)

CBGAddStudentUser::CBGAddStudentUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGAddStudentUser::IDD, pParent)
	, m_AddSDID(_T(""))
	, m_AddSDPassword(_T(""))
	, m_AddSDName(_T(""))
	, m_AddSDSex(_T(""))
	, m_AddSDTelephone(_T(""))
	, m_AddSDMajor(_T(""))
	, m_AddSDNoclasses(_T(""))
{

}

CBGAddStudentUser::~CBGAddStudentUser()
{
}

void CBGAddStudentUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_AddSDID);
	DDX_Text(pDX, IDC_EDIT2, m_AddSDPassword);
	DDX_Text(pDX, IDC_EDIT3, m_AddSDName);
	DDX_CBString(pDX, IDC_COMBO1, m_AddSDSex);
	DDX_Text(pDX, IDC_EDIT5, m_AddSDTelephone);
	DDX_CBString(pDX, IDC_COMBO2, m_AddSDMajor);
	DDX_CBString(pDX, IDC_COMBO3, m_AddSDNoclasses);
}


BEGIN_MESSAGE_MAP(CBGAddStudentUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBGAddStudentUser::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CBGAddStudentUser::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CBGAddStudentUser::OnEnChangeEdit2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CBGAddStudentUser::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// CBGAddStudentUser ��Ϣ�������


void CBGAddStudentUser::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(m_AddSDID == _T("")){ 
		MessageBox(_T("�������˺ţ�"));
	}
	else{
		if(m_AddSDPassword == _T("")){
			MessageBox(_T("���������룡"));
		}
		else{
			if(m_AddSDName == _T("")){
			    MessageBox(_T("���������֣�"));
			}
			else{
				if(m_AddSDSex == _T("")){
			        MessageBox(_T("��ѡ���Ա�"));
			    }
				else{
					if(m_AddSDTelephone == _T("")){
					     MessageBox(_T("������绰��"));
					}
					else{
						if(m_AddSDMajor == _T("")){
							MessageBox(_T("��ѡ��רҵ��"));
						}
						else{
							if(m_AddSDMajor == _T("")){
							    MessageBox(_T("��ѡ��༶��"));
						    }
							else{
	                            student no1;
	                            no1.setinformation(m_AddSDID,m_AddSDPassword,m_AddSDName,m_AddSDTelephone,m_AddSDSex,m_AddSDMajor,m_AddSDNoclasses);
	                            no1.out();
						        MessageBox(_T("�����û��ɹ���"));
						        CDialogEx::OnOK();
							}
						}
					}
				}
			}
	    }
	}
	UpdateData(FALSE);
	
}


void CBGAddStudentUser::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBGAddStudentUser::OnBnClickedOk();
	CBGAddStudentUser sdu;
	sdu.DoModal();
}


void CBGAddStudentUser::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CBGAddStudentUser::OnCbnSelchangeCombo3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
