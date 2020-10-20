void setup()
{
  Serial.begin(9600);  //PC와의 시리얼 통신 속도 설정
  pinMode(3, OUTPUT); // DC모터
}
void loop()
{
 
  int reading = analogRead(A1);  
 
  float voltage = reading * 5.0 / 1024.0;
  float temperature = voltage*100-50;
  float value = map(temperature, -40 , 124, 0, 255);
  analogWrite(3, value);
  
  Serial.print("read - ");
  Serial.print(reading);
  Serial.print(", value - ");
  Serial.println(value);
 
 delay(1000);   //1초 간격으로 측정
}

