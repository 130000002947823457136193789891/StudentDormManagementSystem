// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ������.h"
#include "AddDlg.h"
#include "afxdialogex.h"
#include "Student.h"


// AddDlg �Ի���

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


// AddDlg ��Ϣ�������


void AddDlg::OnRadioMale()
{
	// TODO: �ڴ���������������
	m_bMale=TRUE;
}


void AddDlg::OnRadioFemale()
{
	// TODO: �ڴ���������������
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
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣: OCX ����ҳӦ���� FALSE
	*/
}


void AddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cstudent mSet;
	UpdateData();
	m_strID.TrimLeft();
	m_strStudentName.TrimLeft();

	if(m_strStudentName.IsEmpty()||m_strID.IsEmpty())
		MessageBox("�����п��");
	else
	{
		mSet.m_strFilter .Format("ID='%s'",m_strID);
		mSet.Open();//�򿪼�¼��
		if(!mSet.IsEOF())
		{
			//already recorded
			MessageBox("��ID��Ϣ�Ѿ���ӡ�");
			mSet.Close();
		}
		else
		{
			MessageBox("��ӳɹ���");
			CDialog::OnOK();
		}
	}
	CDialogEx::OnOK();
}
