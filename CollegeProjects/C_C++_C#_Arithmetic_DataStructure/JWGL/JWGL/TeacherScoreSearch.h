#pragma once


// CTeacherScoreSearch �Ի���

class CTeacherScoreSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherScoreSearch)

public:
	CTeacherScoreSearch(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherScoreSearch();

// �Ի�������
	enum { IDD = IDD_DIALOG17 };
	CString classname;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_TCScoreSearchID;
};
