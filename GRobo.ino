#define r1 9     // right motor
#define r2 10
#define l1 11    // left motor
#define l2 12
#define er 8
#define el 13
char str[255];
int i=0;
void enable()
{
  digitalWrite(er, HIGH);
  digitalWrite(el, HIGH);
}
void disable()
{
   digitalWrite(er, LOW);
   digitalWrite(el, LOW);
}
void forward()
{
   enable();
   digitalWrite(l1, HIGH);
   digitalWrite(l2, LOW);
   digitalWrite(r1, HIGH);
   digitalWrite(r2, LOW);
   disable();
}
void backward()
{
   enable();
   digitalWrite(l1, LOW);
   digitalWrite(l2, HIGH);
   digitalWrite(r1, LOW);
   digitalWrite(r2, HIGH);
   disable(); 
}
void left()
{
   enable();
   digitalWrite(l1, LOW);
   digitalWrite(l2, HIGH);
   digitalWrite(r1, HIGH);
   digitalWrite(r2, LOW);
   disable();
}
void right()
{   
   enable();
   digitalWrite(l1, HIGH);
   digitalWrite(l2, LOW);
   digitalWrite(r1, LOW);
   digitalWrite(r2, HIGH);
   disable();
}
void Stop()
{
   disable();
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
  digitalWrite(7, HIGH);
  while(Serial.available())
  {
    //digitalWrite(7, HIGH);
    char ch=Serial.read();
    str[i++]=ch;
    test_cond(str[i-1]); 
  }
}
