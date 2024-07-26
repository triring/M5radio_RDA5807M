#ifndef _TEXTFIELD_H_
#define _TEXTFIELD_H_


#include "OriginComponent.h"
// クラス宣言

class TextField : public OriginComponent {
public:
  TextField(Theme theme, String name, int fontSize, int x, int y, int width, int height)
    : OriginComponent(theme, name, fontSize, x, y, width, height) {}
// String text;
  void setText(String text);
  void update();
};

#endif  // _TEXTFIELD_H_