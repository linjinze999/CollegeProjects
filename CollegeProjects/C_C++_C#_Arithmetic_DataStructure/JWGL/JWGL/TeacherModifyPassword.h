#pragma once
#include "ClassTeacher.h"


// CTeacherModifyPassword �Ի���

class CTeacherModifyPassword : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherModifyPassword)

public:
	CTeacherModifyPassword(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherModifyPassword();

// �Ի�������
	enum { IDD = IDD_DIALOG18 };
	teacher modify;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_TCModifyPWOld;
	CString m_TCModifyPWnew1;
	CString m_TCModifyPWnew2;
	afx_msg void OnBnClickedOk();
};
