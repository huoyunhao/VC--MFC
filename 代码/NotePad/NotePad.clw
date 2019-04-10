; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNotePadDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NotePad.h"

ClassCount=3
Class1=CNotePadApp
Class2=CNotePadDlg

ResourceCount=4
Resource2=IDD_NOTEPAD_DIALOG
Resource3=IDD_ABOUT_DIALOG
Resource1=IDR_MAINFRAME
Class3=CAbout
Resource4=IDR_MENU1

[CLS:CNotePadApp]
Type=0
HeaderFile=NotePad.h
ImplementationFile=NotePad.cpp
Filter=N

[CLS:CNotePadDlg]
Type=0
HeaderFile=NotePadDlg.h
ImplementationFile=NotePadDlg.cpp
Filter=W
LastObject=test
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_NOTEPAD_DIALOG]
Type=1
Class=CNotePadDlg
ControlCount=1
Control1=IDC_TEXT,edit,1352732932

[DLG:IDD_ABOUT_DIALOG]
Type=1
Class=CAbout
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342177283
Control3=IDC_STATIC,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_EXIT
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_EDIT_CLEAR
Command11=ID_EDIT_SELECT_ALL
Command12=ID_EDIT_DATE
Command13=ID_MENUITEM32778
Command14=ID_FORMAT_FONT
Command15=ID_HELP_ABOUT
CommandCount=15

[CLS:CAbout]
Type=0
HeaderFile=About.h
ImplementationFile=About.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_HELP_ABOUT
VirtualFilter=dWC

