#pragma once


// BGPage5 �Ի���

class BGPage5 : public CPropertyPage
{
	DECLARE_DYNAMIC(BGPage5)

public:
	BGPage5();
	virtual ~BGPage5();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LARGE4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_BGStatType;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnPaint();
};
