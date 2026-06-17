#include<WiFiClient.h>
#include<ESP8266WiFi.h>
#include<ArduinoMqttClient.h>

const char *ssid = "$dvd$";
const char *password = "dvd12345";

const char *host = "192.168.108.172";
const int port = 1883;

WiFiClient wifiClient;
MqttClient subscriber(wifiClient);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.flush();

  pinMode(D0, OUTPUT);
  digitalWrite(D0, HIGH);
  
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

  if(!subscriber.connect(host, port))
    while(1);

  Serial.println("Connected to the Broker");

  subscriber.subscribe("room/light");

  Serial.println("Topic is subscribed");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int size = subscriber.parseMessage();
  if(size){
    char str[size];
    memset(str, 0, sizeof(str));
    for(int i = 0 ; i < size ; i++)
      str[i] = (char)subscriber.read();

    Serial.println("Message : " + String(str));

    if(strncmp(str, "ON", 2) == 0){
      digitalWrite(D0, LOW);
      Serial.println("LED is Turned ON");
    }
    else if(strncmp(str, "OFF", 3) == 0){
      digitalWrite(D0, HIGH);
      Serial.println("LED is Turned OFF");
    }

  }

  delay(6000);
}




