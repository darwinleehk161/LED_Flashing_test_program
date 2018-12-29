/*
Title:   LED flashing test program
Author:  Cheung Ka Wing
Date:    2018-12-15
Version: V1.0.2
*/
int PIN_INPUT = 7;
int PIN_LIGHT_OUT = 11;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(PIN_LIGHT_OUT, LOW); //所有output pin都必需要給予一個default值, 而且要在將它設定為output之前給予. 這裡, 設定LED一開始是off 的.
  digitalWrite(PIN_INPUT, LOW);
  pinMode(PIN_INPUT, INPUT_PULLUP);        //Init pin 7 as a input pin
  pinMode(PIN_LIGHT_OUT, OUTPUT);   //Init pin 11 as an output pin
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead (PIN_INPUT) == HIGH){
    digitalWrite(PIN_LIGHT_OUT, HIGH);  //Set pin 11 to high upon detected pin 7 is NOT HIGH
    delay(20);               //Keeping HIGH for 20ms
    digitalWrite(PIN_LIGHT_OUT, LOW);   //Then turn it off
    delay(313);              //Delay 313ms before looping again, that creates 3Hz LED flashing as long as pin 7 keeping HIGH
  }
  else{
    digitalWrite(PIN_LIGHT_OUT, LOW);   //Turn off LED upon detected pin 7 is LOW
  }
  //There is a limitation on this program, the maximum response time from "pin 7 LOW" to LED off is 333ms
}
