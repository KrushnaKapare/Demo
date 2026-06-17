#include<ESP8266WiFi.h>
#include<WiFIClient.h>
#include<ESP8266HTTPClient.h>

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

  pinMode(A0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  String body = "{\"location\":\"Nira\",\"value\":" + String(value) + "}";
  Serial.println(body);


  WiFiClient wifiClient;
  HTTPClient httpClient;
  httpClient.begin(wifiClient, "http://172.18.3.8:4000/ldr");
  httpClient.addHeader("content-type", "application/JSON");

  int code = httpClient.POST(body);
  Serial.printf("status = %d\n", code);

  delay(5000);
}








