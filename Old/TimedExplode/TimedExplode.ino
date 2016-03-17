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

float r, g, b;
float stepSize;

uint32_t explodeColor = ring1.Color(255,255,255);

void setup() 
{  
  uint8_t  brightness = 80;
  
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
  Serial.begin(9600);
}

void loop() {

uint8_t wait, lightWait, darkWait;

wait = 0;
darkWait = 2000;
lightWait = 2000;
stepSize = 30;

for(int h=0; h<ring3.numPixels(); h++) {
  ring1.setPixelColor(h, (0, 0, 0));
  ring2.setPixelColor(h, (0, 0, 0));
  ring3.setPixelColor(h, (0, 0, 0));
}
ring1.show();
ring2.show();
ring3.show();

delay(darkWait);

for(int j=0; j<stepSize; j++) {
  
      for(int i=0; i<ring1.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, Wheel((j) &255));
      }

  ring1.show();
  delay(wait);
}

for(int k=0; k<stepSize; k++) {
  
      for(int o=0; o<ring2.numPixels(); o++) 
      {        
        ring2.setPixelColor(o, Wheel((k) &255));
      }

  ring2.show();
  delay(wait);
}

for(int l=0; l<stepSize; l++) {
  
      for(int p=0; p<ring3.numPixels(); p++) 
      {        
        ring3.setPixelColor(p, Wheel((l) &255));
      }

  ring3.show();
  delay(wait);
}

delay(lightWait);

}

void calcComp() {
    
  r = (explodeColor & 0xff0000)/(0x10000);
  g = (explodeColor & 0xff00)/(0x100);
  b = (explodeColor & 0xff);

}

uint32_t Wheel (float WheelPos) {
  float Red = r*WheelPos/stepSize;
  float Green = g*WheelPos/stepSize;
  float Blue = b*WheelPos/stepSize;

  return ring1.Color(Red, Green, Blue);
}

