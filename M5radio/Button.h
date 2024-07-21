#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "OriginComponent.h"

#define ON 1
#define OFF 0

// クラス宣言

class Button : public OriginComponent {
public:
  Button(Theme theme, String name, int fontSize, int x, int y, int width, int height)
    : OriginComponent(theme, name, fontSize, x, y, width, height) {}
//  String text;
  int  state = 0;
  bool select = false;
  void setState(int state);
  int  getSelect();
  void setSelect(bool select);
  bool isSelect();
  void setText(String text);
  void update();
};

#endif  // _BUTTON_H_