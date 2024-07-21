/**
 * @file M5radio.ino
 * @author @triring
 * @brief Controlling DSP radio with M5Dial (DSPラジオをマイコンでコントロールする)
 * @version 0.2
 * @date 2024-07-20
 *
 * @Hardwares: M5Dial,Grove-I2C-FM-Receiver-v1-1(SeeedStudio)
 * @Dependent Library:
 * M5Unified: https://github.com/m5stack/M5Unified
 * RDA5807 Arduino Library: https://github.com/pu2clr/RDA5807
 */

#include "M5Dial.h"
// M5Dial.h内に取り込まれているで以下は不要
// #include <M5Unified.h>  // M5Stack全機種共通の統合ライブラリ

#include "Palette.h"
#include "Theme.h"
#include "BaseFrame.h"
#include "TitleBar.h"
#include "TextLabel.h"
#include "TextField.h"
#include "ProgressBar.h"
/*
#include "Button.h"
 */
/*
 * 製品名	: ボード設定
 * M5Face	: M5Core
 * M5Fire	: M5Fire
 * M5Dial	: M5Dial M5stack
 */

// String version = "0.1";
Theme theme;

BaseFrame *baseframe;
TitleBar *titlebar;
String str_title = "M5radio";
// 音量フレーム
TextLabel *vol_textlabel;
ProgressBar *vol_progressbar;
TextField *vol_textfield;

// broadcast station	放送局 フレーム
TextLabel *bs_name_label;
TextField *bs_freq_field;
TextLabel *bs_callsign_label;

// 放送局データを構成する構造体
struct station_t {
  const char *station_name;
  const char *callsign;
  const int frequency;
};

static const station_t station_list[] = {
  { "FM岡山", "JOVV-FM", 768 },
  { "Radio momo", "JOZZ8AD-FM", 790 },
  { "FMくらしき", "JOZZ8AC-FM", 828 },
  { "NHK FM岡山", "JOKK-FM", 887 },
  { "RSKラジオ", "JOYR", 914 }
};

// 登録済み放送局数
static constexpr const size_t station_count = sizeof(station_list) / sizeof(station_list[0]);

int volume_value = 3;
int station_index = 0;

// フレームの切替え
int frame_index = 0;

long newPosition = 0;
long oldPosition = 0;
int encode[3];

void setup() {
  auto cfg = M5.config();
  M5Dial.begin(cfg, true, false);
  M5Dial.Display.setFont(&fonts::lgfxJapanGothicP_20);

  theme.init();

  baseframe = new BaseFrame(theme, "baseframe", 2, 0, 0, M5.Display.width(), M5.Display.height());
  baseframe->init();

  titlebar = new TitleBar(theme, "TitleBar", 1, 0, 0, 240, 40);
  titlebar->setText(str_title);
  titlebar->init();
  titlebar->setHorizontalAlignment(CENTER);
  titlebar->setVerticalAlignment(CENTER);

  vol_textlabel = new TextLabel(theme, "vol_Label1", 2, 0, 40, 240, 60);
  vol_textlabel->init();
  vol_textlabel->setHorizontalAlignment(CENTER);
  vol_textlabel->setVerticalAlignment(CENTER);
  vol_textlabel->setText("音量");  // Volume

  vol_progressbar = new ProgressBar(theme, "vol_progress1", 1, 0, 100, 240, 80);
  vol_progressbar->init();
  vol_progressbar->setMinMax(0, 15);  // volumeの設定範囲 (0 - 15)
  vol_progressbar->setValue(volume_value);

  vol_textfield = new TextField(theme, "vol_Text1", 2, 0, 180, 240, 60);
  vol_textfield->init();
  vol_textfield->setHorizontalAlignment(CENTER);
  vol_textfield->setVerticalAlignment(CENTER);
  vol_textfield->setText(String(volume_value));

  // 放送局の情報
  bs_name_label = new TextLabel(theme, "Name", 2, 0, 40, 240, 60);
  bs_name_label->init();
  bs_name_label->setHorizontalAlignment(CENTER);
  bs_name_label->setVerticalAlignment(CENTER);

  bs_freq_field = new TextField(theme, "Freq", 3, 0, 100, 240, 80);
  bs_freq_field->init();
  bs_freq_field->setHorizontalAlignment(CENTER);
  bs_freq_field->setVerticalAlignment(CENTER);

  bs_callsign_label = new TextLabel(theme, "Callsign", 1, 0, 180, 240, 60);
  bs_callsign_label->init();
  bs_callsign_label->setHorizontalAlignment(CENTER);
  bs_callsign_label->setVerticalAlignment(CENTER);

  bs_name_label->setText(station_list[0].station_name);
// String str;
  char str[64];
  sprintf(str, "%3.1f", ((float)station_list[0].frequency / 10));
  bs_freq_field->setText(str);
  bs_callsign_label->setText(station_list[0].callsign);

  baseframe->update();
  titlebar->update();

  vol_textlabel->update();
  vol_textfield->update();
  vol_progressbar->update();

  bs_name_label->update();
  bs_callsign_label->update();
  bs_freq_field->update();

  M5Dial.Encoder.readAndReset();
  newPosition = 0;
  oldPosition = 0;
  encode[0] = 0;
  encode[1] = 0;
  encode[2] = 0;
}

void drawFrame_BroadcastStation(int rotation_direction) {
  char str[64];
  station_index += rotation_direction;
  if (station_index >= station_count) {
    station_index = 0;
  }
  if (-1 >= station_index) {
    station_index = station_count - 1;
  }
  Serial.print(station_index);
  Serial.print(",");
  Serial.println(rotation_direction);
  bs_name_label->setText(station_list[station_index].station_name);
  sprintf(str, "%3.1f", ((float)station_list[station_index].frequency / 10));
  bs_freq_field->setText(str);
  bs_callsign_label->setText(station_list[station_index].callsign);

  bs_name_label->update();
  bs_freq_field->update();
  bs_callsign_label->update();
}

void drawFrame_Volume(int rotation_direction) {
  
    volume_value += rotation_direction;
    if (volume_value > 15) {
      volume_value = 15;
    }
    if (0 > volume_value) {
      volume_value = 0;
    }
    Serial.print(volume_value);
    Serial.print(",");
    Serial.println(rotation_direction);
    vol_textlabel->setText("音量");  // Volume
    vol_textfield->setText(String(volume_value));
    vol_textfield->update();
    vol_progressbar->setValue(volume_value);
    vol_progressbar->update();
}

void loop() {
  M5Dial.update();
  newPosition = M5Dial.Encoder.read();
  if (newPosition != oldPosition) {
    M5Dial.Speaker.tone(1980, 20);
    // 以下はチャタリング防止のために、 
    encode[2] = encode[1];
    encode[1] = encode[0];
    encode[0] = newPosition - oldPosition;
    int sum = encode[0] + encode[1] + encode[2];
    int Rotation_direction = 0;
    if (      sum >= 2) Rotation_direction =  1;
    if (-2 >= sum     ) Rotation_direction = -1;
    if (Rotation_direction == 0) return;
    switch(frame_index) {
      case 0 : drawFrame_BroadcastStation(Rotation_direction); break;
      case 1 : drawFrame_Volume(Rotation_direction); break;
      default : break;
    }
    oldPosition = newPosition;
  }
  if (M5Dial.BtnA.wasPressed()) {
    M5Dial.Speaker.tone(1980, 100);
    M5Dial.Encoder.readAndReset();
    oldPosition = 0;
    newPosition = 0;
    frame_index++;
    if (frame_index >= 2) {
      frame_index = 0;
    }
    switch(frame_index) {
      case 0 : drawFrame_BroadcastStation(0); break;
      case 1 : drawFrame_Volume(0); break;
      default : break;
    }
  }
  if (M5Dial.BtnA.pressedFor(5000)) {
    M5Dial.Encoder.write(100);
  }
  delay(100);
}
