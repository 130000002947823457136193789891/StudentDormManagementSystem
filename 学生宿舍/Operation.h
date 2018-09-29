#pragma once
#include "afxcmn.h"


// Operation 对话框

class Operation : public CDialogEx
{
	DECLARE_DYNAMIC(Operation)

public:
	Operation(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Operation();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonChange();
};
