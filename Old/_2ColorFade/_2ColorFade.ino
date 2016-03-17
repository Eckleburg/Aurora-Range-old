#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN1 3
#define PIN2 5
#define PIN3 6

Adafruit_NeoPixel ring1 = Adafruit_NeoPixel(11, PIN1);
Adafruit_NeoPixel ring2 = Adafruit_NeoPixel(20, PIN2);
Adafruit_NeoPixel ring3 = Adafruit_NeoPixel(29, PIN3);

uint32_t Color1 = ring1.Color(127, 0, 0);
uint32_t Color2 = ring1.Color(51, 255, 255);
uint32_t Color3 = ring1.Color(127, 0, 0);

uint8_t r1, r2, g1, g2, b1, b2, r3, g3, b3;
float RSlope, GSlope, BSlope;

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
  ring3.show();

  Serial.begin(9600);
}

void loop() {


  calcComp();
  calcSlopes();

  for(int f=0; f<10; f++) {
    colorHandler(10000);
  }

}

void colorHandler(int wait) {
  int i;
  int j;

  for(j=0; j<100; j++)
  {  
    
      for(i=0; i<ring3.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, Wheel((j+60)));
        ring2.setPixelColor(i, Wheel((j+30)));
        ring3.setPixelColor(i, Wheel((j)));
      }

//      ring1.show();
//      ring2.show();
      ring3.show();
      
      delay(20);

  }
}

uint32_t Wheel(float WheelPos) {

  float Red, Green, Blue;
  
  if(WheelPos > 100) {
    WheelPos = WheelPos - 100;
  }
  
  if(WheelPos < 50) {
    Red = r1 + RSlope*WheelPos;
    Green = g1 + GSlope*WheelPos;
    Blue = b1 + BSlope*WheelPos;
    
    return ring1.Color(Red, Green, Blue);
  }
  
  else {
    Red = r2 - RSlope*(WheelPos-50);
    Green = g2 - GSlope*(WheelPos-50);
    Blue = b2 - BSlope*(WheelPos-50);
    
    return ring1.Color(Red, Green, Blue);
  }
}

void calcComp() {
    
  r1 = (Color1 & 0xff0000)/(0xffff);
  g1 = (Color1 & 0xff00)/(0xff);
  b1 = (Color1 & 0xff);
  
  r2 = (Color2 & 0xff0000)/(0xffff);
  g2 = (Color2 & 0xff00)/(0xff);
  b2 = (Color2 & 0xff);

  r3 = (Color3 & 0xff0000)/(0xffff);
  g3 = (Color3 & 0xff00)/(0xff);
  b3 = (Color3 & 0xff);
}

void calcSlopes() {

  RSlope = (r2-r1)/50;
  GSlope = (g2-g1)/50;
  BSlope = (b2-b1)/50;
  
}


