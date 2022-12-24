//초음파 : 29us에 1cm를 이동
//delayMicroseconds(us)
//duration = pulseIn(pin, HIGH);
#include <SoftwareSerial.h>
SoftwareSerial HC06(2, 3);
#define trig 4
#define echo 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC06.begin(9600);
  pinMode(trig,OUTPUT); //trig 발사
  pinMode(echo,INPUT); //echo 받기
}
int duration = 0;
void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = (pulseIn(echo, HIGH)/29.0)/2; //cm
  if(duration<10)
   {   
      HC06.println("ENOUGH");
   }
    else
   {
      HC06.println("NOT ENOUGH, NEED SUBSTITUTE");
    }
  
  delay(1000);
}
