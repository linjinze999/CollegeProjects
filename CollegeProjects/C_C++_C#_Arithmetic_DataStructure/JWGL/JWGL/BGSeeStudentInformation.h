#pragma once


// CBGSeeStudentInformation �Ի���

class CBGSeeStudentInformation : public CDialogEx
{
	DECLARE_DYNAMIC(CBGSeeStudentInformation)

public:
	CBGSeeStudentInformation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGSeeStudentInformation();

// �Ի�������
	enum { IDD = IDD_DIALOG15 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_BGSearchExactID;
	CString m_BGSearchExactPassword;
	CString m_BGSearchExactName;
	CString m_BGSearchExactSex;
	CString m_BGSearchExactTelephone;
	CString m_BGSearchExactMajor;
	CString m_BGSearchExactNoclass;
};
