#pragma once


// trueChange 对话框

class trueChange : public CDialogEx
{
	DECLARE_DYNAMIC(trueChange)

public:
	trueChange(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~trueChange();

// 对话框数据
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	bool m_bMale;
	afx_msg void OnBnClickedMale();
	afx_msg void OnBnClickedFemale();
	virtual BOOL OnInitDialog();
	CString m_strID;
	CString m_strStudentName;
};
