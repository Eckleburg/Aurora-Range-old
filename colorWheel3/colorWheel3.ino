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

void setup() 
{
  uint8_t  brightness = 128;
  
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

  Serial.begin(9600);

}


void loop() {

colorWheel();

  

  }

void colorWheel()
{
  int wheelCntr, pixelCntr;
  int wheelSkip;

  //Turns on all layers 1 pixel/layer at a time.
  for(pixelCntr = 0; pixelCntr < 145; pixelCntr++)
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


uint32_t Wheel(float wheelPos) {
//  WheelPos = 255 - WheelPos;
  while(wheelPos > 255)
  wheelPos -= 255;
  while(wheelPos < 0)
  wheelPos += 255;

  if(wheelPos < 85) {
    return layer1.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if(wheelPos < 170) {
    wheelPos -= 85;
    return layer1.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return layer1.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
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


