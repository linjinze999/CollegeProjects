#pragma once


// CBGAddStudentUser �Ի���

class CBGAddStudentUser : public CDialogEx
{
	DECLARE_DYNAMIC(CBGAddStudentUser)

public:
	CBGAddStudentUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGAddStudentUser();

// �Ի�������
	enum { IDD = IDD_DIALOG11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_AddSDID;
	CString m_AddSDPassword;
	CString m_AddSDName;
	CString m_AddSDSex;
	CString m_AddSDTelephone;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	CString m_AddSDMajor;
	CString m_AddSDNoclasses;
	afx_msg void OnCbnSelchangeCombo3();
};
