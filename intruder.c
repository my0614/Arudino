
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int distance =0;
int PIR = 7;
int checksum = 0;
int toggle = 0;
int num1=8,num2=9,num3 = 10; // 금고 비밀번호
char pass[4] = "123"; // 현재 금고 비밀번호
String str = "AAA";
int cnt = -1;

void buzzer()
{
  digitalWrite(6,1);
    delay(1000);
    digitalWrite(6,0);
    delay(1000);
}
void setup() {
 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1,0);
  Serial.begin(9600);
  lcd.print("Inruder System");
  pinMode(6,OUTPUT); // buzzer
  pinMode(7, INPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
}
void loop()
{ 
    
    pinMode(13,OUTPUT); //출력모드  초음파 출력
    digitalWrite(13, LOW); 
    delayMicroseconds(2); 
    digitalWrite(13,HIGH); 
    delayMicroseconds(10); 
    digitalWrite(13,LOW); 

    pinMode(13,INPUT);    //입력모드로 초음파 입력
    float duration = pulseIn(13, HIGH); 
    float distance = duration / 57.5;     

    Serial.println(distance);
   
  if(distance <=80) // 거리가 80cm 이하면
  {
    lcd.setCursor(0,1);
    lcd.print("ultra detection");
    delay(50);
    checksum = 3;
    delay(1000);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Inruder System");
    delay(1000);
  }

  if(checksum == 3)
  {
    int state = digitalRead(PIR);
     if(state == 1)
    {
       toggle = 1;  
    }
  }
  if(toggle == 1)
    { 
       lcd.setCursor(1,0);
       lcd.print("Inruder System");    
       lcd.setCursor(1,1);
       lcd.print("PIR detection");
       delay(1000);
    }
 
  if(digitalRead(num1) == 1) // 버튼을 누르면
  {
    cnt++;
    str.setCharAt(cnt,'1');
    Serial.print("bt1");
  }
  if(digitalRead(num2) == 1) // 버튼을 누르면
  {
    cnt++;
    str.setCharAt(cnt,'2');
    Serial.print("bt2");
  }
  if(digitalRead(num3) == 1) // 버튼을 누르면
  {
    cnt++;
    str.setCharAt(cnt,'3');
    Serial.print("bt3");
  }
  Serial.println(str);
  if(str.equals(pass) == 1)
  {
    lcd.clear();
    buzzer(); // 부저울리기
    Serial.println("equals");
    while(1)
    {
      lcd.setCursor(1,0);
      lcd.print("Inruder System");
      lcd.setCursor(3,1);
      lcd.print("success!!");
    } 
  }
  
  if(cnt>=2 && str.equals(pass) == 0)
  {
    lcd.clear();
    buzzer();
    while(1)
    {
      lcd.setCursor(1,0);
      lcd.print("Inruder System");
      lcd.setCursor(3,1);
      lcd.print("Danger!!");
    }
  }
  delay(500);
}
