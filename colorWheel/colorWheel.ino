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

  Serial.begin(9600);

}

void loop() {



  for(int j=0; j<256*5; j++) 
  {int start, fin, dif;

      start = 0;
      fin = 37;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer0.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 66;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer1.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }
      
      fin = 97;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer2.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 112;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer3.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }
      
      fin = 144;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer4.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 137;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer5.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 137;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer6.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 125;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer7.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 106;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer8.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 83;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer9.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 38;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer10.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }

      fin = 16;
      dif = fin-start;
      for(int i=start ; i<fin; i++)
      {
        layer11.setPixelColor(i, Wheel(((-i * 256 / dif) + j - 10) & 255));
      }
      
      show();
    }
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


uint32_t Wheel(byte WheelPos) {
//  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return layer1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return layer1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return layer1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void show()
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


