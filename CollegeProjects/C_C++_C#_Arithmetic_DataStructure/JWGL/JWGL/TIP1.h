#pragma once


// CTIP1 �Ի���

class CTIP1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTIP1)

public:
	CTIP1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTIP1();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
