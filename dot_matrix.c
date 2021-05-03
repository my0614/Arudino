
#include <LedControl.h>

LedControl Dote = LedControl(7, 6, 5, 1);

byte digits[4][8] = {
  {
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B10000000,
   B11111111
  },
   {
   B11111111,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B11111111
  },
   {
   B10000001,
   B10000001,
   B10000001,
   B10000001,
   B01000010,
   B01000100,
   B00101000,
   B00010000
  },
   {
   B11111111,
   B10000000,
   B10000000,
   B10000000,
   B11111111,
   B10000000,
   B10000000,
   B11111111
  }
};


void setup() 
{
  Dote.shutdown(0, false);
  Dote.setIntensity(0, 7);
  Dote.clearDisplay(0);
}

void loop() 
{
  int i, j;
  for(i=0;i<4;i++)
  {
   for (j = 0; j <8; j++)
   {
     Dote.setRow(0, j, digits[i][j]);
   }
   delay (500);
  }
}
