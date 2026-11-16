# Fuentes, librerías y herramientas utilizadas

En este documento se indican las librerías, herramientas externas y recursos utilizados durante el desarrollo del prototipo, explicando para qué se usaron y cómo fueron adaptados al proyecto.

## 1. Librerías utilizadas
### OneWire

**Fuente:** librería OneWire, desarrollada por Paul Stoffregen.

**Uso en el proyecto:**  
Se utilizó para permitir la comunicación entre el ESP32 y los sensores de temperatura DS18B20 mediante el protocolo 1-Wire.

**Adaptación realizada:**  
Se configuró la librería según los pines utilizados en nuestro circuito y se trabajó en conjunto con la librería DallasTemperature para obtener las mediciones de temperatura.

### DallasTemperature

**Fuente:** Arduino Temperature Control Library.

**Uso en el proyecto:**  
Se utilizó para obtener las mediciones de los sensores DS18B20. Primero se probó con un solo sensor y posteriormente se incorporó un segundo sensor para medir la temperatura de la superficie y la temperatura del agua.

**Adaptación realizada:**  
Se programaron lecturas periódicas en grados Celsius y se utilizaron estos valores dentro de la lógica de funcionamiento del sistema. También se agregó la detección de error `DEVICE_DISCONNECTED_C`, que permite identificar cuando alguno de los sensores se encuentra desconectado o no entrega una lectura válida.


### BluetoothSerial

**Fuente:** librería BluetoothSerial incluida en Arduino-ESP32.

**Uso en el proyecto:**  
Se utilizó para incorporar comunicación inalámbrica al prototipo y poder enviar los datos obtenidos por el sistema.

**Adaptación realizada:**  
Se configuró el dispositivo con el nombre `Compresa_ESP32` y se programó el envío de la temperatura de superficie, temperatura del agua y estado de la bomba.

## 2. Desarrollo del código

El código se desarrolló de forma progresiva, probando primero los componentes por separado y después integrándolos.

Las principales etapas fueron:

1. Prueba inicial del ESP32 mediante el monitor serial.
2. Incorporación de un sensor DS18B20 para medir temperatura.
3. Prueba de la salida utilizada para controlar el MOSFET.
4. Incorporación de una lógica automática para determinar el estado ON/OFF de la bomba según la temperatura.
5. Incorporación de una condición de seguridad para detectar la desconexión del sensor y establecer la bomba en OFF.
6. Incorporación de un segundo sensor DS18B20 para medir la temperatura de superficie y del agua.
7. Incorporación de comunicación Bluetooth para enviar las mediciones y el estado del sistema.

Las distintas versiones utilizadas durante este proceso se encuentran guardadas en la carpeta `firmware/`.

## 3. Uso de inteligencia artificial

### ChatGPT — OpenAI

ChatGPT se utilizó como herramienta de apoyo durante el desarrollo del prototipo y su documentación.

Principalmente se utilizó para:

- ayudar a ordenar y revisar el código;
- resolver dudas sobre el uso de los sensores DS18B20;
- apoyar la programación de la lógica de control de temperatura;
- agregar y revisar la condición de seguridad ante fallas de los sensores;
- apoyar la incorporación de comunicación Bluetooth;
- interpretar algunos errores que aparecieron al cargar el código en el ESP32;
- organizar la estructura del repositorio GitHub;
- apoyar la redacción de documentación técnica del proyecto.

Las respuestas entregadas por la herramienta fueron revisadas y adaptadas de acuerdo con los componentes, conexiones y pruebas realizadas por el equipo. Los códigos fueron probados progresivamente con el hardware disponible y se realizaron cambios según los resultados obtenidos.

## 4. Código y recursos externos

No se utilizó un repositorio externo completo como base del proyecto.

Las funciones utilizadas para leer los sensores y realizar la comunicación Bluetooth provienen de las librerías mencionadas anteriormente y fueron integradas dentro del código desarrollado para el prototipo.

En caso de utilizar posteriormente otros tutoriales, códigos externos o repositorios, estos serán agregados a este documento indicando su fuente y el uso que tuvieron dentro del proyecto.
