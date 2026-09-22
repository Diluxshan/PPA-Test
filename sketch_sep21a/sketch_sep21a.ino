#include <WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"

//#define LDR_pin 32
const char* WIFI_NAME = "dilux";
const char* WIFI_PASSWORD = "12345678";
const int myChannelNumber = 3501759 ;
const char* myApiKey = "GSRURS3OVC5YZRWG";
const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
//  pinMode(LDR_pin, INPUT);
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  ThingSpeak.begin(client);
  Serial.begin(115200);
}

void loop() {
  int ldr = 30;
  Serial.println(ldr);
  ThingSpeak.setField(1,ldr);
  ThingSpeak.writeFields(myChannelNumber,myApiKey);
}