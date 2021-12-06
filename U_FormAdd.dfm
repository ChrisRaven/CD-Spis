object FormAdd: TFormAdd
  Left = 371
  Top = 321
  Width = 259
  Height = 168
  Caption = 'Dodaj'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object LabelNaped: TLabel
    Left = 16
    Top = 24
    Width = 35
    Height = 13
    Caption = 'Nap'#281'd:'
  end
  object LabelNazwa: TLabel
    Left = 16
    Top = 56
    Width = 36
    Height = 13
    Caption = 'Nazwa:'
  end
  object ComboBoxDrives: TComboBox
    Left = 72
    Top = 16
    Width = 169
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
    OnChange = ComboBoxDrivesChange
  end
  object EditCDName: TEdit
    Left = 72
    Top = 48
    Width = 169
    Height = 21
    TabOrder = 0
  end
  object ButtonOK: TBitBtn
    Left = 48
    Top = 96
    Width = 75
    Height = 25
    Caption = 'OK'
    ModalResult = 1
    TabOrder = 2
    OnClick = ButtonOKClick
  end
  object ButtonAnuluj: TBitBtn
    Left = 128
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Anuluj'
    ModalResult = 2
    TabOrder = 3
  end
end
