//---------------------------------------------------------------------------
#ifndef U_FormMainH
#define U_FormMainH
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TFiles
{
public:
        AnsiString Name;
        int Attributes;
        int Size;
        int TimeOfCreation;
        TFiles* Next;
        __fastcall Files(void)
        {
          Next = NULL;
        }
};

class TDirectory
{
public:
        int Attributes;
        int TimeOfCreation;
        TFiles* ListOfFiles;
        int NumberOfFiles;
        __fastcall Directory(void)
        {
          Attributes = 0;
          TimeOfCreation = 0;
          ListOfFiles = NULL;
          NumberOfFiles = 0;
        }
};

class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MenuMain;
        TStatusBar *StatusBar;
        TToolBar *Toolbar;
        TMenuItem *MenuMainFile;
        TToolButton *ToolButtonNew;
        TToolButton *ToolButtonOpen;
        TToolButton *ToolButtonSave;
        TToolButton *ToolButtonAdd;
        TToolButton *ToolButtonRemove;
        TToolButton *ToolButtonSearch;
        TToolButton *ToolButtonSep1;
        TToolButton *ToolButtonView;
        TImageList *NormalImages;
        TImageList *HotImages;
        TImageList *DisabledImages;
        TToolButton *ToolButtonHelp;
        TToolButton *ToolButtonSep2;
        TToolButton *ToolButtonSep3;
        TMenuItem *MenuMainFileNew;
        TMenuItem *MenuMainFileOpen;
        TMenuItem *MenuMainFileSave;
        TMenuItem *MenuMainSep1;
        TMenuItem *MenuMainFileEnd;
        TMenuItem *MenuMainEdit;
        TMenuItem *MenuMainEditAdd;
        TMenuItem *MenuMainEditRemove;
        TMenuItem *MenuMainHelp;
        TMenuItem *MenuMainHelpContext;
        TMenuItem *MenuMainHelpAbout;
        TPopupMenu *MenuPopupView;
        TMenuItem *MenuPopupLargeIcons;
        TMenuItem *MenuPopupList;
        TMenuItem *MenuPopupReport;
        TMenuItem *MenuPopupSmallIcons;
        TTreeView *TreeView1;
        TSplitter *Splitter;
        TListView *ListView1;
        TImageList *SmallIcons;
        TOpenDialog *DialogOpen;
        TSaveDialog *DialogSave;
        TLabel *LabelMod;
        void __fastcall MenuMainFileEndClick(TObject *Sender);
        void __fastcall MenuPopupLargeIconsClick(TObject *Sender);
        void __fastcall MenuPopupSmallIconsClick(TObject *Sender);
        void __fastcall MenuPopupListClick(TObject *Sender);
        void __fastcall MenuPopupReportClick(TObject *Sender);
        void __fastcall ToolButtonAddClick(TObject *Sender);
        void __fastcall ToolButtonOpenClick(TObject *Sender);
        void __fastcall ToolButtonSaveClick(TObject *Sender);
        void __fastcall ToolButtonSearchClick(TObject *Sender);
        void __fastcall ToolButtonNewClick(TObject *Sender);
        void __fastcall TreeView1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ListView1DblClick(TObject *Sender);

        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ToolButtonRemoveClick(TObject *Sender);
        void __fastcall MenuMainHelpAboutClick(TObject *Sender);
        void __fastcall TreeView1Expanded(TObject *Sender,
          TTreeNode *Node);
        void __fastcall TreeView1Collapsed(TObject *Sender,
          TTreeNode *Node);
private:	// User declarations
        TImageList* SysImageListSmall;
        TImageList* SysImageListLarge;
        char WindowsDirName[MAX_PATH];
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);

        void __fastcall ShowFolders(TTreeNode* TNode);
        void __fastcall ShowFiles(TTreeNode* TNode);
        void __fastcall SaveFolder(int Handle, TTreeNode* Node);
        void __fastcall SaveFiles(int Handle, void* Data);
        void __fastcall OpenFolder(int Handle, TTreeNode* Node);
        void __fastcall OpenFiles(int Handle, TTreeNode* Node, TDirectory* Folder);

};

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
