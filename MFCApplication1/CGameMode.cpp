// CGameMode.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CGameMode.h"
#include "afxdialogex.h"


// CGameMode 대화 상자

IMPLEMENT_DYNAMIC(CGameMode, CDialogEx)

CGameMode::CGameMode(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CGameMode::~CGameMode()
{
}

void CGameMode::DoDataExchange(CDataExchange* pDX)
{
	CButton* button;
	button = (CButton*)GetDlgItem(IDCANCEL);
	button->DestroyWindow();

	button = (CButton*)GetDlgItem(IDOK);
	button->DestroyWindow();

	GotoDlgCtrl(GetDlgItem(IDC_BUTTON1));

	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGameMode, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGameMode::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CGameMode::OnBnClickedButton2)
END_MESSAGE_MAP()


// CGameMode 메시지 처리기


void CGameMode::OnBnClickedButton1()
{
	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	::GetUserName(szBuffer, &nSize);
	CString pathtemp = szBuffer;
	CString inipath = L"C:\\Users\\" + pathtemp + L"\\Desktop\\Score.ini";

	WritePrivateProfileString(L"GameMode", L"Mode", L"0", inipath);
	::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CGameMode::OnBnClickedButton2()
{
	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	::GetUserName(szBuffer, &nSize);
	CString pathtemp = szBuffer;
	CString inipath = L"C:\\Users\\" + pathtemp + L"\\Desktop\\Score.ini";

	WritePrivateProfileString(L"GameMode", L"Mode", L"1", inipath);
	::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
