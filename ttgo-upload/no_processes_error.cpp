

/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-oled
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HTTPClient.h>

#include <WiFi.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define LIGHT_SENSOR_PIN 36

int counter = 0;
HTTPClient http;
String mac;



// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid = "WiFi Fritzbox";
const char* password = "jorisputteneers";
// const char* ssid = "Techtile";
// const char* password = "Techtile229";
// const char* ssid = "HTC";
// const char* password = "biodesign";
// const char* ssid = "beyin_gocu_2.4";
// const char* password = "denizecebora";


void setup() {
  pinMode(25, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  Serial.begin(115200);

  delay(1000);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  // dont use adc2 pins if you want to use wifi
  while(WiFi.status() != WL_CONNECTED){
      Serial.print(".");
      oled.print(".");
      delay(100);
  }

  Serial.println("Connected to the WiFi network");
  Serial.println(WiFi.localIP());
  mac = WiFi.macAddress();



  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(100);         
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(0, 10);

  oled.setTextSize(2);
  oled.println("MAC");
  oled.setTextSize(1);
  oled.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());
  oled.display();   
  delay(3000);   
}

//functions
void blinkLed(){
  digitalWrite(25,LOW);
  delay(200);
  digitalWrite(25,HIGH);
  delay(200);
}

uint16_t readSensor(){
  return analogRead(LIGHT_SENSOR_PIN);
}


void printOled(){
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 10);
  oled.println(readSensor());
  oled.println(WiFi.localIP());
  oled.display();   
  delay(2000);
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



void loop() {
  blinkLed();
  // printOled();


  sendData(100, "testing", "time");



  // http.begin("http://hasdata.xyz/");
  // http.addHeader("Content-Type", "application/json");

  // String putMsg = "{\"mac\":\"";
  // putMsg.concat('mac');
  // putMsg.concat("\", \"type\":");
  // putMsg.concat('type');
  // putMsg.concat(",\"metric\":");
  // putMsg.concat('metric');
  // putMsg.concat(", \"value\":\"");
  // putMsg.concat('value');
  // putMsg.concat("\"}");

  // Serial.println(putMsg);

  // int httpResponseCode = http.PUT(putMsg);
  // Serial.println(httpResponseCode);

  // http.end();

  delay(10000);
}






// oled.clearDisplay();
// oled.setTextSize(1);
// oled.setCursor(0, 10);

// oled.println(putMsg);
// oled.display(); 