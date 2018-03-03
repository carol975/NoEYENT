#define outPin6 6

void setup() {
  pinMode(outPin6, OUTPUT); //set pin 6 to output

}

void loop() {
  digitalWrite(outPin6, HIGH);
  delay(1000);
  digitalWrite(outPin6, LOW);
  delay(1000);
  Serial.println("on");

}
