// CAddPerson.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CAddPerson.h"
#include "afxdialogex.h"
#include "resource.h"


// CAddPerson 대화 상자

IMPLEMENT_DYNAMIC(CAddPerson, CDialogEx)

CAddPerson::CAddPerson(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

CAddPerson::~CAddPerson()
{
}

void CAddPerson::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PERSON1, m_Person1);
	DDX_Control(pDX, IDC_PERSON2, m_Person2);
	DDX_Control(pDX, IDC_PERSON3, m_Person3);
	DDX_Control(pDX, IDC_PERSON4, m_Person4);
	DDX_Control(pDX, IDC_PERSON5, m_Person5);
}


BEGIN_MESSAGE_MAP(CAddPerson, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAddPerson::OnBnClickedButton1)
END_MESSAGE_MAP()


// CAddPerson 메시지 처리기


void CAddPerson::OnBnClickedButton1()
{
	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	::GetUserName(szBuffer, &nSize);
	CString pathtemp = szBuffer;
	CString inipath = L"C:\\Users\\" + pathtemp + L"\\Desktop\\Score.ini";

	int nums = 0;
	CString Name1, Name2, Name3, Name4, Name5;
	GetDlgItemText(IDC_PERSON1, Name1);
	GetDlgItemText(IDC_PERSON2, Name2);
	GetDlgItemText(IDC_PERSON3, Name3);
	GetDlgItemText(IDC_PERSON4, Name4);
	GetDlgItemText(IDC_PERSON5, Name5);

	if (Name1.IsEmpty()) {
		nums = 0;
	}
	else if (Name2.IsEmpty()) {
		nums = 1;
	}
	else if (Name3.IsEmpty()) {
		nums = 2;
	}
	else if (Name4.IsEmpty()) {
		nums = 3;
	}
	else if (Name5.IsEmpty()) {
		nums = 4;
	}
	else {
		nums = 5;
	}
	CString str;
	str.Format(L"%d", nums);
	BOOL NameCk = TRUE;
	WritePrivateProfileString(L"Mode0Player", L"Nums", str, inipath);

	if (Name2.IsEmpty()) {
		NameCk = FALSE;
		AfxMessageBox(L"Please enter more than one name");
	}
	else {
		NameCk = TRUE;
	}

	if(!Name1.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name1", Name1, inipath);
	if (!Name2.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name2", Name2, inipath);
	if (!Name3.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name3", Name3, inipath);
	if (!Name4.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name4", Name4, inipath);
	if (!Name5.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name5", Name5, inipath);

	if(NameCk == TRUE)
		::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


BOOL CAddPerson::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	CButton* button;
	button = (CButton*)GetDlgItem(IDCANCEL);
	button->DestroyWindow();

	button = (CButton*)GetDlgItem(IDOK);
	button->DestroyWindow();

	GotoDlgCtrl(GetDlgItem(IDC_BUTTON1));

	return FALSE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
