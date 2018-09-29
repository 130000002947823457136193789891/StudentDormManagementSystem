// Operation.cpp : 实现文件
//

#include "stdafx.h"
#include "学生宿舍.h"
#include "Operation.h"
#include "afxdialogex.h"
#include "student.h"
#include "AddDlg.h"
#include "trueChange.h"
#include "account.h"

// Operation 对话框

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


// Operation 消息处理程序


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
	// TODO:  在此添加额外的初始化
	CDialog::OnInitDialog ();
	CString strHeader[]={"ID","学生姓名","性别"};
	int nLong[]={100,100,100};
	for(int nCol=0;nCol<sizeof(strHeader)/sizeof(CString);nCol++)
		m_listCtrl.InsertColumn(nCol,strHeader[nCol],LVCFMT_LEFT,nLong[nCol]);

	//创建列表项
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
	// 异常: OCX 属性页应返回 FALSE
*/
}


void Operation::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	Cstudent sSet;
	AddDlg dlg;
	if(dlg.DoModal()==IDOK){
		sSet.Open();
		sSet.AddNew();
		//sSet.m_ID=dlg.m_strID;
		sSet.m_Studentname=dlg.m_strStudentName;
		if(dlg.m_bMale==1)
			sSet.m_Sex="男";
		else 
			sSet.m_Sex="女";
		sSet.Update();
		sSet.Requery();
	}
	


}


void Operation::OnBnClickedButtonDel()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos;
	pos=m_listCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL)
	{MessageBox("还没有选中列表项");
	return;}
	int nItem=m_listCtrl.GetNextSelectedItem (pos);
	CString m_del_id1=m_listCtrl.GetItemText(nItem,0);
	CString m_del_id2=m_listCtrl.GetItemText(nItem,6);
	CString m_del_id3=m_listCtrl.GetItemText(nItem,8);
	if(IDYES==MessageBox("确定要删除吗？","警告",MB_ICONWARNING|MB_YESNO))
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

	UpdateData(FALSE);      //将控件的记录传到变量中

}


void Operation::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos;
	pos=m_listCtrl.GetFirstSelectedItemPosition();
	if(pos==NULL){
		MessageBox("还没有选中列表项");
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
			sSet.m_Sex ="男";
		else
			sSet.m_Sex ="女";
		sSet.Update();
		sSet.Requery ();
	}
}
