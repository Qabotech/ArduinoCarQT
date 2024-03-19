#include "connect.h"
#include "functions.h"
const char topic[]  = "real_unique_topic";
const char topic2[]  = "real_unique_topic_2";
const char topic3[]  = "real_unique_topic_3";
String msg; 
String receivedMessage;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  funcSetup();
  connect();
  Serial.println();

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

  Serial.print("Subscribing to topic: ");
  Serial.println(topic);
  Serial.println();

  // subscribe to a topic
  mqttClient.subscribe(topic);
  mqttClient.subscribe(topic2);
  mqttClient.subscribe(topic3);

  Serial.print("Topic: ");
  Serial.println(topic);
  Serial.print("Topic: ");
  Serial.println(topic2);
  Serial.print("Topic: ");
  Serial.println(topic3);

  Serial.println();
}

void loop() {
  mqttClient.poll();
  msg = getReceivedMessage();
    if (msg == "FORWARD") 
    {
      Serial.println("FORWARD");
      forward();
    }
    else if (msg == "BACKWARD") 
    {
      Serial.println("BACKWARD");
      backward();
    }
    else if (msg == "LEFT") 
    {
      Serial.println("LEFT");
      leftForward();
    }
    else if (msg == "RIGHT") 
    {
      Serial.println("RIGHT");
      rightForward();
    }
    else if (msg == "SP") 
    {
      Serial.println("SP");
      carHornSound();
    }
    else 
    {
      Stop();
      Serial.println("Stop");
    }
}

void onMqttMessage(int messageSize) {
  // we received a message, print out the topic and contents
  receivedMessage = ""; // Clear the previous message
  
  while (mqttClient.available()) {
    char receivedChar = mqttClient.read(); 
    receivedMessage += receivedChar; // Concatenate the characters
  }
  Serial.println();
}

String getReceivedMessage() {
  return receivedMessage;
}
