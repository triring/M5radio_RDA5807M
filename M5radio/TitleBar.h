#ifndef _TITLEBAR_H_
#define _TITLEBAR_H_

#include "OriginComponent.h"
// クラス宣言
class TitleBar : public OriginComponent {
public:
  TitleBar(Theme theme, String name, int fontSize, int x, int y, int width, int height)
    : OriginComponent(theme, name, fontSize, x, y, width, height) {}
// String text;
  void setText(String text);
  void update();
};

#endif  //_TITLEBAR_H_