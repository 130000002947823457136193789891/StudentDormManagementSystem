#pragma once


// trueChange �Ի���

class trueChange : public CDialogEx
{
	DECLARE_DYNAMIC(trueChange)

public:
	trueChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~trueChange();

// �Ի�������
	enum { IDD = IDD_DIALOG5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	bool m_bMale;
	afx_msg void OnBnClickedMale();
	afx_msg void OnBnClickedFemale();
	virtual BOOL OnInitDialog();
	CString m_strID;
	CString m_strStudentName;
};
