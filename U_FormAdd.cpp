//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <dir.h>
#include "U_FormAdd.h"
#include "U_FormMain.h"
//---------------------------------------------------------------------------
#pragma hdrstop
#pragma resource "*.dfm"
#pragma package(smart_init)
TFormAdd *FormAdd;
int Level = 0;
int Attributes[10];
int Times[10];
int NumberOfFiles[10];
//---------------------------------------------------------------------------
__fastcall TFormAdd::TFormAdd(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
  char ListOfDrives[26][3];

void __fastcall TFormAdd::FormCreate(TObject *Sender)
{
  char str[3] = "A:\0";
  int j = 0;
  char Name[20] = {0};
  ComboBoxDrives->Clear();

  for (int i=0;i<26;++i)
  {
    str[0] = (char)(i + 'A');
    if (DRIVE_CDROM == GetDriveType(str))
    {
      strcpy(ListOfDrives[j++], str);
      GetVolumeInformation(str, Name, 15, NULL, NULL, NULL, NULL, NULL);
      strcat(Name, " (");
      strcat(Name, str);
      strcat(Name, ")");
      ComboBoxDrives->Items->Add(Name);
    }
  }
  ComboBoxDrives->ItemIndex = 0;
  Name[0] = '\0';
  GetVolumeInformation(ListOfDrives[0], Name, 15, NULL, NULL, NULL, NULL, NULL);
  EditCDName->Text = Name;
}
//---------------------------------------------------------------------------
void __fastcall TFormAdd::ButtonOKClick(TObject *Sender)
{
  if (EditCDName->Text == "")
  {
    if (MessageDlg(AnsiString("W stacji ")
        + ListOfDrives[ComboBoxDrives->ItemIndex]
        + AnsiString(" nie ma p³yty lub nie podano jej nazwy!"), mtError, mbOKCancel, 0) == mrOk)
    {
      FormAdd->ModalResult = NULL;
      return;
    }
    else return;
  }
  TTreeNode* Node = FormMain->TreeView1->Items->AddChild(FormMain->TreeView1->TopItem, EditCDName->Text);
  Node->ImageIndex = 5;
  Node->SelectedIndex = Node->ImageIndex;

  ScanDirectory(ListOfDrives[ComboBoxDrives->ItemIndex], 0, 0, Node);  // skanuj CD
//  ScanDirectory("c:\\", 0, 0, Node);                                 // skanuj dysk C:

  FormMain->ActiveControl = FormMain->TreeView1;
  FormMain->LabelMod->Caption = "yes";
  FormAdd->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormAdd::ScanDirectory(AnsiString Dir, int Attr, int Time, TTreeNode* Parent)
{
  TSearchRec Info;
  if (AnsiLastChar(Dir) != "\\") Dir += "\\";
  AnsiString Mask = Dir + "*";
  Mask += "*";

  TFiles* ListOfFiles = new TFiles();
  TFiles* First = ListOfFiles;

  Attributes[Level] = Attr;
  Times[Level] = Time;
  NumberOfFiles[Level] = 0;

  int Done = FindFirst(Mask, FA_RDONLY | FA_HIDDEN | FA_SYSTEM | FA_DIREC | FA_ARCH, Info);
  while (!Done)
  {
    if ((Info.Name != ".") && (Info.Name != ".."))
    {
      if (!(Info.Attr & FA_DIREC))
      {
        ListOfFiles->Name = Info.Name;
        ListOfFiles->Attributes = Info.Attr;
        ListOfFiles->TimeOfCreation = Info.Time;
        ListOfFiles->Size = Info.Size;
        ListOfFiles->Next = new TFiles();
        ListOfFiles = ListOfFiles->Next;
        NumberOfFiles[Level]++;
      }
      else
      {
        TTreeNode* Node = FormMain->TreeView1->Items->AddChild(Parent, Info.Name);
        Node->ImageIndex = 3;
        Node->SelectedIndex = Node->ImageIndex;
        Level++;
        AnsiString FullDirName = Dir + Info.Name;
        ScanDirectory(FullDirName, Info.Attr, Info.Time, Node);
        Level--;
      }
    }
    Done = FindNext(Info);
  }
  FindClose(Info);

  TDirectory* Folder = new TDirectory();
  Folder->Attributes = Attributes[Level];
  Folder->TimeOfCreation = Times[Level];
  Folder->ListOfFiles = First;
  Folder->NumberOfFiles = NumberOfFiles[Level];
  Parent->Data = Folder;
}
//---------------------------------------------------------------------------
void __fastcall TFormAdd::ComboBoxDrivesChange(TObject *Sender)
{
  char Name[20]={0};
  GetVolumeInformation(ListOfDrives[ComboBoxDrives->ItemIndex], Name, 15, NULL, NULL, NULL, NULL, NULL);
  EditCDName->Text=Name;
}
//---------------------------------------------------------------------------

