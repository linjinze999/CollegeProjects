#pragma once


// CBGSeeTeacherInformation �Ի���

class CBGSeeTeacherInformation : public CDialogEx
{
	DECLARE_DYNAMIC(CBGSeeTeacherInformation)

public:
	CBGSeeTeacherInformation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGSeeTeacherInformation();

// �Ի�������
	enum { IDD = IDD_DIALOG14 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit4();
	CString m_BGSearchTeacherExactID;
	CString m_BGSearchTeacherExactPassword;
	CString m_BGSearchTeacherExactName;
	CString m_BGSearchTeacherExactSex;
	CString m_BGSearchTeacherExactTelephone;
};
