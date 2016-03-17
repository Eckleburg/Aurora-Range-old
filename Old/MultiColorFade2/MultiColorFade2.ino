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

uint32_t Color1 = ring1.Color(127, 0, 0);
uint32_t Color2 = ring1.Color(51, 255, 255);
uint32_t Color3 = ring1.Color(51, 255, 255);

float r1, r2, r3, g1, g2, g3, b1, b2, b3;
float r1r1, r1r2, r1r3, r1g1, r1g2, r1g3, r1b1, r1b2, r1b3;
float r2r1, r2r2, r2r3, r2g1, r2g2, r2g3, r2b1, r2b2, r2b3;
float r3r1, r3r2, r3r3, r3g1, r3g2, r3g3, r3b1, r3b2, r3b3;
float R1RSlope1, R1GSlope1, R1BSlope1, R2RSlope1, R2GSlope1, R2BSlope1, R3RSlope1, R3GSlope1, R3BSlope1;
float RSlope2, GSlope2, BSlope2;

void setup() 
{  
  uint8_t  brightness = 250;
  
  ring1.begin();
  ring1.setBrightness(brightness);
  ring1.show();
  
  ring2.begin();
  ring2.setBrightness(brightness);
  ring2.show();  
  
  ring3.begin();
  ring3.setBrightness(brightness);
  ring3.show();

  calcComp();
  varInit();
  calcSlopes1();
  calcSlopes2();
  calcSlopes3();

  Serial.begin(9600);
}

void loop() {

 Color3 = ring1.Color(51, 255, 255);

  for(int f=0; f<3; f++) {
    colorHandler(0);
  }

  Color3 = ring1.Color(127, 0, 255);
  colorHandler(0);

}

void colorHandler(int wait) {
  int i;
  int j;

  for(j=0; j<100; j++)
  {  
    
      for(i=0; i<ring3.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, Wheel1((j)));
        ring2.setPixelColor(i, Wheel2((j-30)));
        ring3.setPixelColor(i, Wheel3((j-60)));
      }

      ring1.show();
      ring2.show();
      ring3.show();
      
      delay(0);

  }
}

uint32_t Wheel1(float WheelPos) {

  float Red1, Green1, Blue1;
  
  if(WheelPos < 0) {
    WheelPos = WheelPos + 100;
  }

if((WheelPos == 0)&&(Color2 != Color3)) {
//  Color2 = Color3;
  calcComp();
  
  r1r2 = r3;
  r1g2 = g3;
  r1b2 = b3;

  calcSlopes1();
  
  R1RSlope1 = RSlope2;
  R1GSlope1 = GSlope2;
  R1BSlope1 = BSlope2;
  
}
  
  if(WheelPos < 50) {
    Red1 = r1r1 + R1RSlope1*WheelPos;
    Green1 = r1g1 + R1GSlope1*WheelPos;
    Blue1 = r1b1 + R1BSlope1*WheelPos;
  }
  
  else {
    Red1 = r1r2 - R1RSlope1*(WheelPos-50);
    Green1 = r1g2 - R1GSlope1*(WheelPos-50);
    Blue1 = r1b2 - R1BSlope1*(WheelPos-50);
  }

//  Serial.print("\nColor3 = ");
//  Serial.print(Color3);
//  Serial.print("\nWheelPos = ");
//  Serial.print(WheelPos);
//  Serial.print("\ng3 = ");
//  Serial.print(g3);
//  Serial.print("\nr2g2 = ");
//  Serial.print(r1g2);
//  Serial.print("\nGreen");
//  Serial.print(Green1);
  return ring1.Color(Red1, Green1, Blue1);
}

uint32_t Wheel2(float WheelPos) {

  float Red2, Green2, Blue2;
  
  if(WheelPos < 0) {
    WheelPos = WheelPos + 100;
  }

if((WheelPos == 0)&&(Color2 != Color3)) {
//  Color2 = Color3;
  calcComp();
  
  r2r2 = r3;
  r2g2 = g3;
  r2b2 = b3;

  calcSlopes2();
  R2RSlope1 = RSlope2;
  R2GSlope1 = GSlope2;
  R2BSlope1 = BSlope2;
  
}
  
  if(WheelPos < 50) {
    Red2 = r2r1 + R2RSlope1*WheelPos;
    Green2 = r2g1 + R2GSlope1*WheelPos;
    Blue2 = r2b1 + R2BSlope1*WheelPos;
  }
  
  else {
    Red2 = r2r2 - R2RSlope1*(WheelPos-50);
    Green2 = r2g2 - R2GSlope1*(WheelPos-50);
    Blue2 = r2b2 - R2BSlope1*(WheelPos-50);
  }

//  Serial.print("\nColor3 = ");
//  Serial.print(Color3);
//  Serial.print("\nWheelPos = ");
//  Serial.print(WheelPos);
//  Serial.print("\ng3 = ");
//  Serial.print(g3);
//  Serial.print("\nRed2 = ");
//  Serial.print(Red2);
//  Serial.print("\nGreen");
//  Serial.print(Green2);
  return ring1.Color(Red2, Green2, Blue2);
}

uint32_t Wheel3(float WheelPos) {

  float Red3, Green3, Blue3;
  
  if(WheelPos < 0) {
    WheelPos = WheelPos + 100;
  }

if((WheelPos == 0)&&(Color2 != Color3)) {
  Color2 = Color3;
  calcComp();
  
  r3r2 = r3;
  r3g2 = g3;
  r3b2 = b3;

  calcSlopes3();
  R3RSlope1 = RSlope2;
  R3GSlope1 = GSlope2;
  R3BSlope1 = BSlope2;
  
}
  
  if(WheelPos < 50) {
    Red3 = r3r1 + R3RSlope1*WheelPos;
    Green3 = r3g1 + R3GSlope1*WheelPos;
    Blue3 = r3b1 + R3BSlope1*WheelPos;
  }
  
  else {
    Red3 = r3r2 - R3RSlope1*(WheelPos-50);
    Green3 = r3g2 - R3GSlope1*(WheelPos-50);
    Blue3 = r3b2 - R3BSlope1*(WheelPos-50);
  }

//  Serial.print("\nColor3 = ");
//  Serial.print(Color3);
//  Serial.print("\nWheelPos = ");
//  Serial.print(WheelPos);
//  Serial.print("\ng3 = ");
//  Serial.print(g3);
//  Serial.print("\nRed3 = ");
//  Serial.print(Red3);
//  Serial.print("\nGreen");
//  Serial.print(Green2);
  return ring1.Color(Red3, Green3, Blue3);
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

void calcSlopes1() {

  R1RSlope1 = (r2-r1)/50;
  R1GSlope1 = (g2-g1)/50;
  R1BSlope1 = (b2-b1)/50;

  RSlope2 = (r3-r1)/50;
  GSlope2 = (g3-g1)/50;
  BSlope2 = (b3-b1)/50;
  
}

void calcSlopes2() {

  R2RSlope1 = (r2-r1)/50;
  R2GSlope1 = (g2-g1)/50;
  R2BSlope1 = (b2-b1)/50;

  RSlope2 = (r3-r1)/50;
  GSlope2 = (g3-g1)/50;
  BSlope2 = (b3-b1)/50;
  
}

void calcSlopes3() {

  R3RSlope1 = (r2-r1)/50;
  R3GSlope1 = (g2-g1)/50;
  R3BSlope1 = (b2-b1)/50;

  RSlope2 = (r3-r1)/50;
  GSlope2 = (g3-g1)/50;
  BSlope2 = (b3-b1)/50;
  
}

void varInit() {
  r1r1 = r1;
  r1r2 = r2;
  r1r3 = r3;
  r1g1 = g1;
  r1g2 = g2;
  r1g3 = g3;
  r1b1 = b1;
  r1b2 = b2;
  r1b3 = b3;

  r2r1 = r1;
  r2r2 = r2;
  r2r3 = r3;
  r2g1 = g1;
  r2g2 = g2;
  r2g3 = g3;
  r2b1 = b1;
  r2b2 = b2;
  r2b3 = b3;

  r3r1 = r1;
  r3r2 = r2;
  r3r3 = r3;
  r3g1 = g1;
  r3g2 = g2;
  r3g3 = g3;
  r3b1 = b1;
  r3b2 = b2;
  r3b3 = b3;
}


