#include <ArduinoJson.h>
#include <string.h>

void setup() {
  Serial.begin(9600);
}

float get_temperature(){
  return map(analogRead(1), 0, 1024, 0, 40);
}

float get_sound(){
  return map(analogRead(3), 0, 1024, 0, 40);
}

float get_light(){
  return map(analogRead(0), 0, 1024, 0, 40);
}

float get_moisture(){
  return map(analogRead(4), 0, 1024, 0, 100);
}

void loop() {
  StaticJsonDocument<1024> info;
  
  info["temperature"] = String(get_temperature());
  info["sound"] = String(get_sound());
  info["light"] = String(get_light());
  info["moisture"] = String(get_moisture());

  serializeJson(info, Serial);
  Serial.println();
  delay(100);
}
