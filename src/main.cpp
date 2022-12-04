#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
// #include <ArduinoJson.h>
// #include <FreeRTOS.h>

// //*********** WIFICONFIG ***************//

const char *SSID = "LIB-3778491"; // name of internet router
const char *PWD = "xbsf5QfKymtk"; // password
WebServer server(80);
//*********** VARIABLES  ***************//

const int tempPin = 2; // analog input pin constant

int tempVal; // temperature sensor raw readings

float volts; // variable for storing voltage

float tempC; // temperature variable in Degrees Celcius

float tempF; // temperature variable in Degrees Farenheit

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello from the setup");
}

void loop()
{
  // put your main code here, to run repeatedly:
  tempVal = analogRead(tempPin);

  volts = tempVal / 1023.0; // normalize by the maximum temperature raw reading range

  tempC = (volts - 0.5) * 100; // calculate temperature celsius from voltage as per the equation found on the sensor spec sheet.

  tempF = ((volts - 0.5) * 100) * 1.8 + 32;

  Serial.print(" Temperature is:   "); // print out the following string to the serial monitor
  Serial.print(tempC);                 // in the same line print the temperature
  Serial.println(" degrees C\n");      // still in the same line print degrees C, then go to next line.

  Serial.print(" Temperature is:   "); // print out the following string to the serial monitor
  Serial.print(tempF);                 // in the same line print the temperature
  Serial.println(" degrees F\n");

  delay(1000); // wait for 1 second or 1000 milliseconds before taking the next reading.
 }

void wifiConnect()
{
  Serial.print("Connecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, PWD);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
}