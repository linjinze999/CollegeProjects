#pragma once
#include "ClassStudent.h"

// CSDModifySDPassword �Ի���

class CSDModifySDPassword : public CDialogEx
{
	DECLARE_DYNAMIC(CSDModifySDPassword)

public:
	CSDModifySDPassword(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSDModifySDPassword();

// �Ի�������
	enum { IDD = IDD_DIALOG16 };
	student modifypw;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_SDIFMTOld;
	CString m_SDIFMTNew1;
	CString m_SDIFMTNew2;
	afx_msg void OnBnClickedOk();
};
