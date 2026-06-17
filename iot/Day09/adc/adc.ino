void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.flush();

  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);

  Serial.printf("value = %d\n", value);
  delay(2000);

}
