#pragma once


// AddDlg �Ի���

class AddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddDlg)

public:
	AddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~AddDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
