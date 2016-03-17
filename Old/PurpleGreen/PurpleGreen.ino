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
Serial.begin(9600);
  
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

rainbow(0);


}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
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

void rainbow(int wait) 
{
  int i;
  int j;

  for(j=0; j<255; j++)
  {  
    
      for(i=0; i<ring3.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, Wheel((j) &255));
        ring2.setPixelColor(i, Wheel((j-85)&255));
        ring3.setPixelColor(i, Wheel((j-190)&255));
      }

      ring1.show();
      ring2.show();
      ring3.show();

//      Serial.print(j);
      Serial.print("\n");

      delay(wait);
  }
}


uint32_t Wheel(float WheelPos) {
//  WheelPos = 255 - WheelPos;
  if(WheelPos < 128) {
    float Red = (1.195)*WheelPos;
    float Green = 255-(1.594)*WheelPos;
    float Blue = 2*WheelPos;
    
    return ring2.Color(Red, Green, Blue);
  }
  else {
    float Red = 306-(1.195)*WheelPos;
    float Green =1.594*WheelPos - 153;
    float Blue = 510-2*WheelPos;
    
    return ring2.Color(Red, Green, Blue);
  }
}


