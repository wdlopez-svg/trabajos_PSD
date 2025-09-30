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

  # Reto: Secuencia de LEDs con Pulsador  

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

