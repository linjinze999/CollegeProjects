
// IQtestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IQtest.h"
#include "IQtestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
int a=0,b=0;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// CIQtestDlg 对话框




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


// CIQtestDlg 消息处理程序

BOOL CIQtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CIQtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CIQtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CIQtestDlg::PreTranslateMessage(MSG* pMsg)
{
	// 在此移动按钮
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
	// 获取鼠标位置
	m_mouse = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CIQtestDlg::OnBnClickedButton2()
{
	//固定按钮
	MessageBox(_T("还敢说你不是逗比吗，O(∩_∩)O哈哈~\n    赶紧去试试你有多少逗比朋友吧~"));
}


void CIQtestDlg::OnBnClickedButton1()
{
	// 移动按钮
	MessageBox(_T("为什么要追我！流氓！！"));
}




HBRUSH CIQtestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// 使静态文本框背景为透明
	HBRUSH   hBrush   =   CDialog::OnCtlColor(pDC,   pWnd,   nCtlColor);      
	if(nCtlColor == CTLCOLOR_STATIC){  
		pDC->SetBkMode(TRANSPARENT); 
	    return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	} 
	return hBrush;
}
