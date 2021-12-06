//---------------------------------------------------------------------------

#ifndef U_FormSearchH
#define U_FormSearchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TFormSearch : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditSearch;
        TLabel *LabelZnajdz;
        TButton *ButtonStart;
        TGroupBox *GroupBox1;
        TRadioGroup *RadioGroup1;
        TCheckBox *CheckBoxFoldery;
        TCheckBox *CheckBoxPliki;
        TListView *ListView1;
        TStatusBar *StatusBar;
private:	// User declarations
public:		// User declarations
        __fastcall TFormSearch(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSearch *FormSearch;
//---------------------------------------------------------------------------
#endif
