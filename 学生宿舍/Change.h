#pragma once


// CChange 对话框

class CChange : public CDialogEx
{
	DECLARE_DYNAMIC(CChange)

public:
	CChange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChange();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_old;
	CString m_SureNew;
	CString m_user;
	afx_msg void OnBnClickedOk();
	CString m_strConfirm;
};
