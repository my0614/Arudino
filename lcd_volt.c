// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();
}

float A0_value = 0;
float A5_value = 0;

void loop()
{
 	
 	lcd.setCursor(0, 0);
    A0_value = analogRead(A0)*5.0/1023.0;
    lcd.print(A0_value);
    lcd.setCursor(5, 0);
    A5_value = analogRead(A5)*2.5/1023.0;
    lcd.print(A5_value);
 
  if(A0_value >= A5_value+1  || A0_value <= A5_value-1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Event: Over1[V]");
  }
  else
  {
    lcd.clear();
    
    lcd.setCursor(0, 0);
    A0_value = analogRead(A0)*5.0/1023.0;
    lcd.print(A0_value);
    lcd.setCursor(5, 0);
    A5_value = analogRead(A5)*2.5/1023.0;
    lcd.print(A5_value);
    
  }
  delay(1000);

  
}
 
