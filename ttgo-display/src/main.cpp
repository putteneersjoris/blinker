

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



//functions
void blinkLed(){
  digitalWrite(25,LOW);
  delay(200);
  digitalWrite(25,HIGH);
  delay(200);
}




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

  delay(2000);         
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0, 10);

  oled.println("testing");
  oled.println(WiFi.macAddress());
  oled.display();   
  delay(10000);   
}

void printOled(int test){
  
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 10);
  oled.println(test);
  oled.display();   
  delay(200);
  
}


void loop() {
  blinkLed();
  counter ++;
  printOled(counter);

}

