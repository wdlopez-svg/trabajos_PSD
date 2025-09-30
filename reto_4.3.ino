#include <Arduino_FreeRTOS.h>
#include <semphr.h>

// Declaramos el mutex (semáforo binario especial para exclusión mutua)
SemaphoreHandle_t xMutex;

void Tarea1(void *pvParameters);
void Tarea2(void *pvParameters);

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);

  // Crear el mutex
  xMutex = xSemaphoreCreateMutex();

  if (xMutex != NULL) {
    // Crear tareas solo si el mutex se creó correctamente
    xTaskCreate(Tarea1, "Tarea1", 128, NULL, 1, NULL);
    xTaskCreate(Tarea2, "Tarea2", 128, NULL, 1, NULL);
  }
}

void loop() {
  // El loop queda vacío porque FreeRTOS gestiona las tareas
}

void Tarea1(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    // Intentar tomar el mutex
    if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
      Serial.println(">>> Tarea 1 escribiendo en Serial...");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      Serial.println(">>> Tarea 1 terminó de escribir.");
      
      // Liberar el mutex
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(500 / portTICK_PERIOD_MS); 
  }
}

void Tarea2(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    // Intentar tomar el mutex
    if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
      Serial.println(">>> Tarea 2 escribiendo en Serial...");
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      Serial.println(">>> Tarea 2 terminó de escribir.");
      
      // Liberar el mutex
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(700 / portTICK_PERIOD_MS); 
  }
}
