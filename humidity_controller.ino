#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define red_led 10
// Set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
const int potpin = A0;
int potValue = 0;
// Set LCD address, number of columns and rows
// If you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows); 
#define DHTPIN 2 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(115200);
lcd.init(); // Initialize LCD
lcd.backlight(); // Turn on LCD backlight
dht.begin(); // Initialize DHT sensor
pinMode(red_led, OUTPUT);
digitalWrite(red_led, HIGH);
}
void loop() {
// Wait a few seconds between measurements
delay(2000);
// Reading temperature or humidity takes about 250 milliseconds
// Sensor readings may also be up to 2 seconds 'old' (it's a slow sensor)
float h = dht.readHumidity();
float t = dht.readTemperature();
h = roundf(h * 10.0) / 10.0;
t = roundf(t * 10.0) / 10.0;
char humidityStr[6]; // Array to hold the string for humidity (3 digits + decimal 
point + null terminator)
char temperatureStr[6]; // Array to hold the string for temperature (3 digits + 
decimal point + null terminator)
dtostrf(h, 4, 1, humidityStr); // Convert float to string with one decimal point
dtostrf(t, 4, 1, temperatureStr); 
bool status = false;
potValue = analogRead(potpin);
potValue = map(potValue, 0, 1023, 0, 100);
// Check if any reads failed and exit early (to try again)
if (isnan(h) || isnan(t)) {
Serial.println(F("Failed to read from DHT sensor!"));
return;
}
if(h<potValue){
digitalWrite(red_led, LOW);
status =true;
}else{
digitalWrite(red_led,HIGH);
status =false;
}
// Display temperature and humidity on LCD
lcd.setCursor(0, 0);
lcd.print(F("T:"));
lcd.print(temperatureStr);
lcd.print(F("C H:"));
lcd.print(humidityStr);
lcd.print(F("%"));
// Move to the next line and print additional message
lcd.setCursor(0, 1);
lcd.print("Tg: ");
lcd.print(potValue);
lcd.print(" St: ");
lcd.print(status);
}
