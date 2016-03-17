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

uint32_t semiColor = ring1.Color(255,255,255);

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

  Serial.begin(9600);
}

void loop() {

uint8_t wait = 20;

for(int k=0; k<11; k++) {
  
      for(int o=0; o<ring1.numPixels(); o++) 
      {        
        if (((o >= k)&&(o < (k + 5)))||(o < (k-5))) {
          ring1.setPixelColor(o, semiColor);
        }
        else {
          ring1.setPixelColor(o, (0, 0, 0));
        }
      }

  ring1.show();
  delay(wait);
}

for(int k=0; k<20; k++) {
  
      for(int o=0; o<ring2.numPixels(); o++) 
      {        
        if (((o >= k)&&(o < (k + 10)))||(o < (k-10))) {
          ring2.setPixelColor(o, semiColor);
        }
        else {
          ring2.setPixelColor(o, (0, 0, 0));
        }
      }

  ring2.show();
  delay(wait);
}

for(int k=0; k<29; k++) {
  
      for(int o=0; o<ring3.numPixels(); o++) 
      {        
        if (((o >= k)&&(o < (k + 15)))||(o < (k-15))) {
          ring3.setPixelColor(o, semiColor);
        }
        else {
          ring3.setPixelColor(o, (0, 0, 0));
        }
      }

  ring3.show();
  delay(wait);
}

}


