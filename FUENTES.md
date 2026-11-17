# Fuentes, librerías y herramientas utilizadas

En este documento se presentan las librerías, herramientas y recursos utilizados durante el desarrollo de la compresa inteligente Alpha, explicando su función y adaptación al prototipo.

## 1. Librerías utilizadas

### OneWire
**Fuente:** OneWire Library, desarrollada por Paul Stoffregen.

Se utilizó para establecer la comunicación entre el ESP32 y los sensores de temperatura DS18B20 mediante el protocolo 1-Wire.

Se configuró el bus de comunicación en el GPIO 27, permitiendo conectar dos sensores a una misma línea de datos.

### DallasTemperature
**Fuente:** DallasTemperature, Arduino Temperature Control Library.

Se utilizó para obtener las mediciones de temperatura de los sensores DS18B20.

Inicialmente se trabajó con un sensor y posteriormente se incorporó un segundo para medir la temperatura de la superficie y del agua.

Se programaron lecturas periódicas en grados Celsius y se incorporó la detección del valor `DEVICE_DISCONNECTED_C` para identificar lecturas inválidas o sensores desconectados.

### BluetoothSerial
**Fuente:** librería BluetoothSerial incluida en el paquete Arduino-ESP32 de Espressif Systems.

Se utilizó para implementar comunicación inalámbrica mediante Bluetooth clásico entre el ESP32 y un dispositivo receptor.

Se configuró el nombre `Compresa_ESP32` y se programó el envío de las temperaturas de superficie y agua, junto con el estado de la bomba.

## 2. Herramientas de programación

### Arduino IDE
**Fuente:** Arduino.

Se utilizó como entorno de desarrollo para escribir, compilar y cargar los programas en el ESP32, además de realizar pruebas y corregir errores.

### Arduino-ESP32
**Fuente:** Espressif Systems.

Se utilizó el paquete de soporte para placas ESP32, que permite programar el microcontrolador desde Arduino IDE y utilizar sus funciones de entrada, salida y comunicación.

### Monitor Serial
**Fuente:** herramienta integrada en Arduino IDE.

Se utilizó para observar las mediciones de temperatura, comprobar el funcionamiento del código e identificar posibles errores durante las pruebas.

## 3. Desarrollo y adaptación del código

El código se desarrolló progresivamente mediante pruebas individuales de los componentes y su posterior integración.

Las etapas documentadas fueron:

1. Prueba inicial del ESP32 mediante el Monitor Serial.
2. Incorporación de un sensor DS18B20 para medir temperatura.
3. Prueba de la señal GPIO 26 destinada al control del actuador mediante MOSFET.
4. Incorporación de la lógica automática de encendido y apagado según la temperatura.
5. Incorporación de una condición de seguridad ante lecturas inválidas del sensor.
6. Incorporación de un segundo DS18B20 para medir la temperatura de superficie y del agua.
7. Incorporación de comunicación Bluetooth para transmitir las mediciones y el estado del sistema.

En el diseño electrónico actualizado se considera reemplazar el MOSFET por un relé optoacoplado de un canal compatible con señales de control de 3,3 V.

Las distintas versiones del programa se encuentran documentadas en la carpeta `firmware/`.

## 4. Uso de inteligencia artificial

### ChatGPT
**Fuente:** OpenAI.

ChatGPT se utilizó como herramienta de apoyo durante el desarrollo del prototipo y la preparación de su documentación técnica.

Sus principales aplicaciones fueron:

- Apoyar la organización y revisión del código.
- Resolver dudas sobre el funcionamiento de los sensores DS18B20.
- Apoyar la programación de la lógica de control de temperatura.
- Revisar la condición de seguridad ante fallas de los sensores.
- Apoyar la incorporación de comunicación Bluetooth.
- Interpretar errores de programación y carga del código.
- Apoyar la elaboración de diagramas y esquemáticos electrónicos.
- Organizar la estructura del repositorio GitHub.
- Apoyar la redacción y revisión de documentación técnica y protocolos experimentales.

Las respuestas fueron revisadas y adaptadas de acuerdo con los componentes, conexiones y pruebas realizadas durante el desarrollo del prototipo.

## 5. Código y recursos externos

No se utilizó un repositorio externo completo como base del proyecto.

Las funciones de lectura de temperatura y comunicación Bluetooth se implementaron utilizando las librerías mencionadas anteriormente, integradas en el código desarrollado para el prototipo.

El esquema electrónico se elaboró considerando las conexiones y características técnicas de los componentes seleccionados.

Los recursos externos adicionales que se utilicen en futuras versiones serán incorporados a este documento, indicando su procedencia, finalidad y adaptaciones realizadas.
