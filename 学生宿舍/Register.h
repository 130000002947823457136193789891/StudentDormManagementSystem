#pragma once
#include "afxwin.h"


// CRegister 对话框

class CRegister : public CDialogEx
{
	DECLARE_DYNAMIC(CRegister)

public:
	CRegister(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRegister();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_newPassword;
	CString m_strNewPassword;
	CString m_strPassword0;
	CString m_strUsername;
	CButton m_bnOK;
	CButton m_bnCancel;
	afx_msg void OnBnClickedOk();
};
