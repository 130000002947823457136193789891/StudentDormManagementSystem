#pragma once


// AddDlg 对话框

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~AddDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	bool m_bMale;
	afx_msg void OnRadioMale();
	afx_msg void OnRadioFemale();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CString m_strID;
	CString m_strStudentName;
};
