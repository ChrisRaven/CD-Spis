object FormSearch: TFormSearch
  Left = 347
  Top = 252
  Width = 365
  Height = 272
  Caption = 'Szukaj'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelZnajdz: TLabel
    Left = 8
    Top = 8
    Width = 35
    Height = 13
    Caption = 'Znajd'#378':'
  end
  object EditSearch: TEdit
    Left = 56
    Top = 8
    Width = 201
    Height = 21
    TabOrder = 0
  end
  object ButtonStart: TButton
    Left = 272
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Start'
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 40
    Width = 345
    Height = 73
    Caption = 'Opcje'
    TabOrder = 2
    object RadioGroup1: TRadioGroup
      Left = 168
      Top = 0
      Width = 177
      Height = 73
      ItemIndex = 0
      Items.Strings = (
        'normalne'
        'I'
        'LUB')
      TabOrder = 0
    end
    object CheckBoxFoldery: TCheckBox
      Left = 16
      Top = 40
      Width = 97
      Height = 17
      Caption = 'Foldery'
      Checked = True
      State = cbChecked
      TabOrder = 1
    end
    object CheckBoxPliki: TCheckBox
      Left = 16
      Top = 24
      Width = 97
      Height = 17
      Caption = 'Pliki'
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
  end
  object ListView1: TListView
    Left = 0
    Top = 120
    Width = 353
    Height = 96
    Columns = <
      item
        Caption = 'Nazwa'
      end
      item
        Caption = 'Typ'
      end
      item
        Caption = 'Rozmiar'
      end
      item
        Caption = 'Data'
      end
      item
        Caption = 'Atrybuty'
      end>
    TabOrder = 3
    ViewStyle = vsReport
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 219
    Width = 357
    Height = 19
    Panels = <>
    SimplePanel = False
  end
end
