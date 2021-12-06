//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <vfw.h>
#include <dir.h>
#include "U_FormAdd.h"
#include "U_FormSearch.h"
#include "U_IconFromExt.h"
#include "U_FormMain.h"
#include "U_FormAbout.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
 TFormMain *FormMain;
 TTreeNode* LastUsed = NULL;
 int NodeCount = 0;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
  SysImageListSmall = new TImageList(NULL);
  SysImageListSmall->Width = 16;
  SysImageListSmall->Height = 16;
  ListView1->SmallImages = SysImageListSmall;

  SysImageListLarge = new TImageList(NULL);
  SysImageListLarge->Width = 32;
  SysImageListLarge->Height = 32;
  ListView1->LargeImages = SysImageListLarge;

  GetWindowsDirectory(WindowsDirName, MAX_PATH);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
  delete SysImageListSmall;
  delete SysImageListLarge;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  ListView1->Clear();
  TreeView1->Items->Clear();
  if (LabelMod->Caption == "yes")
  {
    int MessageResult = MessageBox(NULL, "Baza nie zosta³a zapisana!\nCzy zapisaæ zmiany?", "Zapisywanie",
                                   MB_YESNOCANCEL | MB_ICONWARNING | MB_TASKMODAL | MB_TOPMOST);
    switch(MessageResult)
    {
      case IDYES:     ToolButtonSaveClick(Sender);
      case IDNO:      LabelMod->Caption == "no";   break;
      case IDCANCEL:  return;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MenuMainFileEndClick(TObject *Sender)
{
  FormMain->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MenuPopupLargeIconsClick(TObject *Sender)
{
  ListView1->ViewStyle = vsIcon;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MenuPopupSmallIconsClick(TObject *Sender)
{
  ListView1->ViewStyle = vsSmallIcon;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MenuPopupListClick(TObject *Sender)
{
  ListView1->ViewStyle = vsList;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MenuPopupReportClick(TObject *Sender)
{
  ListView1->ViewStyle = vsReport;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButtonAddClick(TObject *Sender)
{
  FormAdd = new TFormAdd(Application);
  FormAdd->ShowModal();
  delete FormAdd;
}
//--------------------------------------------------------------------------
void __fastcall TFormMain::ToolButtonSearchClick(TObject *Sender)
{
  FormSearch = new TFormSearch(Application);
  FormSearch->ShowModal();
  delete FormSearch;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButtonNewClick(TObject *Sender)
{
  if (LabelMod->Caption == "yes")
  {
    int MessageResult = MessageBox(NULL, "Baza nie zosta³a zapisana!\nCzy zapisaæ zmiany?", "Zapisywanie",
                                   MB_YESNOCANCEL | MB_ICONWARNING | MB_TASKMODAL | MB_TOPMOST);
    switch(MessageResult)
    {
      case IDYES:     ToolButtonSaveClick(Sender);
      case IDNO:      LabelMod->Caption == "no";   break;
      case IDCANCEL:  return;
    }
  }

  ToolButtonAdd->Enabled    = true;
  ToolButtonSave->Enabled   = true;
  ToolButtonSearch->Enabled = true;
  ToolButtonView->Enabled   = true;

  TreeView1->Items->Clear();
  ListView1->Clear();
  TTreeNode* TNode = TreeView1->Items->Add(NULL, "Baza");
  TNode->Data = NULL;
  TreeView1->Visible = true;
  ListView1->Visible = true;
  ToolButtonAdd->Enabled = true;
  ToolButtonSave->Enabled = true;
  ToolButtonView->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::TreeView1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  TTreeNode* TNode = TreeView1->GetNodeAt(X, Y);
  if ((TNode == NULL) || (TNode == LastUsed)) return;

  if (TNode->Level == 1) ToolButtonRemove->Enabled = true; else ToolButtonRemove->Enabled = false;
  LastUsed = TNode;

  ShowFolders(TNode);
  ShowFiles(TNode);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ListView1DblClick(TObject *Sender)
{
  TListItem* LNode = ListView1->Selected;
  if ((LNode == NULL) || (LNode->Data == NULL)) return;

  TTreeNode* TNode = (TTreeNode*)LNode->Data;
  if (TNode == NULL) return;

  ShowFolders(TNode);
  ShowFiles(TNode);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ShowFolders(TTreeNode* TNode)
{
  AnsiString Attributes = "";
  ListView1->Clear();

  if (ActiveControl == ListView1) TNode->Expanded;
  TDirectory* Folder = new TDirectory();

  TTreeNode* TNode2 = NULL;
  for (int i = 0; i < TNode->Count; i++)
  {
    TNode2 = TNode->Item[i];
    Folder = (TDirectory*)TNode2->Data;
    TListItem* LNode = ListView1->Items->Add();
    LNode->ImageIndex = IconIndexFromFile(WindowsDirName, SysImageListSmall, SysImageListLarge);
    LNode->Caption = TNode2->Text;
    LNode->SubItems->Add("");
    LNode->SubItems->Add("");
    if (Folder->Attributes != 0)
    {
      LNode->SubItems->Add(FileDateToDateTime(Folder->TimeOfCreation));
      if (Folder->Attributes &  faArchive) Attributes += "A";
      if (Folder->Attributes &   faHidden) Attributes += "H";
      if (Folder->Attributes &  faSysFile) Attributes += "S";
      if (Folder->Attributes & faReadOnly) Attributes += "R";
      LNode->SubItems->Add(Attributes);
    }
    LNode->Data = TNode2;
    Attributes = "";
  }
//  delete Folder;    //   N I E   U S U W A Æ   W S K A  N I K Ó W ! ! !
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ShowFiles(TTreeNode* TNode)
{
  if (TNode->Data == NULL) return;

  AnsiString Attributes = "";
  TDirectory* Folder = new TDirectory();
  Folder = (TDirectory*)TNode->Data;
  TFiles* First = Folder->ListOfFiles;
  SHFILEINFO Info;

  if (Folder->ListOfFiles == NULL) return;

  while (Folder->ListOfFiles->Next)
  {
    TListItem* LNode = ListView1->Items->Add();
    if (LNode == NULL) return;
    LNode->Caption = Folder->ListOfFiles->Name;
    LNode->ImageIndex = IconIndexFromExt(ExtractFileExt(LNode->Caption), SysImageListSmall, SysImageListLarge);

    LNode->SubItems->Add(Folder->ListOfFiles->Size);
    if (Folder->ListOfFiles->Attributes &  faArchive) Attributes += "A";
    if (Folder->ListOfFiles->Attributes &   faHidden) Attributes += "H";
    if (Folder->ListOfFiles->Attributes &  faSysFile) Attributes += "S";
    if (Folder->ListOfFiles->Attributes & faReadOnly) Attributes += "R";
    SHGetFileInfo(LNode->Caption.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_USEFILEATTRIBUTES | SHGFI_TYPENAME);
    LNode->SubItems->Add(Info.szTypeName);
    LNode->SubItems->Add(FileDateToDateTime(Folder->ListOfFiles->TimeOfCreation));
    LNode->SubItems->Add(Attributes);
    Attributes = "";
    Folder->ListOfFiles = Folder->ListOfFiles->Next;
  }
  Folder->ListOfFiles = First;
//  delete Folder;                      NIE USUWAC WSKAZNIKOW!!!
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButtonSaveClick(TObject *Sender)
{
 if (!DialogSave->Execute()) return;
 if (FileExists(DialogSave->FileName)) DeleteFile(DialogSave->FileName);
 int Handle = FileCreate(DialogSave->FileName);
 LabelMod->Caption = "no";

 TTreeNode* Node = TreeView1->Items->GetFirstNode()->getFirstChild();
 SaveFolder(Handle, Node);
 FileClose(Handle);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SaveFolder(int Handle, TTreeNode* Node)
{
  while (Node != NULL)
  {
    if (Node->Level == 0)
    {
      SaveFiles(Handle, Node->Data);
    }
    else
    {
      int IntBuf;

      IntBuf = Node->Level;              FileWrite(Handle, &IntBuf, sizeof(int));
      IntBuf = Node->Text.Length();      FileWrite(Handle, &IntBuf, sizeof(int));
      FileWrite(Handle, Node->Text.c_str(), IntBuf);

      TDirectory* Folder = new TDirectory;
      Folder = (TDirectory*)Node->Data;
      IntBuf = Folder->Attributes;       FileWrite(Handle, &IntBuf, sizeof(int));
      IntBuf = Folder->TimeOfCreation;   FileWrite(Handle, &IntBuf, sizeof(int));
      IntBuf = Folder->NumberOfFiles;    FileWrite(Handle, &IntBuf, sizeof(int));

      SaveFiles(Handle, Node->Data);
    }
    Node = Node->GetNext();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SaveFiles(int Handle, void* Data)
{
  int IntBuf;

  TDirectory* Folder = new TDirectory;
  Folder = (TDirectory*)Data;
  TFiles* First = Folder->ListOfFiles;

  for (int i = 0; i < Folder->NumberOfFiles; i++)
  {
    IntBuf = Folder->ListOfFiles->Name.Length();     FileWrite(Handle, &IntBuf, sizeof(int));
    FileWrite(Handle, Folder->ListOfFiles->Name.c_str(), Folder->ListOfFiles->Name.Length());
    IntBuf = Folder->ListOfFiles->Size;              FileWrite(Handle, &IntBuf, sizeof(int));
    IntBuf = Folder->ListOfFiles->TimeOfCreation;    FileWrite(Handle, &IntBuf, sizeof(int));
    IntBuf = Folder->ListOfFiles->Attributes;        FileWrite(Handle, &IntBuf, sizeof(int));
    Folder->ListOfFiles = Folder->ListOfFiles->Next;
  }
  Folder->ListOfFiles = First;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButtonOpenClick(TObject *Sender)
{
  if (LabelMod->Caption == "yes")
  {
    int MessageResult = MessageBox(NULL, "Baza nie zosta³a zapisana!\nCzy zapisaæ zmiany?", "Zapisaæ zmiany?",
                                   MB_YESNOCANCEL | MB_ICONWARNING | MB_TASKMODAL | MB_TOPMOST);

    switch(MessageResult)
    {
      case IDYES:     ToolButtonSaveClick(Sender);
      case IDNO:      break;
      case IDCANCEL:  return;
    }
  }

  if (!DialogOpen->Execute()) return;

  TreeView1->Visible = true;
  ListView1->Visible = true;
  ToolButtonAdd->Enabled    = true;
  ToolButtonSave->Enabled   = true;
  ToolButtonSearch->Enabled = true;
  ToolButtonView->Enabled   = true;
  TreeView1->Items->Clear();
  ListView1->Clear();

  int Handle = FileOpen(DialogOpen->FileName,fmOpenRead);
  TTreeNode* Node = TreeView1->Items->AddFirst(NULL, "Baza");
  Node->ImageIndex = 5;
  Node->SelectedIndex = Node->ImageIndex;
  OpenFolder(Handle, Node);
  FileClose(Handle);
  LabelMod->Caption == "no";
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::OpenFolder(int Handle, TTreeNode* Node)
{

  int IntBuf = 0;

  while (1)
  {
    if (!FileRead(Handle, &IntBuf, sizeof(int))) return;
    if (IntBuf <= Node->Level)
    {
      FileSeek(Handle, (int)(0 - sizeof(int)), 1);
      return;
    }

    FileRead(Handle, &IntBuf, sizeof(int));
    char* StrBuf = new char[IntBuf + 1];
    FileRead(Handle, StrBuf, IntBuf);
    StrBuf[IntBuf] = '\0';
    TTreeNode* Node2 = TreeView1->Items->AddChild(Node, StrBuf);
    delete StrBuf;
    Node2->ImageIndex = 3;
    Node2->SelectedIndex = Node->ImageIndex;

    TDirectory* Folder = new TDirectory();
    FileRead(Handle, &IntBuf, sizeof(int));    Folder->Attributes = IntBuf;
    FileRead(Handle, &IntBuf, sizeof(int));    Folder->TimeOfCreation = IntBuf;

    OpenFiles(Handle, Node2, Folder);
    OpenFolder(Handle, Node2);
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::OpenFiles(int Handle, TTreeNode* Node, TDirectory* Folder)
{
  int IntBuf = 0;

  FileRead(Handle, &IntBuf, sizeof(int));
  int NumberOfFiles = IntBuf;
  Folder->NumberOfFiles = NumberOfFiles;
  TFiles* ListOfFiles = new TFiles;
  TFiles* First = ListOfFiles;

  for (int i = 0; i < NumberOfFiles; i++)
  {
    FileRead(Handle, &IntBuf, sizeof(int));
    char* StrBuf = new char[IntBuf + 1];
    FileRead(Handle, StrBuf, IntBuf);
    StrBuf[IntBuf] = '\0';
    ListOfFiles->Name = StrBuf;
    delete StrBuf;

    FileRead(Handle, &IntBuf, sizeof(int));   ListOfFiles->Size = IntBuf;
    FileRead(Handle, &IntBuf, sizeof(int));   ListOfFiles->TimeOfCreation = IntBuf;
    FileRead(Handle, &IntBuf, sizeof(int));   ListOfFiles->Attributes = IntBuf;

    ListOfFiles->Next = new TFiles;
    ListOfFiles = ListOfFiles->Next;
  }
  Folder->ListOfFiles = First;
  Node->Data = Folder;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::ToolButtonRemoveClick(TObject *Sender)
{
  if (ActiveControl == TreeView1)
    if (TreeView1->Selected != NULL)
      if (MessageBox(NULL, "Czy usun¹æ wybrany element?", "Usuwanie",
                     MB_YESNO | MB_ICONWARNING | MB_TASKMODAL | MB_TOPMOST) == IDYES);
      {
        ListView1->Clear();
        if (TreeView1->Selected != TreeView1->TopItem->GetLastChild())
        {
          ShowFolders(TreeView1->Selected->getNextSibling());
          ShowFiles(TreeView1->Selected->getNextSibling());
        }
        TreeView1->Selected->Delete();
        LabelMod->Caption = "yes";
      }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::MenuMainHelpAboutClick(TObject *Sender)
{
  FormAbout = new TFormAbout(Application);
  FormAbout->ShowModal();
  delete FormAbout;
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::TreeView1Expanded(TObject *Sender,
      TTreeNode *Node)
{
if (Node->Level != 1)
{
  Node->ImageIndex = 4;
  Node->SelectedIndex = Node->ImageIndex;
}
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::TreeView1Collapsed(TObject *Sender,
      TTreeNode *Node)
{
if (Node->Level != 1)
{
  Node->ImageIndex = 3;
  Node->SelectedIndex = Node->ImageIndex;
}
}
//---------------------------------------------------------------------------

