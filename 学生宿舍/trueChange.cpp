// trueChange.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ������.h"
#include "trueChange.h"
#include "afxdialogex.h"


// trueChange �Ի���

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


// trueChange ��Ϣ�������


void trueChange::OnBnClickedMale()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bMale=TRUE;
}


void trueChange::OnBnClickedFemale()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bMale=FALSE;
}


BOOL trueChange::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	if(!m_bMale)
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_FEMALE);
	else
		CheckRadioButton(IDC_MALE,IDC_FEMALE,IDC_MALE);
	UpdateData(FALSE);      //���ؼ���ֵ���������
	

	return TRUE;  // return TRUE unless you set the focus to a control

}
