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
