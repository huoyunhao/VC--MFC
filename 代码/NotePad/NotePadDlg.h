// NotePadDlg.h : header file
//

#if !defined(AFX_NOTEPADDLG_H__3F91FEDA_5FBC_4057_A066_677018A77D7B__INCLUDED_)
#define AFX_NOTEPADDLG_H__3F91FEDA_5FBC_4057_A066_677018A77D7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNotePadDlg dialog

class CNotePadDlg : public CDialog
{
// Construction
public:
	void SetTitle();
	BOOL Prompt();
	CString m_szCurrentFile;
	CFont m_font;
	void OpenFile(CString szFilePath, CString szFileName);
	CNotePadDlg(CWnd* pParent = NULL);	// standard constructor
	PreTranslateMessage(MSG * pMsg);

// Dialog Data
	//{{AFX_DATA(CNotePadDlg)
	enum { IDD = IDD_NOTEPAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNotePadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNotePadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHelpAbout();
	afx_msg void OnQuit();
	virtual void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnEditCopy();
	afx_msg void OnEditClear();
	afx_msg void OnEditUndo();
	afx_msg void OnEditCut();
	afx_msg void OnEditSelectAll();
	afx_msg void OnEditPaste();
	afx_msg void OnEditDate();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnFileExit();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFormatFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOTEPADDLG_H__3F91FEDA_5FBC_4057_A066_677018A77D7B__INCLUDED_)
