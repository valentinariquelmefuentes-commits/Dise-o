#include <OneWire.h>
#include <DallasTemperature.h>

#define SENSOR_PIN 27
#define BOMBA_PIN 26

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

bool bombaEncendida = false;

void setup() {
  Serial.begin(115200);

  sensors.begin();

  pinMode(BOMBA_PIN, OUTPUT);
  digitalWrite(BOMBA_PIN, LOW);
}

void loop() {

  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);

  // Umbrales experimentales del prototipo
  if (temperatura > 30.0) {
    bombaEncendida = true;
  }

  if (temperatura < 26.0) {
    bombaEncendida = false;
  }

  digitalWrite(BOMBA_PIN, bombaEncendida ? HIGH : LOW);

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" C | Bomba: ");

  if (bombaEncendida) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  delay(1000);
}
