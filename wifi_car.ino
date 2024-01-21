/*
copy to File >> preferance >>  URL: http://arduino.esp8266.com/stable/package_esp8266com_index.json 
Install: ESP8266 by ESP8266 Community
App URI:https://play.google.com/store/apps/details?id=com.bluino.esp8266wifirobotcar&pcampaignid=web_share
My git: https://github.com/AbdAlhalemEz/Wifi-Car
*/

#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define OUT1  15          // L298N out1 motors Right          GPIO15(D8)
#define OUT2  13          // L298N out2 motors Right          GPIO13(D7)
#define OUT3  2           // L298N out3 motors Left           GPIO2(D4)
#define OUT4  0           // L298N out4 motors Left           GPIO0(D3)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

String command;             // String to store app command state.
int speedCar = 800;         // 400 - 1023.
int speed_Coeff = 3;

const char* ssid = "WIFI Car ";
ESP8266WebServer server(80);

void setupMotors() {
  // Run all motors for 2 seconds
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, HIGH);
  analogWrite(ENB, speedCar);

  delay(2000);

  // Stop all motors
  stopRobot();
}

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);  
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);  

  Serial.begin(115200);
  
  // Connecting WiFi
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
  // Starting WEB-server 
  server.on("/", HTTP_handleRoot);
  server.onNotFound(HTTP_handleRoot);
  server.begin();

  // Setup motors
  setupMotors();
}

void goAhead() { 
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);
  analogWrite(ENA, speedCar);
}

void goBack() { 
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
  analogWrite(ENA, speedCar);
}

void goRight() { 
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, HIGH);
  digitalWrite(OUT4, LOW);
  analogWrite(ENB, speedCar);
}

void goLeft() { 
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
  analogWrite(ENA, speedCar);

FN   X
}

void goAheadRight() { 
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, HIGH);
  digitalWrite(OUT4, LOW);
  analogWrite(ENB, speedCar);
}

void goAheadLeft() { 
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, HIGH);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, HIGH);
  analogWrite(ENB, speedCar);
}

void goBackRight() { 
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, HIGH);
  digitalWrite(OUT4, LOW);
  analogWrite(ENB, speedCar);
}

void goBackLeft() { 
  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, HIGH);
  analogWrite(ENB, speedCar);
}

void stopRobot() {  
  digitalWrite(OUT1, LOW);
  digitalWrite(OUT2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(OUT3, LOW);
  digitalWrite(OUT4, LOW);
  analogWrite(ENB, speedCar);
}

void loop() {
  server.handleClient();
    
  command = server.arg("State");
  if (command == "F") goAhead();
  else if (command == "B") goBack();
  else if (command == "L") goLeft();
  else if (command == "R") goRight();
  else if (command == "I") goAheadRight();
  else if (command == "G") goAheadLeft();
  else if (command == "J") goBackRight();
  else if (command == "H") goBackLeft();
  else if (command == "S") stopRobot();
}

void HTTP_handleRoot(void) {
  if( server.hasArg("State") ){
    Serial.println(server.arg("State"));
  }
  server.send(200, "text/html", "");
  delay(1);
}
  
