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



