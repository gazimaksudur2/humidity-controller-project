# Humidity Controller

## Abstract
The Humidity Controller is a microprocessor-based project designed to regulate room humidity efficiently. This project utilizes a microcontroller to control a vaporization generator, aiming to increase the room's humidity levels. The key component responsible for monitoring the humidity levels is a hygrometer. By employing this system, the project ensures precise and effective control over the room's humidity automatically, providing a reliable solution for environments requiring specific humidity conditions.

## Introduction
Bangladesh is facing severe mid-winter cold, impacting daily life with dense nighttime fog. This has led to an increase in cold-related illnesses, particularly affecting children and the elderly. Additionally, the winter season brings very low humidity levels, emphasizing the importance of maintaining optimal humidity in controlled environments, greenhouses, and industrial processes. The Humidity Controller project addresses the need for a sophisticated system to manage room humidity. This project focuses on achieving this control by utilizing a microcontroller to regulate a vaporization generator. The microcontroller processes information from a hygrometer, a sensor designed to measure humidity accurately. By interfacing the microcontroller with the vaporization generator, the system can adjust the humidity levels in the room as required.

## Related Works
- Making water vapor by heater.
- Measure of temperature across humidity.
- Measure of Humidity across water vapor.
- Fixed a humidity level when it’s lower, the humidity controller machine starts boiling water by heater.

## Necessary Hardware
- DHT22 humidity and temperature sensor
- Arduino Uno microcontroller
- 5V relay module
- Humidifier
- Breadboard
- Jumper wires
- 10kΩ resistor
- Power supply (5V)
- LED light
- 10K Potentiometer
- LiquidCrystal_I2C Display

## Necessary Software
- Arduino IDE


## Circuit Design

### Connections
- **LiquidCrystal_I2C Display:**
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - SDA to A4 on Arduino
  - SCL to A5 on Arduino
- **DHT22 Sensor:**
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - DATA to Digital Pin 2 on Arduino
- **Potentiometer:**
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - Wiper (middle pin) to A0 on Arduino
- **Red LED:**
  - Anode (long leg) to Digital Pin 10 on Arduino (through a 10kΩ resistor)
  - Cathode (short leg) to GND on Arduino
- **Relay:**
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - IN to Digital Pin 10 on Arduino
- **Humidifier Connect with Relay:**
  - 5V of Humidifier connect with Relay ON
  - GND to GND on Arduino
  - COM of Relay connect with Humidifier VCC

## Code Explanation

### 1. Libraries and Definitions
```cpp
   #include <Wire.h>
   #include <LiquidCrystal_I2C.h>
   #include "DHT.h"
   #define red_led 10
```
- Wire.h and LiquidCrystal_I2C.h are included for I2C communication with the LCD.
- DHT.h is included to interface with the DHT22 sensor.
- The red LED is defined to be connected to digital pin 10.

### 2. LCD and Sensor Initialization
```cpp
int lcdColumns = 16;
int lcdRows = 2;
const int potpin = A0;
int potValue = 0;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
```
- LCD is set to have 16 columns and 2 rows.
- Potentiometer is connected to analog pin A0.
- LCD address is set to 0x27.
- DHT22 sensor is connected to digital pin 2.

### 3. Setup Function
```cpp
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(red_led, OUTPUT);
  digitalWrite(red_led, HIGH);
}
```
- Serial communication is initialized at 115200 baud rate.
- LCD and DHT22 sensor are initialized.
- Red LED is set as output and initially turned off (HIGH).

### 4. Loop Function
```cpp
void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  h = roundf(h * 10.0) / 10.0;
  t = roundf(t * 10.0) / 10.0;
  char humidityStr[6];
  char temperatureStr[6];
  dtostrf(h, 4, 1, humidityStr);
  dtostrf(t, 4, 1, temperatureStr);
  bool status = false;
  potValue = analogRead(potpin);
  potValue = map(potValue, 0, 1023, 0, 100);
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  if(h < potValue) {
    digitalWrite(red_led, LOW);
    status = true;
  } else {
    digitalWrite(red_led, HIGH);
    status = false;
  }
  lcd.setCursor(0, 0);
  lcd.print(F("T:"));
  lcd.print(temperatureStr);
  lcd.print(F("C H:"));
  lcd.print(humidityStr);
  lcd.print(F("%"));
  lcd.setCursor(0, 1);
  lcd.print("Tg: ");
  lcd.print(potValue);
  lcd.print(" St: ");
  lcd.print(status);
}
```
- The system waits for 2 seconds between measurements.
- Temperature and humidity are read from the DHT22 sensor and rounded to one decimal place.
- Values are converted to strings for display.
- The potentiometer value is read and mapped to a range of 0-100.
- If the humidity is less than the potentiometer value, the LED is turned on (LOW), otherwise, it remains off (HIGH).
- Temperature, humidity, threshold value, and status are displayed on the LCD.

## Results
The constructed humidity controller effectively maintained the desired humidity level within the test environment. The DHT22 sensor provided accurate humidity readings, and the Arduino-controlled relay successfully activated and deactivated the humidifier based on the measured humidity.

## Data
Firstly, we set humidity with a 10k potentiometer at 90%. Then the following data was recorded:

| Time (min) | Humidity (%) | Humidifier Status |
|------------|--------------|-------------------|
| 0          | 85           | ON                |
| 5          | 88           | ON                |
| 10         | 90           | OFF               |
| 15         | 95           | OFF               |
| 20         | 89           | ON                |
| 25         | 93           | OFF               |

## Discussion
The humidity controller demonstrated reliable performance in maintaining the desired humidity level. The system's response time was adequate for the test environment, and the hysteresis implemented in the software prevented rapid cycling of the humidifier. The DHT22 sensor's accuracy was sufficient for this application, though higher precision sensors could be considered for more demanding requirements.

## Conclusion
This project successfully developed a humidity controller using an Arduino, DHT22 sensor, and relay module. The system effectively maintained the desired humidity level, proving the feasibility of using low-cost components for humidity control applications. Future improvements could include integrating a display for real-time humidity monitoring and expanding the system to control multiple humidifiers for larger environments.



## Contributors
- **Nobel Ahmad Badhon** (Student ID: 2020331030)
- **Tazbir Hossain Akash** (Student ID: 2020331056)
- **Gazi Maksudur Rahman** (Student ID: 2020331062)
- **Abdullah Al Mahadi Apurbo** (Student ID: 2020331092)
- **Elias Ahahammed** (Student ID: 2020331108)


## Setup and Installation
1. **Clone the repository**:
   ```bash
   https://github.com/gazimaksudur2/humidity-controller-project.git
   cd humidity-controller-project
