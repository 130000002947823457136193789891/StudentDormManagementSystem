// account.h : Caccount 类的实现



// Caccount 实现

// 代码生成在 2018年7月14日, 15:33

#include "stdafx.h"
#include "account.h"
IMPLEMENT_DYNAMIC(Caccount, CRecordset)

Caccount::Caccount(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_account = "";
	m_password = "";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Caccount::GetDefaultConnect()
{
	return _T("DSN=studentsys;SERVER=localhost;UID=root;PWD=13508459029;DATABASE=stuinfo;PORT=3306");
}

CString Caccount::GetDefaultSQL()
{
	return _T("[account]");
}

void Caccount::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[account]"), m_account);
	RFX_Text(pFX, _T("[password]"), m_password);

}
/////////////////////////////////////////////////////////////////////////////
// Caccount 诊断

#ifdef _DEBUG
void Caccount::AssertValid() const
{
	CRecordset::AssertValid();
}

void Caccount::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


