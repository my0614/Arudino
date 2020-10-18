#define start 11
#define reset 12

int hour; // 시간
int minute; //분
int second; //초
int count = 0; // start와 시리얼전송
int toggle =0;
int number = 0;

//전체값 초기화
void reset_bt()
{
  
   
  count =0;
  hour =0;
  second = 0;
  minute = 0;
  toggle = 0;
  number = 0;
  
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(start,INPUT_PULLUP); // start button
  pinMode(reset,INPUT_PULLUP); // reset button
  Serial.begin(9600); // 시리얼 통신
}

void loop() {
  if(digitalRead(reset) == HIGH)
  {
     toggle = 3;
  }
  if(toggle == 3)
  {
     reset_bt();
  }
  //startbutton 
  if(digitalRead(start) == HIGH)
  {
     
      toggle = 1;    
  }
  // start하기
  if(toggle == 1)
  {
        second++;     
        delay(100);
        
        if(second >= 59)
        {
          second=0;
          minute++;
        }
        if(minute >= 59)
        {
          minute =0;
          hour++;  
        }
        hour %= 24;

        if(digitalRead(start) == HIGH)
        {
          toggle = 2;
        }
        if(digitalRead(reset) == HIGH)
        {
          toggle = 3;
        }
     
    }
    // Serial로 시간출력
    if(toggle == 2)
    {
         count++;
         if(count %2 == 0)
        {
          
             number++;
          Serial.print("runner #");
          Serial.println(number);
          Serial.print(hour);
          Serial.print(":");
          Serial.print(minute);
          Serial.print(":");
          Serial.println(second);
          
       
            
        }
        // runner max 출력
        if(count >=21)
        {
          Serial.println("10 runner max");
          while(1)
          { 
            if(digitalRead(reset) == HIGH)
              {
                  reset_bt();
                  break;
              }
     
            delay(1000);
          }
            
          
        }
        if(digitalRead(start) == HIGH)
        {
          toggle = 1;
        }
        if(digitalRead(reset) == HIGH)
          {
              toggle = 3;
              //Serial.println("reset");
          }
     
     }

}
