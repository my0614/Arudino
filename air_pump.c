#define RELAY 13 // RELAY 디지털 13번핀 사용

void setup() {
  Serial.begin(9600);  // 시리얼모니터통신 9600으로 설정
}

void loop() {
  int sensor = A0; //아날로그 A0번핀을 sensor변수로 설정
  int value = analogRead(sensor); // sensor값 아날로그로 읽기
   if(value >= 600) // 압력센서값 0~1023 사이에서 원하는 값 넣어주시면 됩니다.
    {
      digitalWrite(RELAY,HIGH); // 릴레이사용해서 on
      delay(1000); // 원하는 만큼 딜레이주시면 됩니다.
    }
   else
     {
      digitalWrite(RELAY,LOW); // 릴레이사용해서 모터 off
      delay(1000); // 원하는 만큼 릴레이주시면 됩니다.
    }
}
