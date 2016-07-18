
// IQtestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IQtest.h"
#include "IQtestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
int a=0,b=0;

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

// CIQtestDlg �Ի���




CIQtestDlg::CIQtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIQtestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIQtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIQtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON2, &CIQtestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CIQtestDlg::OnBnClickedButton1)
//	ON_WM_CTLCOLOR()
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CIQtestDlg ��Ϣ�������

BOOL CIQtestDlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CIQtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CIQtestDlg::OnPaint()
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
		//CDialogEx::OnPaint();
		 CPaintDC   dc(this);   
         CRect   rect;   
         GetClientRect(&rect);   
         CDC   dcMem;   
         dcMem.CreateCompatibleDC(&dc);   
         CBitmap   bmpBackground;   
         bmpBackground.LoadBitmap(IDB_BITMAP1);   
         BITMAP   bitmap;   
         bmpBackground.GetBitmap(&bitmap);   
         CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   
         dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);   
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CIQtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CIQtestDlg::PreTranslateMessage(MSG* pMsg)
{
	// �ڴ��ƶ���ť
	CRect rect; 
    GetDlgItem(IDC_BUTTON1)->GetWindowRect(&rect); 
    if(rect.PtInRect(pMsg->pt)) 
    { 
		CWnd *pWnd;
        pWnd = GetDlgItem( IDC_BUTTON1 ); 
		if(m_mouse.x<150){
            a=0;
		}
		else{
			if(m_mouse.x>350){
				a=1;
			}
		}
		if(m_mouse.y<50){
				b=0;;
		}
	    else{
			if(m_mouse.y>250){
				b=1;
			}
		}
		if(a == 0 ){
			if(b == 0 ){
				pWnd->MoveWindow( CRect(m_mouse.x+5,m_mouse.y+5,m_mouse.x+150,m_mouse.y+50) ); 
			}
			if(b == 1){
			     pWnd->MoveWindow( CRect(m_mouse.x+5,m_mouse.y-50,m_mouse.x+150,m_mouse.y-5) ); 
			}
		}
		if(a == 1){
			if(b == 0 ){
				pWnd->MoveWindow( CRect(m_mouse.x-150,m_mouse.y+5,m_mouse.x-5,m_mouse.y+50) ); 
			}
			if(b == 1){
			    pWnd->MoveWindow( CRect(m_mouse.x-150,m_mouse.y-50,m_mouse.x-5,m_mouse.y-5) ); 
			}
		}
    }
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CIQtestDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// ��ȡ���λ��
	m_mouse = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CIQtestDlg::OnBnClickedButton2()
{
	//�̶���ť
	MessageBox(_T("����˵�㲻�Ƕ�����O(��_��)O����~\n    �Ͻ�ȥ�������ж��ٶ������Ѱ�~"));
}


void CIQtestDlg::OnBnClickedButton1()
{
	// �ƶ���ť
	MessageBox(_T("ΪʲôҪ׷�ң���å����"));
}




HBRUSH CIQtestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// ʹ��̬�ı��򱳾�Ϊ͸��
	HBRUSH   hBrush   =   CDialog::OnCtlColor(pDC,   pWnd,   nCtlColor);      
	if(nCtlColor == CTLCOLOR_STATIC){  
		pDC->SetBkMode(TRANSPARENT); 
	    return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	} 
	return hBrush;
}
