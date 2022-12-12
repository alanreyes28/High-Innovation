#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <PubSubClient.h>
#include <driver/adc.h>

#define PIN_LED GPIO_NUM_4
#define ON 1
#define OFF 0

//**** WIFICONFIG ******//

const char *SSID = "LIB-3778491"; // name of internet router
const char *PWD = "xbsf5QfKymtk"; // password

//**** MQTT ******//

const char *MQTTBroker = "HighInnovation.space";
const int MQTTPort = 1883;

//**** PUBSUBCONFIG ******//

const char *publishTopic = "tempcelcius";
const char *subscribeTopic = "config";

WiFiClient espClient;
PubSubClient client(espClient);

//**** VARIABLES  ******//

float tempRaw, volts, resistance, kelvin, celcius, farenheit; // variables for calculating temperature

//**** FUNCTIONS  ******//

void mqttConnect()
{
  while (!client.connected())
  {
    Serial.print("Connecting to MQTT Broker... ");
    if (client.connect("ESP32_clientID"))
    {
      Serial.print("You connected to MQTT Broker Successfully");
      Serial.println("\n");
    }
    else
    {
      Serial.print("Connection to MQTT Broker has failed with error: ");
      Serial.print(client.state());
      Serial.println("\n");
      delay(3000);
    }
  }
}

void wifiConnect()
{
  Serial.print("Connecting to ");
  Serial.println(SSID);

  WiFi.begin(SSID, PWD);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("connecting...\n");
    delay(500);
    gpio_set_level(PIN_LED, OFF);
  }

  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("\n");
  // MQTT
  client.setServer(MQTTBroker, MQTTPort);

  // client.setCallback(callback)
  mqttConnect();
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(921600);
  Serial.println("Starting Setup...\n\n");
  wifiConnect();
}

void loop()
{
  tempRaw = adc1_get_raw(ADC1_CHANNEL_7); // read raw analog output from thermistor

  volts = (float)tempRaw / 4095.0 * 3.3; // convert it into volts

  resistance = 10 * volts / (3.3 - volts); // consideration of resistance value

  kelvin = 1 / (1 / (298.15) + log(resistance / 10) / 3950.0); // conversion of value to kelvin

  celcius = kelvin - 273.15; // kelvin to celcius conversion

  farenheit = (celcius * 9) / 5 + 32; // celcius to farenheit conversion

  // terminal output of variables
  Serial.println("Thermistor Output Data: ");
  Serial.print("Analog: ");
  Serial.println(tempRaw);
  Serial.print("mVolts: ");
  Serial.println(volts, 4);
  Serial.print("Temp in kelvin: ");
  Serial.println(kelvin, 4);
  Serial.print("Temp in celcius: ");
  Serial.println(celcius, 4);
  Serial.print("Temp in farenheit: ");
  Serial.println(farenheit, 4);
  Serial.println("\n");

  delay(1000); // wait for 1 second or 1000 milliseconds before taking the next reading.

  char msg[50];
  sprintf(msg, "%f", celcius);

  if (!client.connected())
  {
    mqttConnect();
  }

  client.publish(publishTopic, String(celcius).c_str());
  client.loop();
}
