// trueChange.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍.h"
#include "trueChange.h"
#include "afxdialogex.h"


// trueChange 对话框

IMPLEMENT_DYNAMIC(trueChange, CDialogEx)

trueChange::trueChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(trueChange::IDD, pParent)
	, m_bMale(false)
	, m_strID(_T(""))
	, m_strStudentName(_T(""))
{

}

trueChange::~trueChange()
{
}

void trueChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_STU, m_strStudentName);
}


BEGIN_MESSAGE_MAP(trueChange, CDialogEx)
	ON_BN_CLICKED(IDC_MALE, &trueChange::OnBnClickedMale)
	ON_BN_CLICKED(IDC_FEMALE, &trueChange::OnBnClickedFemale)
END_MESSAGE_MAP()


// trueChange 消息处理程序


void trueChange::OnBnClickedMale()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bMale=TRUE;
}


void trueChange::OnBnClickedFemale()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bMale=FALSE;
}


BOOL trueChange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	if(!m_bMale)
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_FEMALE);
	else
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_MALE);
	UpdateData(FALSE);      //将控件的值传入变量中
	

	return TRUE;  // return TRUE unless you set the focus to a control

}
