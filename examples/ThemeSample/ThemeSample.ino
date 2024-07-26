#include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ
#include "Palette.h"
#include "Theme.h"
#include "BaseFrame.h"
#include "TitleBar.h"
#include "TextLabel.h"
#include "TextField.h"
#include "Button.h"
#include "ProgressBar.h"

/*
 * 製品名	: ボード設定
 * M5Face	: M5Core
 * M5Fire	: M5Fire
 * M5Dial	: M5StampS3
 */

String version = "0.1";
int count = 0;

Theme theme;

BaseFrame *baseframe;
TitleBar *titlebar;
// TextLabel *textlabel;
Button *btnA;
TextField *textfield;
ProgressBar *progressbar;

void setup() {
  auto cfg = M5.config();
  // M5Stack.h（M5Stack用）
  // void begin(bool LCDEnable = true, bool SDEnable = true, bool SerialEnable = true, bool I2CEnable = false);
  M5.begin(cfg);
  M5.Power.begin();  // Init Power module.  電源機構の初期化
  M5.Display.init();
  // 画面を回転させる場合は以下setRotationで設定する。
  // M5.Display.setRotation(2);
  M5.Display.startWrite();
  M5.Display.setFont(&fonts::lgfxJapanGothicP_20);
  Serial.begin(115200);
  int count = 0;
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
    // シリアルポートの接続待ち
    M5.delay(50);
    count++;
    if (count > 60) break;
  }
  String str = "LSRui Ver." + version;
  Serial.println(str);
  theme.init();

  baseframe = new BaseFrame(theme, "baseframe", 2, 0, 0, M5.Display.width(), M5.Display.height());
  baseframe->init();

  titlebar = new TitleBar(theme, "TitleBar", 1, 0, 0, 240, 40);
  titlebar->setText("Theme Sample");
  titlebar->init();
  titlebar->setHorizontalAlignment(CENTER);
  titlebar->setVerticalAlignment(CENTER);

  textfield = new TextField(theme, "field1", 2, 0, 60, 240, 60);
  textfield->init();
  textfield->setHorizontalAlignment(CENTER);
  textfield->setVerticalAlignment(CENTER);

  progressbar = new ProgressBar(theme, "progress1", 1, 0, 120, 240, 60);
  progressbar->init();
  progressbar->setMinMax(0, 16);

  btnA = new Button(theme, "buttonA", 2, 0, 180, 240, 60);
  btnA->init();
  btnA->setHorizontalAlignment(CENTER);
  btnA->setVerticalAlignment(CENTER);
  btnA->setText("Next");


  baseframe->update();
  titlebar->update();
  textfield->update();
  btnA->update();
  progressbar->update();
}

void loop() {
  //  static int index = 0;
  char buf[60];

  M5.update();  // Read the press state of the key.  读取按键 A, B, C 的状态
  int state = 0;
  if (M5.BtnA.wasPressed()) {
    btnA->setState(ON);
    btnA->setSelect(true);
    count++;
    if (count > 13) {
      count = 0;
    }
    btnA->update();
    state++;
  }
  if (M5.BtnA.wasReleased()) {
    btnA->setState(OFF);
    btnA->setSelect(false);
    btnA->update();
    state++;
  }
  if (0 == state) return;
  progressbar->setValue(count+1);
  switch (count) {
    case 0:
      SetTheme("Aqua", Palette_Aqua);
      break;
    case 1:
      SetTheme("Chameleon", Palette_Chameleon);
      break;
    case 2:
      SetTheme("Charcoal", Palette_Charcoal);
      break;
    case 3:
      SetTheme("default(swing)", Palette_default);
      break;
    case 4:
      SetTheme("Emerald", Palette_Emerald);
      break;
    case 5:
      SetTheme("green", Palette_green);
      break;
    case 6:
      SetTheme("HighContrast", Palette_HighContrast);
      break;
    case 7:
      SetTheme("PalmPilot", Palette_PalmPilot);
      break;
    case 8:
      SetTheme("reverse", Palette_reverse);
      break;
    case 9:
      SetTheme("Ruby", Palette_Ruby);
      break;
    case 10:
      SetTheme("startrek", Palette_startrek);
      break;
    case 11:
      SetTheme("startrek1", Palette_startrek1);
      break;
    case 12:
      SetTheme("startrek2", Palette_startrek2);
      break;
    case 13:
      SetTheme("startrek3", Palette_startrek3);
      break;
    default:
      count = 0;
      break;
  }
  M5.delay(100);
}

void SetTheme(String name, uint8_t colorset[][3]) {
  titlebar->setColorSet(colorset);
  textfield->setText(name);
  textfield->setColorSet(colorset);
  progressbar->setColorSet(colorset);
  btnA->setColorSet(colorset);

  titlebar->update();
  textfield->update();
  progressbar->update();
  btnA->update();
}
