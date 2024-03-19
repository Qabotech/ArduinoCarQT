#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>
WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);
char ssid[] = "S20";        // your network SSID (name)
char pass[] = "123456789";    // your network password (use for WPA, or use as key for WEP)
const char broker[] = "test.mosquitto.org";
int        port     = 1883;

void connect ()
{

      while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

  Serial.print("Attempting to connect to the MQTT broker: ");
  Serial.println(broker);

  if (!mqttClient.connect(broker, port)) {
    Serial.print("MQTT connection failed! Error code = ");
    Serial.println(mqttClient.connectError());

    while (1);
  }

  Serial.println("You're connected to the MQTT broker!");
}
