# Evidencias de testing

Esta carpeta contiene fotografías y registros obtenidos durante el montaje, integración y pruebas del prototipo de compresa inteligente.

Las evidencias permiten documentar tanto la construcción física del sistema como el funcionamiento de sus componentes principales, la circulación de agua y la lectura de datos mediante el ESP32.

## Evidencias incluidas

### `montaje_general_caja_electronica.jpeg`

Vista general del interior de la caja electrónica del prototipo. Se observa la disposición de la fuente de alimentación, el ESP32, el módulo de control, el convertidor LM2596, el cableado y la bomba.

### `bomba_12V.jpeg`

Detalle de la bomba de 12 V utilizada para impulsar el agua a través del circuito hidráulico.

### `esp32_rele_lm2596.jpeg`

Vista del ESP32 junto al módulo de relé y al convertidor LM2596. Esta sección corresponde al sistema de adquisición de datos, lógica de control y accionamiento de la bomba.

### `fuente_switching_12V.jpeg`

Detalle de la fuente switching utilizada para alimentar el sistema de potencia del prototipo.

### `sistema_integrado_cajas_y_circuito.jpeg`

Vista general del prototipo integrado, mostrando la conexión entre la caja electrónica, el depósito de agua y el circuito de mangueras.

### `conexiones_hidraulicas_entre_cajas.jpeg`

Detalle de las mangueras que conectan las distintas partes del sistema y permiten la circulación de agua entre el depósito, la bomba y la compresa.

### `deposito_y_mangueras.jpeg`

Vista interior del depósito y de las mangueras utilizadas para el circuito de entrada y retorno de agua.

### `deposito_sensor_y_mangueras.jpeg`

Detalle del depósito con las mangueras y el sensor utilizado para registrar la temperatura del agua del sistema.

### `monitor_serial_temperaturas_bomba_off.jpeg`

Registro del Monitor Serial donde se observan simultáneamente la temperatura de superficie, la temperatura del agua y el estado de la bomba en condición `OFF`.

Esta evidencia permite verificar que ambos sensores son leídos por el ESP32 y que el sistema informa el estado lógico de la bomba.

### `monitor_serial_umbral_control_bomba.jpeg`

Registro del Monitor Serial durante una prueba cercana al umbral configurado de control.

En esta evidencia se observan las lecturas de temperatura entregadas por los sensores y el estado de la bomba determinado por el firmware.

### `compresa_serpentina_manguera.jpeg`

Vista de la construcción de la compresa, mostrando la disposición de la manguera en forma de serpentina sobre la base flexible.

Esta geometría permite distribuir el agua a lo largo de una mayor superficie de la compresa.

### `compresa_cubierta_eva.jpeg`

Vista de la capa de EVA utilizada como cubierta de la compresa durante la construcción del prototipo.

## Relación con el protocolo experimental

Estas fotografías complementan las pruebas descritas en el protocolo experimental disponible en `testing/README.md`.

En particular, permiten documentar:

- el montaje del sistema;
- la integración electrónica;
- el circuito hidráulico;
- la construcción de la compresa;
- la lectura de los sensores;
- el estado lógico de la bomba;
- la integración general del prototipo.

A medida que se realicen nuevas pruebas, se podrán incorporar registros adicionales de Bluetooth, circulación de agua, detección de fallas y funcionamiento continuo del sistema.
