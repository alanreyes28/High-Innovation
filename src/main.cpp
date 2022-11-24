#include <Arduino.h> // Library included with PlatformIO
#include <Wifi.h> // Wifi Library
#include <PubSubClient.h> // MQTT Library


//*********** MQTT CONFIG **************//

const char *mqtt_server = "highinnovation.space"; 
const int mqtt_port = 1883; //....
const char *mqtt_user = "";
const char *mqtt_pass = ""; 
const char *root_topic_subscribe = "esp32/input";
const char *root_topic_publish = "master/mqtt06/writeattributevalue/writeAttribute/6iUzmPqTk8aQi8kMpsqE7S"; 



//*********** WIFICONFIG ***************//

// replace with network credentials 
const char* ssid = "LIB-3778491";
const char* password =  "xbsf5QfKymtk";

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
