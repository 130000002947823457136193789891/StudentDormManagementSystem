// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍.h"
#include "AddDlg.h"
#include "afxdialogex.h"
#include "Student.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(AddDlg::IDD, pParent)
	, m_bMale(false)
	, m_strID(_T(""))
	, m_strStudentName(_T(""))
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_STUDENTNAME, m_strStudentName);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
	ON_COMMAND(IDC_RADIO_MALE, &AddDlg::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &AddDlg::OnRadioFemale)
	ON_BN_CLICKED(IDOK, &AddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AddDlg 消息处理程序


void AddDlg::OnRadioMale()
{
	// TODO: 在此添加命令处理程序代码
	m_bMale=TRUE;
}


void AddDlg::OnRadioFemale()
{
	// TODO: 在此添加命令处理程序代码
	m_bMale=FALSE;
}


BOOL AddDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
/*
#5312

	return TRUE;  // return TRUE unless you set the focus to a control
#5313

#5312

	return TRUE;  // return TRUE unless you set the focus to a control
#5313
	*/
	// TODO:  在此添加额外的初始化
	if(!m_bMale)
		CheckRadioButton(IDC_RADIO_MALE,IDC_RADIO_FEMALE,IDC_RADIO_FEMALE);
	else
		CheckRadioButton(IDC_RADIO_MALE,IDC_RADIO_FEMALE,IDC_RADIO_MALE);
	UpdateData();
	

	return TRUE;  // return TRUE unless you set the focus to a control
/*
#5313
	return TRUE;  // return TRUE unless you set the focus to a control
#5313
	// 异常: OCX 属性页应返回 FALSE
	*/
}


void AddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Cstudent mSet;
	UpdateData();
	m_strID.TrimLeft();
	m_strStudentName.TrimLeft();

	if(m_strStudentName.IsEmpty()||m_strID.IsEmpty())
		MessageBox("不能有空项！");
	else
	{
		mSet.m_strFilter .Format("ID='%s'",m_strID);
		mSet.Open();//打开记录集
		if(!mSet.IsEOF())
		{
			//already recorded
			MessageBox("该ID信息已经添加。");
			mSet.Close();
		}
		else
		{
			MessageBox("添加成功！");
			CDialog::OnOK();
		}
	}
	CDialogEx::OnOK();
}
