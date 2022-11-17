#include <Arduino.h>

#define DIGITAL_PIN  32 // digital pin O-3.3V

void setup() {
  pinMode(DIGITAL_PIN, INPUT);        // set the pin as input
  Serial.begin(115200);           //  setup serial
}

void loop() {
  uint8_t val = digitalRead(DIGITAL_PIN);  // val O or 1 or equivalent LOW or HIGH
  Serial.println(val);          // debug value
  delay(500);
  
}