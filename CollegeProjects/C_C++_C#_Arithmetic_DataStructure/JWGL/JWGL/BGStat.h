#pragma once
#include "afxcmn.h"


// CBGStat �Ի���

class CBGStat : public CDialogEx
{
	DECLARE_DYNAMIC(CBGStat)

public:
	CBGStat(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGStat();

// �Ի�������
	enum { IDD = IDD_DIALOG21 };
	int stattype;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_BGStatCtllist;
	virtual BOOL OnInitDialog();
};
