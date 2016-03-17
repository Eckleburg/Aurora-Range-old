#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel layer0 = Adafruit_NeoPixel(37, 2);
Adafruit_NeoPixel layer1 = Adafruit_NeoPixel(66, 3);
Adafruit_NeoPixel layer2 = Adafruit_NeoPixel(97, 4);
Adafruit_NeoPixel layer3 = Adafruit_NeoPixel(112, 5);
Adafruit_NeoPixel layer4 = Adafruit_NeoPixel(144, 6);
Adafruit_NeoPixel layer5 = Adafruit_NeoPixel(137, 7);
Adafruit_NeoPixel layer6 = Adafruit_NeoPixel(137, 8);
Adafruit_NeoPixel layer7 = Adafruit_NeoPixel(125, 9);
Adafruit_NeoPixel layer8 = Adafruit_NeoPixel(106, 10);
Adafruit_NeoPixel layer9 = Adafruit_NeoPixel(83, 11);
Adafruit_NeoPixel layer10 = Adafruit_NeoPixel(38, 12);
Adafruit_NeoPixel layer11 = Adafruit_NeoPixel(16, 13);

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
  
}

void showColor(int layer, uint32_t displayColor) 
{
  int i;
  
  switch(layer) {
    case 0:
      for(i=0; i<39; i++) {
        layer0.setPixelColor(i, displayColor);
      }
      layer0.show();
      break;

    case 1:
      for(i=0; i<66; i++) {
        layer1.setPixelColor(i, displayColor);
      }
     layer1.show();
      break;

    case 2:
      for(i=0; i<97; i++) {
        layer2.setPixelColor(i, displayColor);
      }
      layer2.show();
      break;

    case 3:
      for(i=0; i<113; i++) {
        layer0.setPixelColor(i, displayColor);
      }
      layer3.show();
      break;

    case 4:
      for(i=0; i<144; i++) {
        layer0.setPixelColor(i, displayColor);
      }
      layer4.show();
      break;

    case 5:
      for(i=0; i<137; i++) {
        layer5.setPixelColor(i, displayColor);
      }
      layer5.show();
      break;

    case 6:
      for(i=6; i<132; i++) {
        layer6.setPixelColor(i, displayColor);
      }
      layer0.show();
      break;

    case 7:
      for(i=0; i<126; i++) {
        layer7.setPixelColor(i, displayColor);
      }
      layer7.show();
      break;

    case 8:
      for(i=0; i<106; i++) {
        layer8.setPixelColor(i, displayColor);
      }
      layer8.show();
      break;

    case 9:
      for(i=0; i<83; i++) {
        layer9.setPixelColor(i, displayColor);
      }
      layer9.show();
      break;

    case 10:
      for(i=0; i<38; i++) {
        layer10.setPixelColor(i, displayColor);
      }
      layer10.show();
      break;

    case 11:
      for(i=0; i<16; i++) {
        layer11.setPixelColor(i, displayColor);
      }
      layer11.show();
      break;
  }
}
//
//  
//
//uint32_t Wheel(float WheelPos) {
////  WheelPos = 255 - WheelPos;
//  if(WheelPos < 85) {
//    return layer1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
//  }
//  if(WheelPos < 170) {
//    WheelPos -= 85;
//    return layer1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
//  }
//  WheelPos -= 170;
//  return layer1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
//}


