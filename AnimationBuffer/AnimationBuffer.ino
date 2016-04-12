#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

int length0 = 38;
int length1 = 66;
int length2 = 97;
int length3 = 112;
int length4 = 144;
int length5 = 137;
int length6 = 137;
int length7 = 125;
int length8 = 106;
int length9 = 83;
int length10 = 38;
int length11 = 16;

Adafruit_NeoPixel layer0 = Adafruit_NeoPixel(length0, 2);
Adafruit_NeoPixel layer1 = Adafruit_NeoPixel(length1, 3);
Adafruit_NeoPixel layer2 = Adafruit_NeoPixel(length2, 4);
Adafruit_NeoPixel layer3 = Adafruit_NeoPixel(length3, 5);
Adafruit_NeoPixel layer4 = Adafruit_NeoPixel(length4, 6);
Adafruit_NeoPixel layer5 = Adafruit_NeoPixel(length5, 7);
Adafruit_NeoPixel layer6 = Adafruit_NeoPixel(length6, 8);
Adafruit_NeoPixel layer7 = Adafruit_NeoPixel(length7, 9);
Adafruit_NeoPixel layer8 = Adafruit_NeoPixel(length8, 10);
Adafruit_NeoPixel layer9 = Adafruit_NeoPixel(length9, 11);
Adafruit_NeoPixel layer10 = Adafruit_NeoPixel(length10, 12);
Adafruit_NeoPixel layer11 = Adafruit_NeoPixel(length11, 13);
Adafruit_NeoPixel c = Adafruit_NeoPixel(1,0);

float r1, r2, g1, g2, b1, b2;
float rSlope, gSlope, bSlope;
uint32_t curColor = c.Color(0, 0, 0);
int customWheelSteps = 0;

int initSpeed = 4;
int animBufferSize = (11-initSpeed)*11;

boolean animDir = 1;
uint32_t prevAnim[122], curAnim[122], tempAnim[122];

float rainbowOffset = 15;

void setup() 
{
  uint8_t  brightness = 50;
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
  }
  opening(60);
  singleColorExpand(c.Color(0, 0, 0));
  curColor = c.Color(0, 0, 0);
}

void loop() 
{
  softWaves();
  sharpWaves();
  spin();
  singleColorExpand(c.Color(0, 0, 0));
  opening(60);
  rainbowSpeed();
  singleColorExpand(c.Color(0, 0, 0));
  curColor = c.Color(0, 0, 0);
  delay(5000);
}

void sharpWaves()
{
int g;
 
singleColorExpand(c.Color(244, 0, 0));

waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(255, 0, 0));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(255, 0, 0));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(255, 0, 0));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(255, 0, 0));
waveUpFade(4, c.Color(0, 0, 0), c.Color(255, 0, 0), c.Color(0, 255, 0));

waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 255, 0));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 255, 0));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 255, 0));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 255, 0));
waveUpFade(4, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));

waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 5, 10, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUpFade(4, c.Color(0, 0, 0), c.Color(0, 0, 255), c.Color(255, 0, 0));

waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));


waveUp(11, 10, 0, c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUp(11, 15, 0, c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUp(5, 15, 0, c.Color(255, 0, 0), c.Color(0, 0, 255));
waveUp(3, 15, 0, c.Color(255, 0, 0), c.Color(0, 255, 255));

for (int sk = 0; sk <=5; sk++)
{
  waveUp(2, 15, 0, c.Color(255, 0, 0), c.Color(0, 250, 0));
}

for (int sk = 0; sk <=5; sk++)
{
  waveUp(2, 15, 0, c.Color(0, 255, 0), c.Color(0, 0, 255));
}

for (int sk = 0; sk <=5; sk++)
{
  waveUp(2, 15, 0, c.Color(0, 0, 255), c.Color(255, 0, 0));
}

singleColorFadeEx(5, c.Color(128, 255, 255));
curColor = c.Color(255, 0, 255);
singleColorFadeEx(1, c.Color(255, 255, 0));

waveDn(11, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveDn(11, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(10, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(10, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(10, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(10, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(9, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(8, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(7, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(6, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(5, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(4, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));
waveUp(3, 1, 5, c.Color(255, 255, 0), c.Color(255, 0, 255));

singleWaveUp(0x1F5B5D, 0xb8599b, c.Color(255,255,102));

  singleColorExpand(c.Color(0, 128, 255));
waveDn(6, c.Color(0, 128, 255), c.Color(255, 255, 102));
waveDn(6, c.Color(0, 128, 255), c.Color(255, 255, 102));
for(g=0; g<10; g++)
{
waveDn(6, c.Color(204, 102, 0), c.Color(255, 255, 102));
}

for(g=0; g<3; g++)
{
waveDn(6, c.Color(128, 0, 255), c.Color(255, 255, 102));
}

for(g=0; g<3; g++)
{
waveDn(6, c.Color(255, 255, 0), c.Color(255, 255, 102));
}

for(g=0; g<3; g++)
{
waveDn(6, c.Color(0, 200, 35), c.Color(255, 255, 102));
}

}

void spin()
{
  int spinCntr;

  singleColorExpand(c.Color(0, 255, 0));
  for(spinCntr = 0; spinCntr < 4; spinCntr++)
  {
    waveUp(1, 50, 0, c.Color(255, 0, 0), c.Color(0, 250, 0));
    waveUp(1, 50, 0, c.Color(0, 0, 255), c.Color(255, 0, 0));
  }
}

void softWaves()
{  
  int waveCntr, waveCntr2;

  uint32_t black = c.Color(0, 0, 0);
  uint32_t white = c.Color(255, 255, 255);
  uint32_t purple = c.Color(128, 0, 255);
  uint32_t red = c.Color(255, 0, 0);
  uint32_t green = c.Color(0, 255, 0);
  uint32_t blue = c.Color(0, 0, 255);

  for(waveCntr = 0; waveCntr < 3; waveCntr++)
  {
    singleWave(red);
    singleWave(black);
    singleWave(black);
    delay(1000);
  }

  for(waveCntr = 0; waveCntr < 3; waveCntr++)
  {
    singleWave(red);
    singleWave(green);
    singleWave(blue);
  }
  
  newSpeed(5);
  for(int waveCntr = 0; waveCntr < 2; waveCntr++)
  {
    singleWave(c.Color(255, 0, 0));
    singleWave(c.Color(0, 0, 255));
    doubleWave(c.Color(255, 0, 0), c.Color(0, 0, 255));
    singleWave(c.Color(0, 255, 0));
  }

  singleWave(c.Color(0, 0, 255));
  reverse();
  singleWave(c.Color(255, 255, 255));

  newSpeed(10);
  singleWave(c.Color(0, 0, 0));
  singleWave(c.Color(0, 255, 255));
  singleWave(c.Color(0, 0, 0));
  singleWave(c.Color(0, 255, 255));
  singleWave(c.Color(0, 0, 0));
  singleWave(c.Color(0, 255, 255));
  
  singleWave(c.Color(0, 255, 0));
  singleWave(c.Color(255, 0, 255));
  singleWave(c.Color(0, 255, 0));
  newSpeed(8);
  
  for(int waveCntr = 0; waveCntr < 2; waveCntr++)
  {
    singleWave(c.Color(255, 0, 0));
    singleWave(c.Color(0, 0, 255));
    doubleWave(c.Color(255, 0, 0), c.Color(0, 0, 255));
  }

  doubleWave(c.Color(128, 128, 0), c.Color(0, 128, 128));
  newSpeed(10);
  reverse();
  singleWave(c.Color(255, 255, 255));
  singleWave(c.Color(0, 255, 0));
  singleWave(c.Color(255, 0, 255));

//Begin Yellow, Purple, Turquoise
  newSpeed(8);
  for(waveCntr = 0; waveCntr < 4; waveCntr++)
  {
    doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 0));
    singleWave(c.Color(0, 0, 0));
  }

  reverse();
  doubleWave(c.Color(0, 0, 0), c.Color(255, 255, 0));
  singleWave(c.Color(0, 0, 0));
  singleWave(c.Color(0, 0, 0));

  reverse();
  newSpeed(9);
  doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 0));
  singleWave(c.Color(0, 0, 0));
  doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 0));

  newSpeed(6);

  singleWave(c.Color(0, 0, 0));
  singleWave(c.Color(255, 255, 0));
  singleWave(c.Color(0, 0, 0));
  singleWave(c.Color(0, 0, 0));

  newSpeed(9);
  singleWave(c.Color(255, 255, 0));
  doubleWave(c.Color(255, 255, 0), c.Color(0, 128, 255));
  singleWave(c.Color(0, 0, 0));
  
  for(waveCntr2 = 0; waveCntr2 < 4; waveCntr2++)
  {
    for(waveCntr = 0; waveCntr < 3; waveCntr++)
    {
      tripleWave(c.Color(255, 255, 0), c.Color(0, 128, 255), c.Color(128, 0, 255));
      tripleWave(c.Color(0, 0, 0), c.Color(255, 255, 0), c.Color(128, 0, 255));
      tripleWave(c.Color(128, 0, 255), c.Color(255, 255, 0), c.Color(0, 128, 255));
    }
    reverse();
  }

  newSpeed(10);
  for(waveCntr = 0; waveCntr < 6; waveCntr++)
  {
    tripleWave(c.Color(128, 0, 255), c.Color(0, 128, 255), c.Color(128, 0, 255));
    tripleWave(c.Color(0, 128, 255), c.Color(128, 0, 255), c.Color(0, 128, 255));
  }
  
  singleWave(c.Color(128, 0, 255));
  singleWave(c.Color(255, 255, 0));
  singleWave(c.Color(0, 0, 0));

//Orange Blue and Cyan
  uint32_t orange = c.Color(255, 70, 0);
  blue = c.Color(0, 43, 255);
  uint32_t cyan = c.Color(0, 255, 213);

  for(waveCntr = 0; waveCntr < 2; waveCntr++)
  {
    singleWave(c.Color(255, 70, 0));
    singleWave(c.Color(0, 43, 255));
    singleWave(c.Color(0, 255, 213));
    singleWave(c.Color(0, 43, 255));
    singleWave(c.Color(255, 70, 0));
    
    reverse();
    singleWave(c.Color(0, 0, 0));
    reverse();
    singleWave(c.Color(0, 0, 0));
    reverse();
    singleWave(c.Color(0, 0, 0));
    reverse();
    singleWave(c.Color(0, 0, 0));
    reverse();
    singleWave(c.Color(255, 0, 0));
    reverse();
    singleWave(c.Color(255, 0, 0));
    reverse();
    singleWave(c.Color(0, 0, 0));
    reverse();
    singleWave(c.Color(255, 0, 0));
    reverse();
    singleWave(c.Color(0, 0, 0));
    reverse();
    doubleWave(c.Color(0, 43, 255), c.Color(0, 0, 0));
    doubleWave(c.Color(0, 43, 255), c.Color(0, 0, 0));
  
    singleWave(blue);
    singleWave(cyan);
    singleWave(blue);
    singleWave(cyan);
    singleWave(blue);
    singleWave(orange);
    singleWave(white);
    singleWave(orange);
    singleWave(white);
    reverse();
  }

  newSpeed(7);
  reverse();
  for(waveCntr = 0; waveCntr < 6; waveCntr++)
  {
    doubleWave(blue, green);
  }

  reverse();
  singleWave(blue);
  newSpeed(9);
  for(waveCntr = 0; waveCntr < 10; waveCntr++)
  {
    doubleWave(blue, purple);
  }

  newSpeed(9);
  for(waveCntr = 0; waveCntr < 6; waveCntr++)
  {
    doubleWave(white, black);
  }
}

void singleWave(uint32_t nextColor)
{
  calcComp(curColor, nextColor);
  calcSlopes(animBufferSize);
  
  for(int arrayCntr = 0; arrayCntr <= animBufferSize; arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*arrayCntr, g1+gSlope*arrayCntr, b1+bSlope*arrayCntr);
  }

  displayAnim();
  curColor = nextColor;
}

void singleWaveUp(uint32_t bColor1, uint32_t bColor2, uint32_t wColor)
{ 
  int wCounter;
  
    for (int j=0; j<30; j++)
    {

      for (int h=0; h<11; h=h+3)
      {
         assignLayer((h+j%3), bColor2);
      }

      assignLayer(j, wColor);
      delay(50);
      showAll();

      for (int h=0; h<11; h=h+3) {
        assignLayer(h+j%3, bColor1);
      }
    }
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
  calcSlopes(int(animBufferSize/2)+1);

  for(int arrayCntr = int(animBufferSize/2); arrayCntr <= animBufferSize; arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*(arrayCntr-int(animBufferSize/2)), g1+gSlope*(arrayCntr-int(animBufferSize/2)), b1+bSlope*(arrayCntr-int(animBufferSize/2)));
  }

  displayAnim();
  curColor = nextColor2;
  
}

void tripleWave(uint32_t nextColor1, uint32_t nextColor2, uint32_t nextColor3)
{
  int waveSize = int((animBufferSize+1)/3);
  calcComp(curColor, nextColor1);
  calcSlopes(waveSize);
  
  for(int arrayCntr = 0; arrayCntr < waveSize; arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*arrayCntr, g1+gSlope*arrayCntr, b1+bSlope*arrayCntr);
  }

  calcComp(nextColor1, nextColor2);
  calcSlopes(waveSize);

  for(int arrayCntr = waveSize; arrayCntr < waveSize*2; arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*(arrayCntr-waveSize), g1+gSlope*(arrayCntr-waveSize), b1+bSlope*(arrayCntr-waveSize));
  }

  calcComp(nextColor2, nextColor3);
  calcSlopes(waveSize);

  for(int arrayCntr = waveSize*2; arrayCntr < waveSize*3; arrayCntr++)
  {
    curAnim[arrayCntr] = c.Color(r1+rSlope*(arrayCntr-2*waveSize), g1+gSlope*(arrayCntr-2*waveSize), b1+bSlope*(arrayCntr-2*waveSize));
  }

  displayAnim();
  curColor = nextColor3;
  
}

void singleColorExpand(uint32_t eColor)
{
  for (int l=0; l<=11; l++)
  {
    assignLayer(l, eColor);
    showAll();
    delay(20);
  }
}

void singleColorClose(uint32_t eColor)
{
  for (int l=11; l>=0; l--)
  {
    assignLayer(l, eColor);
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
      assignLayer(l, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
      showAll();
    }
  }
  curColor = eColor;
}

void waveUp(int waves, int fadeSteps, uint32_t wait, uint32_t tColor1, uint32_t tColor2)
{   
  calcComp(tColor1, tColor2);
  calcSlopes(fadeSteps);
  for (int j=0; j<waves; j++)
  {
    for (int m=0; m<=fadeSteps; m++)
    {
      for (int h=0; h<12; h=h+waves)
      {
        assignLayer(h+j, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
        assignLayer(h+j-1, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));
        showLayer(h+j);
        showLayer(h+j-1);


        if(h+j == 0)
        {
          assignLayer(11, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));        
          showLayer(11);
        }
        delay(wait);
      }  
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
      assignLayer(h+j, c.Color(r1+rSlope*j, g1+gSlope*j, b1+bSlope*j));
      assignLayer(h+j-1, backgroundColor);

      if(h+j == 0)
      assignLayer(11, backgroundColor);
    }
    

    delay(50);
    showAll();

    for (int h=0; h<11; h=h+waves) {
      assignLayer(h+j, backgroundColor);
    }
  }
}

void waveDn(int waves, uint32_t tColor1, uint32_t tColor2)
{ 
  for (int j=waves; j>=0; j--)
  {
    
    for (int h=0; h<11; h=h+waves)
    {
      assignLayer(h+j, tColor2);
    }

    delay(10);
    showAll();

    for (int h=0; h<11; h=h+waves) {
      assignLayer(h+j, tColor1);
    }
  } 
}

void displayAnim()
{  
  byte incomingByte;
  int offset = int(animBufferSize/11);
  for(int animCntr = 0; animCntr <= animBufferSize; animCntr++)
  { 
    if(animDir == 1)
    {
      for(int layerCntr = 0; layerCntr <= 11; layerCntr++)
      {
        incomingByte = Serial.read();
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
    }
    else
    {
      for(int layerCntr = 0; layerCntr <= 11; layerCntr++)
      {
        incomingByte = Serial.read();
        if((animCntr-(11-layerCntr)*offset) < 0)
        {
          assignLayer(layerCntr, prevAnim[animCntr-(11 - layerCntr)*offset+animBufferSize]); 
        }
        else
        {
          assignLayer(layerCntr, curAnim[animCntr-(11 - layerCntr)*offset]);
        }
        showLayer(layerCntr);
      }      
    }
//    showAll();
  }
  memcpy(prevAnim, curAnim, sizeof(curAnim));
}

void flashAnimUp()
{  
  int offset = int(animBufferSize/11);
  
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

void rainbow()
{
 rainbowSkip(10, 1);
 rainbowSkip(10, 1);
 rainbowSkip(10, 1);
 rainbowSkip(10, 1);
 rainbowSkip(6, -1);
 rainbowSkip(10, 1);
 rainbowSkip(6, -1);
 rainbowSkip(6, -1);
}

void rainbowSpeed()
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
delay(5000);

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
      assignLayer(l, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
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
      assignLayer(0, Wheel((dir*rSkipCounter) &255));
      assignLayer(1, Wheel((dir*rSkipCounter+int(rainbowOffset))&255));
      assignLayer(2, Wheel((dir*rSkipCounter+int(2*rainbowOffset))&255));
      assignLayer(3, Wheel((dir*rSkipCounter+int(3*rainbowOffset))&255));
      assignLayer(4, Wheel((dir*rSkipCounter+int(4*rainbowOffset))&255));
      assignLayer(5, Wheel((dir*rSkipCounter+int(5*rainbowOffset))&255));
      assignLayer(6, Wheel((dir*rSkipCounter+int(6*rainbowOffset))&255));
      assignLayer(7, Wheel((dir*rSkipCounter+int(7*rainbowOffset))&255));
      assignLayer(8, Wheel((dir*rSkipCounter+int(8*rainbowOffset))&255));
      assignLayer(9, Wheel((dir*rSkipCounter+int(9*rainbowOffset))&255));
      assignLayer(10, Wheel((dir*rSkipCounter+int(10*rainbowOffset))&255));
      assignLayer(11, Wheel((dir*rSkipCounter+int(11*rainbowOffset))&255));
      
      showAll();
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

void newSpeed(int nextSpeed)
{
  singleWave(curColor);
  
//  for(int buffCntr = 0; buffCntr <= floor(animBufferSize/newBufferSize); buffCntr++)
//  {singleWave(curColor);}

  int newBufferSize = (11-nextSpeed)*12-1; //Previously (11-nextSpeed)*11
  
  for(int arrayPos = 0; arrayPos <= newBufferSize; arrayPos++)
  {
    prevAnim[arrayPos] = curColor;
  }

  animBufferSize = newBufferSize;
}

void reverse()
{
  animDir = !animDir;

  for(int dirCntr = 0; dirCntr <= animBufferSize; dirCntr++)
  {
    tempAnim[dirCntr] = prevAnim[dirCntr];
  }

  for(int dirCntr = 0; dirCntr <= animBufferSize; dirCntr++)
  {
    prevAnim[animBufferSize - dirCntr] = tempAnim[dirCntr];
  }

  curColor = prevAnim[animBufferSize];
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
