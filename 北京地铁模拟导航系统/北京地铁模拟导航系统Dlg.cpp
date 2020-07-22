// ��������ģ�⵼��ϵͳDlg.cpp : implementation file
//By:������
//From:�����Ƽ���ѧ
#include <iostream>
using namespace std;
#include "stdafx.h"
#include "��������ģ�⵼��ϵͳ.h"
#include "��������ģ�⵼��ϵͳDlg.h"
const int max = 100;
const int oo = 999;
int i,j,v,x;
void SearchPath(int *Prev,int v, int u);
void Dijkstra(int n, int v, int *Min, int *Prev, int Dist[max][max]);
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	qidian = _T("");
	zhongdian = _T("");
	y = 0;
	LuJing = _T("");
	z = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, qidian);
	DDX_Text(pDX, IDC_EDIT2, zhongdian);
	DDX_Text(pDX, IDC_EDIT3, y);
	DDX_Text(pDX, IDC_EDIT4, LuJing);
	DDX_Text(pDX, IDC_EDIT5, z);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	ON_BN_CLICKED(IDC_BUTTON21, OnButton21)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON24, OnButton24)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON30, OnButton30)
	ON_BN_CLICKED(IDC_BUTTON31, OnButton31)
	ON_BN_CLICKED(IDC_BUTTON32, OnButton32)
	ON_BN_CLICKED(IDC_BUTTON33, OnButton33)
	ON_BN_CLICKED(IDC_BUTTON34, OnButton34)
	ON_BN_CLICKED(IDC_BUTTON35, OnButton35)
	ON_BN_CLICKED(IDC_BUTTON36, OnButton36)
	ON_BN_CLICKED(IDC_BUTTON37, OnButton37)
	ON_BN_CLICKED(IDC_BUTTON38, OnButton38)
	ON_BN_CLICKED(IDC_BUTTON39, OnButton39)
	ON_BN_CLICKED(IDC_BUTTON40, OnButton40)
	ON_BN_CLICKED(IDC_BUTTON41, OnButton41)
	ON_BN_CLICKED(IDC_BUTTON42, OnButton42)
	ON_BN_CLICKED(IDC_BUTTON43, OnButton43)
	ON_BN_CLICKED(IDC_BUTTON44, OnButton44)
	ON_BN_CLICKED(IDC_BUTTON45, OnButton45)
	ON_BN_CLICKED(IDC_BUTTON46, OnButton46)
	ON_BN_CLICKED(IDC_BUTTON47, OnButton47)
	ON_BN_CLICKED(IDC_BUTTON48, OnButton48)
	ON_BN_CLICKED(IDC_BUTTON49, OnButton49)
	ON_BN_CLICKED(IDC_BUTTON50, OnButton50)
	ON_BN_CLICKED(IDC_BUTTON51, OnButton51)
	ON_BN_CLICKED(IDC_BUTTON52, OnButton52)
	ON_BN_CLICKED(IDC_BUTTON53, OnButton53)
	ON_BN_CLICKED(IDC_BUTTON54, OnButton54)
	ON_BN_CLICKED(IDC_BUTTON55, OnButton55)
	ON_BN_CLICKED(IDC_BUTTON56, OnButton56)
	ON_BN_CLICKED(IDC_BUTTON57, OnButton57)
	ON_BN_CLICKED(IDC_BUTTON58, OnButton58)
	ON_BN_CLICKED(IDC_BUTTON59, OnButton59)
	ON_BN_CLICKED(IDC_BUTTON60, OnButton60)
	ON_BN_CLICKED(IDC_BUTTON61, OnButton61)
	ON_BN_CLICKED(IDC_BUTTON62, OnButton62)
	ON_BN_CLICKED(IDC_BUTTON63, OnButton63)
	ON_BN_CLICKED(IDC_BUTTON64, OnButton64)
	ON_BN_CLICKED(IDC_BUTTON65, OnButton65)
	ON_BN_CLICKED(IDC_BUTTON66, OnButton66)
	ON_BN_CLICKED(IDC_BUTTON67, OnButton67)
	ON_BN_CLICKED(IDC_BUTTON68, OnButton68)
	ON_BN_CLICKED(IDC_BUTTON69, OnButton69)
	ON_BN_CLICKED(IDC_BUTTON70, OnButton70)
	ON_BN_CLICKED(IDC_BUTTON71, OnButton71)
	ON_BN_CLICKED(IDC_BUTTON72, OnButton72)
	ON_BN_CLICKED(IDC_BUTTON73, OnButton73)
	ON_BN_CLICKED(IDC_BUTTON74, OnButton74)
	ON_BN_CLICKED(IDC_BUTTON75, OnButton75)
	ON_BN_CLICKED(IDC_BUTTON76, OnButton76)
	ON_BN_CLICKED(IDC_BUTTON77, OnButton77)
	ON_BN_CLICKED(IDC_BUTTON78, OnButton78)
	ON_BN_CLICKED(IDC_BUTTON79, OnButton79)
	ON_BN_CLICKED(IDC_BUTTON80, OnButton80)
	ON_BN_CLICKED(IDC_BUTTON81, OnButton81)
	ON_BN_CLICKED(IDC_BUTTON82, OnButton82)
	ON_BN_CLICKED(IDC_BUTTON83, OnButton83)
	ON_BN_CLICKED(IDC_BUTTON84, OnButton84)
	ON_BN_CLICKED(IDC_BUTTON85, OnButton85)
	ON_BN_CLICKED(IDC_BUTTON86, OnButton86)
	ON_BN_CLICKED(IDC_BUTTON87, OnButton87)
	ON_BN_CLICKED(IDC_BUTTON88, OnButton88)
	ON_BN_CLICKED(IDC_BUTTON89, OnButton89)
	ON_BN_CLICKED(IDC_BUTTON90, OnButton90)
	ON_BN_CLICKED(IDC_BUTTON91, OnButton91)
	ON_BN_CLICKED(IDC_BUTTON92, OnButton92)
	ON_BN_CLICKED(IDC_BUTTON93, OnButton93)
	ON_BN_CLICKED(IDC_BUTTON94, OnButton94)
	ON_BN_CLICKED(IDC_BUTTON95, OnButton95)
	ON_BN_CLICKED(IDC_BUTTON96, OnButton96)
	ON_BN_CLICKED(IDC_BUTTON97, OnButton97)
	ON_BN_CLICKED(IDC_BUTTON98, OnButton98)
	ON_BN_CLICKED(IDC_BUTTON99, OnButton99)
	ON_BN_CLICKED(IDC_BUTTON100, OnButton100)
	ON_BN_CLICKED(IDC_BUTTON101, OnButton101)
	ON_BN_CLICKED(IDC_BUTTON102, OnButton102)
	ON_BN_CLICKED(IDC_BUTTON103, OnButton103)
	ON_BN_CLICKED(IDC_BUTTON104, OnButton104)
	ON_BN_CLICKED(IDC_BUTTON105, OnButton105)
	ON_BN_CLICKED(IDC_BUTTON106, OnButton106)
	ON_BN_CLICKED(IDC_BUTTON107, OnButton107)
	ON_BN_CLICKED(IDC_BUTTON108, OnButton108)
	ON_BN_CLICKED(IDC_BUTTON109, OnButton109)
	ON_BN_CLICKED(IDC_BUTTON110, OnButton110)
	ON_BN_CLICKED(IDC_BUTTON111, OnButton111)
	ON_BN_CLICKED(IDC_BUTTON112, OnButton112)
	ON_BN_CLICKED(IDC_BUTTON113, OnButton113)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int Min[max];     // ��ǰ�㵽�������·������
    int Prev[max];     // ��ǰ���ǰһ��
    int Dist[max][max];
	int n=99;             // վ����������������������������������������������������������������
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            Dist[i][j] = oo;
    Dist[1][2]=1;Dist[1][20]=1;Dist[1][27]=1;Dist[1][28]=1;Dist[1][30]=1;
	Dist[2][1]=1;Dist[2][3]=1;
	Dist[3][2]=1;Dist[3][4]=1;Dist[3][21]=1;Dist[3][31]=1;
	Dist[4][3]=1;Dist[4][5]=1;
	Dist[5][4]=1;Dist[5][6]=1;
	Dist[6][5]=1;Dist[6][7]=1;
	Dist[7][6]=1;Dist[7][8]=1;
	Dist[8][7]=1;Dist[8][9]=1;
	Dist[9][8]=1;Dist[9][10]=1;
	Dist[10][9]=1;Dist[10][11]=1;Dist[10][43]=1;
	Dist[11][10]=1;Dist[11][12]=1;
	Dist[12][11]=1;Dist[12][13]=1;Dist[12][46]=1;
	Dist[13][12]=1;Dist[13][14]=1;
	Dist[14][13]=1;Dist[14][15]=1;
	Dist[15][14]=1;Dist[15][16]=1;
	Dist[16][15]=1;Dist[16][17]=1;
	Dist[17][16]=1;Dist[17][18]=1;Dist[17][50]=1;
	Dist[18][17]=1;Dist[18][19]=1;
	Dist[19][18]=1;Dist[19][20]=1;Dist[19][48]=1;Dist[19][51]=1;
	Dist[20][19]=1;Dist[20][1]=1;
	Dist[21][3]=1;Dist[21][22]=1;
	Dist[22][21]=1;Dist[22][23]=1;
	Dist[23][22]=1;Dist[23][24]=1;Dist[23][56]=1;
	Dist[24][23]=1;Dist[24][56]=1;
	Dist[25][22]=1;Dist[25][26]=1;
	Dist[26][25]=1;Dist[26][51]=1;
	Dist[27][1]=1;Dist[27][54]=1;
	Dist[28][1]=1;Dist[28][29]=1;
	Dist[29][28]=1;Dist[29][53]=1;
	Dist[30][1]=1;Dist[30][29]=1;
	Dist[31][3]=1;Dist[31][32]=1;
	Dist[32][31]=1;Dist[32][55]=1;
	Dist[33][55]=1;Dist[33][34]=1;Dist[33][36]=1;
	Dist[34][33]=1;Dist[34][35]=1;
	Dist[35][34]=1;Dist[35][42]=1;Dist[35][49]=1;
	Dist[36][33]=1;Dist[36][37]=1;
	Dist[37][36]=1;Dist[37][38]=1;Dist[37][40]=1;
	Dist[38][37]=1;Dist[38][39]=1;
	Dist[39][38]=1;Dist[39][45]=1;
	Dist[40][37]=1;Dist[40][41]=1;
	Dist[41][40]=1;Dist[41][42]=1;Dist[41][44]=1;Dist[41][46]=1;
	Dist[42][41]=1;Dist[42][35]=1;
	Dist[43][10]=1;Dist[43][44]=1;
	Dist[44][43]=1;Dist[44][41]=1;
	Dist[45][39]=1;
	Dist[46][41]=1;Dist[46][12]=1;
	Dist[47][33]=1;Dist[47][48]=1;
	Dist[48][47]=1;Dist[48][19]=1;
	Dist[49][35]=1;Dist[49][50]=1;
	Dist[50][49]=1;Dist[50][17]=1;
	Dist[51][19]=1;Dist[51][52]=1;
	Dist[52][51]=1;Dist[52][53]=1;
	Dist[53][52]=1;Dist[53][29]=1;
	Dist[54][26]=1;Dist[54][27]=1;
	Dist[55][32]=1;Dist[55][34]=1;
	Dist[56][23]=1;Dist[55][24]=1;

    Dijkstra(n, v, Min, Prev, Dist);

    y=Min[x];
	if(y<6)//�Ƽ۴��룬zΪ�۸�
		z=3;
	else if(y>=6&&y<=10)
		z=4;
	else if(y>10)
		z=y-6;

    int Dire[max];
    int num = 1;
    Dire[num] = x;
    num=++num;
    int t = Prev[x];
    while(t != v)
    {
        Dire[num] = t;
        num=++num;
        t = Prev[t];
    }
    Dire[num] = v;

	CString str[max];
	LuJing=str[0];
    for(i=num; i>=1; --i)
	{
		if(Dire[i]==1)
		str[i].Format("��ֱ�� �� ",Dire[i]);  //������������ӵ��ַ���
		if(Dire[i]==2)
		str[i].Format("������ �� ",Dire[i]);  
		if(Dire[i]==3)
		str[i].Format("֪��· �� ",Dire[i]);  
		if(Dire[i]==4)
		str[i].Format("����� �� ",Dire[i]);  
		if(Dire[i]==5)
		str[i].Format("�ϵ� �� ",Dire[i]);  
		if(Dire[i]==6)
		str[i].Format("������ �� ",Dire[i]);  
		if(Dire[i]==7)
		str[i].Format("���� �� ",Dire[i]);  
		if(Dire[i]==8)
		str[i].Format("������ �� ",Dire[i]);  
		if(Dire[i]==9)
		str[i].Format("��Ӫ �� ",Dire[i]); 
		if(Dire[i]==10)
		str[i].Format("��ˮ�� �� ",Dire[i]); 
		if(Dire[i]==11)
		str[i].Format("��Է �� ",Dire[i]); 
		if(Dire[i]==12)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==13)
		str[i].Format("��ҩ�� �� ",Dire[i]); 
		if(Dire[i]==14)
		str[i].Format("������ �� ",Dire[i]); 
		if(Dire[i]==15)
		str[i].Format("���� �� ",Dire[i]); 
		if(Dire[i]==16)
		str[i].Format("��ֱ�� �� ",Dire[i]);
		if(Dire[i]==17)
		str[i].Format("Ӻ�͹� �� ",Dire[i]);
		if(Dire[i]==18)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==19)
		str[i].Format("��¥��� �� ",Dire[i]);
		if(Dire[i]==20)
		str[i].Format("��ˮ̶ �� ",Dire[i]);
		if(Dire[i]==21)
		str[i].Format("֪���� �� ",Dire[i]);
		if(Dire[i]==22)
		str[i].Format("�����ׯ �� ",Dire[i]);
		if(Dire[i]==23)
		str[i].Format("�йش� �� ",Dire[i]);
		if(Dire[i]==24)
		str[i].Format("Բ��԰ �� ",Dire[i]);
		if(Dire[i]==25)
		str[i].Format("�����ѧ �� ",Dire[i]);
		if(Dire[i]==26)
		str[i].Format("κ���� �� ",Dire[i]);
		if(Dire[i]==27)
		str[i].Format("����԰ �� ",Dire[i]);
		if(Dire[i]==28)
		str[i].Format("�½ֿ� �� ",Dire[i]);
		if(Dire[i]==29)
		str[i].Format("ƽ���� �� ",Dire[i]);
		if(Dire[i]==30)
		str[i].Format("����ׯ �� ",Dire[i]);
		if(Dire[i]==31)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==32)
		str[i].Format("ĵ��԰ �� ",Dire[i]);
		if(Dire[i]==33)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==34)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==35)
		str[i].Format("���������Ͽ� �� ",Dire[i]);
		if(Dire[i]==36)
		str[i].Format("�������� �� ",Dire[i]);
		if(Dire[i]==37)
		str[i].Format("����ƥ�˹�԰ �� ",Dire[i]);
		if(Dire[i]==38)
		str[i].Format("��ɳ̲ �� ",Dire[i]);
		if(Dire[i]==39)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==40)
		str[i].Format("����· �� ",Dire[i]);
		if(Dire[i]==41)
		str[i].Format("����·�� �� ",Dire[i]);
		if(Dire[i]==42)
		str[i].Format("�������ֱ��� �� ",Dire[i]);
		if(Dire[i]==43)
		str[i].Format("��ˮ���� �� ",Dire[i]);
		if(Dire[i]==44)
		str[i].Format("��Է·�� �� ",Dire[i]);
		if(Dire[i]==45)
		str[i].Format("�廪��·���� �� ",Dire[i]);
		if(Dire[i]==46)
		str[i].Format("��ׯ �� ",Dire[i]);
		if(Dire[i]==47)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==48)
		str[i].Format("�����ﱱ�� �� ",Dire[i]);
		if(Dire[i]==49)
		str[i].Format("��ƽ���� �� ",Dire[i]);
		if(Dire[i]==50)
		str[i].Format("��ƽ�ﱱ�� �� ",Dire[i]);
		if(Dire[i]==51)
		str[i].Format("ʲɲ�� �� ",Dire[i]);
		if(Dire[i]==52)
		str[i].Format("������� �� ",Dire[i]);
		if(Dire[i]==53)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==54)
		str[i].Format("����ͼ��� �� ",Dire[i]);
		if(Dire[i]==55)
		str[i].Format("������ �� ",Dire[i]);
		if(Dire[i]==56)
		str[i].Format("������ѧ���� �� ",Dire[i]);
		LuJing+=str[i];


	}
	UpdateData(FALSE);
}

void CMyDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnChangeEdit3() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnChangeEdit4() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
}

void Dijkstra(int n, int v, int *Min, int *Prev, int Dist[max][max])
{
    bool List[max];    // �ж��Ƿ��Ѵ���õ㵽S������
    for(i=1; i<=n; ++i)
    {
        Min[i] = Dist[v][i];
        List[i] = 0;     // ��ʼ��δ�ù��õ�
        if(Min[i] == oo)
            Prev[i] = 0;
        else
            Prev[i] = v;
    }
    Min[v] = 0;
    List[v] = 1;
 
    // ���ν�δ����S���ϵĽ���У�ȡDist[]��Сֵ�Ľ�㣬������S��
    // ��List����������V�ж��㣬Dist�ͼ�¼�˴�Դ�㵽������������֮������·������
    for(i=2; i<=n; ++i)
    {
        int Con = oo;
        int u = v;
        // �ҳ���ǰδʹ�õĵ�j��Dist[j]��Сֵ
        for(j=1; j<=n; ++j)
            if((!List[j]) && Min[j]<Con)
            {
                u = j;              // u���浱ǰ�ڽӵ��о��������С�ĵص�ĺ���
                Con = Min[j];
            }
        List[u] = 1;    // u���Ѵ���List������
 
        // ����Min
        for(j=1; j<=n; ++j)
            if((!List[j]) && Dist[u][j]<oo)
            {
                int Min2 = Min[u] + Dist[u][j];
                if(Min2 < Min[j])
                {
                    Min[j] = Min2;
                    Prev[j] = u;
                }
            }
    }
}

void CMyDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	v=1;
	qidian="��ֱ��";
}

void CMyDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	x=1;
	zhongdian="��ֱ��";
}

void CMyDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	v=2;
	qidian="������";
}

void CMyDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	x=2;
	zhongdian="������";	
}

void CMyDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	v=3;
	qidian="֪��·";
}

void CMyDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	x=3;
	zhongdian="֪��·";	
}

void CMyDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	v=4;
	qidian="�����";
}

void CMyDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	x=4;
	zhongdian="�����";	
}

void CMyDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	v=5;
	qidian="�ϵ�";
}

void CMyDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	x=5;
	zhongdian="�ϵ�";
}

void CMyDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	v=6;
	qidian="������";
}

void CMyDlg::OnButton13() 
{
	// TODO: Add your control notification handler code here
	x=6;
	zhongdian="������";	
}

void CMyDlg::OnButton14() 
{
	// TODO: Add your control notification handler code here
	v=7;
	qidian="����";
}

void CMyDlg::OnButton15() 
{
	// TODO: Add your control notification handler code here
	x=7;
	zhongdian="����";
}

void CMyDlg::OnButton16() 
{
	// TODO: Add your control notification handler code here
	v=8;
	qidian="������";
}

void CMyDlg::OnButton17() 
{
	// TODO: Add your control notification handler code here
	x=8;
	zhongdian="������";
}

void CMyDlg::OnButton18() 
{
	// TODO: Add your control notification handler code here
	v=9;
	qidian="��Ӫ";
}

void CMyDlg::OnButton19() 
{
	// TODO: Add your control notification handler code here
	x=9;
	zhongdian="��Ӫ";
}

void CMyDlg::OnButton20() 
{
	// TODO: Add your control notification handler code here
	v=10;
	qidian="��ˮ��";
}

void CMyDlg::OnButton21() 
{
	// TODO: Add your control notification handler code here
	x=10;
	zhongdian="��ˮ��";	
}

void CMyDlg::OnButton22() 
{
	// TODO: Add your control notification handler code here
	v=11;
	qidian="��Է";
}

void CMyDlg::OnButton23() 
{
	// TODO: Add your control notification handler code here
	x=11;
	zhongdian="��Է";	
}

void CMyDlg::OnChangeEdit5() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	
}

void CMyDlg::OnButton24() 
{
	// TODO: Add your control notification handler code here
	v=12;
	qidian="������";
}

void CMyDlg::OnButton25() 
{
	// TODO: Add your control notification handler code here
	x=12;
	zhongdian="������";
}

void CMyDlg::OnButton26() 
{
	// TODO: Add your control notification handler code here
	v=13;
	qidian="��ҩ��";
}

void CMyDlg::OnButton27() 
{
	// TODO: Add your control notification handler code here
	x=13;
	zhongdian="��ҩ��";
}

void CMyDlg::OnButton28() 
{
	// TODO: Add your control notification handler code here
	v=14;
	qidian="������";
}

void CMyDlg::OnButton29() 
{
	// TODO: Add your control notification handler code here
	x=14;
	zhongdian="������";
}

void CMyDlg::OnButton30() 
{
	// TODO: Add your control notification handler code here
	v=15;
	qidian="����";
}

void CMyDlg::OnButton31() 
{
	// TODO: Add your control notification handler code here
	x=15;
	zhongdian="����";
}

void CMyDlg::OnButton32() 
{
	// TODO: Add your control notification handler code here
	v=16;
	qidian="��ֱ��";
}

void CMyDlg::OnButton33() 
{
	// TODO: Add your control notification handler code here
	x=16;
	zhongdian="��ֱ��";
}

void CMyDlg::OnButton34() 
{
	// TODO: Add your control notification handler code here
	v=17;
	qidian="Ӻ�͹�";
}

void CMyDlg::OnButton35() 
{
	// TODO: Add your control notification handler code here
	x=17;
	zhongdian="Ӻ�͹�";
}

void CMyDlg::OnButton36() 
{
	// TODO: Add your control notification handler code here
	v=18;
	qidian="������";
}

void CMyDlg::OnButton37() 
{
	// TODO: Add your control notification handler code here
	x=18;
	zhongdian="������";
}

void CMyDlg::OnButton38() 
{
	// TODO: Add your control notification handler code here
	v=19;
	qidian="��¥���";
}

void CMyDlg::OnButton39() 
{
	// TODO: Add your control notification handler code here
	x=19;
	zhongdian="��¥���";
}

void CMyDlg::OnButton40() 
{
	// TODO: Add your control notification handler code here
	v=20;
	qidian="��ˮ̶";
}

void CMyDlg::OnButton41() 
{
	// TODO: Add your control notification handler code here
	x=20;
	zhongdian="��ˮ̶";
}

void CMyDlg::OnButton42() 
{
	// TODO: Add your control notification handler code here
	v=21;
	qidian="֪����";
}

void CMyDlg::OnButton43() 
{
	// TODO: Add your control notification handler code here
	x=21;
	zhongdian="֪����";
}

void CMyDlg::OnButton44() 
{
	// TODO: Add your control notification handler code here
	v=22;
	qidian="�����ׯ";
}

void CMyDlg::OnButton45() 
{
	// TODO: Add your control notification handler code here
	x=22;
	zhongdian="�����ׯ";	
}

void CMyDlg::OnButton46() 
{
	// TODO: Add your control notification handler code here
	v=23;
	qidian="�йش�";
}

void CMyDlg::OnButton47() 
{
	// TODO: Add your control notification handler code here
	x=23;
	zhongdian="�йش�";
}

void CMyDlg::OnButton48() 
{
	// TODO: Add your control notification handler code here
	v=24;
	qidian="Բ��԰";
}

void CMyDlg::OnButton49() 
{
	// TODO: Add your control notification handler code here
	x=24;
	zhongdian="Բ��԰";
}

void CMyDlg::OnButton50() 
{
	// TODO: Add your control notification handler code here
	v=25;
	qidian="�����ѧ";
}

void CMyDlg::OnButton51() 
{
	// TODO: Add your control notification handler code here
	x=25;
	zhongdian="�����ѧ";
}

void CMyDlg::OnButton52() 
{
	// TODO: Add your control notification handler code here
	v=26;
	qidian="κ����";
}

void CMyDlg::OnButton53() 
{
	// TODO: Add your control notification handler code here
	x=26;
	zhongdian="κ����";
}

void CMyDlg::OnButton54() 
{
	// TODO: Add your control notification handler code here
	v=27;
	qidian="����԰";
}

void CMyDlg::OnButton55() 
{
	// TODO: Add your control notification handler code here
	x=27;
	zhongdian="����԰";
}

void CMyDlg::OnButton56() 
{
	// TODO: Add your control notification handler code here
	v=28;
	qidian="�½ֿ�";
}

void CMyDlg::OnButton57() 
{
	// TODO: Add your control notification handler code here
	x=28;
	zhongdian="�½ֿ�";
}

void CMyDlg::OnButton58() 
{
	// TODO: Add your control notification handler code here
	v=29;
	qidian="ƽ����";
}

void CMyDlg::OnButton59() 
{
	// TODO: Add your control notification handler code here
	x=29;
	zhongdian="ƽ����";
}

void CMyDlg::OnButton60() 
{
	// TODO: Add your control notification handler code here
	v=30;
	qidian="����ׯ";
}

void CMyDlg::OnButton61() 
{
	// TODO: Add your control notification handler code here
	x=30;
	zhongdian="����ׯ";
}

void CMyDlg::OnButton62() 
{
	// TODO: Add your control notification handler code here
	v=31;
	qidian="������";
}

void CMyDlg::OnButton63() 
{
	// TODO: Add your control notification handler code here
	x=31;
	zhongdian="������";
}

void CMyDlg::OnButton64() 
{
	// TODO: Add your control notification handler code here
	v=32;
	qidian="ĵ��԰";
}

void CMyDlg::OnButton65() 
{
	// TODO: Add your control notification handler code here
	x=32;
	zhongdian="ĵ��԰";	
}

void CMyDlg::OnButton66() 
{
	// TODO: Add your control notification handler code here
	v=33;
	qidian="������";
}

void CMyDlg::OnButton67() 
{
	// TODO: Add your control notification handler code here
	x=33;
	zhongdian="������";	
}

void CMyDlg::OnButton68() 
{
	// TODO: Add your control notification handler code here
	v=34;
	qidian="������";	
}

void CMyDlg::OnButton69() 
{
	// TODO: Add your control notification handler code here
	x=34;
	zhongdian="������";	
}

void CMyDlg::OnButton70() 
{
	// TODO: Add your control notification handler code here
	v=35;
	qidian="���������Ͽ�";
}

void CMyDlg::OnButton71() 
{
	// TODO: Add your control notification handler code here
	x=35;
	zhongdian="���������Ͽ�";	
}

void CMyDlg::OnButton72() 
{
	// TODO: Add your control notification handler code here
	v=36;
	qidian="��������";
}

void CMyDlg::OnButton73() 
{
	// TODO: Add your control notification handler code here
	x=36;
	zhongdian="��������";
}

void CMyDlg::OnButton74() 
{
	// TODO: Add your control notification handler code here
	v=37;
	qidian="����ƥ�˹�԰";
}

void CMyDlg::OnButton75() 
{
	// TODO: Add your control notification handler code here
	x=37;
	zhongdian="����ƥ�˹�԰";
}

void CMyDlg::OnButton76() 
{
	// TODO: Add your control notification handler code here
	v=38;
	qidian="��ɳ̲";
}

void CMyDlg::OnButton77() 
{
	// TODO: Add your control notification handler code here
	x=38;
	zhongdian="��ɳ̲";
}

void CMyDlg::OnButton78() 
{
	// TODO: Add your control notification handler code here
	v=39;
	qidian="������";
}

void CMyDlg::OnButton79() 
{
	// TODO: Add your control notification handler code here
	x=39;
	zhongdian="������";
}

void CMyDlg::OnButton80() 
{
	// TODO: Add your control notification handler code here
	v=40;
	qidian="����·";
}

void CMyDlg::OnButton81() 
{
	// TODO: Add your control notification handler code here
	x=40;
	zhongdian="����·";
}

void CMyDlg::OnButton82() 
{
	// TODO: Add your control notification handler code here
	v=41;
	qidian="����·��";
}

void CMyDlg::OnButton83() 
{
	// TODO: Add your control notification handler code here
	x=41;
	zhongdian="����·��";
}

void CMyDlg::OnButton84() 
{
	// TODO: Add your control notification handler code here
	v=42;
	qidian="�������ֱ���";
}

void CMyDlg::OnButton85() 
{
	// TODO: Add your control notification handler code here
	x=42;
	zhongdian="�������ֱ���";
}

void CMyDlg::OnButton86() 
{
	// TODO: Add your control notification handler code here
	v=43;
	qidian="��ˮ����";
}

void CMyDlg::OnButton87() 
{
	// TODO: Add your control notification handler code here
	x=43;
	zhongdian="�������ֱ���";
}

void CMyDlg::OnButton88() 
{
	// TODO: Add your control notification handler code here
	v=44;
	qidian="��Է·��";
}

void CMyDlg::OnButton89() 
{
	// TODO: Add your control notification handler code here
	x=44;
	zhongdian="��Է·��";
}

void CMyDlg::OnButton90() 
{
	// TODO: Add your control notification handler code here
	v=45;
	qidian="�廪��·����";
}

void CMyDlg::OnButton91() 
{
	// TODO: Add your control notification handler code here
	x=45;
	zhongdian="�廪��·����";
}

void CMyDlg::OnButton92() 
{
	// TODO: Add your control notification handler code here
	v=46;
	qidian="��ׯ";
}

void CMyDlg::OnButton93() 
{
	// TODO: Add your control notification handler code here
	x=46;
	zhongdian="��ׯ";
}

void CMyDlg::OnButton94() 
{
	// TODO: Add your control notification handler code here
	v=47;
	qidian="������";
}

void CMyDlg::OnButton95() 
{
	// TODO: Add your control notification handler code here
	x=47;
	zhongdian="������";
}

void CMyDlg::OnButton96() 
{
	// TODO: Add your control notification handler code here
	v=48;
	qidian="�����ﱱ��";
}

void CMyDlg::OnButton97() 
{
	// TODO: Add your control notification handler code here
	x=48;
	zhongdian="�����ﱱ��";
}

void CMyDlg::OnButton98() 
{
	// TODO: Add your control notification handler code here
	v=49;
	qidian="��ƽ����";
}

void CMyDlg::OnButton99() 
{
	// TODO: Add your control notification handler code here
	x=49;
	zhongdian="��ƽ����";
}

void CMyDlg::OnButton100() 
{
	// TODO: Add your control notification handler code here
	v=50;
	qidian="��ƽ�ﱱ��";
}

void CMyDlg::OnButton101() 
{
	// TODO: Add your control notification handler code here
	x=50;
	zhongdian="��ƽ�ﱱ��";
}

void CMyDlg::OnButton102() 
{
	// TODO: Add your control notification handler code here
	v=51;
	qidian="ʲɲ��";
}

void CMyDlg::OnButton103() 
{
	// TODO: Add your control notification handler code here
	x=51;
	zhongdian="ʲɲ��";
}

void CMyDlg::OnButton104() 
{
	// TODO: Add your control notification handler code here
	v=52;
	qidian="�������";
}

void CMyDlg::OnButton105() 
{
	// TODO: Add your control notification handler code here
	x=52;
	zhongdian="�������";
}

void CMyDlg::OnButton106() 
{
	// TODO: Add your control notification handler code here
	v=53;
	qidian="������";
}

void CMyDlg::OnButton107() 
{
	// TODO: Add your control notification handler code here
	x=53;
	zhongdian="������";
}

void CMyDlg::OnButton108() 
{
	// TODO: Add your control notification handler code here
	v=54;
	qidian="����ͼ���";
}

void CMyDlg::OnButton109() 
{
	// TODO: Add your control notification handler code here
	x=54;
	zhongdian="����ͼ���";
}

void CMyDlg::OnButton110() 
{
	// TODO: Add your control notification handler code here
	v=55;
	qidian="������";
}

void CMyDlg::OnButton111() 
{
	// TODO: Add your control notification handler code here
	x=55;
	zhongdian="������";
}

void CMyDlg::OnButton112() 
{
	// TODO: Add your control notification handler code here
	v=56;
	qidian="������ѧ����";
}

void CMyDlg::OnButton113() 
{
	// TODO: Add your control notification handler code here
	x=56;
	zhongdian="������ѧ����";	
}
