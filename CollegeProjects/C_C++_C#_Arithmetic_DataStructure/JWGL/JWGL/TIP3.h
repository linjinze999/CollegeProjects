#pragma once


// CTIP3 �Ի���

class CTIP3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTIP3)

public:
	CTIP3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTIP3();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
