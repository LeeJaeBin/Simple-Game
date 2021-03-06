
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include <ctime>
#include "afxdialogex.h"
#include "Resource.h"
#include "CChild.h"
#include "CScoreSheet.h"
#include <stdlib.h>
#include "CEnterName.h"
#include "CAddPerson.h"
#include "CGameMode.h"
#include "CModeDesc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int x = 10;
int y = 10;

int score = 0;
int High = 0;

CString temp1;
CString temp2;
CString temp3;

BOOL ckResult = FALSE;
BOOL Mode = TRUE;

CString inipath;

CString Name1, Name2, Name3, Name4, Name5, NameArr[5];
int nums = 0;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 대화 상자

CString INIREADString(CString strAppName, CString strKeyName, CString strFilePath) {
	WCHAR szReturnString[1024] = { 0, };
	memset(szReturnString, NULL, 1024);
	GetPrivateProfileString(strAppName, strKeyName, L"", szReturnString, 1024, strFilePath);

	CString str = szReturnString;
	return str;
}

void INIWriteString(CString strAppName, CString strKeyName, CString strValue, CString strFilePath) {
	WritePrivateProfileString(strAppName, strKeyName, strValue, strFilePath);
}

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC1, m_Pic1);
	DDX_Control(pDX, IDC_BAD1, m_Bad1);
	DDX_Control(pDX, IDC_BAD2, m_Bad2);
	DDX_Control(pDX, IDC_BAD3, m_Bad3);
	DDX_Control(pDX, IDC_BAD4, m_Bad4);
	DDX_Control(pDX, IDC_BAD5, m_Bad5);
	DDX_Control(pDX, IDC_BAD6, m_Bad6);
	DDX_Control(pDX, IDC_SCORE, m_Score);
	DDX_Control(pDX, IDC_HIGHSCORE, m_High);
	DDX_Control(pDX, IDC_STATIC_SCORE, m_StaticChanger);
	DDX_Control(pDX, IDC_PLAYERVALUE, m_PlValue);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
//	ON_WM_KEYDOWN()
ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	CButton* button;
	button = (CButton*)GetDlgItem(IDCANCEL);
	button->DestroyWindow();

	button = (CButton*)GetDlgItem(IDOK);
	button->DestroyWindow();

	DWORD nSize = MAX_COMPUTERNAME_LENGTH + 1;
	wchar_t szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	::GetUserName(szBuffer, &nSize);
	CString pathtemp = szBuffer;
	inipath = L"C:\\Users\\" + pathtemp + L"\\Desktop\\Score.ini";
	
	CGameMode gm;
	gm.DoModal();

	CString GameMode;

	GameMode = INIREADString(L"GameMode", L"Mode", inipath);
	if (wcscmp(GameMode, L"0") == 0) {
		Mode = TRUE;
		CModeDesc md;
		md.DoModal();
		CAddPerson ap;
		ap.DoModal();
		CButton* button;
		button = (CButton*)GetDlgItem(IDC_BUTTON2);
		button->DestroyWindow();
		CStatic* st;
		st = (CStatic*)GetDlgItem(IDC_STATIC_HIGH);
		st->DestroyWindow();

		st = (CStatic*)GetDlgItem(IDC_STATIC_SCORE);
		st->DestroyWindow();

		st = (CStatic*)GetDlgItem(IDC_SCORE);
		st->DestroyWindow();

		st = (CStatic*)GetDlgItem(IDC_HIGHSCORE);
		st->DestroyWindow();

		Name1 = INIREADString(L"Mode0Player", L"Name1", inipath);
		Name2 = INIREADString(L"Mode0Player", L"Name2", inipath);
		Name3 = INIREADString(L"Mode0Player", L"Name3", inipath);
		Name4 = INIREADString(L"Mode0Player", L"Name4", inipath);
		Name5 = INIREADString(L"Mode0Player", L"Name5", inipath);

		CString str;
		str = INIREADString(L"Mode0Player", L"Nums", inipath);
		nums = _ttoi(str);

		NameArr[0] = Name1;
		NameArr[1] = Name2;
		NameArr[2] = Name3;
		NameArr[3] = Name4;
		NameArr[4] = Name5;

		m_PlValue.SetWindowTextW(NameArr[0]);
	}
	else {
		Mode = FALSE;
		CChild chld;
		chld.DoModal();

		CEnterName EN;
		EN.DoModal();

		CStatic* st;
		st = (CStatic*)GetDlgItem(IDC_PLAYER);
		st->DestroyWindow();
		st = (CStatic*)GetDlgItem(IDC_PLAYERVALUE);
		st->DestroyWindow();

		RegistName = INIREADString(L"NowPlayer", L"Name", inipath);

		FirstName = INIREADString(L"1", L"Name", inipath);
		SecondName = INIREADString(L"2", L"Name", inipath);
		ThirdName = INIREADString(L"3", L"Name", inipath);

		temp1 = INIREADString(L"1", L"Score", inipath);
		FirstScore = _ttoi(temp1);
		if (temp1.IsEmpty()) {
			High = 0;
			FirstScore = -1;
		}
		else {
			High = FirstScore;
			CString str;
			str.Format(L"%d", High);
			m_High.SetWindowTextW(str + L"pt");
		}

		temp2 = INIREADString(L"2", L"Score", inipath);
		if (temp2.IsEmpty()) {
			SecondScore = -1;
		}
		else {
			SecondScore = _ttoi(temp2);
		}

		temp3 = INIREADString(L"3", L"Score", inipath);
		ThirdScore = _ttoi(temp3);
		if (temp3.IsEmpty()) {
			ThirdScore = -1;
		}
		else {
			ThirdScore = _ttoi(temp3);
		}
	}

	GotoDlgCtrl(GetDlgItem(IDC_BUTTON1));

	return FALSE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int array1[50][2] = { 0 };

int count = 0;
int turn = 0;

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	GetDlgItem(IDC_BUTTON1)->SetWindowText(L"Roll");
	
	if (Mode == TRUE) {

		HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

		m_Pic1.SetBitmap(hBmp);
		CRect rectParent;
		m_Pic1.GetParent()->GetClientRect(rectParent);
		CRect rectControl;
		m_Pic1.GetWindowRect(rectControl);
		m_Pic1.MoveWindow(x, y, rectControl.Width(), rectControl.Height());

		array1[score][0] = x;
		array1[score][1] = y;

		srand(time(0));

		int RandX = rand() % (rectParent.Width() + 1);
		int RandY = rand() % (rectParent.Height() + 1);

		if (score > 0) {
			RandX = array1[score - 1][0];
			RandY = array1[score - 1][1];
		}

		HBITMAP BadBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);
		m_Bad1.SetBitmap(BadBmp);
		m_Bad1.MoveWindow(RandX, RandY, rectControl.Width(), rectControl.Height());

		int RandX2 = rand() % (rectParent.Width() + 1);
		int RandY2 = rand() % (rectParent.Height() + 1);

		m_Bad2.SetBitmap(BadBmp);
		m_Bad2.MoveWindow(RandX2, RandY2, rectControl.Width(), rectControl.Height());

		int RandX3 = rand() % (rectParent.Width() + 1);
		int RandY3 = rand() % (rectParent.Height() + 1);

		m_Bad3.SetBitmap(BadBmp);
		m_Bad3.MoveWindow(RandX3, RandY3, rectControl.Width(), rectControl.Height());

		int RandX4 = rand() % (rectParent.Width() + 1);
		int RandY4 = rand() % (rectParent.Height() + 1);

		m_Bad4.SetBitmap(BadBmp);
		m_Bad4.MoveWindow(RandX4, RandY4, rectControl.Width(), rectControl.Height());

		int RandX5 = rand() % (rectParent.Width() + 1);
		int RandY5 = rand() % (rectParent.Height() + 1);

		m_Bad5.SetBitmap(BadBmp);
		m_Bad5.MoveWindow(RandX5, RandY5, rectControl.Width(), rectControl.Height());

		int RandX6 = rand() % (rectParent.Width() + 1);
		int RandY6 = rand() % (rectParent.Height() + 1);

		m_Bad6.SetBitmap(BadBmp);
		m_Bad6.MoveWindow(RandX6, RandY6, rectControl.Width(), rectControl.Height());

		if (((RandX >= x && RandX <= x + 48 && RandY >= y && RandY <= y + 48) || (RandX + 48 >= x && RandX + 48 <= x + 48 && RandY >= y && RandY <= y + 48) || (RandX + 48 >= x && RandX + 48 <= x + 48 && RandY + 48 >= y && RandY + 48 <= y + 48) || (RandX >= x && RandX <= x + 48 && RandY + 48 >= y && RandY + 48 <= y + 48)) ||
			((RandX2 >= x && RandX2 <= x + 48 && RandY2 >= y && RandY2 <= y + 48) || (RandX2 + 48 >= x && RandX2 + 48 <= x + 48 && RandY2 >= y && RandY2 <= y + 48) || (RandX2 + 48 >= x && RandX2 + 48 <= x + 48 && RandY2 + 48 >= y && RandY2 + 48 <= y + 48) || (RandX2 >= x && RandX2 <= x + 48 && RandY2 + 48 >= y && RandY2 + 48 <= y + 48)) ||
			((RandX3 >= x && RandX3 <= x + 48 && RandY3 >= y && RandY3 <= y + 48) || (RandX3 + 48 >= x && RandX3 + 48 <= x + 48 && RandY3 >= y && RandY3 <= y + 48) || (RandX3 + 48 >= x && RandX3 + 48 <= x + 48 && RandY3 + 48 >= y && RandY3 + 48 <= y + 48) || (RandX3 >= x && RandX3 <= x + 48 && RandY3 + 48 >= y && RandY3 + 48 <= y + 48)) ||
			((RandX4 >= x && RandX4 <= x + 48 && RandY4 >= y && RandY4 <= y + 48) || (RandX4 + 48 >= x && RandX4 + 48 <= x + 48 && RandY4 >= y && RandY4 <= y + 48) || (RandX4 + 48 >= x && RandX4 + 48 <= x + 48 && RandY4 + 48 >= y && RandY4 + 48 <= y + 48) || (RandX4 >= x && RandX4 <= x + 48 && RandY4 + 48 >= y && RandY4 + 48 <= y + 48)) ||
			((RandX5 >= x && RandX5 <= x + 48 && RandY5 >= y && RandY5 <= y + 48) || (RandX5 + 48 >= x && RandX5 + 48 <= x + 48 && RandY5 >= y && RandY5 <= y + 48) || (RandX5 + 48 >= x && RandX5 + 48 <= x + 48 && RandY5 + 48 >= y && RandY5 + 48 <= y + 48) || (RandX5 >= x && RandX5 <= x + 48 && RandY5 + 48 >= y && RandY5 + 48 <= y + 48)) ||
			((RandX6 >= x && RandX6 <= x + 48 && RandY6 >= y && RandY6 <= y + 48) || (RandX6 + 48 >= x && RandX6 + 48 <= x + 48 && RandY6 >= y && RandY6 <= y + 48) || (RandX6 + 48 >= x && RandX6 + 48 <= x + 48 && RandY6 + 48 >= y && RandY6 + 48 <= y + 48) || (RandX6 >= x && RandX6 <= x + 48 && RandY6 + 48 >= y && RandY6 + 48 <= y + 48))) {
			
			AfxMessageBox(NameArr[turn%nums]);
			turn = 0;
			m_PlValue.SetWindowTextW(NameArr[turn]);
			m_Bad1.SetBitmap(BadBmp);
			GetDlgItem(IDC_BUTTON1)->SetWindowText(L"Restart");
		}
		else {
			turn++;
			m_PlValue.SetWindowTextW(NameArr[turn%nums]);
			score++;
		}
	}

	else if (Mode == FALSE) {
		HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

		m_Pic1.SetBitmap(hBmp);
		CRect rectParent;
		m_Pic1.GetParent()->GetClientRect(rectParent);
		CRect rectControl;
		m_Pic1.GetWindowRect(rectControl);
		m_Pic1.MoveWindow(x, y, rectControl.Width(), rectControl.Height());

		array1[score][0] = x;
		array1[score][1] = y;

		srand(time(0));

		int RandX = rand() % (rectParent.Width() + 1);
		int RandY = rand() % (rectParent.Height() + 1);

		if (score > 0) {
			RandX = array1[score - 1][0];
			RandY = array1[score - 1][1];
		}

		HBITMAP BadBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);
		m_Bad1.SetBitmap(BadBmp);
		m_Bad1.MoveWindow(RandX, RandY, rectControl.Width(), rectControl.Height());

		int RandX2 = rand() % (rectParent.Width() + 1);
		int RandY2 = rand() % (rectParent.Height() + 1);

		m_Bad2.SetBitmap(BadBmp);
		m_Bad2.MoveWindow(RandX2, RandY2, rectControl.Width(), rectControl.Height());

		int RandX3 = rand() % (rectParent.Width() + 1);
		int RandY3 = rand() % (rectParent.Height() + 1);

		m_Bad3.SetBitmap(BadBmp);
		m_Bad3.MoveWindow(RandX3, RandY3, rectControl.Width(), rectControl.Height());

		int RandX4 = rand() % (rectParent.Width() + 1);
		int RandY4 = rand() % (rectParent.Height() + 1);

		m_Bad4.SetBitmap(BadBmp);
		m_Bad4.MoveWindow(RandX4, RandY4, rectControl.Width(), rectControl.Height());

		int RandX5 = rand() % (rectParent.Width() + 1);
		int RandY5 = rand() % (rectParent.Height() + 1);

		m_Bad5.SetBitmap(BadBmp);
		m_Bad5.MoveWindow(RandX5, RandY5, rectControl.Width(), rectControl.Height());

		int RandX6 = rand() % (rectParent.Width() + 1);
		int RandY6 = rand() % (rectParent.Height() + 1);

		m_Bad6.SetBitmap(BadBmp);
		m_Bad6.MoveWindow(RandX6, RandY6, rectControl.Width(), rectControl.Height());

		if (((RandX >= x && RandX <= x + 48 && RandY >= y && RandY <= y + 48) || (RandX + 48 >= x && RandX + 48 <= x + 48 && RandY >= y && RandY <= y + 48) || (RandX + 48 >= x && RandX + 48 <= x + 48 && RandY + 48 >= y && RandY + 48 <= y + 48) || (RandX >= x && RandX <= x + 48 && RandY + 48 >= y && RandY + 48 <= y + 48)) ||
			((RandX2 >= x && RandX2 <= x + 48 && RandY2 >= y && RandY2 <= y + 48) || (RandX2 + 48 >= x && RandX2 + 48 <= x + 48 && RandY2 >= y && RandY2 <= y + 48) || (RandX2 + 48 >= x && RandX2 + 48 <= x + 48 && RandY2 + 48 >= y && RandY2 + 48 <= y + 48) || (RandX2 >= x && RandX2 <= x + 48 && RandY2 + 48 >= y && RandY2 + 48 <= y + 48)) ||
			((RandX3 >= x && RandX3 <= x + 48 && RandY3 >= y && RandY3 <= y + 48) || (RandX3 + 48 >= x && RandX3 + 48 <= x + 48 && RandY3 >= y && RandY3 <= y + 48) || (RandX3 + 48 >= x && RandX3 + 48 <= x + 48 && RandY3 + 48 >= y && RandY3 + 48 <= y + 48) || (RandX3 >= x && RandX3 <= x + 48 && RandY3 + 48 >= y && RandY3 + 48 <= y + 48)) ||
			((RandX4 >= x && RandX4 <= x + 48 && RandY4 >= y && RandY4 <= y + 48) || (RandX4 + 48 >= x && RandX4 + 48 <= x + 48 && RandY4 >= y && RandY4 <= y + 48) || (RandX4 + 48 >= x && RandX4 + 48 <= x + 48 && RandY4 + 48 >= y && RandY4 + 48 <= y + 48) || (RandX4 >= x && RandX4 <= x + 48 && RandY4 + 48 >= y && RandY4 + 48 <= y + 48)) ||
			((RandX5 >= x && RandX5 <= x + 48 && RandY5 >= y && RandY5 <= y + 48) || (RandX5 + 48 >= x && RandX5 + 48 <= x + 48 && RandY5 >= y && RandY5 <= y + 48) || (RandX5 + 48 >= x && RandX5 + 48 <= x + 48 && RandY5 + 48 >= y && RandY5 + 48 <= y + 48) || (RandX5 >= x && RandX5 <= x + 48 && RandY5 + 48 >= y && RandY5 + 48 <= y + 48)) ||
			((RandX6 >= x && RandX6 <= x + 48 && RandY6 >= y && RandY6 <= y + 48) || (RandX6 + 48 >= x && RandX6 + 48 <= x + 48 && RandY6 >= y && RandY6 <= y + 48) || (RandX6 + 48 >= x && RandX6 + 48 <= x + 48 && RandY6 + 48 >= y && RandY6 + 48 <= y + 48) || (RandX6 >= x && RandX6 <= x + 48 && RandY6 + 48 >= y && RandY6 + 48 <= y + 48))) {
			AfxMessageBox(L"Over");
			m_Bad1.SetBitmap(BadBmp);

			FirstName = INIREADString(L"1", L"Name", inipath);
			SecondName = INIREADString(L"2", L"Name", inipath);
			ThirdName = INIREADString(L"3", L"Name", inipath);

			temp1 = INIREADString(L"1", L"Score", inipath);
			FirstScore = _ttoi(temp1);
			if (temp1.IsEmpty()) {
				High = 0;
				FirstScore = -1;
			}
			else {
				High = FirstScore;
			}

			temp2 = INIREADString(L"2", L"Score", inipath);
			if (temp2.IsEmpty()) {
				SecondScore = -1;
			}
			else {
				SecondScore = _ttoi(temp2);
			}

			temp3 = INIREADString(L"3", L"Score", inipath);
			ThirdScore = _ttoi(temp3);
			if (temp3.IsEmpty()) {
				ThirdScore = -1;
			}
			else {
				ThirdScore = _ttoi(temp3);
			}

			if (FirstScore == -1) {
				AfxMessageBox(L"Congratulations!! You got High score!");
				CString str;
				str.Format(L"%d", score);
				INIWriteString(L"1", L"Name", RegistName, inipath);
				INIWriteString(L"1", L"Score", str, inipath);
				FirstScore = score;
				FirstName = RegistName;
				ckResult = TRUE;
			}
			else if (FirstScore < score) {
				AfxMessageBox(L"Congratulations!! You got High score!");
				int fstemp = FirstScore;
				CString str;
				str.Format(L"%d", score);
				CString fsntemp = FirstName;
				FirstScore = score;
				FirstName = RegistName;
				INIWriteString(L"1", L"Name", RegistName, inipath);
				INIWriteString(L"1", L"Score", str, inipath);
				int sctemp = SecondScore;
				str.Format(L"%d", fstemp);
				CString scntemp = SecondName;
				SecondScore = fstemp;
				SecondName = fsntemp;
				INIWriteString(L"2", L"Name", fsntemp, inipath);
				INIWriteString(L"2", L"Score", str, inipath);
				ThirdScore = sctemp;
				ThirdName = scntemp;
				str.Format(L"%d", ThirdScore);
				INIWriteString(L"3", L"Name", scntemp, inipath);
				INIWriteString(L"3", L"Score", str, inipath);
				ckResult = TRUE;
			}
			else if (SecondScore == -1) {
				CString temp;
				temp = L"Congratulations " + RegistName + L"! You deserve to be in Top 3";
				AfxMessageBox(temp);
				CString str;
				str.Format(L"%d", score);
				INIWriteString(L"2", L"Name", RegistName, inipath);
				INIWriteString(L"2", L"Score", str, inipath);
				SecondScore = score;
				SecondName = RegistName;
				ckResult = TRUE;
			}
			else if (SecondScore < score) {
				CString temp;
				temp = L"Congratulations " + RegistName + L"! You deserve to be in Top 3";
				AfxMessageBox(temp);
				CString str;
				int sctemp = SecondScore;
				CString scntemp = SecondName;
				SecondScore = score;
				str.Format(L"%d", SecondScore);
				SecondName = RegistName;
				INIWriteString(L"2", L"Name", RegistName, inipath);
				INIWriteString(L"2", L"Score", str, inipath);
				ThirdScore = sctemp;
				str.Format(L"%d", ThirdScore);
				ThirdName = scntemp;
				INIWriteString(L"3", L"Name", ThirdName, inipath);
				INIWriteString(L"3", L"Score", str, inipath);
				ckResult = TRUE;
			}
			else if (ThirdScore == -1) {
				CString temp;
				temp = L"Congratulations " + RegistName + L"! You deserve to be in Top 3";
				AfxMessageBox(temp);
				CString str;
				ThirdScore = score;
				str.Format(L"%d", ThirdScore);
				ThirdName = RegistName;
				INIWriteString(L"3", L"Name", ThirdName, inipath);
				INIWriteString(L"3", L"Score", str, inipath);
				ckResult = TRUE;
			}
			else if (ThirdScore < score) {
				CString temp;
				temp = L"Congratz " + RegistName + L"! You deserve to be in Top 3";
				AfxMessageBox(temp);
				CString str;
				ThirdScore = score;
				str.Format(L"%d", ThirdScore);
				ThirdName = RegistName;
				INIWriteString(L"3", L"Name", ThirdName, inipath);
				INIWriteString(L"3", L"Score", str, inipath);
				ckResult = TRUE;
			}
			else {
				CString str;
				str = RegistName + L", you have not even been in third place..";
				AfxMessageBox(str);
			}
			if (ckResult == TRUE) {
				CScoreSheet ss;
				ss.DoModal();
			}
			ckResult = FALSE;
			score = 0;
			GetDlgItem(IDC_BUTTON1)->SetWindowText(L"Restart");
		}
		else {
			score++;
		}

		CString str, Hstr;
		str.Format(L"%d", score);
		m_Score.SetWindowTextW(str + L"pt");

		if (High < score) {
			High = score;
			Hstr.Format(L"%d", High);
			m_High.SetWindowTextW(Hstr + L"pt");
		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_Pic1.SetBitmap(hBmp);
	CRect rectParent;
	m_Pic1.GetParent()->GetClientRect(rectParent);
	CRect rectControl;
	m_Pic1.GetWindowRect(rectControl);

	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_DOWN) {
			y += 5;
			if (y >= rectParent.Height()) {
				y -= 5;
			}
		}
		else if (pMsg->wParam == VK_UP) {
			y -= 5;
			if (y <= 0) {
				y += 5;
			}
		}
		else if (pMsg->wParam == VK_LEFT) {
			x -= 5;
			if (x <= 0) {
				x += 5;
			}
		}
		else if (pMsg->wParam == VK_RIGHT) {
			x += 5;
			if (x >= rectParent.Width()) {
				x -= 5;
			}
		}
	}

	m_Pic1.MoveWindow(x, y, rectControl.Width(), rectControl.Height());
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	CScoreSheet ss;
	ss.DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
