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

uint32_t colorStream[150];

void setup() 
{
  uint8_t  brightness = 120;
  
  ring1.begin();
  ring1.setBrightness(brightness);
  ring1.show();
  
  ring2.begin();
  ring2.setBrightness(brightness);
  ring2.show();  
  
  ring3.begin();
  ring3.setBrightness(brightness);
  ring3.show(); // Initialize all pixels to 'off'

  for(int e=0; e<101; e++) {
    if(random(2) == 1) {
      colorStream[e] = ring1.Color(255, 0, 0);
    }
    else {
      colorStream[e] = ring1.Color(0, 0, 0);
    }
}
}

void loop() {
  
  uint32_t curColor = ring1.Color(0, 255, 0);
  int g;
  uint8_t wait = 50;

for(int f=0; f<150; f++) {
  if(random(2) == 1) {
    colorStream[f] = curColor;
  }
  else {
    colorStream[f] = ring1.Color(0, 0, 0);
  }

  for(g=0; g<29; g++)
  {
    ring1.setPixelColor(g,colorStream[f+100]);
    ring2.setPixelColor(g,colorStream[f+50]);
    ring3.setPixelColor(g,colorStream[f]);
  }
  ring1.show();
  ring2.show();
  ring3.show();
  delay(wait);
}
}
