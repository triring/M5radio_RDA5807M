#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "OriginComponent.h"
#include "TextField.h"

void TextField::setText(String text) {
  this->text = text;
  this->update();
}

void TextField::update() {
  M5.Display.fillRect(this->x, this->y, this->width, this->height, this->theme->white);
  M5.Display.drawRect(this->x  , this->y  , this->width-1, this->height-1, this->theme->secondary1);
  M5.Display.drawRect(this->x-1, this->y-1, this->width  , this->height  , this->theme->white);
  M5.Display.setTextSize(this->theme->getFontSize());
  M5.Display.setCursor(this->x + calcXoffset(this->text), this->y + calcYoffset());
  M5.Display.setTextColor(this->theme->black, this->theme->white);
  M5.Display.print(text);
}
