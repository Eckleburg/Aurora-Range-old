#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 3
#define PIN2 9
#define PIN3 10
#define PIN4 11

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
Adafruit_NeoPixel sign = Adafruit_NeoPixel(40, PIN4);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() 
{
  uint8_t  brightness = 150;
  
  ring1.begin();
  ring1.setBrightness(brightness);
  ring1.show();
  
  ring2.begin();
  ring2.setBrightness(brightness);
  ring2.show();  
  
  ring3.begin();
  ring3.setBrightness(brightness);
  ring3.show(); // Initialize all pixels to 'off'

  sign.begin();
  sign.setBrightness(brightness);
  sign.show();  
}

void loop() {

int maxSpeed = 150;

for(int f=20; f>1; f--) {
  rainbow_lowskip(f);
}

for(int g=2; g<maxSpeed; g++) {
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

for(int h=maxSpeed; h>2; h--) {
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
      for(i=0; i<ring3.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, Wheel((j) &255));
        ring2.setPixelColor(i, Wheel((j-20)&255));
        ring3.setPixelColor(i, Wheel((j-40)&255));
      }

      for(i=0; i<sign.numPixels(); i++)
      {
        sign.setPixelColor(i, Wheel(((i * 256 / sign.numPixels()) + j) & 255));
      }

      ring1.show();
      ring2.show();
      ring3.show();
      sign.show();
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
      for(i=0; i<ring3.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, Wheel((j) &255));
        ring2.setPixelColor(i, Wheel((j-20)&255));
        ring3.setPixelColor(i, Wheel((j-40)&255));
      }

      ring1.show();
      ring2.show();
      ring3.show();
    }
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


