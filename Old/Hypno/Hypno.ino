#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 3
#define PIN2 5
#define PIN3 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(11, PIN1);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(20, PIN2);
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(29, PIN3);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

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

//for(int f=5; f>1; f--) {
//  rainbow_lowskip(f);
//}
//
//for(int g=2; g<270; g++) {
//  rainbow_highskip(g);
//}
//
//for(int h=270; h>2; h--) {
//  rainbow_highskip(h);
//}
//
//for(int e=1; e<5; e++) {
//  rainbow_lowskip(e);
//}

colorWipe(ring1.Color(102, 0, 204), 20);
colorWipe(ring1.Color(0, 255 , 0), 20);

}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {

  for(int g=0; g<255; g++) {
    c = Wheel(g);
  
  
  for(uint16_t i=0; i<ring1.numPixels(); i++) {
    ring1.setPixelColor(i, c);
    ring1.show();
    delay(wait);
  }

    for(uint16_t i=0; i<ring2.numPixels(); i++) {
    ring2.setPixelColor(i, c);
    ring2.show();
    delay(wait);
  }

    for(uint16_t i=0; i<ring3.numPixels(); i++) {
    ring3.setPixelColor(i, c);
    ring3.show();
    delay(wait);
  }
  }
}

uint32_t Wheel(float WheelPos) {
  
    return ring2.Color(153/255*WheelPos, 255-(51/255)*WheelPos, WheelPos);
}


