#pragma once


// StudentMessageForTeacherWindow �Ի���

class StudentMessageForTeacherWindow : public CDialogEx
{
	DECLARE_DYNAMIC(StudentMessageForTeacherWindow)

public:
	StudentMessageForTeacherWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~StudentMessageForTeacherWindow();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };
	CString tcname;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctllistSDMessageForTC;
	virtual BOOL OnInitDialog();
};
