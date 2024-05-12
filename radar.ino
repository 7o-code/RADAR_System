/*Libraries*/
#include <Servo.h> 

/*Objects*/
Servo myservo; 

/*MACROS*/
#define SERVO 2

#define ECHO 6
#define TRIGGER 7

/*Variables*/
int distance;
int degree;
 
void setup() { 
Serial.begin(9600);

myservo.attach(SERVO);

pinMode(ECHO, INPUT );
pinMode(TRIGGER, OUTPUT); 

delay(100); 
} 
 
 
void loop() { 

//raye7
for(degree=1; degree<180; degree+=1){ 
  myservo.write(degree);   
  delay(80);
  data();   
}

//rage3
for(degree=180; degree>1; degree-=1){ 
  myservo.write(degree);   
  delay(80);
  data();   
}

}

/*Functions*/
void data(){

  digitalWrite(TRIGGER, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGGER, HIGH); 
  delayMicroseconds(10); 
  long time = pulseIn(ECHO, HIGH); 
  distance = time / 28.5 / 2;

  if(distance>100){
    distance = 100;
  }


  Serial.print(degree);
  Serial.print( " ");
  Serial.println(distance);
}


