// CScoreSheet.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CScoreSheet.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"


// CScoreSheet 대화 상자

IMPLEMENT_DYNAMIC(CScoreSheet, CDialogEx)

CScoreSheet::CScoreSheet(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
}

CScoreSheet::~CScoreSheet()
{
}

CString INIREADString2(CString strAppName, CString strKeyName, CString strFilePath) {
	WCHAR szReturnString[1024] = { 0, };
	memset(szReturnString, NULL, 1024);
	GetPrivateProfileString(strAppName, strKeyName, L"", szReturnString, 1024, strFilePath);

	CString str = szReturnString;
	return str;
}

void CScoreSheet::DoDataExchange(CDataExchange* pDX)
{

	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	::GetUserName(szBuffer, &nSize);
	CString pathtemp = szBuffer;
	CString inipath = L"C:\\Users\\" + pathtemp + L"\\Desktop\\Score.ini";

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME1, m_Name1);
	DDX_Control(pDX, IDC_SCORE1, m_Score1);
	DDX_Control(pDX, IDC_NAME2, m_Name2);
	DDX_Control(pDX, IDC_SCORE2, m_Score2);
	DDX_Control(pDX, IDC_NAME3, m_Name3);
	DDX_Control(pDX, IDC_SCORE3, m_Score3);

	CString FirstName;
	CString SecondName;
	CString ThirdName;
	int FirstScore;
	int SecondScore;
	int ThirdScore;
	CString temp1;
	CString temp2;
	CString temp3;

	FirstName = INIREADString2(L"1", L"Name", inipath);
	SecondName = INIREADString2(L"2", L"Name", inipath);
	ThirdName = INIREADString2(L"3", L"Name", inipath);

	temp1 = INIREADString2(L"1", L"Score", inipath);
	if (temp1.IsEmpty()) {
		FirstScore = -1;
	}
	else {
		FirstScore = _ttoi(temp1);
	}

	temp2 = INIREADString2(L"2", L"Score", inipath);
	if (temp2.IsEmpty()) {
		SecondScore = -1;
	}
	else {
		SecondScore = _ttoi(temp2);
	}

	temp3 = INIREADString2(L"3", L"Score", inipath);
	ThirdScore = _ttoi(temp3);
	if (temp3.IsEmpty()) {
		ThirdScore = -1;
	}
	else {
		ThirdScore = _ttoi(temp3);
	}
	
	////////////////////////////////////////////////////////////////////////////////////////////////////
	
	if (!FirstName.IsEmpty()) {
		m_Name1.SetWindowTextW(FirstName);
	}

	if (!SecondName.IsEmpty()) {
		m_Name2.SetWindowTextW(SecondName);
	}
	if (!ThirdName.IsEmpty()) {
		m_Name3.SetWindowTextW(ThirdName);
	}
	if (FirstScore != -1) {
		CString str;
		str.Format(L"%d", FirstScore);
		m_Score1.SetWindowTextW(str + L"pt");
	}
	if (SecondScore != -1) {
		CString str;
		str.Format(L"%d", SecondScore);
		m_Score2.SetWindowTextW(str + L"pt");
	}
	if (ThirdScore != -1) {
		CString str;
		str.Format(L"%d", ThirdScore);
		m_Score3.SetWindowTextW(str + L"pt");
	}
}


BEGIN_MESSAGE_MAP(CScoreSheet, CDialogEx)
END_MESSAGE_MAP()


// CScoreSheet 메시지 처리기
