#pragma once


// CBGAddTeacherUser �Ի���

class CBGAddTeacherUser : public CDialogEx
{
	DECLARE_DYNAMIC(CBGAddTeacherUser)

public:
	CBGAddTeacherUser(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGAddTeacherUser();

// �Ի�������
	enum { IDD = IDD_DIALOG10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_BGAddTCID;
	CString m_BGAddTCPassword;
	CString m_BGAddTCName;
	CString m_BGAddTCSex;
	CString m_BGAddTCTelephone;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};
