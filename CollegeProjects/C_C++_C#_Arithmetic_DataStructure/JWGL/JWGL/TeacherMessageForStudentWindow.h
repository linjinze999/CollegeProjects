#pragma once
#include "afxwin.h"

// TeacherMessageForStudentWindow �Ի���

class TeacherMessageForStudentWindow : public CDialogEx
{
	DECLARE_DYNAMIC(TeacherMessageForStudentWindow)

public:
	TeacherMessageForStudentWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TeacherMessageForStudentWindow();

// �Ի�������
	enum { IDD = IDD_DIALOG7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_TCMessageForSD;
	CString m_TCMessageClassName;
	CString m_TCMessageMessage;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CComboBox m_TCMessageCourseName;
};
