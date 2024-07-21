#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "OriginComponent.h"
#include "Button.h"

void Button::setText(String text) {
  this->text = text;
  this->update();
}

void Button::setState(int state) {
  this->state = state;
}

int  Button::getSelect() {
  return this->state;
}

void Button::setSelect(bool select) {
  this->select = select;
}

bool  Button::isSelect() {
  return this->select;
}

void Button::update() {
  if (this->state == ON) {
    M5.Display.fillRect(this->x, this->y, this->width, this->height, this->theme->secondary2);
    M5.Display.setTextColor(this->theme->black, this->theme->secondary2);
  } else {
    M5.Display.fillRect(this->x, this->y, this->width, this->height, this->theme->secondary3);
    M5.Display.setTextColor(this->theme->black, this->theme->secondary3);
  }
  if (this->select == true) {
    M5.Display.drawRect(this->x  , this->y  , this->width-1, this->height-1, this->theme->primary1);
    M5.Display.drawRect(this->x+1, this->y+1, this->width-2, this->height-2, this->theme->white);
  } else {
    M5.Display.drawRect(this->x  , this->y  , this->width-1, this->height-1, this->theme->secondary1);
    M5.Display.drawRect(this->x+1, this->y+1, this->width-2, this->height-2, this->theme->white);
    M5.Display.drawRect(this->x  , this->y  , this->width  , this->height  , this->theme->white);
  }

  M5.Display.setTextSize(this->theme->getFontSize());
  M5.Display.setCursor(this->x + calcXoffset(this->text)+1, this->y + calcYoffset());
  M5.Display.print(text);
}
