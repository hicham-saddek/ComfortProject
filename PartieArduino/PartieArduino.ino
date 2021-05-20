#include <Wire.h>

#include <SoftwareSerial.h>

#include <Wire.h>
#include <rgb_lcd.h>  // Faut telecharger le fichier zip ici: https://github.com/Seeed-Studio/Grove_LCD_RGB_Backlight
#include <math.h>

rgb_lcd LCD;

typedef struct Color{
  int R = 255;
  int G = 255;
  int B = 255;
} Color;

Color white;

void setup() {
  LCD.begin(16, 2);
  LCD.setRGB(white.R, white.G, white.B);
  Serial.begin(9600);
  
}

void loop() {
  // Get Analog values
  // Get light value
  int light = analogRead(0);
  float lux = exp(0.007251*light);

  // Get Temprerature Value
  int tempValue = analogRead(1);
  float temperature = map(tempValue, 0, 1024, 0, 40);
  Serial.print("temp: ");
  Serial.println(temperature);
  //Get sound value
  int sound = analogRead(3);
  float db = 10 * log10(10/6) + 20 * log10(sound);
  Serial.print("sound: ");
  Serial.println(sound);

  // Get humidity
  int moisture = analogRead(4);
  float Moist = map(moisture, 0, 1024 , 0 , 100);
//  Serial.print("moisture value: ");
//  Serial.println(Moist);

  // Show temperature
  LCD.setCursor(0, 0);
  LCD.print("Temp C: ");
  LCD.print(temperature);
//
//  // Show light value
//  LCD.setCursor(0, 1);
//  LCD.print("Lumens: ");
//  LCD.print(lux);
//  delay(100);

//  //show sound value 
//  LCD.setCursor(0, 1);
//  LCD.print("Son db: ");
//  LCD.print(db);
}
