#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "Theme.h"

Theme::Theme() {
  this->name = "default";
  fontSize = 3;
  // black & white
  this->white = M5.Display.color565(255, 255, 255);
  this->black = M5.Display.color565(0, 0, 0);
  // primary color
  this->primary1 = M5.Display.color565(102, 102, 153);
  this->primary2 = M5.Display.color565(153, 153, 204);
  this->primary3 = M5.Display.color565(204, 204, 255);
  // secondary color
  this->secondary1 = M5.Display.color565(102, 102, 102);
  this->secondary2 = M5.Display.color565(153, 153, 153);
  this->secondary3 = M5.Display.color565(204, 204, 204);
}

void Theme::init() {
  M5.Display.setTextSize(this->fontSize);
  M5.Display.setTextColor(this->black, this->secondary3);
  M5.Display.clear(this->secondary3);
  M5.Display.setCursor(8, 8);
}

void Theme::setFontSize(int fontSize) {
  this->fontSize = fontSize;
}

int Theme::getFontSize() {
  return this->fontSize;
}

void Theme::setColorSet(uint8_t colorset[][3]) {
  // black $ white
  this->white = M5.Display.color565(colorset[0][0], colorset[0][1], colorset[0][2]);
  this->black = M5.Display.color565(colorset[1][0], colorset[1][1], colorset[1][2]);
  // primary color
  this->primary1 = M5.Display.color565(colorset[2][0], colorset[2][1], colorset[2][2]);
  this->primary2 = M5.Display.color565(colorset[3][0], colorset[3][1], colorset[3][2]);
  this->primary3 = M5.Display.color565(colorset[4][0], colorset[4][1], colorset[4][2]);
  // secondary color
  this->secondary1 = M5.Display.color565(colorset[5][0], colorset[5][1], colorset[5][2]);
  this->secondary2 = M5.Display.color565(colorset[6][0], colorset[6][1], colorset[6][2]);
  this->secondary3 = M5.Display.color565(colorset[7][0], colorset[7][1], colorset[7][2]);
}

