#pragma once
#include "ClassStudent.h"

// CBGSearchSDFuzzy �Ի���

class CBGSearchSDFuzzy : public CDialogEx
{
	DECLARE_DYNAMIC(CBGSearchSDFuzzy)

public:
	CBGSearchSDFuzzy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBGSearchSDFuzzy();

// �Ի�������
	enum { IDD = IDD_DIALOG19 };
	student searchsdfuzzy[200];

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctllistBGSearchSDFuzzy;
	virtual BOOL OnInitDialog();
};
