#include <Arduino.h>

#define ADC_PIN   32 // analog pin O-3.3V

void setup() {
  pinMode(ADC_PIN, INPUT);        // set the pin as input
  Serial.begin(115200);           //  setup serial
}

void loop() {
  int val = analogRead(ADC_PIN);  // read the input pin (12 bit)
  Serial.println(val);          // debug value

  delay(100);
}