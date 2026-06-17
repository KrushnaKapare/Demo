#include<ESP8266WiFi.h>
#include<WiFIClient.h>
#include "ThingSpeak.h"


unsigned long myChannelNumber = 3208109;
const char * myWriteAPIKey = "5Z13I58EJJY63D1N";

const char *ssid = "SUNBEAM";
const char *password = "1234567890";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("connecting to WiFi");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");  
  }

  Serial.println("\nWiFi is connected");
  Serial.print("IP Address : ");
  Serial.println((WiFi.localIP()));

}

void loop() {
  // put your main code here, to run repeatedly:
  int valueA0 = analogRead(A0);

  // Write value to Field 1 of a ThingSpeak Channel
  int httpCode = ThingSpeak.writeField(myChannelNumber, 1, valueA0, myWriteAPIKey);

  if (httpCode == 200) {
    Serial.println("Channel write successful.");
  }
  else {
    Serial.println("Problem writing to channel. HTTP error code " + String(httpCode));
  }

  // Wait 20 seconds to update the channel again
  delay(20000);
}








