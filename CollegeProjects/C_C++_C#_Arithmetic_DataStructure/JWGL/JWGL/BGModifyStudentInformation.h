#pragma once
#include "ClassStudent.h"

// CBGModifyStudentInformation �Ի���

class CBGModifyStudentInformation : public CDialogEx
{
	DECLARE_DYNAMIC(CBGModifyStudentInformation)

public:
	CBGModifyStudentInformation(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGModifyStudentInformation();

// �Ի�������
	enum { IDD = IDD_DIALOG13 };
	student modifysd;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_BGModifySDID;
	CString m_BGModifySDPassword;
	CString m_BGModifySDName;
	CString m_BGModifySDSex;
	CString m_BGModifySDMajor;
	CString m_BGModifySDClass;
	CString m_BGModifySDTelephone;
	afx_msg void OnBnClickedOk();
};
