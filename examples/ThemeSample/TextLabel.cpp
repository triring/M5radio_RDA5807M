#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "OriginComponent.h"
#include "TextLabel.h"

void TextLabel::setText(String text) {
  this->text = text;
  this->update();
}

void TextLabel::update() {
  M5.Display.fillRect(this->x, this->y, this->width, this->height, this->theme->secondary3);
  M5.Display.drawRect(this->x, this->y, this->width, this->height, this->theme->secondary1);
  M5.Display.setTextSize(this->theme->getFontSize());
  M5.Display.setCursor(this->x + calcXoffset(this->text), this->y + calcYoffset());
  M5.Display.setTextColor(this->theme->primary1, this->theme->secondary3);
  M5.Display.print(text);
}
