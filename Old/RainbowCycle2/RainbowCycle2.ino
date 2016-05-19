#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 3
#define PIN2 9
#define PIN3 10

#define PIN4 1

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(11, PIN1);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(20, PIN2);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(29, PIN3);

Adafruit_NeoPixel sign = Adafruit_NeoPixel(37, PIN4);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() 
{
  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
}

void loop() {
  for(int skipCounter = 0; skipCounter < 280; skipCounter++)
  {
    rainbowCycle(skipCounter);
  }

}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t skip) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) 
  {
      if(j % 5 == 0)
      {
      for(i=0 ; i< strip1.numPixels(); i++)
      {
        strip1.setPixelColor(i, Wheel(((-i * 256 / strip1.numPixels()) + j - 80) & 255));
      }
  
      for(i=0; i< strip2.numPixels(); i++)
      {
        strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
      }
      
      for(i=0; i< strip3.numPixels(); i++) {
        strip3.setPixelColor(i, Wheel(((i * 256 / strip3.numPixels()) + j) & 255));
      }

      for(i=0 i< sign.numPixels(); i++)
      {
        sign.setPixelColor(i, Wheel(j & 255));
      }
  
      strip1.show();
      strip2.show();
      strip3.show();
      sign.show();
    }
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
