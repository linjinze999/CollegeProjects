#pragma once


// CTeacherPage4 �Ի���

class CTeacherPage4 : public CPropertyPage
{
	DECLARE_DYNAMIC(CTeacherPage4)

public:
	CTeacherPage4();
	virtual ~CTeacherPage4();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_TCIFMTName;
	CString m_TCIFMTID;
	CString m_TCIFMTSex;
	CString m_TCIFMTTelephone;
	CString m_TCIFMTPassword;
	afx_msg void OnPaint();
};
