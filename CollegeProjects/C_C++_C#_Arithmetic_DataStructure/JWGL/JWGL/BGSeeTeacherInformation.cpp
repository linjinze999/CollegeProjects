// BGSeeTeacherInformation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "BGSeeTeacherInformation.h"
#include "afxdialogex.h"


// CBGSeeTeacherInformation �Ի���

IMPLEMENT_DYNAMIC(CBGSeeTeacherInformation, CDialogEx)

CBGSeeTeacherInformation::CBGSeeTeacherInformation(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBGSeeTeacherInformation::IDD, pParent)
	, m_BGSearchTeacherExactID(_T(""))
	, m_BGSearchTeacherExactPassword(_T(""))
	, m_BGSearchTeacherExactName(_T(""))
	, m_BGSearchTeacherExactSex(_T(""))
	, m_BGSearchTeacherExactTelephone(_T(""))
{

}

CBGSeeTeacherInformation::~CBGSeeTeacherInformation()
{
}

void CBGSeeTeacherInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_BGSearchTeacherExactID);
	DDX_Text(pDX, IDC_EDIT2, m_BGSearchTeacherExactPassword);
	DDX_Text(pDX, IDC_EDIT3, m_BGSearchTeacherExactName);
	DDX_Text(pDX, IDC_EDIT4, m_BGSearchTeacherExactSex);
	DDX_Text(pDX, IDC_EDIT5, m_BGSearchTeacherExactTelephone);
}


BEGIN_MESSAGE_MAP(CBGSeeTeacherInformation, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT4, &CBGSeeTeacherInformation::OnEnChangeEdit4)
END_MESSAGE_MAP()


// CBGSeeTeacherInformation ��Ϣ�������


void CBGSeeTeacherInformation::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
