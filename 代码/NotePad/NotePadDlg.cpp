// NotePadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NotePad.h"
#include "NotePadDlg.h"
#include "About.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg dialog

CNotePadDlg::CNotePadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNotePadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNotePadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);  //修改图标
}
/*
实现控件和变量之间的值传递-------------------数据交换
比如你绑定一个CString到一个Edit控件，DoDataExchange可以实现读取Edit的内容到CString中，也可以实现把CString的内容写入Edit，通过UpdateData(TRUE/FALSE)
*/
void CNotePadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNotePadDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}
//用户操作消息监听
BEGIN_MESSAGE_MAP(CNotePadDlg, CDialog)
	//{{AFX_MSG_MAP(CNotePadDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_WM_CLOSE()
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_SELECT_ALL, OnEditSelectAll)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_COMMAND(ID_EDIT_DATE, OnEditDate)
	ON_WM_SIZE()
	ON_WM_DROPFILES()
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FORMAT_FONT, OnFormatFont)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg message handlers
// 初始化对话框标题图标等等
BOOL CNotePadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetWindowText("霍运浩-2016124082-");  //设置标题
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
		
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

//绘制对话框的坐标位置，大小等等
void CNotePadDlg::OnPaint() 
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
//系统调用这个函数以获得用户拖动时显示的光标
//最小化窗口。
HCURSOR CNotePadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//实现关于对话框的显示
void CNotePadDlg::OnHelpAbout() 
{
	CAbout dlg;
	dlg.DoModal();//弹出CAbout类定义的对话框
	
}

//禁用esc退出程序
void CNotePadDlg::OnCancel() 
{
	//CDialog::OnCancel();
}

//重载OnClose()实现X的退出功能
void CNotePadDlg::OnClose() 
{
	OnFileExit();//这里调用菜单下的退出函数
	//EndDialog(IDCANCEL);
	//CDialog::OnClose();
}

//实现菜单栏目下 复制的功能

//---------------------------------IDC_TEXT 为编辑框id

void CNotePadDlg::OnEditCopy() 
{
	//获取选中文本
	CEdit * pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	//调用内建函数 copy复制
    pEdit->Copy();
}

//实现菜单栏目下 删除的功能
void CNotePadDlg::OnEditClear() 
{
	CEdit * pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Clear();
}
//实现菜单栏目下 撤销的功能
void CNotePadDlg::OnEditUndo() 
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit ->Undo();	
}

//实现菜单栏目下 剪切的功能
void CNotePadDlg::OnEditCut() 
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit ->Cut();
}
//实现菜单栏目下 全选的功能
void CNotePadDlg::OnEditSelectAll() 
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	
	pEdit ->SetSel(0,-1);	
}

//实现编辑框快捷键ctrl+a 和delete  通过自己处理消息就是！Ctrl+A是一个组合消息，在检测到A或者a按键按下的时候，
//判断Ctrl键的状态，如果Ctrl键有效则说明用户按下了Ctrl+A按键，这时候我们将Edit中内容设置为全选即可。
BOOL CNotePadDlg::PreTranslateMessage(MSG * pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		BOOL b = GetKeyState(VK_CONTROL) & 0x80;
		CWnd *pActiveWnd = GetFocus();
		DWORD nWndID = 0;
		if (pActiveWnd)
		{
			nWndID = pActiveWnd->GetDlgCtrlID();//获取光标所在的框
		}
		if (b && (pMsg->wParam == 'a' || pMsg->wParam == 'A'))
		{
			SendDlgItemMessage(nWndID, EM_SETSEL, 0, -1);
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


//实现菜单栏目下 粘贴的功能
void CNotePadDlg::OnEditPaste() 
{
	
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit ->Paste();	
}
//实现菜单栏目下 时间的功能
void CNotePadDlg::OnEditDate() 
{
	CTime t = CTime::GetCurrentTime();
	
	CString str = t.Format("%Y年%m月%d日 %H:%M:%S");
	//获取编辑框
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	//替换
	pEdit ->ReplaceSel( str,TRUE);
}

//实现移动窗口大小的功能；记得修改窗口属性当中的值
void CNotePadDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	CWnd* pEdit = GetDlgItem(IDC_TEXT);
	if(pEdit)
		pEdit->MoveWindow(0,0,cx,cy);
	
}

//实现菜单下退出的功能
void CNotePadDlg::OnFileExit() 
{
	if(Prompt() == 0) //如果等于0，代表选择了取消，那么不关闭对话框
	{
		//不做任何处理
	}
	else//如果不等于0 那么代表选择了 否  直接关闭对话框
	{
		EndDialog(IDCANCEL);	
	}
		
}

//实现拖一个文件进入的功能
void CNotePadDlg::OnDropFiles(HDROP hDropInfo) 
{	
	if(!Prompt())
		return;
	char szFile[MAX_PATH];
	UINT n = DragQueryFile(hDropInfo,0,szFile,sizeof(szFile));
	CString str = szFile ;
	n = str.ReverseFind('\\');
	if(n>0)
	{
		str = str.Mid(n+1);
		OpenFile(szFile,str);
	}

	CDialog::OnDropFiles(hDropInfo);
}

//实现菜单栏下新建的功能
void CNotePadDlg::OnFileNew() 
{
	//处理文件改变的情况；如果在我们新建一个文件的时候，改变了原来存在的文件
	//如果==0；代表取消，那么直接返回，表示取消新建的任务
	//如果！=0； 那么就可能保存当前文件或者不保存当前文件
	if(Prompt() == 0)
		return;

	//然后下面就是新建文件的任务。
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->SetWindowText("");
	m_szCurrentFile = "";
	SetTitle();

	
}

//实现菜单栏目下打开的功能
void CNotePadDlg::OnFileOpen() 
{
	//过滤器
	LPCTSTR szFilter = "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||";
	//打开一个文件选择对话框 TRUE代表 打开文件
	CFileDialog filedlg(TRUE,"txt","11",OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST,
		szFilter);
	if(IDCANCEL== filedlg.DoModal())
		return;
	//打开文件并显示到IDC_TEXT当中
	OpenFile(filedlg.GetPathName(),filedlg.GetFileName());
}

//实现菜单栏目下保存的功能
void CNotePadDlg::OnFileSave() 
{
	//如果要保存的文件是第一次保存，那么就转换到 另存为
	if(m_szCurrentFile.GetLength() == 0)
	{
		OnFileSaveAs();
		return;
	}
	
	CFile file;
	if(file.Open(m_szCurrentFile,CFile::modeWrite|CFile::modeCreate) == 0)
	{	
		OnFileSaveAs();
		return;
	
	}

	CString szText;
	GetDlgItemText(IDC_TEXT,szText);//得到Edit控件里面的内容
	file.Write(szText,szText.GetLength());//写入file对象
	file.Close();//关闭对象
		
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT) ;
	pEdit ->SetModify(FALSE);//FALSE表示文本没有改变；这里直接保存，点击退出的时候不要再提示改变

}

//实现菜单栏目下另存为的功能
void CNotePadDlg::OnFileSaveAs() 
{
	
	LPCTSTR szFilter = "文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||";
	//初始化文件对话框 FALSE代表保存文件
	CFileDialog filedlg(FALSE,"txt","新建文件夹",OFN_OVERWRITEPROMPT|OFN_PATHMUSTEXIST|
		OFN_FILEMUSTEXIST|OFN_CREATEPROMPT,szFilter);
	//打开文件对话框
	if(IDCANCEL == filedlg.DoModal())
		return;
	//得到文件对话框中选择文件的路径名
	CString szFile = filedlg.GetPathName();

	//声明一个CFile对象
	CFile file;
	//打开文件
	if( file.Open(szFile,CFile::modeWrite|CFile::modeCreate) == 0)
	{
		MessageBox(filedlg.GetFileName()+"保存文件时失败!", NULL,MB_ICONEXCLAMATION);
		return;
	}

	//当前文件为该文件，保存下来
	m_szCurrentFile = szFile;

	CString strText;
	//得到IDC_TEXT控件里面的内容 
	GetDlgItemText(IDC_TEXT,strText);
	//文件写入，第一个参数是要写入的内容，第二个是写入内容的长度
	file.Write(strText,strText.GetLength());

	/*
1:	Flush是将缓冲区的内容写入文件，并清空。缓冲区是4k的内容，够4k了，
	就会自动写入文件，不够的话就需要flush一下，如果不flush的话，文件
	的最后有可能会少一些内容 
2:  Flush()的作用是刷新缓冲区，如果你在write（）完成后调用了Close()，
	那缓冲区的那部分数据就丢失了，因为数据时先写入内存然后在读进文件了。
	所以在调用Close()前把缓冲区的数据强行输出，这样才不会丢失数据。
3:  flush()的作用是强制将缓冲区的数据写入磁盘，只是为了确保数据尽快被写入，但是其实如果小量数据就用flush(),那么硬盘写入的机械操作时间是相对比较长的，
	如果不调用flush(),缓冲区达到一定的数据量就会自动写入磁盘。
	在关闭文件的时候也会把缓冲区的数据（如果有）强制写入磁盘
4:  如果不是多线程写同一个文件，可以不用flush(),
	最后结束前记得close就可以，当然也可以最后flush一次，再close 
	*/
	file.Flush();//上面的解释跟清除了，我看这个就明白了，相信你也一样

	file.Close();//关闭文件，删除对象！

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	//不更改原有文本
	pEdit ->SetModify(FALSE);
	SetTitle();
	
}

//实现菜单栏目下字体选择的功能
void CNotePadDlg::OnFormatFont() 
{
	
	CFont* pFont = GetDlgItem(IDC_TEXT)->GetFont();
	LOGFONT lf;
	pFont->GetLogFont(&lf);//获得当前CFont对象的LOGFONT结构体的拷贝
	CFontDialog fd(&lf);//构造字体对话框，初始选择字体为当前CFont对象的字体

	if(IDCANCEL == fd.DoModal())
		return;
	m_font.DeleteObject();//如果m_font已经关联了一个字体资源对象，则释放它
	m_font.CreateFontIndirect(fd.m_cf.lpLogFont);//使用选定字体的LOGFONT创建新的字体 
	GetDlgItem(IDC_TEXT)->SetFont(&m_font);//选定字体
	
}
//打开文件
void CNotePadDlg::OpenFile(CString szFilePath, CString szFileName)
{

	CFile file;//声明一个CFile对象

	//打开一个文件
	if(file.Open(szFilePath,CFile::modeRead) == 0)
	{
		MessageBox(szFileName+"打开文件失败!",NULL,MB_ICONEXCLAMATION);
		return;
	}
	/*
	int size = file.GetLength();//得到文件的长度
	char* pText = new char[size+1];//要读入文件缓冲区的指针

	//将CFile对象file相关联文件的数据读入缓冲。
	int nRet = file.Read(pText,size);
	file.Close();//关闭对象
	*/

	//第二种方法
	CFileStatus fs;
	file.GetStatus(fs);
	char *pText = new char[fs.m_size+1];
	memset(pText,0,fs.m_size+1);
	int nRet = file.Read(pText,fs.m_size);
	file.Close();
/*
	这里解释一下你打开文件有可能是乱码，那是因为你要打开的文件是unicode或者其他不是ANSI的格式
	怎么看你要打开的文件是什么格式？
	用记事本打开你要打开的文件，然后另存为，你就会看到你的这个文件是什么格式的了。当你把它改为ANSI格式
	就不会出现乱码了！
*/
	pText[nRet] = 0;//把最后置为0 结尾  字符串结尾要为\0;
	m_szCurrentFile = szFilePath;//把当前文件路径设置为当前打开的文件路径

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->SetWindowText(pText);
	pEdit ->SetModify(FALSE);

	SetTitle();

}
//处理文件修改的情况
BOOL CNotePadDlg::Prompt()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	if(pEdit->GetModify())//如果文件被修改
	{
		CString str;
		if(m_szCurrentFile.IsEmpty())//如果当前的文件为空，则str= 无标题
			str = "无标题";
		else
			str = m_szCurrentFile; //否则就是 现在打开文件的Path

		int nRet = MessageBox(str+"\r\n已经被修改，是否保存？","提示消息",
			MB_YESNOCANCEL|MB_ICONEXCLAMATION);

		if(IDCANCEL == nRet)//如果选择了  取消，那么不做任何处理，也不关闭对话框(在退出函数中做处理)
			return FALSE;
		if(IDNO == nRet) //如果选择了 否 直接关闭对话框（在退出函数当中做处理）
			return TRUE;
		else//如果选择了 是 保存文件
 			OnFileSave();
	}

	return TRUE;
}

//设置上面的标题
void CNotePadDlg::SetTitle()
{
	CString str;
	if(m_szCurrentFile.IsEmpty())
		str = "无标题";
	else
		str = m_szCurrentFile;

	int i = str.ReverseFind('\\'); //反向找到 
	if(i > 0)
		str = str.Mid(i+1); //从\\位置处 截出str后面的内容

	SetWindowText(str);
}
