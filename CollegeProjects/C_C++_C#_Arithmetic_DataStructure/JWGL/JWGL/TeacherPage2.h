#pragma once
#include "afxwin.h"


// TeacherPage2 �Ի���

class TeacherPage2 : public CPropertyPage
{
	DECLARE_DYNAMIC(TeacherPage2)

public:
	TeacherPage2();
	virtual ~TeacherPage2();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE6 };
	CString tcname;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_TCScore;
	CComboBox m_TCScoreCourseName;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString m_TCScoreCourseNM;
	afx_msg void OnPaint();
};
