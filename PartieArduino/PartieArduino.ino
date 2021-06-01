#include <string.h>

void setup() {
  Serial.begin(9600);
  Serial.println("Partie arduino - initialisation");
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
  while(Serial.available()){ whatDoUWant = Serial.readString();}
  if(whatDoUWant == "Temperature\n") {Serial.print("{\"temp\": ");Serial.print(get_temperature());Serial.println("}");}
  if(whatDoUWant == "Sound\n") {Serial.print("{\"sound\": ");Serial.print(get_sound());Serial.println("}");}
  if(whatDoUWant == "Light\n") {Serial.print("{\"light\": ");Serial.print(get_light());Serial.println("}");}
  if(whatDoUWant == "Moisture\n") {Serial.print("{\"moisture\": ");Serial.print(get_moisture());Serial.println("}");}
}
