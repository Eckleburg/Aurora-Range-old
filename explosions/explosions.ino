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

}

void loop() {

explosions(10, c.Color(255, 0, 0), c.Color(0, 0, 255));

}

void explosions(uint8_t exDelay, uint32_t exColor1, uint32_t exColor2)
{
  calcComp(exColor1, exColor2);
  calcSlopes(50);

  for(int exCtr = 0; exCtr < 50; exCtr++)
  {
    assignShape(10, 1, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
    showLayer(10);

    if(exCtr > 10)
    {
      assignShape(9, 1, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(9);     
    }
    
    if(exCtr > 20)
    {
      assignShape(8, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(8);     
    }

    if(exCtr > 30)
    {
      assignShape(7, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(7);     
    }

    if(exCtr > 40)
    {
      assignShape(6, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(6);     
    }
  }

    for(int exCtr = 50; exCtr > 0; exCtr--)
  {
    assignShape(10, 1, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
    showLayer(10);

    if(exCtr > 10)
    {
      assignShape(9, 1, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(9);     
    }
    else
    {
      assignShape(9, 1, c.Color(0, 0, 0));
      showLayer(9); 
    }
    
    if(exCtr > 20)
    {
      assignShape(8, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(8);     
    }
    else
    {
      assignShape(8, 0, c.Color(0, 0, 0));
      showLayer(8); 
    }

    if(exCtr > 30)
    {
      assignShape(7, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(7);     
    }
    else
    {
      assignShape(7, 0, c.Color(0, 0, 0));
      showLayer(7); 
    }

    if(exCtr > 40)
    {
      assignShape(6, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(6);     
    }
    else
    {
      assignShape(6, 0, c.Color(0, 0, 0));
      showLayer(6); 
    }

    if(exCtr == 1)
    {
      assignShape(10, 1, c.Color(0, 0, 0));
      showLayer(10);
    }
  }

calcSlopes(60);

  for(int exCtr = 0; exCtr < 60; exCtr++)
  {
    assignShape(11, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
    showLayer(11);

    if(exCtr > 10)
    {
      assignShape(10, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(10);     
    }
    else
    {
      assignShape(10, 0, c.Color(0, 0, 0));
      showLayer(10);
    }
    
    if(exCtr > 20)
    {
      assignShape(9, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(9);     
    }
    else
    {
      assignShape(9, 0, c.Color(0, 0, 0));
      showLayer(9);
    }

    if(exCtr > 30)
    {
      assignShape(8, 2, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(8);     
    }
    else
    {
      assignShape(8, 2, c.Color(0, 0, 0));
      showLayer(8);
    }

    if(exCtr > 40)
    {
      assignShape(7, 2, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(7);     
    }
    else
    {
      assignShape(7, 2, c.Color(0, 0, 0));
      showLayer(7);
    }

    if(exCtr > 50)
    {
      assignShape(6, 2, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(6);     
    }
    else
    {
      assignShape(6, 2, c.Color(0, 0, 0));
      showLayer(6);
    }
  }

  for(int exCtr = 60; exCtr > 0; exCtr--)
  {
    assignShape(11, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
    showLayer(11);

    if(exCtr > 10)
    {
      assignShape(10, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(10);     
    }
    else
    {
      assignShape(10, 0, c.Color(0, 0, 0));
      showLayer(10);
    }
    
    if(exCtr > 20)
    {
      assignShape(9, 0, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(9);     
    }
    else
    {
      assignShape(9, 0, c.Color(0, 0, 0));
      showLayer(9);
    }

    if(exCtr > 30)
    {
      assignShape(8, 2, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(8);     
    }
    else
    {
      assignShape(8, 2, c.Color(0, 0, 0));
      showLayer(8);
    }

    if(exCtr > 40)
    {
      assignShape(7, 2, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(7);     
    }
    else
    {
      assignShape(7, 2, c.Color(0, 0, 0));
      showLayer(7);
    }

    if(exCtr > 50)
    {
      assignShape(6, 2, c.Color(r1+rSlope*exCtr, g1+gSlope*exCtr, b1+bSlope*exCtr));
      showLayer(6);     
    }
    else
    {
      assignShape(6, 2, c.Color(0, 0, 0));
      showLayer(6);
    }
    
    if(exCtr == 1)
    {
      assignShape(11, 0, c.Color(0, 0, 0));
      showLayer(11);
    }

  }
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
void waveUp(int waves, int fadeSteps, uint32_t wait, uint32_t tColor1, uint32_t tColor2)
{   
  calcComp(tColor1, tColor2);
  calcSlopes(fadeSteps);
  for (int j=0; j<waves; j++)
  {
    for (int m=0; m<=fadeSteps; m++)
    {
      for (int h=0; h<=12; h=h+waves)
      {
        assignLayer(h+j, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
        showLayer(h+j);
        if((h+j)==0)
        {
          assignLayer(11, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));
          showLayer(11);
        }
        else
        
        {        
          assignLayer(h+j-1, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));
          showLayer(h+j-1);
        }
        
        delay(wait);
      }  
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
