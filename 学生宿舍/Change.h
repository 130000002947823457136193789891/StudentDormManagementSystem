#pragma once


// CChange �Ի���

class CChange : public CDialogEx
{
	DECLARE_DYNAMIC(CChange)

public:
	CChange(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChange();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_old;
	CString m_SureNew;
	CString m_user;
	afx_msg void OnBnClickedOk();
	CString m_strConfirm;
};
