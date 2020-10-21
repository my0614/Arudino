#define RED 11
#define BLUE 10
#define GREEN 9


int R_value=0;
int B_value=0;
int G_value=0;

void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  
  int reading = analogRead(A0);  
 
  float voltage = reading * 5.0 / 1024.0;
  float temperature = voltage*100-50; // 온도값
  Serial.println(temperature);
  if(temperature >= 34)
  {
      setcolor(180,0,180);
      digitalWrite(6,HIGH);
      delay(2000);   
      
  }
  else if(temperature >= 24)
  {
     setcolor(255,255,0);
     digitalWrite(6,LOW);
     delay(1000);
     
  }
  else if(temperature < 24)
  {
    setcolor(0,255,0);
     delay(1000);
  }
  
}

void setcolor(int red, int green, int blue)
{
      analogWrite(RED, red);
      analogWrite(BLUE, green);
      analogWrite(GREEN, blue);
  }
