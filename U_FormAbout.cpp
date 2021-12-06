//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "U_FormAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAbout *FormAbout;
//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormAbout::Button1Click(TObject *Sender)
{
FormAbout->Close();        
}
//---------------------------------------------------------------------------

