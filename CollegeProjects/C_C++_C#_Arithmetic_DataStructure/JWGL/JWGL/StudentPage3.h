#pragma once
#include "afxcmn.h"


// StudentPage3 �Ի���

class StudentPage3 : public CPropertyPage
{
	DECLARE_DYNAMIC(StudentPage3)

public:
	StudentPage3();
	virtual ~StudentPage3();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE10 };
	CString studentname;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_SDSeeScore;
	virtual BOOL OnInitDialog();
};
