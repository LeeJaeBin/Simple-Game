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
	CButton* button;
	button = (CButton*)GetDlgItem(IDCANCEL);
	button->DestroyWindow();

	button = (CButton*)GetDlgItem(IDOK);
	button->DestroyWindow();

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
	WritePrivateProfileString(L"Mode0Player", L"Nums", str, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");

	if (Name2.IsEmpty()) {
		NameCk = FALSE;
		AfxMessageBox(L"Please enter more than one name");
	}
	else {
		NameCk = TRUE;
	}

	if(!Name1.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name1", Name1, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");
	if (!Name2.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name2", Name2, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");
	if (!Name3.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name3", Name3, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");
	if (!Name4.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name4", Name4, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");
	if (!Name5.IsEmpty())
		WritePrivateProfileString(L"Mode0Player", L"Name5", Name5, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");

	if(NameCk == TRUE)
		::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
