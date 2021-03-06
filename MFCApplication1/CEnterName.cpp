// CEnterName.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CEnterName.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"


// CEnterName 대화 상자

IMPLEMENT_DYNAMIC(CEnterName, CDialogEx)

CEnterName::CEnterName(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CEnterName::~CEnterName()
{
}

void CEnterName::DoDataExchange(CDataExchange* pDX)
{


	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EnterName);
}


BEGIN_MESSAGE_MAP(CEnterName, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CEnterName::OnBnClickedButton1)
END_MESSAGE_MAP()


// CEnterName 메시지 처리기


void CEnterName::OnBnClickedButton1()
{
	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	::GetUserName(szBuffer, &nSize);
	CString pathtemp = szBuffer;
	CString inipath = L"C:\\Users\\" + pathtemp + L"\\Desktop\\Score.ini";

	CString Name;
	GetDlgItemText(IDC_EDITNAME, Name);

	int len = wcslen(Name);
	if (len > 6) {
		AfxMessageBox(L"Name too long!");
	}
	else {
		WritePrivateProfileString(L"NowPlayer", L"Name", Name, inipath);

		::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CEnterName::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CButton* button;
	button = (CButton*)GetDlgItem(IDCANCEL);
	button->DestroyWindow();

	button = (CButton*)GetDlgItem(IDOK);
	button->DestroyWindow();

	GotoDlgCtrl(GetDlgItem(IDC_BUTTON1));
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
