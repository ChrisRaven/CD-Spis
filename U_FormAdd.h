//---------------------------------------------------------------------------

#ifndef U_FormAddH
#define U_FormAddH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TFormAdd : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBoxDrives;
        TLabel *LabelNaped;
        TEdit *EditCDName;
        TLabel *LabelNazwa;
        TBitBtn *ButtonOK;
        TBitBtn *ButtonAnuluj;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall ComboBoxDrivesChange(TObject *Sender);
        void __fastcall ScanDirectory(AnsiString Dir, int Attr, int Time, TTreeNode* Parent);
     private:	// User declarations
     public:    // User declarations
        __fastcall TFormAdd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAdd *FormAdd;
//---------------------------------------------------------------------------
#endif
