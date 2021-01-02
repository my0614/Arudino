
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
 
  lcd.begin(16, 2);
  Serial.begin(9600);
  
}

void loop() {
    lcd.clear();
	int read = analogRead(A0);
  	float temp = (5.0 * read * 100) /1024;
  	lcd.print(temp);
    Serial.print("temp:");
  	Serial.println(temp);
  	if(temp > 100)
    {
    	lcd.setCursor(0,1);
      	lcd.print("Danger");
      	delay(50);
    }
  	else if ((80 >= temp) && (temp >=50))
    {
    	lcd.setCursor(0,1);
      	lcd.print("Good");
        delay(50);
    }
  	else if (temp <= 15)
    {
    	lcd.setCursor(0,1);
      	lcd.print("Bad");
        delay(50);
    }
  	
  	delay(1000);

}

