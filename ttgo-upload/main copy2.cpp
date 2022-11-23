#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "utils.h"

const char *ssid = "WiFi Fritzbox";
const char *password = "jorisputteneers";


HTTPClient http;
String mac;

void setup()
{
 
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    Serial.println("Connecting to WiFi..");
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }

  Serial.println("Connected to the WiFi network");

  mac = WiFi.macAddress();

}

void sendData(uint8_t sensorID, String value, String time)
{
  http.begin("http://hasdata.xyz/");
  http.addHeader("Content-Type", "application/json");

  String putMsg = "{\"mac\":\"";
  putMsg.concat(mac);
  putMsg.concat("\", \"sensorID\":");
  putMsg.concat(sensorID);
  putMsg.concat(",\"value\":");
  putMsg.concat(value);
  putMsg.concat(", \"time\":\"");
  putMsg.concat(time);
  putMsg.concat("\"}");

  Serial.println(putMsg);

  int httpResponseCode = http.PUT(putMsg);

  http.end();
}

void loop()
{

sendData(100, 'testing', 'time');
delay(30 * 1000);
}