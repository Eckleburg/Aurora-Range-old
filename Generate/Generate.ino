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
  uint8_t  brightness = 160;
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
  curColor = c.Color(0, 0, 0);
}

void loop() 
{
int curExDelay;

curColor = c.Color(0, 0, 0);
setAll(c.Color(0, 0, 0));
  
delay(600);
assignShape(0, 1, c.Color(255, 0, 0));
showLayer(0);
delay(600);
assignShape(0, 1, c.Color(255, 255, 0));
showLayer(0);
delay(600);
assignShape(0, 1, c.Color(0, 255, 0));
showLayer(0);
delay(600);
assignShape(0, 1, c.Color(150, 150, 150));
showLayer(0);
delay(1000);
setAll(c.Color(0, 0, 0));
delay(1500);

newSpeed(7);
singleWave(c.Color(255, 0, 0));
singleWave(c.Color(0, 0, 255));
singleWave(c.Color(255, 0, 0));
newSpeed(10);

int strobeCntr;

for(strobeCntr = 0; strobeCntr < 2; strobeCntr++)
{
  strobe(c.Color(128, 128, 128), 150);
}

for(strobeCntr = 0; strobeCntr < 5; strobeCntr++)
{
  strobe(c.Color(255, 255, 255), 30);
}

for(strobeCntr = 0; strobeCntr < 7; strobeCntr++)
{
  strobe(c.Color(255, 255, 255), 10);
}

//doubleWave(c.Color(0, 255, 0), c.Color(0, 0, 255));
//doubleWave(c.Color(0, 255, 0), c.Color(0, 0, 255));
//doubleWave(c.Color(0, 255, 0), c.Color(0, 0, 255));
//doubleWave(c.Color(0, 255, 0), c.Color(0, 0, 255));

rainbowSkip(15, 1);
rainbowSkip(15, 1);
rainbowSkip(15, 1);


delay(40);

waveUp(11, 4, 0, c.Color(0, 0, 0), c.Color(255, 0, 255));
setAll(c.Color(0, 0, 0));
delay(100);
delay(220);

curExDelay = 220;

rainbowSkip(20, -1);
delay(curExDelay);
rainbowSkip(20, -1);
delay(curExDelay);
rainbowSkip(20, -1);
delay(curExDelay);

calcComp(c.Color(255, 255, 255), c.Color(0, 0, 0));
calcSlopes(17);
int fadeCntr;

for(fadeCntr = 0; fadeCntr < 18; fadeCntr++)
{
  setAll(c.Color(r1+rSlope*fadeCntr, g1+gSlope*fadeCntr, b1+bSlope*fadeCntr));
}

tripleWave(c.Color(0, 0, 255), c.Color(0, 255, 0), c.Color(0, 0, 0));
tripleWave(c.Color(0, 0, 255), c.Color(255, 255, 0), c.Color(255, 255, 255));
tripleWave(c.Color(0, 0, 255), c.Color(0, 255, 0), c.Color(0, 0, 0));
tripleWave(c.Color(0, 0, 255), c.Color(255, 255, 0), c.Color(0, 0, 0));
//Also here
delay(40);
waveUpFade(4, c.Color(0, 0, 0), c.Color(255, 0, 0), c.Color(0, 255, 255));
waveUpFade(4, c.Color(0, 0, 0), c.Color(255, 0, 0), c.Color(0, 255, 255));
delay(40);

reverse();
doubleWave(c.Color(0, 0, 255), c.Color(0, 255, 0));
doubleWave(c.Color(0, 0, 255), c.Color(0, 255, 0));
doubleWave(c.Color(0, 0, 255), c.Color(0, 255, 0));
doubleWave(c.Color(0, 0, 255), c.Color(0, 255, 0));
reverse();
doubleWave(c.Color(255, 0, 0), c.Color(255, 255, 0));
tripleWave(c.Color(255, 255, 255), c.Color(255, 255, 255), c.Color(255, 255, 255));

waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));
waveUp(4, 1, 0, c.Color(255, 255, 255), c.Color(255, 0, 0));

//waveUp(4, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
waveUp(4, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
waveUp(4, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
waveUp(4, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
waveUp(4, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
waveUp(4, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));

waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 255));
waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 255));
//waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 255));
//waveUp(4, 1, 0, c.Color(0, 0, 0), c.Color(0, 0, 0));

curColor = c.Color(0, 0, 0);
reverse();
tripleWave(c.Color(0, 0, 0), c.Color(0, 255, 255), c.Color(0, 0, 0));
tripleWave(c.Color(0, 255, 255), c.Color(0, 0, 0), c.Color(0, 255, 255));
tripleWave(c.Color(0, 0, 0), c.Color(0, 255, 255), c.Color(0, 0, 0));
tripleWave(c.Color(0, 0, 0), c.Color(0, 255, 255), c.Color(0, 0, 0));
delay(40);
delay(40);
waveUp(11, 1, 0, c.Color(0, 0, 0), c.Color(255, 0, 255));
waveDn(11, c.Color(0, 0, 0), c.Color(0, 0, 255));

reverse();
delay(120);
tripleWave(c.Color(0, 255, 255), c.Color(255, 255, 0), c.Color(255, 0, 255));
tripleWave(c.Color(0, 255, 255), c.Color(255, 255, 0), c.Color(255, 0, 255));
tripleWave(c.Color(0, 255, 255), c.Color(255, 255, 0), c.Color(255, 0, 255));
reverse();
tripleWave(c.Color(0, 0, 0), c.Color(0, 0, 0), c.Color(0, 0, 0));
setAll(c.Color(0, 0, 0));
delay(40);
waveDn(4, c.Color(0, 0, 0), c.Color(128, 0, 255));
waveDn(4, c.Color(0, 0, 0), c.Color(255, 255, 0));
waveDn(4, c.Color(0, 0, 0), c.Color(128, 0, 255));
delay(120);

setAll(c.Color(0, 255, 255));
delay(120);
setAll(c.Color(255, 0, 255));
delay(120);
setAll(c.Color(0, 255, 255));
delay(120);
setAll(c.Color(255, 0, 255));
delay(120);setAll(c.Color(0, 255, 255));
delay(120);
setAll(c.Color(255, 0, 255));
delay(120);
setAll(c.Color(0, 255, 255));
delay(120);
setAll(c.Color(255, 0, 255));
delay(120);
setAll(c.Color(0, 255, 255));
delay(120);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(255, 255, 0));
delay(40);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(255, 255, 0));
delay(40);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(255, 255, 0));
delay(40);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);
setAll(c.Color(255, 255, 0));
delay(40);
setAll(c.Color(0, 255, 255));
delay(40);
setAll(c.Color(255, 0, 255));
delay(40);

waveUp(11, 2, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
waveUp(11, 1, 5, c.Color(0, 0, 0), c.Color(255, 255, 255));
waveUp(11, 1, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
delay(320);
waveUp(11, 2, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
delay(120);
waveUp(11, 2, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
delay(120);
waveUp(11, 1, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
delay(120);

calcComp(c.Color(255, 255, 255), c.Color(0, 0, 0));
calcSlopes(17);

for(fadeCntr = 0; fadeCntr < 18; fadeCntr++)
{
  setAll(c.Color(r1+rSlope*fadeCntr, g1+gSlope*fadeCntr, b1+bSlope*fadeCntr));
}

curExDelay = 440;

chickenEx( 10, c.Color(0, 128, 255), c.Color(128, 0, 255));
delay(curExDelay);
wraithEx(10, c.Color(128, 0, 255), c.Color(255, 255, 0));
delay(curExDelay);
chickenEx( 10, c.Color(255, 0, 0), c.Color(0, 255, 0));
delay(curExDelay);
wraithEx(10, c.Color(255, 70, 0), c.Color(0, 43, 255));
delay(160);
wraithEx(10, c.Color(0, 0, 0), c.Color(255, 0, 0));
delay(360);

waveUp(11, 2, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
waveUp(11, 1, 5, c.Color(0, 0, 0), c.Color(255, 255, 255));
waveUp(11, 1, 0, c.Color(0, 0, 255), c.Color(255, 255, 255));
delay(300);
waveUp(11, 2, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
delay(120);
waveUp(11, 2, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
delay(120);
waveUp(11, 1, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
delay(40);
waveUp(11, 2, 0, c.Color(0, 255, 0), c.Color(255, 255, 255));
delay(120);
waveUp(11, 1, 0, c.Color(0, 0, 255 ), c.Color(255, 255, 255));
delay(200);
delay(120);

//Here
curColor = c.Color(0, 0, 0);

curExDelay = 180;

doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 255));
delay(curExDelay);
reverse();
doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 255));
delay(curExDelay);
reverse();
doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 255));
delay(curExDelay);
reverse();
doubleWave(c.Color(255, 255, 0), c.Color(0, 0, 255));
delay(curExDelay);

curColor = c.Color(0, 0, 0);

delay(220);
tripleWave(c.Color(255, 70, 0), c.Color(0, 43, 255), c.Color(0, 0, 0));
tripleWave(c.Color(0, 43, 255), c.Color(0, 0, 0), c.Color(0, 255, 213));
tripleWave(c.Color(255, 70, 0), c.Color(0, 43, 255), c.Color(0, 255, 213));
reverse();
tripleWave(c.Color(0, 0, 0), c.Color(0, 0, 0), c.Color(0, 0, 0));
tripleWave(c.Color(0, 0, 0), c.Color(0, 0, 0), c.Color(0, 0, 0));
reverse();

setAll(c.Color(255, 255, 255));
delay(380);

singleWave(c.Color(128, 0, 255));
singleWave(c.Color(0, 255, 0));
singleWave(c.Color(128, 0, 255));
delay(180);
reverse();
tripleWave(c.Color(0, 255, 0), c.Color(128, 0, 255), c.Color(0, 255, 0));
tripleWave(c.Color(128, 0, 255), c.Color(0, 255, 0), c.Color(0, 0, 0));
delay(180);

waveUp(11, 2, 0, c.Color(0, 0, 255), c.Color(0, 0, 0));
waveUp(11, 1, 5, c.Color(0, 0, 255), c.Color(0, 0, 0));
waveUp(11, 1, 0, c.Color(255, 70, 0), c.Color(0, 0, 0));
delay(300);
waveUp(11, 2, 0, c.Color(0, 0, 255), c.Color(0, 0, 0));
delay(120);
waveUp(11, 2, 0, c.Color(0, 0, 255), c.Color(0, 0, 0));
delay(120);
//waveUp(11, 1, 0, c.Color(0, 0, 0), c.Color(255, 255, 255));
//delay(40);
waveUp(11, 2, 0, c.Color(0, 255, 0), c.Color(0, 0, 0));
delay(120);
//waveUp(11, 1, 0, c.Color(0, 0, 255 ), c.Color(255, 255, 255));
//delay(200);
//delay(120);

setAll(c.Color(0, 0, 0));
delay(580);

singleWave(c.Color(227, 28, 227));
singleWave(c.Color(15, 240, 228));
singleWave(c.Color(227, 28, 227));
delay(180);
reverse();
tripleWave(c.Color(0, 0, 0), c.Color(227, 28, 227), c.Color(15, 240, 228));
tripleWave(c.Color(227, 28, 227), c.Color(0, 0, 0), c.Color(0, 0, 0));
tripleWave(c.Color(0, 0, 0), c.Color(0, 0, 0), c.Color(0, 0, 0));
delay(180);

//setAll(c.Color(255, 255, 255));
delay(5000);
delay(5000);

}

void strobe(uint32_t strobeColor, uint8_t strobeDelay)
{
  setAll(strobeColor);
  showAll();
  delay(strobeDelay);
  setAll(curColor);
  showAll();
  delay(strobeDelay);
}

void waggleloop() 
{
  for(int waggleCntr = 0; waggleCntr < 3; waggleCntr++)
  {
    waggle(30, layer0.Color(255, 255, 0), layer0.Color(102, 0, 51));
    waggle(30, layer0.Color(255, 255, 0), layer0.Color(0, 153, 76));
    waggle(30, layer0.Color(255, 255, 0), layer0.Color(52, 89, 149));
    waggle(30, layer0.Color(255, 255, 0), layer0.Color(251, 77, 61));
    waggle(30, layer0.Color(255, 255, 0), layer0.Color(0, 0, 0)); 
    waggle(30, layer0.Color(255, 255, 0), layer0.Color(0, 0, 0));
    
    waggle(30, layer0.Color(0, 0, 0), layer0.Color(102, 0, 51));
    waggle(30, layer0.Color(0, 0, 0), layer0.Color(0, 153, 76));
    waggle(30, layer0.Color(0, 0, 0), layer0.Color(52, 89, 149));
    waggle(30, layer0.Color(0, 0, 0), layer0.Color(251, 77, 61));
  }
}

void explosionLoop() 
{
  for(int explCntr = 0; explCntr < 3; explCntr++)
  {
    uint32_t exDelay = 2000;
    
    chickenEx(40, c.Color(0, 0, 255), c.Color(0, 255, 0));
    delay(exDelay);
    wraithEx(40, c.Color(255, 0, 0), c.Color(0, 0, 255));
    delay(exDelay);
    wraithEx(40, c.Color(255, 255, 0), c.Color(128, 0, 128));
    delay(exDelay);
    singleColorExpand(c.Color(0, 0, 0));
    delay(500);
    chickenEx(40, c.Color(0, 128, 255), c.Color(255, 255, 255));
    delay(exDelay);
    wraithEx(40, c.Color(0, 0, 0), c.Color(255, 0, 0));
    delay(exDelay);
    chickenEx(40, c.Color(0, 255, 255), c.Color(255, 0, 255));
    delay(exDelay);
    chickenEx(40, c.Color(0, 0, 0), c.Color(0, 0, 255));
    delay(exDelay);
    wraithEx(40, c.Color(255, 70, 0), c.Color(0, 255, 213));
    delay(exDelay);
    singleColorExpand(c.Color(255, 255, 255));
    delay(exDelay);
  }
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

  curColor = c.Color(0, 0, 0);
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

void colorWheel()
{
  colorWheelOpen();
  colorWheelSkip(3);
  colorWheelSkip(3);
  colorWheelSkip(3);
  for(int loopCntr = 0; loopCntr < 5; loopCntr++)
  {
    colorWheelSkip(5);
  }
  
  for(int loopCntr = 0; loopCntr < 5; loopCntr++)
  {
    colorWheelSkip(10);
  }
  colorWheelSkip(5);
  colorWheelClose();
}

void colorWheelOpen()
{
  //Turns on all layers 1 pixel/layer at a time.
  for(int pixelCntr = 0; pixelCntr < 145; pixelCntr++)
  {
    layer0.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length0));
    layer1.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length1));
    layer2.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length2));
    layer3.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length3));
    layer4.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length4));
    layer5.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length5));
    layer6.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length6));
    layer7.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length7));
    layer8.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length8));
    layer9.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length9));
    layer10.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length10));
    layer11.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length11));
    showAll();
  }
}

void colorWheelClose()
{
  //Turns off all layers 1 pixel/layer at a time.
  for(int pixelCntr = 0; pixelCntr < 145; pixelCntr++)
  {
    layer0.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer1.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer2.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer3.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer4.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer5.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer6.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer7.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer8.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer9.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer10.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    layer11.setPixelColor(pixelCntr, c.Color(0, 0, 0));
    showAll();
  }
}

void colorWheelSkip(int wheelSkip)
{
  int wheelCntr, pixelCntr;

  for(wheelCntr = 0; wheelCntr < 255; wheelCntr += wheelSkip)
  {
    for(pixelCntr = 0; pixelCntr < length0; pixelCntr++)
    {
      layer0.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length0 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length1; pixelCntr++)
    {
      layer1.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length1 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length2; pixelCntr++)
    {
      layer2.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length2 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length3; pixelCntr++)
    {
      layer3.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length3 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length4; pixelCntr++)
    {
      layer4.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length4 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length5; pixelCntr++)
    {
      layer5.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length5 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length6; pixelCntr++)
    {
      layer6.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length6 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length7; pixelCntr++)
    {
      layer7.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length7 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length8; pixelCntr++)
    {
      layer8.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length8 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length9; pixelCntr++)
    {
      layer9.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length9 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length10; pixelCntr++)
    {
      layer10.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length10 + wheelCntr));
    }
    
    for(pixelCntr = 0; pixelCntr < length11; pixelCntr++)
    {
      layer11.setPixelColor(pixelCntr, Wheel(pixelCntr*255/length11 + wheelCntr));
    }
    showAll();
  }
}

void chickenEx(uint8_t exDelay, uint32_t exColor1, uint32_t exColor2)
{
  calcComp(exColor1, exColor2);
  calcSlopes(11);
  
  assignShape(10, 1, c.Color(r1+rSlope, g1+gSlope, b1+bSlope));
  showLayer(10);
  delay(exDelay);
  assignShape(9, 1, c.Color(r1+rSlope*2, g1+gSlope*2, b1+bSlope*2));
  showLayer(9);
  delay(exDelay);
  assignShape(8, 0, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  layer8.show();
  delay(exDelay);
  assignShape(7, 0, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  showLayer(7);
  delay(exDelay);
  assignShape(6, 0, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  showLayer(6);
  delay(exDelay);
  assignShape(6, 1, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  assignShape(5, 2, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  showLayer(6);
  showLayer(5);
  delay(exDelay);
  assignShape(5, 3, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  assignShape(4, 0, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  assignShape(7, 1, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  showLayer(5);
  showLayer(4);
  showLayer(7);
  delay(exDelay);
  assignShape(3, 0, c.Color(r1+rSlope*8, g1+gSlope*8, b1+bSlope*8));
  assignShape(4, 1, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  assignShape(8, 1, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  showLayer(3);
  showLayer(4);
  showLayer(8);
  delay(exDelay);
  assignShape(9, 2, c.Color(r1+rSlope*2, g1+gSlope*2, b1+bSlope*2));
  assignShape(4, 2, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  assignShape(2, 0, c.Color(r1+rSlope*9, g1+gSlope*9, b1+bSlope*9));
  assignShape(2, 1, c.Color(r1+rSlope*9, g1+gSlope*9, b1+bSlope*9));
  showLayer(9);
  showLayer(4);
  showLayer(2);  
  delay(exDelay);
  assignShape(5, 0, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  assignShape(5, 1, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  assignShape(1, 0, c.Color(r1+rSlope*10, g1+gSlope*10, b1+bSlope*10));
  assignShape(1, 1, c.Color(r1+rSlope*10, g1+gSlope*10, b1+bSlope*10));
  showLayer(1);
  showLayer(5);
  delay(exDelay);
  assignShape(0, 0, c.Color(r1+rSlope*11, g1+gSlope*11, b1+bSlope*11));
  assignShape(4, 3, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  assignShape(6, 2, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  assignShape(6, 3, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  showLayer(0);
  showLayer(4);
  showLayer(6);
  delay(exDelay);
  assignShape(7, 2, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  assignShape(7, 3, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  assignShape(3, 1, c.Color(r1+rSlope*8, g1+gSlope*8, b1+bSlope*8));
  showLayer(3);
  showLayer(7);
  delay(exDelay);
  assignShape(8, 2, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  assignShape(8, 3, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  assignShape(2, 2, c.Color(r1+rSlope*9, g1+gSlope*9, b1+bSlope*9));
  showLayer(2);
  showLayer(8);
  delay(exDelay);
  assignShape(9, 0, c.Color(r1+rSlope*2, g1+gSlope*2, b1+bSlope*2));
  assignShape(1, 2, c.Color(r1+rSlope*10, g1+gSlope*10, b1+bSlope*10));
  showLayer(1);
  showLayer(9);
  delay(exDelay);
  assignShape(0, 1, c.Color(r1+rSlope*11, g1+gSlope*11, b1+bSlope*11));
  assignShape(10, 0, c.Color(r1+rSlope, g1+gSlope, b1+bSlope));
  showLayer(0);
  showLayer(10);
  delay(exDelay);
  assignShape(11, 0, c.Color(r1, g1, b1));
  showLayer(11);
  delay(exDelay);
}

void wraithEx(uint8_t exDelay, uint32_t exColor1, uint32_t exColor2)
{
  calcComp(exColor1, exColor2);
  calcSlopes(11);
  
  assignShape(11, 0, c.Color(r1, g1, b1));
  showLayer(11);
  delay(exDelay);
  assignShape(10, 0, c.Color(r1+rSlope, g1+gSlope, b1+bSlope));
  showLayer(10);
  delay(exDelay);
  assignShape(9, 0, c.Color(r1+rSlope*2, g1+gSlope*2, b1+bSlope*2));
  showLayer(9);
  delay(exDelay);
  assignShape(8, 2, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  layer8.show();
  delay(exDelay);
  assignShape(7, 2, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  showLayer(7);
  delay(exDelay);
  assignShape(6, 2, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  assignShape(6, 3, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  showLayer(6);
  delay(exDelay);
  assignShape(7, 3, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  assignShape(5, 0, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  assignShape(5, 1, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  showLayer(7);
  showLayer(5);
  delay(exDelay);
  assignShape(8, 3, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  assignShape(4, 3, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  assignShape(4, 2, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  showLayer(8);
  showLayer(4);
  delay(exDelay);
  assignLayer(3, c.Color(r1+rSlope*8, g1+gSlope*8, b1+bSlope*8));
  showLayer(3);
  delay(exDelay);
  assignLayer(2, c.Color(r1+rSlope*9, g1+gSlope*9, b1+bSlope*9));
  assignShape(4, 0, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  showLayer(2);
  showLayer(4);
  delay(exDelay);
  assignLayer(1, c.Color(r1+rSlope*10, g1+gSlope*10, b1+bSlope*10));
  assignShape(5, 2, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  showLayer(1);
  showLayer(5);
  delay(exDelay);
  assignLayer(0, c.Color(r1+rSlope*11, g1+gSlope*11, b1+bSlope*11));
  assignLayer(6, c.Color(r1+rSlope*5, g1+gSlope*5, b1+bSlope*5));
  showLayer(0);
  showLayer(6);
  delay(exDelay);
  assignLayer(7, c.Color(r1+rSlope*4, g1+gSlope*4, b1+bSlope*4));
  assignShape(5, 3, c.Color(r1+rSlope*6, g1+gSlope*6, b1+bSlope*6));
  showLayer(5);
  showLayer(7);
  delay(exDelay);
  assignLayer(8, c.Color(r1+rSlope*3, g1+gSlope*3, b1+bSlope*3));
  assignShape(4, 1, c.Color(r1+rSlope*7, g1+gSlope*7, b1+bSlope*7));
  showLayer(8);
  showLayer(4);
  delay(exDelay);
  assignLayer(9, c.Color(r1+rSlope*2, g1+gSlope*2, b1+bSlope*2));
  showLayer(9);
  delay(exDelay);
  assignLayer(10, c.Color(r1+rSlope, g1+gSlope, b1+bSlope));
  showLayer(10);
  delay(exDelay);
}

void waggle(int scale, uint32_t wColor, uint32_t fillColor)
{
  for(int j=0; j<scale; j++)
  { 
    for(int i=0; i<=144; i=i+scale)
    {
      for(int l=0; l<=11; l++)
      {
        assignPixel(l, i+j, wColor);
      }
    }
    showAll();
    delay(40);

  for(int i=0; i<=144; i=i+scale)
    {
      for(int l=0; l<=11; l++)
      {
        assignPixel(l, i+j, fillColor);
      }
    }
  }
}



void assignPixel(int layer, int pixel, uint32_t displayColor) 
{
  int i;
  
  switch(layer) {
    case 0:
        layer0.setPixelColor(pixel, displayColor);
      break;

    case 1:
        layer1.setPixelColor(pixel, displayColor);
      break;

    case 2:
        layer2.setPixelColor(pixel, displayColor);
      break;

    case 3:
        layer3.setPixelColor(pixel, displayColor);
      break;

    case 4:
        layer4.setPixelColor(pixel, displayColor);
      break;

    case 5:
        layer5.setPixelColor(pixel, displayColor);
      break;

    case 6:
        layer6.setPixelColor(pixel, displayColor);
      break;

    case 7:
        layer7.setPixelColor(pixel, displayColor);
      break;

    case 8:
        layer8.setPixelColor(pixel, displayColor);
      break;

    case 9:
        layer9.setPixelColor(pixel, displayColor);
      break;

    case 10:
        layer10.setPixelColor(pixel, displayColor);
      break;

    case 11:
        layer11.setPixelColor(pixel, displayColor);
      break;
      
    default:
      break;
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

void assignShape(int layer, int shape, uint32_t displayColor) 
{ 
  int shapeCounter;
  
  switch(layer)
  {
    case 0:
    switch(shape)
    {
      case 0:
      //Canyon 0
      for(shapeCounter=0; shapeCounter<26; shapeCounter++) {
        layer0.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:
      //Big Lake 0
      for(shapeCounter=26; shapeCounter<38; shapeCounter++) {
        layer0.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 1:
    switch(shape)
    {
      case 0:
      //Canyon 1
      for(shapeCounter=0; shapeCounter<29; shapeCounter++) {
        layer1.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 1:
      //Small Lake 1
      for(shapeCounter=30; shapeCounter<43; shapeCounter++) {
        layer1.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 2:
      //Big Lake 1
      for(shapeCounter=43; shapeCounter<66; shapeCounter++) {
      layer1.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;


    case 2:
    switch(shape)
    {
      case 0:
      //Canyon 2
      for(shapeCounter=0; shapeCounter<36; shapeCounter++) {
        layer2.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:
      //Small Lake 2
      for(shapeCounter=36; shapeCounter<61; shapeCounter++) {
        layer2.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 2:
      //Big Lake 2
      for(shapeCounter=61; shapeCounter<97; shapeCounter++) {
        layer2.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 3:
    switch(shape)
    {
      case 0:
      //Canyon 3
      for(shapeCounter=0; shapeCounter<73; shapeCounter++) {
        layer3.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:    
      //Big Lake 3
      for(shapeCounter=73; shapeCounter<112; shapeCounter++) {
        layer3.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 4:
    switch(shape)
    {      
      case 0:
      //West Ridge 4
      for(shapeCounter=0; shapeCounter<41; shapeCounter++) {
        layer4.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:
      //SL West 4
      for(shapeCounter=41; shapeCounter<54; shapeCounter++) {
        layer4.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 2:
      //East Ridge 4
      for(shapeCounter=54; shapeCounter<100; shapeCounter++) {
        layer4.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 3:
      //Big Lake 4
      for(shapeCounter=100; shapeCounter<144; shapeCounter++) {
        layer4.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 5:
    switch(shape)
    {
      case 0:
      //West Ridge 5
      for(shapeCounter=0; shapeCounter<46; shapeCounter++) {
        layer5.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:
      //Big Lake 5
      for(shapeCounter=46; shapeCounter<78; shapeCounter++) {
        layer5.setPixelColor(shapeCounter, displayColor);
      }
      break;      

      case 2:
      //East Ridge 5
      for(shapeCounter=78; shapeCounter<117; shapeCounter++) {
        layer5.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 3:
      //SL West 5
      for(shapeCounter=117; shapeCounter<137; shapeCounter++) {
        layer5.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 6:
    switch(shape)
    {
      case 0:  
      //Chicken 6
      for(shapeCounter=0; shapeCounter<33; shapeCounter++) {
        layer6.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:
      //Squid 6
      for(shapeCounter=33; shapeCounter<68; shapeCounter++) {
        layer6.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 2:
      //Wraith 6
      for(shapeCounter=68; shapeCounter<117; shapeCounter++) {
        layer6.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 3:
      //Sm Mtn 6
      for(shapeCounter=117; shapeCounter<137; shapeCounter++) {
        layer6.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 7:
    switch(shape)
    {
      case 0:
      //Chicken 7
      for(shapeCounter=0; shapeCounter<34; shapeCounter++) {
        layer7.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 1:    
      //Squid 7
      for(shapeCounter=34; shapeCounter<68; shapeCounter++) {
        layer7.setPixelColor(shapeCounter, displayColor);
      }
      break;

      case 2:
      //Wraith 7
      for(shapeCounter=68; shapeCounter<113; shapeCounter++) {
        layer7.setPixelColor(shapeCounter, displayColor);
      }
      break;
        
      case 3:
      //Sm Mtn 7
      for(shapeCounter=113; shapeCounter<125; shapeCounter++) {
        layer7.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 8:
    switch(shape)
    {
      case 0:
      //Chicken 8
      for(shapeCounter=0; shapeCounter<29; shapeCounter++) {
        layer8.setPixelColor(shapeCounter, displayColor);
      }
      break;
          
      case 1:
      //Squid 8
      for(shapeCounter=29; shapeCounter<57; shapeCounter++) {
        layer8.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 2:
      //Wraith 8
      for(shapeCounter=57; shapeCounter<98; shapeCounter++) {
        layer8.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 3:
      //Sm Mtn 8
      for(shapeCounter=98; shapeCounter<106; shapeCounter++) {
        layer8.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 9:
    switch(shape)
    {
      case 0:
      //Wraith 9
      for(shapeCounter=0; shapeCounter<48; shapeCounter++) {
        layer9.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 1:
      //Chicken 9
      for(shapeCounter=48; shapeCounter<64; shapeCounter++) {
        layer9.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 2:
      //Squid 9
      for(shapeCounter=64; shapeCounter<83; shapeCounter++) {
        layer9.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 10:
    switch(shape)
    {
      case 0:
      //Wraith 10
      for(shapeCounter=0; shapeCounter<27; shapeCounter++) {
        layer10.setPixelColor(shapeCounter, displayColor);
      }
      break;
      
      case 1:
      //Chicken 10
      for(shapeCounter=27; shapeCounter<38; shapeCounter++) {
        layer10.setPixelColor(shapeCounter, displayColor);
      }
      break;
    }
    break;

    case 11:
    //Wraith 11
          for(shapeCounter=0; shapeCounter<16; shapeCounter++) {
            layer11.setPixelColor(shapeCounter, displayColor);
          }
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

void setAll(uint32_t allColor)
{
  for(int layerCntr = 0; layerCntr < 12; layerCntr++)
  {
    assignLayer(layerCntr, allColor);
  }
  showAll();
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
  while(WheelPos > 255)
  WheelPos -= 255;
  while(WheelPos < 0)
  WheelPos += 255;
  
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
