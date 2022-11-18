#include <Arduino.h>



void setup() {
  Serial.begin(115200);

  pinMode(2, OUTPUT); 

}

void loop() {
  int val = 123;
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  Serial.println(val);
  delay(200);

}