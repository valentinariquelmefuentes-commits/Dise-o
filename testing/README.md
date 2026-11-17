# Protocolo experimental — Compresa inteligente Alpha

## Objetivo

Verificar en banco el funcionamiento integrado del prototipo, comprobando la lectura de los dos sensores DS18B20, la lógica de control de la bomba, la detección de fallas de los sensores y la transmisión de datos mediante Bluetooth.

También se busca observar el comportamiento del circuito de circulación de agua y evaluar si el sistema mantiene un funcionamiento estable durante una prueba continua de al menos cinco minutos.

## Variables del prototipo

Estas son las variables que utiliza directamente el firmware implementado:

| Variable | Descripción | Forma de obtención |
|---|---|---|
| `tempSuperficie` | Temperatura medida en la superficie | Sensor DS18B20 |
| `tempAgua` | Temperatura del agua del circuito | Sensor DS18B20 |
| `bombaEncendida` | Estado lógico de la bomba | Calculado por el firmware como ON/OFF |
| Estado de los sensores | Indica si alguno de los sensores está desconectado o presenta una lectura inválida | Detección mediante `DEVICE_DISCONNECTED_C` |
| Datos transmitidos por Bluetooth | Temperatura de superficie, temperatura del agua y estado de la bomba | Comunicación mediante `BluetoothSerial` |

En el código utilizado, la temperatura de superficie corresponde a la variable empleada para determinar el estado de la bomba.

## Variables de la prueba experimental

Además de las variables entregadas por el prototipo, durante las pruebas se registrarán algunas condiciones externas para poder evaluar el funcionamiento del sistema.

| Variable | Unidad o registro | Método |
|---|---|---|
| Temperatura de referencia | °C | Termómetro independiente, si se encuentra disponible |
| Tiempo de ensayo | s o min | Cronómetro |
| Circulación de agua | Con flujo / sin flujo | Observación visual |
| Fugas | Sí / No | Inspección visual de mangueras y conexiones |
| Funcionamiento físico de la bomba | Encendida / apagada | Observación directa |
| Comunicación Bluetooth | Datos recibidos / no recibidos | Comparación con el Monitor Serial |

Estas variables no corresponden directamente a variables programadas en el firmware, sino que se registran durante el testing para evaluar el desempeño del prototipo.

## Condiciones de prueba

- Las pruebas se realizarán en banco y sin utilizar personas.
- Se utilizará una bolsa o botella hermética con agua tibia para simular una superficie con mayor temperatura.
- La electrónica deberá mantenerse separada del agua durante todo el ensayo.
- El depósito deberá contener suficiente agua para mantener la bomba funcionando sin quedarse sin suministro.
- Antes de iniciar se deberá revisar que las mangueras estén correctamente conectadas y que no existan fugas visibles.
- Se deberá verificar cuál sensor corresponde a la superficie y cuál corresponde al agua.
- Se utilizará la misma versión del firmware durante cada serie de pruebas.
- Se registrarán los umbrales de encendido y apagado configurados en el código utilizado para el ensayo.

## Procedimiento y criterios de aceptación

### P1 — Identificación de los sensores

**Procedimiento**

1. Encender el ESP32.
2. Observar las dos temperaturas mostradas en el Monitor Serial.
3. Aplicar un cambio moderado de temperatura a uno de los sensores.
4. Identificar cuál lectura cambia.
5. Repetir el procedimiento con el segundo sensor.

**Criterio de aceptación**

Se deben identificar correctamente los dos sensores y distinguir cuál corresponde a la temperatura de superficie y cuál a la temperatura del agua.

---

### P2 — Verificación de las mediciones de temperatura

**Procedimiento**

1. Colocar ambos sensores DS18B20 en una condición térmica conocida.
2. Si se dispone de un termómetro independiente, medir simultáneamente la temperatura de referencia.
3. Esperar a que las lecturas se estabilicen.
4. Registrar varias mediciones de ambos sensores.
5. Repetir la prueba utilizando una segunda condición de temperatura.

**Criterio de aceptación**

Las lecturas de ambos sensores deben cambiar de manera coherente con la temperatura aplicada y mantenerse razonablemente estables cuando la condición térmica no cambia.

Si se utiliza un termómetro de referencia, se compararán las lecturas obtenidas con ese instrumento.

---

### P3 — Verificación de la lógica de control

**Procedimiento**

1. Observar la temperatura de superficie indicada por el sistema.
2. Modificar progresivamente la temperatura aplicada al sensor.
3. Hacer que la lectura cruce el umbral de encendido configurado.
4. Registrar el estado indicado por el firmware.
5. Posteriormente disminuir la temperatura hasta cruzar el umbral de apagado.
6. Repetir el procedimiento al menos tres veces.

**Criterio de aceptación**

El estado lógico de la bomba debe cambiar de acuerdo con los umbrales configurados en el firmware:

- al superar el umbral de encendido, el sistema debe indicar `Bomba: ON`;
- al disminuir bajo el umbral de apagado, debe indicar `Bomba: OFF`.

Si la bomba se encuentra completamente integrada físicamente, su funcionamiento debe coincidir con el estado indicado por el sistema.

---

### P4 — Detección de falla de sensor

**Procedimiento**

1. Mantener el sistema funcionando normalmente.
2. Desconectar temporalmente uno de los sensores DS18B20.
3. Observar la respuesta del firmware en el Monitor Serial.
4. Repetir la prueba con el segundo sensor.

**Criterio de aceptación**

Cuando cualquiera de los sensores se encuentre desconectado o entregue una lectura inválida, el sistema debe mostrar:

`ERROR SENSOR - BOMBA OFF`

y establecer el estado de la bomba en OFF.

---

### P5 — Comunicación Bluetooth

**Procedimiento**

1. Encender el prototipo.
2. Establecer la conexión Bluetooth con el dispositivo identificado como `Compresa_ESP32`.
3. Registrar los valores recibidos mediante Bluetooth.
4. Compararlos con los valores mostrados simultáneamente en el Monitor Serial.
5. Mantener la comunicación durante la prueba.

**Criterio de aceptación**

La información transmitida mediante Bluetooth debe incluir:

- temperatura de superficie;
- temperatura del agua;
- estado ON/OFF de la bomba.

Los valores recibidos deben coincidir con los mostrados en el Monitor Serial.

---

### P6 — Circulación de agua

**Procedimiento**

1. Llenar el depósito.
2. Revisar las conexiones de las mangueras.
3. Activar la bomba cuando corresponda.
4. Observar el recorrido del agua por el circuito.
5. Verificar que el agua regrese al depósito.
6. Revisar las uniones y la compresa en busca de fugas.

**Criterio de aceptación**

Se debe observar circulación continua de agua durante el funcionamiento de la bomba y no deben existir fugas que comprometan el sistema o los componentes electrónicos.

---

### P7 — Prueba de integración

**Procedimiento**

1. Montar el sistema completo.
2. Encender el ESP32 y verificar la lectura de ambos sensores.
3. Iniciar la circulación de agua.
4. Establecer la conexión Bluetooth.
5. Mantener el prototipo funcionando durante al menos cinco minutos.
6. Registrar las temperaturas, el estado de la bomba y cualquier problema observado.

**Criterio de aceptación**

Durante los cinco minutos de funcionamiento se espera que:

- ambos sensores mantengan lecturas disponibles;
- la comunicación Bluetooth se mantenga activa;
- el estado de la bomba corresponda a la lógica implementada;
- no se produzcan reinicios inesperados;
- no existan fugas;
- el agua circule cuando la bomba se encuentre activa.

## Registro de datos

Durante las pruebas se pueden registrar los siguientes datos:

`ensayo_id, tiempo_s, tempSuperficie_C, tempAgua_C, estado_bomba, bomba_observada, bluetooth_recibido, fugas, observaciones`

Si se utiliza un termómetro independiente, también se puede agregar:

`temperatura_referencia_C`

## Análisis de resultados

### Sensores

Se analizará:

- estabilidad de las lecturas;
- diferencia entre los dos sensores bajo condiciones similares;
- respuesta de los sensores frente a cambios de temperatura;
- comparación con una temperatura de referencia, si se dispone de ella.

### Lógica de control

Se revisará si los cambios de estado ON/OFF ocurren de acuerdo con los umbrales configurados en el código.

### Seguridad

Se comprobará que la desconexión de cualquiera de los sensores provoque el estado `BOMBA OFF`.

### Bluetooth

Se compararán los datos transmitidos mediante Bluetooth con los valores mostrados en el Monitor Serial.

### Integración

Se registrará cualquier problema observado durante el funcionamiento conjunto del sistema, incluyendo:

- pérdida de comunicación;
- fallas de sensores;
- reinicios;
- problemas de circulación;
- fugas;
- funcionamiento incorrecto de la bomba.

## Iteración

Si durante las pruebas se detecta una falla, se deberá registrar:

1. problema observado;
2. condición en que ocurrió;
3. cambio realizado;
4. resultado obtenido después de repetir la prueba.

De esta forma se podrá documentar la evolución del prototipo y las mejoras realizadas durante el proceso de integración.

## Evidencia esperada

| Prueba | Evidencia |
|---|---|
| P1 — Identificación | Captura del Monitor Serial y registro de la identificación de ambos sensores |
| P2 — Temperatura | Tabla o archivo con las mediciones obtenidas |
| P3 — Control | Captura o registro de los estados `Bomba: ON` y `Bomba: OFF` |
| P4 — Falla de sensor | Captura del mensaje `ERROR SENSOR - BOMBA OFF` |
| P5 — Bluetooth | Captura o registro de los datos recibidos mediante Bluetooth |
| P6 — Circulación | Fotografías o video del circuito de agua funcionando |
| P7 — Integración | Registro de al menos cinco minutos de funcionamiento y fotografías del montaje |
| Iteración | Registro de la falla, modificación realizada y resultado posterior |

## Registro final de pruebas

| Prueba | Fecha | Resultado observado | Estado | Archivo de evidencia |
|---|---|---|---|---|
| P1 — Identificación de sensores | | | | |
| P2 — Verificación de temperatura | | | | |
| P3 — Lógica de control | | | | |
| P4 — Falla de sensor | | | | |
| P5 — Comunicación Bluetooth | | | | |
| P6 — Circulación de agua | | | | |
| P7 — Integración | | | | |

Estados posibles:

- **Cumple**
- **No cumple**
- **No ejecutada**
