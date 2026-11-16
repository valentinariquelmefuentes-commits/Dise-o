#define MOSFET_PIN 26

void setup() {
  pinMode(MOSFET_PIN, OUTPUT);
}

void loop() {
  digitalWrite(MOSFET_PIN, HIGH);
  delay(3000);

  digitalWrite(MOSFET_PIN, LOW);
  delay(3000);
}
