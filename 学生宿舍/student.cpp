// student.h : Cstudent 类的实现



// Cstudent 实现

// 代码生成在 2018年7月14日, 18:23

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Byte(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Studentname]"), m_Studentname);
	RFX_Text(pFX, _T("[Sex]"), m_Sex);

}
/////////////////////////////////////////////////////////////////////////////
// Cstudent 诊断

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


