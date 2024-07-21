#ifndef _THEME_H_
#define _THEME_H_

// 全クラスのベースとなるクラス
// クラス宣言
class Theme {
public:
  // Resource strings for default Theme
  String name = "default";
  // font
  int fontSize = 3;
  // black & white
  uint16_t white;
  uint16_t black;
  // primary color
  uint16_t primary1;
  uint16_t primary2;
  uint16_t primary3;
  // secondary color
  uint16_t secondary1;
  uint16_t secondary2;
  uint16_t secondary3;
  Theme();
  void init();
  void setColorSet(uint8_t colorset[][3]);
  void setFontSize(int fontSize);
  int getFontSize();
};

#endif  // _THEME_H_