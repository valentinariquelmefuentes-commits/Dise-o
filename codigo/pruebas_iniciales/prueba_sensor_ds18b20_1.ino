#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 27

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();

  Serial.println("Iniciando sensor DS18B20...");
}

void loop() {
  sensors.requestTemperatures();

  float temperatura = sensors.getTempCByIndex(0);

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  delay(1000);
}
