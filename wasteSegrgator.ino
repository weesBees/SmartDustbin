#include <Servo.h>

Servo topServo;
Servo botServo;
// top - 13      bot  - 7    IR  -  12     metal -  10
// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos=0;
void setup() {
  topServo.attach(13);
  botServo.attach(7);
  pinMode(8,INPUT);
  pinMode(7,INPUT); 
  topServo.write(0);
  botServo.write(0); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}
void moveMet(){
  if(pos==0){
    for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    botServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
    }
   else if(pos==60){
    for (pos = 60; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    botServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
    }
  }
void moveDry(){
  if(pos==60){
    for (pos = 60; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    botServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
    }
   else if(pos==120){
    for (pos = 60; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    botServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
    }
  }
void moveWet(){
  if(pos==0){
    for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    botServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
    }
   else if(pos==120){
    for (pos = 120; pos >= 60; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    botServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
    }
  }
void loop() {

 int water=analogRead(A0);
 int block=digitalRead(12);
 int metal=digitalRead(10);
Serial.println(block);
 if(block<1){
   if (metal==1){
  moveMet();
  delay(1500);
  for (pos1 = 0; pos1 <= 100; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    topServo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos1 = 100; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    topServo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }  
  }
else if (water<850){
  moveWet();
   delay(1500);
  for (pos1 = 0; pos1 <= 100; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    topServo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos1 = 100; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    topServo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
else{
  moveDry();
  delay(2000);
  for (pos1 = 0; pos1 <= 100; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    topServo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 100; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    topServo.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  }
  }
}