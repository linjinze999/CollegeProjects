#pragma once


// BGPage1 �Ի���

class BGPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(BGPage1)

public:
	BGPage1();
	virtual ~BGPage1();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};
