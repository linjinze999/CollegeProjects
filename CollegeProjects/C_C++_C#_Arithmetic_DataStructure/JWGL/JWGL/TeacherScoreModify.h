#pragma once


// CTeacherScoreModify �Ի���

class CTeacherScoreModify : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherScoreModify)

public:
	CTeacherScoreModify(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherScoreModify();

// �Ի�������
	enum { IDD = IDD_DIALOG8 };
	CString classname;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_TCScoreModifyID;
	CString m_TCScoreModifyScore;
	afx_msg void OnBnClickedOk();
	CString m_TCScoreModifyOld;
	afx_msg void OnEnChangeEdit1();
};
