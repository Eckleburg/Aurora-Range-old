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

float r1, r2, g1, g2, b1, b2, r3, g3, b3;
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

//  Serial.print("\nr1 = ");
//  Serial.print(r1);
//  Serial.print("\nr2 = ");
//  Serial.print(r2);
//  
//  Serial.print("\ng1 = ");
//  Serial.print(g1);
//  Serial.print("\ng2 = ");
//  Serial.print(g2);
//  
//  Serial.print("\nb1 = ");
//  Serial.print(b1);
//  Serial.print("\nb2 = ");
//  Serial.print(b2);

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

      ring1.show();
      ring2.show();
      ring3.show();
      
      delay(0);

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

//    Serial.print("WheelPos = ");
//    Serial.print(WheelPos);
//    Serial.print("\n");
//    Serial.print("Red = ");
//    Serial.print(RSlope);
//    Serial.print("\n");
    return ring1.Color(Red, Green, Blue);
  }
  
  else {
    Red = r2 - RSlope*(WheelPos-50);
    Green = g2 - GSlope*(WheelPos-50);
    Blue = b2 - BSlope*(WheelPos-50);

//    Serial.print("WheelPos = ");
//    Serial.print(WheelPos);
//    Serial.print("\n");
//    Serial.print("Red = ");
//    Serial.print(RSlope);
//    Serial.print("\n");
    return ring1.Color(Red, Green, Blue);
  }
}

void calcComp() {
    
  r1 = (Color1 & 0xff0000)/(0x10000);
  g1 = (Color1 & 0xff00)/(0x100);
  b1 = (Color1 & 0xff);
  
  r2 = (Color2 & 0xff0000)/(0x10000);
  g2 = (Color2 & 0xff00)/(0x100);
  b2 = (Color2 & 0xff);

  r3 = (Color3 & 0xff0000)/(0x10000);
  g3 = (Color3 & 0xff00)/(0x100);
  b3 = (Color3 & 0xff);
}

void calcSlopes() {

  RSlope = (r2-r1)/50;
  GSlope = (g2-g1)/50;
  BSlope = (b2-b1)/50;
  
}


