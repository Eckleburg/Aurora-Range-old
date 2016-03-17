#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel layer0 = Adafruit_NeoPixel(39, 2);
Adafruit_NeoPixel layer1 = Adafruit_NeoPixel(144, 3);
Adafruit_NeoPixel layer2 = Adafruit_NeoPixel(144, 4);
Adafruit_NeoPixel layer3 = Adafruit_NeoPixel(144, 5);
Adafruit_NeoPixel layer4 = Adafruit_NeoPixel(144, 6);
Adafruit_NeoPixel layer5 = Adafruit_NeoPixel(144, 7);
Adafruit_NeoPixel layer6 = Adafruit_NeoPixel(144, 8);
Adafruit_NeoPixel layer7 = Adafruit_NeoPixel(144, 9);
Adafruit_NeoPixel layer8 = Adafruit_NeoPixel(144, 10);
Adafruit_NeoPixel layer9 = Adafruit_NeoPixel(144, 11);
Adafruit_NeoPixel layer10 = Adafruit_NeoPixel(144, 12);
Adafruit_NeoPixel layer11 = Adafruit_NeoPixel(144, 13);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() 
{
  uint8_t  brightness = 255;
  
  layer0.begin();
  layer0.setBrightness(brightness);
  layer0.show();

  layer1.begin();
  layer1.setBrightness(brightness);
  layer1.show();

  layer2.begin();
  layer2.setBrightness(brightness);
  layer2.show();

  layer3.begin();
  layer3.setBrightness(brightness);
  layer3.show();

  layer4.begin();
  layer4.setBrightness(brightness);
  layer4.show();

  layer5.begin();
  layer5.setBrightness(brightness);
  layer5.show();

  layer6.begin();
  layer6.setBrightness(brightness);
  layer6.show();

  layer7.begin();
  layer7.setBrightness(brightness);
  layer7.show();

  layer8.begin();
  layer8.setBrightness(brightness);
  layer8.show();

  layer9.begin();
  layer9.setBrightness(brightness);
  layer9.show();

  layer10.begin();
  layer10.setBrightness(brightness);
  layer10.show();

  layer11.begin();
  layer11.setBrightness(brightness);
  layer11.show();
  
}

void loop() {
int start = 30, fin = 43;
uint32_t wait = 50;
  
for (int i=start; i<fin; i++)
{
 layer1.setPixelColor(i, layer0.Color(255, 0, 0));
 layer1.show();
 delay(wait);
}

for (int i=start; i<fin; i++)
{
 layer1.setPixelColor(i, layer0.Color(0, 0, 255));
 layer1.show();
 delay(wait);
}
}
