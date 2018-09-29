// student.h : Cstudent ���ʵ��



// Cstudent ʵ��

// ���������� 2018��7��14��, 18:23

#include "stdafx.h"
#include "student.h"
IMPLEMENT_DYNAMIC(Cstudent, CRecordset)

Cstudent::Cstudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Studentname = "";
	m_Sex = "";
	m_nFields = 3;
	m_nDefaultType = snapshot;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Cstudent::GetDefaultConnect()
{
	return _T("DSN=studentsys;SERVER=localhost;UID=root;PWD=13508459029;DATABASE=stuinfo;PORT=3306");
}

CString Cstudent::GetDefaultSQL()
{
	return _T("[student]");
}

void Cstudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Byte(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Studentname]"), m_Studentname);
	RFX_Text(pFX, _T("[Sex]"), m_Sex);

}
/////////////////////////////////////////////////////////////////////////////
// Cstudent ���

#ifdef _DEBUG
void Cstudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cstudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


