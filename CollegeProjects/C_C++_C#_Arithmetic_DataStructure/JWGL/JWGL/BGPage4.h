#pragma once


// BGPage4 �Ի���

class BGPage4 : public CPropertyPage
{
	DECLARE_DYNAMIC(BGPage4)

public:
	BGPage4();
	virtual ~BGPage4();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio1();
//	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	CString m_BGSerchID;
	CString m_BGSerchKeyword;
//	virtual BOOL OnInitDialog();
//	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};
