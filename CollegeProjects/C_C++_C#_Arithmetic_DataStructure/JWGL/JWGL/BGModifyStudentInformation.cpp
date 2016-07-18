// BGModifyStudentInformation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGModifyStudentInformation.h"
#include "afxdialogex.h"


// CBGModifyStudentInformation �Ի���

IMPLEMENT_DYNAMIC(CBGModifyStudentInformation, CDialogEx)

CBGModifyStudentInformation::CBGModifyStudentInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGModifyStudentInformation::IDD, pParent)
	, m_BGModifySDID(_T(""))
	, m_BGModifySDPassword(_T(""))
	, m_BGModifySDName(_T(""))
	, m_BGModifySDSex(_T(""))
	, m_BGModifySDMajor(_T(""))
	, m_BGModifySDClass(_T(""))
	, m_BGModifySDTelephone(_T(""))
{

}

CBGModifyStudentInformation::~CBGModifyStudentInformation()
{
}

void CBGModifyStudentInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_BGModifySDID);
	DDX_Text(pDX, IDC_EDIT2, m_BGModifySDPassword);
	DDX_Text(pDX, IDC_EDIT3, m_BGModifySDName);
	DDX_CBString(pDX, IDC_COMBO1, m_BGModifySDSex);
	DDX_CBString(pDX, IDC_COMBO2, m_BGModifySDMajor);
	DDX_CBString(pDX, IDC_COMBO3, m_BGModifySDClass);
	DDX_Text(pDX, IDC_EDIT5, m_BGModifySDTelephone);
}


BEGIN_MESSAGE_MAP(CBGModifyStudentInformation, CDialogEx)
	ON_BN_CLICKED(IDOK, &CBGModifyStudentInformation::OnBnClickedOk)
END_MESSAGE_MAP()


// CBGModifyStudentInformation ��Ϣ�������


void CBGModifyStudentInformation::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CString oldid;
	oldid = modifysd.getid();
	if(m_BGModifySDID == _T("")){MessageBox(_T("�˺Ų���Ϊ�գ�"));}
	else{
		if(m_BGModifySDPassword == _T("")){MessageBox(_T("���벻��Ϊ�գ�"));}
		else{
			if(m_BGModifySDName == _T("")){MessageBox(_T("���ֲ���Ϊ�գ�"));}
			else{
				if(m_BGModifySDSex == _T("")){MessageBox(_T("�Ա���Ϊ�գ�"));}
				else{
					if(m_BGModifySDTelephone == _T("")){MessageBox(_T("�绰����Ϊ�գ�"));}
					else{
						if(m_BGModifySDMajor == _T("")){MessageBox(_T("רҵ����Ϊ�գ�"));}
						else{
							if(m_BGModifySDClass == _T("")){MessageBox(_T("�༶����Ϊ�գ�"));}
							else{
								modifysd.modifyinformation(oldid,m_BGModifySDID,m_BGModifySDPassword,m_BGModifySDName,m_BGModifySDSex,m_BGModifySDTelephone,m_BGModifySDMajor,m_BGModifySDClass);
								MessageBox(_T("�޸ĳɹ���"));
								CDialogEx::OnOK();
							}
						}
					}
				}
			}
		}
	}
}
