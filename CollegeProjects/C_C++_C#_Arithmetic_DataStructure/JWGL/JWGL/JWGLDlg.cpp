
// JWGLDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JWGL.h"
#include "JWGLDlg.h"
#include "afxdialogex.h"
#include "TIP1.h"
#include "TIP2.h"
#include "TIP3.h"
#include "BGWindow.h"
#include "TeacherWindow.h"
#include "StudentWindow.h"
#include "ClassStudent.h"
#include "ClassTeacher.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

int usertype =0;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CJWGLDlg �Ի���




CJWGLDlg::CJWGLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJWGLDlg::IDD, pParent)
	, m_idnumber(_T(""))
	, m_password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJWGLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_idnumber);
	DDV_MaxChars(pDX, m_idnumber, 10);
	DDX_Text(pDX, IDC_EDIT2, m_password);
	DDV_MaxChars(pDX, m_password, 10);
}

BEGIN_MESSAGE_MAP(CJWGLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CJWGLDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CJWGLDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CJWGLDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CJWGLDlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// CJWGLDlg ��Ϣ�������

BOOL CJWGLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SkinH_Attach();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CJWGLDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CJWGLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CJWGLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CJWGLDlg::OnBnClickedButton1()//��½����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE); 
	if( usertype == 1){
		teacher tclogin;
		bool ser;
		ser = tclogin.serch(m_idnumber);
		if(ser && m_password == tclogin.getpassword()){
			//���ش��ڴ���
	        TeacherWindow Propage(_T("��ʦ�û���")); 
			Propage.m_tcpage0.m_TCIFMTID = tclogin.getid();
			Propage.m_tcpage0.m_TCIFMTPassword = tclogin.getpassword();
			Propage.m_tcpage0.m_TCIFMTName = tclogin.getname();
			Propage.m_tcpage0.m_TCIFMTSex = tclogin.getsex();
			Propage.m_tcpage0.m_TCIFMTTelephone = tclogin.gettelephone();
			Propage.m_tcpage1.m_TCCourseName = tclogin.getname();
			Propage.m_tcpage3.message.setname(tclogin.getname());
			Propage.m_tcpage2.tcname = tclogin.getname();
			Propage.DoModal();
			//�رմ��ڴ���
	    }
	    else{
	        CTIP2 tip2;
		    tip2.DoModal();
	    }
	}
	else{
		if( usertype == 2){
			student sdlogin;
			bool serc;
			serc = sdlogin.serch(m_idnumber);
			if(serc && m_password == sdlogin.getpassword()){
				//���ش��ڴ���
	            StudentWindow Propage(_T("ѧ���û���")); 
				Propage.m_sdpage1.m_SDIFMTID = sdlogin.getid();
				Propage.m_sdpage1.m_SDIFMTPassword = sdlogin.getpassword();
				Propage.m_sdpage1.m_SDIFMTName = sdlogin.getname();
				Propage.m_sdpage1.m_SDIFMTSex = sdlogin.getsex();
				Propage.m_sdpage1.m_SDIFMTTelephone = sdlogin.gettelephone();
				Propage.m_sdpage1.m_SDIFMTMajor = sdlogin.getmajor();
				Propage.m_sdpage1.m_SDIFMTNoclass = sdlogin.getnoclass();
				Propage.m_sdpage2.sdname = sdlogin.getname();
				Propage.m_sdpage3.studentname = sdlogin.getname();
				Propage.m_sdpage4.sdname = sdlogin.getname();
				Propage.DoModal();
				//�رմ��ڴ���
	        }
	        else{
	            CTIP2 tip2;
		        tip2.DoModal();
	        }
		}
		else{
			if(usertype == 3){
			    if(m_idnumber == "1111" && m_password == "1111"){
					//���ش��ڴ���
					BGWindow Propage(_T("��̨�û�����")); 
			        Propage.DoModal();
					//�رմ��ڴ���
	            }
	            else{
	                CTIP2 tip2;
		            tip2.DoModal();
	            }
			}
			else{
			    CTIP3 tip3;
		        tip3.DoModal();
			}
		}
	}
	UpdateData(FALSE); 
}


void CJWGLDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	usertype = 1;
}


void CJWGLDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	usertype = 2;
}


void CJWGLDlg::OnBnClickedRadio3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	usertype = 3;
}
