#include <Stepper.h>
#include <DHT11.h>

int pin = A0; // 핀설정
DHT11 dht11(pin);

const int stepsPerRevolution = 2048;  // 2048:한바퀴(360도), 1024:반바퀴(180도)

Stepper myStepper(stepsPerRevolution,12,10,11,8); // 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1    
void setup() {
  myStepper.setSpeed(50); // 속도제어
  Serial.begin(9600);
}
void loop() {
  int i;
  float humi, temp;
  if((i = dht11.read(humi, temp)) == 0)
  { 
    Serial.print("humidity:"); 
    Serial.println(humi); // 습도값 출력
    Serial.print("temperature:");
    Serial.println(temp); // 온도값 출력
  }
  else
  {
     Serial.print("Error:"); 
     Serial.print(i);
  }
  
  if( temp >= 24 & humi >= 30)// 원하시는 조건 값
  {
    myStepper.step(-stepsPerRevolution); // 시계방향으로 회전
    delay(1000);
  }
  
}
