//---------------------------------------------------------------------------
#include <windows.h>
#include <vcl.h>

#pragma hdrstop

#include "U_IconFromExt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int SmallIconFromFile(AnsiString FileName, TImageList* ImageList, int Index)
{
  int IconCount = ExtractIconEx(FileName.c_str(), -1, NULL, NULL, 0);
  if (IconCount < 0 || Index >= IconCount) return -1;
  if (!ImageList) return IconCount;

  Graphics::TIcon* Icon = new Graphics::TIcon();
  HICON hIcon = NULL;
  ExtractIconEx(FileName.c_str(), Index, &hIcon, NULL, 1);
  Icon->Handle = hIcon;
  int Ret = ImageList->AddIcon(Icon);
  delete Icon;

  return Ret;
}
//---------------------------------------------------------------------------
int LargeIconFromFile(AnsiString FileName, TImageList* ImageList, int Index)
{
  int IconCount = ExtractIconEx(FileName.c_str(), -1, NULL, NULL, 0);
  if (IconCount < 0 || Index >= IconCount) return -1;
  if (!ImageList) return IconCount;

  Graphics::TIcon* Icon = new Graphics::TIcon();
  HICON hIcon = NULL;
  ExtractIconEx(FileName.c_str(), Index, NULL, &hIcon, 1);
  Icon->Handle = hIcon;
  int Ret = ImageList->AddIcon(Icon);
  delete Icon;

  return Ret;
}
//---------------------------------------------------------------------------
int SmallIconFromExt(AnsiString FileExt, TImageList* ImageList)
{
  if (FileExt[1] != '.') FileExt = "." + FileExt;

  SHFILEINFO Info;
  if (!SHGetFileInfo(FileExt.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_USEFILEATTRIBUTES | SHGFI_SMALLICON)) return -1;

  Graphics::TIcon* Icon = new Graphics::TIcon();
  Icon->Handle = Info.hIcon;
  int Ret = ImageList->AddIcon(Icon);
  delete Icon;

  return Ret;
}
//---------------------------------------------------------------------------
int LargeIconFromExt(AnsiString FileExt, TImageList* ImageList)
{
  if (FileExt[1] != '.') FileExt = "." + FileExt;

  SHFILEINFO Info;
  if (!SHGetFileInfo(FileExt.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_USEFILEATTRIBUTES | SHGFI_LARGEICON)) return -1;

  Graphics::TIcon* Icon = new Graphics::TIcon();
  Icon->Handle = Info.hIcon;
  int Ret = ImageList->AddIcon(Icon);
  delete Icon;

  return Ret;
}
//---------------------------------------------------------------------------
int IconIndexFromFile(AnsiString FileName, TImageList* ImageListSmall, TImageList* ImageListLarge)
{
  SHFILEINFO Info;
  int HandleSmall = (int)SHGetFileInfo(FileName.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_SMALLICON | SHGFI_SYSICONINDEX);
  if (HandleSmall)
    if (ImageListSmall->Handle != HandleSmall) ImageListSmall->Handle = HandleSmall;

  int HandleLarge = (int)SHGetFileInfo(FileName.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_SYSICONINDEX);
  if (HandleLarge)
    if (ImageListLarge->Handle != HandleLarge) ImageListLarge->Handle = HandleLarge;

  return Info.iIcon;
}
//---------------------------------------------------------------------------
int IconIndexFromExt(AnsiString FileExt, TImageList* ImageListSmall, TImageList* ImageListLarge)
{
  if (FileExt == "")     FileExt = "*";
  if (FileExt[1] != '.') FileExt = "." + FileExt;

  SHFILEINFO Info;
  int HandleSmall = (int)SHGetFileInfo(FileExt.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_USEFILEATTRIBUTES | SHGFI_SMALLICON | SHGFI_SYSICONINDEX);
  if (HandleSmall)
    if (ImageListSmall->Handle != HandleSmall) ImageListSmall->Handle = HandleSmall;

  int HandleLarge = (int)SHGetFileInfo(FileExt.c_str(), NULL, &Info, sizeof(SHFILEINFO), SHGFI_ICON | SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX);
  if (HandleLarge)
    if (ImageListLarge->Handle != HandleLarge) ImageListLarge->Handle = HandleLarge;

  return Info.iIcon;
}
//---------------------------------------------------------------------------

