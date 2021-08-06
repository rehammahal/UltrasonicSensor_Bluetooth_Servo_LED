#include <Servo.h> 

int triggerPin = 7; 
int echoPin = 8;   
int LED = 12;
int info = 0;
int state = 0;
long duration;
long timeStart;
int distance;
Servo Servo1;


void setup() { 
  
  Serial.begin(9600);  
  
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);   
  digitalWrite(LED, LOW);  

  Servo1.write(0); 
  Servo1.attach(11); 

  while(!Serial)
  {
    
  }
}

void loop(){
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0,034 / 2;


  if(distance <=15){
    timeStart = millis();
    while(distance <=15){
      if(millis() - timeStart == 3000){
        digitalWrite(LED, HIGH);  // HERE, LED IS INSTEAD OF VIDEO
        Servo1.write(90);
        delay(100);
        break;
      }
      
    }
    
  }else{
    delay(1000);
    digitalWrite(LED, LOW);  // HERE, LED IS INSTEAD OF VIDEO
    Servo1.write(0);
  }

}
