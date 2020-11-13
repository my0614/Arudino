#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
 
DS1302 rtc(2,3,4); //rtc모듈
 
void setup()
{
  // I2C_LCD를 초기화 해줍니다.
  lcd.init();
  rtc.halt(false);
  rtc.writeProtect(false);
  // I2C_LCD의 백라이트를 켜줍니다.
  lcd.backlight();
  Serial.begin(9600);
  // I2C_LCD에 "Hello, world!"라는 메세지를 첫번째줄 첫번째칸에 출력합니다.(0, 0)
  lcd.setCursor(6, 0);
  lcd.print("Time");

  rtc.setTime(14,50,8);
  rtc.setDate(14,11,2020);
}
 
void loop()
{

    Serial.print(rtc.getDateStr());// 시리얼 모니터에 날짜 출력
 
    Serial.print(" -- ");
    lcd.setCursor(3,1);
    lcd.print(rtc.getTimeStr());
    Serial.println(rtc.getTimeStr());           // 시리얼 모니터에 시간 출력​

    delay(1000);                          


}



