// CModeDesc.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "CModeDesc.h"
#include "afxdialogex.h"


// CModeDesc 대화 상자

IMPLEMENT_DYNAMIC(CModeDesc, CDialogEx)

CModeDesc::CModeDesc(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CModeDesc::~CModeDesc()
{
}

void CModeDesc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModeDesc, CDialogEx)
END_MESSAGE_MAP()


// CModeDesc 메시지 처리기
