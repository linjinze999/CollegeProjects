#pragma once


// CTIP2 �Ի���

class CTIP2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTIP2)

public:
	CTIP2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTIP2();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
