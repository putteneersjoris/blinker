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

#include <WiFi.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int counter = 0;
void setup() {
  pinMode(25, OUTPUT);
  Serial.begin(115200);

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }

  delay(2000);         // wait for initializing

  
  oled.clearDisplay(); // clear display
  oled.setTextSize(1.7);          // text size
  oled.setTextColor(WHITE);     // text color
  oled.setCursor(0, 10);        // position to display
  // oled.println(counter); // text to display
  oled.println("temperature: 21"); // text to display
  oled.println("hunmidity: 38"); // text to display
  oled.display();               // show on OLED


  Serial.print("ESP Board MAC Address:  ");
  oled.println(WiFi.macAddress());



}

void loop() {

  delay(1000);
  digitalWrite(25, HIGH);
  delay(1000);
  digitalWrite(25, LOW);
  Serial.println('test');
}
