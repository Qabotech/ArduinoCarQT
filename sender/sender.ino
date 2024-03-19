#include "connect.h"

const char topic[]  = "real_unique_topic";
const char topic2[]  = "real_unique_topic_2";
const char topic3[]  = "real_unique_topic_3";
//set interval for sending messages (milliseconds)
const long interval = 100;
unsigned long previousMillis = 0;

int count = 0;
int Rvalue  = 0;
int Rvalue2 = 0;
int Rvalue3 = analogRead(A2);
int bValue = 0;
const int swPin = 12;
int switchState = 1;
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  connect();
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.println();
}

void loop() {
  mqttClient.poll();
  Rvalue  = analogRead(A2);
  Rvalue2 = analogRead(A1);
  if (Rvalue2 > 1010)
  {  
                      mqttClient.beginMessage(topic);
                      mqttClient.print("FORWARD");
                      mqttClient.endMessage();
                      Serial.print("FORWARD");
                      Serial.println();
  }
   if (Rvalue2 < 20)
  {  
                      mqttClient.beginMessage(topic);
                      mqttClient.print("BACKWARD");
                      mqttClient.endMessage();
                      Serial.print("BACKWARD");
                      Serial.println();
  }
   if (Rvalue < 20) 
  {  
                      mqttClient.beginMessage(topic);
                      mqttClient.print("LEFT");
                      mqttClient.endMessage();
                      Serial.print("LEFT");
                      Serial.println();
  }
  if (Rvalue > 1010) 
  {  
                      mqttClient.beginMessage(topic);
                      mqttClient.print("RIGHT");
                      mqttClient.endMessage();
                      Serial.print("RIGHT");
                      Serial.println();
  }
  if (Rvalue <= 799 && Rvalue >= 799) 
  {  
                      mqttClient.beginMessage(topic);
                      mqttClient.print("stop");
                      mqttClient.endMessage();
                      Serial.print("stop");
                      Serial.println();
  }
  if (!switchState) 
  {
    Serial.println("Switch pressed");
  }


  

}
