// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();
  Serial.begin(9600);
}

String inString;
float A0_value = 0;
void loop()
{
    lcd.setCursor(0, 0);
    A0_value = analogRead(A0)*5.0/1023.0;
    lcd.print(A0_value);
    lcd.setCursor(5, 0);
  if(Serial.available()){
    inString = Serial.readStringUntil('\n');
  }
    if(inString == "#")
    {
      Serial.println("end");
    }
  Serial.println(A0_value);
    delay(1000);

}
 
