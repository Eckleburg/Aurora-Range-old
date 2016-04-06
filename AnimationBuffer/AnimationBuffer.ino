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
uint32_t curColor = c.Color(0, 0, 0);
int customWheelSteps = 0;

int animBufferSize = 24;
uint32_t prevAnim[100], curAnim[100], nextAnim[100];

float rainbowOffset = 15;

void setup() 
{
  uint8_t  brightness = 80;
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

  for(int arrayCntr = 0; arrayCntr < animBufferSize; arrayCntr++)
  {
    prevAnim[arrayCntr] = c.Color(0, 0, 0);
    curAnim[arrayCntr] = c.Color(0, 0, 0);
    nextAnim[arrayCntr] = c.Color(0, 0, 0);
  }
}

void loop() 
{
  for(int waveCntr = 0; waveCntr < 2; waveCntr++)
  {
  singleWave(c.Color(255, 0, 0));
  singleWave(c.Color(0, 0, 255));
  doubleWave(c.Color(255, 0, 0), c.Color(0, 0, 255));
  }

  singleWave(c.Color(0, 0, 0));
  resizeBuffer(48);
  singleWave(c.Color(0, 255, 0));
//  delay(1000);
  singleWave(c.Color(255, 0, 255));
  resizeBuffer(12);
}

void singleWave(uint32_t nextColor)
{
  calcComp(curColor, nextColor);
  calcSlopes(animBufferSize);
  
  for(int arrayCntr = 0; arrayCntr <= animBufferSize; arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*arrayCntr, g1+gSlope*arrayCntr, b1+bSlope*arrayCntr);
  }

  displayAnimUp();
  curColor = nextColor;
}

void doubleWave(uint32_t nextColor1, uint32_t nextColor2)
{
  calcComp(curColor, nextColor1);
  calcSlopes(int(animBufferSize/2));
  
  for(int arrayCntr = 0; arrayCntr < int(animBufferSize/2); arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*arrayCntr, g1+gSlope*arrayCntr, b1+bSlope*arrayCntr);
  }

  calcComp(nextColor1, nextColor2);
  calcSlopes(int(animBufferSize/2));

  for(int arrayCntr = 0; arrayCntr <= int(animBufferSize/2); arrayCntr++)
  {
    curAnim[arrayCntr+int(animBufferSize/2)] = c.Color(r1+rSlope*arrayCntr, g1+gSlope*arrayCntr, b1+bSlope*arrayCntr);
  }

  displayAnimUp();
  curColor = nextColor2;
  
}

void displayAnimUp()
{  
  int offset = int(animBufferSize/11);
  for(int animCntr = 0; animCntr <= animBufferSize; animCntr++)
  { 
    for(int layerCntr = 0; layerCntr <= 11; layerCntr++)
    {
      if((animCntr-layerCntr*offset) < 0)
      {
        assignLayer(layerCntr, prevAnim[animCntr-layerCntr*offset+animBufferSize]);       
      }
      else
      {
        assignLayer(layerCntr, curAnim[animCntr-layerCntr*offset]);
      }
      showLayer(layerCntr);
    }
//    showAll();
  }
  memcpy(prevAnim, curAnim, sizeof(curAnim));
}

void flashAnimUp(int offset)
{  
  for(int animCntr = 0; animCntr < animBufferSize; animCntr++)
  { 
    for(int layerCntr = 0; layerCntr <= 11; layerCntr++)
    {
      if(animCntr < layerCntr*offset)
      {
        assignLayer(layerCntr, prevAnim[animCntr-layerCntr*offset]);
        
      }
      else
      {
        assignLayer(layerCntr, curAnim[animCntr-layerCntr*offset]);
      }
      showLayer(layerCntr);
    }
//    showAll();
  }
  memcpy(prevAnim, curAnim, 4*animBufferSize);
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

void resizeBuffer(int newBufferSize)
{
  singleWave(curColor);
  for(int arrayPos = 0; arrayPos <= newBufferSize; arrayPos++)
  {
    prevAnim[arrayPos] = curColor;
  }

  animBufferSize = newBufferSize;
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
