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

uint32_t colorArray[150];

int r1, r2, r3, g1, g2, g3, b1, b2, b3;

uint32_t prevColor, curColor, nextColor;

float rSlope, gSlope, bSlope;

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

  prevColor = ring1.Color(0, 0, 0);
  curColor = ring1.Color(0,0,0);
  nextColor = ring1.Color(255, 0, 0);

  calcComp();
  calcSlopes();

  for (int c=0; c<50; c++)
  {
    calcFade(c);
  }

  prevColor = curColor;
  curColor = nextColor;

  Serial.begin(9600);
}

void loop() {

  int delay_t = 20;

   nextColor = ring1.Color(255, 128, 0);
//   Serial.print("\nCurrent Color = ");
//   Serial.print(curColor);
//   Serial.print("\nNext Color = ");
//   Serial.print(nextColor);
   colorHandler(0, delay_t);

   nextColor = ring1.Color(128, 128, 0);
//   Serial.print("\nCurrent Color = ");
//   Serial.print(curColor);
//   Serial.print("\nNext Color = ");
//   Serial.print(nextColor);
   colorHandler(1, delay_t);


      nextColor = ring1.Color(0, 255, 0);
   colorHandler(2, delay_t);

      nextColor = ring1.Color(0, 0, 255);
   colorHandler(0, delay_t);

      nextColor = ring1.Color(128, 0, 128);
   colorHandler(1, delay_t);

      nextColor = ring1.Color(255, 0, 0);
   colorHandler(2, delay_t);

}

void colorHandler(int arrayMult, int wait) {
  int i, j, arraySect;

  if(curColor == nextColor) {
    nextColor = prevColor;
  }

  Serial.print("\n Arraymult = ");
  Serial.print(arrayMult);
  calcComp();
  calcSlopes();

  arraySect = arrayMult*50;

  for(j=0; j<50; j++)
  {  
      if(arrayMult==2) {
        calcFade(j);
      }
      else {
        calcFade(j+arraySect+50);
      }
      
      for(i=0; i<ring3.numPixels(); i++) 
      {        
        ring1.setPixelColor(i, colorArray[j+arraySect+40]);
        ring2.setPixelColor(i, colorArray[j+arraySect+20]);
        ring3.setPixelColor(i, colorArray[j+arraySect]);

      }

//        Serial.print("\nArray Position = ");
//        Serial.print(j+arraySect);

      ring1.show();
      ring2.show();
      ring3.show();
      delay(wait);
  }

  prevColor = curColor;
  curColor = nextColor;  
}

void calcComp() {
    
  r1 = (prevColor & 0xff0000)/(0x10000);
  g1 = (prevColor & 0xff00)/(0x100);
  b1 = (prevColor & 0xff);
  
  r2 = (curColor & 0xff0000)/(0x10000);
  g2 = (curColor & 0xff00)/(0x100);
  b2 = (curColor & 0xff);
  Serial.print("\nr2 = ");
  Serial.print(r2);

  r3 = (nextColor & 0xff0000)/(0x10000);
  g3 = (nextColor & 0xff00)/(0x100);
  b3 = (nextColor & 0xff);
  Serial.print("\nr3 = ");
  Serial.print(r3);
}

void calcSlopes() {
  
  rSlope = (r3-r2)/50;
  gSlope = (g3-g2)/50;
  bSlope = (b3-b2)/50;

}

int calcFade(int colorPos) {

  int Red, Green, Blue, arraySub;

  if(colorPos < 50) {
    arraySub = 0;
  }
  else if(colorPos < 100) {
    arraySub = 1;
  }
  else {
    arraySub = 2;
  }

  Red = r2 + rSlope*(colorPos-50*arraySub);
  Green = g2 + gSlope*(colorPos-50*arraySub);
  Blue = b2 + bSlope*colorPos*(colorPos-50*arraySub);
  
  Serial.print("\nColorPos = ");
  Serial.print(colorPos);
  Serial.print("\n Red = ");
  Serial.print(Red);
  colorArray[colorPos] = ring1.Color(Red, Green, Blue);

}

