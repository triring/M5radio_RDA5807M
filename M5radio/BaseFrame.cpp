#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "OriginComponent.h"
#include "BaseFrame.h"

void BaseFrame::update() {
  M5.Display.clear(this->theme->secondary3);
}
