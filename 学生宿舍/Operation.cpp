// Operation.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ѧ������.h"
#include "Operation.h"
#include "afxdialogex.h"
#include "student.h"
#include "AddDlg.h"
#include "trueChange.h"
#include "account.h"

// Operation �Ի���

IMPLEMENT_DYNAMIC(Operation, CDialogEx)

Operation::Operation(CWnd* pParent /*=NULL*/)
	: CDialogEx(Operation::IDD, pParent)
{

}

Operation::~Operation()
{
}

void Operation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
}


BEGIN_MESSAGE_MAP(Operation, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Operation::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &Operation::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &Operation::OnBnClickedButtonChange)
END_MESSAGE_MAP()


// Operation ��Ϣ�������


BOOL Operation::OnInitDialog()
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
	CDialog::OnInitDialog ();
	CString strHeader[]={"ID","ѧ������","�Ա�"};
	int nLong[]={100,100,100};
	for(int nCol=0;nCol<sizeof(strHeader)/sizeof(CString);nCol++)
		m_listCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);

	//�����б���
	Cstudent sSet;
	sSet.Open();
	int nItem=0;
	CString str;
	while(!sSet.IsEOF()){
		for(UINT i=0;i<6;i++){
		sSet.GetFieldValue(i,str);
		if(i==0)
			m_listCtrl.InsertItem(nItem,str);
		else
			m_listCtrl.SetItemText(nItem,i,str);}
		m_listCtrl.SetItemText(nItem,6,sSet.m_Studentname );

	}
    sSet.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
/*
#5313
	return TRUE;  // return TRUE unless you set the focus to a control
#5313
	// �쳣: OCX ����ҳӦ���� FALSE
*/
}


void Operation::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Cstudent sSet;
	AddDlg dlg;
	if(dlg.DoModal()==IDOK){
		sSet.Open();
		sSet.AddNew();
		//sSet.m_ID=dlg.m_strID;
		sSet.m_Studentname=dlg.m_strStudentName;
		if(dlg.m_bMale==1)
			sSet.m_Sex="��";
		else 
			sSet.m_Sex="Ů";
		sSet.Update();
		sSet.Requery();
	}
	


}


void Operation::OnBnClickedButtonDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos;
	pos=m_listCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{MessageBox("��û��ѡ���б���");
	return;}
	int nItem=m_listCtrl.GetNextSelectedItem (pos);
	CString m_del_id1=m_listCtrl.GetItemText(nItem,0);
	CString m_del_id2=m_listCtrl.GetItemText(nItem,6);
	CString m_del_id3=m_listCtrl.GetItemText(nItem,8);
	if(IDYES==MessageBox("ȷ��Ҫɾ����","����",MB_ICONWARNING|MB_YESNO))
	{
		m_listCtrl.DeleteItem(nItem);
	}
	Cstudent sSet;
	sSet.m_strFilter.Format("ID='%S'",m_del_id1);
	sSet.Open();
	CRecordsetStatus status1;
	sSet.GetStatus(status1);
	sSet.Delete();
	if(status1.m_lCurrentRecord ==0)
		sSet.MoveNext ();
	else
		sSet.MoveFirst ();

	UpdateData(FALSE);      //���ؼ��ļ�¼����������

}


void Operation::OnBnClickedButtonChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	POSITION pos;
	pos=m_listCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL){
		MessageBox("��û��ѡ���б���");
		return;

	}
	int nItem=m_listCtrl.GetNextSelectedItem (pos);
	trueChange dlg;
	dlg.m_strID=m_listCtrl.GetItemText(nItem,0);
	dlg.m_strStudentName=m_listCtrl.GetItemText(nItem,1);
	Caccount pSet;
	Cstudent sSet;
	if(dlg.DoModal ()==IDOK)
	{
		sSet.m_strFilter.Format("ID='%s'",m_listCtrl.GetItemText(nItem,0));
		sSet.Open();
		sSet.Edit();
		sSet.m_Studentname =dlg.m_strStudentName ;
		if(dlg.m_bMale ==1)
			sSet.m_Sex ="��";
		else
			sSet.m_Sex ="Ů";
		sSet.Update();
		sSet.Requery ();
	}
}
