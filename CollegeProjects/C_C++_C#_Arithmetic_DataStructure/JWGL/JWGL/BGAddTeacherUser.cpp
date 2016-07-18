// BGAddTeacherUser.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGAddTeacherUser.h"
#include "afxdialogex.h"
#include "ClassTeacher.h"


// CBGAddTeacherUser �Ի���

IMPLEMENT_DYNAMIC(CBGAddTeacherUser, CDialogEx)

CBGAddTeacherUser::CBGAddTeacherUser(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGAddTeacherUser::IDD, pParent)
	, m_BGAddTCID(_T(""))
	, m_BGAddTCPassword(_T(""))
	, m_BGAddTCName(_T(""))
	, m_BGAddTCSex(_T(""))
	, m_BGAddTCTelephone(_T(""))
{

}

CBGAddTeacherUser::~CBGAddTeacherUser()
{
}

void CBGAddTeacherUser::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_BGAddTCID);
	DDX_Text(pDX, IDC_EDIT2, m_BGAddTCPassword);
	DDX_Text(pDX, IDC_EDIT3, m_BGAddTCName);
	DDX_CBString(pDX, IDC_COMBO1, m_BGAddTCSex);
	DDX_Text(pDX, IDC_EDIT4, m_BGAddTCTelephone);
}


BEGIN_MESSAGE_MAP(CBGAddTeacherUser, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBGAddTeacherUser::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CBGAddTeacherUser::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBGAddTeacherUser ��Ϣ�������


void CBGAddTeacherUser::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_BGAddTCID == _T("")){ 
		MessageBox(_T("�������˺ţ�"));
	}
	else{
		if(m_BGAddTCPassword == _T("")){
			MessageBox(_T("���������룡"));
		}
		else{
			if(m_BGAddTCName == _T("")){
			    MessageBox(_T("���������֣�"));
			}
			else{
				if(m_BGAddTCSex == _T("")){
			        MessageBox(_T("��ѡ���Ա�"));
			    }
				else{
					if(m_BGAddTCTelephone == _T("")){
					     MessageBox(_T("������绰��"));
					}
					else{
	                    teacher tch;
	                    tch.setinformation(m_BGAddTCID,m_BGAddTCPassword,m_BGAddTCName,m_BGAddTCTelephone,m_BGAddTCSex);
                     	tch.out();
						MessageBox(_T("�����û��ɹ���"));
						CDialogEx::OnOK();
					}
				}
			}
	    }
	}
	
	UpdateData(FALSE);
}


void CBGAddTeacherUser::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBGAddTeacherUser::OnBnClickedOk();
	CBGAddTeacherUser bga;
	bga.DoModal();
}
