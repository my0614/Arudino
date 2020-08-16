#define onoff 8
#define dir 9
#define pwm 10
int value = 126;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(onoff, OUTPUT); // on /off
  pinMode(dir, OUTPUT); // DIR
  pinMode(pwm, OUTPUT); // pwm
}

void loop()
{
  if (Serial.available())
  {
    String str;
    str = Serial.readString();

    if (str == "up")
    {
      value += 20;
    }
    else if (str == "down") value -= 20;
    Serial.println(value);
    
    if ( str == "1") // 정회전
    {
      analogWrite(pwm, value);
      digitalWrite(dir, 0);
      digitalWrite(onoff, 0);
    }

    if (str == "0") // 정지
    {
      digitalWrite(pwm, 0);
      digitalWrite(dir, 0);

