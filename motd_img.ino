#include "Adafruit_ThinkInk.h"
#include "image.h"

#define EPD_CS A0
#define EPD_DC A1
#define SRAM_CS -1
#define EPD_RESET A2
#define EPD_BUSY A3

ThinkInk_154_Mono_D67 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    delay(10);
  }
  display.begin(THINKINK_MONO);

  display.clearBuffer();

  for (uint8_t x = 0; x < 200; ++x) {
    for (uint8_t y = 0; y < 200; ++y) {
      uint16_t byteidx = (x + y * 200) / 8;
      uint16_t bitidx = (x + y * 200) % 8;
      uint8_t byte = image[byteidx];
      uint8_t bit = byte & (1 << bitidx);
      display.drawPixel(x, y, bit ? 1 : 0);
    }
  }

  display.display();
}

void loop()
{
  delay(10);
}
