/*
Title:   Two LED test program
Author:  Cheung Ka Wing
Date:    2018-12-29
Version: V1.0.0
*/

#define RED_LED_PIN  10
int redLedPin = 10; //declare Pin 10 as Red LED Pin
int blueLedPin = 9; //declare Pin 9 as Blue LED Pin
int redOnTime = 300; //Red LED On delay time
int redOffTime = 300; //Red LED Off delay time
int blueOnTime = 300; //Blue LED On delay time
int blueOffTime = 300; //Blue LED Off delay time
int forwardLoop = 50; // LED output higher
int e = 0;

int button = 7; //button on Pin 7
boolean ledState = true; //declare Led State default as High


void setup() {
  pinMode(redLedPin, OUTPUT); //Set redLedPin OUTPUT
  pinMode(blueLedPin, OUTPUT); //Set blueLedPin OUTPUT
  pinMode(button, INPUT); //Set button INPUT
  
}

void loop() {

if(button != HIGH){

    if(forwardLoop >= 30){ // Reset after every flash
      forwardLoop = 1;
  }

    for (int q = 1; q <= 3; q++){
 
    digitalWrite(redLedPin, HIGH);
    delay(redOnTime);
    digitalWrite(redLedPin, LOW);
    delay(redOffTime);
    digitalWrite(blueLedPin, HIGH);
    delay(blueOnTime);
    digitalWrite(blueLedPin, LOW);
    delay(blueOffTime);

  }   for (int w = 1; w <= 255; w = w + 5){
    analogWrite(redLedPin, e);
    analogWrite(blueLedPin, e);
    e = e + 5;
    delay(forwardLoop++);
    analogWrite(redLedPin, LOW);
    analogWrite(blueLedPin, LOW);
    delay(forwardLoop++);
  }

  }
  
  /*digitalWrite(redLedPin, ledState);
  digitalWrite(blueLedPin, ledState); 

  if(digitalRead(button) != LOW){
    ledState = !ledState;
    delay(200);
  } */
}
