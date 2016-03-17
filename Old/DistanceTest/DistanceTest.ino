#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 3
#define PIN2 9
#define PIN3 10

Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(11, PIN1);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(20, PIN2);
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(29, PIN3);

void setup() 
{
  uint8_t  brightness = 255;

  ring1.begin();
  ring1.setBrightness(brightness);
  ring1.show();
  
  ring2.begin();
  ring2.setBrightness(brightness);
  ring2.show();  

  ring3.begin();
  ring3.setBrightness(brightness);
  ring3.show(); // Initialize all pixels to 'off'
}

void loop() {

  uint32_t c;

  for(int g=0; g<255; g++) {
   c = Wheel(g);
  
  
    ring3.setPixelColor(12, c);
    ring3.setPixelColor(13, c);

    ring3.show();
    delay(10);
  }

}

uint32_t Wheel(float WheelPos) {
//  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return ring2.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return ring2.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return ring2.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


