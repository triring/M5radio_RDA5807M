#ifndef _PALETTE_H_
#define _PALETTE_H_

uint8_t Palette_Aqua[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  { 102, 153, 153 },  // primary1
  { 128, 192, 192 },  // primary2
  { 159, 235, 235 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 153, 153, 153 },  // secondary2
  { 204, 204, 204 }   // secondary3
};

uint8_t Palette_Chameleon[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  {   0,   0, 255 },  // primary1
  {   0, 255,   0 },  // primary2
  { 255,   0,   0 },  // primary3
  {   0, 255, 255 },  // secondary1
  { 127, 127,   0 },  // secondary2
  { 255,   0, 127 }   // secondary3
};

uint8_t Palette_Charcoal[8][3] = {
  {   0,   0,   0 },  // white
  { 222, 222, 222 },  // black
  {  66,  33,  66 },  // primary1
  {  90,  86,  99 },  // primary2
  {  99,  99,  99 },  // primary3
  {   0,   0,   0 },  // secondary1
  {  51,  51,  51 },  // secondary2
  { 102, 102, 102 }   // secondary3
};

uint8_t Palette_default[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  { 102, 102, 153 },  // primary1
  { 153, 153, 204 },  // primary2
  { 204, 204, 255 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 153, 153, 153 },  // secondary2
  { 204, 204, 204 }   // secondary3
};

uint8_t Palette_Emerald[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  {  51, 142,  71 },  // primary1
  { 102, 193, 122 },  // primary2
  { 153, 244, 173 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 153, 153, 153 },  // secondary2
  { 204, 204, 204 }   // secondary3
};

uint8_t Palette_green[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  {  64, 128, 128 },  // primary1
  {  95, 153, 153 },  // primary2
  { 147, 204, 204 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 153, 153, 153 },  // secondary2
  { 204, 204, 204 }   // secondary3
};

uint8_t Palette_HighContrast[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  {   0,   0,   0 },  // primary1
  { 204, 204, 204 },  // primary2
  { 255, 255, 255 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 204, 204, 204 },  // secondary2
  { 255, 255, 255 }   // secondary3
};

uint8_t Palette_PalmPilot[8][3] = {
  { 192, 255, 128 },  // white
  {   0,   0,   0 },  // black
  {  64, 128, 128 },  // primary1
  {  95, 153, 153 },  // primary2
  { 147, 204, 204 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 153, 153, 153 },  // secondary2
  { 204, 204, 204 }   // secondary3
};

uint8_t Palette_reverse[8][3] = {
  {   0,   0,   0 },  // white
  { 255, 255, 255 },  // black
  { 255, 255, 255 },  // primary1
  { 102, 102, 102 },  // primary2
  { 204, 204, 204 },  // primary3
  { 255, 255, 255 },  // secondary1
  { 204, 204, 204 },  // secondary2
  { 102, 102, 102 }   // secondary3
};

uint8_t Palette_Ruby[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  {  80,  10,  22 },  // primary1
  { 193,  10,  44 },  // primary2
  { 244,  10,  66 },  // primary3
  { 102, 102, 102 },  // secondary1
  { 153, 153, 153 },  // secondary2
  { 204, 204, 204 }   // secondary3
};

// LCARS Standard Colorsを参考にした。
// http://www.lcarsmania.com/
// D:\nbdir\LCARS\color_work\lcars_colors.ods
uint8_t Palette_startrek[8][3] = {
  { 104, 104, 104 },  // white
  { 255, 160,   0 },  // black
  { 153, 153, 204 },  // primary1 (0,0,0)
  { 156, 156, 255 },  // primary2
  { 102, 160, 255 },  // primary3
  { 102,   0, 204 },  // secondary1
  { 255, 204,   0 },  // secondary2
  {  66,  33,  66 }   // secondary3 (0,0,0)
};

// LCARS Standard Colorsを参考にした。
// http://www.lcarsmania.com/
// D:\nbdir\LCARS\color_work\lcars_colors.ods
uint8_t Palette_startrek1[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  { 153, 153, 204 },  // primary1
  { 204, 153, 204 },  // primary2
  { 153, 153, 255 },  // primary3
  { 255, 102,   0 },  // secondary1
  { 255, 153, 102 },  // secondary2
  { 255, 204, 153 }   // secondary3
};

// LCARS Standard Colorsを参考にした。
// http://www.lcarsmania.com/
// D:\nbdir\LCARS\color_work\lcars_colors.ods
uint8_t Palette_startrek2[8][3] = {
  { 255, 255, 255 },  // white
  {   0,   0,   0 },  // black
  { 255, 102,   0 },  // primary1
  { 255, 153, 102 },  // primary2
  { 255, 204, 153 },  // primary3
  { 153, 153, 204 },  // secondary1
  { 204, 153, 204 },  // secondary2
  { 153, 153, 255 }   // secondary3
};

// LCARS Standard Colorsを参考にした。
// http://www.lcarsmania.com/
// D:\nbdir\LCARS\color_work\lcars_colors.ods
uint8_t Palette_startrek3[8][3] = {
  { 255, 204, 153 },  // white
  {   0,   0,   0 },  // black
  {   0, 160, 255 },  // primary1
  {  96,   0, 204 },  // primary2
  { 156, 156, 255 },  // primary3
  { 255, 102,   0 },  // secondary1
  { 255, 153, 102 },  // secondary2
  { 153, 153, 204 }   // secondary3
};

#endif  // _PALETTE_H_