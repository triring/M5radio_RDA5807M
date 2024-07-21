#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "Theme.h"
#include "OriginComponent.h"

// 全クラスのベースとなるクラス
OriginComponent::OriginComponent(Theme parent_theme, String name, int fontSize, int x, int y, int width, int height) {
  this->name = name;
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->text_hor_align  = LEFT;
  this->text_vert_align = CENTER;
  
  this->theme = new Theme();
  this->theme->name = parent_theme.name;
  this->theme->fontSize = parent_theme.fontSize;
  // black & white
  this->theme->white = M5.Display.color565(255, 255, 255);
  this->theme->black = M5.Display.color565(0, 0, 0);
  // primary color
  this->theme->primary1 = M5.Display.color565(102, 102, 153);
  this->theme->primary2 = M5.Display.color565(153, 153, 204);
  this->theme->primary3 = M5.Display.color565(204, 204, 255);
  // secondary color
  this->theme->secondary1 = M5.Display.color565(102, 102, 102);
  this->theme->secondary2 = M5.Display.color565(153, 153, 153);
  this->theme->secondary3 = M5.Display.color565(204, 204, 204);
  setFontSize(fontSize);  
}

void OriginComponent::init() {
  M5.Display.setTextSize(this->theme->fontSize);
  M5.Display.setTextColor(this->theme->black, this->theme->secondary3);
  M5.Display.clear(this->theme->secondary3);
  Serial.print(this->width);
  Serial.print(",");
  Serial.println(this->height);
}

void OriginComponent::update() {
}

void OriginComponent::setFontSize(int fontSize) {
  this->theme->setFontSize(fontSize);
  this->char_width = fontdata[this->theme->getFontSize()][0];
  this->char_height = fontdata[this->theme->getFontSize()][1];
}

void OriginComponent::setColorSet(uint8_t colorset[][3]) {
  this->theme->setColorSet(colorset);
}

// テキストの水平方向配置を設定する
void OriginComponent::setHorizontalAlignment(int align) {
  this->text_hor_align = align;
}

// テキストの水平方向配置を取得する
int OriginComponent::getHorizontalAlignment() {
  return this->text_hor_align;
};

// テキストの垂直方向配置を設定する
void OriginComponent::setVerticalAlignment(int align) {
  this->text_vert_align = align;
}

// テキストの垂直方向配置を取得する
int OriginComponent::getVerticalAlignment() {
  return this->text_vert_align;
};

// 左、中、右の文字揃え
int OriginComponent::calcXoffset(String text) {
  String printStr = "";
  printStr += this->name;
  printStr += "\n";   
  int offset = 0;
  switch (text_hor_align) {
    case LEFT:    // 左寄せ
      offset = (int)(M5.Display.textWidth("A") / 2);
      printStr += "LEFT  ,";
      break;
    case CENTER:  // 中央揃え
      offset = (int)((this->width - M5.Display.textWidth(text)) / 2);
      printStr = "CENTER,";
      break;
    case RIGHT:   // 右寄せ
      offset = this->width - M5.Display.textWidth(text) - (int)(M5.Display.textWidth("A") / 2);
      printStr = "RIGHT ,";
      break;
    default:
      offset = (int)(M5.Display.textWidth("A") / 2);
      printStr = "Unkown,";
      break;
  }
  printStr += String("Xoffset:") + text.length() + "," + String(offset);
// Serial.println(printStr);
  return offset;
}

// 上、中、下の文字揃え
int OriginComponent::calcYoffset() {
  String printStr = "";
  int offset = 0;
  switch (text_vert_align) {
    case TOP   :    // 上端
      offset = (int)(M5.Display.fontHeight() / 4);
      printStr = "TOP   ,";
      break;
    case CENTER:  // 中央
      offset = (int)((this->height - M5.Display.fontHeight()) / 2);
      printStr = "CENTER,";
      break;
    case BOTTOM:   // 下端
      offset = this->height - M5.Display.fontHeight() - (int)(M5.Display.fontHeight() / 4);
      printStr = "BOTTOM,";
      break;
    default:
      offset = (int)(M5.Display.fontHeight() / 4);
      printStr = "Unkown,";
      break;
  }
  printStr += String("Yoffset:") + String(offset);
// Serial.println(printStr);
  return offset;
}
