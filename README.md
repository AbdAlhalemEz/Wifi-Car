# Arduino RC Car Control Project

## Overview
This Arduino project allows you to control an RC car using your smartphone. The project utilizes an ESP8266 for WiFi communication and an L298N motor driver to control the car's movements. The connection between the components is outlined below.

## Hardware Connection
- **ENA (Enable/Speed Motors Right):** Connect to GPIO14 (D5)
- **ENB (Enable/Speed Motors Left):** Connect to GPIO12 (D6)
- **OUT1 (L298N Out1 Motors Right):** Connect to GPIO15 (D8)
- **OUT2 (L298N Out2 Motors Right):** Connect to GPIO13 (D7)
- **OUT3 (L298N Out3 Motors Left):** Connect to GPIO2 (D4)
- **OUT4 (L298N Out4 Motors Left):** Connect to GPIO0 (D3)

![Connection Map](https://github.com/AbdAlhalemEz/Wifi-Car/blob/main/Wifi-controlled-car1.jpg)


## Required App
To control the car, use the following app: [WiFi Robot Car Controller](https://play.google.com/store/apps/details?id=com.bluino.esp8266wifirobotcar&pcampaignid=web_share)

## Setup Instructions
1. Open Arduino IDE and navigate to `File > Preferences`.
2. Add the following URL to the "Additional Boards Manager URLs":
   - Board Manager URL: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
3. Install the ESP8266 board package via `Tools > Board > Boards Manager`.
4. Search for "ESP8266" and install the package by the ESP8266 Community.
5. Connect your Arduino to your computer and upload the provided code to the Arduino.

## Operating the RC Car
1. Once the code is uploaded, search for WiFi SSID "WIFI Car" on your smartphone and connect to it.
2. Open the [WiFi Robot Car Controller app](https://play.google.com/store/apps/details?id=com.bluino.esp8266wifirobotcar&pcampaignid=web_share) and start controlling your RC car.

## Troubleshooting
- If issues arise, use the serial monitor to verify that signals are being received from the phone.
- Check the motor connections; if the car moves forward when pressing back, or vice versa, flip the motor wires. Repeat the process for left and right motors.

Enjoy controlling your RC car with your smartphone! Feel free to reach out if you encounter any difficulties.
