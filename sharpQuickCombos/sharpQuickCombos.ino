//1
  singleColorExpand(layer0.Color(0, 128, 255));
waveDn(6, layer0.Color(0, 128, 255), layer0.Color(255, 255, 102));
waveDn(6, layer0.Color(0, 128, 255), layer0.Color(255, 255, 102));
for(int g=0; g<20; g++)
{
waveDn(6, layer0.Color(204, 102, 0), layer0.Color(255, 255, 102));
}
  singleColorExpand(layer0.Color(255, 0, 0));
waveUp(11, layer0.Color(255, 0, 0), layer0.Color(0, 255, 0));
waveUp(4, layer0.Color(255, 0, 0), layer0.Color(0, 0, 255));
waveUp(3, layer0.Color(255, 0, 0), layer0.Color(0, 255, 255));
waveUp(2, layer0.Color(255, 0, 0), layer0.Color(0, 255, 0));
  singleColorExpand(layer0.Color(255, 0, 127));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 0, 255));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(5, layer0.Color(255, 0, 127), layer0.Color(0, 0, 255));
waveUp(11, layer0.Color(255, 0, 127), layer0.Color(0, 255, 0));
waveUp(11, layer0.Color(255, 0, 127), layer0.Color(0, 0, 255));
waveUp(9, layer0.Color(255, 0, 127), layer0.Color(0, 0, 255));
waveUp(6, layer0.Color(255, 0, 127), layer0.Color(0, 0, 255));
waveUp(6, layer0.Color(255, 0, 127), layer0.Color(0, 120, 255));
  singleColorExpand(layer0.Color(153, 204, 255));
  singleColorExpand(layer0.Color(102, 0, 51));
  singleColorClose(layer0.Color(0, 204, 102));


//2
waveUp(3, layer0.Color(255, 0, 0), layer0.Color(0, 255, 255));
waveUp(3, layer0.Color(0, 0, 0), layer0.Color(0,128,255));


//3
waveUp(3, layer0.Color(0, 0, 0), layer0.Color(0,128,255));

//4
waveUpFade(2, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(2, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(2, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));

void waveUpFade(int waves, uint32_t backgroundColor, uint32_t waveColor1, uint32_t waveColor2)
{ 
  calcComp(waveColor1, waveColor2);
  calcSlopes(waves);
  
  for (int j=0; j<waves; j++)
  {
    
    for (int h=0; h<11; h=h+waves)
    {
      assignColor(h+j, c.Color(r1+rSlope*j, g1+gSlope*j, b1+bSlope*j));
    }
    

    delay(50);
    showColors();

    for (int h=0; h<11; h=h+waves) {
      assignColor(h+j, backgroundColor);
    }
  }
}

//5
waveUpFade(4, c.Color(0, 128, 90), c.Color(58, 18, 109), c.Color(96, 20, 109));
waveUpFade(4, c.Color(0, 128, 90), c.Color(96, 20, 109), c.Color(154, 26, 108));
waveUpFade(4, c.Color(0, 128, 90), c.Color(154, 26, 108), c.Color(208, 34, 107));
waveUpFade(4, c.Color(0, 128, 90), c.Color(208, 34, 107), c.Color(255, 42, 106));
waveUpFade(4, c.Color(0, 128, 90), c.Color(255, 42, 106), c.Color(58, 18, 109));

//6
waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));

//7
waveUpFade(2, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(2, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(2, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(3, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(3, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(3, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(4, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(4, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(4, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(5, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(5, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(5, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(7, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(7, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(7, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(9, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(9, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(9, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));
waveUpFade(11, c.Color(128, 128, 128), c.Color(255, 0, 0), c.Color(0, 255, 0));
waveUpFade(11, c.Color(0, 0, 0), c.Color(0, 255, 0), c.Color(0, 0, 255));
waveUpFade(11, c.Color(128, 128, 128), c.Color(0, 0, 255), c.Color(255, 0, 0));

//8
singleColorFadeEx(5, c.Color(255, 0, 144));
curColor = c.Color(0, 255, 195);
singleColorFadeEx(5, c.Color(255, 255, 0));
curColor = c.Color(0, 255, 195);

//9
waveUp(3, layer0.Color(255, 0, 0), layer0.Color(0, 0, 255));

void waveUp(int waves, uint32_t tColor1, uint32_t tColor2)
{ 
  int fadeSteps = 15;
  
  calcComp(tColor1, tColor2);
  calcSlopes(fadeSteps);
  for (int j=0; j<waves; j++)
  {
    for (int h=0; h<11; h=h+waves)
    {
      for (int m=0; m<=fadeSteps; m++)
      {
        assignColor(h+j, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
        showLayer(h+j);
      }  
    }
//    delay(50);
//    showColors();

    for (int h=0; h<11; h=h+waves) 
    {
      assignColor(h+j, tColor1);
    }
  }   
}

//10
for (int sk = 0; sk <=5; sk++)
{
  waveUp(2, 15, 0, layer0.Color(255, 0, 0), layer0.Color(0, 250, 0));
}

for (int sk = 0; sk <=5; sk++)
{
  waveUp(2, 15, 0, layer0.Color(0, 255, 0), layer0.Color(0, 0, 255));
}

for (int sk = 0; sk <=5; sk++)
{
  waveUp(2, 15, 0, layer0.Color(0, 0, 255), layer0.Color(255, 0, 0));
}

}

//11
  waveUp(2, 15, 0, layer0.Color(255, 0, 0), layer0.Color(0, 250, 0));
  waveUp(2, 15, 0, layer0.Color(0, 0, 255), layer0.Color(255, 0, 0));
}

void waveUp(int waves, int fadeSteps, uint32_t wait, uint32_t tColor1, uint32_t tColor2)
{   
  calcComp(tColor1, tColor2);
  calcSlopes(fadeSteps);
  for (int j=0; j<waves; j++)
  {
    for (int m=0; m<=fadeSteps; m++)
    {
      for (int h=0; h<=11; h=h+waves-1)
      {
        assignColor(h+j, c.Color(r1+m*rSlope, g1+m*gSlope, b1+m*bSlope));
        if ((h+j)==0)
        {
          assignColor(11, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));
        }
        else
        {
          assignColor(h+j-1, c.Color(r2-m*rSlope, g2-m*gSlope, b2-m*bSlope));
        }
        
        showLayer(h+j);
        showLayer(h+j-1);
        delay(wait);
      }  
    }
  }   
}

//12
  waveUp(1, 15, 0, layer0.Color(255, 0, 0), layer0.Color(0, 250, 0));

//13
  waveUp(1, 50, 0, layer0.Color(255, 0, 0), layer0.Color(0, 250, 0));
  waveUp(1, 50, 0, layer0.Color(0, 0, 255), layer0.Color(255, 0, 0));

//14
void rainbowFade()
{
  for(int g=0; g<11; g=g+10) 
  {
    if(g < 60)
    {
      for(int skipRepeat = 0; skipRepeat<10; skipRepeat++)
      {
        rainbow_highskip(g);
      }
    }
    else
    {
      rainbow_highskip(g);
    }
  }
}

void rainbow_highskip(int skip) 
{
  int i;
  int j;

  for(j=255; j>0; j--)
  {
    if (j % skip == 0)     
    {     
      assignColor(0, Wheel((j) &255));
      assignColor(1, Wheel((j-22)&255));
      assignColor(2, Wheel((j-45)&255));
      assignColor(3, Wheel((j-68)&255));
      assignColor(4, Wheel((j+91)&255));
      assignColor(5, Wheel((j+114)&255));
      assignColor(6, Wheel((j+136)&255));
      assignColor(7, Wheel((j+159)&255));
      assignColor(8, Wheel((j+181)&255));
      assignColor(9, Wheel((j+204)&255));
      assignColor(10, Wheel((j+227)&255));
      assignColor(11, Wheel((j+250)&255));

//      for(int l=0; l<=11; l++)
//      {
//        assignColor(l, Wheel((l*250)/11 + j));
//      }
      
      showAll();
    }
  }
}

//15
 rainbowSkip(10, 1);
 rainbowSkip(10, 1);
 rainbowSkip(10, 1);
 rainbowSkip(10, 1);
 rainbowSkip(6, -1);
 rainbowSkip(10, 1);
 rainbowSkip(6, -1);
 rainbowSkip(6, -1);


