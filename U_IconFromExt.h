//---------------------------------------------------------------------------
#ifndef U_IconFromExtH
#define U_IconFromExtH
//---------------------------------------------------------------------------
// To extract icons from file by file name, use the following functions:
int SmallIconFromFile(AnsiString FileName, TImageList* ImageList, int Index = 0);
int LargeIconFromFile(AnsiString FileName, TImageList* ImageList, int Index = 0);
// Note!
// - if ImageList is NULL, the function returns the number of icons
// - if the function fails, the return value is -1
// - if the function succeeds, the return value is the index of icon in ImageList
//---------------------------------------------------------------------------
// To extract icons by file extension, use the following functions:
int SmallIconFromExt(AnsiString FileExt, TImageList* ImageList);
int LargeIconFromExt(AnsiString FileExt, TImageList* ImageList);
int IconIndexFromExt(AnsiString FileExt, TImageList* ImageListSmall, TImageList* ImageListLarge);
int IconIndexFromFile(AnsiString FileName, TImageList* ImageListSmall, TImageList* ImageListLarge);
// Note!
// - if the function fails, the return value is -1
// - if the function succeeds, the return value is the index of icon in ImageList
//---------------------------------------------------------------------------
#endif
