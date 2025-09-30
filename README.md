# Reto 1.1: Encender LED con Pulsador (Modo Toggle)  

## Explicación  
Este programa permite controlar un LED con un pulsador en modo toggle. Cada vez que se presiona el botón, el LED cambia de estado: si estaba apagado se enciende y si estaba encendido se apaga. Para evitar que el LED parpadee mientras se mantiene presionado, se guarda el último estado del botón.  

## Conexiones  
- LED: conectado al pin digital 13 de Arduino, con una resistencia en serie de 220 Ω a GND.  
- Pulsador: conectado al pin digital 2 y a GND. Se recomienda usar una resistencia pull-up (interna o externa).  

## Puntos importantes  
- El botón debe configurarse con `INPUT` (o mejor con `INPUT_PULLUP` para mayor estabilidad).  
- Se usa una variable de estado para “recordar” si el LED está encendido o apagado.  
- El control se hace por flancos de pulsación, no por estado continuo.

# Reto 1.2: Secuencia de LEDs con Pulsador  

## Explicación  
Este programa enciende una secuencia de 8 LEDs al mantener presionado un pulsador. Los LEDs se encienden uno a uno en orden ascendente, y al soltar el botón, se apagan en orden inverso. Además, se registra en el monitor serial qué LED está encendido en cada momento.  

## Conexiones  
- Pulsador: conectado al pin digital 2 y a GND (se recomienda usar `INPUT_PULLUP`).  
- LEDs: conectados a los pines digitales 6, 7, 8, 9, 10, 11, 12 y 13. Cada LED debe llevar una resistencia de 220 Ω a GND.  

## Puntos importantes  
- Se utiliza un arreglo para manejar múltiples LEDs de forma ordenada.  
- Cada LED se enciende con un retardo de 500 ms, creando el efecto de secuencia.  
- Al liberar el botón, la secuencia de apagado ocurre en orden inverso.  
- El monitor serial muestra en qué estado se encuentra cada LED.

# Reto 1.3: Luz de Emergencia con Dos LEDs y Dos Pulsadores  

## Explicación  
Este programa simula una luz de emergencia utilizando dos LEDs.  
- Al presionar el **botón 1**, los LEDs parpadean de forma alternada (primero se enciende uno, luego el otro).  
- El parpadeo se mantiene en un ciclo hasta que se presiona el **botón 2**, que detiene el efecto.  

## Conexiones  
- LED 1 → Pin digital 6 con resistencia de 220 Ω a GND.  
- LED 2 → Pin digital 7 con resistencia de 220 Ω a GND.  
- Botón 1 → Pin digital 1 y GND (se recomienda usar `INPUT_PULLUP`).  
- Botón 2 → Pin digital 2 y GND (se recomienda usar `INPUT_PULLUP`).  

## Puntos importantes  
- Se emplea un bucle `do-while` para mantener el parpadeo hasta que se active el botón de parada.  
- Cada LED permanece encendido 1 segundo antes de alternar.  
- Es recomendable evitar usar el pin 1 para botones, ya que en muchos Arduinos corresponde al puerto Serial.

# Reto1.4: Contador Binario con LEDs  

## Explicación  
Este programa utiliza 4 LEDs para representar un número binario entre **0 y 15**.  
- Cada vez que se presiona el botón, el contador aumenta en 1.  
- Los LEDs en los pines 6, 7, 8 y 9 muestran el valor en binario.  
- Cuando se llega al número 15, el contador vuelve a 0.  
- El valor en binario también se imprime en el Monitor Serial.  

## Conexiones  
- LED 1 → Pin digital 6 con resistencia de 220 Ω a GND.  
- LED 2 → Pin digital 7 con resistencia de 220 Ω a GND.  
- LED 3 → Pin digital 8 con resistencia de 220 Ω a GND.  
- LED 4 → Pin digital 9 con resistencia de 220 Ω a GND.  
- Botón → Pin digital 2 y GND (recomendable usar `INPUT_PULLUP`).  

## Puntos importantes  
- El código convierte el número decimal a binario usando divisiones sucesivas entre 2.  
- Cada LED representa un bit (LSB en el LED 1 y MSB en el LED 4).  
- Se reinicia automáticamente cuando el contador supera el valor 15.  

# Reto 1.5: Control de Brillo con Pulsadores (PWM)

## Explicación  
Este programa controla el **brillo de un LED** mediante dos botones:  
- El botón en el pin 2 **aumenta el brillo**.  
- El botón en el pin 3 **disminuye el brillo**.  
- El LED está conectado a un pin PWM (pin 6 en este caso).  
- El brillo varía entre 0 (apagado) y 255 (máxima intensidad).  
- El valor del brillo también se muestra en el Monitor Serial.  

## Conexiones  
- LED → Pin digital PWM 6 con resistencia de 220 Ω a GND.  
- Botón 1 → Pin digital 2 y GND (incrementa brillo).  
- Botón 2 → Pin digital 3 y GND (disminuye brillo).  
- Se recomienda usar resistencias pull-down o configurar `INPUT_PULLUP` en los botones.  

## Puntos importantes  
- Se utiliza `analogWrite()` para generar la señal PWM y variar la intensidad del LED.  
- El brillo se ajusta paso a paso dentro del rango válido (0 a 255).  
- El uso del Monitor Serial permite visualizar el valor actual del brillo.

# Reto 1.6: Memoria de Secuencia (Juego de Simón)

## Explicación  
Este programa implementa una versión básica del **juego de Simón**, donde el sistema genera una secuencia de LEDs encendidos y el usuario debe repetirla presionando los botones correspondientes.  

- Cada ronda, la secuencia crece en **un paso más** si el usuario acierta.  
- Si el jugador se equivoca, todos los LEDs parpadean indicando error y el juego se reinicia desde el inicio.  
- El uso de `random()` permite generar secuencias diferentes cada vez.  
- La comparación entre `secuencia1` (la generada por el programa) y `secuencia2` (la ingresada por el usuario) define si el jugador pasa de nivel o no.  

## Conexiones  
- **LEDs**:  
  - LED1 → Pin 6  
  - LED2 → Pin 7  
  - LED3 → Pin 8  
  - LED4 → Pin 9  
  - LED5 → Pin 10  

- **Botones**:  
  - Botón 1 → Pin 11  
  - Botón 2 → Pin 2  
  - Botón 3 → Pin 3  
  - Botón 4 → Pin 4  
  - Botón 5 → Pin 5  

- Todos los botones deben estar conectados con resistencia **pull-down** (o configurarse con `INPUT_PULLUP`).  
- Los LEDs se conectan con resistencia de **220 Ω** hacia GND.  

## Puntos importantes  
- Cada ronda se muestra la secuencia encendiendo los LEDs con pausas de 1 segundo.  
- El jugador debe introducir la secuencia en el mismo orden utilizando los botones.  
- El valor de la secuencia se imprime en el **Monitor Serial** para ver el proceso internamente.  
- Si hay error, los LEDs parpadean tres veces y el contador de secuencia vuelve a 1.  

# Reto 1.7: Semáforo con Peatón

## Explicación  
Este programa simula el funcionamiento de un **semáforo vehicular con cruce peatonal**.  

- El semáforo para autos funciona normalmente en **verde**.  
- Cuando el botón de peatones es presionado:  
  1. El verde se apaga.  
  2. Se enciende el **amarillo** durante un tiempo breve (1.5 s).  
  3. Luego se enciende el **rojo** para autos y la luz de **peatones**.  
  4. Pasado un tiempo de cruce (5 s), el sistema vuelve al verde para autos.  

Esto asegura que los peatones crucen con seguridad.  

## Conexiones  
- **LEDs (semáforo de autos + peatones):**  
  - LED peatones → Pin 10  
  - LED verde autos → Pin 7  
  - LED amarillo autos → Pin 8  
  - LED rojo autos → Pin 9  

- **Botón peatonal:**  
  - Botón → Pin 2  

- Los LEDs deben conectarse con resistencias de **220 Ω** hacia GND.  
- El botón debe estar con resistencia **pull-down** (o configurarse como `INPUT_PULLUP`).  

## Puntos importantes  
- El tiempo de cruce peatonal está configurado en **5 segundos**.  
- El amarillo dura **1.5 segundos** como transición.  
- Durante el cruce, los autos quedan en rojo y los peatones en verde.  
- Se puede ajustar los tiempos modificando los valores en `delay()`.  

# Reto 2.1: Contador con Interrupción Externa  

## Descripción  
Este programa implementa un contador que se incrementa cada vez que se presiona un botón conectado al pin digital 2.  
En lugar de usar *polling* con `digitalRead()`, se utiliza una **interrupción externa** que responde inmediatamente al evento.  
El valor del contador se muestra en el monitor serial.  

## Conexiones  
- Botón → Pin digital 2 (INT0).  
- El otro extremo del botón → GND.  
- Se recomienda usar `INPUT_PULLUP` para evitar rebotes.  

## Funcionamiento  
- La función `attachInterrupt()` configura el pin 2 para generar una interrupción en el flanco de subida (*RISING*).  
- Cada vez que ocurre la interrupción, se ejecuta la función `velocidadMenos()`, que incrementa el contador y lo imprime en el monitor serial.  
- De esta forma, no es necesario usar `loop()` para verificar continuamente el estado del botón.  

## Aplicaciones  
- Contadores de eventos (pulsos, vueltas, clics).  
- Medición de entradas digitales rápidas.  
- Sistemas donde se necesita respuesta inmediata a una señal externa.  

# Reto2.2: Control de PWM con Interrupción  

## Descripción  
Este programa controla la intensidad de un LED mediante **PWM**.  
- El LED aumenta o disminuye gradualmente su brillo en función de una variable de control.  
- Cada vez que se presiona un botón conectado al pin digital 3, se genera una **interrupción externa** que invierte la dirección del cambio (si estaba aumentando, pasa a disminuir, y viceversa).  

## Conexiones  
- LED → Pin digital 13 (a través de una resistencia de 220 Ω hacia GND).  
- Botón → Pin digital 3 (INT1).  
- El otro extremo del botón → GND.  
- Se recomienda usar `INPUT_PULLUP` para evitar rebotes en la señal del botón.  

## Funcionamiento  
- La intensidad del LED se controla con `analogWrite()`, variando de 0 a 255.  
- Cada 50 ms el valor de brillo se incrementa o decrementa según el estado de la variable `aumento_disminucion`.  
- Cuando el botón en el pin 3 detecta un flanco ascendente (*RISING*), la interrupción ejecuta la función `velocidadMenos()`, que invierte la dirección del cambio de brillo.  

## Aplicaciones  
- Control de brillo adaptativo en sistemas de iluminación.  
- Ejemplo de cómo usar **PWM junto con interrupciones externas** para lograr un comportamiento dinámico.  

# Reto 2.3: Temporizador interno para parpadeo preciso  

## Descripción  
Este programa utiliza el **Timer1** del microcontrolador en modo **CTC (Clear Timer on Compare Match)** para generar una interrupción periódica.  
El objetivo es hacer que un LED parpadee con precisión, sin necesidad de usar la función `delay()`.  

## Conexiones  
- LED → Pin digital 13 (con resistencia de 220 Ω hacia GND).  

## Funcionamiento  
1. Se configura el **Timer1** con un prescaler de 256.  
2. Se establece el valor de comparación `OCR1A = 31250`, lo que genera una interrupción cada **500 ms**.  
   - Cálculo:  
     ```
     Frecuencia Arduino = 16 MHz  
     Prescaler = 256  
     Tiempo = (OCR1A + 1) * (Prescaler / Frecuencia)  
     Tiempo = (31250) * (256 / 16,000,000) ≈ 0.5 segundos  
     ```  
3. En la rutina de interrupción (`ISR`), se invierte el estado del LED en el pin 13.  
   - Si estaba encendido se apaga, y si estaba apagado se enciende.  

## Ventaja  
A diferencia de `delay()`, este método permite que el microcontrolador pueda seguir ejecutando otras tareas en el `loop()` mientras el temporizador controla el parpadeo.  

## Aplicaciones  
- Sistemas que requieren **tiempos precisos**.  
- Parpadeo de LEDs en intervalos regulares.  
- Base para relojes, cronómetros o generación de señales periódicas.

# Reto 2.4: Medición de frecuencia de una señal externa  

## Descripción  
Este programa mide la frecuencia de una señal de entrada (pulsos por segundo) utilizando **interrupciones externas** junto con el **Timer1** del Arduino.  

## Conexiones  
- Pin **2** → Entrada de pulsos (botón, sensor de efecto Hall, encoder, etc.).  
- Pin **13** → LED incorporado (no se usa en este caso, pero está configurado como salida).  

## Funcionamiento  
1. **Interrupción externa (INT0 en pin 2):**  
   - Cada pulso en el pin 2 genera una interrupción que incrementa la variable `contador`.  
   - Esto permite contar los pulsos de manera precisa sin usar polling.  

2. **Interrupción por Timer1:**  
   - Se configura el Timer1 en modo CTC con un prescaler de **256**.  
   - `OCR1A = 15625*4` → genera una interrupción cada **1 segundo**.  
     - Cálculo:  
       ```
       Frecuencia Arduino = 16 MHz  
       Prescaler = 256  
       OCR1A = (Tiempo * Frecuencia) / Prescaler  
       OCR1A = (1 * 16,000,000) / 256 ≈ 62,500  
       ```  
       Se usa `15625*4` que equivale al mismo valor.  

3. **Cálculo de frecuencia:**  
   - En la ISR del temporizador (`TIMER1_COMPA_vect`), se muestra en el monitor serial la cantidad de pulsos contados en ese segundo.  
   - Se interpreta directamente como **frecuencia en Hz (pulsos/segundo)**.  
   - Luego, el contador se reinicia a 0 para la siguiente medición.  

## Aplicaciones  
- Medir la velocidad de giro de un motor con un sensor Hall o encoder.  
- Contar la frecuencia de pulsos en sistemas digitales.  
- Construir tacómetros o medidores de RPM.  

# Reto 2.5: Sistema de alarma con múltiples interrupciones  

## Descripción  
Este programa implementa un sistema de **alarma con buzzer** controlado mediante dos interrupciones externas y un temporizador interno (Timer2).  

## Conexiones  
- **Pin 2 (INT0)** → Sensor de activación (ej. PIR o pulsador).  
- **Pin 3 (INT1)** → Botón de apagado de la alarma.  
- **Pin 13** → Buzzer (salida de la alarma).  

## Funcionamiento  
1. **Interrupción externa en pin 2 (sensor):**  
   - Activa la alarma al detectar un evento.  
   - Se establece `estado_alarma = true`.  

2. **Interrupción externa en pin 3 (apagado):**  
   - Desactiva la alarma y reinicia el valor de frecuencia.  
   - Se apaga el buzzer inmediatamente.  

3. **Interrupción por Timer2:**  
   - Configurada en **modo CTC**.  
   - Genera una señal PWM sobre el buzzer, aumentando progresivamente la frecuencia para simular una **sirena de alarma**.  
   - El valor de `frecuencia` se incrementa hasta 255 y luego se reinicia.  

4. **Loop principal:**  
   - Supervisa los límites de `frecuencia` y ajusta el ciclo de variación.  
   - No depende de `delay()`, ya que todo el control ocurre dentro de las interrupciones.  

## Aplicaciones  
- Sistemas de seguridad doméstica.  
- Alarmas en maquinaria o laboratorios.  
- Demostración de cómo integrar **múltiples interrupciones (externas e internas)** para coordinar diferentes eventos en un sistema.  

# Reto 3.1: Contador Persistente de Encendidos  

## Descripción  
Este programa usa la **EEPROM del Arduino** para contar cuántas veces se ha encendido el sistema.  
El valor del contador se guarda en la memoria no volátil, por lo que se mantiene incluso después de apagar o reiniciar la placa.  

## Funcionamiento  
- Al iniciar, el Arduino lee el valor del contador desde la dirección `0` de la EEPROM.  
- Incrementa ese valor en `+1`.  
- Escribe el nuevo valor en la misma dirección de la EEPROM.  
- Muestra en el **Monitor Serial** el número de veces que la placa ha sido encendida.  

## Conexiones  
No requiere componentes externos. Solo es necesario conectar el Arduino al PC y abrir el **Monitor Serial**.  

## Aplicaciones  
- Contadores de encendidos o reinicios.  
- Registro de uso de equipos electrónicos.  
- Sistemas de mantenimiento predictivo donde se necesita saber el número de ciclos de trabajo.  

# Reto 3.2: Menú de Configuración Persistente con EEPROM  

## Descripción  
Este programa permite al usuario seleccionar, mediante el **Monitor Serial**, qué LED encender (amarillo, azul o rojo).  
La configuración se guarda en la **EEPROM** del Arduino, de modo que cuando la placa se reinicie, el último LED encendido se restaura automáticamente.  

## Funcionamiento  
- El usuario escribe en el Monitor Serial:  
  - `1` → Enciende el LED amarillo.  
  - `2` → Enciende el LED azul.  
  - `3` → Enciende el LED rojo.  
- La opción seleccionada se almacena en la EEPROM.  
- Al iniciar, el Arduino recupera la última opción guardada y enciende el LED correspondiente sin necesidad de volver a configurarlo.  

## Conexiones  
- LED amarillo → Pin 11  
- LED azul → Pin 12  
- LED rojo → Pin 13  
Cada LED debe conectarse en serie con una resistencia de **220 Ω** hacia GND.  

## Aplicaciones  
- Sistemas que necesitan **guardar configuraciones de usuario** (ejemplo: color de un indicador).  
- Menús de ajustes que deben mantenerse tras un reinicio.  
- Ejemplo básico de uso de **EEPROM con variables** para configuraciones persistentes.

# Reto 4.1: Parpadeo Multitarea con FreeRTOS en Arduino

## Descripción
Este programa utiliza **FreeRTOS** para crear dos tareas que se ejecutan de manera concurrente en un Arduino.  
Cada tarea controla un LED con un intervalo de parpadeo diferente, demostrando el funcionamiento del planificador de tareas sin necesidad de usar `delay()`.

- **Tarea 1**: Hace parpadear el LED conectado al pin 8 cada **500 ms**.  
- **Tarea 2**: Hace parpadear el LED conectado al pin 9 cada **1000 ms**.  

El sistema operativo en tiempo real se encarga de administrar ambas tareas, permitiendo que funcionen de manera independiente y no bloqueante.

## Conexiones
- LED1 → Pin 8 (con resistencia de 220 Ω).  
- LED2 → Pin 9 (con resistencia de 220 Ω).  
- GND común para ambos LEDs.  

## Conceptos Clave
- Uso de **xTaskCreate()** para crear tareas.  
- Uso de **vTaskDelay()** para retardos sin bloquear la CPU.  
- Inicio del planificador con **vTaskStartScheduler()**.  

## Aplicación
Este ejercicio es la base para comprender cómo trabajar con múltiples procesos en paralelo usando un RTOS, lo que es útil en sistemas embebidos, IoT y aplicaciones donde se requieren respuestas rápidas y concurrentes.

# Reto 4.2: Tareas con Diferentes Prioridades en FreeRTOS

## Descripción
Este programa implementa tres tareas concurrentes con **FreeRTOS** en un Arduino, cada una con distinta prioridad.  
De esta manera se observa cómo el planificador asigna el uso de la CPU según la importancia de cada tarea.

- **Tarea 1 (prioridad baja, 1):** Hace parpadear el LED en el pin 8 cada **500 ms**.  
- **Tarea 2 (prioridad media, 2):** Lee el valor de un potenciómetro conectado al pin **A0** y lo muestra por el puerto serie cada **500 ms**.  
- **Tarea 3 (prioridad alta, 3):** Hace parpadear el LED en el pin 9 cada **1000 ms**.  

La CPU siempre dará preferencia a la tarea de mayor prioridad cuando esté lista para ejecutarse.

## Conexiones
- LED1 → Pin 8 (con resistencia de 220 Ω).  
- LED2 → Pin 9 (con resistencia de 220 Ω).  
- Potenciómetro → Pin A0 (terminal central), extremos a **5V** y **GND**.  

## Conceptos Clave
- Las tareas se crean con **xTaskCreate()**, asignando prioridad en el quinto parámetro.  
- FreeRTOS interrumpe tareas de baja prioridad si una de mayor prioridad requiere ejecución.  
- El uso de **vTaskDelay()** permite liberar la CPU para que otras tareas puedan ejecutarse.  

## Aplicación
Este ejemplo ayuda a comprender cómo manejar procesos concurrentes en sistemas embebidos, priorizando tareas críticas (como botones o sensores) sobre otras menos urgentes (como parpadeo de LEDs).

# Reto 4.3: Sincronización con Semáforos en FreeRTOS

## Descripción
Este programa implementa dos tareas que comparten un recurso crítico: la **salida Serial**.  
Para evitar que ambas escriban al mismo tiempo (y que los mensajes salgan mezclados), se utiliza un **mutex** (semáforo binario especial para exclusión mutua).

- **Tarea 1:** Escribe un mensaje en Serial, tarda 1 segundo y libera el recurso.  
- **Tarea 2:** También escribe en Serial, tarda 1 segundo y libera el recurso.  

El **mutex garantiza** que solo una tarea pueda usar Serial a la vez.

## Conexiones
No se necesitan conexiones externas, solo el monitor Serial de Arduino.

## Conceptos Clave
- Un **mutex** funciona como una "llave" que solo una tarea puede tener a la vez.  
- Las tareas usan `xSemaphoreTake()` para intentar obtener el recurso, y `xSemaphoreGive()` para liberarlo.  
- Esto evita condiciones de **carrera** y asegura que el recurso compartido se use de forma ordenada.  
- Los **delays** (`vTaskDelay()`) permiten observar claramente cómo se turnan las tareas.  

## Aplicación
Este ejemplo es útil para comprender cómo sincronizar tareas que comparten periféricos en sistemas embebidos.  
Aplicaciones típicas:
- Acceso controlado a pantallas LCD.  
- Escritura ordenada en memoria EEPROM o SD.  
- Comunicación Serial en proyectos con múltiples tareas.

# Reto 4.4: Colas de mensajes en FreeRTOS

## Descripción
Este programa implementa tres tareas que se comunican a través de una **cola**.  
El flujo de trabajo es el siguiente:

- **Tarea de Lectura:** Lee la temperatura desde un sensor DHT11 y envía el valor a la cola.  
- **Tarea de Procesamiento:** Recibe los datos de la cola, los muestra por Serial y enciende un LED si la temperatura supera un umbral definido.  
- **Tarea de Monitoreo:** Muestra periódicamente un mensaje para confirmar que el sistema sigue activo.  

De esta forma, las tareas trabajan **de manera concurrente y ordenada**, sin necesidad de variables globales compartidas.

## Conexiones
- **Sensor DHT11:**
  - Señal → Pin 2 de Arduino  
  - VCC → 5V  
  - GND → GND  
- **LED:**
  - Ánodo (positivo) → Pin 13  
  - Cátodo → Resistencia de 220 Ω → GND  

## Conceptos Clave
- Una **cola** permite que las tareas intercambien datos sin bloquearse entre sí.  
- `xQueueSend()` coloca datos en la cola.  
- `xQueueReceive()` extrae datos de la cola.  
- El uso de la cola evita condiciones de carrera y asegura que los valores se transmitan en orden.  

## Aplicación
Este ejemplo es útil para sistemas en los que:
- **Un sensor produce datos** (productor).  
- **Otra tarea los procesa o decide acciones** (consumidor).  
- Se requiere un sistema robusto que pueda manejar múltiples fuentes de información sin que se mezclen los datos.  

Aplicaciones típicas:
- Sistemas de monitoreo ambiental.  
- Estaciones meteorológicas IoT.  
- Procesos industriales donde sensores y actuadores trabajan en paralelo.
