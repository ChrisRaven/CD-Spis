library SHEventsNotify;

uses
  SysUtils,
  Classes,
  Forms,
  SHChangeNotify in 'SHChangeNotify.pas';

{$R *.res}
{------------------------------------------------------------------------------}
function SHEventNotifyCreate : TObject; stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify.Create(TForm.Create(nil));
  Result := EN;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifyDestroy(Handle: TObject); stdcall;
var EN:TSHChangeNotify;
    Owner:TForm;
begin
  EN := TSHChangeNotify(Handle);
  Owner := TForm(EN.Owner);
  EN.Free;
  Owner.Free;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifyStart(Handle: TObject); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.HardDriveOnly := false;
  EN.Execute;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifyStop(Handle: TObject); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.Stop;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnAssocChanged(Handle: TObject; EventFunction:TTwoParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnAssocChanged := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnAttributes(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnAttributes := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnCreate(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnCreate := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnDelete(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnDelete := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnDriveAdd(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnDriveAdd := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnDriveAddGUI(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnDriveAddGUI := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnDriveRemoved(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnDriveRemoved := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnMediaInserted(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnMediaInserted := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnMediaRemoved(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnMediaRemoved := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnMkDir(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnMkDir := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnNetShare(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnNetShare := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnNetUnshare(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnNetUnshare := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnRenameFolder(Handle: TObject; EventFunction:TTwoParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnRenameFolder := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnRenameItem(Handle: TObject; EventFunction:TTwoParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnRenameItem := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnRmDir(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnRmDir := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnServerDisconnect(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnServerDisconnect := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnUpdateDir(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnUpdateDir := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnUpdateImage(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnUpdateImage := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnUpdateItem(Handle: TObject; EventFunction:TOneParmEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnUpdateItem := EventFunction;
end;
{------------------------------------------------------------------------------}
procedure SHEventNotifySetOnEndSessionQuery(Handle: TObject; EventFunction:TEndSessionQueryEvent); stdcall;
var EN:TSHChangeNotify;
begin
  EN := TSHChangeNotify(Handle);
  EN.OnEndSessionQuery := EventFunction;
end;
{------------------------------------------------------------------------------}

exports
  SHEventNotifyCreate,
  SHEventNotifyDestroy,
  SHEventNotifyStart,
  SHEventNotifyStop,
  SHEventNotifySetOnAssocChanged,
  SHEventNotifySetOnAttributes,
  SHEventNotifySetOnCreate,
  SHEventNotifySetOnDelete,
  SHEventNotifySetOnDriveAdd,
  SHEventNotifySetOnDriveAddGUI,
  SHEventNotifySetOnDriveRemoved,
  SHEventNotifySetOnMediaInserted,
  SHEventNotifySetOnMediaRemoved,
  SHEventNotifySetOnMkDir,
  SHEventNotifySetOnNetShare,
  SHEventNotifySetOnNetUnshare,
  SHEventNotifySetOnRenameFolder,
  SHEventNotifySetOnRenameItem,
  SHEventNotifySetOnRmDir,
  SHEventNotifySetOnServerDisconnect,
  SHEventNotifySetOnUpdateDir,
  SHEventNotifySetOnUpdateImage,
  SHEventNotifySetOnUpdateItem,
  SHEventNotifySetOnEndSessionQuery;

begin
end.
