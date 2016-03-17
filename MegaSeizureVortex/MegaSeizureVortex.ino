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

//for(int f=20; f>1; f--) {
//  rainbow_lowskip(f);
//}

for(int g=10; g<270; g=g+10) {
  if(g < 60)
  {
    for(int skipRepeat = 0; skipRepeat<10; skipRepeat++)
    {
      rainbow_highskip(g);
    }
  }
  else
  {
    rainbow_highskip(g);
  }
}

for(int h=270; h>2; h--) {
  if(h < 60)
  {
    for(int skipRepeat = 0; skipRepeat<5; skipRepeat++)
    {
      rainbow_highskip(h);
    }
  }
  else
  {
    rainbow_highskip(h);
  }
}

for(int e=1; e<20; e++) {
  rainbow_lowskip(e);
}

}

void rainbow_lowskip(int skip) 
{
  int i;
  int j;

  for(j=0; j<255; j++)
  {
    if (j % skip != 0)     
    {
      for(i=0; i<layer1.numPixels(); i++) 
      {        
        layer0.setPixelColor(i, Wheel((j) &255));
        layer1.setPixelColor(i, Wheel((j-20)&255));
        layer2.setPixelColor(i, Wheel((j-40)&255));
        layer3.setPixelColor(i, Wheel((j-60)&255));
        layer4.setPixelColor(i, Wheel((j-80)&255));
        layer5.setPixelColor(i, Wheel((j-100)&255));
        layer6.setPixelColor(i, Wheel((j-120)&255));
        layer7.setPixelColor(i, Wheel((j-140)&255));
        layer8.setPixelColor(i, Wheel((j-160)&255));
        layer9.setPixelColor(i, Wheel((j-180)&255));
        layer10.setPixelColor(i, Wheel((j-200)&255));
        layer11.setPixelColor(i, Wheel((j-220)&255));
        
      }

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
        

//      delay(20);
    }
  }
  
}

void rainbow_highskip(int skip) 
{
  int i;
  int j;

  for(j=0; j<255; j++)
  {
    if (j % skip == 0)     
    {
      for(i=0; i<layer1.numPixels(); i++) 
      {        
        layer0.setPixelColor(i, Wheel((j) &255));
        layer1.setPixelColor(i, Wheel((j-20)&255));
        layer2.setPixelColor(i, Wheel((j-60)&255));
        layer3.setPixelColor(i, Wheel((j-80)&255));
        layer4.setPixelColor(i, Wheel((j-100)&255));
        layer5.setPixelColor(i, Wheel((j-120)&255));
        layer6.setPixelColor(i, Wheel((j-140)&255));
        layer7.setPixelColor(i, Wheel((j-160)&255));
        layer8.setPixelColor(i, Wheel((j-180)&255));
        layer9.setPixelColor(i, Wheel((j-200)&255));
        layer10.setPixelColor(i, Wheel((j-220)&255));
        layer11.setPixelColor(i, Wheel((j-240)&255));
        
      }

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
  }
}

uint32_t Wheel(float WheelPos) {
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


