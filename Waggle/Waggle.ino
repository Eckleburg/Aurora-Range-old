#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel layer0 = Adafruit_NeoPixel(144, 2);
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

void setup() 
{
  uint8_t  brightness = 128;
  
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
 waggle(30, layer0.Color(255, 255, 0), layer0.Color(102, 0, 51));
 waggle(30, layer0.Color(255, 255, 0), layer0.Color(0, 153, 76));
 waggle(30, layer0.Color(255, 255, 0), layer0.Color(52, 89, 149));
 waggle(30, layer0.Color(255, 255, 0), layer0.Color(251, 77, 61));
 waggle(30, layer0.Color(255, 255, 0), layer0.Color(0, 0, 0)); 
 waggle(30, layer0.Color(255, 255, 0), layer0.Color(0, 0, 0));
  
 waggle(30, layer0.Color(0, 0, 0), layer0.Color(102, 0, 51));
 waggle(30, layer0.Color(0, 0, 0), layer0.Color(0, 153, 76));
 waggle(30, layer0.Color(0, 0, 0), layer0.Color(52, 89, 149));
 waggle(30, layer0.Color(0, 0, 0), layer0.Color(251, 77, 61));
// waggle(30, layer0.Color(0, 0, 0), layer0.Color(0, 0, 0)); 
// waggle(30, layer0.Color(0, 0, 0), layer0.Color(0, 0, 0));
}



void waggle(int scale, uint32_t wColor, uint32_t fillColor)
{
  for(int j=0; j<scale; j++)
  { 
    for(int i=0; i<=144; i=i+scale)
    {
      for(int l=0; l<=11; l++)
      {
        assignPixel(l, i+j, wColor);
      }
    }
    showColors();
    delay(40);
  

  for(int i=0; i<=144; i=i+scale)
    {
      for(int l=0; l<=11; l++)
      {
        assignPixel(l, i+j, fillColor);
      }
    }
  }
  
//  for(int j=scale; j>0; j--)
//  { 
//    for(int i=0; i<=144; i=i+scale)
//    {
//      for(int l=0; l<=11; l++)
//      {
//        assignPixel(l, i+j, wColor);
//      }
//    }
//    showColors();
//    delay(40);
  

//  for(int i=0; i<=144; i=i+scale)
//    {
//      for(int l=0; l<=11; l++)
//      {
//        assignPixel(l, i+j, fillColor);
//      }
//    }
//  }
}
void assignPixel(int layer, int pixel, uint32_t displayColor) 
{
  int i;
  
  switch(layer) {
    case 0:
        layer0.setPixelColor(pixel, displayColor);
      break;

    case 1:
        layer1.setPixelColor(pixel, displayColor);
      break;

    case 2:
        layer2.setPixelColor(pixel, displayColor);
      break;

    case 3:
        layer3.setPixelColor(pixel, displayColor);
      break;

    case 4:
        layer4.setPixelColor(pixel, displayColor);
      break;

    case 5:
        layer5.setPixelColor(pixel, displayColor);
      break;

    case 6:
        layer6.setPixelColor(pixel, displayColor);
      break;

    case 7:
        layer7.setPixelColor(pixel, displayColor);
      break;

    case 8:
        layer8.setPixelColor(pixel, displayColor);
      break;

    case 9:
        layer9.setPixelColor(pixel, displayColor);
      break;

    case 10:
        layer10.setPixelColor(pixel, displayColor);
      break;

    case 11:
        layer11.setPixelColor(pixel, displayColor);
      break;
      
    default:
      break;
  }
}

void showColors()
{
  layer0.show();
  layer1.show();
  layer2.show();
  layer3.show();
  layer4.show();
  layer5.show();
  layer6.show();
  layer7.show();
  layer8.show();
  layer9.show();
  layer10.show();
  layer11.show();
}



