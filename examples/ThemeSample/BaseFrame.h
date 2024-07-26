#ifndef _BASEFRAME_H_
#define _BASEFRAME_H_

#include "OriginComponent.h"
// クラス宣言
class BaseFrame : public OriginComponent {
public:
  BaseFrame(Theme theme, String name, int fontSize, int x, int y, int width, int height)
    : OriginComponent(theme, name, fontSize, x, y, width, height) {}
  void update();
};

#endif  // _BASEFRAME_H_