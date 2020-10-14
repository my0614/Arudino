
#define Front_L 2
#define Front_R 3
#define Left 4
#define Right 5
#define Back 6


void setup()
{
  pinMode(Front_L,INPUT); // 적외선센서
  pinMode(Front_R,INPUT); // 적외선센서
  pinMode(Left,INPUT);
  pinMode(Right,INPUT);
  pinMode(Back,INPUT);
  pinMode(8,OUTPUT); // LED
  Serial.begin(9600);
    
}

void loop()
{
  
  int front_L = digitalRead(Front_L);
  int front_R = digitalRead(Front_R);
  int back = digitalRead(Back);
  int left = digitalRead(Left);
  int right = digitalRead(Right);

  Serial.println("start");

  if(front_L == 1 && front_R == 1  && left == 1 && right == 1 && back == 1)
  {
     Serial.println("십자교차로");
  }
  // ㅓ교차로
  else if(front_L == 1 && front_R == 0 && right == 0 && left== 1 && back == 1)
  {
    
    Serial.println("ㅓ교차로");
  }
  //ㅏ 교차로
  else if(front_L == 0 && front_R == 1 && right == 1 && left == 0 && back == 1)
  {
    Serial.println("ㅏ교차로");
  }
  // ㄱ교차로
  else if(front_L == 0 && front_R == 0 && right == 0 && left == 1 && back == 0)
  {
    
    Serial.println("ㄱ교차로");
  }
  // ㄱ거꾸로 교차로
  else if(front_L == 0 && front_R == 0 && right == 1 && left == 0 && back == 1)
  {
    
    Serial.println("ㄱ거꾸로교차로");
  }
  // ㅣ일자 교차로
  else if(front_L ==  1 && front_R == 1 && right == 0 && left == 0 && back == 1 )
  {
    
    Serial.println("ㅣ일자교차로");
  }
  //ㅜ교차로
   else if(front_L == 0 && front_R == 0 && right == 1 && left == 1 && back== 1 )
  {
    
    Serial.println("ㅜ교차로");
  }
  
  
    delay(1000);
  
 
}

