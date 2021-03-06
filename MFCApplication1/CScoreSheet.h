#pragma once


// CScoreSheet 대화 상자

class CScoreSheet : public CDialogEx
{
	DECLARE_DYNAMIC(CScoreSheet)

public:
	CScoreSheet(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CScoreSheet();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Name1;
	CStatic m_Score1;
	CStatic m_Name2;
	CStatic m_Score2;
	CStatic m_Name3;
	CStatic m_Score3;
};
