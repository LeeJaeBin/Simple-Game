#pragma once


// CAddPerson 대화 상자

class CAddPerson : public CDialogEx
{
	DECLARE_DYNAMIC(CAddPerson)

public:
	CAddPerson(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CAddPerson();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Person1;
	CEdit m_Person2;
	CEdit m_Person3;
	CEdit m_Person4;
	CEdit m_Person5;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
