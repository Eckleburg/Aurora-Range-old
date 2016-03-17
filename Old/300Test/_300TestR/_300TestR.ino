#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(300, PIN);

void setup() {

  uint8_t  brightness = 255;

  strip.begin();
  strip.setBrightness(brightness);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

 uint8_t  wait = 100;
 
  for(uint16_t b=0; b<5; b++)
  {
    uint16_t t = (60*b);
    
    for(uint16_t i=t; i<(t+60); i++) {
      strip.setPixelColor(i, strip.Color(255,0,0));
    }
    strip.show();

    for(uint16_t i=t; i<(t+60); i++) {
      strip.setPixelColor(i, strip.Color(0,255,0));
      delay(wait);
    }
    strip.show();

    for(uint16_t i=t; i<(t+60); i++) {
      strip.setPixelColor(i, strip.Color(0,0,255));
      delay(wait);
    }
    strip.show();


      for(uint16_t i=t; i<(t+60); i++) {
      strip.setPixelColor(i, strip.Color(0,0,0));
      delay(wait);
    }
    strip.show();
  }
}

