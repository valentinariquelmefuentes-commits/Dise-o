Y este es el código final que use para poder conectarlo a bluetooth:

#include <OneWire.h>
#include <DallasTemperature.h>
#include "BluetoothSerial.h"

#define SENSOR_PIN 27
#define BOMBA_PIN 26

OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);

BluetoothSerial SerialBT;

bool bombaEncendida = false;

void setup() {

  Serial.begin(115200);

  sensors.begin();

  pinMode(BOMBA_PIN, OUTPUT);
  digitalWrite(BOMBA_PIN, LOW);

  // Nombre Bluetooth del prototipo
  SerialBT.begin("Compresa_ESP32");

  Serial.println("Sistema iniciado");
  Serial.println("Bluetooth: Compresa_ESP32");

  SerialBT.println("Sistema de compresa iniciado");
}

void loop() {

  sensors.requestTemperatures();

  float tempSuperficie = sensors.getTempCByIndex(0);
  float tempAgua = sensors.getTempCByIndex(1);

  // Seguridad: si falla cualquiera de los sensores
  if (tempSuperficie == DEVICE_DISCONNECTED_C ||
      tempAgua == DEVICE_DISCONNECTED_C) {

    bombaEncendida = false;
    digitalWrite(BOMBA_PIN, LOW);

    Serial.println("ERROR SENSOR - BOMBA OFF");
    SerialBT.println("ERROR SENSOR - BOMBA OFF");

    delay(1000);
    return;
  }

  // Umbrales experimentales del prototipo
  if (tempSuperficie > 30.0) {
    bombaEncendida = true;
  }

  if (tempSuperficie < 26.0) {
    bombaEncendida = false;
  }

  digitalWrite(BOMBA_PIN, bombaEncendida ? HIGH : LOW);

  // ----- MONITOR SERIAL -----

  Serial.print("Superficie: ");
  Serial.print(tempSuperficie);
  Serial.print(" C | Agua: ");
  Serial.print(tempAgua);
  Serial.print(" C | Bomba: ");

  if (bombaEncendida) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  // ----- BLUETOOTH -----

  SerialBT.print("Superficie: ");
  SerialBT.print(tempSuperficie);
  SerialBT.print(" C | Agua: ");
  SerialBT.print(tempAgua);
  SerialBT.print(" C | Bomba: ");

  if (bombaEncendida) {
    SerialBT.println("ON");
  } else {
    SerialBT.println("OFF");
  }

  delay(1000);
}
