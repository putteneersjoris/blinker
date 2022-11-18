#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>


const char *ssid = "HTC";
const char *password = "biodesign";


HTTPClient http;
String mac;

void setup()
{
  Serial.begin(115200);

  pinMode(2, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(2, HIGH);
    delay(500);
    Serial.println("Connecting to WiFi..");
    digitalWrite(2, LOW);
    delay(500);
  }

  Serial.println("Connected to the WiFi network");

  mac = WiFi.macAddress();
  Serial.println(mac);
}


void loop()
{
Serial.println('test');
}