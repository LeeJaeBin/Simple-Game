// CChild.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CChild.h"
#include "afxdialogex.h"


// CChild 대화 상자

IMPLEMENT_DYNAMIC(CChild, CDialogEx)

CChild::CChild(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CChild::~CChild()
{
}

void CChild::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChild, CDialogEx)
END_MESSAGE_MAP()


// CChild 메시지 처리기
