#include <Arduino.h>

#define DIGITAL_PIN   32 // digital pin O-3.3V
// #define LED  2 // digital pin O-3.3V

void setup() {

  pinMode(DIGITAL_PIN, INPUT);        // set the pin as input
  pinMode(2, OUTPUT);
  Serial.begin(115200);  

}

void loop() {

  int val = digitalRead(DIGITAL_PIN); 

  if(val==1){

    digitalWrite(2, HIGH);
    

  }
  else{  
  digitalWrite(2, LOW);
   }
  Serial.println(val);
  delay(100);

}