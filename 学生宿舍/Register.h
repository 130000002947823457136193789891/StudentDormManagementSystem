#pragma once
#include "afxwin.h"


// CRegister �Ի���

class CRegister : public CDialogEx
{
	DECLARE_DYNAMIC(CRegister)

public:
	CRegister(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRegister();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
