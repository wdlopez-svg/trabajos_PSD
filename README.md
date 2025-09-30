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
