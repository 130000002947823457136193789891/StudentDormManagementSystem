// Change.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ������.h"
#include "Change.h"
#include "afxdialogex.h"
#include "account.h"



// CChange �Ի���

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


// CChange ��Ϣ�������


void CChange::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Caccount cSet;
	if(!m_SureNew.IsEmpty()&&!m_old.IsEmpty ()&&m_strConfirm.IsEmpty()&&!m_user.IsEmpty () ){
		cSet.Open();
		if(cSet.IsEOF()){
			MessageBox("�û���������");
				cSet.Close();
		}
		else 
		{
			cSet.Close ();
			cSet.m_strFilter.Format ("password='%s'",m_old);
			cSet.Open();
			if(cSet.IsEOF ())    //����򿪼�¼���޼�¼
			{
				MessageBox("���������");
				cSet.Close();
			}
			else{
				if(m_SureNew==m_old)
					MessageBox("�¾����벻����ͬ��");
				else {
					if(m_SureNew !=m_old)
						MessageBox("������ȷ�����룡");
					else{
						MessageBox("�޸ĳɹ���");
						CDialogEx::OnOK();
					}
				}

			}
		}
	}

	else 
		MessageBox("���벻��Ϊ�գ�");
}
