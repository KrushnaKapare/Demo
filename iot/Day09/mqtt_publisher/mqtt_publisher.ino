#include<WiFiClient.h>
#include<ESP8266WiFi.h>
#include<ArduinoMqttClient.h>

const char *ssid = "$dvd$";
const char *password = "dvd12345";

const char *host = "192.168.108.172";
const int port = 1883;

WiFiClient wifiClient;
MqttClient publisher(wifiClient);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.flush();

  pinMode(A0, INPUT);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to a WiFi");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("\n WiFi is connected");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());

  if(!publisher.connect(host, port))
    while(1);

  Serial.println("Connected to the Broker");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  float value = analogRead(A0);

  publisher.beginMessage("sensor/ldr");
  publisher.print(value);
  publisher.endMessage();


  delay(6000);
}




