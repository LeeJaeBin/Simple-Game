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
	CButton* button;
	button = (CButton*)GetDlgItem(IDCANCEL);
	button->DestroyWindow();

	button = (CButton*)GetDlgItem(IDOK);
	button->DestroyWindow();

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EnterName);
}


BEGIN_MESSAGE_MAP(CEnterName, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CEnterName::OnBnClickedButton1)
END_MESSAGE_MAP()


// CEnterName 메시지 처리기


void CEnterName::OnBnClickedButton1()
{
	CString Name;
	GetDlgItemText(IDC_EDITNAME, Name);
	WritePrivateProfileString(L"NowPlayer", L"Name", Name, L"C:\\Users\\TERUTEN\\Desktop\\Score.ini");

	::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
