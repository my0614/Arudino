void setup() {
Serial.begin(9600);
// 기울기 센서
pinMode(7, INPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
}



void loop() {
int tilt = digitalRead(7);
Serial.println(tilt);

if(tilt == 0)
{
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}
else
{
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
}
 delay(20);
 
}
