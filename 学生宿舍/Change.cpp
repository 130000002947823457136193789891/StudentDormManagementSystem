// Change.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍.h"
#include "Change.h"
#include "afxdialogex.h"
#include "account.h"



// CChange 对话框

IMPLEMENT_DYNAMIC(CChange, CDialogEx)

CChange::CChange(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChange::IDD, pParent)
	, m_old(_T(""))
	, m_SureNew(_T(""))
	, m_user(_T(""))
	, m_strConfirm(_T(""))
{

}

CChange::~CChange()
{
}

void CChange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OLD, m_old);
	DDX_Text(pDX, IDC_EDIT_SURENEW, m_SureNew);
	DDX_Text(pDX, IDC_EDIT_USER, m_user);
	DDX_Text(pDX, IDC_EDIT_CONFIRM, m_strConfirm);
}


BEGIN_MESSAGE_MAP(CChange, CDialogEx)
	ON_BN_CLICKED(IDOK, &CChange::OnBnClickedOk)
END_MESSAGE_MAP()


// CChange 消息处理程序


void CChange::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Caccount cSet;
	if(!m_SureNew.IsEmpty()&&!m_old.IsEmpty ()&&m_strConfirm.IsEmpty()&&!m_user.IsEmpty () ){
		cSet.Open();
		if(cSet.IsEOF()){
			MessageBox("用户名不存在");
				cSet.Close();
		}
		else 
		{
			cSet.Close ();
			cSet.m_strFilter.Format ("password='%s'",m_old);
			cSet.Open();
			if(cSet.IsEOF ())    //如果打开记录集无记录
			{
				MessageBox("旧密码错误！");
				cSet.Close();
			}
			else{
				if(m_SureNew==m_old)
					MessageBox("新旧密码不能相同！");
				else {
					if(m_SureNew !=m_old)
						MessageBox("请重新确认密码！");
					else{
						MessageBox("修改成功！");
						CDialogEx::OnOK();
					}
				}

			}
		}
	}

	else 
		MessageBox("密码不能为空！");
}
