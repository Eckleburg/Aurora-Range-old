#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel layer0 = Adafruit_NeoPixel(37, 2);
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
uint32_t curColor = 0;
int customWheelSteps = 0;

void setup() 
{
  uint8_t  brightness = 120;

  Serial.begin(9600);
  
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

}

void loop() {

stretchWaveUp(15, 1, c.Color(255, 0, 0), c.Color(0, 0, 255));
stretchWaveUp(15, 2, c.Color(255, 0, 0), c.Color(0, 0, 255));
//stretchWaveUp(8, 3, c.Color(255, 0, 0), c.Color(0, 0, 255));
//stretchWaveUp(8, 4, c.Color(255, 0, 0), c.Color(0, 0, 255));
stretchWaveUp(15, 1, c.Color(255, 0, 0), c.Color(0, 255, 0));

//waveUp(4, 10, 10, c.Color(0, 0, 0), c.Color(255, 0, 0));
//waveUp(4, 10, 10, c.Color(0, 0, 0), c.Color(255, 0, 0));
//waveUpFade(4, c.Color(0, 0, 0), c.Color(255, 0, 0), c.Color(0, 255, 0));
//
//waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 255, 0));
//waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 255, 0));
//waveUpFade(4, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
//
//waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
//waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
//waveUpFade(4, c.Color(0, 0, 0), c.Color(0, 0, 255), c.Color(255, 0, 0));
//
//waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
//waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
//waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
//waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
//waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
//waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
//waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
//waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
//waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
//
//
//waveUp(11, 10, 0, c.Color(255, 0, 0), c.Color(0, 255, 0));
//waveUp(11, 15, 0, layer0.Color(255, 0, 0), layer0.Color(0, 255, 0));
//waveUp(5, 15, 0, layer0.Color(255, 0, 0), layer0.Color(0, 0, 255));
//waveUp(3 , 15, 0, layer0.Color(255, 0, 0), layer0.Color(0, 255, 255));
//waveUp(2, 20, 0, layer0.Color(255, 0, 0), layer0.Color(0, 255, 0));
//waveUp(2, 20, 0, layer0.Color(255, 0, 0), layer0.Color(0, 255, 0));
//waveUp(2, 20, 0, layer0.Color(255, 0, 0), layer0.Color(0, 255, 0));
//
////singleColorFadeEx(5, c.Color(128, 255, 255));
//curColor = c.Color(255, 0, 255);
//singleColorFadeEx(1, c.Color(255, 255, 0));
//
//waveDn(11, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveDn(11, c.Color(255, 255, 0), c.Color(255, 0, 255));
//delay(400);
//waveUp(10, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(9, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(8, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(7, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(6, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(5, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(4, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//waveUp(3, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
//
//
//singleWaveUp(0x1F5B5D, 0xb8599b, c.Color(255,255,102));

  
}

void stretchWaveUp(int waveLayers, int fadeMultiplier, uint32_t color1, uint32_t color2)
{  
  customWheelSteps = fadeMultiplier*waveLayers;
  calcComp(color1, color2);
  calcSlopes(customWheelSteps);

  for(int waveStep = 0; waveStep <= 2*customWheelSteps; waveStep++)
  {
    for(int layerCntr = 0; layerCntr < 11; layerCntr += waveLayers)
    {      
      for(int waveCntr = 0; waveCntr < waveLayers; waveCntr++)
      {
        assignLayer(layerCntr + waveCntr, customWheel(waveStep + 2*fadeMultiplier*waveCntr));
      }
    }
       showAll();

  }
}
void singleColorExpand(uint32_t eColor)
{
  for (int l=0; l<=11; l++)
  {
    assignColor(l, eColor);
    showAll();
    delay(20);
  }


}


void singleColorFadeEx(int fadeSteps, uint32_t eColor)
{

  calcComp(curColor, eColor);
  calcSlopes(fadeSteps);
  
  for (int l=0; l<=11; l++)
  {
    for (int m=0; m<=fadeSteps; m++)
    {
      assignColor(l, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
      showAll();
    }
  }
  

curColor = eColor;

}
void singleColorClose(uint32_t eColor)
{
  for (int l=11; l>=0; l--)
  {
    assignColor(l, eColor);
    showAll();
    delay(20);
  }


}

void waveUp(int waves, int fadeSteps, uint32_t wait, uint32_t tColor1, uint32_t tColor2)
{   
  calcComp(tColor1, tColor2);
  calcSlopes(fadeSteps);
  for (int j=0; j<waves; j++)
  {
    for (int m=0; m<=fadeSteps; m++)
    {
      for (int h=0; h<11; h=h+waves)
      {
        assignColor(h+j, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
        assignColor(h+j-1, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));
        showLayer(h+j);
        showLayer(h+j-1);


        if(h+j == 0)
        {
          assignColor(11, tColor1);        
          showLayer(11);
        }
        delay(wait);
      }  
    }
  }   
}

void singleWaveUp(uint32_t bColor1, uint32_t bColor2, uint32_t wColor)
{ 
  int wCounter;
  
    for (int j=0; j<30; j++)
    {

      for (int h=0; h<11; h=h+3)
      {
         assignColor((h+j%3), bColor2);
      }

      assignColor(j, wColor);

  
      delay(50);
      showAll();

      for (int h=0; h<11; h=h+3) {
        assignColor(h+j%3, bColor1);
      }
    }
}

void waveUpFade(int waves, uint32_t backgroundColor, uint32_t waveColor1, uint32_t waveColor2)
{ 
  calcComp(waveColor1, waveColor2);
  calcSlopes(waves);
  
  for (int j=0; j<waves; j++)
  {
    
    for (int h=0; h<11; h=h+waves)
    {
      assignColor(h+j, c.Color(r1+rSlope*j, g1+gSlope*j, b1+bSlope*j));
      assignColor(h+j-1, backgroundColor);

      if(h+j == 0)
      assignColor(11, backgroundColor);
    }
    

    delay(50);
    showAll();

    for (int h=0; h<11; h=h+waves) {
      assignColor(h+j, backgroundColor);
    }
  }
}



void waveDn(int waves, uint32_t tColor1, uint32_t tColor2)
{ 
  for (int j=waves; j>=0; j--)
  {
    
    for (int h=0; h<11; h=h+waves)
    {
      assignColor(h+j, tColor2);
    }

    delay(10);
    showAll();

    for (int h=0; h<11; h=h+waves) {
      assignColor(h+j, tColor1);
    }
  }
  
}

void assignLayer(int layer, uint32_t displayColor) 
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



void assignColor(int layer, uint32_t displayColor) 
{
  int i;
  
  switch(layer) {
    case 0:
      for(i=0; i<39; i++) {
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

uint32_t customWheel(int wheelPos)
{
  while(wheelPos > 2*customWheelSteps)
  wheelPos -= 2*customWheelSteps;
  while(wheelPos < 0)
  wheelPos += 2*customWheelSteps;

  if(wheelPos < (customWheelSteps))
  return c.Color(r1+rSlope*wheelPos, g1+gSlope*wheelPos, b1+bSlope*wheelPos);
  else
  return c.Color(r2-rSlope*(wheelPos-customWheelSteps), g2-gSlope*(wheelPos-customWheelSteps), b2-bSlope*(wheelPos-customWheelSteps));
}

