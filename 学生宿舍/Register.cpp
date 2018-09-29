// Register.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ������.h"
#include "Register.h"
#include "afxdialogex.h"
#include "account.h"


// CRegister �Ի���

IMPLEMENT_DYNAMIC(CRegister, CDialogEx)

CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegister::IDD, pParent)
	, m_strNewPassword(_T(""))
	, m_strPassword0(_T(""))
	, m_strUsername(_T(""))
{

}

CRegister::~CRegister()
{
}

void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT_NEWPASSWORD, m_newPassword);
	DDX_Text(pDX, IDC_EDIT_NEWPASSWORD, m_strNewPassword);
	DDX_Text(pDX, IDC_EDIT_PASSWORD0, m_strPassword0);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUsername);
	DDX_Control(pDX, IDCANCEL, m_bnOK);
	DDX_Control(pDX, IDOK, m_bnCancel);
}


BEGIN_MESSAGE_MAP(CRegister, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRegister::OnBnClickedOk)
END_MESSAGE_MAP()


// CRegister ��Ϣ�������


void CRegister::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	Caccount cSet;
	UpdateData();
	m_strUsername.TrimLeft ();
	m_strPassword0.TrimLeft ();
	if(!m_strPassword0.IsEmpty()&&!m_strUsername.IsEmpty()){
		if(m_strNewPassword.IsEmpty())
		AfxMessageBox(TEXT("��ȷ������"));
	else if(m_strPassword0!=m_strNewPassword &&!m_strNewPassword.IsEmpty())
		MessageBox("������ȷ������");
	else if(m_strPassword0 ==m_strNewPassword ){
		cSet.m_strFilter.Format("account='%s'",m_strUsername );
		cSet.Open();//�򿪼�¼��
		if(!cSet.IsEOF()){ //����򿪼�¼���м�¼
			MessageBox("�û����Ѵ��ڣ��������");
			cSet.Close();
		}
		else {
			MessageBox("ע��ɹ���");
			CDialogEx::OnOK();
		}
	}

	}
	else if(m_strPassword0 .IsEmpty()&&m_strUsername.IsEmpty())
		AfxMessageBox(TEXT("�û��������벻��Ϊ�գ�"));
	else if(m_strPassword0 .IsEmpty())
	AfxMessageBox(TEXT("���벻��Ϊ�գ�"));
	else if(m_strUsername.IsEmpty())
		AfxMessageBox(TEXT("�û�������Ϊ��"));
}
