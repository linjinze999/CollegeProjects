#pragma once
#include "ClassTeacher.h"

// TeacherAddCourseWindow �Ի���

class TeacherAddCourseWindow : public CDialogEx
{
	DECLARE_DYNAMIC(TeacherAddCourseWindow)

public:
	TeacherAddCourseWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TeacherAddCourseWindow();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };
	teacher addcourse;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit2();
	CString m_TCAddCourseClassname;
	CString m_TCAddCourseClassMessage;
	afx_msg void OnBnClickedOk();
};
