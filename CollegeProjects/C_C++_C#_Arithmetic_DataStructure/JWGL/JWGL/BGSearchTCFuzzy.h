#pragma once
#include "afxcmn.h"
#include "ClassTeacher.h"

// CBGSearchTCFuzzy �Ի���

class CBGSearchTCFuzzy : public CDialogEx
{
	DECLARE_DYNAMIC(CBGSearchTCFuzzy)

public:
	CBGSearchTCFuzzy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGSearchTCFuzzy();

// �Ի�������
	enum { IDD = IDD_DIALOG20 };
	teacher searchtcfuzzy[200];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctllistBGSearchTCfUZZY;
	virtual BOOL OnInitDialog();
};
