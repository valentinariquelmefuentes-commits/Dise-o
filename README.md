Compresa Inteligente - TEI201

Descripción
Este repositorio contiene el desarrollo del prototipo Alpha de una compresa con circulación de líquido y monitoreo de temperatura, diseñada como propuesta para el enfriamiento inicial controlado de quemaduras térmicas.

El prototipo utiliza un microcontrolador ESP32, sensores de temperatura DS18B20, una bomba de circulación y comunicación Bluetooth. El desarrollo se realizó de forma incremental, probando primero cada componente de manera individual y posteriormente integrando las distintas funciones del sistema.

Componentes principales
- ESP32
- Dos sensores de temperatura DS18B20
- Módulo MOSFET
- Bomba de circulación de agua
- Sistema de alimentación
- Conectividad Bluetooth
- Librerías utilizadas
- OneWire
- DallasTemperature
- BluetoothSerial
- Funcionamiento general

Los sensores DS18B20 permiten medir la temperatura de la superficie y del agua del sistema. El ESP32 procesa estas mediciones y determina el estado de funcionamiento de la bomba según los umbrales experimentales establecidos.

En la versión Alpha también se incorporó una condición de seguridad que detecta fallas o desconexiones de los sensores. Ante una lectura inválida, el sistema establece automáticamente el estado de la bomba en OFF.

La información de temperatura y el estado calculado de la bomba pueden visualizarse mediante el monitor serial y transmitirse inalámbricamente mediante Bluetooth.

La activación física de la bomba se encuentra todavía en etapa de integración. Actualmente, la lógica de control permite visualizar correctamente los estados ON y OFF determinados por el sistema.

Evolución del código
1. ESP32
Se verificó inicialmente el funcionamiento del microcontrolador mediante el mensaje “ESP32 funcionando” enviado al monitor serial.

2. ESP32 + DS18B20
Se incorporó el primer sensor DS18B20 para realizar mediciones de temperatura en grados Celsius.

3. ESP32 + salida GPIO 26
Se probó la salida destinada al control del MOSFET, verificando cambios entre estados ON y OFF.

4. Sensor + lógica de control
Se integró la medición de temperatura con una lógica automática para determinar el estado de la bomba según umbrales experimentales.

5. Seguridad
Se incorporó una condición capaz de detectar una falla o desconexión del sensor. Ante una lectura inválida, el sistema establece automáticamente la bomba en OFF.

6. Segundo DS18B20
Se incorporó un segundo sensor para medir simultáneamente la temperatura de la superficie y la temperatura del agua.

7. Bluetooth
Se incorporó la librería BluetoothSerial para transmitir inalámbricamente la temperatura de superficie, la temperatura del agua y el estado calculado de la bomba.

Organización del repositorio
- codigo/: contiene las diferentes etapas de desarrollo del software del prototipo.
- esquematicos/: contiene los diagramas de funcionamiento y conexiones eléctricas.
- CAD/: contiene el modelo 3D preliminar del sistema.
- testing/: contiene fotografías, registros y resultados obtenidos durante las pruebas.


Integrantes
- Martina Calvo
- Florencia Maldonado
- Catalina Ríos
- Valentina Riquelme
