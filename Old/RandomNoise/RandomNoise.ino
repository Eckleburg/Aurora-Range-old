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

uint8_t wait = 0;
  
  ring1.setPixelColor(random(ring1.numPixels()), random(255),random(255),random(255));

  ring1.show();
  delay(wait);
  
  ring2.setPixelColor(random(ring2.numPixels()), random(255),random(255),random(255));

  ring2.show();
  delay(wait);
  
  ring3.setPixelColor(random(ring3.numPixels()), random(255),random(255),random(255));

  ring3.show();
  delay(wait);

}


