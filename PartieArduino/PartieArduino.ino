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
  String whatDoUWant = "";
  if(Serial.available()) whatDoUWant = Serial.readString();
  if(whatDoUWant != "") Serial.println(whatDoUWant);
  if(whatDoUWant == "Temperature") {Serial.print("Temp: ");Serial.println(get_temperature());}
  if(whatDoUWant == "Sound") {Serial.print("Sound: ");Serial.println(get_sound());}
  if(whatDoUWant == "Light") {Serial.print("Light: ");Serial.println(get_light());}
  if(whatDoUWant == "Moisture") {Serial.print("Moisture: ");Serial.println(get_moisture());}
}
