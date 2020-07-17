#include <Servo.h> // 서보모터 헤더파일 사용
Servo myservo;

void button_fun();
void open_door();
void close_door();

int senserpin = 3;     // 센서 신호핀
int angle = 0; // 서보 모터 각도
int red_led = 5, blue_led = 4; // LED 5,4핀사용 (red_led, blue_led)
int button = 2; // button 2번핀 사용
int red_led_stat = 0;
long long int now, last;
int door_state=0; // 0-close, 1-open
int button_fun_state=0;

void setup() 
{
  Serial.begin(9600); // 시리얼 모니터 통신 9600으로
  myservo.attach(7); // 서보 모터 시작
  myservo.write(0);
  pinMode(senserpin, INPUT); // pir 감지
  
  pinMode(red_led,OUTPUT); // red_led LED
  pinMode(blue_led,OUTPUT); // blue_led LED
  pinMode(button, INPUT_PULLUP); // 버튼 입력모드

  attachInterrupt(digitalPinToInterrupt(button), button_fun, FALLING); // 인터럽트 설정

  digitalWrite(red_led,LOW);
  digitalWrite(blue_led,LOW);
}
void button_fun() // 버튼이 눌렸을때
{
  button_fun_state = 1;
  if(door_state == 0) // 문이 닫혀있으면 열기
    open_door();
}
void open_door() // 서보모터 열기
{
  
  door_state = 1;
  digitalWrite(blue_led, LOW);
  for( ; angle <=30; angle++) // 서보모터로 문열기 (3초동안)
  {
    myservo.write(angle*3);
    delay(100);  //0.05
    if(angle >= 27) delay(50);
    if(angle % 5 == 0) // red_led led깜빡이기
    {
      red_led_stat = ~(red_led_stat);
      digitalWrite(red_led, red_led_stat);
    }
  }
  digitalWrite(red_led, LOW);
  digitalWrite(blue_led, HIGH); // blue_led led점등
}
void close_door() // 모터 닫기
{
  int middle_state=0;
  door_state = 0;
  button_fun_state = 0;
  for(angle = 30; angle >= 0; angle--) // 서보모터로 문닫기
  {
    myservo.write(angle*3);
    delay(100); // 0.025
    if(angle <= 3) delay(50);
    int value = digitalRead(senserpin);
    if(value == HIGH)
    {
      delay(100);
      middle_state = 1;
      break;
    }
  }
  if(middle_state == 1)
  {
    delay(100);
    open_door();
  }
}
void loop() 
{
  int value = digitalRead(senserpin); // 센서값 읽어오기
  if((value == HIGH && door_state==0) || button_fun_state==1) // 감지되면
  {
    if(button_fun_state==0) open_door(); // 열기
    last = millis();
    while(1)
    {
      now = millis();
      if(now > last + 5000) { // 5초간 감지가 되지 않으면 문 닫기
        close_door();
        if(door_state == 0) break;
        last = millis();
      }
      value = digitalRead(senserpin); // 센서값 읽어오기
      if(value == HIGH) 
      {
        last = millis();
      }
    }
  }
}
