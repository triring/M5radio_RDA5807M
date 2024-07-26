#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "OriginComponent.h"
#include "ProgressBar.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void ProgressBar::setMinMax(int min, int max) {
  this->min = min;
  this->max = max;
}

void ProgressBar::setValue(int value) {
  if (this->min > value) {}
  this->value = MAX(this->min, value);
  this->value = MIN(this->max, value);
  this->update();
}

void ProgressBar::update() {
  int bar_width = 0;
  M5.Display.fillRect(this->x, this->y, this->width, this->height, this->theme->white);
  bar_width = (int)(value * this->width / this->max);
  M5.Display.fillRect(this->x, this->y, bar_width, this->height, this->theme->primary2);
  M5.Display.drawRect(this->x, this->y, this->width, this->height, this->theme->primary1);
  M5.Display.setCursor(this->x + (this->height / 4), this->y + (this->height / 4));
}
