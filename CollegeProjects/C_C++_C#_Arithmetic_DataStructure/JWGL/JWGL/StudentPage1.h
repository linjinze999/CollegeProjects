#pragma once


// StudentPage1 �Ի���

class StudentPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(StudentPage1)

public:
	StudentPage1();
	virtual ~StudentPage1();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	CString m_SDIFMTName;
	CString m_SDIFMTID;
	CString m_SDIFMTSex;
	CString m_SDIFMTTelephone;
	CString m_SDIFMTMajor;
	CString m_SDIFMTNoclass;
	CString m_SDIFMTPassword;
	afx_msg void OnPaint();
};
