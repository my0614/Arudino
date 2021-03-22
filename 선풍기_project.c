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
  pinMode(speed_3, INPUT_PULLUP); 
  pinMode(motorPin, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
} 

void loop() 
{ 
  int power_state = digitalRead(powerbt); // 상태값 읽기
  int sensor = analogRead(temp);
  float voltage = sensor * 5000.0/1024.0;     // 온도센서의 값을 전압으로 변환
  float temp_re = (voltage - 500) / 10.0;     // 전압을 온도로 변환
  Serial.println(temp_re);
  if(temp_re >= 33) temp_state = 1;
  else temp_state = 0;
  if(temp_state == 1) power_toggle =1;
  if(power_state == HIGH)  power_toggle = 1;

  // 전원버튼 눌렀을때
  if(power_toggle == 1)
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
          analogWrite(motorPin, 80); // 속도 하
          Serial.println("speed_1");
          break;
        case 2:
          analogWrite(motorPin, 160); // 속도 중
          Serial.println("speed_2");
          break;
       case 3:
          analogWrite(motorPin, 250); // 속도 상
          Serial.println("speed_3");
          break;
      }
    
    if(power_state ==HIGH && temp_state != 1)
    {
      speed_toggle = 0;
        power_toggle = 0;
    }
    if(power_state == HIGH && temp_state ==1){}
  }
  
  if(power_toggle == 0 && speed_toggle == 0)
  {
    analogWrite(motorPin, 0); // 모터 멈추기
    Serial.println("stop");
    if(power_state == HIGH)
    {
      power_toggle = 1;
    }
  }
} 


