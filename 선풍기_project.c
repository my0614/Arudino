int motorPin = 3; // dc모터(pwm)
int powerbt = 8; // 전원버튼
int speed_1 = 9; // 속도 하
int speed_2 = 10; // 속도 중
int speed_3 = 11; // 속도 상
int temp = A0; // 온도센서
int power_toggle = 0; // 상태값
int speed_toggle = 5; // 속도상태값
int temp_state =0;
void setup() 
{ 
  pinMode(powerbt, INPUT_PULLUP);
  pinMode(speed_1, INPUT_PULLUP); 
  pinMode(speed_2, INPUT_PULLUP); 
  pinMode(4, OUTPUT);       // Motor B 방향설정1
  pinMode(5, OUTPUT);       // Motor B 방향설정2
  pinMode(motorPin, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
  digitalWrite(4, HIGH);    // Motor B 방향설정1
  digitalWrite(5, LOW);     // Motor B 방향설정2
} 
int power_state;
int sensor;
float temp_re;
 
void loop() 
{ 
  power_state = digitalRead(powerbt); // 상태값 읽기
  sensor = analogRead(temp);
  temp_re = (5.0 * sensor *100) / 1024;   // 전압을 온도로 변환
  Serial.println(temp_re);
  delay(500);
  if(temp_re >= 33)
  {
    analogWrite(3,80);
    play();
  }
  else temp_state = 0;
  if(temp_state == 1) power_toggle =1;
  if(power_state == HIGH)power_toggle = 1;
  // 전원버튼 눌렀을때
  if(power_toggle == 1)
  {
    play();
  }

  if(power_toggle == 0 && speed_toggle == 0)
  {
    analogWrite(3, 0);      // Motor B 속도조절 (0~255)
    Serial.println("stop");
    if(power_state == HIGH)
    {
      power_toggle = 1;
    }
  }
} 

void play()
{
    int speed_state1 = digitalRead(speed_1); // 상태값 읽기
    int speed_state2 = digitalRead(speed_2); // 상태값 읽기
    int speed_state3 = digitalRead(speed_3); // 상태값 읽기
    Serial.println("start");
     if(speed_state1 == HIGH) speed_toggle = 1;
     if(speed_state2 == HIGH) speed_toggle = 2;
     if(speed_state3 == HIGH) speed_toggle = 3;
      switch(speed_toggle)
      {
        case 1:
          analogWrite(3, 80);      // Motor B 속도조절 (0~255)
          Serial.println("speed_1");
          break;
        case 2:
          analogWrite(3, 160);      // Motor B 속도조절 (0~255)
          Serial.println("speed_2");
          break;
       case 3:
          analogWrite(3, 250);      // Motor B 속도조절 (0~255)
          Serial.println("speed_3");
          break;
      }
    
    if(power_state ==HIGH && temp_state != 1)
    {
      speed_toggle = 0;
        power_toggle = 0;
    }
    if(power_state == HIGH && temp_state ==1){}

    if(power_toggle == 0 && speed_toggle == 0)
  {
    analogWrite(3, 0);      // Motor B 속도조절 (0~255)
    Serial.println("stop");
    if(power_state == HIGH)
    {
      power_toggle = 1;
    }
  }
}

