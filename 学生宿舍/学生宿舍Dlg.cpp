
// 学生宿舍Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍.h"
#include "学生宿舍Dlg.h"
#include "afxdialogex.h"
#include "account.h"
#include "Register.h"
#include "Operation.h"
#include "Change.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

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


// C学生宿舍Dlg 对话框



C学生宿舍Dlg::C学生宿舍Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C学生宿舍Dlg::IDD, pParent)
	, m_strAccount(_T(""))
	, m_strPassword(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C学生宿舍Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_CHANGE, m_bnChange);
	DDX_Control(pDX, IDC_BUTTON_LOGIN, m_bnLogIn);
	DDX_Control(pDX, IDC_BUTTON_LOGOUT, m_bnLogOut);
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, m_strAccount);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
}

BEGIN_MESSAGE_MAP(C学生宿舍Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &C学生宿舍Dlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, &C学生宿舍Dlg::OnBnClickedButtonLogout)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &C学生宿舍Dlg::OnBnClickedButtonChange)
END_MESSAGE_MAP()


// C学生宿舍Dlg 消息处理程序

BOOL C学生宿舍Dlg::OnInitDialog()
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

void C学生宿舍Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C学生宿舍Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C学生宿舍Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C学生宿舍Dlg::OnBnClickedButtonLogin()
{
	// TODO: 在此添加控件通知处理程序代码
		Caccount pSet;
	UpdateData();
	m_strAccount.TrimLeft();
	m_strPassword.TrimLeft();
	if(m_strAccount.IsEmpty()||m_strPassword.IsEmpty())
	{
		AfxMessageBox(TEXT("账号，密码不能为空！"));
		return;
	}
	if(pSet.IsOpen())
		pSet.Close();
	pSet.m_strFilter .Format ("account='%s'",m_strAccount);
	pSet.Open();
	if(!pSet.IsEOF())        //如果记录集不为空
	{
		pSet.Close();
		pSet.m_strFilter .Format ("account='%s'and password='%s'",m_strAccount,m_strPassword);
		pSet.Open();
		if(!pSet.IsEOF())
		{
			MessageBox("登录成功");
			pSet.Close();
			OnCancel();
			Operation dlg;
			//C学生宿舍Dlg dlg;
			dlg.DoModal ();

		}
		else
			MessageBox("密码错误");
	}

}


void C学生宿舍Dlg::OnBnClickedButtonLogout()
{
	// TODO: 在此添加控件通知处理程序代码
	CRegister dlg;
	dlg.DoModal ();

}


void C学生宿舍Dlg::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	Caccount cSet;
	CChange dlg;
	if(dlg.DoModal ()==IDOK){
		cSet.Open();
		cSet.Edit();
		cSet.m_password =dlg.m_SureNew ;     //确定新密码即代表新密码值
		cSet.Update();
		cSet.Requery ();

	}
}
