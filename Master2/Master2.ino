#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel layer0 = Adafruit_NeoPixel(38, 2);
Adafruit_NeoPixel layer1 = Adafruit_NeoPixel(66, 3);
Adafruit_NeoPixel layer2 = Adafruit_NeoPixel(97, 4);
Adafruit_NeoPixel layer3 = Adafruit_NeoPixel(112, 5);
Adafruit_NeoPixel layer4 = Adafruit_NeoPixel(144, 6);
Adafruit_NeoPixel layer5 = Adafruit_NeoPixel(137, 7);
Adafruit_NeoPixel layer6 = Adafruit_NeoPixel(137, 8);
Adafruit_NeoPixel layer7 = Adafruit_NeoPixel(125, 9);
Adafruit_NeoPixel layer8 = Adafruit_NeoPixel(106, 10);
Adafruit_NeoPixel layer9 = Adafruit_NeoPixel(83, 11);
Adafruit_NeoPixel layer10 = Adafruit_NeoPixel(38, 12);
Adafruit_NeoPixel layer11 = Adafruit_NeoPixel(16, 13);
Adafruit_NeoPixel c = Adafruit_NeoPixel(1,0);

float r1, r2, g1, g2, b1, b2;
float rSlope, gSlope, bSlope;
uint32_t curColor;

float rainbowOffset = 15;

void setup() 
{
  uint8_t  brightness = 180;
  
  layer0.begin();
  layer0.setBrightness(brightness);
  layer0.show();

  layer1.begin();
  layer1.setBrightness(brightness);
  layer1.show();

  layer2.begin();
  layer2.setBrightness(brightness);
  layer2.show();

  layer3.begin();
  layer3.setBrightness(brightness);
  layer3.show();

  layer4.begin();
  layer4.setBrightness(brightness);
  layer4.show();

  layer5.begin();
  layer5.setBrightness(brightness);
  layer5.show();

  layer6.begin();
  layer6.setBrightness(brightness);
  layer6.show();

  layer7.begin();
  layer7.setBrightness(brightness);
  layer7.show();

  layer8.begin();
  layer8.setBrightness(brightness);
  layer8.show();

  layer9.begin();
  layer9.setBrightness(brightness);
  layer9.show();

  layer10.begin();
  layer10.setBrightness(brightness);
  layer10.show();

  layer11.begin();
  layer11.setBrightness(brightness);
  layer11.show();

//  opening(60);

}

void loop() 
{
  for(int rainbowCounter=0; rainbowCounter<5; rainbowCounter++)
  {
    rainbowSkip(0, 1);
  }
  
  for(int rainbowCounter=0; rainbowCounter<10; rainbowCounter++)
  {
    rainbowSkip(rainbowCounter, 1);
    rainbowSkip(rainbowCounter, 1);
  }

  for(int rainbowCounter=0; rainbowCounter<5; rainbowCounter++)
  {
     rainbowSkip(10, 1);
     rainbowSkip(10, 1);
     rainbowSkip(10, 1);
     rainbowSkip(10, 1);
     rainbowSkip(6, -1);
     rainbowSkip(6, -1);
     rainbowSkip(10, 1);
     rainbowSkip(6, -1);
  }
  
  rainbowSpeed(10);
  
}


void opening(int fadeSteps)
{
  uint32_t eColor;

//delay(5000);
//delay(5000);

for(int i=0; i<26; i++)
{
  layer0.setPixelColor(i, c.Color((255)/50, 0, 0));
  showLayer(0);
  delay(50);
}

delay(2000);

for(int bg = 1; bg<=50; bg++)
{
  for(int i=0; i<26; i++)
  {
    layer0.setPixelColor(i, c.Color((bg*255)/50, 0, 0));
  }
    showLayer(0);
    delay(100);
}

delay(3000);

for(int bg = 1; bg<=50; bg++)
{
  for(int i=26; i<37; i++)
  {
    layer0.setPixelColor(i, c.Color((bg*255)/50, 0, 0));
  }
    showLayer(0);
    delay(100);
}

  
  for (int l=1; l<=11; l++)
  {
    eColor = Wheel((l*int(rainbowOffset))&255);
    calcComp(curColor, eColor);
    calcSlopes(fadeSteps);

    for (int m=0; m<=fadeSteps; m++)
    {
      assignColor(l, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
      showAll();
    }
  }

  curColor = eColor;
  delay(9000);
}

void rainbowSpeed(int velocity)
{
  for(int k=velocity; k<105; k++)
  {
    rainbowSkip(k, 1);
    rainbowSkip(k, 1);
  }

  for(int k=105; k>0; k--)
  {
    rainbowSkip(k, 1);
  }
}

void rainbowSkip(int skip, int dir) 
{

  for(int rSkipCounter=255; rSkipCounter>0; rSkipCounter--)
  {
    if (rSkipCounter % skip == 0)     
    {     
      assignColor(0, Wheel((dir*rSkipCounter) &255));
      assignColor(1, Wheel((dir*rSkipCounter+int(rainbowOffset))&255));
      assignColor(2, Wheel((dir*rSkipCounter+int(2*rainbowOffset))&255));
      assignColor(3, Wheel((dir*rSkipCounter+int(3*rainbowOffset))&255));
      assignColor(4, Wheel((dir*rSkipCounter+int(4*rainbowOffset))&255));
      assignColor(5, Wheel((dir*rSkipCounter+int(5*rainbowOffset))&255));
      assignColor(6, Wheel((dir*rSkipCounter+int(6*rainbowOffset))&255));
      assignColor(7, Wheel((dir*rSkipCounter+int(7*rainbowOffset))&255));
      assignColor(8, Wheel((dir*rSkipCounter+int(8*rainbowOffset))&255));
      assignColor(9, Wheel((dir*rSkipCounter+int(9*rainbowOffset))&255));
      assignColor(10, Wheel((dir*rSkipCounter+int(10*rainbowOffset))&255));
      assignColor(11, Wheel((dir*rSkipCounter+int(11*rainbowOffset))&255));
      
      showAll();
    }      
  }
}

void assignColor(int layer, uint32_t displayColor) 
{
  int i;
  
  switch(layer) {
    case 0:
      for(i=0; i<38; i++) {
        layer0.setPixelColor(i, displayColor);
      }
      break;

    case 1:
      for(i=0; i<66; i++) {
        layer1.setPixelColor(i, displayColor);
      }
      break;

    case 2:
      for(i=0; i<97; i++) {
        layer2.setPixelColor(i, displayColor);
      }
      break;

    case 3:
      for(i=0; i<112; i++) {
        layer3.setPixelColor(i, displayColor);
      }
      break;

    case 4:
      for(i=0; i<144; i++) {
        layer4.setPixelColor(i, displayColor);
      }
      break;

    case 5:
      for(i=0; i<137; i++) {
        layer5.setPixelColor(i, displayColor);
      }
      break;

    case 6:
      for(i=0; i<137; i++) {
        layer6.setPixelColor(i, displayColor);
      }
      break;

    case 7:
      for(i=0; i<125; i++) {
        layer7.setPixelColor(i, displayColor);
      }
      break;

    case 8:
      for(i=0; i<106; i++) {
        layer8.setPixelColor(i, displayColor);
      }
      break;

    case 9:
      for(i=0; i<83; i++) {
        layer9.setPixelColor(i, displayColor);
      }
      break;

    case 10:
      for(i=0; i<38; i++) {
        layer10.setPixelColor(i, displayColor);
      }
      break;

    case 11:
      for(i=0; i<16; i++) {
        layer11.setPixelColor(i, displayColor);
      }
      break;
      
    default:
      break;
  }
}

void showLayer(int layer)
{
  switch(layer)
  {
    case 0:
    layer0.show();
    break;

   case 1:
    layer1.show();
    break;

   case 2:
    layer2.show();
    break;

   case 3:
    layer3.show();
    break;

   case 4:
    layer4.show();
    break;

   case 5:
    layer5.show();
    break;

   case 6:
    layer6.show();
    break;

   case 7:
    layer7.show();
    break;

   case 8:
    layer8.show();
    break;

   case 9:
    layer9.show();
    break;

   case 10:
    layer10.show();
    break;

   case 11:
    layer11.show();
    break;

    default:
    break;   
  }

}

void showAll()
{
  layer0.show();
  layer1.show();
  layer2.show();
  layer3.show();
  layer4.show();
  layer5.show();
  layer6.show();
  layer7.show();
  layer8.show();
  layer9.show();
  layer10.show();
  layer11.show();
}

void calcComp(uint32_t ccColor1, uint32_t ccColor2) 
{
  r1 = (ccColor1 & 0xff0000)/(0x10000);
  g1 = (ccColor1 & 0xff00)/(0x100);
  b1 = (ccColor1 & 0xff);
  
  r2 = (ccColor2 & 0xff0000)/(0x10000);
  g2 = (ccColor2 & 0xff00)/(0x100);
  b2 = (ccColor2 & 0xff);
}

void calcSlopes(int slopeSteps) {

  rSlope = (r2-r1)/slopeSteps;
  gSlope = (g2-g1)/slopeSteps;
  bSlope = (b2-b1)/slopeSteps;

}

uint32_t Wheel(float WheelPos) {
//  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return layer1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return layer1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return layer1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
