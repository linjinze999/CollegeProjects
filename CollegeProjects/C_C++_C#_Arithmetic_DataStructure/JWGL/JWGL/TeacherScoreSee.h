#pragma once
#include "afxcmn.h"


// CTeacherScoreSee �Ի���

class CTeacherScoreSee : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherScoreSee)

public:
	CTeacherScoreSee(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherScoreSee();

// �Ի�������
	enum { IDD = IDD_DIALOG9 };
	CString classname;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_TCScoreSeeCtllist;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
