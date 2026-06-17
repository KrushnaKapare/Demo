#include<ESP8266WiFi.h>
#include<WiFIClient.h>
#include<ESP8266WebServer.h>

const char *ssid = "SUNBEAM";
const char *password = "1234567890";

ESP8266WebServer server(80);

void welcome(){
  server.send(200, "text/html", "<html><body><h1>This is a welcome page</h1></body></html>");
}

void ledon(){
  digitalWrite(D0, LOW);
  server.send(200, "text/html", "<html><body><h1>led is turned ON</h1></body></html>");
}

void ledoff(){
  digitalWrite(D0, HIGH);
  server.send(200, "text/html", "<html><body><h1>led is turned OFF</h1></body></html>");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  digitalWrite(D0, HIGH);

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

  server.on("/welcome", HTTP_GET, welcome);
  server.on("/ledon", HTTP_GET, ledon);
  server.on("/ledoff", HTTP_GET, ledoff);

  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}








