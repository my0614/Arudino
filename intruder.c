
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

// 부저 1동안 울리는 함수
void buzzer()
{
    digitalWrite(6,1); // 부저 1초동안 HIGH
    delay(1000);
    digitalWrite(6,0); // 부저 1초동안 LOW
    delay(1000);
}

void setup() {
 
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1,0);
  Serial.begin(9600);

  // LCD 처음셋팅
  lcd.print("Inruder System");
  pinMode(6,OUTPUT); // buzzer
  pinMode(7, INPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
}
void loop()
{ 
 // 초음파센서 값 읽기
    pinMode(13,OUTPUT);
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
  // 아니면 그대로 Intruder만 출력하기 (감지가 안되었으니깐)
  else
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Intruder System");
    delay(1000);
  }

// 초음파센서가 끝나면 PIR이 센서가 감지되도록
  if(checksum == 3)
  {
    int state = digitalRead(PIR); // PIR센서 감지하기
     if(state == 1)
    {
       toggle = 1;  // 감지되면 toggle 변수 값 바꿔주기
    }
  }
  // PIR감지시 LCD에 PIR센서감지 출력하기
  if(toggle == 1)
    { 
       lcd.setCursor(1,0);
       lcd.print("Intruder System");    
       lcd.setCursor(1,1);
       lcd.print("PIR detection");
       delay(1000);
    }
 
  if(digitalRead(num1) == 1) // 버튼1을 누르면
  {
    cnt++;
    str.setCharAt(cnt,'1'); // setCharAt 함수를 사용해서 현재 누른 버튼의 인덱스의 값을 1로 바꾸기
    Serial.print("bt1");
  }
  if(digitalRead(num2) == 1) // 버튼2을 누르면
  {
    cnt++;
    str.setCharAt(cnt,'2'); // setCharAt 함수를 사용해서 현재 누른 버튼의 인덱스의 값을 2로 바꾸기
    Serial.print("bt2");
  }
  if(digitalRead(num3) == 1) // 버튼3을 누르면
  {
    cnt++;
    str.setCharAt(cnt,'3'); // setCharAt 함수를 사용해서 현재 누른 버튼의 인덱스의 값을 바꾸기
    Serial.print("bt3");
  }
  Serial.println(str); // 매번 비밀번호 

  // 만약 내가 누른 비밀번호가 원래의 비밀번호하고 같으면 
  if(str.equals(pass) == 1)
  {
    lcd.clear();
    buzzer(); // 부저함수 호출
    Serial.println("equals");
    // LCD화면에 success!! 출력하기 
    while(1)
    {
      lcd.setCursor(1,0);
      lcd.print("Intruder System");
      lcd.setCursor(3,1);
      lcd.print("success!!");
    } 
  }

  // 만약 누른 비밀번호가 다르면
  if(cnt>=2 && str.equals(pass) == 0)
  {
    lcd.clear();
    buzzer(); // 부저함수 호출
    //LCD에 Danger!! 출력하기
    while(1)
    {
      lcd.setCursor(1,0);
      lcd.print("Intruder System");
      lcd.setCursor(3,1);
      lcd.print("Danger!!");
    }
  }
  delay(500);
}
