#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <DHT.h>

// -------------------- Configuración del sensor --------------------
#define DHTPIN 2       // Pin del DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// -------------------- Configuración del LED --------------------
#define LEDPIN 13
#define UMBRAL 28.0  // Temperatura límite para encender el LED

// -------------------- Cola para enviar datos --------------------
QueueHandle_t colaTemperatura;

// -------------------- Prototipos de tareas --------------------
void tareaLectura(void *pvParameters);
void tareaProcesamiento(void *pvParameters);
void tareaMonitoreo(void *pvParameters);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);

  // Crear la cola con espacio para 5 valores tipo float
  colaTemperatura = xQueueCreate(5, sizeof(float));

  if (colaTemperatura != NULL) {
    // Crear las tareas
    xTaskCreate(tareaLectura, "Lectura", 128, NULL, 2, NULL);
    xTaskCreate(tareaProcesamiento, "Proceso", 128, NULL, 2, NULL);
    xTaskCreate(tareaMonitoreo, "Monitoreo", 128, NULL, 1, NULL);
  } else {
    Serial.println("Error al crear la cola");
  }
}

void loop() {
  // No usamos loop(), FreeRTOS gestiona las tareas
}

// -------------------- Tarea 1: Lectura del sensor --------------------
void tareaLectura(void *pvParameters) {
  (void) pvParameters;

  for (;;) {
    float temp = dht.readTemperature();

    if (isnan(temp)) {
      Serial.println("Error al leer el sensor");
    } else {
      // Enviar el valor a la cola
      xQueueSend(colaTemperatura, &temp, portMAX_DELAY);
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS); // Leer cada 2 segundos
  }
}

// -------------------- Tarea 2: Procesamiento --------------------
void tareaProcesamiento(void *pvParameters) {
  (void) pvParameters;
  float valorRecibido;

  for (;;) {
    // Esperar un dato de la cola
    if (xQueueReceive(colaTemperatura, &valorRecibido, portMAX_DELAY) == pdPASS) {
      Serial.print("Temperatura recibida: ");
      Serial.println(valorRecibido);

      // Encender o apagar LED según umbral
      if (valorRecibido > UMBRAL) {
        digitalWrite(LEDPIN, HIGH);
      } else {
        digitalWrite(LEDPIN, LOW);
      }
    }
  }
}

// -------------------- Tarea 3: Monitoreo --------------------
void tareaMonitoreo(void *pvParameters) {
  (void) pvParameters;

  for (;;) {
    Serial.println("✅ Sistema en funcionamiento...");
    vTaskDelay(3000 / portTICK_PERIOD_MS); // Cada 3 segundos
  }
}
