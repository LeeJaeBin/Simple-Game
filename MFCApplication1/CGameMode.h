#pragma once


// CGameMode 대화 상자

class CGameMode : public CDialogEx
{
	DECLARE_DYNAMIC(CGameMode)

public:
	CGameMode(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CGameMode();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
