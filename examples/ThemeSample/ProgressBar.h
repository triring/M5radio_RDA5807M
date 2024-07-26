#ifndef _PROGRESSBAR_H_
#define _PROGRESSBAR_H_

#include "OriginComponent.h"

// クラス宣言
class ProgressBar : public OriginComponent {
public:
  ProgressBar(Theme theme, String name, int fontSize, int x, int y, int width, int height)
    : OriginComponent(theme, name, fontSize, x, y, width, height) {}
  int value = 0;
  int min = 0;
  int max = 100;
  void setMinMax(int min, int max);
  void setValue(int value);
  void update();
};

#endif  // _PROGRESSBAR_H_