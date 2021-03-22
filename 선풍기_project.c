int motorPin = 3; // dc모터(pwm)
int powerbt = 8; // 전원버튼
int speed_1 = 9; // 속도 하
int speed_2 = 10; // 속도 중
int speed_3 = 11; // 속도 상
int temp = 13; // 온도센서
int power_toggle = 0; // 상태값
int speed_toggle = 0; // 속도상태값


void setup() 
{ 
  pinMode(powerbt, INPUT_PULLUP);
  pinMode(speed_1, INPUT_PULLUP); 
  pinMode(speed_2, INPUT_PULLUP); 
  pinMode(speed_3, INPUT_PULLUP); 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  int power_state = digitalRead(powerbt); // 상태값 읽기
  if(power_state == HIGH)
  {
    power_toggle = 1;
  }

  // 전원버튼 눌렀을때
  if(power_toggle == 1)
  {
    int speed_state1 = digitalRead(speed_1); // 상태값 읽기
    int speed_state2 = digitalRead(speed_2); // 상태값 읽기
    int speed_state3 = digitalRead(speed_3); // 상태값 읽기
    Serial.println("start");
     if(speed_state1 == HIGH)
     {
        speed_toggle = 1;
     }
     if(speed_state2 == HIGH)
     {
        speed_toggle = 2;
   
     }
     if(speed_state3 == HIGH)
     {
        speed_toggle = 3;
        
     }

     if(speed_toggle == 1)
     {
       analogWrite(motorPin, 80); // 속도 하
       Serial.println("speed_1");
      
     }
     
     if(speed_toggle == 2)
     {
       analogWrite(motorPin, 160); // 속도 중
       Serial.println("speed_2");
      
     }
     if(speed_toggle == 3)
     {
       analogWrite(motorPin, 250); // 속도 상
       Serial.println("speed_3");
       
     }
	
    if(po
  }
  if(power_toggle == 0)
  {
    analogWrite(motorPin, 0); // 모터 멈추기
    Serial.println("power_stop");
  }  

} 


