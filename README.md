# Compresa inteligente de enfriamiento controlado

**Proyecto Alpha · TEI201 — Taller de Diseño en Ingeniería · Universidad Adolfo Ibáñez**

## Descripción del proyecto

El proyecto desarrolla una compresa reutilizable con circulación de agua y monitoreo de temperatura. El sistema utiliza un ESP32 para adquirir las lecturas de dos sensores DS18B20 y controlar una bomba de 12 V mediante un módulo de control.

El desarrollo se realizó de forma progresiva, comenzando con pruebas individuales del ESP32, los sensores y el sistema de control, para luego integrar la medición de temperatura, el accionamiento de la bomba y la comunicación del sistema.

El [protocolo experimental](testing/README.md) describe las pruebas definidas para evaluar el funcionamiento del prototipo y su desempeño.

## Integrantes

- Catalina Ríos
- Valentina Riquelme
- Florencia Maldonado
- Martina Calvo

## Problemática

El proyecto aborda la dificultad de monitorear y controlar la temperatura durante el enfriamiento inicial de quemaduras térmicas infantiles en el hogar.

Como propuesta de solución se desarrolla una compresa reutilizable con circulación de agua, que permite medir la temperatura durante el proceso de enfriamiento y controlar el funcionamiento del sistema.

El prototipo se evalúa mediante pruebas experimentales y no se utiliza directamente sobre personas ni corresponde a un dispositivo validado clínicamente.

## Componentes principales

| Componente | Función y conexión principal |
|---|---|
| ESP32 DevKit V1 | Adquiere las lecturas de temperatura y ejecuta la lógica de control. |
| 2 sensores DS18B20 | Miden la temperatura de la superficie y del agua. Comparten el bus 1-Wire conectado a `GPIO27`. |
| Resistencia de 4,7 kΩ | Funciona como resistencia pull-up entre `3V3` y la línea de datos de los sensores. |
| Módulo de control de la bomba | Recibe la señal generada por el ESP32 desde `GPIO26` y permite controlar la bomba de 12 V. |
| Bomba de 12 V CC | Hace circular el agua entre el depósito y la compresa. |
| Fuente switching de 12 V CC | Alimenta el circuito de potencia del sistema. |
| Convertidor LM2596 | Reduce la tensión de 12 V para alimentar los componentes que requieren menor voltaje. |
| Depósito, mangueras y compresa | Forman el circuito cerrado de circulación de agua. |

## Instalación

1. Instalar Arduino IDE, el paquete de placas `esp32` de Espressif Systems y las librerías `OneWire` y `DallasTemperature`.
2. Abrir el archivo `.ino` principal ubicado en la carpeta `firmware/`.
3. Seleccionar **DOIT ESP32 DEVKIT V1** y el puerto correspondiente a la placa.
4. Con la alimentación desconectada, conectar ambos sensores DS18B20 al bus 1-Wire utilizado por el sistema y verificar la resistencia pull-up de 4,7 kΩ.
5. Conectar la salida de control del ESP32 al módulo utilizado para accionar la bomba.
6. Cargar el firmware mediante USB y abrir el Monitor Serial a **115200 baudios** para verificar las lecturas.
7. Conectar el circuito hidráulico, llenar el depósito y comprobar que no existan fugas antes de iniciar las pruebas.

## Uso

1. Encender el prototipo y verificar que ambos sensores sean reconocidos correctamente.
2. Revisar las temperaturas registradas por el sistema.
3. Comprobar el estado ON/OFF calculado para la bomba según los umbrales configurados.
4. Verificar la circulación de agua y comprobar que no existan fugas.
5. Al finalizar la prueba, apagar el sistema y desconectar la alimentación.

## Comunicación y visualización de datos

El prototipo incorpora comunicación Bluetooth mediante el ESP32. A través de esta conexión se pueden enviar de forma inalámbrica las mediciones de temperatura de la superficie y del agua, junto con el estado calculado de la bomba.

Durante las pruebas, esta información se utilizó para monitorear el comportamiento del sistema y verificar que las lecturas obtenidas por los sensores coincidieran con los estados definidos por la lógica de control.
