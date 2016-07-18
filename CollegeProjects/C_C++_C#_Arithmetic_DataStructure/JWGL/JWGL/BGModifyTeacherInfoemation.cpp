// BGModifyTeacherInfoemation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGModifyTeacherInfoemation.h"
#include "afxdialogex.h"


// CBGModifyTeacherInfoemation �Ի���

IMPLEMENT_DYNAMIC(CBGModifyTeacherInfoemation, CDialogEx)

CBGModifyTeacherInfoemation::CBGModifyTeacherInfoemation(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGModifyTeacherInfoemation::IDD, pParent)
	, m_BGModifyTCID(_T(""))
	, m_BGModifyTCPassword(_T(""))
	, m_BGModifyTCName(_T(""))
	, m_BGModifyTCSex(_T(""))
	, m_BGModifyTCTelephone(_T(""))
{

}

CBGModifyTeacherInfoemation::~CBGModifyTeacherInfoemation()
{
}

void CBGModifyTeacherInfoemation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_BGModifyTCID);
	DDX_Text(pDX, IDC_EDIT2, m_BGModifyTCPassword);
	DDX_Text(pDX, IDC_EDIT3, m_BGModifyTCName);
	DDX_CBString(pDX, IDC_COMBO1, m_BGModifyTCSex);
	DDX_Text(pDX, IDC_EDIT4, m_BGModifyTCTelephone);
}


BEGIN_MESSAGE_MAP(CBGModifyTeacherInfoemation, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT3, &CBGModifyTeacherInfoemation::OnEnChangeEdit3)
	ON_BN_CLICKED(IDOK, &CBGModifyTeacherInfoemation::OnBnClickedOk)
END_MESSAGE_MAP()


// CBGModifyTeacherInfoemation ��Ϣ�������


void CBGModifyTeacherInfoemation::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CBGModifyTeacherInfoemation::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CString oldid;
	oldid = modifyinformation.getid();
	if(m_BGModifyTCID == _T("")){MessageBox(_T("�˺Ų���Ϊ�գ�"));}
	else{
		if(m_BGModifyTCPassword == _T("")){MessageBox(_T("���벻��Ϊ�գ�"));}
		else{
			if(m_BGModifyTCName == _T("")){MessageBox(_T("���ֲ���Ϊ�գ�"));}
			else{
				if(m_BGModifyTCSex == _T("")){MessageBox(_T("�Ա���Ϊ�գ�"));}
				else{
					if(m_BGModifyTCTelephone == _T("")){MessageBox(_T("�绰����Ϊ�գ�"));}
					else{
						modifyinformation.modifyinformation(oldid,m_BGModifyTCID,m_BGModifyTCPassword,m_BGModifyTCName,m_BGModifyTCSex,m_BGModifyTCTelephone);
						MessageBox(_T("�޸ĳɹ���"));
						CDialogEx::OnOK();
					}
				}
			}
		}
	}
}
