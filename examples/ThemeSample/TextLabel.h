#ifndef _TEXTLABEL_H_
#define _TEXTLABEL_H_


#include "OriginComponent.h"
// クラス宣言

class TextLabel : public OriginComponent {
public:
  TextLabel(Theme theme, String name, int fontSize, int x, int y, int width, int height)
    : OriginComponent(theme, name, fontSize, x, y, width, height) {}
// String text;
  void setText(String text);
  void update();
};

#endif  // _TEXTLABEL_H_