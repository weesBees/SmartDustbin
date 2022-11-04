#include <Mouse.h>  
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo1;
Servo servo2;
int laserPin = 6;
const int trigpin= 8;  
const int echopin= 7;  
long duration;  
int distance;  
int pos=100;
int pos2=0;
#include "HX711.h"
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;  
const int LOADCELL_DOUT_PIN = 3; 
const int LOADCELL_SCK_PIN = 2; 
  
HX711 scale;

void setup(){  
  pinMode(12, OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(trigpin,OUTPUT);  
  pinMode(echopin,INPUT);  
  servo1.attach(9);
  servo2.attach(10);
  Serial.begin(9600);  
  servo1.write(pos);
  servo2.write(pos2);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  lcd.init(); // initialize the lcd
  lcd.backlight();
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, HIGH); 
     // move cursor to   (0, 0)
}  
long int weight=0;
bool block=false;
char state="N";
void loop(){  
  // if (scale.is_ready()) {
    long reading = scale.read();
    weight=map(reading,53520,107200,0,500);
if (weight>390){
      if(analogRead(A0)>850){
        if(pos>0){
   lcd.setCursor(0, 0); 
    lcd.print("Weight: ");
    lcd.print(weight);
    lcd.setCursor(0, 1);
lcd.print("FILLED     ");
digitalWrite(12,HIGH);
digitalWrite(5,HIGH);
Serial.write("FULL");
        }
 else{
      lcd.setCursor(0, 0); 
    lcd.print("Weight: ");
    lcd.print(weight);
    lcd.setCursor(0, 1);
   lcd.print("NOT FILLED");
   digitalWrite(12,LOW);
  digitalWrite(5,LOW);
  Serial.write("EMPTY");
 }
      }
 else{
      lcd.setCursor(0, 0); 
    lcd.print("Weight: ");
    lcd.print(weight);
    lcd.setCursor(0, 1);
   state="N";
   lcd.print("NOT FILLED");
   digitalWrite(12,LOW);
  digitalWrite(5,LOW);
    Serial.write("EMPTY");
 }
}
else{
     lcd.setCursor(0, 0); 
    lcd.print("Weight: ");
    lcd.print(weight);
    lcd.setCursor(0, 1);
  state="N";
  lcd.print("NOT FILLED");
  digitalWrite(12,LOW);
  digitalWrite(5,LOW);
    Serial.write("EMPTY");
}
 
    // Serial.print("weight: ");
    // Serial.println(weight);
  // } 
  // else {
  //   Serial.println("HX711 not found.");
  // }
  digitalWrite(trigpin,HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigpin,LOW);  
  duration=pulseIn(echopin,HIGH);  
  distance = duration*0.034/2; 
  // Serial.println(analogRead(A0)); 
  if (distance<20){
    if(pos>0){
 for (pos = 100; pos >= 0; pos -= 1) { 
   pos2=(pos-100)*-1;
    servo1.write(pos);
    servo2.write(pos2) ;         
    delay(15);      
  }
}

  }
else{
 
  if(pos<100){
   delay(5000);
  for (pos = 0; pos <= 100; pos += 1) {
    pos2=(pos-100)*-1;
    servo1.write(pos); 
    servo2.write(pos2);            
    delay(15);                       
  }
  }
}
} 

