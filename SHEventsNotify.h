#ifndef SHEventNotifyH
#define SHEventNotifyH
//---------------------------------------------------------------------------
#include <Systobj.h>
//---------------------------------------------------------------------------
#ifndef __DLL__
 #define DLL_EXP __stdcall __import
#else
 #define DLL_EXP __stdcall __export
#endif
//---------------------------------------------------------------------------
typedef void __fastcall (__closure *TOneParmEvent)(TObject* Sender, Cardinal Flags, AnsiString Path1);
typedef void __fastcall (__closure *TTwoParmEvent)(TObject* Sender, Cardinal Flags, AnsiString Path1, AnsiString Path2);
typedef void __fastcall (__closure *TEndSessionQueryEvent)(TObject* Sender, bool& CanEndSession);

//---------------------------------------------------------------------------
extern "C" TObject* DLL_EXP SHEventNotifyCreate(void);
extern "C" void DLL_EXP SHEventNotifyDestroy(TObject* Handle);
extern "C" void DLL_EXP SHEventNotifyStart(TObject* Handle);
extern "C" void DLL_EXP SHEventNotifyStop(TObject* Handle);
extern "C" void DLL_EXP SHEventNotifySetOnAssocChanged(TObject* Handle, TTwoParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnAttributes(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnCreate(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnDelete(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnDriveAdd(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnDriveAddGUI(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnDriveRemoved(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnMediaInserted(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnMediaRemoved(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnMkDir(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnNetShare(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnNetUnshare(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnRenameFolder(TObject* Handle, TTwoParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnRenameItem(TObject* Handle, TTwoParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnRmDir(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnServerDisconnect(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnUpdateDir(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnUpdateImage(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnUpdateItem(TObject* Handle, TOneParmEvent EventFunction);
extern "C" void DLL_EXP SHEventNotifySetOnEndSessionQuery(TObject* Handle, TEndSessionQueryEvent EventFunction);

//---------------------------------------------------------------------------
#endif
