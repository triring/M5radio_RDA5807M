#ifndef _ORIGINCOMPONENT_H_
#define _ORIGINCOMPONENT_H_

#include "Theme.h"

// 全クラスのベースとなるクラス
// 位置と大きさを規定する。
// クラス宣言
class OriginComponent {
public:
  OriginComponent(Theme theme, String name, int fontSize, int x, int y, int width, int height);
  String name;
  String text;
  int x;
  int y;
  int width;
  int height;
  int char_width;      // 1文字の幅
  int char_height;     // 1文字の高さ
  int text_hor_align;  // 文字の水平配置
  int text_vert_align; // 文字の垂直配置
  Theme *theme;

// 文字列の配置等を設定するための定数
// javax.swing.SwingConstantsの定数フィールド値を参考にした。
#define HORIZONTAL  0
#define VERTICAL    1

#define CENTER      0
#define TOP         1
#define LEFT        2
#define BOTTOM      3
#define RIGHT       4

#define NORTH       1
#define NORTH_EAST  2
#define EAST        3
#define SOUTH_EAST  4
#define SOUTH       5
#define SOUTH_WEST  6
#define WEST        7
#define NORTH_WEST  8

#define LEADING    10
#define TRAILING   11
#define NEXT       12
#define PREVIOUS   13

// フォントサイズとそのフォントサイズを設定した時のフォント1文字の幅と高さ
const int fontdata[9][2] = {
  //	char_width		char_height 		TextSize
  { 0, 0 },      // font size =  	0
  { 20, 24 },    // font size =  	1 30 3
  { 40, 48 },    // font size =  	2 60 11
  { 60, 72 },    // font size =  	3 80 4
  { 80, 96 },    // font size =  	4 120 12
  { 100, 120 },  // font size =  	5 140
  { 120, 144 },  // font size =  	6 160
  { 140, 168 },  // font size =  	7 180
  { 160, 192 }   // font size =  	8 200
};
  
  // private:
  void init();
  void setFontSize(int fontSize);
  void setColorSet(uint8_t colorset[][3]);
  void setHorizontalAlignment(int align); // テキストの水平方向配置を設定する
  int getHorizontalAlignment(); // テキストの水平方向配置を取得する
  void setVerticalAlignment(int align); // テキストの垂直方向配置を設定する
  int getVerticalAlignment(); // テキストの垂直方向配置を取得する

  void update();
  int getFontWidth();
  int getFontHeight();
  int calcXoffset(String text); // 左、中、右の文字揃え
  int calcYoffset();  // 上下の文字揃え　真ん中に合わせるだけ
};

#endif  // _ORIGINCOMPONENT_H_