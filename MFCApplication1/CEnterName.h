#pragma once


// CEnterName 대화 상자

class CEnterName : public CDialogEx
{
	DECLARE_DYNAMIC(CEnterName)

public:
	CEnterName(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEnterName();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EnterName;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
};
