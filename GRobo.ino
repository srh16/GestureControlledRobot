#include <SoftwareSerial.h>
#define r1 9     // right motor
#define r2 10
#define l1 11    // left motor
#define l2 12
char str[255];
int i=0;
void forward()
{
   digitalWrite(l1, HIGH);
   digitalWrite(l2, LOW);
   digitalWrite(r1, HIGH);
   digitalWrite(r2, LOW);
}
void backward()
{
   digitalWrite(l1, LOW);
   digitalWrite(l2, HIGH);
   digitalWrite(r1, LOW);
   digitalWrite(r2, HIGH);
}
void left()
{
   digitalWrite(l1, LOW);
   digitalWrite(l2, HIGH);
   digitalWrite(r1, HIGH);
   digitalWrite(r2, LOW);
}
void right()
{   
   digitalWrite(l1, HIGH);
   digitalWrite(l2, LOW);
   digitalWrite(r1, LOW);
   digitalWrite(r2, HIGH);
}
void Stop()
{
   digitalWrite(l1, LOW);
   digitalWrite(l2, LOW);
   digitalWrite(r1, LOW);
   digitalWrite(r2, LOW);
}
void repeat()
{
  int j=0;
  for(j=0;j<i-1;j++)
    test_cond(str[j]);
  i=0;
}
void test_cond(char k)
{
    if(k=='1')
      forward();
    else if(k=='2')
      right();
    else if(k=='3')
      left();    
    else if(k=='4')
      backward();
    else if(k=='5')
      Stop();
    else if(k='6')
      repeat();
}
void setup() 
{
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
}

void loop() 
{
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    Serial.println(ch);
    test_cond(str[i-1]); 
  }
}
