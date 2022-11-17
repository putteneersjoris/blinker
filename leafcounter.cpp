#include <Arduino.h>

#define DIGITAL_PIN   32 // digital pin O-3.3V

void setup() {
  pinMode(DIGITAL_PIN, INPUT);        // set the pin as input
  Serial.begin(115200);           //  setup serial
}

int counter = 0;
void loop() {
  uint8_t val = digitalRead(DIGITAL_PIN); 
  if(val==1){
    counter ++;
  }
  Serial.println(counter);   
  delay(2000);       // debug value
}