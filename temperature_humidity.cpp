#include <Arduino.h>
// #include "utils.h"
// #include "DFRobot_MICS.h"

/* value = temp (°C), humidity (%) */
#include "DHTesp.h"
int dht;

void setup()
{
  Serial.begin(115200);
  dht.setup(14, DHTesp::DHT22);
  
}

void loop()
{
  TempAndHumidity meas = dht.getTempAndHumidity();
  Serial.println(meas.temperature);
  Serial.println(meas.humidity);
  delay(2 * 1000);
}